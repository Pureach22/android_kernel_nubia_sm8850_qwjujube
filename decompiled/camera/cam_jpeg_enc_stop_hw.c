__int64 __fastcall cam_jpeg_enc_stop_hw(__int64 a1)
{
  __int64 v1; // x22
  __int64 v3; // x23
  __int64 v4; // x24
  __int64 v5; // x20

  if ( a1 )
  {
    v1 = *(_QWORD *)(a1 + 3680);
    v3 = *(_QWORD *)(a1 + 384);
    v4 = *(_QWORD *)(v1 + 8);
    mutex_lock(v1 + 64);
    v5 = raw_spin_lock_irqsave(a1 + 48);
    if ( *(_DWORD *)(a1 + 92) )
    {
      if ( *(_DWORD *)v1 == 3 )
      {
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          512,
          1,
          "cam_jpeg_enc_stop_hw",
          434,
          "alrady stopping");
        raw_spin_unlock_irqrestore(a1 + 48, v5);
      }
      else
      {
        *(_DWORD *)(a1 + 56) = 0;
        *(_DWORD *)v1 = 3;
        raw_spin_unlock_irqrestore(a1 + 48, v5);
        cam_io_w_mb(*(unsigned int *)(v4 + 92), v3 + *(unsigned int *)(v4 + 16));
        if ( !cam_common_wait_for_completion_timeout(a1 + 56) )
        {
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
            3,
            512,
            1,
            "cam_jpeg_enc_stop_hw",
            451,
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
        "cam_jpeg_enc_stop_hw",
        428,
        "JPEG HW is in off state");
      raw_spin_unlock_irqrestore(a1 + 48, v5);
      mutex_unlock(v1 + 64);
      return 4294967274LL;
    }
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      512,
      1,
      "cam_jpeg_enc_stop_hw",
      416,
      "Invalid args");
    return 4294967274LL;
  }
}
