/*=========================================================================

 medInria

 Copyright (c) INRIA 2013 - 2014. All rights reserved.
 See LICENSE.txt for details.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

=========================================================================*/

#include <medItkMorphomathOperationProcessPlugin.h>

#include <medCore.h>
#include <medItkOpeningImageProcess.h>
#include <medItkClosingImageProcess.h>
#include <medItkDilateImageProcess.h>
#include <medItkErodeImageProcess.h>

void medItkMorphomathOperationProcessPlugin::initialize(void)
{
    medCore::morphomathOperation::openingImage::pluginFactory().record(medItkOpeningImageProcess::staticMetaObject.className()
                                                                     , medItkOpeningImageProcessCreator);
    medCore::morphomathOperation::closingImage::pluginFactory().record(medItkClosingImageProcess::staticMetaObject.className()
                                                                          , medItkClosingImageProcessCreator);
    medCore::morphomathOperation::dilateImage::pluginFactory().record(medItkDilateImageProcess::staticMetaObject.className()
                                                                          , medItkDilateImageProcessCreator);
    medCore::morphomathOperation::erodeImage::pluginFactory().record(medItkErodeImageProcess::staticMetaObject.className()
                                                                        , medItkErodeImageProcessCreator);
}

void medItkMorphomathOperationProcessPlugin::uninitialize(void)
{

}
DTK_DEFINE_PLUGIN(medItkOpeningImageProcess)
DTK_DEFINE_PLUGIN(medItkClosingImageProcess)
DTK_DEFINE_PLUGIN(medItkDilateImageProcess)
DTK_DEFINE_PLUGIN(medItkErodeImageProcess)
