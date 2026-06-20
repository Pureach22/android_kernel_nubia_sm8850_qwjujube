__int64 __fastcall hdd_cstats_log_ndi_create_req_evt(__int64 a1, __int16 a2)
{
  int v3; // w9
  char v4; // w8
  __int64 result; // x0
  int v6; // [xsp+0h] [xbp-20h] BYREF
  char v7; // [xsp+4h] [xbp-1Ch]
  char v8; // [xsp+5h] [xbp-1Bh]
  unsigned __int64 time_of_the_day_us; // [xsp+6h] [xbp-1Ah]
  unsigned __int64 StatusReg; // [xsp+Eh] [xbp-12h]
  __int16 v11; // [xsp+16h] [xbp-Ah]
  __int64 v12; // [xsp+18h] [xbp-8h]

  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_DWORD *)(a1 + 16);
  v6 = 1310753;
  v4 = *(_BYTE *)(a1 + 168);
  v7 = v3;
  v8 = v4;
  time_of_the_day_us = qdf_get_time_of_the_day_us();
  __isb(0xFu);
  StatusReg = _ReadStatusReg(CNTVCT_EL0);
  v11 = a2;
  result = wlan_cp_stats_cstats_write_to_buff(0, &v6, 24);
  _ReadStatusReg(SP_EL0);
  return result;
}
