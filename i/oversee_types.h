/* oversee_types.h	Sat Feb 16 2013 05:47:30 tmm */

/*

Module:  oversee_types.h

Function:
	Forward types for OVERSEE.

Version:
	V0.91a	Sat Feb 16 2013 05:47:30 tmm	Edit level 1

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
   0.91a  Sat Feb 16 2013 05:47:30  tmm
	Module created.

*/

#ifndef OVERSEE_TYPES_H__		/* prevent multiple includes */
#define OVERSEE_TYPES_H__

#ifndef OVERSEE_ENV_H__
# include "oversee_env.h"
#endif

/****************************************************************************\
|
|	Forward types
|
| All tags end in {type}_s for struct, {type}_u for union, {type_e} for enum.
|
| We do not declare P{type} variants.
|
\****************************************************************************/

typedef	struct OVERSEE_CONTEXT_s	OVERSEE_CONTEXT;
typedef struct OVERSEE_SUITE_s		OVERSEE_SUITE;
typedef	struct OVERSEE_FIXTURE_s	OVERSEE_FIXTURE;
typedef	struct OVERSEE_TEST_s		OVERSEE_TEST;

typedef struct OVERSEE_PLATFORM_API_s	OVERSEE_PLATFORM_API;
typedef struct OVERSEE_RESULT_STREAM_API_s OVERSEE_RESULT_STREAM_API;

typedef	int OVERSEE_BOOL;

/*

Type:	OVERSEE_TEST_DURATION

Index:	Constant:	OVERSEE_TEST_DURATION_NIL
	String:		OVERSEE_TEST_DURATION_PRINT

Function:
	Represents a test duration, with designated "nil".

Description:
	OVERSEE_TEST_DURATION is a signed integer type that is used for
	representing a test duration.  Since we're designing for embedded
	systems, we don't actually specify how this maps to seconds or
	fractions thereof.  It's just got to be a signed integer value
	thats large enough to hold the measurements of interest.

	OVERSEE_TEST_DURATION_NIL is a distinguished value that can be
	used to indicate that a duration value is not specified.

	OVERSEE_TEST_DURATION_PRINT is a format specifier string (such as
	"ld") that will print a value other than NIL as a decimal number.

*/

#if defined(OVERSEE_TEST_DURATION_TYPE)
 typedef OVERSEE_TEST_DURATION_TYPE OVERSEE_OPTIONAL_TEST_DURATION;
# if ! (defined(OVERSEE_TEST_DURATION_NIL) && \
        defined(OVERSEE_TEST_DURATION_PRINT))
#   error "If you define OVERSEE_TEST_DURATION_TYPE, need _NIL and _PRINT too"
# endif
#else
  typedef long OVERSEE_OPTIONAL_TEST_DURATION;
# define OVERSEE_OPTIONAL_TEST_DURATION_NIL (-1l)
# define OVERSEE_OPTIONAL_TEST_DURATION_PRINT "ld"
#endif

/****************************************************************************\
|
|	The API function typedefs (used by clients).
|
| All function type names end with _FN. All callback function types end with
| _CB_FN. (Callback function types are functions that are passed as 
| parameters to APIs). 
|
| All API function type names are of the form OVERSEE_{object}_{method}_FN.
|
| The referenced object is the first parameter.
|
| All are conceptually designed as methods.
|
\****************************************************************************/

typedef 
OVERSEE_SAL_Function_class(OVERSEE_SUITE_SETUP_FN)
void OVERSEE_ABI_STD 
OVERSEE_SUITE_SETUP_FN(
	OVERSEE_SAL_In
		OVERSEE_SUITE *,
	OVERSEE_SAL_In_opt
		void *
	);

typedef	
OVERSEE_SAL_Function_class(OVERSEE_SUITE_TEARDOWN_FN)
void OVERSEE_ABI_STD 
OVERSEE_SUITE_TEARDOWN_FN(
	OVERSEE_SAL_In
		OVERSEE_SUITE *,
	OVERSEE_SAL_In_opt
		void *
	);

typedef 
OVERSEE_SAL_Function_class(OVERSEE_FIXTURE_SETUP_FN)
void OVERSEE_ABI_STD 
OVERSEE_FIXTURE_SETUP_FN(
	OVERSEE_SAL_In
		OVERSEE_FIXTURE *,
	OVERSEE_SAL_In_opt
		void *
	);

typedef	
OVERSEE_SAL_Function_class(OVERSEE_FIXTURE_TEARDOWN_FN)
void OVERSEE_ABI_STD 
OVERSEE_FIXTURE_TEARDOWN_FN(
	OVERSEE_SAL_In
		OVERSEE_FIXTURE *,
	OVERSEE_SAL_In_opt
		void *
	);

typedef
OVERSEE_SAL_Function_class(OVERSEE_SUITE_DRIVER_FN)
void OVERSEE_ABI_STD
OVERSEE_SUITE_DRIVER_FN(
	OVERSEE_SAL_In
		OVERSEE_SUITE *		/* pSuite */,
	OVERSEE_SAL_In_opt
		void *			/* pContext */
	);

/**** end of oversee_types.h ****/
#endif /* OVERSEE_TYPES_H__ */
