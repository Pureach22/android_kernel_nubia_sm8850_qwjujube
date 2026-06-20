__int64 __fastcall wlan_twt_cfg_deinit(
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
  void *comp_private_obj; // x0
  const char *v11; // x2

  if ( a1 )
  {
    comp_private_obj = (void *)wlan_objmgr_psoc_get_comp_private_obj(a1, 0x2Cu);
    if ( comp_private_obj )
    {
      qdf_mem_set(comp_private_obj, 0x14u, 0);
      return 0;
    }
    v11 = "%s: null twt psoc priv obj";
  }
  else
  {
    v11 = "%s: null psoc";
  }
  qdf_trace_msg(0x96u, 2u, v11, a2, a3, a4, a5, a6, a7, a8, a9, "wlan_twt_cfg_deinit");
  return 16;
}
