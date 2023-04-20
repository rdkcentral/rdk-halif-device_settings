/*
 * If not stated otherwise in this file or this component's Licenses.txt file the
 * following copyright and licenses apply:
 *
 * Copyright 2016 RDK Management
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
*/
 


/**
* @defgroup devicesettings Device Settings
* @{
* @defgroup hal Device Settings HAL
* @{
**/


#ifndef _DS_VIDEORESOLUTIONSETTINGS_H_
#define _DS_VIDEORESOLUTIONSETTINGS_H_

#include "dsTypes.h"

#ifdef __cplusplus
extern "C" {
namespace {
#endif


#define  _INTERLACED true   ///< Video format is interlaced.
#define _PROGRESSIVE false  ///< Video format is progressive.

#define dsVideoPortRESOLUTION_NUMMAX 32 ///< Max port number.

/* List all supported resolutions here */

static dsVideoPortResolution_t kResolutions[] = {
{   /*480i*/
    /*.name = */                "480i",
    /*.pixelResolution = */     dsVIDEO_PIXELRES_720x480,   
                                    ///< See dsVideoResolution_t
    /*.aspectRatio = */         dsVIDEO_ASPECT_RATIO_4x3,   
                                    ///< See dsVideoAspectRatio_t
    /*.stereoscopicMode = */    dsVIDEO_SSMODE_2D,          
                                    ///< See dsVideoStereoScopicMode_t
    /*.frameRate = */           dsVIDEO_FRAMERATE_29dot97,  
                                    ///< See dsVideoFrameRate_t
    /*.interlaced = */          _INTERLACED,                
                                    ///< Video format. True for interlaced, false for progressive.
},
{   /*480p*/
    /*.name = */                "480p",
    /*.pixelResolution = */     dsVIDEO_PIXELRES_720x480,   
                                    ///< See dsVideoResolution_t
    /*.aspectRatio = */         dsVIDEO_ASPECT_RATIO_4x3,   
                                    ///< See dsVideoAspectRatio_t
    /*.stereoscopicMode = */    dsVIDEO_SSMODE_2D,          
                                    ///< See dsVideoStereoScopicMode_t
    /*.frameRate = */           dsVIDEO_FRAMERATE_59dot94,  
                                    ///< See dsVideoFrameRate_t
    /*.interlaced = */          _PROGRESSIVE,               
                                    ///< Video format. True for interlaced, false for progressive.
},
{   /*720i*/
    /*.name = */                "576p50",
    /*.pixelResolution = */     dsVIDEO_PIXELRES_720x576,   
                                    ///< See dsVideoResolution_t. 
    /*.aspectRatio = */         dsVIDEO_ASPECT_RATIO_4x3,   
                                    ///< See dsVideoAspectRatio_t
    /*.stereoscopicMode = */    dsVIDEO_SSMODE_2D,          
                                    ///< See dsVideoStereoScopicMode_t
    /*.frameRate = */           dsVIDEO_FRAMERATE_50,       
                                    ///< See dsVideoFrameRate_t
    /*.interlaced = */          _PROGRESSIVE,               
                                    ///< Video format. True for interlaced, false for progressive.
},
{   /*720p - Default - AutoSelect */
    /*.name = */                "720p",
    /*.pixelResolution = */     dsVIDEO_PIXELRES_1280x720,  
                                    ///< See dsVideoResolution_t 
    /*.aspectRatio = */         dsVIDEO_ASPECT_RATIO_16x9,  
                                    ///< See dsVideoAspectRatio_t
    /*.stereoscopicMode = */    dsVIDEO_SSMODE_2D,          
                                    ///< See dsVideoStereoScopicMode_t
    /*.frameRate = */           dsVIDEO_FRAMERATE_59dot94,  
                                    ///< See dsVideoFrameRate_t
    /*.interlaced = */          _PROGRESSIVE,               
                                    ///< Video format. True for interlaced, false for progressive.
},
{   /*720p - Default - AutoSelect */
    /*.name = */                "720p50",
    /*.pixelResolution = */     dsVIDEO_PIXELRES_1280x720,  
                                    ///< See dsVideoResolution_t 
    /*.aspectRatio = */         dsVIDEO_ASPECT_RATIO_16x9,  
                                    ///< See dsVideoAspectRatio_t
    /*.stereoscopicMode = */    dsVIDEO_SSMODE_2D,          
                                    ///< See dsVideoStereoScopicMode_t
    /*.frameRate = */           dsVIDEO_FRAMERATE_50,       
                                    ///< See dsVideoFrameRate_t
    /*.interlaced = */          _PROGRESSIVE,               
                                    ///< Video format. True for interlaced, false for progressive.
},
{   /*1080p24*/
    /*.name = */                "1080p24",
    /*.pixelResolution = */     dsVIDEO_PIXELRES_1920x1080, 
                                    ///< See dsVideoResolution_t  
    /*.aspectRatio = */         dsVIDEO_ASPECT_RATIO_16x9,  
                                    ///< See dsVideoAspectRatio_t
    /*.stereoscopicMode = */    dsVIDEO_SSMODE_2D,          
                                    ///< See dsVideoStereoScopicMode_t
    /*.frameRate = */           dsVIDEO_FRAMERATE_50,       
                                    ///< See dsVideoFrameRate_t
    /*.interlaced = */          _PROGRESSIVE,               
                                    ///< Video format. True for interlaced, false for progressive.
},
{   /*1080p60*/
    /*.name = */                "1080p60",
    /*.pixelResolution = */     dsVIDEO_PIXELRES_1920x1080, 
                                    ///< See dsVideoResolution_t  
    /*.aspectRatio = */         dsVIDEO_ASPECT_RATIO_16x9,  
                                    ///< See dsVideoAspectRatio_t
    /*.stereoscopicMode = */    dsVIDEO_SSMODE_2D,          
                                    ///< See dsVideoStereoScopicMode_t
    /*.frameRate = */           dsVIDEO_FRAMERATE_59dot94,  
                                    ///< See dsVideoFrameRate_t
    /*.interlaced = */          _PROGRESSIVE,               
                                    ///< Video format. True for interlaced, false for progressive.
},
{   /*1080i*/
    /*.name = */                "1080i50",
    /*.pixelResolution = */     dsVIDEO_PIXELRES_1920x1080, 
                                    ///< See dsVideoResolution_t  
    /*.aspectRatio = */         dsVIDEO_ASPECT_RATIO_16x9,  
                                    ///< See dsVideoAspectRatio_t
    /*.stereoscopicMode = */    dsVIDEO_SSMODE_2D,          
                                    ///< See dsVideoStereoScopicMode_t
    /*.frameRate = */           dsVIDEO_FRAMERATE_50,       
                                    ///< See dsVideoFrameRate_t
    /*.interlaced = */          _INTERLACED,                
                                    ///< Video format. True for interlaced, false for progressive.
},
{   /*1080p30*/
    /*.name = */                "1080i",
    /*.pixelResolution = */     dsVIDEO_PIXELRES_1920x1080, 
                                    ///< See dsVideoResolution_t  
    /*.aspectRatio = */         dsVIDEO_ASPECT_RATIO_16x9,  
                                    ///< See dsVideoAspectRatio_t
    /*.stereoscopicMode = */    dsVIDEO_SSMODE_2D,          
                                    ///< See dsVideoStereoScopicMode_t
    /*.frameRate = */           dsVIDEO_FRAMERATE_59dot94,  
                                    ///< See dsVideoFrameRate_t
    /*.interlaced = */          _INTERLACED,                
                                    ///< Video format. True for interlaced, false for progressive.
},
};

static const int kDefaultResIndex = 3; //Pick one resolution from kResolutions[] as default

#ifdef __cplusplus
}
}
#endif

#endif /* VIDEORESOLUTIONSETTINGS_H_ */


/** @} */
/** @} */
