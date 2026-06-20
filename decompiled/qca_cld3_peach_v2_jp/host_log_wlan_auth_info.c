__int64 __fastcall host_log_wlan_auth_info(
        __int16 a1,
        __int16 a2,
        __int16 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 result; // x0
  _WORD v12[4]; // [xsp+0h] [xbp-10h] BYREF
  __int64 v13; // [xsp+8h] [xbp-8h]

  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12[0] = a1;
  v12[1] = a2;
  v12[2] = a3;
  result = host_diag_event_report_payload(3218, 6, v12, a4, a5, a6, a7, a8, a9, a10, a11);
  _ReadStatusReg(SP_EL0);
  return result;
}
