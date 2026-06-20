__int64 __fastcall cam_actuator_apply_settings(__int64 a1, __int64 a2)
{
  _QWORD *v3; // x28
  const char *v5; // x5
  __int64 v6; // x4
  __int64 v7; // x4
  const char *v8; // x5
  int v9; // w8
  unsigned int v10; // w26
  _QWORD *v11; // x1
  __int64 v12; // x8
  __int64 v13; // x27
  __int64 v14; // x21
  __int16 v15; // w8

  if ( !a1 || !a2 )
  {
    v5 = "Invalid Args";
    v6 = 258;
LABEL_32:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x2000,
      1,
      "cam_actuator_apply_settings",
      v6,
      v5);
    return (unsigned int)-22;
  }
  if ( *(_DWORD *)(a2 + 16) != 1 )
  {
    v5 = " Invalid settings";
    v6 = 263;
    goto LABEL_32;
  }
  v3 = *(_QWORD **)a2;
  if ( *(_QWORD *)a2 != a2 )
  {
    while ( 1 )
    {
      v9 = *((_DWORD *)v3 - 2);
      v10 = 0;
      v11 = v3 - 9;
      if ( v9 <= 1 )
        break;
      if ( v9 == 2 )
      {
        v10 = camera_io_dev_write_continuous(a1 + 32, v11, 2);
        if ( (v10 & 0x80000000) != 0 )
        {
          v7 = 183;
          v8 = "Failed to seq write I2C settings: %d";
          goto LABEL_7;
        }
LABEL_24:
        v15 = debug_mdl;
        if ( (debug_mdl & 0x2000) != 0 )
          goto LABEL_25;
        goto LABEL_8;
      }
      if ( v9 != 5 )
        goto LABEL_24;
      v12 = *((unsigned int *)v3 - 16);
      if ( (_DWORD)v12 )
      {
        v13 = 16 * v12;
        v14 = 0;
        while ( 1 )
        {
          v10 = camera_io_dev_poll(
                  a1 + 32,
                  *(unsigned int *)(*(v3 - 9) + v14),
                  *(unsigned int *)(*(v3 - 9) + v14 + 4),
                  *(unsigned int *)(*(v3 - 9) + v14 + 12),
                  *((unsigned int *)v3 - 15),
                  *((unsigned int *)v3 - 14),
                  *(unsigned int *)(*(v3 - 9) + v14 + 8));
          if ( (v10 & 0x80000000) != 0 )
            break;
          v14 += 16;
          if ( v13 == v14 )
            goto LABEL_24;
        }
        v7 = 210;
        v8 = "i2c poll apply setting Fail: %d";
        goto LABEL_7;
      }
      v10 = 0;
      v15 = debug_mdl;
      if ( (debug_mdl & 0x2000) != 0 )
      {
LABEL_25:
        if ( !debug_priority )
          ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            v15 & 0x2000,
            4,
            "cam_actuator_apply_settings",
            279,
            "Success:request ID: %d",
            *(_QWORD *)(a2 + 24));
      }
LABEL_8:
      v3 = (_QWORD *)*v3;
      if ( v3 == (_QWORD *)a2 )
        return v10;
    }
    if ( v9 )
    {
      if ( v9 == 1 )
      {
        v10 = camera_io_dev_write_continuous(a1 + 32, v11, 1);
        if ( (v10 & 0x80000000) != 0 )
        {
          v7 = 194;
          v8 = "Failed to burst write I2C settings: %d";
LABEL_7:
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
            3,
            0x2000,
            1,
            "cam_actuator_i2c_modes_util",
            v7,
            v8,
            v10);
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            0x2000,
            1,
            "cam_actuator_apply_settings",
            275,
            "Failed to apply settings: %d",
            v10);
          goto LABEL_8;
        }
      }
    }
    else
    {
      v10 = camera_io_dev_write(a1 + 32, v11);
      if ( (v10 & 0x80000000) != 0 )
      {
        v7 = 172;
        v8 = "Failed to random write I2C settings: %d";
        goto LABEL_7;
      }
    }
    goto LABEL_24;
  }
  return 0;
}
