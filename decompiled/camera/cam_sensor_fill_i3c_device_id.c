__int64 __fastcall cam_sensor_fill_i3c_device_id(__int64 a1, int a2, __int64 a3, __int64 a4)
{
  __int64 v7; // x25
  __int64 v8; // x8
  __int16 v9; // w8
  __int16 v10; // w9
  __int64 v11; // x22
  int v12; // w24
  unsigned int v13; // w0
  unsigned int v14; // w24
  unsigned int v15; // w0
  const char *v16; // x5
  __int64 v17; // x4
  __int64 result; // x0
  __int64 v19; // x6
  const char *v20; // x5
  unsigned int v21; // w19
  __int64 v22; // x4
  int v23; // [xsp+10h] [xbp-10h] BYREF
  int v24; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v25; // [xsp+18h] [xbp-8h]

  v25 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v24 = 0;
  v23 = 0;
  if ( !a1 )
  {
    v16 = "dev ptr is null";
    v17 = 66;
LABEL_16:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x800000000LL,
      1,
      "cam_sensor_fill_i3c_device_id",
      v17,
      v16);
    result = 4294967274LL;
    goto LABEL_17;
  }
  if ( !a3 )
  {
    v16 = "sensor_id_table_str ptr is null";
    v17 = 71;
    goto LABEL_16;
  }
  if ( !a4 )
  {
    v16 = "sensor_i3c_device_id ptr is null";
    v17 = 76;
    goto LABEL_16;
  }
  if ( a2 < 1 )
  {
LABEL_18:
    result = 0;
  }
  else
  {
    v7 = a4 + 4;
    v8 = -66;
    while ( 1 )
    {
      v11 = v8 + 2;
      if ( v8 == -2 )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          0x800000000LL,
          2,
          "cam_sensor_fill_i3c_device_id",
          84,
          "Num_entries are more than MAX_I3C_DEVICE_ID_ENTRIES for dev: %s",
          *(const char **)(a1 + 16));
        result = 4294967284LL;
        goto LABEL_17;
      }
      v12 = v8 + 66;
      v13 = of_property_read_u32_index(a1, a3, (unsigned int)(v8 + 66), &v24);
      if ( v13 )
      {
        v19 = *(_QWORD *)(a1 + 16);
        v20 = "Failed in reading the MID. dev: %s rc: %d";
        v21 = v13;
        v22 = 91;
        goto LABEL_22;
      }
      v14 = v12 + 1;
      v15 = of_property_read_u32_index(a1, a3, v14, &v23);
      if ( v15 )
        break;
      if ( (debug_mdl & 0x800000000LL) != 0 && !debug_priority )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 0x800000000LL,
          4,
          "cam_sensor_fill_i3c_device_id",
          104,
          "dev: %s PID: 0x%x, MID: 0x%x",
          *(const char **)(a1 + 16),
          v23,
          v24);
      v9 = v24;
      v10 = v23;
      *(_BYTE *)(v7 - 4) = 6;
      *(_WORD *)(v7 - 2) = v9;
      *(_WORD *)v7 = v10;
      *(_QWORD *)(v7 + 4) = 0;
      v7 += 16;
      v8 = v11;
      if ( (int)(v14 + 1) >= a2 )
        goto LABEL_18;
    }
    v19 = *(_QWORD *)(a1 + 16);
    v20 = "Failed in reading the PID. dev: %s rc: %d";
    v21 = v15;
    v22 = 99;
LABEL_22:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, _QWORD))cam_print_log)(
      3,
      0x800000000LL,
      1,
      "cam_sensor_fill_i3c_device_id",
      v22,
      v20,
      v19,
      v21);
    result = v21;
  }
LABEL_17:
  _ReadStatusReg(SP_EL0);
  return result;
}
