__int64 __fastcall hdd_wlan_suspend_resume_event(char a1)
{
  __int64 result; // x0
  _BYTE v3[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v4; // [xsp+8h] [xbp-8h]

  v4 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3[0] = 0;
  qdf_mem_set(v3, 1u, 0);
  v3[0] = a1;
  result = host_diag_event_report_payload(2743, 1, v3);
  _ReadStatusReg(SP_EL0);
  return result;
}
