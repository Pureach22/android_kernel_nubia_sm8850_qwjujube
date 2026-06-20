__int64 __fastcall cam_sensor_update_i2c_info(_DWORD *a1, __int64 a2)
{
  int v2; // w8
  __int64 v3; // x8
  unsigned int v4; // w9
  char v5; // w9
  __int64 v6; // x8
  unsigned int v7; // w8
  const char *v8; // x5
  __int64 v9; // x4
  _DWORD *v11; // [xsp+10h] [xbp-10h]
  __int64 v12; // [xsp+18h] [xbp-8h]

  v2 = *(_DWORD *)(a2 + 6480);
  if ( v2 == 2 )
  {
    v6 = *(_QWORD *)(a2 + 6488);
    if ( v6 )
    {
      *(_WORD *)(*(_QWORD *)v6 + 2LL) = *a1;
      if ( (debug_mdl & 0x20) == 0 || debug_priority )
        goto LABEL_10;
      v12 = a2;
      v11 = a1;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x20,
        4,
        "cam_sensor_update_i2c_info",
        870,
        "Slave addr: 0x%x",
        *a1);
LABEL_16:
      a1 = v11;
      a2 = v12;
      goto LABEL_10;
    }
    v8 = "failed: qup_client %pK";
    v9 = 866;
LABEL_13:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
      3,
      32,
      1,
      "cam_sensor_update_i2c_info",
      v9,
      v8,
      0);
    return (unsigned int)-22;
  }
  if ( v2 == 1 )
  {
    v3 = *(_QWORD *)(a2 + 6496);
    if ( v3 )
    {
      v4 = *a1;
      *(_DWORD *)(v3 + 28) = 3;
      *(_WORD *)(v3 + 20) = v4 >> 1;
      v5 = debug_mdl;
      *(_DWORD *)(v3 + 12) = *((unsigned __int8 *)a1 + 4);
      if ( (v5 & 0x20) == 0 || debug_priority )
        goto LABEL_10;
      v12 = a2;
      v11 = a1;
      ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        v5 & 0x20,
        4,
        "cam_sensor_update_i2c_info",
        861,
        "CCI: %d Master: %d slave_addr: 0x%x freq_mode: %d",
        *(unsigned __int16 *)(v3 + 32),
        *(_DWORD *)(v3 + 16),
        *a1,
        *((unsigned __int8 *)a1 + 4));
      goto LABEL_16;
    }
    v8 = "failed: cci_client %pK";
    v9 = 851;
    goto LABEL_13;
  }
LABEL_10:
  v7 = 0;
  **(_DWORD **)(a2 + 3656) = *a1;
  return v7;
}
