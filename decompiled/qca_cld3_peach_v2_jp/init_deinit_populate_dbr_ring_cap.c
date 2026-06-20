__int64 __fastcall init_deinit_populate_dbr_ring_cap(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 a10,
        __int64 a11,
        __int64 a12)
{
  __int64 v12; // x21
  __int64 v16; // x0
  unsigned int v17; // w23
  unsigned int dbr_ring_cap_service_ready_ext; // w0
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  unsigned int v28; // w20

  v12 = *(unsigned int *)(a12 + 796);
  qdf_trace_msg(
    0x49u,
    8u,
    "%s: Num DMA Capabilities = %d",
    a1,
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    "init_deinit_populate_dbr_ring_cap",
    (unsigned int)v12);
  if ( !(_DWORD)v12 )
    return 0;
  v16 = _qdf_mem_malloc(20 * v12, "init_deinit_populate_dbr_ring_cap", 436);
  *(_QWORD *)(a12 + 3272) = v16;
  if ( !v16 )
    return 4294967274LL;
  v17 = 0;
  while ( 1 )
  {
    dbr_ring_cap_service_ready_ext = wmi_extract_dbr_ring_cap_service_ready_ext(
                                       a10,
                                       a11,
                                       v17,
                                       *(_QWORD *)(a12 + 3272) + 20LL * (unsigned __int8)v17);
    if ( dbr_ring_cap_service_ready_ext )
      break;
    if ( (unsigned int)v12 <= (unsigned __int8)++v17 )
      return 0;
  }
  v28 = dbr_ring_cap_service_ready_ext;
  qdf_trace_msg(
    0x49u,
    2u,
    "%s: Extraction of DMA cap failed",
    v19,
    v20,
    v21,
    v22,
    v23,
    v24,
    v25,
    v26,
    "init_deinit_populate_dbr_ring_cap");
  _qdf_mem_free(*(_QWORD *)(a12 + 3272));
  *(_QWORD *)(a12 + 3272) = 0;
  return qdf_status_to_os_return(v28);
}
