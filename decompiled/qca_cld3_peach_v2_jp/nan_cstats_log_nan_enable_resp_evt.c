__int64 __fastcall nan_cstats_log_nan_enable_resp_evt(__int64 *a1)
{
  __int64 v2; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  int v11; // w9
  char v12; // w10
  __int64 v13; // x20
  unsigned __int64 StatusReg; // x8
  __int16 v15; // w9
  __int64 v16; // x0
  double discovery_state; // d0
  char v18; // w0
  unsigned int *v19; // x8
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  __int64 result; // x0
  int v36; // [xsp+Ch] [xbp-24h] BYREF
  char v37; // [xsp+10h] [xbp-20h]
  char v38; // [xsp+11h] [xbp-1Fh]
  unsigned __int64 time_of_the_day_us; // [xsp+12h] [xbp-1Eh]
  unsigned __int64 v40; // [xsp+1Ah] [xbp-16h]
  __int16 v41; // [xsp+22h] [xbp-Eh]
  char v42; // [xsp+24h] [xbp-Ch]
  __int64 v43; // [xsp+28h] [xbp-8h]

  v43 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = ((__int64 (__fastcall *)(_QWORD, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
         *a1,
         *((unsigned __int8 *)a1 + 14),
         20);
  if ( v2 )
  {
    v11 = *(_DWORD *)(v2 + 16);
    v12 = *(_BYTE *)(v2 + 104);
    v13 = v2;
    v36 = 1376286;
    v37 = v11;
    v38 = v12;
    time_of_the_day_us = qdf_get_time_of_the_day_us();
    __isb(0xFu);
    StatusReg = _ReadStatusReg(CNTVCT_EL0);
    v15 = *((_WORD *)a1 + 6);
    v16 = *a1;
    v40 = StatusReg;
    v41 = v15;
    discovery_state = nan_get_discovery_state(v16);
    v42 = v18;
    wlan_objmgr_vdev_release_ref(v13, 0x14u, v19, discovery_state, v20, v21, v22, v23, v24, v25, v26);
    result = wlan_cp_stats_cstats_write_to_buff(0, (__int64)&v36, 0x19u, v27, v28, v29, v30, v31, v32, v33, v34);
  }
  else
  {
    result = qdf_trace_msg(
               0x53u,
               2u,
               "%s: Invalid vdev!",
               v3,
               v4,
               v5,
               v6,
               v7,
               v8,
               v9,
               v10,
               "nan_cstats_log_nan_enable_resp_evt");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
