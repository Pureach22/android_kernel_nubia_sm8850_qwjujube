__int64 QDF_PRINT_INFO(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        ...)
{
  __int64 result; // x0
  gcc_va_list va; // [xsp+28h] [xbp-48h] BYREF
  gcc_va_list va1; // [xsp+48h] [xbp-28h] BYREF
  __int64 v15; // [xsp+68h] [xbp-8h]

  va_start(va1, a12);
  va_start(va, a12);
  v15 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  result = ((__int64 (__fastcall *)(_QWORD, __int64, __int64, __int64, __va_list_tag *))qdf_trace_msg_cmn)(
             (unsigned int)qdf_pidx,
             56,
             2,
             a4,
             va1);
  _ReadStatusReg(SP_EL0);
  return result;
}
