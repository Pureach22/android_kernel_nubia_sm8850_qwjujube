__int64 __fastcall wlan_cm_get_exclude_rm_partial_scan_freq(__int64 a1)
{
  __int64 psoc_ext_obj_fl; // x0
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7

  psoc_ext_obj_fl = mlme_get_psoc_ext_obj_fl(a1);
  if ( psoc_ext_obj_fl )
    return *(unsigned __int8 *)(psoc_ext_obj_fl + 2558);
  qdf_trace_msg(
    0x1Fu,
    2u,
    "%s: Failed to get MLME Obj",
    v2,
    v3,
    v4,
    v5,
    v6,
    v7,
    v8,
    v9,
    "wlan_cm_get_exclude_rm_partial_scan_freq");
  return 0;
}
