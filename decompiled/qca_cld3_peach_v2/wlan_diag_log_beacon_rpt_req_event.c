__int64 __fastcall wlan_diag_log_beacon_rpt_req_event(
        char a1,
        unsigned __int8 a2,
        char a3,
        char a4,
        char a5,
        __int16 a6,
        __int64 a7)
{
  __int64 v14; // x8
  __int64 v15; // x0
  __int64 result; // x0
  __int64 v17; // [xsp+0h] [xbp-40h] BYREF
  unsigned __int64 time_of_the_day_us; // [xsp+8h] [xbp-38h]
  __int64 v19; // [xsp+10h] [xbp-30h]
  __int64 v20; // [xsp+18h] [xbp-28h]
  __int64 v21; // [xsp+20h] [xbp-20h]
  __int64 v22; // [xsp+28h] [xbp-18h]
  int v23; // [xsp+30h] [xbp-10h]
  __int64 v24; // [xsp+38h] [xbp-8h]

  v24 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v23 = 0;
  v21 = 0;
  v22 = 0;
  v19 = 0;
  v20 = 0;
  v17 = 0;
  time_of_the_day_us = 0;
  qdf_mem_set(&v17, 0x34u, 0);
  HIWORD(v17) = *(unsigned __int8 *)(*(_QWORD *)(a7 + 16) + 168LL);
  time_of_the_day_us = qdf_get_time_of_the_day_us();
  v14 = (unsigned __int128)(ktime_get(time_of_the_day_us) * (__int128)0x20C49BA5E353F7CFLL) >> 64;
  v15 = *(_QWORD *)(a7 + 16);
  LOWORD(v21) = 11011;
  v20 = (v14 >> 7) + ((unsigned __int64)v14 >> 63);
  if ( (mlo_is_mld_sta(v15) & 1) != 0 )
    LOBYTE(v23) = wlan_convert_freq_to_diag_band(*(unsigned int *)(a7 + 284));
  HIBYTE(v21) = a1;
  LOWORD(v22) = a2;
  BYTE3(v21) = a3;
  BYTE4(v21) = a4;
  WORD1(v22) = a6;
  BYTE5(v21) = a5;
  result = host_diag_event_report_payload(3384, 52, &v17);
  _ReadStatusReg(SP_EL0);
  return result;
}
