__int64 __fastcall cam_jpeg_dma_start_hw(__int64 a1)
{
  __int64 v1; // x9
  unsigned int *v2; // x20
  __int64 v3; // x19
  const char *v5; // x5
  __int64 v6; // x4

  if ( !a1 )
  {
    v5 = "Invalid args";
    v6 = 335;
LABEL_9:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      512,
      1,
      "cam_jpeg_dma_start_hw",
      v6,
      v5);
    return 4294967274LL;
  }
  v1 = *(_QWORD *)(a1 + 3680);
  if ( *(_DWORD *)v1 != 1 )
  {
    v5 = "Error not ready";
    v6 = 346;
    goto LABEL_9;
  }
  v2 = *(unsigned int **)(v1 + 8);
  v3 = *(_QWORD *)(a1 + 384);
  if ( (debug_mdl & 0x200) != 0 && !debug_priority )
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      debug_mdl & 0x200,
      4,
      "cam_jpeg_dma_start_hw",
      350,
      "Starting DMA");
  cam_io_w_mb(1537, v3 + v2[3]);
  cam_io_w_mb(v2[13], v3 + v2[4]);
  return 0;
}
