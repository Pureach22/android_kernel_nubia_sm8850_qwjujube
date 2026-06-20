__int64 write_str(
        __int64 a1,
        __int64 a2,
        const char *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        ...)
{
  __int64 result; // x0
  gcc_va_list va; // [xsp+28h] [xbp-48h] BYREF
  gcc_va_list va1; // [xsp+48h] [xbp-28h] BYREF
  __int64 v14; // [xsp+68h] [xbp-8h]

  va_start(va, a11);
  va_start(va1, a11);
  v14 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  result = vscnprintf(a1, a2, a3, va);
  _ReadStatusReg(SP_EL0);
  return result;
}
