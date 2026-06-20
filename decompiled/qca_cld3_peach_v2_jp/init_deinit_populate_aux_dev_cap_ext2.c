__int64 __fastcall init_deinit_populate_aux_dev_cap_ext2(
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
  unsigned int aux_dev_cap_service_ready_ext2; // w0
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  unsigned int v28; // w20

  v12 = *(unsigned int *)(a12 + 980);
  qdf_trace_msg(
    0x49u,
    4u,
    "%s: num_aux_dev_caps = %d",
    a1,
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    "init_deinit_populate_aux_dev_cap_ext2",
    (unsigned int)v12);
  if ( !(_DWORD)v12 )
    return 0;
  v16 = _qdf_mem_malloc(20 * v12, "init_deinit_populate_aux_dev_cap_ext2", 711);
  *(_QWORD *)(a12 + 4456) = v16;
  if ( !v16 )
    return 4294967274LL;
  v17 = 0;
  while ( 1 )
  {
    aux_dev_cap_service_ready_ext2 = wmi_extract_aux_dev_cap_service_ready_ext2(
                                       a10,
                                       a11,
                                       v17,
                                       *(_QWORD *)(a12 + 4456) + 20LL * (unsigned __int8)v17);
    if ( aux_dev_cap_service_ready_ext2 )
      break;
    if ( (unsigned int)v12 <= (unsigned __int8)++v17 )
      return 0;
  }
  v28 = aux_dev_cap_service_ready_ext2;
  qdf_trace_msg(
    0x49u,
    2u,
    "%s: Extraction of aux dev cap failed",
    v19,
    v20,
    v21,
    v22,
    v23,
    v24,
    v25,
    v26,
    "init_deinit_populate_aux_dev_cap_ext2");
  _qdf_mem_free(*(_QWORD *)(a12 + 4456));
  *(_QWORD *)(a12 + 4456) = 0;
  *(_DWORD *)(a12 + 980) = 0;
  return qdf_status_to_os_return(v28);
}
