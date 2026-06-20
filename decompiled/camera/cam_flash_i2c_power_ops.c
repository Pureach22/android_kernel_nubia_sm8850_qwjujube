__int64 __fastcall cam_flash_i2c_power_ops(__int64 a1, char a2)
{
  int v3; // w8
  unsigned int v4; // w0
  int v5; // w0
  unsigned int v6; // w20
  const char *v7; // x5
  __int64 v8; // x4
  _QWORD *v9; // x0
  _QWORD *v10; // x0

  v3 = *(unsigned __int8 *)(a1 + 6205);
  *(_QWORD *)(a1 + 3608) = *(_QWORD *)(a1 + 32);
  if ( (a2 & 1) != 0 )
  {
    if ( (v3 & 1) == 0 )
    {
      if ( *(_QWORD *)(a1 + 3616)
        || *(_QWORD *)(a1 + 3632)
        || (((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
              3,
              4096,
              3,
              "cam_flash_i2c_power_ops",
              176,
              "Using default power settings"),
            v4 = cam_flash_construct_default_power_setting(a1 + 3608),
            (v4 & 0x80000000) == 0) )
      {
        v5 = cam_sensor_core_power_up(a1 + 3608, a1 + 24, 0);
        if ( v5 )
        {
          v6 = v5;
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            4096,
            1,
            "cam_flash_i2c_power_ops",
            190,
            "power up the core is failed:%d",
            v5);
        }
        else
        {
          v6 = camera_io_init((unsigned int *)(a1 + 6280));
          if ( !v6 )
          {
            *(_BYTE *)(a1 + 6205) = 1;
            return v6;
          }
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            4096,
            1,
            "cam_flash_i2c_power_ops",
            196,
            "cci_init failed: rc: %d",
            v6);
          cam_sensor_util_power_down(a1 + 3608, a1 + 24);
        }
        goto LABEL_16;
      }
      v6 = v4;
      v7 = "Construct default pwr setting failed rc: %d";
      v8 = 182;
LABEL_11:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
        3,
        4096,
        1,
        "cam_flash_i2c_power_ops",
        v8,
        v7,
        v6);
      return v6;
    }
    return 0;
  }
  if ( !v3 )
    return 0;
  v6 = cam_sensor_util_power_down(a1 + 3608, a1 + 24);
  if ( v6 )
  {
    v7 = "power down the core is failed:%d";
    v8 = 206;
    goto LABEL_11;
  }
  camera_io_release(a1 + 6280);
  *(_BYTE *)(a1 + 6205) = 0;
LABEL_16:
  v9 = *(_QWORD **)(a1 + 3616);
  if ( mem_trace_en == 1 )
    cam_mem_trace_free(v9, 0);
  else
    kvfree(v9);
  v10 = *(_QWORD **)(a1 + 3632);
  if ( mem_trace_en == 1 )
    cam_mem_trace_free(v10, 0);
  else
    kvfree(v10);
  *(_QWORD *)(a1 + 3616) = 0;
  *(_QWORD *)(a1 + 3632) = 0;
  *(_WORD *)(a1 + 3624) = 0;
  *(_WORD *)(a1 + 3640) = 0;
  return v6;
}
