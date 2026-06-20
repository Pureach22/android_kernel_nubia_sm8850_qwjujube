__int64 __fastcall cam_sensor_parse_dt(__int64 a1)
{
  __int64 v1; // x21
  __int64 v3; // x0
  __int64 v4; // x20
  int v5; // w6
  __int64 v6; // x0
  unsigned int updated; // w22
  __int64 v8; // x0
  unsigned int v9; // w0
  __int64 v10; // x8
  int v11; // w7
  unsigned int inited; // w0
  unsigned int v13; // w6
  const char *v14; // x5
  __int64 v15; // x4
  __int64 v16; // x22
  __int64 v17; // x26
  unsigned __int64 v18; // x0
  unsigned int sub_module_index; // w0
  int v20; // w1
  int v21; // w8
  __int64 v22; // x8
  __int64 v23; // x6
  const char *v24; // x5
  __int64 v25; // x1
  __int64 v26; // x2
  __int64 v27; // x4
  unsigned int v28; // w0
  int v29; // w22
  unsigned int v30; // w23
  unsigned __int64 StatusReg; // x22
  __int64 v32; // x23

  v1 = *(_QWORD *)(a1 + 6560);
  if ( mem_trace_en == 1 )
    v3 = cam_mem_trace_alloc(200, 0xCC0u, 0, "cam_sensor_parse_dt", 0xB8u);
  else
    v3 = _kvmalloc_node_noprof(200, 0, 3520, 0xFFFFFFFFLL);
  v4 = v3;
  *(_QWORD *)(a1 + 3656) = v3;
  if ( !v3 )
    return (unsigned int)-12;
  while ( 1 )
  {
    cam_sensor_get_ois_dev(v1, a1);
    if ( !a1 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        32,
        1,
        "cam_sensor_init_bus_params",
        147,
        "failed: invalid params s_ctrl %pK",
        nullptr);
      goto LABEL_22;
    }
    if ( (debug_mdl & 0x20) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x20,
        4,
        "cam_sensor_init_bus_params",
        152,
        "master_type: %d",
        *(_DWORD *)(a1 + 6480));
    v5 = *(_DWORD *)(a1 + 6480);
    if ( v5 == 4 )
    {
      if ( (debug_mdl & 0x20) != 0 && !debug_priority )
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          debug_mdl & 0x20,
          4,
          "cam_sensor_init_bus_params",
          165,
          "I3C Master Type");
      goto LABEL_25;
    }
    if ( v5 != 2 )
    {
      if ( v5 == 1 )
      {
        if ( mem_trace_en == 1 )
        {
          v6 = cam_mem_trace_alloc(40, 0xCC0u, 0, "cam_sensor_init_bus_params", 0x9Cu);
          *(_QWORD *)(a1 + 6496) = v6;
          if ( !v6 )
            goto LABEL_96;
          goto LABEL_25;
        }
        v8 = _kvmalloc_node_noprof(40, 0, 3520, 0xFFFFFFFFLL);
        *(_QWORD *)(a1 + 6496) = v8;
        if ( v8 )
          goto LABEL_25;
LABEL_96:
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          32,
          1,
          "cam_sensor_init_bus_params",
          158,
          "Memory allocation failed");
        updated = -12;
LABEL_23:
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          32,
          1,
          "cam_sensor_parse_dt",
          195,
          "Failed in Initialize Bus params, rc %d",
          updated);
        goto LABEL_88;
      }
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        32,
        1,
        "cam_sensor_init_bus_params",
        169,
        "Invalid master / Master type Not supported : %d",
        v5);
LABEL_22:
      updated = -22;
      goto LABEL_23;
    }
    if ( !*(_QWORD *)(a1 + 6488) )
      goto LABEL_22;
LABEL_25:
    v9 = ((__int64 (__fastcall *)(__int64, __int64))cam_sensor_util_parse_and_request_resources)(a1 + 6480, a1 + 32);
    if ( (v9 & 0x80000000) != 0 )
    {
      updated = v9;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x10000,
        1,
        "cam_sensor_parse_dt",
        202,
        "Failed in parse_and_request_resources rc : %d",
        v9);
      return updated;
    }
    v10 = *(_QWORD *)(a1 + 6488);
    if ( v10 )
      v11 = *(unsigned __int8 *)(v10 + 16);
    else
      v11 = 0;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      32,
      3,
      "cam_sensor_parse_dt",
      210,
      "master: %d (1-CCI, 2-I2C, 3-SPI, 4-I3C) pm_ctrl_client_enable: %d",
      *(_DWORD *)(a1 + 6480),
      v11);
    inited = cam_sensor_util_init_gpio_pin_tbl(a1 + 32, v4 + 152);
    if ( (inited & 0x80000000) != 0 )
    {
      updated = inited;
      v14 = "Failed to read gpios %d";
      v15 = 215;
      goto LABEL_86;
    }
    v13 = *(_DWORD *)(a1 + 52);
    *(_DWORD *)(a1 + 6552) = v13;
    if ( v13 > 0xF )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        32,
        1,
        "cam_sensor_parse_dt",
        223,
        "Failed invalid cell_id %d",
        v13);
      updated = -22;
      goto LABEL_87;
    }
    if ( !*(_DWORD *)(a1 + 520) )
      break;
    v16 = 0;
    while ( v16 != 10 )
    {
      v17 = a1 + 8 * v16;
      if ( !strcmp(*(const char **)(v17 + 528), "cam_bob") )
      {
        if ( (debug_mdl & 0x20) != 0 && !debug_priority )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 0x20,
            4,
            "cam_sensor_parse_dt",
            233,
            "i: %d cam_bob",
            v16);
        *(_DWORD *)(a1 + 7544) = v16;
        v18 = devm_regulator_get(*(_QWORD *)(a1 + 40), *(_QWORD *)(v17 + 528));
        *(_QWORD *)(v17 + 776) = v18;
        if ( v18 && v18 < 0xFFFFFFFFFFFFF001LL )
        {
          if ( of_find_property(v1, "pwm-switch", 0) )
          {
            *(_BYTE *)(a1 + 7548) = 1;
          }
          else
          {
            if ( (debug_mdl & 0x20) != 0 && !debug_priority )
              ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                3,
                debug_mdl & 0x20,
                4,
                "cam_sensor_parse_dt",
                246,
                "No BoB PWM switch param defined");
            *(_BYTE *)(a1 + 7548) = 0;
          }
        }
        else
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            32,
            2,
            "cam_sensor_parse_dt",
            240,
            "Regulator: %s get failed",
            *(const char **)(v17 + 528));
          *(_QWORD *)(v17 + 776) = 0;
        }
      }
      if ( ++v16 >= (unsigned __int64)*(unsigned int *)(a1 + 520) )
        goto LABEL_51;
    }
    __break(0x5512u);
    StatusReg = _ReadStatusReg(SP_EL0);
    v32 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &cam_sensor_parse_dt__alloc_tag;
    v4 = _kvmalloc_node_noprof(200, 0, 3520, 0xFFFFFFFFLL);
    *(_QWORD *)(StatusReg + 80) = v32;
    *(_QWORD *)(a1 + 3656) = v4;
    if ( !v4 )
      return (unsigned int)-12;
  }
LABEL_51:
  sub_module_index = cam_sensor_get_sub_module_index(v1, v4);
  if ( (sub_module_index & 0x80000000) != 0 )
  {
    updated = sub_module_index;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      32,
      1,
      "cam_sensor_parse_dt",
      259,
      "failed to get sub module index, rc=%d",
      sub_module_index);
    goto LABEL_87;
  }
  if ( (of_property_read_variable_u32_array(v1, "sensor-position-pitch", v4 + 36, 1, 0) & 0x80000000) != 0 )
  {
    if ( (debug_mdl & 0x20) != 0 && !debug_priority )
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        debug_mdl & 0x20,
        4,
        "cam_sensor_parse_dt",
        265,
        "Invalid sensor position");
    *(_DWORD *)(v4 + 36) = 360;
  }
  if ( (of_property_read_variable_u32_array(v1, "sensor-position-roll", v4 + 28, 1, 0) & 0x80000000) != 0 )
  {
    if ( (debug_mdl & 0x20) != 0 && !debug_priority )
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        debug_mdl & 0x20,
        4,
        "cam_sensor_parse_dt",
        270,
        "Invalid sensor position");
    *(_DWORD *)(v4 + 28) = 360;
  }
  if ( (of_property_read_variable_u32_array(v1, "sensor-position-yaw", v4 + 32, 1, 0) & 0x80000000) != 0 )
  {
    if ( (debug_mdl & 0x20) != 0 && !debug_priority )
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        debug_mdl & 0x20,
        4,
        "cam_sensor_parse_dt",
        275,
        "Invalid sensor position");
    *(_DWORD *)(v4 + 32) = 360;
  }
  if ( (of_property_read_variable_u32_array(v1, "aon-camera-id", a1 + 7596, 1, 0) & 0x80000000) != 0 )
  {
    if ( (debug_mdl & 0x20) == 0 || debug_priority )
      goto LABEL_80;
    v23 = *(unsigned int *)(a1 + 52);
    v24 = "cell_idx: %d is not used for AON usecase";
    v25 = debug_mdl & 0x20;
    v26 = 4;
    v27 = 280;
LABEL_79:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
      3,
      v25,
      v26,
      "cam_sensor_parse_dt",
      v27,
      v24,
      v23);
LABEL_80:
    v20 = 255;
    *(_DWORD *)(a1 + 7596) = 255;
    goto LABEL_81;
  }
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    32,
    3,
    "cam_sensor_parse_dt",
    286,
    "AON Sensor detected in cell_idx: %d aon_camera_id: %d phy_index: %d",
    *(_DWORD *)(a1 + 52),
    *(_DWORD *)(a1 + 7596),
    *(_DWORD *)(*(_QWORD *)(a1 + 3656) + 60LL));
  v20 = *(_DWORD *)(a1 + 7596);
  v21 = *(_DWORD *)(*(_QWORD *)(a1 + 3656) + 60LL);
  if ( v21 == 4 )
  {
    if ( !v20 )
      goto LABEL_81;
    goto LABEL_78;
  }
  if ( v21 == 2 && v20 != 1 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      32,
      1,
      "cam_sensor_parse_dt",
      290,
      "Incorrect AON camera id for cphy_index %d",
      2);
    v20 = 255;
    v22 = *(_QWORD *)(a1 + 3656);
    *(_DWORD *)(a1 + 7596) = 255;
    if ( *(_DWORD *)(v22 + 60) == 4 )
    {
LABEL_78:
      v24 = "Incorrect AON camera id for cphy_index %d";
      v25 = 32;
      v26 = 1;
      v27 = 296;
      v23 = 4;
      goto LABEL_79;
    }
  }
LABEL_81:
  v28 = *(_DWORD *)(*(_QWORD *)(a1 + 3656) + 60LL);
  if ( (debug_mdl & 0x20) != 0 && !debug_priority )
  {
    v29 = v20;
    v30 = *(_DWORD *)(*(_QWORD *)(a1 + 3656) + 60LL);
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x20,
      4,
      "cam_sensor_util_aon_registration",
      141,
      "Register phy_idx: %u for AON_Camera_ID: %d",
      v28,
      v20);
    v28 = v30;
    v20 = v29;
  }
  updated = cam_csiphy_util_update_aon_registration(v28, v20);
  if ( !updated )
  {
    *(_BYTE *)(a1 + 7632) = of_find_property(v1, "hw-no-ops", 0) != 0;
    _mutex_init(a1 + 3608, "&(s_ctrl->cam_sensor_mutex)", &cam_sensor_parse_dt___key);
    _mutex_init(a1 + 7928, "&(s_ctrl->read_buf_lock)", &cam_sensor_parse_dt___key_44);
    *(_QWORD *)(a1 + 7912) = a1 + 7912;
    *(_QWORD *)(a1 + 7920) = a1 + 7912;
    return updated;
  }
  v14 = "Aon registration failed, rc: %d";
  v15 = 305;
LABEL_86:
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
    3,
    32,
    1,
    "cam_sensor_parse_dt",
    v15,
    v14,
    updated);
LABEL_87:
  cam_sensor_util_release_resources(a1 + 6480, a1 + 32);
LABEL_88:
  if ( mem_trace_en == 1 )
    cam_mem_trace_free((_QWORD *)v4, 0);
  else
    kvfree(v4);
  *(_QWORD *)(a1 + 3656) = 0;
  return updated;
}
