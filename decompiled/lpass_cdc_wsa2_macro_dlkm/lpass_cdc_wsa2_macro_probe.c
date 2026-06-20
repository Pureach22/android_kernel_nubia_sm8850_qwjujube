__int64 __fastcall lpass_cdc_wsa2_macro_probe(__int64 a1)
{
  __int64 v1; // x19
  __int64 v3; // x0
  __int64 v4; // x21
  __int64 v5; // x0
  unsigned int variable_u32_array; // w0
  __int64 v7; // x1
  __int64 v8; // x0
  __int64 v9; // x0
  __int64 v10; // x0
  __int64 v11; // x22
  __int64 v12; // x0
  __int64 v13; // x0
  __int64 v14; // x0
  __int64 v15; // x0
  __int16 v16; // w8
  unsigned __int16 v17; // w9
  unsigned int v18; // w0
  int v19; // w8
  __int64 v20; // x9
  unsigned __int64 v21; // x0
  int v22; // w0
  unsigned int v23; // w22
  __int64 result; // x0
  unsigned int v25; // w20
  const char *v26; // x1
  const char *v27; // x1
  const char *v28; // x1
  unsigned int v29; // w20
  unsigned int v30; // [xsp+4h] [xbp-DCh] BYREF
  int v31; // [xsp+8h] [xbp-D8h] BYREF
  int v32; // [xsp+Ch] [xbp-D4h] BYREF
  __int64 v33; // [xsp+10h] [xbp-D0h] BYREF
  void *v34; // [xsp+18h] [xbp-C8h] BYREF
  __int64 (__fastcall *v35)(); // [xsp+20h] [xbp-C0h]
  __int64 v36; // [xsp+28h] [xbp-B8h]
  __int64 v37; // [xsp+30h] [xbp-B0h]
  char **v38; // [xsp+38h] [xbp-A8h]
  __int64 v39; // [xsp+40h] [xbp-A0h]
  __int64 (__fastcall *v40)(); // [xsp+48h] [xbp-98h]
  __int64 v41; // [xsp+50h] [xbp-90h]
  __int64 (__fastcall *v42)(); // [xsp+58h] [xbp-88h]
  __int64 v43; // [xsp+60h] [xbp-80h]
  __int64 v44; // [xsp+68h] [xbp-78h]
  __int64 v45; // [xsp+70h] [xbp-70h]
  __int64 v46; // [xsp+78h] [xbp-68h]
  __int64 v47; // [xsp+80h] [xbp-60h]
  _QWORD v48[11]; // [xsp+88h] [xbp-58h] BYREF

  v1 = a1 + 16;
  v48[10] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v46 = 0;
  v47 = 0;
  v44 = 0;
  v45 = 0;
  v42 = nullptr;
  v43 = 0;
  v40 = nullptr;
  v41 = 0;
  v38 = nullptr;
  v39 = 0;
  v36 = 0;
  v37 = 0;
  v34 = nullptr;
  v35 = nullptr;
  v33 = 0;
  v31 = 1;
  v32 = 0;
  v30 = 0;
  if ( (lpass_cdc_is_va_macro_registered(a1 + 16) & 1) == 0 )
  {
    dev_err(v1, "%s: va-macro not registered yet, defer\n", "lpass_cdc_wsa2_macro_probe");
LABEL_43:
    result = 4294966779LL;
    goto LABEL_57;
  }
  v3 = devm_kmalloc(v1, 672, 3520);
  if ( !v3 )
  {
    result = 4294967284LL;
    goto LABEL_57;
  }
  v4 = v3;
  v5 = *(_QWORD *)(a1 + 760);
  *(_BYTE *)(v4 + 648) = 1;
  *(_QWORD *)v4 = v1;
  variable_u32_array = of_property_read_variable_u32_array(v5, "reg", (char *)&v33 + 4, 1, 0);
  if ( (variable_u32_array & 0x80000000) != 0 )
  {
    v25 = variable_u32_array;
    dev_err(v1, "%s: could not find %s entry in dt\n", "lpass_cdc_wsa2_macro_probe", "reg");
    result = v25;
    goto LABEL_57;
  }
  of_property_read_variable_u32_array(*(_QWORD *)(a1 + 760), "wsa_data_fs_ctl_reg", v4 + 636, 1, 0);
  if ( !*(_QWORD *)(v4 + 656) )
  {
    v7 = *(unsigned int *)(v4 + 636);
    if ( (_DWORD)v7 )
      *(_QWORD *)(v4 + 656) = devm_ioremap(v1, v7, 4096);
  }
  if ( of_find_property(*(_QWORD *)(a1 + 760), "qcom,is-used-swr-gpio", 0)
    && (of_property_read_variable_u32_array(*(_QWORD *)(a1 + 760), "qcom,is-used-swr-gpio", &v31, 1, 0) & 0x80000000) != 0 )
  {
    dev_err(v1, "%s: error reading %s in dt\n", "lpass_cdc_wsa2_macro_probe", "qcom,is-used-swr-gpio");
    v31 = 1;
  }
  v8 = *(_QWORD *)(a1 + 760);
  memset(v48, 0, 80);
  if ( (unsigned int)_of_parse_phandle_with_args(v8, "qcom,wsa2-swr-gpios", 0, 0, 0, v48) )
    v9 = 0;
  else
    v9 = v48[0];
  *(_QWORD *)(v4 + 240) = v9;
  if ( !v9 && v31 )
  {
    dev_err(v1, "%s: swr_gpios handle not provided!\n", "lpass_cdc_wsa2_macro_probe");
LABEL_45:
    result = 4294967274LL;
    goto LABEL_57;
  }
  if ( (msm_cdc_pinctrl_get_state() & 0x80000000) != 0 && v31 )
  {
    dev_err(v1, "%s: failed to get swr pin state\n", "lpass_cdc_wsa2_macro_probe");
    goto LABEL_43;
  }
  msm_cdc_pinctrl_set_wakeup_capable(*(_QWORD *)(v4 + 240), 0);
  v10 = devm_ioremap(v1, HIDWORD(v33), 4096);
  if ( !v10 )
  {
    dev_err(v1, "%s: ioremap failed\n", "lpass_cdc_wsa2_macro_probe");
    goto LABEL_45;
  }
  v11 = v10;
  v12 = *(_QWORD *)(a1 + 760);
  LODWORD(v48[0]) = 0;
  if ( of_find_property(v12, "qcom,wsa-rloads", v48) )
  {
    if ( (v48[0] & 0xFFFFFFFC) == 8 )
    {
      if ( (of_property_read_variable_u32_array(*(_QWORD *)(a1 + 760), "qcom,wsa-rloads", v4 + 628, 2, 0) & 0x80000000) == 0 )
        goto LABEL_21;
      v26 = "%s: Failed to read %s\n";
    }
    else
    {
      v26 = "%s: invalid number of %s\n";
    }
  }
  else
  {
    v26 = "%s: missing %s\n";
  }
  dev_info(v1, v26, "lpass_cdc_wsa2_macro_read_array", "qcom,wsa-rloads");
LABEL_21:
  v13 = *(_QWORD *)(a1 + 760);
  LODWORD(v48[0]) = 0;
  if ( of_find_property(v13, "qcom,wsa-system-gains", v48) )
  {
    if ( (v48[0] & 0xFFFFFFFC) == 0x10 )
    {
      if ( (of_property_read_variable_u32_array(*(_QWORD *)(a1 + 760), "qcom,wsa-system-gains", v4 + 604, 4, 0)
          & 0x80000000) == 0 )
        goto LABEL_24;
      v27 = "%s: Failed to read %s\n";
    }
    else
    {
      v27 = "%s: invalid number of %s\n";
    }
  }
  else
  {
    v27 = "%s: missing %s\n";
  }
  dev_info(v1, v27, "lpass_cdc_wsa2_macro_read_array", "qcom,wsa-system-gains");
LABEL_24:
  v14 = *(_QWORD *)(a1 + 760);
  LODWORD(v48[0]) = 0;
  if ( !of_find_property(v14, "qcom,wsa-bat-cfgs", v48) )
  {
    v28 = "%s: missing %s\n";
LABEL_63:
    dev_info(v1, v28, "lpass_cdc_wsa2_macro_read_array", "qcom,wsa-bat-cfgs");
    goto LABEL_27;
  }
  if ( (v48[0] & 0xFFFFFFFC) != 8 )
  {
    v28 = "%s: invalid number of %s\n";
    goto LABEL_63;
  }
  if ( (of_property_read_variable_u32_array(*(_QWORD *)(a1 + 760), "qcom,wsa-bat-cfgs", v4 + 620, 2, 0) & 0x80000000) != 0 )
  {
    v28 = "%s: Failed to read %s\n";
    goto LABEL_63;
  }
LABEL_27:
  *(_BYTE *)(v4 + 41) = 1;
  *(_QWORD *)(v4 + 432) = v11;
  *(_QWORD *)(v4 + 208) = 0xFFFFFFFE00000LL;
  *(_QWORD *)(v4 + 216) = v4 + 216;
  *(_QWORD *)(v4 + 224) = v4 + 216;
  *(_QWORD *)(v4 + 232) = lpass_cdc_wsa2_macro_add_child_devices;
  *(_QWORD *)(v4 + 568) = 0xFFFFFFFE00000LL;
  *(_QWORD *)(v4 + 576) = v4 + 576;
  *(_QWORD *)(v4 + 584) = v4 + 576;
  v15 = *(_QWORD *)(a1 + 760);
  *(_QWORD *)(v4 + 592) = lpass_cdc_wsa2_macro_cooling_adjust_gain;
  *(_QWORD *)(v4 + 152) = v4;
  *(_QWORD *)(v4 + 160) = 0;
  *(_QWORD *)(v4 + 168) = 0;
  *(_QWORD *)(v4 + 176) = 0;
  *(_QWORD *)(v4 + 184) = wsa2_swrm_clock;
  *(_QWORD *)(v4 + 192) = lpass_cdc_wsa2_macro_core_vote;
  *(_QWORD *)(v4 + 200) = 0;
  if ( (of_property_read_variable_u32_array(v15, "qcom,default-clk-id", &v33, 1, 0) & 0x80000000) != 0 )
  {
    dev_err(v1, "%s: could not find %s entry in dt\n", "lpass_cdc_wsa2_macro_probe", "qcom,mux0-clk-id");
    v16 = 4;
    LODWORD(v33) = 4;
  }
  else
  {
    v16 = v33;
  }
  *(_WORD *)(v4 + 504) = v16;
  *(_QWORD *)(a1 + 168) = v4;
  _mutex_init(v4 + 48, "&wsa2_priv->mclk_lock", &lpass_cdc_wsa2_macro_probe___key_18);
  _mutex_init(v4 + 96, "&wsa2_priv->swr_clk_lock", &lpass_cdc_wsa2_macro_probe___key_20);
  v36 = 0;
  v37 = 0;
  v34 = &lpass_cdc_wsa2_macro_init;
  v35 = lpass_cdc_wsa2_macro_deinit;
  v38 = &lpass_cdc_wsa2_macro_dai;
  v39 = 0;
  v17 = *(_WORD *)(v4 + 504);
  LOWORD(v36) = 6;
  v40 = lpass_cdc_wsa2_macro_event_handler;
  v41 = 0;
  v44 = 0;
  v45 = 0;
  v46 = v11;
  v42 = lpass_cdc_wsa2_macro_set_port_map;
  v43 = 0;
  v47 = v17;
  WORD1(v47) = v17;
  v18 = lpass_cdc_register_macro(v1, 4, &v34);
  if ( (v18 & 0x80000000) == 0 )
  {
    if ( of_find_property(*(_QWORD *)(*(_QWORD *)v4 + 744LL), "#cooling-cells", 0) )
    {
      if ( (of_property_read_variable_u32_array(*(_QWORD *)(a1 + 760), "qcom,thermal-max-state", &v32, 1, 0) & 0x80000000) != 0 )
      {
        dev_info(v1, "%s: could not find %s entry in dt\n", "lpass_cdc_wsa2_macro_probe", "qcom,thermal-max-state");
        v19 = 11;
      }
      else
      {
        v19 = v32;
      }
      v20 = *(_QWORD *)v4;
      *(_DWORD *)(v4 + 564) = v19;
      v21 = devm_thermal_of_cooling_device_register(v1, *(_QWORD *)(v20 + 744), "wsa2", v4, wsa2_cooling_ops);
      *(_QWORD *)(v4 + 552) = v21;
      if ( v21 >= 0xFFFFFFFFFFFFF001LL )
      {
        dev_err(v1, "%s: failed to register wsa2 macro as cooling device\n", "lpass_cdc_wsa2_macro_probe");
        *(_QWORD *)(v4 + 552) = 0;
      }
    }
    v22 = of_property_read_variable_u32_array(*(_QWORD *)(a1 + 760), "qcom,noise-gate-mode", &v30, 1, 0);
    v23 = v22 & (v22 >> 31);
    if ( v22 < 0 )
    {
      dev_info(v1, "%s: could not find %s entry in dt\n", "lpass_cdc_wsa2_macro_probe", "qcom,noise-gate-mode");
    }
    else if ( v30 <= 3 )
    {
      *(_DWORD *)(v4 + 644) = v30;
LABEL_56:
      pm_runtime_set_autosuspend_delay(v1, 50);
      _pm_runtime_use_autosuspend(v1, 1);
      _pm_runtime_set_status(v1, 2);
      *(_WORD *)(a1 + 504) |= 0x100u;
      pm_runtime_enable(v1);
      queue_work_on(32, system_wq, v4 + 208);
      result = v23;
      goto LABEL_57;
    }
    *(_DWORD *)(v4 + 644) = 0;
    goto LABEL_56;
  }
  v29 = v18;
  dev_err(v1, "%s: register macro failed\n", "lpass_cdc_wsa2_macro_probe");
  result = v29;
LABEL_57:
  _ReadStatusReg(SP_EL0);
  return result;
}
