__int64 __fastcall ucfg_ie_allowlist_enabled(__int64 a1, __int64 a2)
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
  __int64 v12; // x20
  char v13; // w8

  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 3u);
  if ( !comp_private_obj )
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
      "ucfg_ie_allowlist_enabled",
      1494);
LABEL_6:
    v13 = 0;
    return v13 & 1;
  }
  if ( *(_DWORD *)(a2 + 16) )
    goto LABEL_6;
  v12 = comp_private_obj;
  if ( !(unsigned int)wlan_vdev_is_up() )
    goto LABEL_6;
  v13 = *(_BYTE *)(v12 + 18632);
  return v13 & 1;
}
