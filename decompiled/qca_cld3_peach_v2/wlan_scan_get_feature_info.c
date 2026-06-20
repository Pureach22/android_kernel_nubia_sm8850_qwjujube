__int64 __fastcall wlan_scan_get_feature_info(__int64 a1, _BYTE *a2)
{
  __int64 result; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  int v13; // w8
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  char v30; // w8
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7

  result = wlan_objmgr_psoc_get_comp_private_obj(a1, 3u);
  if ( result )
  {
    v13 = *(unsigned __int8 *)(result + 18357);
    *a2 = v13;
    if ( v13 != 1 )
      return result;
  }
  else
  {
    qdf_trace_msg(
      0x15u,
      2u,
      "%s: %s:%u, Failed to get scan object",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "wlan_psoc_get_scan_obj_fl",
      "wlan_scan_get_pno_scan_support",
      701);
    qdf_trace_msg(
      0x15u,
      2u,
      "%s: NULL scan obj",
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "wlan_scan_get_pno_scan_support");
    *a2 = 1;
  }
  result = wlan_objmgr_psoc_get_comp_private_obj(a1, 3u);
  if ( result )
  {
    v30 = *(_BYTE *)(result + 1745);
  }
  else
  {
    qdf_trace_msg(
      0x15u,
      2u,
      "%s: %s:%u, Failed to get scan object",
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      "wlan_psoc_get_scan_obj_fl",
      "wlan_scan_is_connected_scan_enabled",
      720);
    result = qdf_trace_msg(
               0x15u,
               2u,
               "%s: Failed to get scan object",
               v31,
               v32,
               v33,
               v34,
               v35,
               v36,
               v37,
               v38,
               "wlan_scan_is_connected_scan_enabled");
    v30 = 1;
  }
  a2[1] = v30 & 1;
  return result;
}
