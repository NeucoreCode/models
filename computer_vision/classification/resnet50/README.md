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

Verify...
Verify Graph: 1236ms or 1236553us
Start run graph [1] times...
Run the 1 time: 29ms or 29905us
vxProcessGraph execution time:
Total   29ms or 29962us
Average 29.00ms or 29962.00us
 --- Top5 ---
  1: 0.997559
115: 0.001925
794: 0.000123
721: 0.000096
 -1: 0.000000


*******************************************************************************
#### Model Description

Image classification inference model

##### Original Network Link:



##### Pre-trained Model Link:




##### Input Data Description:

The input image should be resized to 227*227 pixels, and padding to 256*224 pixels, YUV420SP_U8.

##### Out Data Description:

The pre-trained model is trained for image recognition，the result follow 1000 lables of ImageNet.

