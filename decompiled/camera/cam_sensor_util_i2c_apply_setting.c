__int64 __fastcall cam_sensor_util_i2c_apply_setting(
        int *a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6)
{
  __int64 v6; // x6
  __int64 result; // x0
  const char *v10; // x5
  unsigned int v11; // w19
  __int64 v12; // x4
  __int64 v13; // x8
  __int64 v14; // x21
  __int64 v15; // x22

  v6 = *(unsigned int *)(a2 + 64);
  if ( (int)v6 <= 1 )
  {
    if ( !(_DWORD)v6 )
    {
      result = camera_io_dev_write(a1, (_QWORD *)a2, a3, a4, a5, a6, v6);
      if ( (result & 0x80000000) == 0 )
        return result;
      v10 = "Failed to random write I2C settings: %d";
      v11 = result;
      v12 = 972;
      goto LABEL_20;
    }
    if ( (_DWORD)v6 == 1 )
    {
      result = camera_io_dev_write_continuous(a1, (_QWORD *)a2, 1, a4, a5, a6, v6);
      if ( (result & 0x80000000) == 0 )
        return result;
      v10 = "Failed to burst write I2C settings: %d";
      v11 = result;
      v12 = 994;
      goto LABEL_20;
    }
LABEL_13:
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x800000000LL,
      1,
      "cam_sensor_util_i2c_apply_setting",
      1019,
      "Wrong Opcode: %d",
      v6);
    return 4294967274LL;
  }
  if ( (_DWORD)v6 == 2 )
  {
    result = camera_io_dev_write_continuous(a1, (_QWORD *)a2, 2, a4, a5, a6, v6);
    if ( (result & 0x80000000) == 0 )
      return result;
    v10 = "Failed to seq write I2C settings: %d";
    v11 = result;
    v12 = 983;
    goto LABEL_20;
  }
  if ( (_DWORD)v6 != 5 )
    goto LABEL_13;
  v13 = *(unsigned int *)(a2 + 8);
  if ( !(_DWORD)v13 )
    return 0;
  v14 = 16 * v13;
  v15 = 0;
  while ( 1 )
  {
    result = camera_io_dev_poll(
               a1,
               *(unsigned int *)(*(_QWORD *)a2 + v15),
               *(unsigned int *)(*(_QWORD *)a2 + v15 + 4),
               *(_DWORD *)(*(_QWORD *)a2 + v15 + 12),
               *(_DWORD *)(a2 + 12),
               *(_DWORD *)(a2 + 16));
    if ( (result & 0x80000000) != 0 )
      break;
    v15 += 16;
    if ( v14 == v15 )
      return result;
  }
  v10 = "i2c poll apply setting Fail: %d";
  v11 = result;
  v12 = 1012;
LABEL_20:
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
    3,
    0x800000000LL,
    1,
    "cam_sensor_util_i2c_apply_setting",
    v12,
    v10,
    v11);
  return v11;
}
