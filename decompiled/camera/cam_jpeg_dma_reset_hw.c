__int64 __fastcall cam_jpeg_dma_reset_hw(__int64 a1)
{
  __int64 v1; // x21
  __int64 v3; // x22
  unsigned int *v4; // x23
  __int64 v6; // x0
  int v7; // w8
  unsigned int v8; // w19

  if ( a1 )
  {
    v1 = *(_QWORD *)(a1 + 3680);
    v3 = *(_QWORD *)(a1 + 384);
    v4 = *(unsigned int **)(v1 + 8);
    mutex_lock(v1 + 64);
    raw_spin_lock(a1 + 48);
    if ( *(_DWORD *)v1 == 2 )
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        512,
        1,
        "cam_jpeg_dma_reset_hw",
        262,
        "dma alrady resetting");
      raw_spin_unlock(a1 + 48);
      mutex_unlock(v1 + 64);
      return 0;
    }
    else
    {
      *(_DWORD *)(a1 + 56) = 0;
      *(_DWORD *)v1 = 2;
      raw_spin_unlock(a1 + 48);
      cam_io_w_mb(v4[11], v3 + v4[3]);
      cam_io_w_mb(v4[10], v3 + v4[2]);
      cam_io_w_mb(v4[12], v3 + v4[3]);
      cam_io_w_mb(v4[14], v3 + v4[5]);
      v6 = cam_common_wait_for_completion_timeout(a1 + 56);
      v7 = 0;
      if ( !v6 )
      {
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          512,
          1,
          "cam_jpeg_dma_reset_hw",
          286,
          "dma error Reset Timeout");
        v7 = -110;
        *(_DWORD *)v1 = 0;
      }
      v8 = v7;
      mutex_unlock(v1 + 64);
      return v8;
    }
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      512,
      1,
      "cam_jpeg_dma_reset_hw",
      249,
      "Invalid args");
    return 4294967274LL;
  }
}
