__int64 __fastcall init_deinit_populate_scan_radio_cap_ext2(
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
  __int64 v11; // x22
  __int64 v15; // x0
  __int64 v16; // x23
  unsigned int scan_radio_cap_service_ready_ext2; // w0
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
    qdf_trace_msg(0x49u, 2u, v27, a4, a5, a6, a7, a8, a9, a10, a11, "init_deinit_populate_scan_radio_cap_ext2");
    return 4294967274LL;
  }
  v11 = *(unsigned __int8 *)(a3 + 944);
  qdf_trace_msg(
    0x49u,
    8u,
    "%s: num scan radio capabilities = %d",
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    "init_deinit_populate_scan_radio_cap_ext2",
    v11);
  if ( !(_DWORD)v11 )
    return 0;
  v15 = _qdf_mem_malloc(8 * v11, "init_deinit_populate_scan_radio_cap_ext2", 1122);
  *(_QWORD *)(a3 + 4432) = v15;
  if ( !v15 )
  {
    v27 = "%s: Failed to allocate memory for scan radio caps";
    goto LABEL_10;
  }
  v16 = 0;
  while ( 1 )
  {
    scan_radio_cap_service_ready_ext2 = wmi_extract_scan_radio_cap_service_ready_ext2(
                                          a1,
                                          a2,
                                          (unsigned int)v16,
                                          *(_QWORD *)(a3 + 4432) + 8 * v16);
    if ( scan_radio_cap_service_ready_ext2 )
      break;
    if ( ++v16 == v11 )
      return 0;
  }
  v28 = scan_radio_cap_service_ready_ext2;
  qdf_trace_msg(
    0x49u,
    2u,
    "%s: Extraction of scan radio cap failed",
    v18,
    v19,
    v20,
    v21,
    v22,
    v23,
    v24,
    v25,
    "init_deinit_populate_scan_radio_cap_ext2");
  _qdf_mem_free(*(_QWORD *)(a3 + 4432));
  *(_QWORD *)(a3 + 4432) = 0;
  return qdf_status_to_os_return(v28);
}
