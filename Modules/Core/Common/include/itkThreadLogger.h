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
#ifndef __itkThreadLogger_h
#define __itkThreadLogger_h

#include "itkMultiThreader.h"
#include "itkLogger.h"
#include "itkSimpleFastMutexLock.h"

#include <string>
#include <queue>

namespace itk
{
/** \class ThreadLogger
 *  \brief Class ThreadLogger is meant for providing logging service
 *  as a separate thread.
 *
 *
 * \author Hee-Su Kim, Compute Science Dept. Kyungpook National University,
 *                     ISIS Center, Georgetown University.
 *
 *
 *  \ingroup OSSystemObjects LoggingObjects
 */

class ITKCommon_EXPORT ThreadLogger:public Logger
{
public:

  typedef ThreadLogger               Self;
  typedef Logger                     Superclass;
  typedef SmartPointer< Self >       Pointer;
  typedef SmartPointer< const Self > ConstPointer;

  /** Run-time type information (and related methods). */
  itkTypeMacro(ThreadLogger, Logger);

  /** New macro for creation of through a Smart Pointer */
  itkNewMacro(Self);

  typedef  Logger::OutputType OutputType;

  typedef  Logger::PriorityLevelType PriorityLevelType;

  /** Definition of types of operations for ThreadLogger. */
  typedef enum {
    SET_PRIORITY_LEVEL,
    SET_LEVEL_FOR_FLUSHING,
    ADD_LOG_OUTPUT,
    WRITE,
    FLUSH
    } OperationType;

  /** Set the priority level for the current logger. Only messages that have
   * priorities equal or greater than the one set here will be posted to the
   * current outputs */
  virtual void SetPriorityLevel(PriorityLevelType level);

  /** Get the priority level for the current logger. Only messages that have
   * priorities equal or greater than the one set here will be posted to the
   * current outputs */
  virtual PriorityLevelType GetPriorityLevel() const;

  virtual void SetLevelForFlushing(PriorityLevelType level);

  virtual PriorityLevelType GetLevelForFlushing() const;

  /** Registers another output stream with the multiple output. */
  virtual void AddLogOutput(OutputType *output);

  virtual void Write(PriorityLevelType level, std::string const & content);

  virtual void Flush();

protected:

  /** Constructor */
  ThreadLogger();

  /** Destructor */
  virtual ~ThreadLogger();

  /** Print contents of a ThreadLogger */
  virtual void PrintSelf(std::ostream & os, Indent indent) const;

  static ITK_THREAD_RETURN_TYPE ThreadFunction(void *);

private:

  typedef std::queue< OperationType > OperationContainerType;

  typedef std::queue< std::string > MessageContainerType;

  typedef std::queue< PriorityLevelType > LevelContainerType;

  typedef std::queue< OutputType::Pointer > OutputContainerType;

  MultiThreader::Pointer m_Threader;

  int m_ThreadID;

  OperationContainerType m_OperationQ;

  MessageContainerType m_MessageQ;

  LevelContainerType m_LevelQ;

  OutputContainerType m_OutputQ;

  SimpleFastMutexLock m_Mutex;

  SimpleFastMutexLock m_WaitMutex;
};  // class ThreadLogger
} // namespace itk

#endif  // __itkThreadLogger_h
