__int64 __fastcall cnss_select_pinctrl_enable(__int64 a1)
{
  unsigned int v1; // w21
  __int64 v2; // x19
  __int64 v3; // x0
  unsigned int raw_value; // w0
  __int64 v5; // x6
  __int64 v6; // x7
  unsigned int v7; // w20
  unsigned __int64 v8; // x8
  const char *v9; // x1
  __int16 v10; // w9
  const char *v11; // x8
  unsigned int v12; // w22
  __int64 v13; // x0
  __int64 v14; // x6
  __int64 v15; // x7
  unsigned int v16; // w8
  unsigned __int64 StatusReg; // x21
  const char *v18; // x1
  __int64 v19; // x6
  __int64 v20; // x7
  const char *v21; // x1
  char vars0; // [xsp+0h] [xbp+0h]
  char vars0a; // [xsp+0h] [xbp+0h]

  v1 = *(_DWORD *)(a1 + 112);
  if ( (v1 & 0x80000000) != 0 || *(_QWORD *)(a1 + 528) != 4355 )
    return (unsigned int)cnss_select_pinctrl_state(a1, 1);
  v2 = a1;
  v3 = gpio_to_desc(v1);
  raw_value = gpiod_get_raw_value(v3);
  v7 = raw_value;
  if ( raw_value
    && ((v8 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v8 + 16) & 0xF0000) == 0)
      ? ((v10 = *(_DWORD *)(v8 + 16), v11 = (const char *)(v8 + 2320), (v10 & 0xFF00) != 0)
       ? (v9 = "soft_irq")
       : (v9 = v11))
      : (v9 = "irq"),
        cnss_debug_ipc_log_print(
          cnss_ipc_log_context,
          v9,
          "cnss_select_pinctrl_enable",
          7u,
          7u,
          "BT_EN_GPIO State: On\n",
          v5,
          v6,
          vars0),
        (raw_value = cnss_select_pinctrl_state(v2, 1)) == 0) )
  {
    return 0;
  }
  else
  {
    v12 = raw_value;
    v13 = gpio_to_desc(v1);
    if ( !(unsigned int)gpiod_get_raw_value(v13) )
    {
      StatusReg = _ReadStatusReg(SP_EL0);
      if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
      {
        v18 = "irq";
      }
      else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
      {
        v18 = "soft_irq";
      }
      else
      {
        v18 = (const char *)(StatusReg + 2320);
      }
      cnss_debug_ipc_log_print(
        cnss_ipc_log_context,
        v18,
        "cnss_select_pinctrl_enable",
        7u,
        7u,
        "BT_EN_GPIO State: Off. Delay WLAN_GPIO enable\n",
        v14,
        v15,
        vars0);
      if ( v7 )
      {
        if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
        {
          v21 = "irq";
        }
        else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
        {
          v21 = "soft_irq";
        }
        else
        {
          v21 = (const char *)(StatusReg + 2320);
        }
        cnss_debug_ipc_log_print(
          cnss_ipc_log_context,
          v21,
          "cnss_select_pinctrl_enable",
          7u,
          7u,
          "Reset WLAN_EN as BT got turned off during enable\n",
          v19,
          v20,
          vars0a);
        cnss_select_pinctrl_state(v2, 0);
      }
      msleep(100);
      a1 = v2;
      return (unsigned int)cnss_select_pinctrl_state(a1, 1);
    }
    a1 = v2;
    v16 = v12;
    if ( !v7 )
      return (unsigned int)cnss_select_pinctrl_state(a1, 1);
  }
  return v16;
}
