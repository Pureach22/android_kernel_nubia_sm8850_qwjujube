__int64 __fastcall lpass_cdc_rx_macro_probe(__int64 a1)
{
  __int64 v1; // x19
  __int64 v3; // x0
  __int64 v4; // x21
  __int64 v5; // x0
  unsigned int variable_u32_array; // w0
  __int64 v7; // x0
  __int64 v8; // x0
  __int64 v9; // x0
  __int64 v10; // x1
  __int64 v11; // x22
  __int64 v12; // x0
  __int16 v13; // w8
  unsigned __int64 v14; // x0
  unsigned __int64 v15; // x8
  unsigned int v16; // w0
  __int64 result; // x0
  unsigned int v18; // w20
  unsigned int v19; // w20
  int v20; // [xsp+8h] [xbp-D8h] BYREF
  int v21; // [xsp+Ch] [xbp-D4h] BYREF
  __int64 v22; // [xsp+10h] [xbp-D0h] BYREF
  __int64 (__fastcall *v23)(); // [xsp+18h] [xbp-C8h] BYREF
  __int64 (__fastcall *v24)(); // [xsp+20h] [xbp-C0h]
  __int64 v25; // [xsp+28h] [xbp-B8h]
  __int64 v26; // [xsp+30h] [xbp-B0h]
  char **v27; // [xsp+38h] [xbp-A8h]
  __int64 v28; // [xsp+40h] [xbp-A0h]
  void *v29; // [xsp+48h] [xbp-98h]
  __int64 v30; // [xsp+50h] [xbp-90h]
  __int64 (__fastcall *v31)(); // [xsp+58h] [xbp-88h]
  __int64 v32; // [xsp+60h] [xbp-80h]
  __int64 v33; // [xsp+68h] [xbp-78h]
  __int64 v34; // [xsp+70h] [xbp-70h]
  __int64 v35; // [xsp+78h] [xbp-68h]
  __int64 v36; // [xsp+80h] [xbp-60h]
  _QWORD v37[11]; // [xsp+88h] [xbp-58h] BYREF

  v1 = a1 + 16;
  v37[10] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v35 = 0;
  v36 = 0;
  v33 = 0;
  v34 = 0;
  v31 = nullptr;
  v32 = 0;
  v29 = nullptr;
  v30 = 0;
  v27 = nullptr;
  v28 = 0;
  v25 = 0;
  v26 = 0;
  v23 = nullptr;
  v24 = nullptr;
  v22 = 0;
  v20 = 1;
  v21 = 0;
  if ( (lpass_cdc_is_va_macro_registered(a1 + 16) & 1) == 0 )
  {
    dev_err(v1, "%s: va-macro not registered yet, defer\n", "lpass_cdc_rx_macro_probe");
LABEL_28:
    result = 4294966779LL;
    goto LABEL_32;
  }
  v3 = devm_kmalloc(v1, 2360, 3520);
  if ( !v3 )
  {
LABEL_31:
    result = 4294967284LL;
    goto LABEL_32;
  }
  v4 = v3;
  v5 = *(_QWORD *)(a1 + 760);
  *(_BYTE *)(v4 + 95) = 1;
  *(_QWORD *)v4 = v1;
  variable_u32_array = of_property_read_variable_u32_array(v5, "reg", (char *)&v22 + 4, 1, 0);
  if ( (variable_u32_array & 0x80000000) != 0
    || (variable_u32_array = of_property_read_variable_u32_array(
                               *(_QWORD *)(a1 + 760),
                               "qcom,rx_mclk_mode_muxsel",
                               &v22,
                               1,
                               0),
        (variable_u32_array & 0x80000000) != 0) )
  {
    v18 = variable_u32_array;
    dev_err(v1, "%s: could not find %s entry in dt\n", "lpass_cdc_rx_macro_probe");
    result = v18;
    goto LABEL_32;
  }
  if ( (of_property_read_variable_u32_array(*(_QWORD *)(a1 + 760), "qcom,default-clk-id", &v21, 1, 0) & 0x80000000) != 0 )
  {
    dev_err(v1, "%s: could not find %s entry in dt\n", "lpass_cdc_rx_macro_probe", "qcom,default-clk-id");
    v21 = 1;
  }
  if ( of_find_property(*(_QWORD *)(a1 + 760), "qcom,is-used-swr-gpio", 0)
    && (of_property_read_variable_u32_array(*(_QWORD *)(a1 + 760), "qcom,is-used-swr-gpio", &v20, 1, 0) & 0x80000000) != 0 )
  {
    dev_err(v1, "%s: error reading %s in dt\n", "lpass_cdc_rx_macro_probe", "qcom,is-used-swr-gpio");
    v20 = 1;
  }
  v7 = *(_QWORD *)(a1 + 760);
  memset(v37, 0, 80);
  if ( (unsigned int)_of_parse_phandle_with_args(v7, "qcom,rx-swr-gpios", 0, 0, 0, v37) )
    v8 = 0;
  else
    v8 = v37[0];
  *(_QWORD *)(v4 + 296) = v8;
  if ( !v8 && v20 )
  {
    dev_err(v1, "%s: swr_gpios handle not provided!\n", "lpass_cdc_rx_macro_probe");
    result = 4294967274LL;
    goto LABEL_32;
  }
  if ( (msm_cdc_pinctrl_get_state() & 0x80000000) != 0 && v20 )
  {
    dev_err(v1, "%s: failed to get swr pin state\n", "lpass_cdc_rx_macro_probe");
    goto LABEL_28;
  }
  msm_cdc_pinctrl_set_wakeup_capable(*(_QWORD *)(v4 + 296), 0);
  v9 = devm_ioremap(v1, HIDWORD(v22), 4096);
  if ( !v9 )
  {
    dev_err(v1, "%s: ioremap failed\n", "lpass_cdc_rx_macro_probe");
    goto LABEL_31;
  }
  v10 = (unsigned int)v22;
  v11 = v9;
  *(_QWORD *)(v4 + 456) = v9;
  v12 = devm_ioremap(v1, v10, 4);
  if ( !v12 )
  {
    dev_err(v1, "%s: ioremap failed for muxsel\n", "lpass_cdc_rx_macro_probe");
    goto LABEL_31;
  }
  *(_QWORD *)(v4 + 464) = v12;
  *(_QWORD *)(v4 + 256) = 0;
  *(_QWORD *)(v4 + 264) = 0xFFFFFFFE00000LL;
  *(_BYTE *)(v4 + 73) = 1;
  *(_QWORD *)(v4 + 272) = v4 + 272;
  *(_QWORD *)(v4 + 280) = v4 + 272;
  *(_QWORD *)(v4 + 288) = lpass_cdc_rx_macro_add_child_devices;
  *(_QWORD *)(v4 + 240) = rx_swrm_clock;
  *(_QWORD *)(v4 + 248) = lpass_cdc_rx_macro_core_vote;
  v13 = v21;
  *(_QWORD *)(v4 + 208) = v4;
  *(_QWORD *)(v4 + 216) = 0;
  *(_QWORD *)(v4 + 224) = 0;
  *(_QWORD *)(v4 + 232) = 0;
  *(_WORD *)(v4 + 2336) = v13;
  *(_WORD *)(v4 + 2338) = v13;
  v14 = devm_clk_get(v1, "rx_mclk2_2x_clk");
  if ( v14 <= 0xFFFFFFFFFFFFF000LL )
    v15 = v14;
  else
    v15 = 0;
  *(_DWORD *)(v4 + 2328) = 1;
  *(_QWORD *)(v4 + 2344) = v15;
  *(_QWORD *)(a1 + 168) = v4;
  _mutex_init(v4 + 104, "&rx_priv->mclk_lock", &lpass_cdc_rx_macro_probe___key_21);
  _mutex_init(v4 + 152, "&rx_priv->swr_clk_lock", &lpass_cdc_rx_macro_probe___key_23);
  v26 = 0;
  v23 = lpass_cdc_rx_macro_init;
  v24 = lpass_cdc_rx_macro_deinit;
  v27 = &lpass_cdc_rx_macro_dai;
  v28 = 0;
  v25 = 7;
  v29 = &lpass_cdc_rx_macro_event_handler;
  v30 = 0;
  v33 = 0;
  v34 = 0;
  v35 = v11;
  v36 = 0;
  v31 = lpass_cdc_rx_macro_set_port_map;
  v32 = 0;
  v16 = lpass_cdc_register_macro(v1, 1, &v23);
  if ( v16 )
  {
    v19 = v16;
    dev_err(v1, "%s: register macro failed\n", "lpass_cdc_rx_macro_probe");
    result = v19;
  }
  else
  {
    pm_runtime_set_autosuspend_delay(v1, 50);
    _pm_runtime_use_autosuspend(v1, 1);
    _pm_runtime_set_status(v1, 2);
    *(_WORD *)(a1 + 504) |= 0x100u;
    pm_runtime_enable(v1);
    queue_work_on(32, system_wq, v4 + 264);
    result = 0;
  }
LABEL_32:
  _ReadStatusReg(SP_EL0);
  return result;
}
