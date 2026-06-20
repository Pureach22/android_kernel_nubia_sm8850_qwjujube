__int64 __fastcall mlo_sta_stop_reconfig_timer_by_vdev(
        __int64 result,
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
  __int64 v11; // x19
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  __int64 v28; // x20
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  __int64 v37; // [xsp+8h] [xbp-18h]

  if ( result )
  {
    if ( !*(_DWORD *)(result + 16) )
    {
      v37 = v10;
      v11 = result;
      result = wlan_vdev_mlme_is_mlo_vdev(result, a2, a3, a4, a5, a6, a7, a8, a9);
      if ( (result & 1) != 0 )
      {
        result = wlan_vdev_mlme_get_cmpt_obj(v11, v12, v13, v14, v15, v16, v17, v18, v19);
        if ( result )
        {
          if ( *(_BYTE *)(result + 1008) == 1 )
          {
            v28 = result;
            timer_delete((timer_t)(result + 952));
            result = qdf_trace_msg(
                       0x8Fu,
                       8u,
                       "%s: vdev %d reconfig timer active to stop",
                       v29,
                       v30,
                       v31,
                       v32,
                       v33,
                       v34,
                       v35,
                       v36,
                       "mlo_sta_stop_reconfig_timer_by_vdev",
                       *(unsigned __int8 *)(v11 + 168),
                       v9,
                       v37);
            *(_BYTE *)(v28 + 1008) = 0;
          }
        }
        else
        {
          return qdf_trace_msg(
                   0x8Fu,
                   2u,
                   "%s: vdev mlme is null",
                   v20,
                   v21,
                   v22,
                   v23,
                   v24,
                   v25,
                   v26,
                   v27,
                   "mlo_sta_stop_reconfig_timer_by_vdev",
                   v9,
                   v37);
        }
      }
    }
  }
  return result;
}
