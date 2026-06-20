__int64 __fastcall cam_jpeg_dma_stop_hw(__int64 a1)
{
  __int64 v1; // x21
  __int64 v3; // x22
  __int64 v4; // x23

  if ( a1 )
  {
    v1 = *(_QWORD *)(a1 + 3680);
    v3 = *(_QWORD *)(a1 + 384);
    v4 = *(_QWORD *)(v1 + 8);
    mutex_lock(v1 + 64);
    raw_spin_lock(a1 + 48);
    if ( *(_DWORD *)v1 == 3 )
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        512,
        1,
        "cam_jpeg_dma_stop_hw",
        382,
        "alrady stopping");
      raw_spin_unlock(a1 + 48);
    }
    else
    {
      *(_DWORD *)(a1 + 56) = 0;
      *(_DWORD *)v1 = 3;
      raw_spin_unlock(a1 + 48);
      cam_io_w_mb(*(unsigned int *)(v4 + 60), v3 + *(unsigned int *)(v4 + 16));
      if ( !cam_common_wait_for_completion_timeout(a1 + 56) )
      {
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          512,
          1,
          "cam_jpeg_dma_stop_hw",
          399,
          "error Reset Timeout");
        *(_DWORD *)v1 = 0;
      }
    }
    mutex_unlock(v1 + 64);
    return 0;
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      512,
      1,
      "cam_jpeg_dma_stop_hw",
      370,
      "Invalid args");
    return 4294967274LL;
  }
}
