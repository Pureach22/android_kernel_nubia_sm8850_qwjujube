__int64 __fastcall ucfg_scan_get_global_config(__int64 a1, unsigned int a2, _DWORD *a3)
{
  __int64 comp_private_obj; // x21
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  int v14; // w8

  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 3u);
  if ( !comp_private_obj )
  {
    qdf_trace_msg(
      0x15u,
      2u,
      "%s: %s:%u, Failed to get scan object",
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      "wlan_psoc_get_scan_obj_fl",
      "ucfg_scan_get_global_config",
      1635);
    goto LABEL_7;
  }
  if ( !a3 )
  {
LABEL_7:
    qdf_trace_msg(
      0x15u,
      2u,
      "%s: scan object:%pK config:%d, val:0x%pK",
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      "ucfg_scan_get_global_config",
      comp_private_obj,
      a2,
      a3);
    return 4;
  }
  if ( a2 == 1 )
  {
    v14 = *(unsigned __int8 *)(comp_private_obj + 18739);
    goto LABEL_10;
  }
  if ( a2 )
    return 4;
  v14 = *(unsigned __int8 *)(comp_private_obj + 18738);
LABEL_10:
  *a3 = v14;
  return 0;
}
