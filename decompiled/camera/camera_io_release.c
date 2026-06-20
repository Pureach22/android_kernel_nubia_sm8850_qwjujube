__int64 __fastcall camera_io_release(__int64 a1)
{
  int v1; // w6
  _BYTE *v2; // x9
  __int64 v3; // x8
  __int64 v5; // x9
  __int64 v6; // x8
  __int64 v7; // x19
  int v8; // w0
  const char **v9; // x8
  const char *v10; // x7

  if ( !a1 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x4000000000LL,
      1,
      "camera_io_release",
      298,
      "Invalid Args");
    return 4294967274LL;
  }
  v1 = *(_DWORD *)a1;
  if ( *(int *)a1 <= 2 )
  {
    if ( v1 == 1 )
      return cam_sensor_cci_i2c_util(*(_QWORD *)(a1 + 16), 1);
    if ( v1 == 2 )
    {
      v2 = *(_BYTE **)(a1 + 8);
      if ( v2 )
      {
        if ( *(_QWORD *)v2 )
        {
          v3 = *(_QWORD *)(*(_QWORD *)v2 + 24LL);
          if ( v3 )
          {
            if ( v2[16] == 1 )
            {
              if ( (debug_mdl & 0x4000000000LL) != 0 && !debug_priority )
              {
                ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                  3,
                  debug_mdl & 0x4000000000LL,
                  4,
                  "camera_io_release",
                  327,
                  "%s:%d: %s: I2C_MASTER: Calling put_sync",
                  "camera_io_release",
                  327,
                  (const char *)(a1 + 32));
                v3 = *(_QWORD *)(**(_QWORD **)(a1 + 8) + 24LL);
              }
              _pm_runtime_idle(*(_QWORD *)(v3 + 208), 4);
              return 0;
            }
          }
        }
      }
      return 0;
    }
LABEL_22:
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x4000000000LL,
      1,
      "camera_io_release",
      334,
      "Invalid Master Type:%d",
      v1);
    return 4294967274LL;
  }
  if ( v1 == 3 )
    return 0;
  if ( v1 != 4 )
    goto LABEL_22;
  v5 = *(_QWORD *)(a1 + 8);
  if ( !v5 )
    return 0;
  v6 = *(_QWORD *)(v5 + 8);
  if ( !v6 || *(_BYTE *)(v5 + 16) != 1 )
    return 0;
  if ( (debug_mdl & 0x4000000000LL) != 0 )
  {
    v7 = a1;
    if ( !debug_priority )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x4000000000LL,
        4,
        "camera_io_release",
        310,
        "%s:%d: %s: I3C_MASTER: Calling put_sync",
        "camera_io_release",
        310,
        (const char *)(a1 + 32));
      v6 = *(_QWORD *)(*(_QWORD *)(v7 + 8) + 8LL);
    }
  }
  else
  {
    v7 = a1;
  }
  v8 = _pm_runtime_idle(*(_QWORD *)(v6 + 96), 4);
  if ( (v8 & 0x80000000) == 0 )
    return 0;
  v9 = *(const char ***)(*(_QWORD *)(*(_QWORD *)(v7 + 8) + 8LL) + 96LL);
  v10 = v9[14];
  if ( !v10 )
    v10 = *v9;
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    0x4000000000LL,
    2,
    "camera_io_release",
    317,
    "Failed to I3C PUT_SYNC rc: %d parent: %s",
    v8,
    v10);
  return 0;
}
