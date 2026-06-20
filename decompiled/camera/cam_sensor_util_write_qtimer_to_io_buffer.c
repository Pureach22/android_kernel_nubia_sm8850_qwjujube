__int64 __fastcall cam_sensor_util_write_qtimer_to_io_buffer(__int64 a1, int *a2)
{
  int v2; // w6
  int cpu_buf; // w0
  unsigned __int64 v6; // x6
  __int64 result; // x0
  unsigned int v8; // w19
  int v9; // [xsp+14h] [xbp-1Ch]
  size_t v10; // [xsp+18h] [xbp-18h] BYREF
  const void *v11[2]; // [xsp+20h] [xbp-10h] BYREF

  v11[1] = *(const void **)(_ReadStatusReg(SP_EL0) + 1808);
  v11[0] = nullptr;
  v10 = 0;
  if ( a2 )
  {
    v2 = a2[56];
    if ( v2 == 2 )
    {
      cpu_buf = cam_mem_get_cpu_buf(*a2, v11, &v10);
      if ( cpu_buf < 0 || !v11[0] )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          0x800000000LL,
          1,
          "cam_sensor_util_write_qtimer_to_io_buffer",
          433,
          "invalid buffer, rc: %d, buf_addr: %pK",
          cpu_buf,
          v11[0]);
      }
      else
      {
        if ( (debug_mdl & 0x800000000LL) != 0 && !debug_priority )
        {
          v9 = cpu_buf;
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 0x800000000LL,
            4,
            "cam_sensor_util_write_qtimer_to_io_buffer",
            438,
            "buf_addr: %pK, buf_size: %zu, offsetsize: %d",
            v11[0],
            v10,
            a2[3]);
          cpu_buf = v9;
        }
        v6 = (unsigned int)a2[3];
        if ( v10 <= v6 )
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            0x800000000LL,
            1,
            "cam_sensor_util_write_qtimer_to_io_buffer",
            442,
            "invalid size:io_cfg->offsets[0]: %d, buf_size: %d",
            v6,
            v10);
        }
        else
        {
          if ( v10 - v6 > 7 )
          {
            *(_QWORD *)((char *)v11[0] + v6) = a1;
            v8 = cpu_buf;
            cam_mem_put_cpu_buf(*a2);
            result = v8;
            goto LABEL_17;
          }
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            0x800000000LL,
            1,
            "cam_sensor_util_write_qtimer_to_io_buffer",
            453,
            "not enough size for qtimer, target_size:%d",
            v10 - v6);
        }
        cam_mem_put_cpu_buf(*a2);
      }
    }
    else
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x800000000LL,
        1,
        "cam_sensor_util_write_qtimer_to_io_buffer",
        462,
        "Invalid direction: %d",
        v2);
    }
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x800000000LL,
      1,
      "cam_sensor_util_write_qtimer_to_io_buffer",
      423,
      "Invalid args, io buf is NULL");
  }
  result = 4294967274LL;
LABEL_17:
  _ReadStatusReg(SP_EL0);
  return result;
}
