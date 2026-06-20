__int64 __fastcall cam_sensor_get_sub_module_index(__int64 a1, __int64 a2)
{
  __int64 property; // x0
  int v5; // w0
  unsigned int v6; // w21
  int v7; // w0
  int v8; // w0
  int v9; // w0
  unsigned int v10; // w0
  const char *v11; // x5
  __int64 v12; // x4
  int v13; // w22
  int v15; // [xsp+0h] [xbp-60h]
  int v16; // [xsp+0h] [xbp-60h]
  int v17; // [xsp+0h] [xbp-60h]
  int v18; // [xsp+4h] [xbp-5Ch] BYREF
  __int64 v19; // [xsp+8h] [xbp-58h] BYREF
  __int64 v20; // [xsp+10h] [xbp-50h]
  __int64 v21; // [xsp+18h] [xbp-48h]
  __int64 v22; // [xsp+20h] [xbp-40h]
  __int64 v23; // [xsp+28h] [xbp-38h]
  __int64 v24; // [xsp+30h] [xbp-30h]
  __int64 v25; // [xsp+38h] [xbp-28h]
  __int64 v26; // [xsp+40h] [xbp-20h]
  __int64 v27; // [xsp+48h] [xbp-18h]
  __int64 v28; // [xsp+50h] [xbp-10h]
  __int64 v29; // [xsp+58h] [xbp-8h]

  v29 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v18 = 0;
  property = of_find_property(a1, "zte-tof-enable", 0);
  tof_enable_0 = property != 0;
  if ( property && !tof_inited )
  {
    if ( (debug_mdl & 0x20) != 0 && !debug_priority )
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        debug_mdl & 0x20,
        4,
        "cam_sensor_get_sub_module_index",
        37,
        "TOF_stmvl53l1_init");
    vi530x_init();
    tof_inited = 1;
  }
  *(_QWORD *)(a2 + 56) = -1;
  *(_QWORD *)(a2 + 64) = -1;
  *(_QWORD *)(a2 + 40) = -1;
  *(_QWORD *)(a2 + 48) = -1;
  v27 = 0;
  v28 = 0;
  v25 = 0;
  v26 = 0;
  v23 = 0;
  v24 = 0;
  v21 = 0;
  v22 = 0;
  v19 = 0;
  v20 = 0;
  if ( !(unsigned int)_of_parse_phandle_with_args(a1, "actuator-src", 0, 0, 0, &v19) && v19 )
  {
    v5 = of_property_read_variable_u32_array(v19, "cell-index", &v18, 1, 0);
    v6 = v5 & (v5 >> 31);
    if ( (debug_mdl & 0x20) != 0 && !debug_priority )
    {
      v15 = v5;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x20,
        4,
        "cam_sensor_get_sub_module_index",
        50,
        "actuator cell index %d, rc %d",
        v18,
        v6);
      if ( (v15 & 0x80000000) == 0 )
        goto LABEL_12;
    }
    else if ( (v5 & 0x80000000) == 0 )
    {
LABEL_12:
      *(_DWORD *)(a2 + 44) = v18;
      goto LABEL_16;
    }
    v11 = "failed %d";
    v12 = 52;
    goto LABEL_54;
  }
  if ( (debug_mdl & 0x20) != 0 && !debug_priority )
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      debug_mdl & 0x20,
      4,
      "cam_sensor_get_sub_module_index",
      47,
      "src_node NULL");
LABEL_16:
  v27 = 0;
  v28 = 0;
  v25 = 0;
  v26 = 0;
  v23 = 0;
  v24 = 0;
  v21 = 0;
  v22 = 0;
  v19 = 0;
  v20 = 0;
  if ( !(unsigned int)_of_parse_phandle_with_args(a1, "ois-src", 0, 0, 0, &v19) && v19 )
  {
    v7 = of_property_read_variable_u32_array(v19, "cell-index", &v18, 1, 0);
    v6 = v7 & (v7 >> 31);
    if ( (debug_mdl & 0x20) != 0 && !debug_priority )
    {
      v16 = v7;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x20,
        4,
        "cam_sensor_get_sub_module_index",
        65,
        " ois cell index %d, rc %d",
        v18,
        v6);
      if ( (v16 & 0x80000000) == 0 )
        goto LABEL_21;
    }
    else if ( (v7 & 0x80000000) == 0 )
    {
LABEL_21:
      *(_DWORD *)(a2 + 64) = v18;
      goto LABEL_25;
    }
    v11 = "failed %d";
    v12 = 67;
    goto LABEL_54;
  }
  if ( (debug_mdl & 0x20) != 0 && !debug_priority )
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      debug_mdl & 0x20,
      4,
      "cam_sensor_get_sub_module_index",
      62,
      "src_node NULL");
LABEL_25:
  v27 = 0;
  v28 = 0;
  v25 = 0;
  v26 = 0;
  v23 = 0;
  v24 = 0;
  v21 = 0;
  v22 = 0;
  v19 = 0;
  v20 = 0;
  if ( !(unsigned int)_of_parse_phandle_with_args(a1, "eeprom-src", 0, 0, 0, &v19) && v19 )
  {
    v8 = of_property_read_variable_u32_array(v19, "cell-index", &v18, 1, 0);
    v6 = v8 & (v8 >> 31);
    if ( (debug_mdl & 0x20) != 0 && !debug_priority )
    {
      v17 = v8;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x20,
        4,
        "cam_sensor_get_sub_module_index",
        80,
        "eeprom cell index %d, rc %d",
        v18,
        v6);
      if ( (v17 & 0x80000000) == 0 )
        goto LABEL_30;
    }
    else if ( (v8 & 0x80000000) == 0 )
    {
LABEL_30:
      *(_DWORD *)(a2 + 48) = v18;
      goto LABEL_34;
    }
    v11 = "failed %d";
    v12 = 82;
    goto LABEL_54;
  }
  if ( (debug_mdl & 0x20) != 0 && !debug_priority )
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      debug_mdl & 0x20,
      4,
      "cam_sensor_get_sub_module_index",
      77,
      "eeprom src_node NULL");
LABEL_34:
  v27 = 0;
  v28 = 0;
  v25 = 0;
  v26 = 0;
  v23 = 0;
  v24 = 0;
  v21 = 0;
  v22 = 0;
  v19 = 0;
  v20 = 0;
  if ( !(unsigned int)_of_parse_phandle_with_args(a1, "led-flash-src", 0, 0, 0, &v19) && v19 )
  {
    v9 = of_property_read_variable_u32_array(v19, "cell-index", &v18, 1, 0);
    v6 = v9 & (v9 >> 31);
    if ( (debug_mdl & 0x20) != 0 && !debug_priority )
    {
      v13 = v9;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x20,
        4,
        "cam_sensor_get_sub_module_index",
        95,
        "led flash cell index %d, rc %d",
        v18,
        v6);
      if ( (v13 & 0x80000000) == 0 )
        goto LABEL_39;
    }
    else if ( (v9 & 0x80000000) == 0 )
    {
LABEL_39:
      *(_DWORD *)(a2 + 52) = v18;
      goto LABEL_43;
    }
    v11 = "failed %d";
    v12 = 97;
    goto LABEL_54;
  }
  if ( (debug_mdl & 0x20) != 0 && !debug_priority )
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      debug_mdl & 0x20,
      4,
      "cam_sensor_get_sub_module_index",
      92,
      " src_node NULL");
LABEL_43:
  v10 = of_property_read_variable_u32_array(a1, "csiphy-sd-index", &v18, 1, 0);
  if ( (v10 & 0x80000000) != 0 )
  {
    v6 = v10;
    v11 = "paring the dt node for csiphy rc %d";
    v12 = 107;
LABEL_54:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
      3,
      32,
      1,
      "cam_sensor_get_sub_module_index",
      v12,
      v11,
      v6);
    goto LABEL_55;
  }
  v6 = 0;
  *(_DWORD *)(a2 + 60) = v18;
LABEL_55:
  _ReadStatusReg(SP_EL0);
  return v6;
}
