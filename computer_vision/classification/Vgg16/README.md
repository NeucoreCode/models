*******************************************************************************
##### Structure of the directory for storing model files
```
computer_vision
   |-- classification   
       |-- Alexnet
            |--README.md            
            |--vgg16    
            |--CMakeLists.txt   
            |--src
            |--include
            |--goldfish.jpg
            |--space_shuttle.jpg
```
*******************************************************************************

  test results:

[TRAINER]Running 1 Testing Steps
[TRAINER]TEST SAMPLE[[2/2]] TIME[[1.076832]] TOP1 accuracy rate 1.00 (Error num: 0/0)
[TRAINER]Validation Top1 Accuracy: 100.0%
[TRAINER]Validation Top5 Accuracy: 100.0%


*******************************************************************************
#### Model Description

Image classification inference model



##### Input Data Description:

The input image should be resized to 224*224 pixels.

##### Out Data Description:

The pre-trained model is trained for image recognition，the result follow 1000 lables of ImageNet.




