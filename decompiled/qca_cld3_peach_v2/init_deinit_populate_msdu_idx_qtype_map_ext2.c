__int64 __fastcall init_deinit_populate_msdu_idx_qtype_map_ext2(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  size_t v11; // x22
  __int64 v15; // x0
  unsigned int v16; // w23
  unsigned int msdu_idx_qtype_map_service_ready_ext2; // w0
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  const char *v27; // x2
  unsigned int v28; // w20

  if ( !a2 )
  {
    v27 = "%s: Invalid event buffer";
LABEL_10:
    qdf_trace_msg(0x49u, 2u, v27, a4, a5, a6, a7, a8, a9, a10, a11, "init_deinit_populate_msdu_idx_qtype_map_ext2");
    return 4294967274LL;
  }
  v11 = *(unsigned int *)(a3 + 964);
  qdf_trace_msg(
    0x49u,
    8u,
    "%s: num msdu_idx to qtype map = %d",
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    "init_deinit_populate_msdu_idx_qtype_map_ext2",
    (unsigned int)v11);
  if ( !(_DWORD)v11 )
    return 0;
  v15 = _qdf_mem_malloc(v11, "init_deinit_populate_msdu_idx_qtype_map_ext2", 1182);
  *(_QWORD *)(a3 + 5720) = v15;
  if ( !v15 )
  {
    v27 = "%s: Failed to allocate memory for msdu idx qtype map";
    goto LABEL_10;
  }
  v16 = 0;
  while ( 1 )
  {
    msdu_idx_qtype_map_service_ready_ext2 = wmi_extract_msdu_idx_qtype_map_service_ready_ext2(
                                              a1,
                                              a2,
                                              v16,
                                              *(_QWORD *)(a3 + 5720) + (unsigned __int8)v16);
    if ( msdu_idx_qtype_map_service_ready_ext2 )
      break;
    if ( (unsigned int)v11 <= (unsigned __int8)++v16 )
      return 0;
  }
  v28 = msdu_idx_qtype_map_service_ready_ext2;
  qdf_trace_msg(
    0x49u,
    2u,
    "%s: Extraction of msdu idx qtype map failed",
    v18,
    v19,
    v20,
    v21,
    v22,
    v23,
    v24,
    v25,
    "init_deinit_populate_msdu_idx_qtype_map_ext2");
  _qdf_mem_free(*(_QWORD *)(a3 + 5720));
  *(_QWORD *)(a3 + 5720) = 0;
  return qdf_status_to_os_return(v28);
}
