__int64 __fastcall ucfg_scan_set_obss_scan_offload(__int64 a1, char a2)
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
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7

  result = wlan_objmgr_psoc_get_comp_private_obj(a1, 3u);
  if ( result )
  {
    *(_BYTE *)(result + 18741) = a2 & 1;
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
      "ucfg_scan_set_obss_scan_offload",
      1661);
    return qdf_trace_msg(
             0x15u,
             2u,
             "%s: NULL scan obj",
             v12,
             v13,
             v14,
             v15,
             v16,
             v17,
             v18,
             v19,
             "ucfg_scan_set_obss_scan_offload");
  }
  return result;
}
