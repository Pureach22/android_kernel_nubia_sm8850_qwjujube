__int64 __fastcall wlan_util_vdev_mgr_compute_max_channel_switch_time(__int64 a1, int *a2)
{
  __int64 cmpt_obj; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  int v13; // w8
  __int64 v14; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  int v23; // w8
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7

  *a2 = 0;
  cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(a1);
  if ( cmpt_obj )
  {
    v13 = *(unsigned __int16 *)(cmpt_obj + 20) + 550;
    *a2 = v13;
    *a2 = v13 + *(unsigned __int16 *)(cmpt_obj + 20);
    v14 = wlan_vdev_mlme_get_cmpt_obj(a1);
    if ( v14 )
    {
      v23 = *(_DWORD *)(v14 + 244);
    }
    else
    {
      qdf_trace_msg(
        0x68u,
        2u,
        "%s: vdev_mlme is null",
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        "wlan_util_vdev_mgr_get_cac_timeout_for_vdev");
      v23 = 0;
    }
    *a2 += v23;
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: vdev_mlme is null",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "wlan_util_vdev_mgr_get_csa_channel_switch_time");
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: Failed to get the CSA channel switch time",
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      "wlan_util_vdev_mgr_compute_max_channel_switch_time");
    return 16;
  }
}
