__int64 __fastcall wlan_report_log_completion(int a1, int a2, int a3, unsigned __int8 a4)
{
  __int64 result; // x0
  _DWORD v5[4]; // [xsp+8h] [xbp-18h] BYREF
  __int64 v6; // [xsp+18h] [xbp-8h]

  v6 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5[0] = a1;
  v5[1] = a2;
  v5[2] = a3;
  v5[3] = a4;
  result = host_diag_event_report_payload(2727, 16, v5);
  _ReadStatusReg(SP_EL0);
  return result;
}
