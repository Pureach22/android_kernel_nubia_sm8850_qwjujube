__int64 __fastcall lpass_cdc_va_macro_probe(__int64 a1)
{
  __int64 v1; // x19
  __int64 v3; // x0
  _QWORD *v4; // x21
  __int64 v5; // x0
  unsigned int variable_u32_array; // w0
  __int64 v7; // x0
  unsigned int v8; // w22
  __int64 v9; // x0
  int *v10; // x23
  int v11; // w3
  __int16 v12; // w8
  unsigned int v13; // w23
  __int16 v14; // w8
  __int16 v15; // w8
  int v16; // w3
  unsigned int v17; // w22
  __int64 v18; // x0
  int *v19; // x23
  __int16 v20; // w8
  __int16 v22; // w8
  __int16 v23; // w8
  __int64 v24; // x0
  __int64 v25; // x0
  __int64 v26; // x0
  __int64 v27; // x22
  unsigned __int64 v28; // x0
  unsigned __int64 v29; // x8
  __int64 v30; // x0
  unsigned __int64 v31; // x0
  __int64 v32; // x0
  unsigned int v33; // w0
  __int64 v34; // x0
  __int64 v35; // x0
  __int16 v36; // w8
  __int64 v37; // x0
  int v38; // w8
  unsigned __int16 v39; // w10
  int v40; // [xsp+4h] [xbp-DCh] BYREF
  __int64 v41; // [xsp+8h] [xbp-D8h] BYREF
  __int64 v42; // [xsp+10h] [xbp-D0h] BYREF
  __int64 (__fastcall *v43)(); // [xsp+18h] [xbp-C8h] BYREF
  __int64 (__fastcall *v44)(); // [xsp+20h] [xbp-C0h]
  __int64 v45; // [xsp+28h] [xbp-B8h]
  __int64 v46; // [xsp+30h] [xbp-B0h]
  char **v47; // [xsp+38h] [xbp-A8h]
  __int64 v48; // [xsp+40h] [xbp-A0h]
  __int64 (__fastcall *v49)(); // [xsp+48h] [xbp-98h]
  __int64 (__fastcall *v50)(); // [xsp+50h] [xbp-90h]
  __int64 (__fastcall *v51)(); // [xsp+58h] [xbp-88h]
  __int64 (__fastcall *v52)(); // [xsp+60h] [xbp-80h]
  __int64 v53; // [xsp+68h] [xbp-78h]
  __int64 v54; // [xsp+70h] [xbp-70h]
  __int64 v55; // [xsp+78h] [xbp-68h]
  __int64 v56; // [xsp+80h] [xbp-60h]
  __int64 v57; // [xsp+88h] [xbp-58h] BYREF
  __int64 v58; // [xsp+90h] [xbp-50h]
  __int64 v59; // [xsp+98h] [xbp-48h]
  __int64 v60; // [xsp+A0h] [xbp-40h]
  __int64 v61; // [xsp+A8h] [xbp-38h]
  __int64 v62; // [xsp+B0h] [xbp-30h]
  __int64 v63; // [xsp+B8h] [xbp-28h]
  __int64 v64; // [xsp+C0h] [xbp-20h]
  __int64 v65; // [xsp+C8h] [xbp-18h]
  __int64 v66; // [xsp+D0h] [xbp-10h]
  __int64 v67; // [xsp+D8h] [xbp-8h]

  v1 = a1 + 16;
  v67 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v55 = 0;
  v56 = 0;
  v53 = 0;
  v54 = 0;
  v51 = nullptr;
  v52 = nullptr;
  v49 = nullptr;
  v50 = nullptr;
  v47 = nullptr;
  v48 = 0;
  v45 = 0;
  v46 = 0;
  v43 = nullptr;
  v44 = nullptr;
  v41 = 0;
  v42 = 0;
  v40 = 0;
  v3 = devm_kmalloc(a1 + 16, 1592, 3520);
  if ( !v3 )
    goto LABEL_78;
  v4 = (_QWORD *)v3;
  v5 = *(_QWORD *)(a1 + 760);
  *v4 = v1;
  variable_u32_array = of_property_read_variable_u32_array(v5, "reg", (char *)&v42 + 4, 1, 0);
  if ( (variable_u32_array & 0x80000000) != 0 )
  {
    v13 = variable_u32_array;
    dev_err(v1, "%s: could not find %s entry in dt\n", "lpass_cdc_va_macro_probe", "reg");
    goto LABEL_79;
  }
  v7 = *(_QWORD *)(a1 + 760);
  v4[165] = 0;
  v4[166] = 0x2000200020002LL;
  if ( !of_find_property(v7, "qcom,va-dmic-clk-div-factor", &v42) )
  {
    dev_err(v1, "%s: could not find clk_div_factor entry in dt\n", "lpass_cdc_va_macro_probe");
    goto LABEL_69;
  }
  v8 = v42;
  v9 = devm_kmalloc(v1, (unsigned int)v42, 3520);
  if ( !v9 )
    goto LABEL_78;
  v10 = (int *)v9;
  if ( (of_property_read_variable_u32_array(
          *(_QWORD *)(a1 + 760),
          "qcom,va-dmic-clk-div-factor",
          v9,
          (unsigned __int64)(unsigned int)v42 >> 2,
          0)
      & 0x80000000) != 0 )
    goto LABEL_69;
  if ( v8 < 4 )
    goto LABEL_186;
  v11 = *v10;
  if ( *v10 > 5 )
  {
    switch ( v11 )
    {
      case 6:
        v12 = 3;
        goto LABEL_21;
      case 8:
        v12 = 4;
        goto LABEL_21;
      case 16:
        v12 = 5;
        goto LABEL_21;
    }
  }
  else
  {
    switch ( v11 )
    {
      case 2:
        *((_WORD *)v4 + 660) = 0;
        goto LABEL_22;
      case 3:
        v12 = 1;
        goto LABEL_21;
      case 4:
        v12 = 2;
LABEL_21:
        *((_WORD *)v4 + 660) = v12;
        goto LABEL_22;
    }
  }
  dev_err(
    *v4,
    "%s: Invalid div_factor %d mic_pair %d, is_override %d\n",
    "lpass_cdc_va_macro_update_clk_div_factor",
    v11,
    0,
    0);
LABEL_22:
  if ( (v8 & 0xFFFFFFFC) == 4 )
    goto LABEL_186;
  v11 = v10[1];
  if ( v11 > 5 )
  {
    switch ( v11 )
    {
      case 6:
        v14 = 3;
        break;
      case 8:
        v14 = 4;
        break;
      case 16:
        v14 = 5;
        break;
      default:
        goto LABEL_177;
    }
  }
  else
  {
    if ( v11 == 2 )
    {
      *((_WORD *)v4 + 661) = 0;
      if ( v8 < 8 )
        goto LABEL_186;
      goto LABEL_38;
    }
    if ( v11 != 3 )
    {
      if ( v11 == 4 )
      {
        v14 = 2;
        goto LABEL_37;
      }
LABEL_177:
      dev_err(
        *v4,
        "%s: Invalid div_factor %d mic_pair %d, is_override %d\n",
        "lpass_cdc_va_macro_update_clk_div_factor",
        v11,
        1,
        0);
      if ( v8 < 8 )
        goto LABEL_186;
      goto LABEL_38;
    }
    v14 = 1;
  }
LABEL_37:
  *((_WORD *)v4 + 661) = v14;
  if ( v8 < 8 )
    goto LABEL_186;
LABEL_38:
  if ( (v8 & 0xFFFFFFFC) == 8 )
    goto LABEL_186;
  v11 = v10[2];
  if ( v11 <= 5 )
  {
    if ( v11 == 2 )
    {
      *((_WORD *)v4 + 662) = 0;
      if ( v8 < 0xC )
        goto LABEL_186;
      goto LABEL_54;
    }
    if ( v11 != 3 )
    {
      if ( v11 == 4 )
      {
        v15 = 2;
        goto LABEL_53;
      }
      goto LABEL_179;
    }
    v15 = 1;
LABEL_53:
    *((_WORD *)v4 + 662) = v15;
    if ( v8 < 0xC )
      goto LABEL_186;
    goto LABEL_54;
  }
  switch ( v11 )
  {
    case 6:
      v15 = 3;
      goto LABEL_53;
    case 8:
      v15 = 4;
      goto LABEL_53;
    case 16:
      v15 = 5;
      goto LABEL_53;
  }
LABEL_179:
  dev_err(
    *v4,
    "%s: Invalid div_factor %d mic_pair %d, is_override %d\n",
    "lpass_cdc_va_macro_update_clk_div_factor",
    v11,
    2,
    0);
  if ( v8 < 0xC )
    goto LABEL_186;
LABEL_54:
  if ( (v8 & 0xFFFFFFFC) == 0xC )
    goto LABEL_186;
  v16 = v10[3];
  if ( v16 > 5 )
  {
    switch ( v16 )
    {
      case 6:
        *((_WORD *)v4 + 663) = 3;
        goto LABEL_69;
      case 8:
        *((_WORD *)v4 + 663) = 4;
        goto LABEL_69;
      case 16:
        *((_WORD *)v4 + 663) = 5;
        goto LABEL_69;
    }
  }
  else
  {
    switch ( v16 )
    {
      case 2:
        *((_WORD *)v4 + 663) = 0;
        goto LABEL_69;
      case 3:
        *((_WORD *)v4 + 663) = 1;
        goto LABEL_69;
      case 4:
        *((_WORD *)v4 + 663) = 2;
        goto LABEL_69;
    }
  }
  dev_err(
    *v4,
    "%s: Invalid div_factor %d mic_pair %d, is_override %d\n",
    "lpass_cdc_va_macro_update_clk_div_factor",
    v16,
    3,
    0);
LABEL_69:
  if ( !of_find_property(*(_QWORD *)(a1 + 760), "qcom,va-dmic-override-clk-div-factor", &v42) )
  {
    dev_err(v1, "%s: could not find override_clk_div_factor entry in dt\n", "lpass_cdc_va_macro_probe");
    goto LABEL_136;
  }
  v17 = v42;
  v18 = devm_kmalloc(v1, (unsigned int)v42, 3520);
  if ( !v18 )
  {
LABEL_78:
    v13 = -12;
    goto LABEL_79;
  }
  v19 = (int *)v18;
  if ( (of_property_read_variable_u32_array(
          *(_QWORD *)(a1 + 760),
          "qcom,va-dmic-override-clk-div-factor",
          v18,
          (unsigned __int64)(unsigned int)v42 >> 2,
          0)
      & 0x80000000) == 0 )
  {
    if ( v17 < 4 )
      goto LABEL_186;
    v11 = *v19;
    if ( *v19 > 5 )
    {
      switch ( v11 )
      {
        case 6:
          v20 = 3;
          goto LABEL_88;
        case 8:
          v20 = 4;
          goto LABEL_88;
        case 16:
          v20 = 5;
          goto LABEL_88;
      }
    }
    else
    {
      switch ( v11 )
      {
        case 2:
          *((_WORD *)v4 + 664) = 0;
          goto LABEL_89;
        case 3:
          v20 = 1;
          goto LABEL_88;
        case 4:
          v20 = 2;
LABEL_88:
          *((_WORD *)v4 + 664) = v20;
          goto LABEL_89;
      }
    }
    dev_err(
      *v4,
      "%s: Invalid div_factor %d mic_pair %d, is_override %d\n",
      "lpass_cdc_va_macro_update_clk_div_factor",
      v11,
      0,
      1);
LABEL_89:
    if ( (v17 & 0xFFFFFFFC) == 4 )
      goto LABEL_186;
    v11 = v19[1];
    if ( v11 > 5 )
    {
      switch ( v11 )
      {
        case 6:
          v22 = 3;
          break;
        case 8:
          v22 = 4;
          break;
        case 16:
          v22 = 5;
          break;
        default:
          goto LABEL_183;
      }
    }
    else
    {
      if ( v11 == 2 )
      {
        *((_WORD *)v4 + 665) = 0;
        if ( v17 < 8 )
          goto LABEL_186;
        goto LABEL_105;
      }
      if ( v11 != 3 )
      {
        if ( v11 == 4 )
        {
          v22 = 2;
          goto LABEL_104;
        }
LABEL_183:
        dev_err(
          *v4,
          "%s: Invalid div_factor %d mic_pair %d, is_override %d\n",
          "lpass_cdc_va_macro_update_clk_div_factor",
          v11,
          1,
          1);
        if ( v17 < 8 )
          goto LABEL_186;
        goto LABEL_105;
      }
      v22 = 1;
    }
LABEL_104:
    *((_WORD *)v4 + 665) = v22;
    if ( v17 < 8 )
      goto LABEL_186;
LABEL_105:
    if ( (v17 & 0xFFFFFFFC) == 8 )
      goto LABEL_186;
    v11 = v19[2];
    if ( v11 > 5 )
    {
      switch ( v11 )
      {
        case 6:
          v23 = 3;
          break;
        case 8:
          v23 = 4;
          break;
        case 16:
          v23 = 5;
          break;
        default:
LABEL_185:
          dev_err(
            *v4,
            "%s: Invalid div_factor %d mic_pair %d, is_override %d\n",
            "lpass_cdc_va_macro_update_clk_div_factor",
            v11,
            2,
            1);
          if ( v17 < 0xC )
            goto LABEL_186;
          goto LABEL_121;
      }
    }
    else
    {
      if ( v11 == 2 )
      {
        *((_WORD *)v4 + 666) = 0;
        if ( v17 < 0xC )
          goto LABEL_186;
LABEL_121:
        if ( (v17 & 0xFFFFFFFC) != 0xC )
        {
          v11 = v19[3];
          if ( v11 > 5 )
          {
            switch ( v11 )
            {
              case 6:
                *((_WORD *)v4 + 667) = 3;
                goto LABEL_136;
              case 8:
                *((_WORD *)v4 + 667) = 4;
                goto LABEL_136;
              case 16:
                *((_WORD *)v4 + 667) = 5;
                goto LABEL_136;
            }
          }
          else
          {
            switch ( v11 )
            {
              case 2:
                *((_WORD *)v4 + 667) = 0;
                goto LABEL_136;
              case 3:
                *((_WORD *)v4 + 667) = 1;
                goto LABEL_136;
              case 4:
                *((_WORD *)v4 + 667) = 2;
                goto LABEL_136;
            }
          }
LABEL_187:
          dev_err(
            *v4,
            "%s: Invalid div_factor %d mic_pair %d, is_override %d\n",
            "lpass_cdc_va_macro_update_clk_div_factor",
            v11,
            3,
            1);
          goto LABEL_136;
        }
LABEL_186:
        __break(1u);
        goto LABEL_187;
      }
      if ( v11 != 3 )
      {
        if ( v11 == 4 )
        {
          v23 = 2;
          goto LABEL_120;
        }
        goto LABEL_185;
      }
      v23 = 1;
    }
LABEL_120:
    *((_WORD *)v4 + 666) = v23;
    if ( v17 < 0xC )
      goto LABEL_186;
    goto LABEL_121;
  }
LABEL_136:
  if ( of_find_property(*(_QWORD *)(a1 + 760), "qcom,is-used-swr-gpio", 0)
    && (of_property_read_variable_u32_array(*(_QWORD *)(a1 + 760), "qcom,is-used-swr-gpio", &v40, 1, 0) & 0x80000000) != 0 )
  {
    dev_err(v1, "%s: error reading %s in dt\n", "lpass_cdc_va_macro_probe", "qcom,is-used-swr-gpio");
    v40 = 0;
  }
  v24 = *(_QWORD *)(a1 + 760);
  v65 = 0;
  v66 = 0;
  v63 = 0;
  v64 = 0;
  v61 = 0;
  v62 = 0;
  v59 = 0;
  v60 = 0;
  v57 = 0;
  v58 = 0;
  if ( (unsigned int)_of_parse_phandle_with_args(v24, "qcom,va-swr-gpios", 0, 0, 0, &v57) )
    v25 = 0;
  else
    v25 = v57;
  v4[169] = v25;
  if ( !v25 && v40 )
  {
    dev_err(v1, "%s: swr_gpios handle not provided!\n", "lpass_cdc_va_macro_probe");
LABEL_170:
    v13 = -22;
    goto LABEL_79;
  }
  if ( (msm_cdc_pinctrl_get_state() & 0x80000000) != 0 && v40 )
  {
    dev_err(v1, "%s: failed to get swr pin state\n", "lpass_cdc_va_macro_probe");
    v13 = -517;
    goto LABEL_79;
  }
  v26 = devm_ioremap(v1, HIDWORD(v42), 4096);
  if ( !v26 )
  {
    dev_err(v1, "%s: ioremap failed\n", "lpass_cdc_va_macro_probe");
    goto LABEL_170;
  }
  v27 = v26;
  v4[183] = v26;
  v28 = devm_clk_get(v1, "lpass_audio_hw_vote");
  if ( v28 <= 0xFFFFFFFFFFFFF000LL )
    v29 = v28;
  else
    v29 = 0;
  v30 = *(_QWORD *)(a1 + 760);
  v65 = 0;
  v66 = 0;
  v4[2] = v29;
  v63 = 0;
  v64 = 0;
  v61 = 0;
  v62 = 0;
  v59 = 0;
  v60 = 0;
  v57 = 0;
  v58 = 0;
  if ( !(unsigned int)_of_parse_phandle_with_args(v30, "va-vdd-micb-supply", 0, 0, 0, &v57) && v57 )
  {
    v31 = devm_regulator_get(v1, "va-vdd-micb");
    v4[188] = v31;
    if ( v31 >= 0xFFFFFFFFFFFFF001LL )
    {
      v13 = v31;
      dev_err(v1, "%s:Failed to get micbias supply for VA Mic %d\n", "lpass_cdc_va_macro_probe", v31);
      goto LABEL_79;
    }
    v13 = of_property_read_variable_u32_array(*(_QWORD *)(a1 + 760), "qcom,va-vdd-micb-voltage", v4 + 189, 1, 0);
    v32 = *(_QWORD *)(a1 + 760);
    if ( (v13 & 0x80000000) != 0 )
    {
      dev_err(
        v1,
        "%s:Looking up %s property in node %s failed\n",
        "lpass_cdc_va_macro_probe",
        "qcom,va-vdd-micb-voltage",
        *(const char **)(v32 + 16));
      goto LABEL_79;
    }
    v33 = of_property_read_variable_u32_array(v32, "qcom,va-vdd-micb-current", (char *)v4 + 1516, 1, 0);
    if ( (v33 & 0x80000000) != 0 )
    {
      v13 = v33;
      dev_err(
        a1 + 16,
        "%s:Looking up %s property in node %s failed\n",
        "lpass_cdc_va_macro_probe",
        "qcom,va-vdd-micb-current",
        *(const char **)(*(_QWORD *)(a1 + 760) + 16LL));
      goto LABEL_79;
    }
  }
  v34 = *(_QWORD *)(a1 + 760);
  LODWORD(v41) = 3;
  if ( of_find_property(v34, "qcom,use-clk-id", 0)
    && (of_property_read_variable_u32_array(*(_QWORD *)(a1 + 760), "qcom,use-clk-id", &v41, 1, 0) & 0x80000000) != 0 )
  {
    LODWORD(v41) = 3;
  }
  v35 = *(_QWORD *)(a1 + 760);
  *((_WORD *)v4 + 767) = v41;
  if ( (of_property_read_variable_u32_array(v35, "qcom,default-clk-id", (char *)&v41 + 4, 1, 0) & 0x80000000) != 0 )
  {
    dev_err(v1, "%s: could not find %s entry in dt\n", "lpass_cdc_va_macro_probe", "qcom,default-clk-id");
    v36 = v41;
    HIDWORD(v41) = v41;
  }
  else
  {
    v36 = WORD2(v41);
  }
  v37 = *(_QWORD *)(a1 + 760);
  *((_WORD *)v4 + 766) = v36;
  *((_WORD *)v4 + 788) = 0;
  *((_DWORD *)v4 + 396) = 0;
  *((_BYTE *)v4 + 1581) = 0;
  if ( of_find_property(v37, "use-lpi-control", 0) )
    *((_BYTE *)v4 + 1581) = 1;
  v38 = v40;
  if ( v40 )
  {
    *((_BYTE *)v4 + 1344) = 1;
    v4[178] = 0xFFFFFFFE00000LL;
    v4[179] = v4 + 179;
    v4[180] = v4 + 179;
    v4[181] = lpass_cdc_va_macro_add_child_devices;
    v4[175] = lpass_cdc_va_macro_swrm_clock;
    v4[171] = v4;
    v4[172] = 0;
    v4[173] = 0;
    v4[174] = 0;
    v4[176] = lpass_cdc_va_macro_core_vote;
    v4[177] = 0;
    _mutex_init(v4 + 9, "&va_priv->swr_clk_lock", &lpass_cdc_va_macro_probe___key_24);
    v38 = v40;
  }
  *((_DWORD *)v4 + 381) = v38;
  *((_BYTE *)v4 + 1579) = 1;
  _mutex_init(v4 + 3, "&va_priv->mclk_lock", &lpass_cdc_va_macro_probe___key_26);
  _mutex_init(v4 + 15, "&va_priv->wlock", &lpass_cdc_va_macro_probe___key_28);
  v46 = 0;
  v47 = &lpass_cdc_va_macro_dai;
  v48 = 0;
  v45 = 3;
  v43 = lpass_cdc_va_macro_init;
  v44 = lpass_cdc_va_macro_deinit;
  v49 = lpass_cdc_va_macro_event_handler;
  v50 = lpass_cdc_va_macro_reg_wake_irq;
  v39 = *((_WORD *)v4 + 766);
  *(_QWORD *)(a1 + 168) = v4;
  v53 = 0;
  v54 = 0;
  v55 = v27;
  v51 = lpass_cdc_va_macro_set_port_map;
  v52 = lpass_cdc_va_macro_clk_div_get;
  v56 = v39;
  WORD1(v56) = v39;
  v13 = lpass_cdc_register_macro(v1, 3, &v43);
  if ( (v13 & 0x80000000) != 0 )
  {
    dev_err(v1, "%s: register macro failed\n", "lpass_cdc_va_macro_probe");
  }
  else
  {
    pm_runtime_set_autosuspend_delay(v1, 100);
    _pm_runtime_use_autosuspend(v1, 1);
    _pm_runtime_set_status(v1, 2);
    *(_WORD *)(a1 + 504) |= 0x100u;
    pm_runtime_enable(v1);
    if ( v40 )
      queue_work_on(32, system_wq, v4 + 178);
  }
LABEL_79:
  _ReadStatusReg(SP_EL0);
  return v13;
}
