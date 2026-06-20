__int64 __fastcall cm_roam_btm_block_event(unsigned __int8 a1, char a2, char a3)
{
  __int64 v6; // x1
  __int64 v7; // x2
  __int64 v8; // x3
  __int64 v9; // x4
  __int64 v10; // x0
  __int64 v12; // [xsp+0h] [xbp-40h] BYREF
  unsigned __int64 time_of_the_day_us; // [xsp+8h] [xbp-38h]
  __int64 v14; // [xsp+10h] [xbp-30h]
  __int64 v15; // [xsp+18h] [xbp-28h]
  __int64 v16; // [xsp+20h] [xbp-20h]
  __int64 v17; // [xsp+28h] [xbp-18h]
  int v18; // [xsp+30h] [xbp-10h]
  __int64 v19; // [xsp+38h] [xbp-8h]

  v19 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v18 = 0;
  v16 = 0;
  v17 = 0;
  v14 = 0;
  v15 = 0;
  v12 = 0;
  time_of_the_day_us = 0;
  qdf_mem_set(&v12, 0x34u, 0);
  HIWORD(v12) = a1;
  time_of_the_day_us = qdf_get_time_of_the_day_us();
  v10 = ktime_get(time_of_the_day_us, v6, v7, v8, v9);
  LOBYTE(v17) = a2;
  BYTE1(v17) = 47;
  LOBYTE(v16) = 2;
  BYTE3(v16) = a3;
  v14 = 0;
  v15 = v10 / 1000;
  host_diag_event_report_payload(3361, 52, &v12);
  _ReadStatusReg(SP_EL0);
  return 0;
}
