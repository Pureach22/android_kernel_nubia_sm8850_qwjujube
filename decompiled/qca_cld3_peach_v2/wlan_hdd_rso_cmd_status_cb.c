__int64 __fastcall wlan_hdd_rso_cmd_status_cb(__int64 a1, __int64 a2)
{
  __int64 link_info_by_vdev; // x0
  __int64 v4; // x1
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7

  link_info_by_vdev = hdd_get_link_info_by_vdev(a1);
  if ( !link_info_by_vdev )
    return qdf_trace_msg(0x33u, 2u, "%s: Invalid vdev", v5, v6, v7, v8, v9, v10, v11, v12, "wlan_hdd_rso_cmd_status_cb");
  *(_DWORD *)(*(_QWORD *)link_info_by_vdev + 52056LL) = *(unsigned __int8 *)(a2 + 4);
  return complete(*(_QWORD *)link_info_by_vdev + 52064LL, v4);
}
