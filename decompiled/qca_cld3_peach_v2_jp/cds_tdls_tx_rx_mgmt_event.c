__int64 __fastcall cds_tdls_tx_rx_mgmt_event(char a1, char a2, char a3, char a4, const void *a5)
{
  __int64 result; // x0
  _BYTE v6[4]; // [xsp+Ch] [xbp-14h] BYREF
  int v7; // [xsp+10h] [xbp-10h] BYREF
  __int16 v8; // [xsp+14h] [xbp-Ch]
  __int64 v9; // [xsp+18h] [xbp-8h]

  v9 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6[0] = a1;
  v6[1] = a2;
  v6[2] = a3;
  v8 = 0;
  v7 = 0;
  v6[3] = a4;
  qdf_mem_copy(&v7, a5, 6u);
  result = host_diag_event_report_payload(2746, 10, v6);
  _ReadStatusReg(SP_EL0);
  return result;
}
