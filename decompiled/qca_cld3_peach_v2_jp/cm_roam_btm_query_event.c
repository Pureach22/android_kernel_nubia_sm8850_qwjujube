__int64 __fastcall cm_roam_btm_query_event(__int64 a1, unsigned __int8 a2)
{
  unsigned int v4; // w21
  __int64 v5; // x1
  __int64 v6; // x2
  __int64 v7; // x3
  __int64 v8; // x4
  __int64 v9; // x0
  char v10; // w11
  char v11; // w12
  __int64 v13; // [xsp+0h] [xbp-40h] BYREF
  unsigned __int64 time_of_the_day_us; // [xsp+8h] [xbp-38h]
  __int64 v15; // [xsp+10h] [xbp-30h]
  __int64 v16; // [xsp+18h] [xbp-28h]
  __int64 v17; // [xsp+20h] [xbp-20h]
  __int64 v18; // [xsp+28h] [xbp-18h]
  int v19; // [xsp+30h] [xbp-10h]
  __int64 v20; // [xsp+38h] [xbp-8h]

  v20 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v19 = 0;
  v17 = 0;
  v18 = 0;
  v15 = 0;
  v16 = 0;
  v13 = 0;
  time_of_the_day_us = 0;
  qdf_mem_set(&v13, 0x34u, 0);
  v4 = *(_DWORD *)(a1 + 12);
  HIWORD(v13) = a2;
  time_of_the_day_us = qdf_get_time_of_the_day_us();
  v9 = ktime_get(time_of_the_day_us, v5, v6, v7, v8);
  LOBYTE(v17) = 2;
  v10 = *(_BYTE *)(a1 + 176);
  BYTE1(v18) = 20;
  v11 = *(_BYTE *)(a1 + 183);
  LOBYTE(v18) = v10;
  BYTE1(v17) = *(_BYTE *)(a1 + 178);
  v15 = 1000LL * v4;
  v16 = v9 / 1000;
  HIBYTE(v17) = HIBYTE(v17) & 1 | (2 * v11);
  host_diag_event_report_payload(3361, 52, &v13);
  _ReadStatusReg(SP_EL0);
  return 0;
}
