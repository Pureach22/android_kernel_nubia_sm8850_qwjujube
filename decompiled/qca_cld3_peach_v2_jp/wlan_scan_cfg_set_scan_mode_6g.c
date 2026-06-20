__int64 __fastcall wlan_scan_cfg_set_scan_mode_6g(__int64 a1, int a2)
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
  __int64 v12; // x8

  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 3u);
  if ( comp_private_obj )
  {
    v12 = comp_private_obj;
    *(_DWORD *)(v12 + 1740) = a2;
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x15u,
      2u,
      "%s: %s:%u, Failed to get scan object",
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      "wlan_psoc_get_scan_obj_fl",
      "wlan_scan_cfg_set_scan_mode_6g",
      173);
    return 4;
  }
}
