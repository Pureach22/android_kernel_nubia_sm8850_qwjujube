bool __fastcall cam_cdm_write_hw_reg(__int64 a1, unsigned int a2, unsigned int a3)
{
  char *v3; // x21
  __int64 v4; // x22
  char *v6; // x20
  char *v7; // x22
  __int64 v8; // x0
  unsigned int v10; // w20

  v3 = *(char **)(a1 + 384);
  v4 = *(_QWORD *)(a1 + 400);
  if ( (debug_mdl & 1) != 0 && !debug_priority )
  {
    v10 = a3;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      1,
      4,
      "cam_cdm_write_hw_reg",
      65,
      "E: b=%pK off=%x val=%x",
      v3,
      a2,
      a3);
    a3 = v10;
  }
  v6 = &v3[a2];
  v7 = &v3[v4];
  if ( v6 <= v7 )
  {
    cam_io_w_mb(a3, &v3[a2]);
  }
  else
  {
    if ( (unsigned int)__ratelimit(&cam_cdm_write_hw_reg__rs, "cam_cdm_write_hw_reg") )
      v8 = 3;
    else
      v8 = 2;
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
      v8,
      1,
      1,
      "cam_cdm_write_hw_reg",
      71,
      "Accessing invalid region:%d\n",
      a2);
  }
  return v6 > v7;
}
