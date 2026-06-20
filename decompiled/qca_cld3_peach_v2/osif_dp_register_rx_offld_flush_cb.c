_QWORD *__fastcall osif_dp_register_rx_offld_flush_cb(
        int a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  _QWORD *result; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 (__fastcall **v19)(_QWORD); // x8
  __int64 (__fastcall *v20)(_QWORD); // x8
  __int64 (__fastcall *v21)(); // x0
  __int64 (__fastcall **v22)(_QWORD); // x8
  __int64 (__fastcall **v23)(_QWORD); // x8

  result = _cds_get_context(71, (__int64)"osif_dp_register_rx_offld_flush_cb", a2, a3, a4, a5, a6, a7, a8, a9);
  if ( a1 == 2 )
  {
    if ( result )
    {
      if ( *result )
      {
        v23 = *(__int64 (__fastcall ***)(_QWORD))(*result + 160LL);
        if ( v23 )
        {
          v20 = *v23;
          if ( !v20 )
            return result;
          v21 = osif_dp_hif_napi_gro_flush;
          goto LABEL_19;
        }
      }
    }
    return (_QWORD *)qdf_trace_msg(
                       0x45u,
                       1u,
                       "%s invalid instance",
                       v11,
                       v12,
                       v13,
                       v14,
                       v15,
                       v16,
                       v17,
                       v18,
                       "cdp_register_rx_offld_flush_cb");
  }
  if ( a1 == 1 )
  {
    if ( result )
    {
      if ( *result )
      {
        v22 = *(__int64 (__fastcall ***)(_QWORD))(*result + 160LL);
        if ( v22 )
        {
          v20 = *v22;
          if ( !v20 )
            return result;
          v21 = osif_dp_rxthread_napi_normal_gro_flush;
          goto LABEL_19;
        }
      }
    }
    return (_QWORD *)qdf_trace_msg(
                       0x45u,
                       1u,
                       "%s invalid instance",
                       v11,
                       v12,
                       v13,
                       v14,
                       v15,
                       v16,
                       v17,
                       v18,
                       "cdp_register_rx_offld_flush_cb");
  }
  if ( a1 )
    return result;
  if ( !result )
    return (_QWORD *)qdf_trace_msg(
                       0x45u,
                       1u,
                       "%s invalid instance",
                       v11,
                       v12,
                       v13,
                       v14,
                       v15,
                       v16,
                       v17,
                       v18,
                       "cdp_register_rx_offld_flush_cb");
  if ( !*result )
    return (_QWORD *)qdf_trace_msg(
                       0x45u,
                       1u,
                       "%s invalid instance",
                       v11,
                       v12,
                       v13,
                       v14,
                       v15,
                       v16,
                       v17,
                       v18,
                       "cdp_register_rx_offld_flush_cb");
  v19 = *(__int64 (__fastcall ***)(_QWORD))(*result + 160LL);
  if ( !v19 )
    return (_QWORD *)qdf_trace_msg(
                       0x45u,
                       1u,
                       "%s invalid instance",
                       v11,
                       v12,
                       v13,
                       v14,
                       v15,
                       v16,
                       v17,
                       v18,
                       "cdp_register_rx_offld_flush_cb");
  v20 = *v19;
  if ( !v20 )
    return result;
  v21 = osif_dp_qdf_lro_flush;
LABEL_19:
  if ( *((_DWORD *)v20 - 1) != -1669684001 )
    __break(0x8228u);
  return (_QWORD *)v20(v21);
}
