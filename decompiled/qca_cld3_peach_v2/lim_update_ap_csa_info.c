__int64 __fastcall lim_update_ap_csa_info(__int64 a1)
{
  __int64 system_time; // x20
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 v11; // x0
  __int64 cmpt_obj; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x21
  __int64 result; // x0
  int v23; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v24; // [xsp+8h] [xbp-8h]

  v24 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  system_time = qdf_mc_timer_get_system_time();
  v11 = *(_QWORD *)(a1 + 16);
  v23 = 0;
  if ( v11 )
  {
    cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(v11, v3, v4, v5, v6, v7, v8, v9, v10);
    if ( cmpt_obj )
    {
      v21 = cmpt_obj;
      if ( !*(_BYTE *)(a1 + 7218) )
        *(_QWORD *)(cmpt_obj + 264) = system_time;
      result = wlan_util_vdev_mgr_compute_max_channel_switch_time(*(_QWORD *)(a1 + 16), &v23);
      *(_DWORD *)(v21 + 256) = v23;
    }
    else
    {
      result = qdf_trace_msg(
                 0x35u,
                 2u,
                 "%s: VDEV_%d: VDEV_MLME is NULL",
                 v13,
                 v14,
                 v15,
                 v16,
                 v17,
                 v18,
                 v19,
                 v20,
                 "lim_update_ap_csa_info",
                 *(unsigned __int8 *)(a1 + 10));
    }
  }
  else
  {
    result = qdf_trace_msg(0x35u, 2u, "%s: VDEV is NULL", v3, v4, v5, v6, v7, v8, v9, v10, "lim_update_ap_csa_info");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
