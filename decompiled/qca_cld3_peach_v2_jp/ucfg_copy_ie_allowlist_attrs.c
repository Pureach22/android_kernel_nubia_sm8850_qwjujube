bool __fastcall ucfg_copy_ie_allowlist_attrs(__int64 a1, void *a2)
{
  __int64 comp_private_obj; // x19
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7

  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 3u);
  if ( comp_private_obj )
    qdf_mem_copy(a2, (const void *)(comp_private_obj + 18632), 0x68u);
  else
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
      "ucfg_copy_ie_allowlist_attrs",
      1479);
  return comp_private_obj != 0;
}
