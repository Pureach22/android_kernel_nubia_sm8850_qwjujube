__int64 __fastcall wma_cold_boot_cal_event_handler(
        __int64 a1,
        __int64 *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v20; // x21
  unsigned int v21; // w5
  const void *v22; // x19
  __int64 v23; // x0
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  _DWORD *v32; // x20
  size_t v33; // x2

  if ( (unsigned int)_wma_validate_handle(
                       a1,
                       (__int64)"wma_cold_boot_cal_event_handler",
                       a3,
                       a4,
                       a5,
                       a6,
                       a7,
                       a8,
                       a9,
                       a10) )
    return 4294967274LL;
  if ( !a2 )
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: Invalid Cold Boot Cal Event",
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      "wma_cold_boot_cal_event_handler");
    return 4294967274LL;
  }
  v20 = *a2;
  v21 = *((_DWORD *)a2 + 6);
  if ( *(_DWORD *)(*a2 + 4) > v21 || v21 >= 0x801 )
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: Excess data_len:%d, num_data:%d",
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      "wma_cold_boot_cal_event_handler");
    return 4294967274LL;
  }
  v22 = (const void *)a2[2];
  v23 = _qdf_mem_malloc(0x818u, "wma_send_cold_boot_cal_data", 5177);
  if ( v23 )
  {
    v32 = (_DWORD *)v23;
    host_diag_log_set_code(v23, 6680);
    host_diag_log_set_length(v32, 2072);
    v32[3] = 1;
    v33 = *(unsigned int *)(v20 + 4);
    v32[5] = v33;
    v32[4] = *(_DWORD *)(v20 + 8);
    qdf_mem_copy(v32 + 6, v22, v33);
    host_diag_log_submit(v32);
    _qdf_mem_free((__int64)v32);
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: Cold Boot Cal Diag log not sent",
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      "wma_cold_boot_cal_event_handler");
    return 4294967284LL;
  }
}
