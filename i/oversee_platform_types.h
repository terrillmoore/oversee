/* oversee_platform_types.h	Thu Feb 28 2013 16:27:21 tmm */

/*

Module:  oversee_platform_types.h

Function:
	The "scalar types" for the oversee platform.

Version:
	V0.91a	Thu Feb 28 2013 16:27:21 tmm	Edit level 1

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
   0.91a  Thu Feb 28 2013 16:27:21  tmm
	Module created.

*/

#ifndef OVERSEE_PLATFORM_TYPES_H__		/* prevent multiple includes */
#define OVERSEE_PLATFORM_TYPES_H__

#ifndef OVERSEE_TYPES_H__
# include "oversee_types.h"
#endif

/****************************************************************************\
|
|	Platform API functions
|
| Platform APIs are used by OVERSEE to do its work.  
|
\****************************************************************************/

typedef struct OVERSEE_HPLATFORM_s *OVERSEE_HPLATFORM;

typedef	
OVERSEE_SAL_Function_class(OVERSEE_PLATFORM_REFERENCE_FN)
void OVERSEE_ABI_STD
OVERSEE_PLATFORM_REFERENCE_FN(
	OVERSEE_SAL_In
		OVERSEE_HPLATFORM	/* hPlatform */
	);

typedef 
OVERSEE_SAL_Function_class(OVERSEE_PLATFORM_DEREFERENCE_FN)
void OVERSEE_ABI_STD
OVERSEE_PLATFORM_DEREFERENCE_FN(
	OVERSEE_SAL_In
		OVERSEE_HPLATFORM	/* hPlatform */
	);

typedef 
OVERSEE_SAL_Function_class(OVERSEE_PLATFORM_STRLEN_FN)
size_t OVERSEE_ABI_STD
OVERSEE_PLATFORM_STRLEN_FN(
	OVERSEE_SAL_In
		OVERSEE_HPLATFORM	/* hPlatform */,
	OVERSEE_SAL_In_opt_z 
		const char *
	);

typedef	
OVERSEE_SAL_Function_class(OVERSEE_PLATFORM_SNPRINTF_FN)
int OVERSEE_ABI_VARARGS
OVERSEE_PLATFORM_SNPRINTF_FN(
	OVERSEE_SAL_In
		OVERSEE_HPLATFORM		/* hPlatform */,
	OVERSEE_SAL_Out_writes_z(OVERSEE_SAL_Param(3))
	OVERSEE_SAL_Pre_defensive
		char * OVERSEE_RESTRICT		/* pBuffer */,
	OVERSEE_SAL_In
		size_t				/* nBuffer */,
	OVERSEE_SAL_In_z
	OVERSEE_SAL_Printf_format_string
	OVERSEE_SAL_Pre_defensive
		const char * OVERSEE_RESTRICT	/* pFormat */,
		...
	);

typedef 
OVERSEE_SAL_Function_class(OVERSEE_PLATFORM_STRCMP_FN)
int OVERSEE_ABI_STD
OVERSEE_PLATFORM_STRCMP_FN(
	OVERSEE_SAL_In
		OVERSEE_HPLATFORM		/* hPlatform */,
	OVERSEE_SAL_In_z
	OVERSEE_SAL_Pre_defensive
		const char *			/* pS1 */,
	OVERSEE_SAL_In_z
	OVERSEE_SAL_Pre_defensive
		const char *			/* pS2 */
	);

typedef 
OVERSEE_SAL_Function_class(OVERSEE_PLATFORM_STRSTR_FN)
int OVERSEE_ABI_STD
OVERSEE_PLATFORM_STRSTR_FN(
	OVERSEE_SAL_In
		OVERSEE_HPLATFORM		/* hPlatform */,
	OVERSEE_SAL_In_z
	OVERSEE_SAL_Pre_defensive
		const char *			/* pLookInThisString */,
	OVERSEE_SAL_In_z
	OVERSEE_SAL_Pre_defensive
		const char *			/* pStringToLookFor */
	);

typedef 
OVERSEE_SAL_Function_class(OVERSEE_PLATFORM_STRNCMP_FN)
int OVERSEE_ABI_STD
OVERSEE_PLATFORM_STRNCMP_FN(
	OVERSEE_SAL_In
		OVERSEE_HPLATFORM		/* hPlatform */,
	OVERSEE_SAL_In_reads_or_z(OVERSEE_SAL_Param(4))
	OVERSEE_SAL_Pre_defensive
		const char *			/* pS1 */,
	OVERSEE_SAL_In_reads_or_z(OVERSEE_SAL_Param(4))
	OVERSEE_SAL_Pre_defensive
		const char *			/* pS2 */,
	OVERSEE_SAL_In
		size_t				/* n */
	);

typedef 
OVERSEE_SAL_Function_class(OVERSEE_PLATFORM_OPEN_RESULT_STREAM_FN)
void OVERSEE_ABI_STD
OVERSEE_PLATFORM_OPEN_RESULT_STREAM_FN(
	OVERSEE_SAL_In
		OVERSEE_HPLATFORM		/* hPlatform  */,
	OVERSEE_SAL_Out_writes_bytes(OVERSEE_SAL_Param(3))
	OVERSEE_SAL_Pre_defensive
		OVERSEE_RESULT_STREAM_API *	/* pStreamAPIs */,
	OVERSEE_SAL_In
		size_t				/* sizeStreamAPIs */
	);

/* the function type for the parameter for protected call */
typedef 
OVERSEE_SAL_Function_class(OVERSEE_PLATFORM_PROTECTED_CALL_CB_FN)
void OVERSEE_ABI_STD
OVERSEE_PLATFORM_PROTECTED_CALL_CB_FN(
	OVERSEE_SAL_In
		OVERSEE_HPLATFORM			/* hPlatform */,
	OVERSEE_SAL_In_opt
		void *					/* context */
	);

typedef 
OVERSEE_SAL_Function_class(OVERSEE_PLATFORM_PROTECTED_CALL_FN)
int OVERSEE_ABI_STD
OVERSEE_PLATFORM_PROTECTED_CALL_FN(
	OVERSEE_SAL_In
		OVERSEE_HPLATFORM			/* hPlatform */,
	OVERSEE_SAL_In OVERSEE_SAL_Pre_defensive
		OVERSEE_PLATFORM_PROTECTED_CALL_CB_FN *	/* pFN */,
	OVERSEE_SAL_In_opt
		void *					/* context */
	);

/**** end of oversee_platform_types.h ****/
#endif /* OVERSEE_PLATFORM_TYPES_H__ */
