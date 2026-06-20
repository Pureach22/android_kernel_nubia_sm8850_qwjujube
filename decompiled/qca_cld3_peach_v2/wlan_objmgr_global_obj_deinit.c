__int64 __fastcall wlan_objmgr_global_obj_deinit(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8)
{
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7

  if ( g_umac_glb_obj )
  {
    if ( (unsigned int)wlan_objmgr_global_obj_can_destroyed() )
    {
      qdf_trace_msg(
        0x57u,
        2u,
        "%s: PSOCs are leaked can't free global objmgr ctx",
        v8,
        v9,
        v10,
        v11,
        v12,
        v13,
        v14,
        v15,
        "wlan_objmgr_global_obj_deinit");
    }
    else
    {
      _qdf_mem_free(g_umac_glb_obj);
      g_umac_glb_obj = 0;
    }
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x57u,
      2u,
      "%s: Global object is not allocated",
      a1,
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      "wlan_objmgr_global_obj_deinit");
    return 16;
  }
}
