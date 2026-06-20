__int64 __fastcall wlan_util_vdev_mgr_set_acs_mode_for_vdev(__int64 a1, char a2)
{
  __int64 result; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7

  result = wlan_vdev_mlme_get_cmpt_obj(a1);
  if ( !result )
    return qdf_trace_msg(
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
             "wlan_util_vdev_mgr_set_acs_mode_for_vdev");
  *(_BYTE *)(result + 272) = a2 & 1;
  return result;
}
