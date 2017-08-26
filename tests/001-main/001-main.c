/* 001-main.c	Sun Mar  3 2013 18:06:54 tmm */

/*

Module:  001-main.c

Function:
	Test for oversee -- simplest possible configuration.

Version:
	V0.91a	Sun Mar  3 2013 18:06:54 tmm	Edit level 1

Copyright notice:
	This file copyright (C) 2013 by

		Terrill Moore
		3170 Perry City Road
		Trumansburg, NY  14886

	An unpublished work.  All rights reserved.
	
	This file is proprietary information, and may not be disclosed or
	copied without the prior permission of Terrill Moore.
 
Author:
	Terry Moore	March 2013

Revision history:
   0.91a  Sun Mar  3 2013 18:06:54  tmm
	Module created.

*/

#include <stdio.h>
#include <stdlib.h>

#include "oversee.h"

/****************************************************************************\
|
|		Manifest constants & typedefs.
|
|	This is strictly for private types and constants which will not 
|	be exported.
|
\****************************************************************************/

static OVERSEE_SUITE_DRIVER_FN SuiteDriver;

/****************************************************************************\
|
|	Read-only data.
|
|	If program is to be ROM-able, these must all be tagged read-only 
|	using the ROM storage class; they may be global.
|
\****************************************************************************/



/****************************************************************************\
|
|	VARIABLES:
|
|	If program is to be ROM-able, these must be initialized
|	using the BSS keyword.  (This allows for compilers that require
|	every variable to have an initializer.)  Note that only those 
|	variables owned by this module should be declared here, using the BSS
|	keyword; this allows for linkers that dislike multiple declarations
|	of objects.
|
\****************************************************************************/

int main(
	int argc,
	char **argv
	)
	{
	OVERSEE_SUITE *pSuite;
	OVERSEE_BOOL fResult;
	
	pSuite = Oversee_StaticInit();

	fResult = OverseeSuite_RunTests(pSuite, SuiteDriver, NULL);

	return fResult ? EXIT_SUCCESS : EXIT_FAILURE;
	}

void
SuiteDriver(
	OVERSEE_SUITE *pSuite,
	void *pContext_void
	)
	{
	/* nothing */
	}
