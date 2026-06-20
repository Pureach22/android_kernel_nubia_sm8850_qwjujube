__int64 __fastcall cam_jpeg_enc_start_hw(__int64 a1)
{
  __int64 v1; // x23
  __int64 v3; // x21
  __int64 v4; // x22
  __int64 v5; // x20

  if ( !a1 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      512,
      1,
      "cam_jpeg_enc_start_hw",
      374,
      "Invalid args");
    return 4294967274LL;
  }
  v1 = *(_QWORD *)(a1 + 3680);
  v3 = *(_QWORD *)(a1 + 384);
  v4 = *(_QWORD *)(v1 + 8);
  v5 = raw_spin_lock_irqsave(a1 + 48);
  if ( !*(_DWORD *)(a1 + 92) )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      512,
      1,
      "cam_jpeg_enc_start_hw",
      386,
      "JPEG HW is in off state");
LABEL_11:
    raw_spin_unlock_irqrestore(a1 + 48, v5);
    return 4294967274LL;
  }
  if ( *(_DWORD *)v1 != 1 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      512,
      1,
      "cam_jpeg_enc_start_hw",
      391,
      "Error not ready: %d",
      *(_DWORD *)v1);
    goto LABEL_11;
  }
  raw_spin_unlock_irqrestore(a1 + 48, v5);
  if ( (debug_mdl & 0x200) != 0 && !debug_priority )
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      debug_mdl & 0x200,
      4,
      "cam_jpeg_enc_start_hw",
      397,
      "Starting JPEG ENC");
  cam_io_w_mb(*(unsigned int *)(v4 + 84), v3 + *(unsigned int *)(v4 + 16));
  return 0;
}
