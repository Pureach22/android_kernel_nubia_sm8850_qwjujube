__int64 __fastcall ucfg_scan_wake_lock_in_user_scan(__int64 a1)
{
  __int64 comp_private_obj; // x0
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
  char v10; // w8

  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 3u);
  if ( comp_private_obj )
  {
    v10 = *(_BYTE *)(comp_private_obj + 1607);
  }
  else
  {
    qdf_trace_msg(
      0x15u,
      2u,
      "%s: %s:%u, Failed to get scan object",
      v2,
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      "wlan_psoc_get_scan_obj_fl",
      "ucfg_scan_wake_lock_in_user_scan",
      1538);
    v10 = 0;
  }
  return v10 & 1;
}
