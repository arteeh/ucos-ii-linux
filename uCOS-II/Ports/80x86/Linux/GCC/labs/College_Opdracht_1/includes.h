// conio.h alternative. requires libncurses-dev
#include <curses.h>

// http://man7.org/linux/man-pages/man2/syscall.2.html
// Segmentation fault if not commented out?
//#include <unistd.h>
//#include <sys/syscall.h>

#include "../../src/os_cpu.h"
#include "../../src/pc.h"
#include "os_cfg.h"
#include "../../../../../../Source/ucos_ii.h"
