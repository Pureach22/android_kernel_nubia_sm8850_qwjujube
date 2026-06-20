__int64 __fastcall scm_db_init(
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
  __int64 v19; // x8
  _QWORD *v20; // x10
  __int64 v21; // x0
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int64 v30; // x19
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7

  if ( a1 )
  {
    comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 3u);
    if ( comp_private_obj )
    {
      v19 = 0;
      *(_DWORD *)(comp_private_obj + 32) = 0;
      *(_DWORD *)(comp_private_obj + 40) = 0;
      *(_QWORD *)(comp_private_obj + 48) = 0;
      do
      {
        v20 = (_QWORD *)(comp_private_obj + v19);
        v19 += 24;
        v20[7] = v20 + 7;
        v20[8] = v20 + 7;
        v20[9] = 0x1F400000000LL;
      }
      while ( v19 != 1536 );
      v21 = wlan_objmgr_psoc_get_comp_private_obj(a1, 3u);
      if ( v21 )
      {
        v30 = v21;
        qdf_trace_msg(
          0x15u,
          8u,
          "%s: pdev %d, Reset all channel info",
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          v28,
          v29,
          "scm_reset_scan_chan_info",
          0);
        qdf_mem_set((void *)(v30 + 17524), 0x334u, 0);
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
          "scm_reset_scan_chan_info",
          1955);
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
      qdf_trace_msg(0x15u, 2u, "%s: scan_db is NULL %d", v32, v33, v34, v35, v36, v37, v38, v39, "scm_db_init", 0);
    }
    return 0;
  }
  else
  {
    qdf_trace_msg(0x15u, 2u, "%s: psoc is NULL", a2, a3, a4, a5, a6, a7, a8, a9, "scm_db_init");
    return 4;
  }
}
