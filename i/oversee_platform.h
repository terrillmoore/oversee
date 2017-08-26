/* oversee_platform.h	Thu Feb 28 2013 16:26:34 tmm */

/*

Module:  oversee_platform.h

Function:
	The interface to the OVERSEE platform

Version:
	V0.91a	Thu Feb 28 2013 16:26:34 tmm	Edit level 1

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
   0.91a  Thu Feb 28 2013 16:26:34  tmm
	Module created.

*/

#ifndef OVERSEE_PLATFORM_H__		/* prevent multiple includes */
#define OVERSEE_PLATFORM_H__

#ifndef OVERSEE_PLATFORM_TYPES_H__
# include "oversee_platform_types.h"
#endif


struct OVERSEE_PLATFORM_API_s
	{
	size_t					sizeApis;
	OVERSEE_HPLATFORM			hPlatform;
	OVERSEE_PLATFORM_REFERENCE_FN		*pReference;
	OVERSEE_PLATFORM_DEREFERENCE_FN		*pDereference;
	OVERSEE_PLATFORM_SNPRINTF_FN		*pSnprintf;
	OVERSEE_PLATFORM_STRCMP_FN		*pStrcmp;
	OVERSEE_PLATFORM_STRLEN_FN		*pStrlen;
	OVERSEE_PLATFORM_STRNCMP_FN		*pStrncmp;
	OVERSEE_PLATFORM_STRSTR_FN		*pStrstr;
	OVERSEE_PLATFORM_PROTECTED_CALL_FN	*pProtectedCall;
	OVERSEE_PLATFORM_OPEN_RESULT_STREAM_FN	*pOpenResultStream;
	};


/**** end of oversee_platform.h ****/
#endif /* _OVERSEE_PLATFORM_H__ */
