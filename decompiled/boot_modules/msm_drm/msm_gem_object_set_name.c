__int64 msm_gem_object_set_name(
        __int64 result,
        char *format,
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
  gcc_va_list arg; // [xsp+38h] [xbp-48h] BYREF
  gcc_va_list va1; // [xsp+58h] [xbp-28h] BYREF
  __int64 v12; // [xsp+78h] [xbp-8h]

  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( format )
  {
    va_start(va1, a10);
    va_start(arg, a10);
    result = vsnprintf((char *)(result + 617), 0x20u, format, arg);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
