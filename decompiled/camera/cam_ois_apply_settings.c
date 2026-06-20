__int64 __fastcall cam_ois_apply_settings(__int64 a1, __int64 a2)
{
  _QWORD *v3; // x21
  __int64 result; // x0
  const char *v6; // x5
  __int64 v7; // x4
  int v8; // w8
  _QWORD *v9; // x1
  __int64 v10; // x8
  __int64 v11; // x22
  __int64 v12; // x23
  const char *v13; // x5
  unsigned int v14; // w19
  __int64 v15; // x4
  unsigned int v16; // w19

  if ( !a2 )
  {
    v6 = "Invalid Args";
    v7 = 324;
LABEL_20:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x100000,
      1,
      "cam_ois_apply_settings",
      v7,
      v6);
    return 4294967274LL;
  }
  if ( *(_DWORD *)(a2 + 16) != 1 )
  {
    v6 = " Invalid settings";
    v7 = 329;
    goto LABEL_20;
  }
  v3 = *(_QWORD **)a2;
  if ( *(_QWORD *)a2 == a2 )
    return 0;
  result = 0;
  while ( 1 )
  {
    v8 = *((_DWORD *)v3 - 2);
    if ( v8 == 5 )
      break;
    v9 = v3 - 9;
    if ( v8 == 2 )
    {
      result = camera_io_dev_write_continuous(a1 + 3656, v9, 2);
      if ( (result & 0x80000000) != 0 )
      {
        v16 = result;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          0x100000,
          1,
          "cam_ois_apply_settings",
          351,
          "Failed to seq write I2C settings: %d",
          result);
        return v16;
      }
    }
    else if ( !v8 )
    {
      result = camera_io_dev_write(a1 + 3656, v9);
      if ( (result & 0x80000000) != 0 )
      {
        v13 = "Failed in Applying i2c wrt settings";
        v14 = result;
        v15 = 340;
LABEL_24:
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          0x100000,
          1,
          "cam_ois_apply_settings",
          v15,
          v13);
        return v14;
      }
    }
LABEL_7:
    v3 = (_QWORD *)*v3;
    if ( v3 == (_QWORD *)a2 )
      return result;
  }
  v10 = *((unsigned int *)v3 - 16);
  if ( !(_DWORD)v10 )
    goto LABEL_7;
  v11 = 16 * v10;
  v12 = 0;
  while ( 1 )
  {
    result = camera_io_dev_poll(
               a1 + 3656,
               *(unsigned int *)(*(v3 - 9) + v12),
               *(unsigned int *)(*(v3 - 9) + v12 + 4),
               *(unsigned int *)(*(v3 - 9) + v12 + 12),
               *((unsigned int *)v3 - 15),
               *((unsigned int *)v3 - 14),
               *(unsigned int *)(*(v3 - 9) + v12 + 8));
    if ( (result & 0x80000000) != 0 )
    {
      v13 = "i2c poll apply setting Fail";
      v14 = result;
      v15 = 367;
      goto LABEL_24;
    }
    if ( (_DWORD)result == 1 )
      break;
    v12 += 16;
    if ( v11 == v12 )
      goto LABEL_7;
  }
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
    3,
    0x100000,
    1,
    "cam_ois_apply_settings",
    370,
    "i2c poll mismatch");
  return 1;
}
