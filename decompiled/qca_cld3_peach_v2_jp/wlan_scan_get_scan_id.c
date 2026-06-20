__int64 __fastcall wlan_scan_get_scan_id(
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
  __int64 comp_private_obj; // x0
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  const char *v18; // x2
  unsigned int v19; // w19
  unsigned int v27; // w8
  unsigned int v28; // w8

  if ( !a1 )
  {
    v18 = "%s: null psoc";
LABEL_6:
    qdf_trace_msg(0x15u, 2u, v18, a2, a3, a4, a5, a6, a7, a8, a9, "wlan_scan_get_scan_id");
    return 0;
  }
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 3u);
  if ( !comp_private_obj )
  {
    qdf_trace_msg(
      0x15u,
      2u,
      "%s: %s:%u, Failed to get scan object",
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      "wlan_psoc_get_scan_obj_fl",
      "wlan_scan_get_scan_id",
      519);
    v18 = "%s: scan object null";
    goto LABEL_6;
  }
  _X9 = (unsigned int *)(comp_private_obj + 24);
  __asm { PRFM            #0x11, [X9] }
  do
  {
    v27 = __ldxr(_X9);
    v28 = v27 + 1;
  }
  while ( __stlxr(v28, _X9) );
  __dmb(0xBu);
  v19 = v28 & 0xFFF | 0xA000;
  qdf_trace_msg(0x15u, 8u, "%s: scan_id: 0x%x", v10, v11, v12, v13, v14, v15, v16, v17, "wlan_scan_get_scan_id", v19);
  return v19;
}
