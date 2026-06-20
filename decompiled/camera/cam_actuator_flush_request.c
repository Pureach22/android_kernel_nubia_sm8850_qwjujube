__int64 __fastcall cam_actuator_flush_request(__int64 a1)
{
  __int64 device_priv; // x0
  __int64 v3; // x19
  __int16 v4; // w8
  int v5; // w8
  __int64 v6; // x24
  unsigned int v7; // w21
  int v8; // w9
  __int64 v9; // x25
  __int64 v10; // x0
  const char *v11; // x5
  __int64 v12; // x4

  if ( !a1 )
    return (unsigned int)-22;
  device_priv = cam_get_device_priv(*(_DWORD *)(a1 + 4));
  if ( !device_priv )
  {
    v11 = "Device data is NULL";
    v12 = 1293;
LABEL_24:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x2000,
      1,
      "cam_actuator_flush_request",
      v12,
      v11);
    return (unsigned int)-22;
  }
  v3 = device_priv;
  if ( !*(_QWORD *)(device_priv + 4448) )
  {
    v11 = "i2c frame data is NULL";
    v12 = 1298;
    goto LABEL_24;
  }
  mutex_lock(device_priv + 3672);
  if ( !*(_DWORD *)(a1 + 8) )
  {
    v4 = debug_mdl;
    *(_DWORD *)(v3 + 4664) = *(_QWORD *)(a1 + 16);
    if ( (v4 & 0x2000) != 0 && !debug_priority )
      ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        v4 & 0x2000,
        4,
        "cam_actuator_flush_request",
        1306,
        "last reqest to flush is %lld",
        *(_QWORD *)(a1 + 16));
  }
  v5 = *(_DWORD *)(a1 + 8);
  v6 = 0;
  v7 = 0;
  v8 = v5;
  do
  {
    v9 = *(_QWORD *)(v3 + 4448);
    v10 = v9 + v6;
    if ( v8 == 1 && *(_QWORD *)(v10 + 24) != *(_QWORD *)(a1 + 16) )
    {
      v8 = 1;
    }
    else if ( *(_DWORD *)(v10 + 16) == 1 )
    {
      v7 = delete_request(v10);
      if ( (v7 & 0x80000000) != 0 )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          0x2000,
          1,
          "cam_actuator_flush_request",
          1321,
          "delete request: %lld rc: %d",
          *(_QWORD *)(v9 + v6 + 24),
          v7);
      v5 = *(_DWORD *)(a1 + 8);
      v8 = v5;
      if ( v5 == 1 )
        goto LABEL_22;
    }
    v6 += 48;
  }
  while ( v6 != 1536 );
  if ( v5 == 1 && (debug_mdl & 0x2000) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x2000,
      4,
      "cam_actuator_flush_request",
      1335,
      "Flush request id:%lld not found in the pending list",
      *(_QWORD *)(a1 + 16));
LABEL_22:
  mutex_unlock(v3 + 3672);
  return v7;
}
