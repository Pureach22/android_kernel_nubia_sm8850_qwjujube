__int64 __fastcall cam_jpeg_enc_reset_hw(__int64 a1)
{
  __int64 v1; // x22
  __int64 v3; // x23
  unsigned int *v4; // x24
  __int64 v5; // x20
  __int64 v7; // x0
  int v8; // w8
  unsigned int v9; // w19

  if ( a1 )
  {
    v1 = *(_QWORD *)(a1 + 3680);
    v3 = *(_QWORD *)(a1 + 384);
    v4 = *(unsigned int **)(v1 + 8);
    mutex_lock(v1 + 64);
    v5 = raw_spin_lock_irqsave(a1 + 48);
    if ( *(_DWORD *)(a1 + 92) )
    {
      if ( *(_DWORD *)v1 == 2 )
      {
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          512,
          1,
          "cam_jpeg_enc_reset_hw",
          301,
          "alrady resetting");
        raw_spin_unlock_irqrestore(a1 + 48, v5);
        mutex_unlock(v1 + 64);
        return 0;
      }
      else
      {
        *(_DWORD *)(a1 + 56) = 0;
        *(_DWORD *)v1 = 2;
        raw_spin_unlock_irqrestore(a1 + 48, v5);
        cam_io_w_mb(v4[19], v3 + v4[3]);
        cam_io_w_mb(v4[18], v3 + v4[2]);
        cam_io_w_mb(v4[20], v3 + v4[3]);
        cam_io_w_mb(v4[22], v3 + v4[5]);
        v7 = cam_common_wait_for_completion_timeout(a1 + 56);
        v8 = 0;
        if ( !v7 )
        {
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
            3,
            512,
            1,
            "cam_jpeg_enc_reset_hw",
            324,
            "error Reset Timeout");
          v8 = -110;
          *(_DWORD *)v1 = 0;
        }
        v9 = v8;
        mutex_unlock(v1 + 64);
        return v9;
      }
    }
    else
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        512,
        1,
        "cam_jpeg_enc_reset_hw",
        295,
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
      "cam_jpeg_enc_reset_hw",
      282,
      "Invalid args");
    return 4294967274LL;
  }
}
