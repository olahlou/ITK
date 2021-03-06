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
#ifndef __itkTreeNode_h
#define __itkTreeNode_h

#include <vector>
#include <algorithm>
#include <iostream>
#include "itkObject.h"
#include "itkObjectFactory.h"
#include "itkIntTypes.h"

namespace itk
{
/** \class TreeNode
 *  \brief TreeNode class
 *
 * This class derives from the Object class.
 *
 * The class is templated over the type of the elements.
 *
 * Template parameters for class TreeNode:
 *
 * - TValueType = Element type stored in the node
 *
 * \ingroup DataRepresentation
 */
template< class TValueType >
class TreeNode:public Object
{
public:

  /** Standard typedefs */
  typedef Object                     Superclass;
  typedef TreeNode< TValueType >     Self;
  typedef SmartPointer< Self >       Pointer;
  typedef SmartPointer< const Self > ConstPointer;
  typedef std::vector< Pointer >     ChildrenListType;
  typedef ::itk::OffsetValueType     ChildIdentifier;

  /** Method for creation through the object factory. */
  itkNewMacro(Self);

  /** Run-time type information (and related methods). */
  itkTypeMacro(TreeNode, Object);

  /** Get the value of the node */
  const TValueType & Get() const;

  /** Set the current value of the node */
  TValueType Set(const TValueType data);

  /** Get the child node */
  TreeNode< TValueType > * GetChild(ChildIdentifier number) const;

  /** Get the parent node */
  TreeNode< TValueType > * GetParent() const;

  /** Return true if the node has children */
  bool HasChildren() const;

  /** Return true if the node has a parent */
  bool HasParent() const;

  /** Set the parent of the node */
  void SetParent(TreeNode< TValueType > *n);

  /** Return the number of children */
  ChildIdentifier CountChildren() const;

  /** Remove a node from the node */
  bool Remove(TreeNode< TValueType > *n);

  /** Get the number of children given a name and depth */
  ChildIdentifier GetNumberOfChildren(unsigned int depth = 0, char *name = NULL) const;

  /** Replace a given child by a new one */
  bool ReplaceChild(TreeNode< TValueType > *oldChild, TreeNode< TValueType > *newChild);

  /** Return the child position given a node */
  ChildIdentifier ChildPosition(const TreeNode< TValueType > *node) const;

  /** Return the child position given a value */
  ChildIdentifier ChildPosition(TValueType node) const;

  /** Add a child to the node */
  void AddChild(TreeNode< TValueType > *node);

  /** Add a child to the node and specify the number in the children list */
  virtual void AddChild(ChildIdentifier number, TreeNode< TValueType > *node);

  /** Get the children list */
#if !defined( CABLE_CONFIGURATION )
  virtual ChildrenListType * GetChildren(unsigned int depth = 0, char *name = NULL) const;

#endif

  /** Get the internal list of children */
#if !defined( CABLE_CONFIGURATION )
  virtual ChildrenListType & GetChildrenList() { return m_Children; }
#endif

  /** Set the data of the node */
  //virtual void SetData(TValueType data) {m_Data = data;}
protected:

  TreeNode();
  virtual ~TreeNode();
  TValueType m_Data;

  Self *m_Parent;

  ChildrenListType m_Children;
private:
  TreeNode(const Self &);       //purposely not implemented
  void operator=(const Self &); //purposely not implemented
};
} // end namespace itk

// Define instantiation macro for this template.
#define ITK_TEMPLATE_TreeNode(_, EXPORT, TypeX, TypeY)     \
  namespace itk                                            \
  {                                                        \
  _( 1 ( class EXPORT TreeNode< ITK_TEMPLATE_1 TypeX > ) ) \
  namespace Templates                                      \
  {                                                        \
  typedef TreeNode< ITK_TEMPLATE_1 TypeX >                 \
  TreeNode##TypeY;                                       \
  }                                                        \
  }

#if ITK_TEMPLATE_EXPLICIT
#include "Templates/itkTreeNode+-.h"
#endif

#if ITK_TEMPLATE_TXX
#include "itkTreeNode.txx"
#endif

#endif
