/*=========================================================================
 *
 *  Copyright Insight Software Consortium
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *         http://www.apache.org/licenses/LICENSE-2.0.txt
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 *=========================================================================*/
#ifndef __itkComplexToModulusImageAdaptor_h
#define __itkComplexToModulusImageAdaptor_h

#include "itkImageAdaptor.h"
#include <complex>

namespace itk
{
namespace Accessor
{
/** \class ComplexToModulusPixelAccessor
 * \brief Give access to the Modulus of a std::complex<> value
 *
 * ComplexToModulusPixelAccessor is templated over an internal type and an
 * external type representation. The internal type is an std::complex<T> and
 * the external part is a type T. This class cast the input applies the function
 * to it and cast the result according to the types defined as template
 * parameters
 *
 * \ingroup ImageAdaptors
 */
template< class TInternalType, class TExternalType >
class ITK_EXPORT ComplexToModulusPixelAccessor
{
public:
  /** External typedef. It defines the external aspect
   * that this class will exhibit. */
  typedef TExternalType ExternalType;

  /** Internal typedef. It defines the internal modulus
   * representation of data. */
  typedef TInternalType InternalType;

  static inline void Set(TInternalType & output, const TExternalType & input)
  { output = (TInternalType)( input ); }

  static inline TExternalType Get(const TInternalType & input)
  {
    return (TExternalType)( vcl_sqrt( input.real() * input.real()
                                      + input.imag() * input.imag() ) );
  }
};
} // end namespace Accessor

/** \class ComplexToModulusImageAdaptor
 * \brief Presents a complex image as being composed of vcl_abs() part
 * of its pixels
 *
 * Additional casting is performed according to the input and output image
 * types following C++ default casting rules.
 *
 * \ingroup ImageAdaptors
 */
template< class TImage, class TOutputPixelType >
class ITK_EXPORT ComplexToModulusImageAdaptor:public
  ImageAdaptor< TImage,
                Accessor::ComplexToModulusPixelAccessor<
                  typename TImage::PixelType,
                  TOutputPixelType >   >
{
public:
  /** Standard class typedefs. */
  typedef ComplexToModulusImageAdaptor Self;
  typedef ImageAdaptor< TImage, Accessor::ComplexToModulusPixelAccessor<
                          typename TImage::PixelType,
                          TOutputPixelType > >  Superclass;

  typedef SmartPointer< Self >       Pointer;
  typedef SmartPointer< const Self > ConstPointer;

  /** Method for creation through the object factory. */
  itkNewMacro(Self);

  /** Run-time type information (and related methods). */
  itkTypeMacro(ComplexToModulusImageAdaptor, ImageAdaptor);
protected:
  ComplexToModulusImageAdaptor() {}
  virtual ~ComplexToModulusImageAdaptor() {}
private:
  ComplexToModulusImageAdaptor(const Self &); //purposely not implemented
  void operator=(const Self &);               //purposely not implemented
};
} // end namespace itk

#endif
