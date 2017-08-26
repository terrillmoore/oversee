/* oversee_result_stream_api.h	Fri Mar  1 2013 11:29:10 tmm */

/*

Module:  oversee_result_stream_api.h

Function:
	The result-stream API

Version:
	V0.91a	Fri Mar  1 2013 11:29:10 tmm	Edit level 1

Copyright notice:
	This file copyright (C) 2013 by

		Terrill Moore
		3170 Krums Corners Road
		Trumansburg, NY  14886

	An unpublished work.  All rights reserved.
	
	This file is proprietary information, and may not be disclosed or
	copied without the prior permission of Terrill Moore.
 
Author:
	Terry Moore	March 2013

Revision history:
   0.91a  Fri Mar  1 2013 11:29:10  tmm
	Module created.

*/

#ifndef OVERSEE_RESULT_STREAM_API_H__		/* prevent multiple includes */
#define OVERSEE_RESULT_STREAM_API_H__

#ifndef OVERSEE_RESULT_STREAM_TYPES_H__
# include "oversee_result_stream_types.h"
#endif

/*

Type:	OVERSEE_RESULT_STREAM_API

Index:	Type:	OVERSEE_HSTREAM

Function:
	Provides the bindings for the result-stream API for the OVERSEE
	test fixture.

Description:
	This structure is obtained by calling
	OVERSEE_PLATFORM::pOpenResultStream(). It provides a family of
	services which are used by the Oversee framework for producing test
	reports. It is not intended for direct use by test fixture code.

Contents:
	size_t sizeApi;
		This gives the size of the overall interface structure.

	OVERSEE_HSTREAM hResultStream;
		An opaque handle to be used when calling the APIs provided by
		this function.

	OVERSEE_RESULT_STREAM_REFERENCE_FN pReference;
		

Notes:
	xxx

See Also:
	xxx

*/

struct OVERSEE_RESULT_STREAM_API_s
	{
	size_t						sizeApi;
	OVERSEE_HSTREAM					hResultStream;
	OVERSEE_RESULT_STREAM_REFERENCE_FN		*pReference;
	OVERSEE_RESULT_STREAM_DEREFERENCE_FN		*pDereference;
	OVERSEE_RESULT_STREAM_WRITE_TEST_COMMENT_FN	*pWriteComment;
	OVERSEE_RESULT_STREAM_WRITE_TEST_RESULT_FN	*pWriteResult;
	OVERSEE_RESULT_STREAM_WRITE_TEST_SUMMARY_FN	*pWriteSummary;
	};


/**** end of oversee_result_stream_api.h ****/
#endif /* OVERSEE_RESULT_STREAM_API_H__ */
