__int64 __fastcall scm_get_rnr_channel_db(__int64 a1)
{
  __int64 comp_private_obj; // x19
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7

  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 3u);
  if ( comp_private_obj )
    return comp_private_obj + 21032;
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
    "scm_get_rnr_channel_db",
    68);
  return 0;
}
