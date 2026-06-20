__int64 __fastcall cam_eeprom_parse_dt_memory_map(__int64 a1, __int64 a2)
{
  unsigned int variable_u32_array; // w0
  unsigned __int64 v5; // x21
  __int64 v6; // x22
  int v7; // w8
  unsigned int v8; // w23
  __int64 v9; // x24
  unsigned int v10; // w0
  unsigned int v11; // w0
  unsigned int v12; // w0
  unsigned int v13; // w10
  unsigned int v14; // w25
  __int64 v15; // x0
  const char *v16; // x5
  __int64 v17; // x4
  unsigned __int64 StatusReg; // x23
  __int64 v19; // x24
  char s[11]; // [xsp+8h] [xbp-28h] BYREF
  __int64 v22; // [xsp+13h] [xbp-1Dh]
  _BYTE v23[13]; // [xsp+1Bh] [xbp-15h] BYREF
  __int64 v24; // [xsp+28h] [xbp-8h]

  v24 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v23, 0, sizeof(v23));
  v22 = 0;
  strcpy(s, "num-blocks");
  variable_u32_array = of_property_read_variable_u32_array(a1, s, a2 + 8, 1, 0);
  if ( (variable_u32_array & 0x80000000) != 0 )
  {
    v14 = variable_u32_array;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x10000,
      1,
      "cam_eeprom_parse_dt_memory_map",
      128,
      "failed: num-blocks not available rc %d",
      variable_u32_array);
  }
  else
  {
    v5 = 100LL * *(unsigned int *)(a2 + 8);
    v6 = vzalloc_noprof(v5);
    if ( !v6 )
      goto LABEL_27;
    while ( 1 )
    {
      v7 = *(_DWORD *)(a2 + 8);
      *(_QWORD *)a2 = v6;
      if ( !v7 )
        break;
      v8 = 0;
      while ( 1 )
      {
        snprintf(s, 0x20u, "page%d", v8);
        v9 = v6 + 100LL * (int)v8;
        v10 = of_property_read_variable_u32_array(a1, s, v9, 8, 0);
        if ( (v10 & 0x80000000) != 0 )
        {
          v14 = v10;
          v16 = "failed: page not available rc %d";
          v17 = 145;
LABEL_25:
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
            3,
            0x10000,
            1,
            "cam_eeprom_parse_dt_memory_map",
            v17,
            v16,
            v14);
          goto LABEL_29;
        }
        snprintf(s, 0x20u, "pageen%d", v8);
        if ( (of_property_read_variable_u32_array(a1, s, v9 + 24, 8, 0) & 0x80000000) != 0
          && (debug_mdl & 0x10000) != 0
          && !debug_priority )
        {
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
            3,
            debug_mdl & 0x10000,
            4,
            "cam_eeprom_parse_dt_memory_map",
            153,
            "pageen not needed");
        }
        snprintf(s, 0x20u, "saddr%d", v8);
        if ( (of_property_read_variable_u32_array(a1, s, v9 + 96, 1, 0) & 0x80000000) != 0
          && (debug_mdl & 0x10000) != 0
          && !debug_priority )
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 0x10000,
            4,
            "cam_eeprom_parse_dt_memory_map",
            159,
            "saddr not needed - block %d",
            v8);
        }
        snprintf(s, 0x20u, "poll%d", v8);
        v11 = of_property_read_variable_u32_array(a1, s, v9 + 48, 8, 0);
        if ( (v11 & 0x80000000) != 0 )
        {
          v14 = v11;
          v16 = "failed: poll not available rc %d";
          v17 = 166;
          goto LABEL_25;
        }
        snprintf(s, 0x20u, "mem%d", v8);
        v12 = of_property_read_variable_u32_array(a1, s, v9 + 72, 8, 0);
        if ( (v12 & 0x80000000) != 0 )
        {
          v14 = v12;
          v16 = "failed: mem not available rc %d";
          v17 = 175;
          goto LABEL_25;
        }
        if ( v5 <= 100LL * (int)v8 + 72 )
          break;
        ++v8;
        v13 = *(_DWORD *)(a2 + 8);
        *(_DWORD *)(a2 + 24) += *(_DWORD *)(v9 + 72);
        if ( v8 >= v13 )
          goto LABEL_20;
      }
      __break(1u);
      StatusReg = _ReadStatusReg(SP_EL0);
      v19 = *(_QWORD *)(StatusReg + 80);
      *(_QWORD *)(StatusReg + 80) = &cam_eeprom_parse_dt_memory_map__alloc_tag;
      v5 = 100LL * *(unsigned int *)(a2 + 8);
      v6 = vzalloc_noprof(v5);
      *(_QWORD *)(StatusReg + 80) = v19;
      if ( !v6 )
      {
LABEL_27:
        v14 = -12;
        goto LABEL_30;
      }
    }
LABEL_20:
    v15 = vzalloc_noprof(*(unsigned int *)(a2 + 24));
    *(_QWORD *)(a2 + 16) = v15;
    if ( v15 )
    {
      v14 = 0;
    }
    else
    {
      v14 = -12;
LABEL_29:
      vfree(*(_QWORD *)a2);
      *(_QWORD *)(a2 + 16) = 0;
      *(_QWORD *)(a2 + 24) = 0;
      *(_QWORD *)a2 = 0;
      *(_QWORD *)(a2 + 8) = 0;
    }
  }
LABEL_30:
  _ReadStatusReg(SP_EL0);
  return v14;
}
