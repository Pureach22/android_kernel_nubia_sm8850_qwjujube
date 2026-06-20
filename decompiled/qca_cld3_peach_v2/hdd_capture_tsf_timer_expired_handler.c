__int64 __fastcall hdd_capture_tsf_timer_expired_handler(
        __int64 result,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  int v9; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v10; // [xsp+8h] [xbp-8h]

  v10 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( result )
    result = hdd_capture_tsf_internal(result, &v9, 1, a2, a3, a4, a5, a6, a7, a8, a9);
  _ReadStatusReg(SP_EL0);
  return result;
}
