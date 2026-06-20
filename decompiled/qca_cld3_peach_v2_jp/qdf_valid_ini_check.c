__int64 __fastcall qdf_valid_ini_check(char *s2)
{
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
  __int64 result; // x0
  _BYTE *v11; // x8
  __int64 v12; // x4
  int v13; // w0
  const char *v14; // x21
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  int v23; // w9
  int v24; // w8
  unsigned int v25; // w8
  int v26; // w9
  const char *v27; // x2
  unsigned int v28; // w20
  _BYTE *v29; // [xsp+0h] [xbp-30h] BYREF
  _BYTE *v30; // [xsp+8h] [xbp-28h] BYREF
  _BYTE v31[4]; // [xsp+14h] [xbp-1Ch] BYREF
  _BYTE *v32; // [xsp+18h] [xbp-18h] BYREF
  const char *v33[2]; // [xsp+20h] [xbp-10h] BYREF

  v33[1] = *(const char **)(_ReadStatusReg(SP_EL0) + 1808);
  v30 = nullptr;
  if ( !strcmp("wifi_module_param.ini", s2)
    || (v29 = nullptr, (unsigned int)qdf_file_read(s2, (__int64 *)&v30, nullptr)) )
  {
    qdf_trace_msg(
      0x38u,
      2u,
      "%s: Failed to read *.ini file @ %s",
      v2,
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      "qdf_valid_ini_check",
      s2,
      v29);
    result = 0;
    goto LABEL_40;
  }
  v11 = v30;
  v29 = v30;
  while ( 1 )
  {
    v12 = (unsigned __int8)*v11;
    if ( (unsigned int)v12 <= 0x3D )
    {
      if ( ((1LL << v12) & 0x2400300900002400LL) != 0 )
        goto LABEL_6;
      if ( !*v11 )
        break;
    }
    if ( ((unsigned int)(v12 - 91) > 4 || ((1 << (v12 - 91)) & 0x15) == 0) && (*((_BYTE *)&ctype + v12) & 7) == 0 )
    {
      qdf_trace_msg(
        0x38u,
        2u,
        "%s: Found invalid character %c",
        v2,
        v3,
        v4,
        v5,
        v6,
        v7,
        v8,
        v9,
        "qdf_check_ini_validity",
        v29);
      goto LABEL_36;
    }
LABEL_6:
    ++v11;
  }
  v33[0] = nullptr;
  v32 = nullptr;
  v31[0] = 0;
LABEL_14:
  while ( 1 )
  {
    v13 = qdf_ini_read_values(&v29, v33, (__int64 *)&v32, v31);
    if ( v13 )
      break;
    if ( (v31[0] & 1) == 0 )
    {
      v14 = v33[0];
      if ( !strcmp(v33[0], "END") )
        goto LABEL_35;
      v23 = *(unsigned __int8 *)v14;
      if ( *v14 )
      {
        v24 = 1;
        while ( (v23 & 0xDFu) - 65 < 0x1A || v23 == 95 || (unsigned int)(v23 - 48) <= 9 )
        {
          v23 = (unsigned __int8)v14[v24++];
          if ( !v23 )
            goto LABEL_24;
        }
        v27 = "%s: Invalid INI: %s";
        goto LABEL_33;
      }
LABEL_24:
      v25 = (unsigned __int8)*v32;
      if ( *v32 )
      {
        v26 = 1;
        while ( v25 - 48 < 0xA
             || (v25 & 0xDF) - 65 < 0x1A
             || v25 <= 0x3A && ((1LL << v25) & 0x400384000000000LL) != 0
             || v25 == 124 )
        {
          v25 = (unsigned __int8)v32[v26++];
          if ( !v25 )
            goto LABEL_14;
        }
        v27 = "%s: Invalid INI value: %s";
LABEL_33:
        qdf_trace_msg(0x38u, 2u, v27, v15, v16, v17, v18, v19, v20, v21, v22, "qdf_check_ini_validity", v29);
        goto LABEL_36;
      }
    }
  }
  if ( v13 == 16 )
  {
LABEL_35:
    v28 = 1;
    goto LABEL_37;
  }
LABEL_36:
  v28 = 0;
LABEL_37:
  if ( strcmp("wifi_module_param.ini", s2) )
    qdf_file_buf_free((__int64)v30);
  result = v28;
LABEL_40:
  _ReadStatusReg(SP_EL0);
  return result;
}
