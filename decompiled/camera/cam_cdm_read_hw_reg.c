bool __fastcall cam_cdm_read_hw_reg(__int64 a1, unsigned int a2, int *a3)
{
  char *v3; // x22
  __int64 v4; // x23
  char *v7; // x21
  char *v8; // x23
  __int64 v9; // x0
  int v10; // w0

  v3 = *(char **)(a1 + 384);
  v4 = *(_QWORD *)(a1 + 400);
  if ( (debug_mdl & 1) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      1,
      4,
      "cam_cdm_read_hw_reg",
      35,
      "E: b=%pK blen=%d off=%x",
      v3,
      v4,
      a2);
  v7 = &v3[a2];
  v8 = &v3[v4];
  if ( v7 <= v8 )
  {
    v10 = cam_io_r_mb(&v3[a2]);
    *a3 = v10;
    if ( (debug_mdl & 1) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        1,
        4,
        "cam_cdm_read_hw_reg",
        46,
        "X b=%pK off=%x val=%x",
        v3,
        a2,
        v10);
  }
  else
  {
    if ( (unsigned int)__ratelimit(&cam_cdm_read_hw_reg__rs, "cam_cdm_read_hw_reg") )
      v9 = 3;
    else
      v9 = 2;
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
      v9,
      1,
      1,
      "cam_cdm_read_hw_reg",
      40,
      "Invalid mapped region %d",
      a2);
    *a3 = 0;
  }
  return v7 > v8;
}
