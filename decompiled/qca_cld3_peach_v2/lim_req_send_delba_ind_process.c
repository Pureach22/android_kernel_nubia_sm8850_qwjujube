__int64 __fastcall lim_req_send_delba_ind_process(
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
  unsigned __int8 *v11; // x20
  __int64 **context; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 **v22; // x21
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 v31; // x8
  void (__fastcall *v32)(__int64 **, unsigned __int8 *, __int64, __int64, __int64); // x8
  __int64 v33; // x2
  __int64 v34; // x3
  __int64 result; // x0

  v11 = *(unsigned __int8 **)(a2 + 8);
  context = (__int64 **)_cds_get_context(71, (__int64)"lim_req_send_delba_ind_process", a3, a4, a5, a6, a7, a8, a9, a10);
  if ( !v11 )
    return qdf_trace_msg(
             0x35u,
             2u,
             "%s: Invalid body pointer in message",
             v14,
             v15,
             v16,
             v17,
             v18,
             v19,
             v20,
             v21,
             "lim_req_send_delba_ind_process");
  v22 = context;
  if ( (unsigned int)lim_send_delba_action_frame(a1, *v11, v11 + 1, v11[7], v11[8]) )
  {
    if ( v22 && *v22 )
    {
      v31 = **v22;
      if ( v31 )
      {
        v32 = *(void (__fastcall **)(__int64 **, unsigned __int8 *, __int64, __int64, __int64))(v31 + 472);
        if ( v32 )
        {
          v33 = *v11;
          v34 = v11[7];
          if ( *((_DWORD *)v32 - 1) != 75369535 )
            __break(0x8228u);
          v32(v22, v11 + 1, v33, v34, 1);
        }
      }
    }
    else
    {
      qdf_trace_msg(
        0x89u,
        8u,
        "%s: Invalid Instance:",
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        "cdp_delba_tx_completion");
    }
  }
  result = _qdf_mem_free((__int64)v11);
  *(_QWORD *)(a2 + 8) = 0;
  return result;
}
