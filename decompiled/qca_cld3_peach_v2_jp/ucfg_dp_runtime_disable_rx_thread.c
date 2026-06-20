__int64 __fastcall ucfg_dp_runtime_disable_rx_thread(
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
  __int64 comp_private_obj; // x19
  __int64 result; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  unsigned int *v21; // x21
  int v22; // w8
  __int64 (*v23)(void); // x8
  unsigned int v24; // w19
  unsigned int v31; // w10
  unsigned int v34; // w10

  if ( !a1 )
  {
    qdf_trace_msg(0x45u, 2u, "%s: vdev is null", a3, a4, a5, a6, a7, a8, a9, a10, "dp_get_vdev_priv_obj");
    _cds_get_context(71, "ucfg_dp_runtime_disable_rx_thread");
    return qdf_trace_msg(
             0x45u,
             2u,
             "%s: Unable to get DP link",
             v13,
             v14,
             v15,
             v16,
             v17,
             v18,
             v19,
             v20,
             "ucfg_dp_runtime_disable_rx_thread");
  }
  comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(a1, 0x2Eu);
  result = _cds_get_context(71, "ucfg_dp_runtime_disable_rx_thread");
  if ( !comp_private_obj )
    return qdf_trace_msg(
             0x45u,
             2u,
             "%s: Unable to get DP link",
             v13,
             v14,
             v15,
             v16,
             v17,
             v18,
             v19,
             v20,
             "ucfg_dp_runtime_disable_rx_thread");
  v21 = *(unsigned int **)(comp_private_obj + 32);
  if ( v21 && *(_QWORD *)v21 )
  {
    if ( (*(_BYTE *)(*(_QWORD *)v21 + 371LL) & 1) != 0 )
    {
      v22 = a2 & 1;
      _X9 = v21 + 894;
      __asm { PRFM            #0x11, [X9] }
      do
        v31 = __ldxr(_X9);
      while ( __stxr(v31 + 1, _X9) );
      if ( *((unsigned __int8 *)v21 + 3614) != v22 )
      {
        *((_BYTE *)v21 + 3614) = v22;
        if ( result )
        {
          if ( *(_QWORD *)result )
          {
            v23 = *(__int64 (**)(void))(**(_QWORD **)result + 624LL);
            if ( v23 )
            {
              v24 = *(unsigned __int8 *)(comp_private_obj + 24);
              if ( *((_DWORD *)v23 - 1) != -1355198606 )
                __break(0x8228u);
              result = v23();
              if ( result )
                result = dp_rx_tm_flush_by_vdev_id(result + 16, v24);
            }
          }
          else
          {
            result = qdf_trace_msg(
                       0x89u,
                       8u,
                       "%s: Invalid Instance:",
                       v13,
                       v14,
                       v15,
                       v16,
                       v17,
                       v18,
                       v19,
                       v20,
                       "cdp_soc_get_dp_txrx_handle");
          }
        }
      }
      _X8 = v21 + 894;
      __asm { PRFM            #0x11, [X8] }
      do
        v34 = __ldxr(_X8);
      while ( __stxr(v34 - 1, _X8) );
    }
    else
    {
      return qdf_trace_msg(
               0x45u,
               5u,
               "%s: rx_thread is not enabled",
               v13,
               v14,
               v15,
               v16,
               v17,
               v18,
               v19,
               v20,
               "ucfg_dp_runtime_disable_rx_thread");
    }
  }
  return result;
}
