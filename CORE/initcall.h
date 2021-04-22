#ifndef __INIT_CALL_H__
#define __INIT_CALL_H__


typedef int (*initcall_t)(void);
#define INIT_EXPORT(fn, level) \
	static initcall_t __initcall_##fn __attribute__((used)) \
	__attribute__((__section__(".initcall."level))) = fn
	

#define INIT_BOARD_EXPORT(fn)			INIT_EXPORT(fn, "1")
#define INIT_DEVICE_EXPORT(fn)			INIT_EXPORT(fn, "2")
#define INIT_COMPONENT_EXPORT(fn)		INIT_EXPORT(fn, "3")
#define INIT_APP_EXPORT(fn) 			INIT_EXPORT(fn, "4")

#endif