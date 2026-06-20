__int64 __fastcall ucfg_tdls_get_current_mode(
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
  const char *v11; // x2

  if ( a1 )
  {
    comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0xAu);
    if ( comp_private_obj )
      return *(unsigned int *)(comp_private_obj + 8);
    v11 = "Failed to get tdls psoc component";
  }
  else
  {
    v11 = "psoc invalid";
  }
  qdf_trace_msg(0, 2u, v11, a2, a3, a4, a5, a6, a7, a8, a9);
  return 0;
}
