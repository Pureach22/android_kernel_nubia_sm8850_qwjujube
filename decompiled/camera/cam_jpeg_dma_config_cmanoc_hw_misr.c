__int64 __fastcall cam_jpeg_dma_config_cmanoc_hw_misr(unsigned int *a1, __int64 a2, _DWORD *a3)
{
  __int64 v3; // x20
  __int64 v6; // x8
  __int64 result; // x0
  const char *v8; // x5
  __int64 v9; // x4

  v3 = *(_QWORD *)(a2 + 312);
  if ( !v3 )
  {
    v8 = "Invalid camnoc base address";
    v9 = 608;
LABEL_10:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      512,
      1,
      "cam_jpeg_dma_config_cmanoc_hw_misr",
      v9,
      v8);
    return 4294967274LL;
  }
  if ( !a3 )
  {
    v8 = "Invalid command argument";
    v9 = 613;
    goto LABEL_10;
  }
  cam_io_w_mb(a1[16], *(_QWORD *)(a2 + 288) + a1[8]);
  cam_io_w_mb(a1[36], v3 + a1[31]);
  cam_io_w_mb(a1[36], v3 + a1[32]);
  v6 = 38;
  if ( *a3 == 2 )
    v6 = 39;
  cam_io_w_mb(a1[v6], v3 + a1[33]);
  cam_io_w_mb(a1[40], v3 + a1[34]);
  result = 0;
  if ( (debug_mdl & 0x200) != 0 && !debug_priority )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      debug_mdl & 0x200,
      4,
      "cam_jpeg_dma_config_cmanoc_hw_misr",
      645,
      "DMA CAMNOC and HW MISR configured");
    return 0;
  }
  return result;
}
