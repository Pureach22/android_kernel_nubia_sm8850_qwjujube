__int64 __fastcall wma_sta_kickout_event(int a1, char a2, const void *a3)
{
  __int64 result; // x0
  __int64 v7; // [xsp+8h] [xbp-18h] BYREF
  int v8; // [xsp+10h] [xbp-10h]
  __int64 v9; // [xsp+18h] [xbp-8h]

  v9 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = 0;
  v7 = 0;
  qdf_mem_set(&v7, 0xCu, 0);
  LODWORD(v7) = a1;
  BYTE2(v8) = a2;
  if ( a3 )
    qdf_mem_copy((char *)&v7 + 4, a3, 6u);
  result = host_diag_event_report_payload(2873, 12, &v7);
  _ReadStatusReg(SP_EL0);
  return result;
}
