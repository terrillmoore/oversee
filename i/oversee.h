/* oversee.h	Mon Feb 11 2013 02:29:37 tmm */

/*

Module:  oversee.h

Function:
	Header file for embedded unit testing (loosely based on seatest).

Version:
	V0.91a	Mon Feb 11 2013 02:29:37 tmm	Edit level 1

Copyright notice:
	This file copyright (C) 2013 by

		Terrill Moore
		3170 Perry City Road
		Trumansburg, NY  14886

	An unpublished work.  All rights reserved.
	
	This file is proprietary information, and may not be disclosed or
	copied without the prior permission of Terrill Moore.
 
Author:
	Terry Moore	February 2013

Revision history:
   0.91a  Mon Feb 11 2013 02:29:37  tmm
	Module created.

*/

#ifndef OVERSEE_H__		/* prevent multiple includes */
#define OVERSEE_H__

#ifndef OVERSEE_TYPES_H__
# include "oversee_types.h"
#endif

/*

MODULE DOCUMENTATION:	Naming Conventions

All global-namespace symbols defined by OVERSEE begin with "OVERSEE".

Normal industry practice is to use a single leading underscore for symbols 
that are in the global namespace but are not API symbols. For exmaple,
header-file inclusion guards are often named _FOO_H_ (to prevent multiple
includes of foo.h).  However ISO C99 says that any symbol beginning with
_ and uppercase, or double-underscore, is reserved for the implementation.
So OVERSEE uses trailing underscores to distinguish such symbols. Header-
file guard symbols are named OVERSEE_{something}_H__.

For similar reasons, OVERSEE avoids the common practice of using a leading
underscore on a structure tag. Structure tags are all named 
OVERSEE_{STRUCTNAME}_s.  Similarly, union tags are OVERSEE_{UNIONNAME}_u, 
and enum tags are OVERSEE_{ENUM}_e.  So, for example, the declaration
of the OVERSEE_TEST structure is 

.	typedef struct OVERSEE_TEST_s OVERSEE_TEST;

rather than

.	typedef struct _OVERSEE_TEST OVERSEE_TEST;

When defining fields or variable names, we use a loose form of 
Hungarian notation. Names beginning with "p" are pointers. Names beginning
with "pv" are pointers to vectors. Names beginning with "u" are some kind
of unsigned type; names beginning with "i" are some kind of signed integral
type. Names beginning with "size" denote an unsigned size in bytes; names 
beginning with "length" or "n" denote an unsigned count of units.  Names
beginning with "f" are logically boolean flags.

Hungarian notation has been criticised on the basis that the type of the
variable should be declared and not repeated. This is true to an extent;
however, C is not really type agnostic. It's important to know whether a
variable is signed or unsigned when looking at code, and making the eye
wander to a declaration, especially of a structure in another file, is
both hard on the reader and distracting for purposes of analysis. We find
that readable software, like natural language, necessarily has a certain
amount of redundant information. Elegant writing uses this redundancy
consciously, for rhetorical effect. Coding style should manage redundancy
to guide the writer, the maintaininer, and the auditor.

*/



/****************************************************************************\
|
|	The various structures
|
\****************************************************************************/

struct OVESEE_TEST_s
	{
	OVERSEE_CONTEXT			*pContext;
	OVERSEE_FIXTURE			*pParentFixture;

	/*
	|| pTestId points to the name of the test. Normally this is taken
	|| from the test function name.
	*/
	const char			*pTestId;
	};

/*
|| A fixture represents the test fixture. In theory, there is one of these for
|| each actual fixture, but in fact these are all "virtual", and are only
|| intantiated for the execution life of the fixture.
*/
struct OVERSEE_FIXTURE_s
	{
	OVERSEE_CONTEXT			*pContext;
	OVERSEE_SUITE			*pParentSuite;
	OVERSEE_FIXTURE_SETUP_FN	*pSetupFn;
	void				*pSetupContext;
	OVERSEE_FIXTURE_TEARDOWN_FN	*pTeardownFn;
	void				*pTeardownContext;

	/*
	|| pFixtureId points to the name of the test fixture. Normally
	|| this is taken from the source file name.
	*/
	const char			*pFixtureId;
	};

struct OVERSEE_SUITE_s
	{
	OVERSEE_CONTEXT			*pContext;
	OVERSEE_FIXTURE			*pCurrentFixture;

	OVERSEE_SUITE_SETUP_FN		*pSetupFn;
	void				*pSetupContext;
	OVERSEE_SUITE_TEARDOWN_FN	*pTeardownFn;
	void				*pTeardownContext;	
	};

/****************************************************************************\
|
|	The API functions
|
\****************************************************************************/

OVERSEE_BEGIN_DECLS

OVERSEE_SAL_Ret_notnull
OVERSEE_SUITE *
Oversee_StaticInit(
	void
	);

OVERSEE_SAL_Success(return != 0)
OVERSEE_BOOL
OverseeSuite_RunTests(
	OVERSEE_SAL_In
		OVERSEE_SUITE *			/* pSuite */,
	OVERSEE_SAL_In
		OVERSEE_SUITE_DRIVER_FN *	/* pSuiteDriver */,
	OVERSEE_SAL_In_opt
		void *				/* pSuiteDriverCtx */
	);

OVERSEE_END_DECLS

/**** end of oversee.h ****/
#endif /* OVERSEE_H__ */
