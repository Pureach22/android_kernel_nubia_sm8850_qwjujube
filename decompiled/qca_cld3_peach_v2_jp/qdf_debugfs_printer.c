__int64 qdf_debugfs_printer(
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
  gcc_va_list va; // [xsp+38h] [xbp-48h] BYREF
  gcc_va_list va1; // [xsp+58h] [xbp-28h] BYREF
  __int64 v14; // [xsp+78h] [xbp-8h]

  va_start(va, a10);
  va_start(va1, a10);
  v14 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  seq_vprintf(a1, a2, va);
  seq_putc(a1, 10);
  _ReadStatusReg(SP_EL0);
  return 0;
}
