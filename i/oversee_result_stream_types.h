/* oversee_result_stream_types.h	Fri Mar  1 2013 11:15:29 tmm */

/*

Module:  oversee_result_stream_types.h

Function:
	Types for OVERSEE_RESULT_STREAM.

Version:
	V0.91a	Fri Mar  1 2013 11:15:29 tmm	Edit level 1

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
   0.91a  Fri Mar  1 2013 11:15:29  tmm
	Module created.

*/

#ifndef _OVERSEE_RESULT_STREAM_TYPES_H_		/* prevent multiple includes */
#define _OVERSEE_RESULT_STREAM_TYPES_H_

#ifndef OVERSEE_ENV_H__
# include "oversee_types.h"
#endif

/****************************************************************************\
|
|	The result-stream API is used by OVERSEE to output results
|
\****************************************************************************/

typedef struct OVERSEE_HSTREAM_s *OVERSEE_HSTREAM;
/* typedef struct OVERSEE_RESULT_STREAM_API_s OVERSEE_RESULT_STREAM_API; */

typedef 
OVERSEE_SAL_Function_class(OVERSEE_RESULT_STREAM_REFERENCE_FN)
void OVERSEE_ABI_STD
OVERSEE_RESULT_STREAM_REFERENCE_FN(
	OVERSEE_SAL_In
		OVERSEE_HSTREAM
	);

typedef 
OVERSEE_SAL_Function_class(OVERSEE_RESULT_STREAM_DEREFERENCE_FN)
void OVERSEE_ABI_STD
OVERSEE_RESULT_STREAM_DEREFERENCE_FN(
	OVERSEE_SAL_In 
	OVERSEE_SAL_Post_invalid
		OVERSEE_HSTREAM
	);

typedef	
OVERSEE_SAL_Function_class(OVERSEE_RESULT_STREAM_WRITE_TEST_COMMENT_FN)
void OVERSEE_ABI_STD
OVERSEE_RESULT_STREAM_WRITE_TEST_COMMENT_FN(
	OVERSEE_SAL_In 
		OVERSEE_HSTREAM			/* hResultStream */,
	OVERSEE_SAL_In 
		OVERSEE_BOOL			/* TRUE indicates that this 
						|| should count as a failure
						*/,
	OVERSEE_SAL_In_opt_z 
		const char *			/* message text */
	);

typedef 
OVERSEE_SAL_Function_class(OVERSEE_RESULT_STREAM_WRITE_TEST_RESULT_FN)
void OVERSEE_ABI_STD
OVERSEE_RESULT_STREAM_WRITE_TEST_RESULT_FN(
	OVERSEE_SAL_In 
		OVERSEE_HSTREAM 		/* hResultStream */,
	OVERSEE_SAL_In 
		OVERSEE_BOOL			/* failure if TRUE */,
	OVERSEE_SAL_In_opt_z 
		const char *			/* reason */,
	OVERSEE_SAL_In_opt_z 
		const char *			/* Suite ID */,
	OVERSEE_SAL_In_opt_z 
		const char *			/* Fixture ID */,
	OVERSEE_SAL_In_opt_z 
		const char *			/* Test ID */,
	OVERSEE_SAL_In 
		unsigned int			/* Line# */
	);

typedef 
OVERSEE_SAL_Function_class(OVERSEE_RESULT_STREAM_WRITE_TEST_SUMMARY_FN)
void OVERSEE_ABI_STD
OVERSEE_RESULT_STREAM_WRITE_TEST_SUMMARY_FN(
	OVERSEE_SAL_In 
		OVERSEE_HSTREAM 		/* hResultStream */,
	OVERSEE_SAL_In_z
		const char *			/* pVersion */,
	OVERSEE_SAL_In 
		unsigned			/* nTestsRun */,
	OVERSEE_SAL_In 
		unsigned			/* nTestsFailed */,
	OVERSEE_SAL_In 
		unsigned			/* nFrameworkFailures */,
	OVERSEE_SAL_In 
		OVERSEE_OPTIONAL_TEST_DURATION	/* delta-T (ms) -- or -1 if no time */
	);

/**** end of oversee_result_stream_types.h ****/
#endif /* _OVERSEE_RESULT_STREAM_TYPES_H_ */
