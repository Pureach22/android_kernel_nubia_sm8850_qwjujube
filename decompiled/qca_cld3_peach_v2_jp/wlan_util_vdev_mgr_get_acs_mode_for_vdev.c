__int64 __fastcall wlan_util_vdev_mgr_get_acs_mode_for_vdev(__int64 a1)
{
  __int64 cmpt_obj; // x0
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
  char v10; // w8

  cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(a1);
  if ( cmpt_obj )
  {
    v10 = *(_BYTE *)(cmpt_obj + 256);
  }
  else
  {
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: vdev_mlme is null",
      v2,
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      "wlan_util_vdev_mgr_get_acs_mode_for_vdev");
    v10 = 0;
  }
  return v10 & 1;
}
