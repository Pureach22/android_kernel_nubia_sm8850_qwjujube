__int64 __fastcall wma_mlo_link_info_sync_rx_process(
        _QWORD *a1,
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
  __int64 v13; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22; // x19
  const char *v23; // x2
  unsigned int v24; // w1
  unsigned int v25; // w20

  if ( (unsigned int)_wma_validate_handle(
                       (__int64)a1,
                       (__int64)"wma_mlo_link_info_sync_rx_process",
                       a3,
                       a4,
                       a5,
                       a6,
                       a7,
                       a8,
                       a9,
                       a10) )
    return 4294967274LL;
  v13 = _qdf_mem_malloc(0xD0u, "wma_mlo_link_info_sync_rx_process", 4556);
  if ( !v13 )
    return 4294967284LL;
  v22 = v13;
  if ( a1[3] )
  {
    if ( !(unsigned int)wmi_extract_mgmt_rx_ml_cu_params(*a1, a2, v13) )
    {
      ((void (__fastcall *)(__int64))lim_update_cuflag_bpcc_each_link)(v22);
      v25 = 0;
      goto LABEL_11;
    }
    v23 = "%s: Failed to extract CU Params";
    v24 = 8;
  }
  else
  {
    v23 = "%s: psoc ctx is NULL";
    v24 = 2;
  }
  qdf_trace_msg(0x36u, v24, v23, v14, v15, v16, v17, v18, v19, v20, v21, "wma_mlo_link_info_sync_rx_process");
  v25 = -22;
LABEL_11:
  _qdf_mem_free(v22);
  return v25;
}
