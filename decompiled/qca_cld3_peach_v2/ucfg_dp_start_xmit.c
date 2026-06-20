__int64 __fastcall ucfg_dp_start_xmit(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 a10)
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
  __int64 v19; // x20
  __int64 v20; // x20
  __int64 result; // x0
  unsigned int v28; // w9
  unsigned int v31; // w10

  if ( a10 )
  {
    comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(a10, 0x2Eu);
    if ( comp_private_obj )
    {
      v19 = *(_QWORD *)(comp_private_obj + 32);
      _X8 = (unsigned int *)(v19 + 3576);
      __asm { PRFM            #0x11, [X8] }
      do
        v28 = __ldxr(_X8);
      while ( __stxr(v28 + 1, _X8) );
      result = dp_start_xmit();
      _X8 = (unsigned int *)(v19 + 3576);
      __asm { PRFM            #0x11, [X8] }
      do
        v31 = __ldxr(_X8);
      while ( __stxr(v31 - 1, _X8) );
      return result;
    }
  }
  else
  {
    qdf_trace_msg(0x45u, 2u, "%s: vdev is null", a1, a2, a3, a4, a5, a6, a7, a8, "dp_get_vdev_priv_obj");
  }
  v20 = jiffies;
  if ( ucfg_dp_start_xmit___last_ticks - jiffies + 125 < 0 )
  {
    qdf_trace_msg(0x45u, 2u, "%s: DP link not found", v11, v12, v13, v14, v15, v16, v17, v18, "ucfg_dp_start_xmit");
    ucfg_dp_start_xmit___last_ticks = v20;
  }
  return 4;
}
