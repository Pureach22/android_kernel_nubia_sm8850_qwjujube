__int64 __fastcall ucfg_scan_get_wide_band_scan(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  int v9; // w19
  __int64 comp_private_obj; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  char v19; // w8

  if ( !a1 )
  {
    qdf_trace_msg(0x15u, 3u, "%s: null vdev", a2, a3, a4, a5, a6, a7, a8, a9, "ucfg_scan_get_wide_band_scan");
LABEL_7:
    v19 = 1;
    return v19 & 1;
  }
  v9 = *(unsigned __int8 *)(a1 + 40);
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(*(_QWORD *)(a1 + 80), 3u);
  if ( !comp_private_obj )
  {
    qdf_trace_msg(
      0x15u,
      2u,
      "%s: %s:%u, Failed to get scan object",
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      "wlan_psoc_get_scan_obj_fl",
      "wlan_pdev_get_scan_obj",
      764);
    goto LABEL_7;
  }
  if ( !v9 )
  {
    v19 = *(_BYTE *)(comp_private_obj + 16240);
    return v19 & 1;
  }
  __break(0x5512u);
  return ucfg_scan_cancel_sync(comp_private_obj);
}
