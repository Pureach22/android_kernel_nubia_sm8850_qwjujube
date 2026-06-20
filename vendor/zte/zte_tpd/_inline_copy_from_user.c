#include "defs.h"
#include <linux/uaccess.h>

size_t __fastcall inline_copy_from_user(__int64 a1, unsigned __int64 a2, size_t n)
{
    return copy_from_user((void *)a1, (const void __user *)a2, n);
}
