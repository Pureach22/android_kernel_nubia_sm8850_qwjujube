__int64 __fastcall cam_jpeg_enc_config_cmanoc_hw_misr(unsigned int *a1, __int64 a2, _DWORD *a3)
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
    v9 = 699;
LABEL_10:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      512,
      1,
      "cam_jpeg_enc_config_cmanoc_hw_misr",
      v9,
      v8);
    return 4294967274LL;
  }
  if ( !a3 )
  {
    v8 = "Invalid command argument";
    v9 = 704;
    goto LABEL_10;
  }
  cam_io_w_mb(a1[24], *(_QWORD *)(a2 + 288) + a1[8]);
  cam_io_w_mb(a1[38], v3 + a1[33]);
  cam_io_w_mb(a1[38], v3 + a1[34]);
  v6 = 40;
  if ( *a3 == 2 )
    v6 = 41;
  cam_io_w_mb(a1[v6], v3 + a1[35]);
  cam_io_w_mb(a1[42], v3 + a1[36]);
  result = 0;
  if ( (debug_mdl & 0x200) != 0 && !debug_priority )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      debug_mdl & 0x200,
      4,
      "cam_jpeg_enc_config_cmanoc_hw_misr",
      740,
      "ENC CAMNOC MISR configured");
    return 0;
  }
  return result;
}
