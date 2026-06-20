__int64 __fastcall ucfg_p2p_get_indoor_ch_support(
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
    comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 5u);
    if ( comp_private_obj )
      return (*(unsigned __int8 *)(comp_private_obj + 272) >> 2) & 1;
    v11 = "%s: p2p soc private object is NULL";
  }
  else
  {
    v11 = "%s: invalid psoc";
  }
  qdf_trace_msg(0x4Eu, 2u, v11, a2, a3, a4, a5, a6, a7, a8, a9, "ucfg_p2p_get_indoor_ch_support");
  return 0;
}
