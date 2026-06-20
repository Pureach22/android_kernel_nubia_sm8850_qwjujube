__int64 __fastcall hdd_wlan_offload_event(char a1, char a2)
{
  __int64 result; // x0
  _WORD v5[2]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v6; // [xsp+8h] [xbp-8h]

  v6 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5[0] = 0;
  qdf_mem_set(v5, 2u, 0);
  LOBYTE(v5[0]) = a1;
  HIBYTE(v5[0]) = a2;
  result = host_diag_event_report_payload(2744, 2, v5);
  _ReadStatusReg(SP_EL0);
  return result;
}
