__int64 __fastcall wma_get_snr(
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
  __int64 *context; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x21
  __int64 result; // x0
  __int64 *v21; // x22
  void *v22; // x0
  __int64 v23; // x20
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7

  context = _cds_get_context(54, (__int64)"wma_get_snr", a2, a3, a4, a5, a6, a7, a8, a9);
  if ( !context )
    return 5;
  v19 = context[65] + 488LL * *(unsigned __int8 *)(a1 + 4);
  if ( *(_QWORD *)(v19 + 256) )
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: previous snr request is pending",
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      "wma_get_snr");
    return 0;
  }
  else
  {
    v21 = context;
    v22 = (void *)_qdf_mem_malloc(0x20u, "wma_get_snr", 246);
    if ( v22 )
    {
      v23 = (__int64)v22;
      qdf_mem_set(v22, 0x20u, 0);
      *(_QWORD *)(v23 + 16) = *(_QWORD *)(a1 + 16);
      *(_QWORD *)(v23 + 8) = *(_QWORD *)(a1 + 8);
      *(_QWORD *)(v19 + 256) = v23;
      result = wmi_unified_snr_cmd(*v21);
      if ( (_DWORD)result )
      {
        qdf_trace_msg(
          0x36u,
          2u,
          "%s: Failed to send host stats request to fw",
          v24,
          v25,
          v26,
          v27,
          v28,
          v29,
          v30,
          v31,
          "wma_get_snr");
        _qdf_mem_free(v23);
        *(_QWORD *)(v19 + 256) = 0;
        return 16;
      }
    }
    else
    {
      return 2;
    }
  }
  return result;
}
