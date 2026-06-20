__int64 __fastcall cam_sensor_util_power_down(__int64 a1, __int64 a2)
{
  signed int v4; // w21
  __int64 v5; // x22
  const char *v6; // x5
  __int64 v7; // x4
  __int64 v8; // x6
  __int64 v9; // x23
  unsigned int *v10; // x28
  __int64 v11; // x6
  unsigned int v12; // w8
  __int64 v13; // x9
  __int64 v14; // x25
  int v15; // w0
  __int64 v16; // x8
  int v17; // w25
  __int64 v18; // x0
  int v19; // w0
  __int64 v21; // [xsp+28h] [xbp-18h]
  __int64 v22; // [xsp+30h] [xbp-10h]

  if ( (debug_mdl & 0x800000000LL) != 0 && !debug_priority )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      debug_mdl & 0x800000000LL,
      4,
      "cam_sensor_util_power_down",
      2607,
      "Enter");
    if ( !a1 )
      goto LABEL_76;
  }
  else if ( !a1 )
  {
LABEL_76:
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x800000000LL,
      1,
      "cam_sensor_util_power_down",
      2609,
      "failed ctrl %pK",
      (const void *)a1);
    return 4294967274LL;
  }
  if ( !a2 )
    goto LABEL_76;
  v4 = *(_DWORD *)(a2 + 488);
  v5 = *(_QWORD *)(a1 + 40);
  if ( (unsigned int)(v4 - 11) <= 0xFFFFFFF5 )
  {
    if ( (debug_bypass_drivers & 1) == 0 )
    {
      v6 = "failed: num_vreg %d";
      v7 = 2621;
      v8 = (unsigned int)v4;
      goto LABEL_74;
    }
    if ( (debug_mdl & 0x800000000LL) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x800000000LL,
        4,
        "cam_sensor_util_power_down",
        2619,
        "Bypass parameter check num_vreg %d",
        v4);
  }
  if ( *(unsigned __int16 *)(a1 + 32) > 0xCu )
  {
    v8 = *(unsigned __int16 *)(a1 + 16);
    v6 = "Invalid: power setting size %d";
    v7 = 2628;
    goto LABEL_74;
  }
  if ( !*(_WORD *)(a1 + 32) )
  {
LABEL_68:
    if ( *(_BYTE *)(a1 + 80) )
    {
      if ( (unsigned int)pinctrl_select_state(*(_QWORD *)(a1 + 48), *(_QWORD *)(a1 + 64)) )
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          0x800000000LL,
          1,
          "cam_sensor_util_power_down",
          2763,
          "cannot set pin to suspend state");
      devm_pinctrl_put(*(_QWORD *)(a1 + 48));
    }
    cam_sensor_util_request_gpio_table(a2, 0);
    *(_BYTE *)(a1 + 80) = 0;
    return 0;
  }
  v9 = 0;
  v21 = a2 + 744;
  v22 = a2 + 496;
  while ( 1 )
  {
    if ( (debug_mdl & 0x800000000LL) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x800000000LL,
        4,
        "cam_sensor_util_power_down",
        2633,
        "power_down_index %d",
        v9);
    v10 = (unsigned int *)(*(_QWORD *)(a1 + 24) + 112 * v9);
    if ( !v10 )
      break;
    if ( (debug_mdl & 0x800000000LL) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x800000000LL,
        4,
        "cam_sensor_util_power_down",
        2642,
        "seq_type %d",
        *v10);
    v11 = *v10;
    if ( (unsigned int)v11 > 0xD )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x800000000LL,
        1,
        "cam_sensor_util_power_down",
        2748,
        "error power seq type %d",
        v11);
      goto LABEL_55;
    }
    if ( ((1 << v11) & 0x30FE) != 0 )
    {
      if ( (debug_bypass_drivers & 1) != 0 )
      {
        if ( (debug_mdl & 0x800000000LL) != 0 && !debug_priority )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 0x800000000LL,
            4,
            "cam_sensor_util_power_down",
            2695,
            "Bypass regulator disable seq_type %d",
            v11);
        goto LABEL_16;
      }
      v12 = *((unsigned __int16 *)v10 + 2);
      if ( v12 == 100 )
        goto LABEL_55;
      v13 = *(unsigned __int16 *)(a1 + 16);
      if ( !*(_WORD *)(a1 + 16) )
        goto LABEL_46;
      v14 = *(_QWORD *)(a1 + 8);
      while ( __PAIR64__(*(unsigned __int16 *)(v14 + 4), *(_DWORD *)v14) != __PAIR64__(v12, v11) )
      {
        --v13;
        v14 += 112;
        if ( !v13 )
          goto LABEL_46;
      }
      if ( !v14 )
      {
LABEL_46:
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          0x800000000LL,
          1,
          "cam_sensor_util_power_down",
          2737,
          "error in power up/down seq");
        goto LABEL_47;
      }
      if ( v4 <= (int)v12 )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          0x800000000LL,
          1,
          "cam_sensor_util_power_down",
          2733,
          "seq_val:%d > num_vreg: %d",
          *((unsigned __int16 *)v10 + 2),
          v4);
        goto LABEL_47;
      }
      if ( (debug_mdl & 0x800000000LL) != 0 && !debug_priority )
      {
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          debug_mdl & 0x800000000LL,
          4,
          "cam_sensor_util_power_down",
          2708,
          "Disable Regulator");
        v12 = *(unsigned __int16 *)(v14 + 4);
        if ( v12 > 9 )
        {
LABEL_67:
          __break(0x5512u);
          goto LABEL_68;
        }
      }
      else if ( v12 > 9 )
      {
        goto LABEL_67;
      }
      v15 = cam_soc_util_regulator_disable(
              *(_QWORD *)(v21 + 8LL * v12),
              *(const char **)(v22 + 8LL * v12),
              *(unsigned int *)(a2 + 580 + 4LL * v12),
              *(_DWORD *)(a2 + 620 + 4LL * v12),
              *(unsigned int *)(a2 + 660 + 4LL * v12),
              *(_DWORD *)(a2 + 824 + 4LL * v12));
      v16 = *(unsigned __int16 *)(v14 + 4);
      if ( !v15 )
      {
        if ( (unsigned int)v16 > 9 )
          goto LABEL_67;
        *(_QWORD *)(v14 + 24) = *(_QWORD *)(v21 + 8 * v16);
LABEL_47:
        msm_cam_sensor_handle_reg_gpio(*v10, v5, 0);
LABEL_55:
        v18 = *((unsigned __int16 *)v10 + 8);
        if ( (unsigned int)v18 >= 0x15 )
        {
          msleep(v18);
        }
        else if ( *((_WORD *)v10 + 8) )
        {
          usleep_range_state(1000LL * *((unsigned __int16 *)v10 + 8), (1000 * *((unsigned __int16 *)v10 + 8)) | 5u, 2);
        }
        goto LABEL_16;
      }
      if ( (unsigned int)v16 > 9 )
        goto LABEL_67;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x800000000LL,
        1,
        "cam_sensor_util_power_down",
        2720,
        "Reg: %s disable failed",
        *(const char **)(v22 + 8 * v16));
      msm_cam_sensor_handle_reg_gpio(*v10, v5, 0);
    }
    else if ( ((1 << v11) & 0xF00) != 0 )
    {
      if ( *(_BYTE *)(v5 + 28 + v11) )
      {
        cam_res_mgr_gpio_set_value(*(unsigned __int16 *)(v5 + 2 * v11), v10[2]);
        goto LABEL_55;
      }
    }
    else
    {
      if ( (debug_bypass_drivers & 4) != 0 )
      {
        if ( (debug_mdl & 0x800000000LL) != 0 && !debug_priority )
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
            3,
            debug_mdl & 0x800000000LL,
            4,
            "cam_sensor_util_power_down",
            2646,
            "Bypass mclk disable");
        goto LABEL_16;
      }
      v17 = *(_DWORD *)(a2 + 868) - 1;
      if ( v17 >= 0 )
      {
        do
          cam_soc_util_clk_disable(a2, 0xFFFFFFFF, 0, (unsigned int)v17--);
        while ( v17 != -1 );
      }
      if ( *(_BYTE *)(a2 + 3308) == 1 )
      {
        if ( !(unsigned int)cam_soc_util_turn_off_power_domain(a2) )
          goto LABEL_55;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          0x800000000LL,
          1,
          "cam_sensor_util_power_down",
          2658,
          "Failed to turn off the GDSC for dev: %s",
          *(const char **)(a2 + 24));
      }
      else
      {
        v19 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD))cam_config_mclk_reg)(a1, a2, (unsigned int)v9);
        if ( (v19 & 0x80000000) == 0 )
          goto LABEL_55;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          0x800000000LL,
          1,
          "cam_sensor_util_power_down",
          2665,
          "config clk reg failed rc: %d",
          v19);
      }
    }
LABEL_16:
    if ( ++v9 >= (unsigned __int64)*(unsigned __int16 *)(a1 + 32) )
      goto LABEL_68;
  }
  v6 = "Invalid power down settings for index %d";
  v7 = 2638;
  v8 = (unsigned int)v9;
LABEL_74:
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
    3,
    0x800000000LL,
    1,
    "cam_sensor_util_power_down",
    v7,
    v6,
    v8);
  return 4294967274LL;
}
