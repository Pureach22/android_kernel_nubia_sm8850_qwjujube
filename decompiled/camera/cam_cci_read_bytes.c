__int64 __fastcall cam_cci_read_bytes(__int64 a1, __int64 a2)
{
  __int64 v3; // x8
  __int64 v4; // x21
  __int64 v5; // x6
  const char *v6; // x5
  __int64 v7; // x4
  const char *v8; // x5
  __int64 v9; // x4
  __int64 result; // x0
  unsigned int v11; // w23
  unsigned int v12; // w19
  __int64 v14; // x25
  __int64 v15; // x2
  __int64 v16; // x4
  __int64 v17; // x7
  unsigned int v18; // w19

  if ( !a1 )
  {
    ((void (*)(__int64, const char *, ...))cam_print_log)(
      3,
      print_fmt_cam_context_state,
      (_BYTE *)&_ksymtab_cam_cci_dump_registers + 1,
      "cam_cci_read_bytes",
      2275);
    return 4294967274LL;
  }
  v3 = *(_QWORD *)(a2 + 8);
  if ( !v3 )
  {
    v8 = "cci_info NULL";
    v9 = 2279;
LABEL_12:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x4000,
      1,
      "cam_cci_read_bytes",
      v9,
      v8);
    return 4294967274LL;
  }
  v4 = *(_QWORD *)(a1 + 240);
  if ( !v4 )
  {
    v8 = "cci_dev NULL";
    v9 = 2284;
    goto LABEL_12;
  }
  if ( *(_DWORD *)(v4 + 3968) )
  {
    v5 = *(unsigned int *)(v4 + 404);
    v6 = "invalid CCI:%d state %d";
    v7 = 2289;
LABEL_6:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
      3,
      0x4000,
      1,
      "cam_cci_read_bytes",
      v7,
      v6,
      v5);
    return 4294967274LL;
  }
  if ( *(_DWORD *)(v3 + 16) >= 2u )
  {
    v8 = "Invalid I2C master addr";
    v9 = 2295;
    goto LABEL_12;
  }
  *(_BYTE *)(v4 + 5896) = *(_BYTE *)(a2 + 64);
  v11 = *(unsigned __int16 *)(a2 + 40);
  v12 = *(_DWORD *)(*(_QWORD *)(a2 + 8) + 16LL);
  if ( !*(_WORD *)(a2 + 40) || v11 > 0x5000 )
  {
    v5 = *(unsigned int *)(v4 + 404);
    v6 = "CCI%d_I2C_M%d read num bytes 0";
    v7 = 2305;
    goto LABEL_6;
  }
  if ( v12 >= 2 )
  {
    __break(0x5512u);
    return cam_cci_i2c_set_sync_prms(a1);
  }
  else
  {
    v14 = v4 + 544LL * v12;
    mutex_lock(v14 + 4248);
    *(_DWORD *)(v14 + 4136) = 0;
    *(_DWORD *)(v14 + 4168) = 0;
    mutex_unlock(v14 + 4248);
    if ( (debug_mdl & 0x4000) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x4000,
        4,
        "cam_cci_read_bytes",
        2323,
        "CCI%d_I2C_M%d Bytes to read %u",
        *(_DWORD *)(v4 + 404),
        v12,
        v11);
    *(_WORD *)(a2 + 40) = v11;
    if ( v11 < 0x100 )
      result = cam_cci_read(a1, a2);
    else
      result = cam_cci_burst_read(a1, a2);
    if ( (_DWORD)result )
    {
      if ( *(_BYTE *)(v4 + 5896) == 1 )
      {
        v15 = 3;
        v16 = 2338;
      }
      else
      {
        v15 = 1;
        v16 = 2341;
      }
      v17 = v12;
      v18 = result;
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, __int64, _DWORD))cam_print_log)(
        3,
        0x4000,
        v15,
        "cam_cci_read_bytes",
        v16,
        "CCI%d_I2C_M%d Failed to read rc:%d",
        *(unsigned int *)(v4 + 404),
        v17,
        result);
      return v18;
    }
  }
  return result;
}
