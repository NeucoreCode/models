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
            |--goldfish.jpeg
            |--space_shuttle.jpg
```
*******************************************************************************

                 test results:
 
Verify...

Verify Graph: 123ms or 123144us

Start run graph [1] times...

Run the 1 time: 28ms or 28153us

vxProcessGraph execution time:

Total   28ms or 28270us

Average 28.00ms or 28270.00us



 --- Top5 ---
 
  1: 0.935059
  
927: 0.046539

949: 0.003820

963: 0.003820

115: 0.002317




*******************************************************************************
#### Model Description

Image classification inference model


##### Input Data Description:

The input image should be resized to 224*224 pixels.

##### Out Data Description:

The pre-trained model is trained for image recognition，the result follow 1000 lables of ImageNet.




