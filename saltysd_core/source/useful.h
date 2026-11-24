#ifndef USEFUL_H
#define USEFUL_H

#if defined(SWITCH32)
#include <switch_min.h>
#elif defined(SWITCH)
#include <switch.h>
#else
#error "Unsupported base architecture!"
#endif
#include <string.h>
#include <stdio.h>
#include <stdarg.h>

#define LINKABLE __attribute__ ((weak))

<<<<<<< HEAD
extern void SaltySDCore_printf(const char* format, ...) LINKABLE;
	
void SaltySDCore_printf(const char* format, ...)
{
	FILE* logflag = fopen("sdmc:/switch/SaltySD/flags/log.flag", "r");
	if (logflag == NULL) return;
	fclose(logflag);
	
	char buffer[256];

	va_list args;
	va_start(args, format);
	vsnprintf(buffer, 256, format, args);
	va_end(args);
	
	svcOutputDebugString(buffer, strlen(buffer));
	
	FILE* f = fopen("sdmc:/switch/SaltySD/saltysd_core.log", "ab");
	if (f)
	{
		fwrite(buffer, strlen(buffer), 1, f);
		fclose(f);
	}
=======
#ifdef __cplusplus
extern "C" {
#endif

extern void SaltySDCore_printf(const char* format, ...) LINKABLE;

#ifdef __cplusplus
>>>>>>> 6d4b27255fe350fd349483430d42da770ea3d982
}
#endif

#define debug_log(...) \
	{char log_buf[0x200]; npf_snprintf(log_buf, 0x200, __VA_ARGS__); \
	svcOutputDebugString(log_buf, strlen(log_buf));}
	
#endif // USEFUL_H