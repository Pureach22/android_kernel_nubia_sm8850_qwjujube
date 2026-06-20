__int64 __fastcall cam_sensor_get_io_buffer(int *a1, __int64 a2)
{
  int v2; // w6
  __int64 result; // x0
  size_t v6; // x6
  int v7; // w7
  unsigned int v8; // [xsp+14h] [xbp-1Ch]
  size_t v9; // [xsp+18h] [xbp-18h] BYREF
  const void *v10[2]; // [xsp+20h] [xbp-10h] BYREF

  v10[1] = *(const void **)(_ReadStatusReg(SP_EL0) + 1808);
  v10[0] = nullptr;
  v9 = 0;
  if ( !a1 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x800000000LL,
      1,
      "cam_sensor_get_io_buffer",
      378,
      "Invalid args, io buf or i2c settings is NULL");
LABEL_14:
    result = 4294967274LL;
    goto LABEL_15;
  }
  v2 = a1[56];
  if ( v2 != 2 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x800000000LL,
      1,
      "cam_sensor_get_io_buffer",
      407,
      "Invalid direction: %d",
      v2);
    goto LABEL_14;
  }
  result = cam_mem_get_cpu_buf(*a1, v10, &v9);
  if ( (result & 0x80000000) != 0 || !v10[0] )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x800000000LL,
      1,
      "cam_sensor_get_io_buffer",
      388,
      "invalid buffer, rc: %d, buf_addr: %pK",
      result,
      v10[0]);
    goto LABEL_14;
  }
  if ( (debug_mdl & 0x800000000LL) != 0 && !debug_priority )
  {
    v8 = result;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x800000000LL,
      4,
      "cam_sensor_get_io_buffer",
      393,
      "buf_addr: %pK, buf_size: %zu, offsetsize: %d",
      v10[0],
      v9,
      a1[3]);
    result = v8;
  }
  v6 = (unsigned int)a1[3];
  v7 = v9;
  if ( v9 <= v6 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x800000000LL,
      1,
      "cam_sensor_get_io_buffer",
      397,
      "invalid size:io_cfg->offsets[0]: %d, buf_size: %d",
      v6,
      v9);
    cam_mem_put_cpu_buf(*a1);
    goto LABEL_14;
  }
  *(_QWORD *)(a2 + 24) = (char *)v10[0] + v6;
  *(_DWORD *)(a2 + 32) = v7 - a1[3];
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return result;
}
