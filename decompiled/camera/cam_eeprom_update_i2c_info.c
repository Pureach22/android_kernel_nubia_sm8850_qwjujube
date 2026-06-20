__int64 __fastcall cam_eeprom_update_i2c_info(__int64 a1, unsigned __int16 *a2)
{
  int v2; // w8
  __int64 v3; // x8
  unsigned int v4; // w9
  __int64 result; // x0
  __int64 v6; // x8
  int v7; // w6
  const char *v8; // x5
  __int64 v9; // x4

  v2 = *(_DWORD *)(a1 + 3664);
  if ( v2 == 3 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x10000,
      1,
      "cam_eeprom_update_i2c_info",
      113,
      "Slave addr: 0x%x Freq Mode: %d",
      *a2,
      *((unsigned __int8 *)a2 + 2));
    return 0;
  }
  if ( v2 != 2 )
  {
    if ( v2 == 1 )
    {
      v3 = *(_QWORD *)(a1 + 3680);
      if ( v3 )
      {
        v4 = *a2;
        *(_DWORD *)(v3 + 28) = 3;
        *(_WORD *)(v3 + 20) = v4 >> 1;
        *(_DWORD *)(v3 + 12) = *((unsigned __int8 *)a2 + 2);
        return 0;
      }
      v8 = "failed: cci_client %pK";
      v9 = 95;
      goto LABEL_14;
    }
    return 0;
  }
  v6 = *(_QWORD *)(a1 + 3672);
  if ( !v6 )
  {
    v8 = "failed: qup_client %pK";
    v9 = 105;
LABEL_14:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
      3,
      0x10000,
      1,
      "cam_eeprom_update_i2c_info",
      v9,
      v8,
      0);
    return 4294967274LL;
  }
  v7 = *a2;
  result = 0;
  *(_WORD *)(*(_QWORD *)v6 + 2LL) = v7;
  if ( (debug_mdl & 0x10000) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x10000,
      4,
      "cam_eeprom_update_i2c_info",
      110,
      "Slave addr: 0x%x",
      v7);
    return 0;
  }
  return result;
}
