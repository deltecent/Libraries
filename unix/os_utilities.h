#pragma once
/*	Copyright  (c)	Günter Woigk 2001 - 2020
					mailto:kio@little-bat.de

	This file is free software.

	Permission to use, copy, modify, distribute, and sell this software
	and its documentation for any purpose is hereby granted without fee,
	provided that the above copyright notice appears in all copies and
	that both that copyright notice, this permission notice and the
	following disclaimer appear in supporting documentation.

	THIS SOFTWARE IS PROVIDED "AS IS", WITHOUT ANY WARRANTY, NOT EVEN THE
	IMPLIED WARRANTY OF MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE
	AND IN NO EVENT SHALL THE COPYRIGHT HOLDER BE LIABLE FOR ANY DAMAGES
	ARISING FROM THE USE OF THIS SOFTWARE,
	TO THE EXTENT PERMITTED BY APPLICABLE LAW.
*/

#include	"kio/kio.h"


/* ----	system info ----------------------
*/
extern	cstr	hostName		();
extern	uint	numCPUs			() noexcept;
extern	time_t	bootTime		();

extern	void	sysLoad			(double load[3]);			// ranges: 1, 5, and 15 minutes
extern	size_t 	memoryUsage		(bool resident = true);
extern	double	cpuLoad			();

extern	time_t	intCurrentTime	();
//extern double	now				();		// was: floatCurrentTime() .. now in kio.cpp
inline	time_t	upTime			()		{ return intCurrentTime()-bootTime(); }

#ifdef _UNIX
inline	uid_t	getUID			( )		{ return getuid(); }
inline	gid_t	getGID			( )		{ return getgid(); }
inline	uid_t	getEffUID		( )		{ return geteuid(); }
inline	gid_t	getEffGID		( )		{ return getegid(); }
#endif
extern	cstr	getUser			( );
extern	cstr	getEffUser		( );


extern	str		execCmd			( /* cmd = argv[0] */ str const argv[], str const envv[]=nullptr );
extern	str		execCmd			( cstr cmd, ... /* argv[1] ... NULL */ );










