*******************************************************************************
##### Structure of the directory for storing model files
```
computer_vision
   |-- classification   
       |-- alexnet
            |--README.md            

```
*******************************************************************************


  test results:


Alexnet:
I 812: 0.5358559489250183
I 404: 0.28682297468185425
I 895: 0.056478798389434814
I 908: 0.03425612300634384
I 657: 0.016181446611881256



*******************************************************************************
#### Model Description

Image classification inference model

##### Original Network Link:



##### Pre-trained Model Link:




##### Input Data Description:

The input image should be resized to 227*227 pixels, and padding to 256*224 pixels, YUV420SP_U8.

##### Out Data Description:

The pre-trained model is trained for image recognition，the result follow 1000 lables of ImageNet.

