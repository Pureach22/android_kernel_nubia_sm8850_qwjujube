__int64 __fastcall nan_cstats_log_nan_disable_resp_evt(char a1, __int64 a2)
{
  double discovery_state; // d0
  char v4; // w0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 result; // x0
  int v13; // [xsp+0h] [xbp-20h] BYREF
  char v14; // [xsp+4h] [xbp-1Ch]
  char v15; // [xsp+5h] [xbp-1Bh]
  unsigned __int64 time_of_the_day_us; // [xsp+6h] [xbp-1Ah]
  unsigned __int64 StatusReg; // [xsp+Eh] [xbp-12h]
  char v18; // [xsp+16h] [xbp-Ah]
  __int64 v19; // [xsp+18h] [xbp-8h]

  v19 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v13 = 1245216;
  v14 = 16;
  v15 = a1;
  time_of_the_day_us = qdf_get_time_of_the_day_us();
  __isb(0xFu);
  StatusReg = _ReadStatusReg(CNTVCT_EL0);
  discovery_state = nan_get_discovery_state(a2);
  v18 = v4;
  result = wlan_cp_stats_cstats_write_to_buff(0, (__int64)&v13, 0x17u, discovery_state, v5, v6, v7, v8, v9, v10, v11);
  _ReadStatusReg(SP_EL0);
  return result;
}
