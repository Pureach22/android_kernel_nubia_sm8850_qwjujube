__int64 __fastcall wlan_util_vdev_mgr_get_csa_channel_switch_time(__int64 a1, int *a2)
{
  __int64 cmpt_obj; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 v12; // x8
  int v14; // w9

  *a2 = 0;
  cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(a1);
  if ( cmpt_obj )
  {
    v12 = cmpt_obj;
    v14 = *(unsigned __int16 *)(v12 + 20) + 550;
    *a2 = v14;
    *a2 = v14 + *(unsigned __int16 *)(v12 + 20);
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: vdev_mlme is null",
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      "wlan_util_vdev_mgr_get_csa_channel_switch_time");
    return 16;
  }
}
