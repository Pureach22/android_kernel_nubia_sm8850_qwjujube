__int64 __fastcall cam_sensor_flush_request(__int64 a1)
{
  __int64 device_priv; // x0
  __int64 v3; // x19
  int v4; // w8
  char v5; // w8
  int v6; // w8
  __int64 v7; // x24
  unsigned int v8; // w21
  int v9; // w9
  __int64 v10; // x25
  __int64 v11; // x0
  const char *v12; // x5
  __int64 v13; // x4
  int v14; // w24
  __int64 v15; // x25
  int v16; // w9
  __int64 v17; // x26
  __int64 v18; // x0
  __int64 v19; // x25
  int v20; // w9
  __int64 v21; // x26
  __int64 v22; // x0

  if ( !a1 )
    return (unsigned int)-22;
  device_priv = cam_get_device_priv(*(_DWORD *)(a1 + 4));
  if ( !device_priv )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      32,
      1,
      "cam_sensor_flush_request",
      2438,
      "Device data is NULL");
    return (unsigned int)-22;
  }
  v3 = device_priv;
  mutex_lock(device_priv + 3608);
  if ( (unsigned int)(*(_DWORD *)(v3 + 6544) - 3) >= 2 )
  {
    mutex_unlock(v3 + 3608);
    return 0;
  }
  if ( !*(_QWORD *)(v3 + 7296) )
  {
    v12 = "i2c frame data is NULL";
    v13 = 2450;
LABEL_32:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      32,
      1,
      "cam_sensor_flush_request",
      v13,
      v12);
    mutex_unlock(v3 + 3608);
    return (unsigned int)-22;
  }
  if ( !*(_QWORD *)(v3 + 7288) )
  {
    v12 = "i2c frame data is NULL";
    v13 = 2456;
    goto LABEL_32;
  }
  if ( !*(_QWORD *)(v3 + 7304) )
  {
    v12 = "i2c not ready data is NULL";
    v13 = 2462;
    goto LABEL_32;
  }
  v4 = *(_DWORD *)(a1 + 8);
  if ( !v4 )
  {
    v5 = debug_mdl;
    *(_DWORD *)(v3 + 7552) = *(_QWORD *)(a1 + 16);
    if ( (v5 & 0x20) != 0 && !debug_priority )
    {
      ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        v5 & 0x20,
        4,
        "cam_sensor_flush_request",
        2470,
        "last reqest to flush is %lld",
        *(_QWORD *)(a1 + 16));
      if ( (*(_BYTE *)(v3 + 7621) & 1) != 0 )
        goto LABEL_12;
    }
    else if ( (*(_BYTE *)(v3 + 7621) & 1) != 0 )
    {
      goto LABEL_12;
    }
    v6 = *(unsigned __int8 *)(a1 + 24);
    if ( v6 != 1 )
    {
LABEL_14:
      *(_BYTE *)(v3 + 7622) = v6;
      v4 = *(_DWORD *)(a1 + 8);
      goto LABEL_15;
    }
LABEL_12:
    cam_sensor_stream_off(v3);
    *(_BYTE *)(v3 + 7620) = 0;
    v6 = *(unsigned __int8 *)(a1 + 24);
    if ( v6 == 1 )
    {
      *(_DWORD *)(v3 + 6544) = 2;
      *(_BYTE *)(v3 + 7622) = 1;
      LOBYTE(v6) = *(_BYTE *)(a1 + 24);
    }
    goto LABEL_14;
  }
LABEL_15:
  v7 = 0;
  v8 = 0;
  v9 = v4;
  while ( 1 )
  {
    v10 = *(_QWORD *)(v3 + 7296);
    v11 = v10 + v7;
    if ( v9 != 1 || *(_QWORD *)(v11 + 24) == *(_QWORD *)(a1 + 16) )
      break;
    v9 = 1;
LABEL_18:
    v7 += 48;
    if ( v7 == 1536 )
    {
      v14 = 0;
      goto LABEL_34;
    }
  }
  if ( *(_DWORD *)(v11 + 16) != 1 )
    goto LABEL_18;
  v8 = delete_request(v11);
  if ( (v8 & 0x80000000) != 0 )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      32,
      1,
      "cam_sensor_flush_request",
      2496,
      "delete request for no valid deferred req: %lld rc: %d",
      *(_QWORD *)(v10 + v7 + 24),
      v8);
  v4 = *(_DWORD *)(a1 + 8);
  if ( v4 != 1 )
  {
    v9 = *(_DWORD *)(a1 + 8);
    goto LABEL_18;
  }
  v14 = 1;
LABEL_34:
  v15 = 0;
  v16 = v4;
  while ( 2 )
  {
    v17 = *(_QWORD *)(v3 + 7288);
    v18 = v17 + v15;
    if ( v16 == 1 && *(_QWORD *)(v18 + 24) != *(_QWORD *)(a1 + 16) )
    {
      v16 = 1;
      goto LABEL_36;
    }
    if ( *(_DWORD *)(v18 + 16) != 1 )
    {
LABEL_36:
      v15 += 48;
      if ( v15 == 1536 )
        goto LABEL_45;
      continue;
    }
    break;
  }
  v8 = delete_request(v18);
  if ( (v8 & 0x80000000) != 0 )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      32,
      1,
      "cam_sensor_flush_request",
      2518,
      "delete request: %lld rc: %d",
      *(_QWORD *)(v17 + v15 + 24),
      v8);
  v4 = *(_DWORD *)(a1 + 8);
  if ( v4 != 1 )
  {
    v16 = *(_DWORD *)(a1 + 8);
    goto LABEL_36;
  }
  v14 = 1;
LABEL_45:
  v19 = 0;
  v20 = v4;
  do
  {
    v21 = *(_QWORD *)(v3 + 7304);
    v22 = v21 + v19;
    if ( v20 == 1 && *(_QWORD *)(v22 + 24) != *(_QWORD *)(a1 + 16) )
    {
      v20 = 1;
    }
    else if ( *(_DWORD *)(v22 + 16) == 1 )
    {
      v8 = delete_request(v22);
      if ( (v8 & 0x80000000) != 0 )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          32,
          1,
          "cam_sensor_flush_request",
          2540,
          "delete request for not ready packet: %lld rc: %d",
          *(_QWORD *)(v21 + v19 + 24),
          v8);
      v4 = *(_DWORD *)(a1 + 8);
      v20 = v4;
      if ( v4 == 1 )
        goto LABEL_59;
    }
    v19 += 48;
  }
  while ( v19 != 1536 );
  if ( !v14 && v4 == 1 && (debug_mdl & 0x20) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x20,
      4,
      "cam_sensor_flush_request",
      2554,
      "Flush request id:%lld not found in the pending list",
      *(_QWORD *)(a1 + 16));
LABEL_59:
  mutex_unlock(v3 + 3608);
  return v8;
}
