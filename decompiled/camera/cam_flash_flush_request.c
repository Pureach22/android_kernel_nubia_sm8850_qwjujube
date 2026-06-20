__int64 __fastcall cam_flash_flush_request(__int64 a1)
{
  __int64 device_priv; // x0
  __int64 v3; // x19
  int v4; // w8
  __int16 v5; // w8
  _DWORD *v6; // x8
  unsigned int v7; // w20
  const char *v8; // x5
  __int64 v9; // x4
  __int64 (__fastcall *v10)(__int64, __int64, __int64); // x8
  __int64 v11; // x2

  device_priv = cam_get_device_priv(*(_DWORD *)(a1 + 4));
  if ( device_priv )
  {
    v3 = device_priv;
    mutex_lock(device_priv + 6152);
    if ( *(_DWORD *)(v3 + 6200) )
    {
      v4 = *(_DWORD *)(a1 + 8);
      if ( v4 == 1 )
      {
        v10 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(v3 + 6232);
        v11 = *(_QWORD *)(a1 + 16);
        if ( *((_DWORD *)v10 - 1) != 1074490795 )
          __break(0x8228u);
        v7 = v10(v3, 1, v11);
        if ( !v7 )
          goto LABEL_19;
        v8 = "FLUSH_REQ failed rc: %d";
        v9 = 375;
LABEL_18:
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
          3,
          4096,
          1,
          "cam_flash_flush_request",
          v9,
          v8,
          v7);
        goto LABEL_19;
      }
      if ( !v4 )
      {
        v5 = debug_mdl;
        *(_DWORD *)(v3 + 6712) = *(_QWORD *)(a1 + 16);
        if ( (v5 & 0x1000) != 0 && !debug_priority )
          ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            v5 & 0x1000,
            4,
            "cam_flash_flush_request",
            365,
            "last reqest to flush is %lld",
            *(_QWORD *)(a1 + 16));
        v6 = *(_DWORD **)(v3 + 6232);
        if ( *(v6 - 1) != 1074490795 )
          __break(0x8228u);
        v7 = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD))v6)(v3, 0, 0);
        if ( !v7 )
          goto LABEL_19;
        v8 = "FLUSH_TYPE_ALL failed rc: %d";
        v9 = 368;
        goto LABEL_18;
      }
    }
    v7 = 0;
LABEL_19:
    mutex_unlock(v3 + 6152);
    return v7;
  }
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
    3,
    4096,
    1,
    "cam_flash_flush_request",
    354,
    "Device data is NULL");
  return (unsigned int)-22;
}
