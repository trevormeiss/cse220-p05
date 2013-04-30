//**************************************************************************************************************
// CLASS: DListData.hpp
//
// DESCRIPTION
// Data type of the data in each element of the DList.
//
// AUTHOR INFORMATION
// Kevin R. Burger [KRB]
//
// Mailing Address:
// Computer Science & Engineering
// School of Computing, Informatics, and Decision Systems Engineering
// Arizona State University
// Tempe, AZ 85287-8809
//
// Email: burgerk@asu
// Web:   http://kevin.floorsoup.com
//**************************************************************************************************************
#ifndef DLISTDATA_HPP
#define DLISTDATA_HPP

//==============================================================================================================
//  TYPE DEFINITIONS
//==============================================================================================================

// In an attempt to make the code for the DList class fairly generic, i.e., reusable, the data type of the data
// stored in each node is specified using this tDListData type. To change the data type of the data stored in
// each node, simply modify this typedef statement to change the type of tDListData and rebuild.

typedef int tDListData;

// TEMPLATES
// Note: the proper way to create a generic data structure, such as this DList class, is to use C++ templates.
// I would dearly love to have the time to teach templates in CSE220, but I don't, and rather than trying to
// squeeze it in -- and not have enough time to teach it well -- I simply omit the concept. So, what you should
// leave CSE220 knowing is that C++ has these things called templates (see the references for some high-level
// and not-so-high-level overviews) and that the Standard Template Library (STL) is a significant part of the
// C++ Standard Library, and the STL provides numerous templated classes for implementing, primarily, container
// types, i.e., various data structures such as lists, stacks, queues, trees, etc.
//
// When you get into CSE310 and other upper division courses, but particularly in CSE310, you should learn
// templates and practice writing code using them. It's a valuable C++ skill, and one that many employers will
// expect you to be -- at least somewhat -- familiar with.
//
// References:
// 1. https://en.wikipedia.org/wiki/Template_(C++)
// 2. http://www.yolinux.com/TUTORIALS/Cpp-Templates.html
// 3. http://www.parashift.com/c++-faq/templates.html

#endif
