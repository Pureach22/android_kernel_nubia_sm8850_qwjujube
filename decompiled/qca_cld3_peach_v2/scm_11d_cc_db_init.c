__int64 __fastcall scm_11d_cc_db_init(
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
  __int64 v18; // x19
  void *v19; // x0
  void *v20; // x20
  const char *v22; // x2

  if ( a1 )
  {
    comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 3u);
    if ( comp_private_obj )
    {
      v18 = comp_private_obj;
      v19 = qdf_mem_malloc_atomic_fl(0x25Cu, (__int64)"scm_11d_cc_db_init", 0xF0u);
      if ( v19 )
      {
        v20 = v19;
        qdf_mem_set(v19, 0x25Cu, 0);
        *(_QWORD *)(v18 + 1592) = v20;
        return 0;
      }
      v22 = "%s: alloc country code db error";
    }
    else
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
        "scm_11d_cc_db_init",
        233);
      v22 = "%s: scan_obj is NULL";
    }
  }
  else
  {
    v22 = "%s: psoc is NULL";
  }
  qdf_trace_msg(0x15u, 2u, v22, a2, a3, a4, a5, a6, a7, a8, a9, "scm_11d_cc_db_init");
  return 4;
}
