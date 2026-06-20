__int64 __fastcall ucfg_dp_softap_start_xmit(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 comp_private_obj; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x20
  __int64 v21; // x20
  __int64 result; // x0
  unsigned int v29; // w9
  unsigned int v32; // w10

  if ( a2 )
  {
    comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(a2, 0x2Eu);
    if ( comp_private_obj )
    {
      v20 = *(_QWORD *)(comp_private_obj + 32);
      _X8 = (unsigned int *)(v20 + 3576);
      __asm { PRFM            #0x11, [X8] }
      do
        v29 = __ldxr(_X8);
      while ( __stxr(v29 + 1, _X8) );
      result = dp_softap_start_xmit(a1, comp_private_obj);
      _X8 = (unsigned int *)(v20 + 3576);
      __asm { PRFM            #0x11, [X8] }
      do
        v32 = __ldxr(_X8);
      while ( __stxr(v32 - 1, _X8) );
      return result;
    }
  }
  else
  {
    qdf_trace_msg(0x45u, 2u, "%s: vdev is null", a3, a4, a5, a6, a7, a8, a9, a10, "dp_get_vdev_priv_obj");
  }
  v21 = jiffies;
  if ( ucfg_dp_softap_start_xmit___last_ticks - jiffies + 125 < 0 )
  {
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: DP link not found",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "ucfg_dp_softap_start_xmit");
    ucfg_dp_softap_start_xmit___last_ticks = v21;
  }
  return 4;
}
