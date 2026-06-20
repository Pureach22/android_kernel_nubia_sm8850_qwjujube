__int64 __fastcall cnss_get_wlan_tsf_gpio_info(_DWORD *a1)
{
  __int64 v1; // x20
  __int64 result; // x0
  unsigned int named_gpio; // w0
  __int64 v5; // x7
  unsigned __int64 StatusReg; // x8
  const char *v7; // x1
  __int16 v8; // w9
  const char *v9; // x8
  char vars0; // [xsp+0h] [xbp+0h]

  v1 = *(_QWORD *)a1;
  result = of_find_property(*(_QWORD *)(*(_QWORD *)a1 + 760LL), "qcom,wlan-tsf-gpio", 0);
  if ( result )
  {
    named_gpio = of_get_named_gpio(*(_QWORD *)(v1 + 760), "qcom,wlan-tsf-gpio", 0);
    a1[38] = named_gpio;
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v7 = "irq";
    }
    else
    {
      v8 = *(_DWORD *)(StatusReg + 16);
      v9 = (const char *)(StatusReg + 2320);
      if ( (v8 & 0xFF00) != 0 )
        v7 = "soft_irq";
      else
        v7 = v9;
    }
    return cnss_debug_ipc_log_print(
             cnss_ipc_log_context,
             v7,
             "cnss_get_wlan_tsf_gpio_info",
             7u,
             7u,
             "WLAN TSF GPIO: %d\n",
             named_gpio,
             v5,
             vars0);
  }
  else
  {
    a1[38] = -22;
  }
  return result;
}
