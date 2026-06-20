__int64 __fastcall cam_jpeg_dma_deinit_hw(__int64 a1)
{
  __int64 v1; // x19
  int v3; // w6
  int v5; // w0
  int v6; // w0

  if ( !a1 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      512,
      1,
      "cam_jpeg_dma_deinit_hw",
      118,
      "Invalid cam_dev_info");
    return 4294967274LL;
  }
  v1 = *(_QWORD *)(a1 + 3680);
  if ( !v1 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      512,
      1,
      "cam_jpeg_dma_deinit_hw",
      127,
      "soc_info = %pK core_info = %pK",
      (const void *)(a1 + 96),
      nullptr);
    return 4294967274LL;
  }
  mutex_lock(v1 + 64);
  v3 = *(_DWORD *)(v1 + 56) - 1;
  *(_DWORD *)(v1 + 56) = v3;
  if ( v3 >= 1 )
  {
LABEL_4:
    mutex_unlock(v1 + 64);
    return 0;
  }
  if ( (v3 & 0x80000000) == 0 )
  {
    v5 = cam_jpeg_dma_disable_soc_resources(a1 + 96);
    if ( v5 )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        512,
        1,
        "cam_jpeg_dma_deinit_hw",
        146,
        "soc disable failed %d",
        v5);
    v6 = cam_cpas_stop(*(_DWORD *)(v1 + 16));
    if ( v6 )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        512,
        1,
        "cam_jpeg_dma_deinit_hw",
        150,
        "cpas stop failed: %d",
        v6);
    goto LABEL_4;
  }
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    512,
    1,
    "cam_jpeg_dma_deinit_hw",
    138,
    "ref cnt %d",
    v3);
  *(_DWORD *)(v1 + 56) = 0;
  mutex_unlock(v1 + 64);
  return 4294967282LL;
}
