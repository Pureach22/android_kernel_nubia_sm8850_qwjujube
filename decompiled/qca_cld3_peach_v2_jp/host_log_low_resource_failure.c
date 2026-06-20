__int64 __fastcall host_log_low_resource_failure(
        char a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 result; // x0
  _BYTE v10[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v11; // [xsp+8h] [xbp-8h]

  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10[0] = a1;
  result = host_diag_event_report_payload(2747, 1, v10, a2, a3, a4, a5, a6, a7, a8, a9);
  _ReadStatusReg(SP_EL0);
  return result;
}
