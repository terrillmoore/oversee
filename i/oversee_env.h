/* oversee_env.h	Sun Mar  3 2013 18:35:40 tmm */

/*

Module:  oversee_env.h

Function:
	Compiler and environment adaptation for the oversee unit-test package.

Version:
	V0.91a	Sun Mar  3 2013 18:35:40 tmm	Edit level 2

Copyright notice:
	This file copyright (C) 2013 by

		Terrill Moore
		3170 Perry City Road
		Trumansburg, NY 14886

	An unpublished work.  All rights reserved.
	
	This file is proprietary information, and may not be disclosed or
	copied without the prior permission of Terrill Moore
 
Author:
	Terry Moore	February 2013

Revision history:
   0.91a  Sat Feb 16 2013 05:54:15  tmm
	Module created.

*/

#ifndef OVERSEE_ENV_H__		/* prevent multiple includes */
#define OVERSEE_ENV_H__

/****************************************************************************\
|
|	Compiler and environment adaptation
|
| Header file dependencies: <stddef.h>, ISO C99 compliant.  This means we're
| allowed to use size_t, ptrdiff_t, wchar_t, NULL and offsetof().
|
| Oversee uses the term "ABI keyword" to denote the special syntax used
| by many C compilers to tag functions and function prototypes as using
| a particular machine-language calling sequence.  (ABI stands for
| "application binary interface".)  One of the purposes of this module is
| to define appropriate OVERSEE_... symbols that expand to the appropriate
| compiler-specific tag for functions of given types.
|
| Compile-time parameters:
|
|	_MSC_VER		if defined, triggers MSFT C awareness
|
|	OVERSEE_ABI_STD		if defined, is the ABI keyword for
|				decorating the fixed-signature ABIs.
|
|	OVERSEE_ABI_VARARGS	if defined, is the ABI keyword for
|				decorating the variadic ABIs.
|
|	OVERSEE_RESTRICT	if defined, is the ABI keyword that
|				provides the C99 "restrict" keyword
|				functionality.
|
|	OVERSEE_STDDEF_H	if defined, this is the name of
|				a header file to use instead of
|				<stddef.h>.  It is normally defined
|				to the compiler using
|				-D OVERSEE_STDDEF_H=local_stddef.h --
|				without quotes.  This syntax is
|				easiest to use, but doesn't allow
|				for angle-brackets. It will be
|				#included using "name" notation.
|
|	OVERSEE_STDDEF_H_META	if defined, this is the name of
|				a header file to use instead of <stddef.h>
|				It will be #included using <metabracket>
|				notation.
|
| Post conditions of this module:
|	<stddef.h> has been included.
|
|	OVERSEE_ABI_STD is always defined, and should be used when declaring
|	function types for functions that take a fixed number of parameters.
|	It should be used as follows:
|
|	typedef {type} OVERSEE_ABI_STD {FNTYPENAME}( {params} );
|
|	OVERSEE_ABI_VARARGS is always defined, and should be used when
|	declaring function types for functions that take a variable number of
|	parameters.  It should be used as follows:
|
|	typedef {type} OVERSEE_ABI_VARARGS {FNTYPENAME} ( {params}, ... );
|
|	This syntax is annoying, but is required in order to allow oversee
|	code to be safely embedded in the widest variety of environments.
|
|	OVERSEE_STRING() is always defined as a macro that returns the
|	stringification of its argument, without macro expansion.
|
|	OVERSEE_STRINGVAL() is always defined as a macro that returns the
|	stringification of its argument, after macro expansion.
|
|	OVERSEE_CONCAT3(x,y,z) is defined as a macro that returns the
|	paste of its arguments, without macro exapansion.
|
|	OVERSEE_CONCATVAL3(x,y,z) is defined as a macro that returns the
|	paste of its arguments, after macro expansion.
|
\****************************************************************************/

/****************************************************************************\
|
|	Define the ABI symbols
|
\****************************************************************************/

#ifndef OVERSEE_ABI_STD
# ifdef _MSC_VER
#  define OVERSEE_ABI_STD	__stdcall
# else
#  define OVERSEE_ABI_STD	/* nothing */
# endif
#endif

#ifndef OVERSEE_ABI_VARARGS
# ifdef _MSC_VER
#  define OVERSEE_ABI_VARARGS	__cdecl
# else
#  define OVERSEE_ABI_VARARGS	/* nothing */
# endif
#endif

/****************************************************************************\
|
|	Define the "restrict" keyword
|
\****************************************************************************/

/*
|| Many C compilers implement the restrict keyword, but not all. Rather
|| than using "restrict" and hoping for the best, we simply define an
|| oversee variant that can be overridden if needed.
*/
#ifndef OVERSEE_RESTRICT
# if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L
#   define OVERSEE_RESTRICT	restrict
# elif defined __GNUC__
#   define OVERSEE_RESTRICT	__restrict__
# else
#   define OVERSEE_RESTRICT	/* nothing */
# endif
#endif

/****************************************************************************\
|
|	Define the string-manipulation macros
|
\****************************************************************************/

#define	OVERSEE_STRING(x)	#x
#define	OVERSEE_STRINGVAL(x)	OVERSEE_STRING(x)
#define	OVERSEE_CONCAT3(x,y,z)	x##y##z
#define	OVERSEE_CONCATVAL3(x,y,z) OVERSEE_CONCAT3(x,y,z)

/****************************************************************************\
|
|	Include <stddef.h> or equivalent.
|
| Post-condition: types ptrdiff_t, size_t, wchar_t are defined
|		  macros NULL, offsetof(t, member) are defined
|
\****************************************************************************/

#if defined(OVERSEE_STDDEF_H_META)
# if defined(OVERSEE_STDDEF_H)
#  error "Do not define both OVERSEE_STDDEF_H and OVERSEE_STDDEF_H_META"
# endif
# include OVERSEE_CONCATVAL3(<,OVERSEE_STDDEF_H_META,>)
#elif defined(OVERSEE_STDDEF_H)
# include OVERSEE_STRINGVAL(OVERSEE_STDDEF_H)
#else
# include <stddef.h>
#endif

/****************************************************************************\
|
|	Define the begin/end declaration tags for C++ co-existance
|
\****************************************************************************/

#ifdef __cplusplus
# define OVERSEE_BEGIN_DECLS	extern "C" {
# define OVERSEE_END_DECLS	}
#else
# define OVERSEE_BEGIN_DECLS	/* nothing */
# define OVERSEE_END_DECLS	/* nothing */
#endif

/****************************************************************************\
|
|	Get set up for SAL-style annotations
|
| Postcondition:
|	OVERSEE_PARAM_USE_SAL is defined and numeric
|
|	OVERSEE_SAL_Function_class(n) is defined and like _Function_class_(n)
|	OVERSEE_SAL_In, OVERSEE_SAL_Out, OVERSEE_SAL_In_z,
	OVERSEE_SAL_Out_opt, OVERSEE_SAL_Out_writes_z(nChar)
|
\****************************************************************************/

#ifndef OVERSEE_PARAM_USE_SAL
# if defined(_MSCVER)
#  define OVERSEE_PARAM_USE_SAL 1
# else
#  define OVERSEE_PARAM_USE_SAL 0
# endif
#endif

#if OVERSEE_PARAM_USE_SAL
# include <sal.h>

/* annotation defining a function class for role-checking */
# define OVERSEE_SAL_Function_class(n)	_Function_class_(n)
# define OVERSEE_SAL_In			_In_
# define OVERSEE_SAL_In_opt		_In_opt_
# define OVERSEE_SAL_In_opt_z		_In_opt_z_
# define OVERSEE_SAL_In_reads_or_z(c)	_In_reads_or_z_(c)
# define OVERSEE_SAL_In_z		_In_z_
# define OVERSEE_SAL_Out		_Out_
# define OVERSEE_SAL_Out_opt		_Out_opt_
# define OVERSEE_SAL_Out_writes_bytes(n) _Out_writes_bytes_(n)
# define OVERSEE_SAL_Out_writes_z(nc)	_Out_writes_z_(nc)
# define OVERSEE_SAL_Param(i)		_Param_(i)
# define OVERSEE_SAL_Post_invalid	_Post_invalid_
# define OVERSEE_SAL_Pre_defensive	_Pre_defensive_
# define OVERSEE_SAL_Printf_format_string _Printf_format_string_
# define OVERSEE_SAL_Ret_notnull	_Ret_notnull_
# define OVERSEE_SAL_Success(e)		_Success_(e)
#else /* !OVERSEE_PARAM_USE_SAL */

# define OVERSEE_SAL_Function_class(n)	/* nothing */
# define OVERSEE_SAL_In			/* nothing */
# define OVERSEE_SAL_In_opt		/* nothing */
# define OVERSEE_SAL_In_opt_z		/* nothing */
# define OVERSEE_SAL_In_reads_or_z(c)	/* nothing */
# define OVERSEE_SAL_In_z		/* nothing */
# define OVERSEE_SAL_Out		/* nothing */
# define OVERSEE_SAL_Out_opt		/* nothing */
# define OVERSEE_SAL_Out_writes_bytes(n) /* nothing */
# define OVERSEE_SAL_Out_writes_z(nc)	/* nothing */
# define OVERSEE_SAL_Post_invalid	/* nothing */
# define OVERSEE_SAL_Pre_defensive	/* nothing */
# define OVERSEE_SAL_Printf_format_string /* nothing */
# define OVERSEE_SAL_Ret_notnull	/* nothing */
# define OVERSEE_SAL_Success(e)		/* nothing */

#endif /* !OVERSEE_PARAM_USE_SAL */

/**** end of oversee_env.h ****/
#endif /* OVERSEE_ENV_H__ */
