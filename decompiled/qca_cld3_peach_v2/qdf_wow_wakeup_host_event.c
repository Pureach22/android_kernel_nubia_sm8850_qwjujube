__int64 __fastcall qdf_wow_wakeup_host_event(char a1)
{
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
  __int64 result; // x0
  _QWORD v11[3]; // [xsp+8h] [xbp-18h] BYREF

  v11[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v11, 0, 11);
  qdf_mem_set(v11, 0xBu, 0);
  LOBYTE(v11[0]) = 3;
  BYTE1(v11[1]) = a1;
  result = host_diag_event_report_payload(1666, 11, v11, v2, v3, v4, v5, v6, v7, v8, v9);
  _ReadStatusReg(SP_EL0);
  return result;
}
