/*=========================================================================

  Program:   Insight Segmentation & Registration Toolkit
  Module:    itkObject.h
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
#ifndef __itkObject_h
#define __itkObject_h

#include "itkLightObject.h"
#include "itkEventObject.h"


namespace itk
{
class SubjectImplementation;
class Command;

/** \class Object
 * \brief Base class for most itk classes.
 *
 * Object is the second-highest level base class for most itk objects.
 * It extends the base object functionality of LightObject by
 * implementing callbacks (via object/observer), debug flags/methods,
 * and modification time tracking. Most ITK classes should be a subclas
 * of Object due to the need to keep track of modified time.
 *
 * \ingroup ITKSystemObjects
 * \ingroup DataRepresentation
 */
class ITK_EXPORT Object: public LightObject
{
public:
  /** 
   * Smart pointer typedef support.
   */
  typedef Object              Self;
  typedef SmartPointer<Self>  Pointer;
  typedef SmartPointer<const Self>  ConstPointer;

  /**
   * Standard "Superclass" typedef.
   */
  typedef LightObject  Superclass;

  /**
   * Method for creation through the object factory.
   */
  static Pointer New();

  /** 
   * Standard part of all itk objects.
   */
  itkTypeMacro(Object, LightObject);

  /** 
   * Turn debugging output on. 
   */
  virtual void DebugOn() const;

  /** 
   * Turn debugging output off. 
   */
  virtual void DebugOff() const;
  
  /** 
   * Get the value of the debug flag. 
   */
  bool GetDebug() const;
  
  /** 
   * Set the value of the debug flag. A non-zero value turns debugging on.
   */
  void SetDebug(bool debugFlag) const;
  
  /** 
   * Return this objects modified time. 
   */
  virtual unsigned long GetMTime() const;

  /** 
   * Update the modification time for this object. Many filters rely on the
   * modification time to determine if they need to recompute their data. 
   */
  virtual void Modified() const;
  
  /** 
   * Increase the reference count (mark as used by another object). 
   */
  virtual void Register() const;

  /** 
   * Decrease the reference count (release by another object). 
   */
  virtual void UnRegister() const;

  /** 
   * Sets the reference count (use with care) 
   */
  virtual void SetReferenceCount(int);

  /** 
   * This is a global flag that controls whether any debug, warning
   *  or error messages are displayed. 
   */
  static void SetGlobalWarningDisplay(bool flag);
  static bool GetGlobalWarningDisplay();

  static void GlobalWarningDisplayOn()
    { Object::SetGlobalWarningDisplay(true); }
  static void GlobalWarningDisplayOff()
    { Object::SetGlobalWarningDisplay(false); }
  
  /**
   * Allow people to add/remove/invoke observers (callbacks) to any ITK
   * object. This is an implementation of the subject/observer design
   * pattern. An observer is added by specifying an event to respond to
   * and an itk::Command to execute. It returns an unsigned long tag
   * which can be used later to remove the event or retrieve the
   * command.  The memory for the Command becomes the responsibility of
   * this object, so don't pass the same instance of a command to two
   * different objects 
   */
  unsigned long AddObserver(const EventObject & event, Command *);

 
  /** 
   * Get the command associated with the given tag.  NOTE: This returns
   * a pointer to a Command, but it is safe to asign this to a
   * Command::Pointer.  Since Command inherits from LightObject, at this
   * point in the code, only a pointer or a reference to the Command can
   * be used.  
   */
  Command* GetCommand(unsigned long tag);

  /**
   * Call Execute on all the Commands observing this event id.
   */
  void InvokeEvent( const EventObject & );

  /**
   * Call Execute on all the Commands observing this event id.
   * The actions triggered by this call doesn't modify this object.
   */
  void InvokeEvent( const EventObject & ) const;
 

  /**
   * Remove the observer with this tag value.
   */
  void RemoveObserver(unsigned long tag);

  /**
   * Return true if an observer is registered for this event.
   */
  bool HasObserver( const EventObject & event ) const;

  
protected:
  Object(); 
  virtual ~Object(); 

  /** 
   * Methods invoked by Print() to print information about the object
   * including superclasses. Typically not called by the user (use Print()
   * instead) but used in the hierarchical print process to combine the
   * output of several classes. 
   */
  virtual void PrintSelf(std::ostream& os, Indent indent) const;

private:
  Self(const Self&); //purposely not implemented
  void operator=(const Self&); //purposely not implemented

  /**
   * Enable/Disable debug messages.
   */
  mutable bool m_Debug;
  
  /**
   * Keep track of modification time.
   */
  mutable TimeStamp m_MTime;
  
  /**
   * Global object debug flag.
   */
  static bool m_GlobalWarningDisplay;

  /**
   * Implementation class for Subject/Observer Pattern.
   * This is only allocated if used.
   */
  SubjectImplementation* m_SubjectImplementation;
};
  
} // end namespace itk

#endif

