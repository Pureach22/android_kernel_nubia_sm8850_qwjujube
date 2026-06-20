__int64 __fastcall init_deinit_populate_dbr_ring_cap_ext2(
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
  __int64 v15; // x0
  __int64 v16; // x22
  __int64 v17; // x0
  unsigned int v18; // w23
  unsigned int dbr_ring_cap_service_ready_ext2; // w0
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  unsigned int v29; // w20

  if ( *(_DWORD *)(a12 + 796) )
  {
    qdf_trace_msg(
      0x49u,
      8u,
      "%s: dbr_ring_caps already populated",
      a1,
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      "init_deinit_populate_dbr_ring_cap_ext2");
    v15 = *(_QWORD *)(a12 + 3272);
    *(_DWORD *)(a12 + 796) = 0;
    _qdf_mem_free(v15);
    *(_QWORD *)(a12 + 3272) = 0;
  }
  v16 = *(unsigned int *)(a12 + 924);
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
    "init_deinit_populate_dbr_ring_cap_ext2",
    (unsigned int)v16);
  if ( !(_DWORD)v16 )
    return 0;
  v17 = _qdf_mem_malloc(20 * v16, "init_deinit_populate_dbr_ring_cap_ext2", 489);
  *(_QWORD *)(a12 + 3272) = v17;
  if ( !v17 )
    return 4294967274LL;
  v18 = 0;
  while ( 1 )
  {
    dbr_ring_cap_service_ready_ext2 = wmi_extract_dbr_ring_cap_service_ready_ext2(
                                        a10,
                                        a11,
                                        v18,
                                        *(_QWORD *)(a12 + 3272) + 20LL * (unsigned __int8)v18);
    if ( dbr_ring_cap_service_ready_ext2 )
      break;
    if ( (unsigned int)v16 <= (unsigned __int8)++v18 )
      return 0;
  }
  v29 = dbr_ring_cap_service_ready_ext2;
  qdf_trace_msg(
    0x49u,
    2u,
    "%s: Extraction of DMA cap failed",
    v20,
    v21,
    v22,
    v23,
    v24,
    v25,
    v26,
    v27,
    "init_deinit_populate_dbr_ring_cap_ext2");
  _qdf_mem_free(*(_QWORD *)(a12 + 3272));
  *(_QWORD *)(a12 + 3272) = 0;
  return qdf_status_to_os_return(v29);
}
