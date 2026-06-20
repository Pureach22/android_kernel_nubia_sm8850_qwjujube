__int64 __fastcall cam_cci_read_bytes_v_1_2(__int64 a1, __int64 a2)
{
  __int64 v3; // x8
  __int64 v4; // x21
  __int64 v5; // x6
  const char *v6; // x5
  __int64 v7; // x4
  const char *v8; // x5
  __int64 v9; // x4
  __int64 v10; // x19
  unsigned int v11; // w8
  int v13; // w22
  __int64 v14; // x25
  __int16 v15; // w8
  unsigned int v16; // w0
  __int64 v17; // x10
  __int64 v18; // x2
  __int64 v19; // x4
  __int64 v20; // x7
  unsigned int v21; // w19
  __int64 v22; // x23

  if ( !a1 )
  {
    ((void (*)(__int64, const char *, ...))cam_print_log)(
      3,
      print_fmt_cam_context_state,
      (_BYTE *)&_ksymtab_cam_cci_dump_registers + 1,
      "cam_cci_read_bytes_v_1_2",
      2196);
    return (unsigned int)-22;
  }
  v3 = *(_QWORD *)(a2 + 8);
  if ( !v3 )
  {
    v8 = "cci_info NULL";
    v9 = 2200;
LABEL_12:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x4000,
      1,
      "cam_cci_read_bytes_v_1_2",
      v9,
      v8);
    return (unsigned int)-22;
  }
  v4 = *(_QWORD *)(a1 + 240);
  if ( !v4 )
  {
    v8 = "cci_dev NULL";
    v9 = 2205;
    goto LABEL_12;
  }
  if ( *(_DWORD *)(v4 + 3968) )
  {
    v5 = *(unsigned int *)(v4 + 404);
    v6 = "invalid CCI:%d state %d";
    v7 = 2210;
LABEL_6:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
      3,
      0x4000,
      1,
      "cam_cci_read_bytes_v_1_2",
      v7,
      v6,
      v5);
    return (unsigned int)-22;
  }
  v10 = *(unsigned int *)(v3 + 16);
  if ( (unsigned int)v10 >= 2 )
  {
    v8 = "Invalid I2C master addr";
    v9 = 2216;
    goto LABEL_12;
  }
  if ( (unsigned int)*(unsigned __int16 *)(a2 + 40) - 20481 <= 0xFFFFAFFF )
  {
    v5 = *(unsigned int *)(v4 + 404);
    v6 = "CCI%d_I2C_M%d read num bytes 0";
    v7 = 2224;
    goto LABEL_6;
  }
  *(_DWORD *)(v4 + 544LL * (unsigned int)v10 + 4136) = 0;
  v13 = *(unsigned __int16 *)(a2 + 40);
  if ( (debug_mdl & 0x4000) != 0 && !debug_priority )
  {
    v22 = a1;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x4000,
      4,
      "cam_cci_read_bytes_v_1_2",
      2232,
      "CCI%d_I2C_M%d Bytes to read %u",
      *(_DWORD *)(v4 + 404),
      v10,
      v13);
    a1 = v22;
  }
  while ( 1 )
  {
    v14 = a1;
    v15 = (unsigned __int16)v13 <= 0xDu ? v13 : 14;
    *(_WORD *)(a2 + 40) = v15;
    *(_BYTE *)(v4 + 5828 + v10) = 0;
    v16 = cam_cci_read();
    if ( v16 )
      break;
    if ( (unsigned __int16)v13 < 0xEu )
      return 0;
    LOWORD(v13) = v13 - 14;
    v11 = 0;
    a1 = v14;
    v17 = *(_QWORD *)(a2 + 32) + 14LL;
    *(_DWORD *)(a2 + 24) += 14;
    *(_QWORD *)(a2 + 32) = v17;
    if ( !(_WORD)v13 )
      return v11;
  }
  if ( *(_BYTE *)(v4 + 5896) == 1 )
  {
    v18 = 3;
    v19 = 2244;
  }
  else
  {
    v18 = 1;
    v19 = 2247;
  }
  v20 = (unsigned int)v10;
  v21 = v16;
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, __int64, unsigned int))cam_print_log)(
    3,
    0x4000,
    v18,
    "cam_cci_read_bytes_v_1_2",
    v19,
    "CCI%d_I2C_M%d failed to read rc: %d",
    *(unsigned int *)(v4 + 404),
    v20,
    v16);
  return v21;
}
