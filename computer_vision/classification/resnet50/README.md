*******************************************************************************
##### Structure of the directory for storing model files
```
computer_vision
   |-- classification   
       |-- Alexnet
            |--README.md            
            |--res50   
            |--CMakeLists.txt   
            |--src
            |--include
            |--
```
*******************************************************************************

  test results:

[TRAINER]Running 1 Testing Steps
[TRAINER]TEST SAMPLE[[2/2]] TIME[[0.808725]] TOP1 accuracy rate 1.00 (Error num: 0/0)
[TRAINER]Validation Top1 Accuracy: 100.0%
[TRAINER]Validation Top5 Accuracy: 100.0%


*******************************************************************************
#### Model Description

Image classification inference model

##### Original Network Link:



##### Pre-trained Model Link:




##### Input Data Description:

The input image should be resized to 227*227 pixels, and padding to 256*224 pixels, YUV420SP_U8.

##### Out Data Description:

The pre-trained model is trained for image recognition，the result follow 1000 lables of ImageNet.

