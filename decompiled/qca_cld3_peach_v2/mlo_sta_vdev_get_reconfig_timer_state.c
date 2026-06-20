__int64 __fastcall mlo_sta_vdev_get_reconfig_timer_state(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x29
  __int64 v10; // x30
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 cmpt_obj; // x0
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  char v30; // w8
  __int64 v31; // [xsp+8h] [xbp-18h]

  if ( !a1 || *(_DWORD *)(a1 + 16) )
    return 0;
  v31 = v10;
  if ( (wlan_vdev_mlme_is_mlo_vdev(a1, a2, a3, a4, a5, a6, a7, a8, a9) & 1) == 0 )
    goto LABEL_8;
  cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(a1, v13, v14, v15, v16, v17, v18, v19, v20);
  if ( !cmpt_obj )
  {
    qdf_trace_msg(
      0x8Fu,
      2u,
      "%s: vdev mlme is null",
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      "mlo_sta_vdev_get_reconfig_timer_state",
      v9,
      v31);
LABEL_8:
    v30 = 0;
    return v30 & 1;
  }
  v30 = *(_BYTE *)(cmpt_obj + 1008);
  return v30 & 1;
}
