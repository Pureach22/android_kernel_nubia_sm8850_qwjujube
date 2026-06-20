__int64 __fastcall scm_db_deinit(
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
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x19
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  __int64 i; // x22
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7

  if ( a1 )
  {
    comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 3u);
    if ( comp_private_obj )
    {
      v19 = comp_private_obj;
      scm_flush_scan_entries(a1, comp_private_obj + 32, 0, 0);
      for ( i = 72; i != 1608; i += 24 )
      {
        if ( *(_DWORD *)(v19 + i) )
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: list length not equal to zero",
            v20,
            v21,
            v22,
            v23,
            v24,
            v25,
            v26,
            v27,
            "qdf_list_destroy");
      }
    }
    else
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
        "wlan_pdevid_get_scan_db",
        57);
      qdf_trace_msg(0x15u, 2u, "%s: scan_db is NULL %d", v30, v31, v32, v33, v34, v35, v36, v37, "scm_db_deinit", 0);
    }
    return 0;
  }
  else
  {
    qdf_trace_msg(0x15u, 2u, "%s: scan obj is NULL", a2, a3, a4, a5, a6, a7, a8, a9, "scm_db_deinit");
    return 4;
  }
}
