__int64 __fastcall cam_eeprom_parse_dt(__int64 a1)
{
  __int64 v1; // x8
  __int64 v2; // x21
  _DWORD *v3; // x20
  int v5; // w0
  __int64 v6; // x22
  __int64 property; // x0
  int variable_u32_array; // w0
  int v9; // w0
  int v10; // w8
  int v11; // w9
  __int64 result; // x0
  unsigned int v13; // w19
  int v14; // w8
  unsigned int dt_power_setting_data; // w0
  int v16; // w0
  int v17; // w0
  unsigned __int8 v18; // w8
  const char *v19; // x5
  __int64 v20; // x4
  unsigned int v21; // w21
  __int64 v22; // x8
  const char *v23; // x5
  __int64 v24; // x2
  __int64 v25; // x4
  int v26; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v27; // [xsp+18h] [xbp-8h]

  v27 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(_QWORD *)(a1 + 96);
  v2 = *(_QWORD *)(a1 + 3384);
  v26 = 0;
  if ( !v1 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x10000,
      1,
      "cam_eeprom_parse_dt",
      249,
      "Dev is NULL");
    result = 4294967274LL;
    goto LABEL_57;
  }
  v3 = (_DWORD *)(a1 + 3664);
  *(_WORD *)(a1 + 4336) = 0;
  v5 = ((__int64 (__fastcall *)(__int64, __int64))cam_sensor_util_parse_and_request_resources)(a1 + 3664, a1 + 88);
  if ( v5 < 0 )
  {
    v13 = v5;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x10000,
      1,
      "cam_eeprom_parse_dt",
      258,
      "Failed in parse_and_request_resources rc : %d",
      v5);
    result = v13;
    goto LABEL_57;
  }
  v6 = *(_QWORD *)(*(_QWORD *)(a1 + 96) + 744LL);
  if ( of_find_property(v6, "multimodule-support", 0) )
  {
    if ( (debug_mdl & 0x20000) != 0 && !debug_priority )
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        debug_mdl & 0x20000,
        4,
        "cam_eeprom_parse_dt",
        265,
        "Multi Module is Supported");
    *(_WORD *)(a1 + 4336) = 1;
  }
  if ( (of_property_read_string(v6, "eeprom-name", v2) & 0x80000000) != 0 )
  {
    if ( (debug_mdl & 0x10000) != 0 && !debug_priority )
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        debug_mdl & 0x10000,
        4,
        "cam_eeprom_parse_dt",
        272,
        "kernel probe is not enabled");
    *(_BYTE *)(a1 + 4296) = 1;
  }
  if ( *v3 == 3 )
  {
    property = of_find_property(v6, "cmm-data-support", 0);
    *(_DWORD *)(v2 + 104) = property != 0;
    if ( property )
    {
      *(_DWORD *)(v2 + 108) = of_find_property(v6, "cmm-data-compressed", 0) != 0;
      variable_u32_array = of_property_read_variable_u32_array(v6, "cmm-data-offset", v2 + 112, 1, 0);
      if ( variable_u32_array < 0 && (debug_mdl & 0x10000) != 0 && !debug_priority )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 0x10000,
          4,
          "cam_eeprom_cmm_dts",
          219,
          "No MM offset data rc %d",
          variable_u32_array & (variable_u32_array >> 31));
      v9 = of_property_read_variable_u32_array(v6, "cmm-data-size", v2 + 116, 1, 0);
      v10 = debug_mdl;
      v11 = debug_priority;
      if ( v9 < 0 && (debug_mdl & 0x10000) != 0 && !debug_priority )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 0x10000,
          4,
          "cam_eeprom_cmm_dts",
          224,
          "No MM size data rc %d",
          v9 & (v9 >> 31));
        v10 = debug_mdl;
        v11 = debug_priority;
        if ( (debug_mdl & 0x10000) == 0 )
          goto LABEL_30;
      }
      else if ( (debug_mdl & 0x10000) == 0 )
      {
        goto LABEL_30;
      }
      if ( !v11 )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          *(_QWORD *)&v10 & 0x10000LL,
          4,
          "cam_eeprom_cmm_dts",
          228,
          "cmm_compr %d, cmm_offset %d, cmm_size %d",
          *(_DWORD *)(v2 + 108),
          *(_DWORD *)(v2 + 112),
          *(_DWORD *)(v2 + 116));
    }
    else if ( (debug_mdl & 0x10000) != 0 && !debug_priority )
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        debug_mdl & 0x10000,
        4,
        "cam_eeprom_cmm_dts",
        209,
        "No cmm support");
    }
  }
LABEL_30:
  v14 = *(unsigned __int8 *)(a1 + 4296);
  if ( (v14 & 1) == 0 )
  {
    dt_power_setting_data = cam_get_dt_power_setting_data(v6, a1 + 88, v2 + 16);
    if ( (dt_power_setting_data & 0x80000000) != 0 )
    {
      v21 = dt_power_setting_data;
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        0x10000,
        1,
        "cam_eeprom_parse_dt",
        286,
        "failed in getting power settings");
LABEL_54:
      cam_sensor_util_release_resources(v3, a1 + 88);
      result = v21;
      goto LABEL_57;
    }
    v14 = *(unsigned __int8 *)(a1 + 4296);
  }
  if ( v14 || *v3 == 3 )
    goto LABEL_47;
  v16 = of_property_read_variable_u32_array(v6, "slave-addr", &v26, 1, 0);
  if ( v16 < 0 && (debug_mdl & 0x10000) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x10000,
      4,
      "cam_eeprom_parse_dt",
      295,
      "failed: no slave-addr rc %d",
      v16 & (v16 >> 31));
  *(_WORD *)(v2 + 8) = v26;
  v17 = of_property_read_variable_u32_array(v6, "i2c-freq-mode", &v26, 1, 0);
  v18 = v26;
  *(_BYTE *)(v2 + 10) = v26;
  if ( v17 < 0 )
  {
    v19 = "i2c-freq-mode read fail %d";
    v20 = 303;
    goto LABEL_44;
  }
  if ( v18 >= 4u )
  {
    v19 = "invalid i2c_freq_mode = %d";
    v20 = 308;
LABEL_44:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x10000,
      1,
      "cam_eeprom_parse_dt",
      v20,
      v19);
    *(_BYTE *)(v2 + 10) = 0;
  }
  if ( (debug_mdl & 0x10000) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x10000,
      4,
      "cam_eeprom_parse_dt",
      312,
      "slave-addr = 0x%X",
      *(unsigned __int16 *)(v2 + 8));
    v22 = *(_QWORD *)(a1 + 3296);
    if ( v22 )
      goto LABEL_48;
LABEL_56:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x10000,
      3,
      "cam_eeprom_parse_dt",
      316,
      "No GPIO found");
    result = 0;
    goto LABEL_57;
  }
LABEL_47:
  v22 = *(_QWORD *)(a1 + 3296);
  if ( !v22 )
    goto LABEL_56;
LABEL_48:
  if ( !*(_BYTE *)(v22 + 8) )
  {
    v23 = "No GPIO found";
    v24 = 3;
    v25 = 321;
    goto LABEL_53;
  }
  result = cam_sensor_util_init_gpio_pin_tbl(a1 + 88, v2 + 56);
  if ( (result & 0x80000000) != 0 || !*(_QWORD *)(v2 + 56) )
  {
    v23 = "No/Error EEPROM GPIOs";
    v24 = 1;
    v25 = 329;
LABEL_53:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x10000,
      v24,
      "cam_eeprom_parse_dt",
      v25,
      v23);
    v21 = -22;
    goto LABEL_54;
  }
LABEL_57:
  _ReadStatusReg(SP_EL0);
  return result;
}
