__int64 __fastcall hdd_sap_restart_chan_switch_cb(__int64 a1, __int64 a2, unsigned int a3, unsigned int a4, char a5)
{
  __int64 *link_info_from_vdev; // x0
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7

  link_info_from_vdev = (__int64 *)wlan_hdd_get_link_info_from_vdev();
  if ( link_info_from_vdev )
    return hdd_sap_restart_with_channel_switch(
             a1,
             link_info_from_vdev,
             a3,
             a4,
             a5 & 1,
             v10,
             v11,
             v12,
             v13,
             v14,
             v15,
             v16,
             v17);
  qdf_trace_msg(0x33u, 2u, "%s: Invalid vdev", v10, v11, v12, v13, v14, v15, v16, v17, "hdd_sap_restart_chan_switch_cb");
  return 4;
}
