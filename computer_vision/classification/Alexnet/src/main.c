/****************************************************************************
*   Generated by ACUITY 3.11.0
*   Match ovxlib 1.0.8
*
*   Neural Network application project entry file
****************************************************************************/
/*-------------------------------------------
                Includes
-------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef __linux__
#include <time.h>
#elif defined(_WIN32)
#include <windows.h>
#endif

#define _BASETSD_H

#include "vsi_nn_pub.h"

#include "vnn_global.h"
#include "vnn_pre_process.h"
#include "vnn_post_process.h"
#include "vnn_alexnetcaffe.h"

/*-------------------------------------------
        Macros and Variables
-------------------------------------------*/

/*-------------------------------------------
                  Functions
-------------------------------------------*/
static void vnn_ReleaseNeuralNetwork
    (
    vsi_nn_graph_t *graph
    )
{
    vsi_bool use_img_process = GetEnvForImageProcess();
    vnn_ReleaseAlexnetCaffe( graph, TRUE );
    if (use_img_process)
    {
        ReleaseBufferImg();
    }
}

static vsi_status vnn_PostProcessNeuralNetwork
    (
    vsi_nn_graph_t *graph
    )
{
    return vnn_PostProcessAlexnetCaffe( graph );
}

#define BILLION                                 1000000000
static vx_uint64 vnn_GetPerfCount()
{
#if defined(__linux__) || defined(__ANDROID__) || defined(__QNX__) || defined(__CYGWIN__)
    struct timespec ts;

    clock_gettime(CLOCK_MONOTONIC, &ts);

    return (vx_uint64)((vx_uint64)ts.tv_nsec + (vx_uint64)ts.tv_sec * BILLION);
#elif defined(_WIN32) || defined(UNDER_CE)
    LARGE_INTEGER ln;

    QueryPerformanceCounter(&ln);

    return (vx_uint64)ln.QuadPart;
#endif
}

static vsi_status vnn_ProcessGraph
    (
    vsi_nn_graph_t *graph
    )
{
    vsi_status status;
    int32_t i,loop;
    char *loop_s;
    vx_uint64 tmsStart, tmsEnd, sigStart, sigEnd, msVal, usVal;

    status = VSI_FAILURE;
    loop = 1; /* default loop time is 1 */
    loop_s = getenv("VNN_LOOP_TIME");
    if(loop_s)
    {
        loop = atoi(loop_s);
    }

    /* Verify graph */
    printf("Verify...\n");
    tmsStart = vnn_GetPerfCount();
    status = vsi_nn_VerifyGraph( graph );
    _CHECK_STATUS( status, final );
    tmsEnd = vnn_GetPerfCount();
    msVal = (tmsEnd - tmsStart)/1000000;
    usVal = (tmsEnd - tmsStart)/1000;
    printf("Verify Graph: %ldms or %ldus\n", msVal, usVal);

    /* Run graph */
    tmsStart = vnn_GetPerfCount();
    printf("Start run graph [%d] times...\n", loop);
    for(i = 0; i < loop; i++)
    {
        sigStart = vnn_GetPerfCount();
        status = vsi_nn_RunGraph(graph);
        if(status != VSI_SUCCESS)
        {
            printf("Run graph the %d time fail\n", i);
            return VSI_FAILURE;
        }
        sigEnd = vnn_GetPerfCount();
        msVal = (sigEnd - sigStart)/1000000;
        usVal = (sigEnd - sigStart)/1000;
        printf("Run the %u time: %ldms or %ldus\n", (i+1), msVal, usVal);
    }
    tmsEnd = vnn_GetPerfCount();
    msVal = (tmsEnd - tmsStart)/1000000;
    usVal = (tmsEnd - tmsStart)/1000;
    printf("vxProcessGraph execution time:\n");
    printf("Total   %ldms or %ldus\n", msVal, usVal);
    printf("Average %.2fms or %.2fus\n", ((float)msVal)/loop, ((float)usVal)/loop);

final:
    return status;
}

static vsi_status vnn_PreProcessNeuralNetwork
    (
    vsi_nn_graph_t *graph,
    const char *image_name
    )
{
    vsi_bool use_img_process = GetEnvForImageProcess();
    if (use_img_process)
    {
        return vnn_PreProcessAlexnetCaffe_ImageProcess( graph, image_name );
    }
    return vnn_PreProcessAlexnetCaffe( graph, image_name );
}

static vsi_nn_graph_t *vnn_CreateNeuralNetwork
    (
    const char *data_file_name
    )
{
    vsi_nn_graph_t *graph = NULL;
    vx_uint64 tmsStart, tmsEnd, msVal, usVal;

    tmsStart = vnn_GetPerfCount();
    graph = vnn_CreateAlexnetCaffe(data_file_name, NULL);
    _CHECK_PTR(graph, final);
    tmsEnd = vnn_GetPerfCount();
    msVal = (tmsEnd - tmsStart)/1000000;
    usVal = (tmsEnd - tmsStart)/1000;
    printf("Create Neural Network: %ldms or %ldus\n", msVal, usVal);

    /* Show the node and tensor */
    vsi_nn_PrintGraph(graph);

final:
    return graph;
}

/*-------------------------------------------
                  Main Functions
-------------------------------------------*/
int main
    (
    int argc,
    char **argv
    )
{
    vsi_status status;
    vsi_nn_graph_t *graph;
    const char *data_name = NULL;
    const char *image_name = NULL;

    status = VSI_FAILURE;
    if(argc != 3)
    {
        printf("Usage:%s data_file_name image_file_name\n", argv[0]);
        return -1;
    }

    data_name = (const char *)argv[1];
    image_name = (const char *)argv[2];

    /* Create the neural network */
    graph = vnn_CreateNeuralNetwork( data_name );
    _CHECK_PTR(graph, final);

    /* Pre process the image data */
    status = vnn_PreProcessNeuralNetwork( graph, image_name );
    _CHECK_STATUS( status, final );

    /* Verify and Process graph */
    status = vnn_ProcessGraph( graph );
    _CHECK_STATUS( status, final );

    if(VNN_APP_DEBUG)
    {
        /* Dump all node outputs */
        vsi_nn_DumpGraphNodeOutputs(graph, "./network_dump", NULL, 0, TRUE, 0);
    }

    /* Post process output data */
    status = vnn_PostProcessNeuralNetwork( graph );
    _CHECK_STATUS( status, final );

final:
    vnn_ReleaseNeuralNetwork( graph );
    return status;
}

