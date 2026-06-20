__int64 __fastcall wlan_objmgr_global_obj_init(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8)
{
  __int64 v9; // x0

  if ( g_umac_glb_obj )
  {
    qdf_trace_msg(
      0x57u,
      2u,
      "%s: Global object is already created",
      a1,
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      "wlan_objmgr_global_obj_init");
    return 16;
  }
  else
  {
    v9 = _qdf_mem_malloc(0x2DD8u, "wlan_objmgr_global_obj_init", 51);
    if ( v9 )
    {
      g_umac_glb_obj = v9;
      *(_DWORD *)(v9 + 11720) = 0;
      *(_QWORD *)(v9 + 11728) = 0;
      return 0;
    }
    else
    {
      return 2;
    }
  }
}
