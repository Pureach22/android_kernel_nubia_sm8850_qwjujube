__int64 __fastcall cm_roam_btm_query_event(__int64 a1, unsigned __int8 a2)
{
  unsigned int v4; // w21
  __int64 v5; // x0
  char v6; // w11
  char v7; // w12
  __int64 v9; // [xsp+0h] [xbp-40h] BYREF
  unsigned __int64 time_of_the_day_us; // [xsp+8h] [xbp-38h]
  __int64 v11; // [xsp+10h] [xbp-30h]
  __int64 v12; // [xsp+18h] [xbp-28h]
  __int64 v13; // [xsp+20h] [xbp-20h]
  __int64 v14; // [xsp+28h] [xbp-18h]
  int v15; // [xsp+30h] [xbp-10h]
  __int64 v16; // [xsp+38h] [xbp-8h]

  v16 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v15 = 0;
  v13 = 0;
  v14 = 0;
  v11 = 0;
  v12 = 0;
  v9 = 0;
  time_of_the_day_us = 0;
  qdf_mem_set(&v9, 0x34u, 0);
  v4 = *(_DWORD *)(a1 + 12);
  HIWORD(v9) = a2;
  time_of_the_day_us = qdf_get_time_of_the_day_us();
  v5 = ktime_get();
  LOBYTE(v13) = 2;
  v6 = *(_BYTE *)(a1 + 176);
  BYTE1(v14) = 20;
  v7 = *(_BYTE *)(a1 + 183);
  LOBYTE(v14) = v6;
  BYTE1(v13) = *(_BYTE *)(a1 + 178);
  v11 = 1000LL * v4;
  v12 = v5 / 1000;
  HIBYTE(v13) = HIBYTE(v13) & 1 | (2 * v7);
  host_diag_event_report_payload(3361, 52, &v9);
  _ReadStatusReg(SP_EL0);
  return 0;
}
