__int64 printk_adapter(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        ...)
{
  int v10; // w19
  __int64 v11; // x1
  __int64 v12; // x2
  __int64 v13; // x3
  int v14; // w0
  gcc_va_list va; // [xsp+38h] [xbp-48h] BYREF
  gcc_va_list va1; // [xsp+58h] [xbp-28h] BYREF
  __int64 v18; // [xsp+78h] [xbp-8h]

  va_start(va, a10);
  va_start(va1, a10);
  v18 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = vprintk(a2, va);
  v14 = printk("\n", v11, v12, v13);
  _ReadStatusReg(SP_EL0);
  return (unsigned int)(v14 + v10);
}
