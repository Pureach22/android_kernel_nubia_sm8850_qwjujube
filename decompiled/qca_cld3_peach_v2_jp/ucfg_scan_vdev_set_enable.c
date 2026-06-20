__int64 __fastcall ucfg_scan_vdev_set_enable(__int64 a1, int a2)
{
  __int64 comp_private_obj; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7

  comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(a1, 3u);
  if ( comp_private_obj )
  {
    *(_DWORD *)(comp_private_obj + 4) &= ~a2;
    qdf_trace_msg(0x15u, 8u, "%s: Vdev scan_disabled %x", v4, v5, v6, v7, v8, v9, v10, v11, "ucfg_scan_vdev_set_enable");
    return 0;
  }
  else
  {
    qdf_trace_msg(0x15u, 2u, "%s: null scan_vdev_obj", v4, v5, v6, v7, v8, v9, v10, v11, "ucfg_scan_vdev_set_enable");
    return 29;
  }
}
