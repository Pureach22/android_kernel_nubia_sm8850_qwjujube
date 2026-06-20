__int64 __fastcall scm_11d_cc_db_deinit(
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
  const char *v19; // x2

  if ( a1 )
  {
    comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 3u);
    if ( comp_private_obj )
    {
      _qdf_mem_free(*(_QWORD *)(comp_private_obj + 1592));
      return 0;
    }
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
      "scm_11d_cc_db_deinit",
      263);
    v19 = "%s: scan_obj is NULL";
  }
  else
  {
    v19 = "%s: psoc is NULL";
  }
  qdf_trace_msg(0x15u, 2u, v19, a2, a3, a4, a5, a6, a7, a8, a9, "scm_11d_cc_db_deinit");
  return 4;
}
