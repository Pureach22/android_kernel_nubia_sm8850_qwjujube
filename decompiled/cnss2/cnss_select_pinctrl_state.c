__int64 __fastcall cnss_select_pinctrl_state(
        __int64 a1,
        char a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  char v9; // w22
  unsigned __int64 v10; // x1
  unsigned int v11; // w0
  __int64 v12; // x7
  unsigned int v13; // w8
  unsigned __int64 StatusReg; // x9
  __int64 v15; // x0
  unsigned int v16; // w19
  const char *v17; // x1
  unsigned __int64 v18; // x8
  const char *v19; // x1
  unsigned __int64 v20; // x8
  __int64 result; // x0
  __int64 v22; // x6
  __int64 v23; // x7
  unsigned int v24; // w0
  unsigned int v25; // w8
  unsigned __int64 v26; // x9
  __int16 v27; // w9
  const char *v28; // x8
  unsigned __int64 v29; // x8
  const char *v30; // x1
  unsigned __int64 v31; // x1
  unsigned int v32; // w0
  __int64 v33; // x6
  unsigned __int64 v34; // x9
  int v35; // w10
  const char *v36; // x1
  __int16 v37; // w8
  const char *v38; // x9
  const char *v39; // x5
  __int16 v40; // w9
  const char *v41; // x8
  __int16 v42; // w10
  const char *v43; // x9
  __int16 v44; // w8
  const char *v45; // x9
  __int16 v46; // w10
  const char *v47; // x9
  unsigned __int64 v48; // x1
  unsigned int v49; // w0
  unsigned int v50; // w8
  unsigned __int64 v51; // x9
  __int64 v52; // x8
  unsigned __int64 v53; // x23
  __int64 v54; // x20
  const char *v55; // x21
  __int64 v56; // x0
  unsigned int raw_value; // w0
  __int64 v58; // x7
  __int64 v59; // x7
  const char *v60; // x1
  const char *v61; // x6
  __int16 v62; // w8
  const char *v63; // x9
  char vars0; // [xsp+0h] [xbp+0h]
  char vars0a; // [xsp+0h] [xbp+0h]

  if ( a1 )
  {
    if ( (a2 & 1) != 0 )
    {
      v9 = a2;
      v10 = *(_QWORD *)(a1 + 64);
      if ( v10 && v10 <= 0xFFFFFFFFFFFFF000LL )
      {
        v11 = pinctrl_select_state(*(_QWORD *)(a1 + 56), v10);
        if ( v11 )
        {
          v13 = v11;
          StatusReg = _ReadStatusReg(SP_EL0);
          v15 = cnss_ipc_log_context;
          v16 = v13;
          if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
          {
            v17 = "irq";
          }
          else
          {
            v37 = *(_DWORD *)(StatusReg + 16);
            v38 = (const char *)(StatusReg + 2320);
            if ( (v37 & 0xFF00) != 0 )
              v17 = "soft_irq";
            else
              v17 = v38;
          }
          v39 = "Failed to select bootstrap active state, err = %d\n";
LABEL_79:
          cnss_debug_ipc_log_print(v15, v17, "cnss_select_pinctrl_state", 3u, 3u, v39, v16, v12, vars0);
          return v16;
        }
        _const_udelay(4295000);
      }
      v31 = *(_QWORD *)(a1 + 72);
      if ( v31 && v31 <= 0xFFFFFFFFFFFFF000LL )
      {
        v32 = pinctrl_select_state(*(_QWORD *)(a1 + 56), v31);
        v34 = _ReadStatusReg(SP_EL0);
        v35 = *(_DWORD *)(v34 + 16) & 0xF0000;
        if ( v32 )
        {
          v16 = v32;
          if ( v35 )
          {
            v17 = "irq";
          }
          else
          {
            v42 = *(_DWORD *)(v34 + 16);
            v43 = (const char *)(v34 + 2320);
            if ( (v42 & 0xFF00) != 0 )
              v17 = "soft_irq";
            else
              v17 = v43;
          }
          v39 = "Failed to select sol default state, err = %d\n";
          v15 = cnss_ipc_log_context;
          goto LABEL_79;
        }
        if ( v35 )
        {
          v36 = "irq";
        }
        else
        {
          v46 = *(_DWORD *)(v34 + 16);
          v47 = (const char *)(v34 + 2320);
          if ( (v46 & 0xFF00) != 0 )
            v36 = "soft_irq";
          else
            v36 = v47;
        }
        cnss_debug_ipc_log_print(
          cnss_ipc_log_context,
          v36,
          "cnss_select_pinctrl_state",
          7u,
          7u,
          "Selected sol default state\n",
          v33,
          v12,
          vars0);
      }
      cnss_set_xo_clk_gpio_state(a1, 1);
      v48 = *(_QWORD *)(a1 + 80);
      if ( !v48 || v48 > 0xFFFFFFFFFFFFF000LL )
      {
        cnss_set_xo_clk_gpio_state(a1, 0);
        return 0;
      }
      v49 = pinctrl_select_state(*(_QWORD *)(a1 + 56), v48);
      if ( v49 )
      {
        v50 = v49;
        v51 = _ReadStatusReg(SP_EL0);
        v15 = cnss_ipc_log_context;
        v16 = v50;
        if ( (*(_DWORD *)(v51 + 16) & 0xF0000) != 0 )
        {
          v17 = "irq";
        }
        else
        {
          v62 = *(_DWORD *)(v51 + 16);
          v63 = (const char *)(v51 + 2320);
          if ( (v62 & 0xFF00) != 0 )
            v17 = "soft_irq";
          else
            v17 = v63;
        }
        v39 = "Failed to select wlan_en active state, err = %d\n";
        goto LABEL_79;
      }
      v52 = *(_QWORD *)(a1 + 528);
      if ( v52 == 62 || !v52 )
      {
        _const_udelay(4295000);
        _const_udelay(4295000);
        _const_udelay(4295000);
        _const_udelay(4295000);
        _const_udelay(4295000);
        _const_udelay(4295000);
        _const_udelay(4295000);
        _const_udelay(4295000);
        _const_udelay(4295000);
      }
      _const_udelay(4295000);
      cnss_set_xo_clk_gpio_state(a1, 0);
LABEL_60:
      v53 = _ReadStatusReg(SP_EL0);
      v54 = cnss_ipc_log_context;
      if ( (*(_DWORD *)(v53 + 16) & 0xF0000) != 0 )
      {
        v55 = "irq";
      }
      else if ( (*(_DWORD *)(v53 + 16) & 0xFF00) != 0 )
      {
        v55 = "soft_irq";
      }
      else
      {
        v55 = (const char *)(v53 + 2320);
      }
      v56 = gpio_to_desc(*(unsigned int *)(a1 + 116));
      raw_value = gpiod_get_raw_value(v56);
      cnss_debug_ipc_log_print(
        v54,
        v55,
        "cnss_select_pinctrl_state",
        7u,
        7u,
        "WLAN_EN Value: %d\n",
        raw_value,
        v58,
        vars0);
      if ( (*(_DWORD *)(v53 + 16) & 0xF0000) != 0 )
      {
        v60 = "irq";
      }
      else if ( (*(_DWORD *)(v53 + 16) & 0xFF00) != 0 )
      {
        v60 = "soft_irq";
      }
      else
      {
        v60 = (const char *)(v53 + 2320);
      }
      if ( (v9 & 1) != 0 )
        v61 = "Assert";
      else
        v61 = "De-assert";
      cnss_debug_ipc_log_print(
        cnss_ipc_log_context,
        v60,
        "cnss_select_pinctrl_state",
        7u,
        7u,
        "%s WLAN_EN GPIO successfully\n",
        (__int64)v61,
        v59,
        vars0a);
      return 0;
    }
    v20 = *(_QWORD *)(a1 + 88);
    result = 0;
    if ( v20 && v20 <= 0xFFFFFFFFFFFFF000LL )
    {
      v9 = a2;
      cnss_wlan_hw_disable_check(a1);
      if ( (*(_QWORD *)(a1 + 552) & 0x1000000) != 0 )
      {
        v29 = _ReadStatusReg(SP_EL0);
        if ( (*(_DWORD *)(v29 + 16) & 0xF0000) != 0 )
        {
          v30 = "irq";
        }
        else
        {
          v40 = *(_DWORD *)(v29 + 16);
          v41 = (const char *)(v29 + 2320);
          if ( (v40 & 0xFF00) != 0 )
            v30 = "soft_irq";
          else
            v30 = v41;
        }
        cnss_debug_ipc_log_print(
          cnss_ipc_log_context,
          v30,
          "cnss_select_pinctrl_state",
          7u,
          7u,
          "Avoid WLAN_EN low. WLAN HW Disbaled",
          v22,
          v23,
          vars0);
        return 0;
      }
      v24 = pinctrl_select_state(*(_QWORD *)(a1 + 56), *(_QWORD *)(a1 + 88));
      if ( v24 )
      {
        v25 = v24;
        v26 = _ReadStatusReg(SP_EL0);
        v15 = cnss_ipc_log_context;
        v16 = v25;
        if ( (*(_DWORD *)(v26 + 16) & 0xF0000) != 0 )
        {
          v17 = "irq";
        }
        else
        {
          v44 = *(_DWORD *)(v26 + 16);
          v45 = (const char *)(v26 + 2320);
          if ( (v44 & 0xFF00) != 0 )
            v17 = "soft_irq";
          else
            v17 = v45;
        }
        v39 = "Failed to select wlan_en sleep state, err = %d\n";
        goto LABEL_79;
      }
      goto LABEL_60;
    }
  }
  else
  {
    v18 = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(v18 + 16) & 0xF0000) != 0 )
    {
      v19 = "irq";
    }
    else
    {
      v27 = *(_DWORD *)(v18 + 16);
      v28 = (const char *)(v18 + 2320);
      if ( (v27 & 0xFF00) != 0 )
        v19 = "soft_irq";
      else
        v19 = v28;
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v19,
      "cnss_select_pinctrl_state",
      3u,
      3u,
      "plat_priv is NULL!\n",
      a7,
      a8,
      vars0);
    return 4294967277LL;
  }
  return result;
}
