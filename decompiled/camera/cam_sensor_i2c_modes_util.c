__int64 __fastcall cam_sensor_i2c_modes_util(__int64 a1, __int64 a2)
{
  int v2; // w8
  __int64 result; // x0
  const char *v6; // x5
  unsigned int v7; // w19
  __int64 v8; // x4
  __int64 v9; // x8
  __int64 v10; // x21
  __int64 v11; // x22

  v2 = *(_DWORD *)(a2 + 64);
  result = 0;
  if ( v2 > 1 )
  {
    if ( v2 == 2 )
    {
      result = camera_io_dev_write_continuous(a1, a2, 2);
      if ( (result & 0x80000000) == 0 )
        return result;
      v6 = "Failed to seq write I2C settings: %d";
      v7 = result;
      v8 = 804;
    }
    else
    {
      if ( v2 != 5 )
        return result;
      v9 = *(unsigned int *)(a2 + 8);
      if ( !(_DWORD)v9 )
        return 0;
      v10 = 16 * v9;
      v11 = 0;
      while ( 1 )
      {
        result = camera_io_dev_poll(
                   a1,
                   *(unsigned int *)(*(_QWORD *)a2 + v11),
                   *(unsigned int *)(*(_QWORD *)a2 + v11 + 4),
                   *(unsigned int *)(*(_QWORD *)a2 + v11 + 12),
                   *(unsigned int *)(a2 + 12),
                   *(unsigned int *)(a2 + 16),
                   *(unsigned int *)(*(_QWORD *)a2 + v11 + 8));
        if ( (result & 0x80000000) != 0 )
          break;
        v11 += 16;
        if ( v10 == v11 )
          return result;
      }
      v6 = "i2c poll apply setting Fail: %d";
      v7 = result;
      v8 = 831;
    }
    goto LABEL_19;
  }
  if ( !v2 )
  {
    result = camera_io_dev_write(a1, a2);
    if ( (result & 0x80000000) == 0 )
      return result;
    v6 = "Failed to random write I2C settings: %d";
    v7 = result;
    v8 = 793;
    goto LABEL_19;
  }
  if ( v2 == 1 )
  {
    result = camera_io_dev_write_continuous(a1, a2, 1);
    if ( (result & 0x80000000) != 0 )
    {
      v6 = "Failed to burst write I2C settings: %d";
      v7 = result;
      v8 = 815;
LABEL_19:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
        3,
        32,
        1,
        "cam_sensor_i2c_modes_util",
        v8,
        v6,
        v7);
      return v7;
    }
  }
  return result;
}
