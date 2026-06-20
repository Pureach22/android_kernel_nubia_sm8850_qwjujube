__int64 __fastcall ucfg_dp_fisa_route_to_latency_sensitive_reo(
        __int64 a1,
        char a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 result; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  _BYTE *v20; // x8
  _QWORD *v21; // x19
  __int64 v22; // x20
  __int64 v23; // x9
  const char *v24; // x2
  unsigned int v31; // w11
  unsigned int v34; // w10

  if ( !a1 )
  {
    qdf_trace_msg(0x45u, 2u, "%s: vdev is null", a3, a4, a5, a6, a7, a8, a9, a10, "dp_get_vdev_priv_obj");
    goto LABEL_14;
  }
  result = wlan_objmgr_vdev_get_comp_private_obj(a1, 0x2Eu);
  if ( !result )
  {
LABEL_14:
    v24 = "%s: Unable to get DP link";
    return qdf_trace_msg(
             0x45u,
             2u,
             v24,
             v12,
             v13,
             v14,
             v15,
             v16,
             v17,
             v18,
             v19,
             "ucfg_dp_fisa_route_to_latency_sensitive_reo");
  }
  v20 = *(_BYTE **)(result + 32);
  if ( !v20 || !*(_QWORD *)v20 || v20[3612] == (a2 & 1) )
    return result;
  if ( (*(_BYTE *)(*(_QWORD *)v20 + 1496LL) & 1) == 0 )
  {
    v24 = "%s: lsr feature not supported";
    return qdf_trace_msg(
             0x45u,
             2u,
             v24,
             v12,
             v13,
             v14,
             v15,
             v16,
             v17,
             v18,
             v19,
             "ucfg_dp_fisa_route_to_latency_sensitive_reo");
  }
  v20[3612] = a2 & 1;
  v21 = *(_QWORD **)(result + 32);
  v22 = result;
  result = _cds_get_context(71, "dp_flush_fisa_entries_by_link");
  if ( result )
  {
    v23 = *v21;
    if ( *v21 )
    {
      _X10 = (unsigned int *)(v21 + 447);
      __asm { PRFM            #0x11, [X10] }
      do
        v31 = __ldxr(_X10);
      while ( __stxr(v31 + 1, _X10) );
      if ( *(_BYTE *)(v23 + 218) == 1 )
        result = wlan_dp_rx_fisa_flush_by_vdev_id(result, *(unsigned __int8 *)(v22 + 24));
      _X8 = (unsigned int *)(v21 + 447);
      __asm { PRFM            #0x11, [X8] }
      do
        v34 = __ldxr(_X8);
      while ( __stxr(v34 - 1, _X8) );
    }
  }
  return result;
}
