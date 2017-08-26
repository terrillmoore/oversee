/* oversee_internals.h	Sun Mar  3 2013 18:19:19 tmm */

/*

Module:  oversee_internals.h

Function:
	The internal structures for the Oversee unit test system.

Version:
	V0.91a	Sun Mar  3 2013 18:19:19 tmm	Edit level 1

Copyright notice:
	This file copyright (C) 2013 by

		Terrill Moore
		3170 Perry City Road
		Trumansburg, NY  14886

	An unpublished work.  All rights reserved.
	
	This file is proprietary information, and may not be disclosed or
	copied without the prior permission of Terrill Moore.
 
Author:
	Terry Moore, Terrill Moore	March 2013

Revision history:
   0.91a  Sun Mar  3 2013 18:19:19  tmm
	Module created.

*/

#ifndef OVERSEE_INTERNALS_H__		/* prevent multiple includes */
#define OVERSEE_INTERNALS_H__

#ifndef OVERSEE_TYPES_H__
# include "oversee_types.h"
#endif

/****************************************************************************\
|
|	The overall OVERSEE_CONTEXT structure
|
\****************************************************************************/

struct OVERSEE_CONTEXT_s
	{
	/*
	|| There is intended to only one test suite per instance, but
	|| that's not actaully a requirement.  But since only one suite
	|| can be active per oversee instance, we only have memory for one.
	*/
	OVERSEE_SUITE	CurrentSuite;

	/*
	|| We expect to have multiple fixtures per instance, but only one
	|| active at a time. So we only have memory for one live instance.
	*/
	OVERSEE_FIXTURE	CurrentFixture;

	/*
	|| The platform pointers live separately so we don't have to have
	|| the structure in scope unless we really need it.
	*/
	OVERSEE_PLATFORM_API *pPlatform;

	/*
	|| The result stream API pointers similarly live separately, so we
	|| don't have to have things in scope.
	*/
	OVERSEE_RESULT_STREAM_API *pResultStream;

	/*
	|| we count the number of failures.
	*/
	unsigned	nTestsFailed;

	/*
	|| we count the number of tests run here.
	*/
	unsigned	nTestsRun;

	/*
	|| similarly, we count the number of fixtures failed/run
	*/
	unsigned	nFixturesFailed;
	unsigned	nFixturesRun;

	/*
	|| finally, the number of suites failed/run
	*/
	unsigned	nSuitesFailed;
	unsigned	nSuitesRun;
	};

/**** end of oversee_internals.h ****/
#endif /* OVERSEE_INTERNALS_H_ */
