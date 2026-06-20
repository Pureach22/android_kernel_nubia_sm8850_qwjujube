__int64 __fastcall cnss_get_pinctrl(__int64 a1)
{
  __int64 v2; // x26
  unsigned __int64 v3; // x0
  __int64 v4; // x7
  unsigned int v5; // w20
  unsigned __int64 v6; // x0
  unsigned __int64 v7; // x0
  __int64 v8; // x6
  unsigned __int64 v9; // x8
  const char *v10; // x1
  unsigned __int64 StatusReg; // x8
  __int64 v12; // x0
  const char *v13; // x1
  __int16 v14; // w9
  const char *v15; // x8
  const char *v16; // x5
  unsigned __int64 v17; // x8
  unsigned __int64 v18; // x8
  __int16 v19; // w9
  const char *v20; // x8
  __int16 v21; // w9
  const char *v22; // x8
  __int16 v23; // w9
  const char *v24; // x8
  unsigned int named_gpio; // w0
  __int64 v26; // x7
  unsigned __int64 v27; // x21
  const char *v28; // x1
  unsigned __int64 v29; // x0
  unsigned __int64 v30; // x0
  unsigned int v31; // w0
  __int64 v32; // x7
  unsigned __int64 v33; // x8
  const char *v34; // x1
  __int16 v35; // w9
  const char *v36; // x8
  unsigned int v37; // w0
  __int64 v38; // x7
  unsigned __int64 v39; // x8
  const char *v40; // x1
  __int16 v41; // w9
  const char *v42; // x8
  unsigned int v43; // w0
  __int64 v44; // x7
  unsigned __int64 v45; // x20
  const char *v46; // x1
  unsigned __int64 v47; // x0
  __int64 v48; // x7
  __int64 v49; // x6
  unsigned int v50; // w0
  __int64 v51; // x0
  const char *v52; // x1
  const char *v53; // x5
  unsigned int v54; // w3
  unsigned int v55; // w4
  unsigned __int64 v57; // x0
  __int64 v58; // x7
  __int64 v59; // x6
  unsigned int v60; // w0
  unsigned __int64 v61; // x8
  __int64 v62; // x0
  const char *v63; // x1
  unsigned __int64 v64; // x8
  __int16 v65; // w9
  const char *v66; // x8
  const char *v67; // x5
  unsigned int v68; // w3
  unsigned int v69; // w4
  __int16 v70; // w9
  const char *v71; // x8
  __int64 v72; // x6
  __int64 v73; // x7
  int v74; // w19
  unsigned __int64 v75; // x27
  int v76; // w8
  const char *v77; // x1
  const char *v78; // x1
  unsigned int i; // w21
  unsigned int v80; // w3
  unsigned int v81; // w4
  const char *v82; // x5
  __int64 v83; // x6
  __int64 v84; // x7
  __int64 v85; // x0
  const char *v86; // x1
  unsigned int v87; // w0
  int v88; // w9
  char v89; // [xsp+0h] [xbp-10h]
  char v90; // [xsp+0h] [xbp-10h]
  unsigned int v91; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v92; // [xsp+8h] [xbp-8h]

  v92 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)a1;
  v91 = 0;
  v3 = devm_pinctrl_get(v2 + 16);
  v5 = v3;
  *(_QWORD *)(a1 + 56) = v3;
  if ( !v3 || v3 >= 0xFFFFFFFFFFFFF001LL )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    v12 = cnss_ipc_log_context;
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v13 = "irq";
    }
    else
    {
      v14 = *(_DWORD *)(StatusReg + 16);
      v15 = (const char *)(StatusReg + 2320);
      if ( (v14 & 0xFF00) != 0 )
        v13 = "soft_irq";
      else
        v13 = v15;
    }
    v16 = "Failed to get pinctrl, err = %d\n";
    goto LABEL_92;
  }
  if ( of_find_property(*(_QWORD *)(v2 + 760), "qcom,enable-bootstrap-gpio", 0) )
  {
    v6 = pinctrl_lookup_state(*(_QWORD *)(a1 + 56), "bootstrap_active");
    v5 = v6;
    *(_QWORD *)(a1 + 64) = v6;
    if ( !v6 || v6 >= 0xFFFFFFFFFFFFF001LL )
    {
      v17 = _ReadStatusReg(SP_EL0);
      v12 = cnss_ipc_log_context;
      if ( (*(_DWORD *)(v17 + 16) & 0xF0000) != 0 )
      {
        v13 = "irq";
      }
      else
      {
        v19 = *(_DWORD *)(v17 + 16);
        v20 = (const char *)(v17 + 2320);
        if ( (v19 & 0xFF00) != 0 )
          v13 = "soft_irq";
        else
          v13 = v20;
      }
      v16 = "Failed to get bootstrap active state, err = %d\n";
      goto LABEL_92;
    }
  }
  if ( of_find_property(*(_QWORD *)(v2 + 760), "wlan-host-sol-gpio", 0)
    && of_find_property(*(_QWORD *)(v2 + 760), "wlan-dev-sol-gpio", 0) )
  {
    v7 = pinctrl_lookup_state(*(_QWORD *)(a1 + 56), "sol_default");
    v5 = v7;
    *(_QWORD *)(a1 + 72) = v7;
    if ( !v7 || v7 >= 0xFFFFFFFFFFFFF001LL )
    {
      v18 = _ReadStatusReg(SP_EL0);
      v12 = cnss_ipc_log_context;
      if ( (*(_DWORD *)(v18 + 16) & 0xF0000) != 0 )
      {
        v13 = "irq";
      }
      else
      {
        v21 = *(_DWORD *)(v18 + 16);
        v22 = (const char *)(v18 + 2320);
        if ( (v21 & 0xFF00) != 0 )
          v13 = "soft_irq";
        else
          v13 = v22;
      }
      v16 = "Failed to get sol default state, err = %d\n";
      goto LABEL_92;
    }
    v9 = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(v9 + 16) & 0xF0000) != 0 )
    {
      v10 = "irq";
    }
    else
    {
      v23 = *(_DWORD *)(v9 + 16);
      v24 = (const char *)(v9 + 2320);
      if ( (v23 & 0xFF00) != 0 )
        v10 = "soft_irq";
      else
        v10 = v24;
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v10,
      "cnss_get_pinctrl",
      7u,
      7u,
      "Got sol default state\n",
      v8,
      v4,
      v89);
  }
  if ( !of_find_property(*(_QWORD *)(v2 + 760), "wlan-en-gpio", 0) )
  {
    *(_DWORD *)(a1 + 116) = -22;
    goto LABEL_46;
  }
  named_gpio = of_get_named_gpio(*(_QWORD *)(v2 + 760), "wlan-en-gpio", 0);
  *(_DWORD *)(a1 + 116) = named_gpio;
  v27 = _ReadStatusReg(SP_EL0);
  if ( (*(_DWORD *)(v27 + 16) & 0xF0000) != 0 )
  {
    v28 = "irq";
  }
  else if ( (*(_DWORD *)(v27 + 16) & 0xFF00) != 0 )
  {
    v28 = "soft_irq";
  }
  else
  {
    v28 = (const char *)(v27 + 2320);
  }
  cnss_debug_ipc_log_print(
    cnss_ipc_log_context,
    v28,
    "cnss_get_pinctrl",
    7u,
    7u,
    "WLAN_EN GPIO: %d\n",
    named_gpio,
    v26,
    v89);
  v29 = pinctrl_lookup_state(*(_QWORD *)(a1 + 56), "wlan_en_active");
  v5 = v29;
  *(_QWORD *)(a1 + 80) = v29;
  if ( !v29 || v29 >= 0xFFFFFFFFFFFFF001LL )
  {
    v12 = cnss_ipc_log_context;
    if ( (*(_DWORD *)(v27 + 16) & 0xF0000) != 0 )
    {
      v13 = "irq";
    }
    else if ( (*(_DWORD *)(v27 + 16) & 0xFF00) != 0 )
    {
      v13 = "soft_irq";
    }
    else
    {
      v13 = (const char *)(v27 + 2320);
    }
    v16 = "Failed to get wlan_en active state, err = %d\n";
    goto LABEL_92;
  }
  v30 = pinctrl_lookup_state(*(_QWORD *)(a1 + 56), "wlan_en_sleep");
  v5 = v30;
  *(_QWORD *)(a1 + 88) = v30;
  if ( !v30 || v30 >= 0xFFFFFFFFFFFFF001LL )
  {
    v12 = cnss_ipc_log_context;
    if ( (*(_DWORD *)(v27 + 16) & 0xF0000) != 0 )
    {
      v13 = "irq";
    }
    else if ( (*(_DWORD *)(v27 + 16) & 0xFF00) != 0 )
    {
      v13 = "soft_irq";
    }
    else
    {
      v13 = (const char *)(v27 + 2320);
    }
    v16 = "Failed to get wlan_en sleep state, err = %d\n";
LABEL_92:
    cnss_debug_ipc_log_print(v12, v13, "cnss_get_pinctrl", 3u, 3u, v16, v5, v4, v89);
    goto LABEL_93;
  }
  cnss_set_feature_list(a1, 2);
LABEL_46:
  if ( of_find_property(*(_QWORD *)(v2 + 760), "qcom,bt-en-gpio", 0) )
  {
    v31 = of_get_named_gpio(*(_QWORD *)(v2 + 760), "qcom,bt-en-gpio", 0);
    *(_DWORD *)(a1 + 112) = v31;
    v33 = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(v33 + 16) & 0xF0000) != 0 )
    {
      v34 = "irq";
    }
    else
    {
      v35 = *(_DWORD *)(v33 + 16);
      v36 = (const char *)(v33 + 2320);
      if ( (v35 & 0xFF00) != 0 )
        v34 = "soft_irq";
      else
        v34 = v36;
    }
    cnss_debug_ipc_log_print(cnss_ipc_log_context, v34, "cnss_get_pinctrl", 7u, 7u, "BT GPIO: %d\n", v31, v32, v89);
  }
  else
  {
    *(_DWORD *)(a1 + 112) = -22;
  }
  if ( of_find_property(*(_QWORD *)(v2 + 760), "qcom,xo-clk-gpio", 0) )
  {
    v37 = of_get_named_gpio(*(_QWORD *)(v2 + 760), "qcom,xo-clk-gpio", 0);
    *(_DWORD *)(a1 + 120) = v37;
    v39 = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(v39 + 16) & 0xF0000) != 0 )
    {
      v40 = "irq";
    }
    else
    {
      v41 = *(_DWORD *)(v39 + 16);
      v42 = (const char *)(v39 + 2320);
      if ( (v41 & 0xFF00) != 0 )
        v40 = "soft_irq";
      else
        v40 = v42;
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v40,
      "cnss_get_pinctrl",
      7u,
      7u,
      "QCA6490 XO_CLK GPIO: %d\n",
      v37,
      v38,
      v89);
    cnss_set_feature_list(a1, 0);
  }
  else
  {
    *(_DWORD *)(a1 + 120) = -22;
  }
  if ( !of_find_property(*(_QWORD *)(v2 + 760), "qcom,sw-ctrl-gpio", 0) )
  {
    *(_DWORD *)(a1 + 124) = -22;
    goto LABEL_99;
  }
  v43 = of_get_named_gpio(*(_QWORD *)(v2 + 760), "qcom,sw-ctrl-gpio", 0);
  *(_DWORD *)(a1 + 124) = v43;
  v45 = _ReadStatusReg(SP_EL0);
  if ( (*(_DWORD *)(v45 + 16) & 0xF0000) != 0 )
  {
    v46 = "irq";
  }
  else if ( (*(_DWORD *)(v45 + 16) & 0xFF00) != 0 )
  {
    v46 = "soft_irq";
  }
  else
  {
    v46 = (const char *)(v45 + 2320);
  }
  cnss_debug_ipc_log_print(
    cnss_ipc_log_context,
    v46,
    "cnss_get_pinctrl",
    7u,
    7u,
    "Switch control GPIO: %d\n",
    v43,
    v44,
    v89);
  v47 = pinctrl_lookup_state(*(_QWORD *)(a1 + 56), "sw_ctrl");
  v49 = v47;
  *(_QWORD *)(a1 + 96) = v47;
  if ( v47 && v47 < 0xFFFFFFFFFFFFF001LL )
  {
    v50 = pinctrl_select_state(*(_QWORD *)(a1 + 56), v47);
    if ( !v50 )
      goto LABEL_99;
    v49 = v50;
    v51 = cnss_ipc_log_context;
    if ( (*(_DWORD *)(v45 + 16) & 0xF0000) != 0 )
    {
      v52 = "irq";
    }
    else if ( (*(_DWORD *)(v45 + 16) & 0xFF00) != 0 )
    {
      v52 = "soft_irq";
    }
    else
    {
      v52 = (const char *)(v45 + 2320);
    }
    v53 = "Failed to select sw_ctrl state, err = %d\n";
    v54 = 3;
    v55 = 3;
  }
  else
  {
    v51 = cnss_ipc_log_context;
    if ( (*(_DWORD *)(v45 + 16) & 0xF0000) != 0 )
    {
      v52 = "irq";
    }
    else if ( (*(_DWORD *)(v45 + 16) & 0xFF00) != 0 )
    {
      v52 = "soft_irq";
    }
    else
    {
      v52 = (const char *)(v45 + 2320);
    }
    v53 = "Failed to get sw_ctrl state, err = %d\n";
    v54 = 7;
    v55 = 7;
  }
  cnss_debug_ipc_log_print(v51, v52, "cnss_get_pinctrl", v54, v55, v53, v49, v48, v89);
LABEL_99:
  if ( of_find_property(*(_QWORD *)(v2 + 760), "qcom,wlan-sw-ctrl-gpio", 0) )
  {
    v57 = pinctrl_lookup_state(*(_QWORD *)(a1 + 56), "sw_ctrl_wl_cx");
    v59 = v57;
    *(_QWORD *)(a1 + 104) = v57;
    if ( !v57 || v57 >= 0xFFFFFFFFFFFFF001LL )
    {
      v64 = _ReadStatusReg(SP_EL0);
      v62 = cnss_ipc_log_context;
      if ( (*(_DWORD *)(v64 + 16) & 0xF0000) != 0 )
      {
        v63 = "irq";
      }
      else
      {
        v65 = *(_DWORD *)(v64 + 16);
        v66 = (const char *)(v64 + 2320);
        if ( (v65 & 0xFF00) != 0 )
          v63 = "soft_irq";
        else
          v63 = v66;
      }
      v67 = "Failed to get sw_ctrl_wl_cx state, err = %d\n";
      v68 = 7;
      v69 = 7;
      goto LABEL_115;
    }
    v60 = pinctrl_select_state(*(_QWORD *)(a1 + 56), v57);
    if ( v60 )
    {
      v59 = v60;
      v61 = _ReadStatusReg(SP_EL0);
      v62 = cnss_ipc_log_context;
      if ( (*(_DWORD *)(v61 + 16) & 0xF0000) != 0 )
      {
        v63 = "irq";
      }
      else
      {
        v70 = *(_DWORD *)(v61 + 16);
        v71 = (const char *)(v61 + 2320);
        if ( (v70 & 0xFF00) != 0 )
          v63 = "soft_irq";
        else
          v63 = v71;
      }
      v67 = "Failed to select sw_ctrl_wl_cx state, err = %d\n";
      v68 = 3;
      v69 = 3;
LABEL_115:
      cnss_debug_ipc_log_print(v62, v63, "cnss_get_pinctrl", v68, v69, v67, v59, v58, v89);
    }
  }
  v74 = of_property_count_elems_of_size(*(_QWORD *)(v2 + 760), "mpm_wake_set_gpios", 4);
  v75 = _ReadStatusReg(SP_EL0);
  v76 = *(_DWORD *)(v75 + 16) & 0xF0000;
  if ( v74 < 1 )
  {
    if ( v76 )
    {
      v78 = "irq";
    }
    else if ( (*(_DWORD *)(v75 + 16) & 0xFF00) != 0 )
    {
      v78 = "soft_irq";
    }
    else
    {
      v78 = (const char *)(v75 + 2320);
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v78,
      "cnss_get_pinctrl",
      7u,
      7u,
      "No GPIOs to be setup for interrupt wakeup capable\n",
      v72,
      v73,
      v89);
  }
  else
  {
    if ( v76 )
    {
      v77 = "irq";
    }
    else if ( (*(_DWORD *)(v75 + 16) & 0xFF00) != 0 )
    {
      v77 = "soft_irq";
    }
    else
    {
      v77 = (const char *)(v75 + 2320);
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v77,
      "cnss_get_pinctrl",
      7u,
      7u,
      "Num of GPIOs to be setup for interrupt wakeup capable: %d\n",
      (unsigned int)v74,
      v73,
      v89);
    for ( i = 0; i != v74; ++i )
    {
      if ( (unsigned int)of_property_read_u32_index(*(_QWORD *)(v2 + 760), "mpm_wake_set_gpios", i, &v91) )
      {
        v85 = cnss_ipc_log_context;
        v86 = "irq";
        if ( (*(_DWORD *)(v75 + 16) & 0xF0000) == 0 )
        {
          if ( (*(_DWORD *)(v75 + 16) & 0xFF00) != 0 )
            v86 = "soft_irq";
          else
            v86 = (const char *)(v75 + 2320);
        }
        v80 = 3;
        v81 = 3;
        v82 = "Failed to read gpio_id at index: %d\n";
        v83 = i;
      }
      else
      {
        v87 = msm_gpio_mpm_wake_set(v91, 1);
        v88 = *(_DWORD *)(v75 + 16) & 0xF0000;
        if ( (v87 & 0x80000000) != 0 )
        {
          v83 = v87;
          v86 = "irq";
          if ( !v88 )
          {
            if ( (*(_DWORD *)(v75 + 16) & 0xFF00) != 0 )
              v86 = "soft_irq";
            else
              v86 = (const char *)(v75 + 2320);
          }
          v85 = cnss_ipc_log_context;
          v80 = 3;
          v81 = 3;
          v82 = "Failed to setup gpio_id: %d as interrupt wakeup capable, ret: %d\n";
        }
        else
        {
          v86 = "irq";
          if ( !v88 )
          {
            if ( (*(_DWORD *)(v75 + 16) & 0xFF00) != 0 )
              v86 = "soft_irq";
            else
              v86 = (const char *)(v75 + 2320);
          }
          v83 = v91;
          v85 = cnss_ipc_log_context;
          v80 = 7;
          v81 = 7;
          v82 = "gpio_id: %d successfully setup for interrupt wakeup capable\n";
        }
      }
      cnss_debug_ipc_log_print(v85, v86, "cnss_get_pinctrl", v80, v81, v82, v83, v84, v90);
    }
  }
  v5 = 0;
LABEL_93:
  _ReadStatusReg(SP_EL0);
  return v5;
}
