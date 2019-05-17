*******************************************************************************
##### Structure of the directory for storing model files
```
computer_vision
   |-- classification   
       |-- Alexnet
       |-- resnet50
       |-- vgg16
       |-- bvlc_googlenet
       |-- inceptionV1
       |-- inceptionV2
       |-- inceptionV3
       |-- inceptionV4
```
*******************************************************************************

模型转换方法：

下载好模型

1 在命令行输入./import.sh导入模型 ，tensorflow需要--tf-pb文件，caffe的输入需要--caffe-model与--caffe-blob

2 ./quantize.sh 量化模型，注意输入的模型名字

3 ./export.sh 即可输入ovx_src文件夹，生成的头文件和c文件

4.Cmake编译.h和.c文件，生成可执行文件

*******************************************************************************
#### Model Description

Image classification inference model




