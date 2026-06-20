__int64 __fastcall hdd_hidden_ssid_enable_roaming(__int64 a1, unsigned __int8 a2)
{
  unsigned __int8 *link_info_by_vdev; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7

  link_info_by_vdev = (unsigned __int8 *)hdd_get_link_info_by_vdev(a1, a2);
  if ( link_info_by_vdev )
    return wlan_hdd_set_roaming_state(link_info_by_vdev, 1u, 1);
  else
    return qdf_trace_msg(
             0x33u,
             2u,
             "%s: Invalid vdev",
             v3,
             v4,
             v5,
             v6,
             v7,
             v8,
             v9,
             v10,
             "hdd_hidden_ssid_enable_roaming");
}
