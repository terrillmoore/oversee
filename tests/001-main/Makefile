##############################################################################
#
# Module:  Makefile
#
# Function:
#	Bsdmake/pmake file for building the tests in this directory. Not 
#	necessarily an mcci bsdmake file!
#
# Version:
#	V0.91a	Thu Oct 17 2013 15:28:12 tmm	Edit level 1
#
# Copyright notice:
#	This file copyright (C) 2013 by
#
#		MCCI Corporation
#		3520 Krums Corners Road
#		Ithaca, NY  14850
#
#	An unpublished work.  All rights reserved.
#
#	This file is proprietary information, and may not be disclosed
#	or copied without the prior permission of MCCI Corporation.
#
# Author:
#	Terry Moore, MCCI Corporation	October 2013
#
# Revision History:
#    0.91a  Thu Oct 17 2013 15:28:12  tmm
#	Module created.
#
##############################################################################

##############################################################################
#
# 	This test supports native and cross compiles, so it's complex.
#
#	H_* symbols are "host"... T_* symbols are "target".  T_CC is the CC
#	for the target.  Have to be careful becu
#
##############################################################################


##############################################################################
#
#	Setup when running on x86
#
##############################################################################

.if ${MACHINE_ARCH} == w32x86
. ifndef MAKESHELL
.  echo Warning: MAKESHELL not set, shell operations won't work.
. endif

# figure out the OS setup
H_OS != if [ -r /dev/null ]; then echo cygwin ; else echo Win32 ; fi
_X ?= .exe
H_CPU = i386

. if ${H_OS} == "Win32"
MKDIR_P = mkdir
ECHO = echo -r
. endif

##############################################################################
#
#	Setup for other than mccimake and Windows
#
##############################################################################

.else # not w32x86
H_OS = ${MACHINE_ARCH}
_X ?=
.endif

ECHO ?= echo
MKDIR_P ?= mkdir -p

.ifndef H_OS
H_OS != uname
.endif
.ifndef H_CPU
H_CPU != uname -m
.endif

##############################################################################
#
# Set up for non-Windows, assuming not cross-compiling.	
#
##############################################################################

# allow simple overrides
.ifndef T_CC
. ifdef CC
T_CC := ${CC}
. else
.  error Either T_CC or CC must be defined.
. endif
.endif

.ifndef T_OS
# set T_OS to the current target
T_OS := ${H_OS}
.endif

.ifndef T_CPU
T_CPU := ${H_CPU}
.endif

# turn off all built-in suffix processing
.SUFFIXES:

##############################################################################
#
#	Customize based on target compiler.
#
##############################################################################

# T_CPU, T_OS, T_CC specifiy the target CPU, target OS, target compiler
# T_CC == cl implies that we're using Microsoft C.

#### set up for Microsoft C ####
.if ${T_CC} == cl
O ?= obj
A ?= lib
CFLAGS ?= -WX -W4
CPPFLAGS ?= -I ../../i
LD_EXT ?= exe
.SUFFIXES:	.c .$O .$A .${LD_EXT}

#### set up for non-MSC but on Windows ####
.elif ${T_OS} == "w32" || ${T_OS} == "cygwin"
O ?= o
A ?= a
CFLAGS ?= -Wall -Werror
CPPFLAGS += -I ../../i
LD_EXT ?= exe
.SUFFIXES:	.c .$O .$A .${LD_EXT}

#### set up for all other cases ####
.else
O ?= o
A ?= a
CFLAGS ?= -Wall -Werror
CPPFLAGS += -I ../../i
LD_EXT ?=
BUILDNULL ?= out
.SUFFIXES:	.c .$O .$A
.NULL: .${BUILDNULL}
.endif

#### Handle the extension for executable files ####
.if empty(LD_EXT)
  .LD_EXT =	# nothing
.else
  .LD_EXT := .${LD_EXT}
.endif

#
# The compilation rules
#
COMPILE.c?=	${CC} ${CFLAGS} ${CPPFLAGS} -c
LINK.c?=	${CC} ${CFLAGS} ${CPPFLAGS} ${LDFLAGS}

COMPILE.cc?=	${CXX} ${CXXFLAGS} ${CPPFLAGS} -c
LINK.cc?=	${CXX} ${CXXFLAGS} ${CPPFLAGS} ${LDFLAGS}

CPP?=		cpp
CPPFLAGS?=	

#
# Deal with target locations.
#
BUILDCURDIR =	.

# BUILDTREE is where we intend to build, generally speaking
.ifndef BUILDTREE
BUILDTREE ?=	${BUILDCURDIR}/../../build
.endif
BUILDROOT ?=	${BUILDTREE}/${T_CPU}/${T_OS}/${T_CC}

# T_OBJDIR is where we'll put the objects in the BUILDTREE
T_OBJDIR =	${BUILDROOT}/${.CURDIR:H:T}/${.CURDIR:T}

# Vefify that we have a BUILDTREE directory
_TEST != if [ -d ${BUILDTREE} ]; then echo yes; else echo no; fi
.if ${_TEST} != yes
. error BUILDTREE must point to an existing directory: ${BUILDTREE}
.endif

# Verify that we have an specific T_OBJDIR, and create if not.
_TEST != if [ -d ${T_OBJDIR} ]; then echo yes; else echo no; fi
.if ${_TEST} != yes
. echo Creating T_OBJDIR: ${T_OBJDIR}
_STATUS != if ${MKDIR_P} ${T_OBJDIR} ; then echo yes; else echo no; fi
.endif

# verify that the create actually worked.
_TEST != if [ -d ${T_OBJDIR} ]; then echo yes; else echo no; fi
.if ${_TEST} != yes
. error No T_OBJDIR: ${T_OBJDIR}
.endif

.PATH.$O: ${T_OBJDIR}
.PATH.$A: ${T_OBJDIR}
.PATH${.LD_EXT}: ${T_OBJDIR}

.c.$O:
	${COMPILE.c} ${.IMPSRC}
	
##############################################################################
#
#	Finally, the rules that are specifically for this directory.
#	The idea is that eventually the above go to a common include file.
#
##############################################################################

# the library to use for test links
OVERSEE_A = 	../../src/oversee.$A

all:	001-main${.LD_EXT}

001-main.$O:	001-main.c
	${COMPILE.c} -o ${T_OBJDIR}/${.TARGET} ${.ALLSRC}

001-main${.LD_EXT}:	001-main.$O ${OVERSEE_A}
	${LINK.c} -o ${T_OBJDIR}/${.TARGET} ${.ALLSRC}


#### end of Makefile ####
