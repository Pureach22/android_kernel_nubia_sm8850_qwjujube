__int64 __fastcall host_log_acs_scan_start(
        int a1,
        unsigned __int8 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 result; // x0
  _DWORD v11[2]; // [xsp+0h] [xbp-10h] BYREF
  __int64 v12; // [xsp+8h] [xbp-8h]

  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11[0] = a1;
  v11[1] = a2;
  result = host_diag_event_report_payload(3147, 8, v11, a3, a4, a5, a6, a7, a8, a9, a10);
  _ReadStatusReg(SP_EL0);
  return result;
}
