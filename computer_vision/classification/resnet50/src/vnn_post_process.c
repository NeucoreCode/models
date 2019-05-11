/****************************************************************************
*   Generated by ACUITY 3.11.0
*   Match ovxlib 1.0.8
*
*   Neural Network appliction post-process source file
****************************************************************************/
/*-------------------------------------------
                Includes
-------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "vsi_nn_pub.h"

#include "vnn_global.h"
#include "vnn_post_process.h"

#define _BASETSD_H

/*-------------------------------------------
                  Functions
-------------------------------------------*/

static void vnn_SaveOutputData(vsi_nn_graph_t *graph)
{
    uint32_t i;
#define _DUMP_FILE_LENGTH 1028
#define _DUMP_SHAPE_LENGTH 128
    char filename[_DUMP_FILE_LENGTH] = {0}, shape[_DUMP_SHAPE_LENGTH] = {0};
    vsi_nn_tensor_t *tensor;

    for(i = 0; i < graph->output.num; i++)
    {
        tensor = vsi_nn_GetTensor(graph, graph->output.tensors[i]);
        vsi_nn_ShapeToString( tensor->attr.size, tensor->attr.dim_num,
            shape, _DUMP_SHAPE_LENGTH, FALSE );
        snprintf(filename, _DUMP_FILE_LENGTH, "output%u_%s.txt", i, shape);

        vsi_nn_SaveTensorToTextByFp32( graph, tensor, filename, NULL );
    }
}

static vsi_bool vnn_GetTop
    (
    float *pfProb,
    float *pfMaxProb,
    uint32_t *pMaxClass,
    uint32_t outputCount,
    uint32_t topNum
    )
{
    uint32_t i, j;

    #define MAX_TOP_NUM 20
    if (topNum > MAX_TOP_NUM) return FALSE;

    memset(pfMaxProb, 0, sizeof(float) * topNum);
    memset(pMaxClass, 0xff, sizeof(float) * topNum);

    for (j = 0; j < topNum; j++)
    {
        for (i=0; i<outputCount; i++)
        {
            if ((i == *(pMaxClass+0)) || (i == *(pMaxClass+1)) || (i == *(pMaxClass+2)) ||
                (i == *(pMaxClass+3)) || (i == *(pMaxClass+4)))
            {
                continue;
            }

            if (pfProb[i] > *(pfMaxProb+j))
            {
                *(pfMaxProb+j) = pfProb[i];
                *(pMaxClass+j) = i;
            }
        }
    }

    return TRUE;
}

static vsi_status vnn_ShowTp5Result
    (
    vsi_nn_graph_t *graph,
    vsi_nn_tensor_t *tensor
    )
{
    vsi_status status = VSI_FAILURE;
    uint32_t i,sz,stride;
    float *buffer = NULL;
    uint8_t *tensor_data = NULL;
    uint32_t MaxClass[5];
    float fMaxProb[5];

    sz = 1;
    for(i = 0; i < tensor->attr.dim_num; i++)
    {
        sz *= tensor->attr.size[i];
    }

    stride = vsi_nn_TypeGetBytes(tensor->attr.dtype.vx_type);
    tensor_data = (uint8_t *)vsi_nn_ConvertTensorToData(graph, tensor);
    buffer = (float *)malloc(sizeof(float) * sz);

    for(i = 0; i < sz; i++)
    {
        status = vsi_nn_DtypeToFloat32(&tensor_data[stride * i], &buffer[i], &tensor->attr.dtype);
    }

    if (!vnn_GetTop(buffer, fMaxProb, MaxClass, sz, 5))
    {
        printf("Fail to show result.\n");
        goto final;
    }

    printf(" --- Top5 ---\n");
    for(i=0; i<5; i++)
    {
        printf("%3d: %8.6f\n", MaxClass[i], fMaxProb[i]);
    }
    status = VSI_SUCCESS;

final:
    if(tensor_data)vsi_nn_Free(tensor_data);
    if(buffer)free(buffer);
    return status;
}

vsi_status vnn_PostProcessResnet50Caffe(vsi_nn_graph_t *graph)
{
    vsi_status status = VSI_FAILURE;

    /* Show the top5 result */
    status = vnn_ShowTp5Result(graph, vsi_nn_GetTensor(graph, graph->output.tensors[0]));
    _CHECK_STATUS(status, final);

    /* Save all output tensor data to txt file */
    vnn_SaveOutputData(graph);

final:
    return VSI_SUCCESS;
}
