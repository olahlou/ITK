/*==========================================================================

  Program:   Insight Segmentation & Registration Toolkit
  Module:    itkUpwindDerivativeImageFunction.h
  Language:  C++
  Date:      $Date$
  Version:   $Revision$
Copyright (c) 2001 Insight Consortium
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

 * Redistributions of source code must retain the above copyright notice,
   this list of conditions and the following disclaimer.

 * Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation
   and/or other materials provided with the distribution.

 * The name of the Insight Consortium, nor the names of any consortium members,
   nor of any contributors, may be used to endorse or promote products derived
   from this software without specific prior written permission.

  * Modified source versions must be plainly marked as such, and must not be
    misrepresented as being the original software.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDER AND CONTRIBUTORS ``AS IS''
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHORS OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

=========================================================================*/
#ifndef _itkUpwindDerivativeImageFunction_h
#define _itkUpwindDerivativeImageFunction_h

#include "itkImageFunction.h"

namespace itk
{

/**
 * \class UpwindDerivativeImageFunction
 * \brief Calculate the derivative using only upwind neighbors.
 *
 * UpwindDerivativeImageFunction calculates a derivative using only upwind
 * neighbors. The flow direction can be specified by the sign of
 * the speed value set via the SetSpeed() method.
 *
 * If the speed is positive, the backward difference operator is
 * used. If speed is negative, the forward difference operator is
 * used.
 *
 * This class is templated over the input image type.
 *
 * Reference:
 * "Level Set Methods and Fast Marching Methods", J.A. Sethian,
 * Cambridge Press, Chapter 6, Second edition, 1999.
 *
 * Possible improvements:
 * - the use of Neighborhood operators may improve efficiency.
 *
 * \ingroup Functions
 */
template <class TInputImage >
class ITK_EXPORT UpwindDerivativeImageFunction :
  public ImageFunction< TInputImage, double >
{
public:
  /**
   * Standard "Self" typedef
   */
  typedef UpwindDerivativeImageFunction Self;

  /**
   * Standard "Superclass" typedef
   */
  typedef ImageFunction<TInputImage, double> Superclass;

  /**
   * Smart pointer typedef support.
   */
  typedef SmartPointer<Self> Pointer;
  typedef SmartPointer<const Self>  ConstPointer;

  /** 
   * Run-time type information (and related methods).
   */
  itkTypeMacro(UpwindDerivativeImageFunction, ImageFunction);

  /**
   * Method for creation through the object factory.
   */
  itkNewMacro(Self);

  /**
   * InputImageType typedef support.
   */
  typedef TInputImage InputImageType;

  /**
   * Dimension of the underlying image.
   */
  enum { ImageDimension = InputImageType::ImageDimension };

  /**
   * Index typedef support.
   */
  typedef typename Superclass::IndexType IndexType;

  /**
   * ContinuousIndex typedef support.
   */
  typedef typename Superclass::ContinuousIndexType ContinuousIndexType;

  /**
   * Point typedef support.
   */
  typedef typename Superclass::PointType PointType;
 
  /**
   * Set the input image.
   */
  virtual void SetInputImage( const InputImageType * ptr );

  /**
   * Set the speed parameter.
   */
  virtual void SetSpeed( double value )
  { m_Speed = value; }

  /**
   * Get the speed parameter.
   */
  virtual double GetSpeed() const
    { return m_Speed; }

  /**
   * Evalulate the function at specified index
   */
  virtual double EvaluateAtIndex( const IndexType& index ) const
    { return ( this->EvaluateAtIndex( index, 0 ) ); }

  /**
   * Evaluate the function at non-integer positions
   */
  virtual double Evaluate( const PointType& point ) const
    { 
      IndexType index;
      this->ConvertPointToNearestIndex( point, index );
      return this->EvaluateAtIndex( index, 0 ); 
    }

  virtual double EvaluateAtContinuousIndex( 
    const ContinuousIndexType& cindex ) const
    { 
      IndexType index;
      this->ConvertContinuousIndexToNearestIndex( cindex, index );
      return this->EvaluateAtIndex( index, 0 ) ; 
    }

  /**
   * Evalulate the function at specified index
   */
  virtual double EvaluateAtIndex( const IndexType& index, 
                           unsigned int dim = 0 ) const;

  /**
   * Get the derivative from last evaluation
   */
  virtual double GetDerivative() const
  { return m_Derivative; }

protected:
  UpwindDerivativeImageFunction(){};
  ~UpwindDerivativeImageFunction(){};
  void PrintSelf(std::ostream& os, Indent indent) const;

  double                  m_Speed;
  mutable double          m_Derivative;

private:
  Self(const Self&); //purposely not implemented
  void operator=(const Self&); //purposely not implemented

  signed long             m_ImageSize[ImageDimension];
  bool                    m_ImageSizeOK;

  mutable IndexType       m_NeighIndex;
  mutable double          m_CenterValue;
  mutable double          m_DiffValue;

};

} // namespace itk

#ifndef ITK_MANUAL_INSTANTIATION
#include "itkUpwindDerivativeImageFunction.txx"
#endif

#endif

