__int64 __fastcall cam_sensor_core_power_up(__int64 a1, __int64 a2, __int64 a3)
{
  _DWORD *v6; // x25
  __int64 v7; // x22
  __int64 v8; // x21
  char v9; // w8
  unsigned int v10; // w0
  unsigned int v11; // w26
  __int64 v12; // x24
  __int64 v13; // x28
  unsigned int v14; // w6
  unsigned int v15; // w27
  unsigned __int64 v16; // x0
  unsigned int v17; // w2
  unsigned int v18; // w3
  unsigned int v19; // w2
  unsigned int v20; // w0
  __int64 v21; // x1
  unsigned int v22; // w6
  unsigned int v23; // w7
  unsigned int v24; // w0
  __int64 v25; // x0
  unsigned int *v26; // x22
  __int64 v27; // x21
  __int64 v28; // x27
  unsigned __int64 v29; // x0
  __int64 v30; // x8
  unsigned __int64 v31; // x9
  unsigned int v32; // w27
  const char *v33; // x5
  __int64 v34; // x4
  __int64 result; // x0
  const char *v36; // x6
  const char *v37; // x5
  __int64 v38; // x4
  __int64 v39; // x10
  __int64 v40; // x21
  int v41; // w8
  __int64 v42; // x24
  __int64 v43; // x1
  unsigned int *v44; // x26
  __int64 v45; // x6
  unsigned int v46; // w28
  _DWORD *v47; // x27
  __int64 v48; // x25
  int v49; // w28
  __int64 v50; // x8
  __int64 v51; // x0
  int v52; // w0
  __int64 v53; // x6
  const char *v54; // x5
  __int64 v55; // x4
  __int64 v56; // [xsp+38h] [xbp-28h]
  __int64 v57; // [xsp+40h] [xbp-20h]
  __int64 v58; // [xsp+48h] [xbp-18h]
  __int64 v59; // [xsp+50h] [xbp-10h]
  __int64 v60; // [xsp+58h] [xbp-8h]

  v6 = &unk_393000;
  if ( (debug_mdl & 0x800000000LL) == 0 || debug_priority )
  {
    if ( a1 )
      goto LABEL_4;
LABEL_172:
    v33 = "Invalid ctrl handle";
    v34 = 2205;
    goto LABEL_173;
  }
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
    3,
    debug_mdl & 0x800000000LL,
    4,
    "cam_sensor_core_power_up",
    2203,
    "Enter");
  if ( !a1 )
    goto LABEL_172;
LABEL_4:
  v7 = *(unsigned int *)(a2 + 488);
  v8 = *(_QWORD *)(a1 + 40);
  if ( (unsigned int)(v7 - 11) <= 0xFFFFFFF5 )
  {
    if ( (debug_bypass_drivers & 1) == 0 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x800000000LL,
        1,
        "cam_sensor_core_power_up",
        2217,
        "failed: num_vreg %d",
        v7);
      return 4294967274LL;
    }
    if ( (debug_mdl & 0x800000000LL) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x800000000LL,
        4,
        "cam_sensor_core_power_up",
        2215,
        "Bypass parameter check num_vreg %d",
        v7);
  }
  v58 = a3;
  if ( (msm_camera_pinctrl_init((unsigned __int64 *)(a1 + 48), *(_QWORD *)a1) & 0x80000000) != 0 )
  {
    v9 = 0;
    if ( (debug_mdl & 0x800000000LL) != 0 && !debug_priority )
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        debug_mdl & 0x800000000LL,
        4,
        "cam_sensor_core_power_up",
        2225,
        "Initialization of pinctrl failed");
      v9 = 0;
    }
  }
  else
  {
    v9 = 1;
  }
  *(_BYTE *)(a1 + 80) = v9;
  v10 = cam_sensor_util_request_gpio_table(a2, 1);
  if ( (v10 & 0x80000000) != 0 )
  {
LABEL_98:
    v33 = "request gpio table failed";
    v34 = 2233;
LABEL_173:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x800000000LL,
      1,
      "cam_sensor_core_power_up",
      v34,
      v33);
    return 4294967274LL;
  }
  v11 = v10;
  if ( *(_BYTE *)(a1 + 80) && (unsigned int)pinctrl_select_state(*(_QWORD *)(a1 + 48), *(_QWORD *)(a1 + 56)) )
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x800000000LL,
      1,
      "cam_sensor_core_power_up",
      2242,
      "cannot set pin to active state");
  if ( (debug_mdl & 0x800000000LL) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x800000000LL,
      4,
      "cam_sensor_core_power_up",
      2245,
      "power setting size: %d",
      *(unsigned __int16 *)(a1 + 16));
  v59 = v7;
  if ( *(_WORD *)(a1 + 16) )
  {
    v12 = 0;
    v57 = a2 + 744;
    v56 = a2 + 496;
    v60 = v8;
    while ( 1 )
    {
      if ( (debug_mdl & 0x800000000LL) != 0 && !debug_priority )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 0x800000000LL,
          4,
          "cam_sensor_core_power_up",
          2248,
          "index: %d",
          v12);
      v13 = *(_QWORD *)(a1 + 8) + 112 * v12;
      if ( !v13 )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          0x800000000LL,
          1,
          "cam_sensor_core_power_up",
          2253,
          "Invalid power up settings for index %d",
          v12);
        return 4294967274LL;
      }
      if ( (debug_mdl & 0x800000000LL) != 0 && !debug_priority )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 0x800000000LL,
          4,
          "cam_sensor_core_power_up",
          2257,
          "seq_type %d",
          *(_DWORD *)v13);
      v14 = *(_DWORD *)v13;
      if ( *(_DWORD *)v13 > 0xDu )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          0x800000000LL,
          1,
          "cam_sensor_core_power_up",
          2437,
          "error power seq type %d",
          v14);
        goto LABEL_66;
      }
      if ( ((1 << v14) & 0x30FE) == 0 )
        break;
      if ( (debug_bypass_drivers & 1) != 0 )
      {
        if ( (debug_mdl & 0x800000000LL) != 0 && !debug_priority )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 0x800000000LL,
            4,
            "cam_sensor_core_power_up",
            2369,
            "Bypass regulator enable seq_type %d",
            v14);
        goto LABEL_25;
      }
      v15 = *(unsigned __int16 *)(v13 + 4);
      if ( v15 != 100 )
      {
        if ( v15 >= 8 )
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            0x800000000LL,
            1,
            "cam_sensor_core_power_up",
            2379,
            "vreg index %d >= max %d",
            v15,
            8);
          goto LABEL_120;
        }
        if ( (int)v7 <= (int)v15 )
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            0x800000000LL,
            1,
            "cam_sensor_core_power_up",
            2423,
            "usr_idx:%d dts_idx:%d",
            v15,
            v7);
        }
        else
        {
          if ( (debug_mdl & 0x800000000LL) != 0 && !debug_priority )
          {
            ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
              3,
              debug_mdl & 0x800000000LL,
              4,
              "cam_sensor_core_power_up",
              2383,
              "Enable Regulator");
            v15 = *(unsigned __int16 *)(v13 + 4);
            if ( v15 > 9 )
            {
LABEL_97:
              __break(0x5512u);
              goto LABEL_98;
            }
          }
          v16 = *(_QWORD *)(v57 + 8LL * v15);
          if ( !v16 || v16 >= 0xFFFFFFFFFFFFF001LL )
          {
            if ( (_DWORD)v16 )
              v11 = *(_QWORD *)(v57 + 8LL * v15);
            else
              v11 = -22;
            v36 = *(const char **)(v56 + 8LL * v15);
            v37 = "%s get failed %d";
            v38 = 2393;
            goto LABEL_115;
          }
          LODWORD(v7) = v59;
          if ( *(_BYTE *)(v13 + 104) == 1 )
          {
            v17 = *(_DWORD *)(v13 + 8);
            v18 = v17;
          }
          else
          {
            v17 = *(_DWORD *)(a2 + 580 + 4LL * v15);
            v18 = *(_DWORD *)(a2 + 620 + 4LL * v15);
          }
          v8 = v60;
          v24 = cam_soc_util_regulator_enable(
                  v16,
                  *(const char **)(v56 + 8LL * v15),
                  v17,
                  v18,
                  *(_DWORD *)(a2 + 660 + 4LL * v15),
                  *(_DWORD *)(a2 + 824 + 4LL * v15));
          if ( v24 )
          {
            v11 = v24;
            v54 = "Reg Enable failed for %s";
            v53 = *(_QWORD *)(v56 + 8LL * v15);
            v55 = 2416;
            goto LABEL_117;
          }
          *(_QWORD *)(v13 + 24) = *(_QWORD *)(v57 + 8LL * v15);
        }
        v20 = *(_DWORD *)v13;
        v21 = v8;
        v19 = 1;
LABEL_65:
        msm_cam_sensor_handle_reg_gpio(v20, v21, v19);
        v11 = 0;
      }
LABEL_66:
      v25 = *(unsigned __int16 *)(v13 + 16);
      if ( (unsigned int)v25 >= 0x15 )
      {
        msleep(v25);
      }
      else if ( *(_WORD *)(v13 + 16) )
      {
        usleep_range_state(1000LL * *(unsigned __int16 *)(v13 + 16), (1000 * *(unsigned __int16 *)(v13 + 16)) | 5u, 2);
      }
LABEL_25:
      if ( ++v12 >= (unsigned __int64)*(unsigned __int16 *)(a1 + 16) )
        goto LABEL_100;
    }
    if ( ((1 << v14) & 0xF00) == 0 )
    {
      if ( (debug_bypass_drivers & 4) != 0 )
      {
        if ( (debug_mdl & 0x800000000LL) != 0 && !debug_priority )
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
            3,
            debug_mdl & 0x800000000LL,
            4,
            "cam_sensor_core_power_up",
            2262,
            "Bypass mclk enable");
        goto LABEL_25;
      }
      v22 = *(unsigned __int16 *)(v13 + 4);
      v23 = *(_DWORD *)(a2 + 868);
      if ( v23 <= v22 )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          0x800000000LL,
          1,
          "cam_sensor_core_power_up",
          2269,
          "clk index %d >= max %u",
          v22,
          v23);
        goto LABEL_120;
      }
      if ( (*(_BYTE *)(a2 + 3308) & 1) != 0 )
      {
        v11 = cam_soc_util_turn_on_power_domain(a2);
        if ( v11 )
        {
          v53 = *(_QWORD *)(a2 + 24);
          v54 = "Failed to turn on the GDSC for dev: %s";
          v55 = 2277;
LABEL_117:
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
            3,
            0x800000000LL,
            1,
            "cam_sensor_core_power_up",
            v55,
            v54,
            v53);
          goto LABEL_120;
        }
      }
      else if ( (int)v7 >= 1 )
      {
        v26 = (unsigned int *)(a2 + 580);
        v27 = a2 + 496;
        v28 = 0;
        do
        {
          if ( v28 == 10 )
            goto LABEL_97;
          if ( !strcmp(*(const char **)v27, "cam_clk") )
          {
            if ( (debug_mdl & 0x800000000LL) != 0 && !debug_priority )
            {
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                debug_mdl & 0x800000000LL,
                4,
                "cam_sensor_core_power_up",
                2285,
                "Enable cam_clk: %d",
                v28);
              v29 = *(_QWORD *)(v27 + 248);
              if ( !v29 )
              {
LABEL_111:
                v36 = *(const char **)v27;
                if ( (_DWORD)v29 )
                  v11 = v29;
                else
                  v11 = -22;
                v37 = "vreg %s %d";
                v38 = 2295;
LABEL_115:
                ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, const char *, _QWORD))cam_print_log)(
                  3,
                  0x800000000LL,
                  1,
                  "cam_sensor_core_power_up",
                  v38,
                  v37,
                  v36,
                  v11);
                LODWORD(v7) = v59;
LABEL_120:
                ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                  3,
                  0x800000000LL,
                  1,
                  "cam_sensor_core_power_up",
                  2460,
                  "failed. rc:%d",
                  v11);
                if ( (int)v12 < 1 )
                {
LABEL_166:
                  if ( *(_BYTE *)(a1 + 80) )
                  {
                    if ( (unsigned int)pinctrl_select_state(*(_QWORD *)(a1 + 48), *(_QWORD *)(a1 + 64)) )
                      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                        3,
                        0x800000000LL,
                        1,
                        "cam_sensor_core_power_up",
                        2568,
                        "cannot set pin to suspend state");
                    devm_pinctrl_put(*(_QWORD *)(a1 + 48));
                  }
                  *(_BYTE *)(a1 + 80) = 0;
                  cam_sensor_util_request_gpio_table(a2, 0);
                  return 4294967274LL;
                }
                v39 = a2 + 496;
                v40 = (unsigned int)v12;
                while ( 2 )
                {
                  v41 = v6[919];
                  v42 = v40--;
                  v43 = debug_mdl & 0x800000000LL;
                  if ( (debug_mdl & 0x800000000LL) != 0 && !v41 )
                  {
                    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                      3,
                      v43,
                      4,
                      "cam_sensor_core_power_up",
                      2462,
                      "index %d",
                      v40);
                    v39 = a2 + 496;
                    v41 = v6[919];
                    v43 = debug_mdl & 0x800000000LL;
                  }
                  v44 = (unsigned int *)(*(_QWORD *)(a1 + 8) + 112 * v40);
                  if ( v43 && !v41 )
                  {
                    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                      3,
                      v43,
                      4,
                      "cam_sensor_core_power_up",
                      2465,
                      "type %d",
                      *v44);
                    v39 = a2 + 496;
                  }
                  v45 = *v44;
                  if ( (unsigned int)v45 > 0xD )
                  {
                    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                      3,
                      0x800000000LL,
                      1,
                      "cam_sensor_core_power_up",
                      2552,
                      "error power seq type %d",
                      v45);
                    goto LABEL_158;
                  }
                  if ( ((1 << v45) & 0x30FE) != 0 )
                  {
                    if ( (debug_bypass_drivers & 1) == 0 )
                    {
                      v46 = *((unsigned __int16 *)v44 + 2);
                      if ( (int)v7 <= (int)v46 )
                      {
                        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                          3,
                          0x800000000LL,
                          1,
                          "cam_sensor_core_power_up",
                          2543,
                          "seq_val:%d > num_vreg: %d",
                          v46,
                          v7);
                      }
                      else
                      {
                        if ( (debug_mdl & 0x800000000LL) != 0 )
                        {
                          v7 = a2 + 744;
                          if ( !v6[919] )
                          {
                            ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                              3,
                              debug_mdl & 0x800000000LL,
                              4,
                              "cam_sensor_core_power_up",
                              2516,
                              "Disable Regulator");
                            v39 = a2 + 496;
                            v46 = *((unsigned __int16 *)v44 + 2);
                          }
                        }
                        else
                        {
                          v7 = a2 + 744;
                        }
                        if ( v46 > 9 )
                          goto LABEL_97;
                        v47 = v6;
                        v48 = v39;
                        if ( (unsigned int)cam_soc_util_regulator_disable(
                                             *(_QWORD *)(v7 + 8LL * v46),
                                             *(const char **)(v39 + 8LL * v46),
                                             *(unsigned int *)(a2 + 580 + 4LL * v46),
                                             *(_DWORD *)(a2 + 620 + 4LL * v46),
                                             *(unsigned int *)(a2 + 660 + 4LL * v46),
                                             *(_DWORD *)(a2 + 824 + 4LL * v46)) )
                        {
                          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                            3,
                            0x800000000LL,
                            1,
                            "cam_sensor_core_power_up",
                            2530,
                            "Fail to disalbe reg: %s",
                            *(const char **)(v48 + 8LL * v46));
                          *(_QWORD *)(v7 + 8LL * v46) = 0;
                          msm_cam_sensor_handle_reg_gpio(*v44, v60, 0);
                          LODWORD(v7) = v59;
                          v39 = v48;
                          v6 = v47;
                          goto LABEL_124;
                        }
                        v50 = *(_QWORD *)(v7 + 8LL * v46);
                        LODWORD(v7) = v59;
                        v6 = v47;
                        *((_QWORD *)v44 + 3) = v50;
                      }
                      msm_cam_sensor_handle_reg_gpio(*v44, v60, 0);
                      goto LABEL_158;
                    }
                    if ( (debug_mdl & 0x800000000LL) != 0 && !v6[919] )
                    {
                      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                        3,
                        debug_mdl & 0x800000000LL,
                        4,
                        "cam_sensor_core_power_up",
                        2511,
                        "Bypass regulator disable seq_type %d",
                        v45);
                      goto LABEL_123;
                    }
                  }
                  else if ( ((1 << v45) & 0xF00) != 0 )
                  {
                    if ( v60 && *(_BYTE *)(v60 + 28 + v45) )
                    {
                      cam_res_mgr_gpio_set_value(*(unsigned __int16 *)(v60 + 2 * v45), 0);
                      goto LABEL_158;
                    }
                  }
                  else if ( (debug_bypass_drivers & 4) != 0 )
                  {
                    if ( (debug_mdl & 0x800000000LL) != 0 && !v6[919] )
                    {
                      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                        3,
                        debug_mdl & 0x800000000LL,
                        4,
                        "cam_sensor_core_power_up",
                        2469,
                        "Bypass mclk disable");
                      goto LABEL_123;
                    }
                  }
                  else
                  {
                    v49 = *(_DWORD *)(a2 + 868) - 1;
                    if ( v49 >= 0 )
                    {
                      do
                        cam_soc_util_clk_disable(a2, 0xFFFFFFFF, 0, (unsigned int)v49--);
                      while ( v49 != -1 );
                    }
                    if ( *(_BYTE *)(a2 + 3308) == 1 )
                    {
                      cam_soc_util_turn_off_power_domain(a2);
                      goto LABEL_158;
                    }
                    v52 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD))cam_config_mclk_reg)(
                            a1,
                            a2,
                            (unsigned int)v40);
                    if ( v52 < 0 )
                    {
                      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                        3,
                        0x800000000LL,
                        1,
                        "cam_sensor_core_power_up",
                        2482,
                        "config clk reg failed rc: %d",
                        v52);
                      goto LABEL_123;
                    }
LABEL_158:
                    v51 = *((unsigned __int16 *)v44 + 8);
                    if ( (unsigned int)v51 >= 0x15 )
                    {
                      msleep(v51);
LABEL_123:
                      v39 = a2 + 496;
                      goto LABEL_124;
                    }
                    v39 = a2 + 496;
                    if ( *((_WORD *)v44 + 8) )
                    {
                      usleep_range_state(
                        1000LL * *((unsigned __int16 *)v44 + 8),
                        (1000 * *((unsigned __int16 *)v44 + 8)) | 5u,
                        2);
                      goto LABEL_123;
                    }
                  }
LABEL_124:
                  if ( v42 <= 1 )
                    goto LABEL_166;
                  continue;
                }
              }
            }
            else
            {
              v29 = *(_QWORD *)(v27 + 248);
              if ( !v29 )
                goto LABEL_111;
            }
            if ( v29 >= 0xFFFFFFFFFFFFF001LL )
              goto LABEL_111;
            v11 = cam_soc_util_regulator_enable(v29, *(const char **)v27, *v26, v26[10], v26[20], v26[61]);
            if ( v11 )
            {
              ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                3,
                0x800000000LL,
                1,
                "cam_sensor_core_power_up",
                2308,
                "Reg enable failed");
              LODWORD(v7) = v59;
              goto LABEL_120;
            }
            *(_QWORD *)(v13 + 24) = *(_QWORD *)(v27 + 248);
          }
          ++v28;
          v27 += 8;
          ++v26;
        }
        while ( v59 != v28 );
      }
      v30 = *(_QWORD *)(v13 + 8);
      if ( v30 )
      {
        v31 = *(unsigned __int16 *)(v13 + 4);
        if ( v31 > 0x1F )
          goto LABEL_97;
        *(_DWORD *)(a2 + 1384 + 4 * v31) = v30;
      }
      LODWORD(v7) = v59;
      v8 = v60;
      if ( *(_DWORD *)(a2 + 868) )
      {
        v32 = 0;
        while ( 1 )
        {
          v11 = cam_soc_util_clk_enable(a2, 0xFFFFFFFF, 0, v32, 0);
          if ( v11 )
            break;
          if ( ++v32 >= *(_DWORD *)(a2 + 868) )
            goto LABEL_66;
        }
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          0x20000,
          1,
          "cam_sensor_core_power_up",
          2326,
          "Failed in clk enable %d",
          0);
      }
      if ( (v11 & 0x80000000) != 0 )
      {
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          0x800000000LL,
          1,
          "cam_sensor_core_power_up",
          2332,
          "clk enable failed");
        goto LABEL_120;
      }
      goto LABEL_66;
    }
    if ( !v8 )
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        0x800000000LL,
        1,
        "cam_sensor_core_power_up",
        2341,
        "Invalid gpio_num_info");
      goto LABEL_120;
    }
    if ( (debug_mdl & 0x800000000LL) != 0 && !debug_priority )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x800000000LL,
        4,
        "cam_sensor_core_power_up",
        2346,
        "gpio set val %d",
        *(unsigned __int16 *)(v8 + 2LL * v14));
      v14 = *(_DWORD *)v13;
    }
    v19 = *(_DWORD *)(v13 + 8);
    v20 = v14;
    v21 = v8;
    goto LABEL_65;
  }
  LODWORD(v12) = 0;
LABEL_100:
  result = v58;
  if ( v58 )
  {
    if ( !cam_common_wait_for_completion_timeout(v58) )
    {
      v60 = v8;
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        0x800000000LL,
        1,
        "cam_sensor_core_power_up",
        2452,
        "Wait for I3C probe timedout");
      v11 = -110;
      goto LABEL_120;
    }
    return 0;
  }
  return result;
}
