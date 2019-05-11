/****************************************************************************
*   Generated by ACUITY 3.11.0
*   Match ovxlib 1.0.8
*
*   Neural Network appliction network definition header file
****************************************************************************/

#ifndef _VSI_NN_VGG16CAFFE_H
#define _VSI_NN_VGG16CAFFE_H

#include "vsi_nn_pub.h"

void vnn_ReleaseVgg16Caffe
    (
    vsi_nn_graph_t * graph,
    vsi_bool release_ctx
    );

vsi_nn_graph_t * vnn_CreateVgg16Caffe
    (
    const char * data_file_name,
    vsi_nn_context_t in_ctx
    );

#endif
