__int64 __fastcall cam_ois_driver_soc_init(_QWORD *a1)
{
  __int64 v1; // x8
  __int64 v3; // x21
  unsigned int v4; // w20
  __int64 v5; // x8
  unsigned int inited; // w0
  const char *v7; // x5
  __int64 v8; // x2
  __int64 v9; // x4
  const char *v10; // x5
  __int64 v11; // x4

  v1 = a1[11];
  if ( !v1 )
  {
    v10 = "soc_info is not initialized";
    v11 = 33;
LABEL_11:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x100000,
      1,
      "cam_ois_driver_soc_init",
      v11,
      v10);
    return (unsigned int)-22;
  }
  if ( !*(_QWORD *)(v1 + 744) )
  {
    v10 = "dev.of_node NULL";
    v11 = 39;
    goto LABEL_11;
  }
  v3 = a1[422];
  v4 = ((__int64 (__fastcall *)(_QWORD *, _QWORD *))cam_sensor_util_parse_and_request_resources)(a1 + 457, a1 + 10);
  if ( (v4 & 0x80000000) == 0 )
  {
    v5 = a1[411];
    if ( v5 )
    {
      if ( *(_BYTE *)(v5 + 8) )
      {
        inited = cam_sensor_util_init_gpio_pin_tbl(a1 + 10, v3 + 56);
        if ( (inited & 0x80000000) == 0 )
        {
          v4 = inited;
          if ( *(_QWORD *)(v3 + 56) )
            goto LABEL_16;
        }
        v7 = "No/Error OIS GPIOs";
        v8 = 1;
        v9 = 64;
      }
      else
      {
        v7 = "No GPIO found";
        v8 = 3;
        v9 = 56;
      }
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        0x100000,
        v8,
        "cam_ois_driver_soc_init",
        v9,
        v7);
      cam_sensor_util_release_resources(a1 + 457, a1 + 10);
      v4 = -22;
    }
    else
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        0x100000,
        3,
        "cam_ois_driver_soc_init",
        51,
        "No GPIO found");
    }
LABEL_16:
    *(_QWORD *)((char *)a1 + 4566) = 0;
    *(_QWORD *)((char *)a1 + 4574) = 0;
    a1[540] = a1 + 540;
    a1[541] = a1 + 540;
    a1[546] = a1 + 546;
    a1[547] = a1 + 546;
    a1[534] = a1 + 534;
    a1[535] = a1 + 534;
    a1[575] = a1 + 575;
    a1[576] = a1 + 575;
    a1[552] = a1 + 552;
    a1[553] = a1 + 552;
    a1[558] = a1 + 558;
    a1[559] = a1 + 558;
    a1[583] = a1 + 583;
    a1[584] = a1 + 583;
    _mutex_init(a1 + 585, "&(o_ctrl->read_buf_lock)", &cam_ois_driver_soc_init___key);
    return v4;
  }
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    0x10000,
    1,
    "cam_ois_driver_soc_init",
    46,
    "Failed in parse_and_request_resources rc : %d",
    v4);
  return v4;
}
