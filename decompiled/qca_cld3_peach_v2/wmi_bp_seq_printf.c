__int64 wmi_bp_seq_printf(
        __int64 a1,
        const char *a2,
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
  __int64 result; // x0
  gcc_va_list va; // [xsp+38h] [xbp-48h] BYREF
  gcc_va_list va1; // [xsp+58h] [xbp-28h] BYREF
  __int64 v13; // [xsp+78h] [xbp-8h]

  va_start(va, a10);
  va_start(va1, a10);
  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  result = seq_vprintf(a1, a2, va);
  _ReadStatusReg(SP_EL0);
  return result;
}
