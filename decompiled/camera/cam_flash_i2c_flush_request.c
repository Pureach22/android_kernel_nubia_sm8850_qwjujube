__int64 __fastcall cam_flash_i2c_flush_request(__int64 a1, int a2, __int64 a3)
{
  unsigned int v6; // w0
  __int64 v7; // x6
  const char *v8; // x5
  __int64 v9; // x4
  unsigned int v10; // w19
  __int64 v11; // x25
  __int64 v12; // x26
  __int64 v13; // x0
  unsigned int v14; // w0

  if ( a1 )
  {
    if ( a2 == 1 && !a3 )
    {
      if ( *(_DWORD *)(a1 + 6360) == 1 && (v6 = delete_request(a1 + 6344)) != 0 )
      {
        v7 = v6;
        v8 = "Failed to delete Init i2c_setting: %d";
        v9 = 102;
      }
      else
      {
        if ( *(_DWORD *)(a1 + 6408) != 1 )
          return 0;
        v14 = delete_request(a1 + 6392);
        if ( !v14 )
          return 0;
        v7 = v14;
        v8 = "Failed to delete NRT i2c_setting: %d";
        v9 = 111;
      }
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
        3,
        4096,
        2,
        "cam_flash_i2c_flush_nrt",
        v9,
        v8,
        v7);
      return 0;
    }
    v11 = 0;
    v10 = 0;
    while ( 1 )
    {
      v12 = *(_QWORD *)(a1 + 6584);
      v13 = v12 + v11;
      if ( (a2 != 1 || *(_QWORD *)(v13 + 24) == a3) && *(_DWORD *)(v13 + 16) == 1 )
      {
        v10 = delete_request(v13);
        if ( (v10 & 0x80000000) != 0 )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            4096,
            1,
            "cam_flash_i2c_flush_request",
            328,
            "delete request: %lld rc: %d",
            *(_QWORD *)(v12 + v11 + 24),
            v10);
        if ( a2 == 1 )
          break;
      }
      v11 += 48;
      if ( v11 == 1536 )
      {
        if ( a2 == 1 && a3 && (debug_mdl & 0x1000) != 0 && !debug_priority )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 0x1000,
            4,
            "cam_flash_i2c_flush_request",
            342,
            "Flush request id:%lld not found in the pending list",
            a3);
        return v10;
      }
    }
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      4096,
      1,
      "cam_flash_i2c_flush_request",
      306,
      "Device data is NULL");
    return (unsigned int)-22;
  }
  return v10;
}
