__int64 __fastcall ucfg_scan_get_slow_scan_multiplier(__int64 a1)
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
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7

  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 3u);
  if ( comp_private_obj )
    return *(unsigned int *)(comp_private_obj + 18364);
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
    "ucfg_scan_get_slow_scan_multiplier",
    1750);
  qdf_trace_msg(
    0x15u,
    2u,
    "%s: NULL scan obj",
    v11,
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    "ucfg_scan_get_slow_scan_multiplier");
  return 6;
}
