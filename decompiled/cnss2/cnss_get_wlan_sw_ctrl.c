__int64 __fastcall cnss_get_wlan_sw_ctrl(_DWORD *a1)
{
  __int64 v1; // x20
  unsigned int named_gpio; // w0
  __int64 v4; // x7
  unsigned __int64 StatusReg; // x8
  const char *v6; // x1
  __int16 v7; // w9
  const char *v8; // x8
  char vars0; // [xsp+0h] [xbp+0h]

  v1 = *(_QWORD *)a1;
  if ( of_find_property(*(_QWORD *)(*(_QWORD *)a1 + 760LL), "qcom,wlan-sw-ctrl-gpio", 0) )
  {
    named_gpio = of_get_named_gpio(*(_QWORD *)(v1 + 760), "qcom,wlan-sw-ctrl-gpio", 0);
    a1[32] = named_gpio;
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v6 = "irq";
    }
    else
    {
      v7 = *(_DWORD *)(StatusReg + 16);
      v8 = (const char *)(StatusReg + 2320);
      if ( (v7 & 0xFF00) != 0 )
        v6 = "soft_irq";
      else
        v6 = v8;
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v6,
      "cnss_get_wlan_sw_ctrl",
      7u,
      7u,
      "WLAN Switch control GPIO: %d\n",
      named_gpio,
      v4,
      vars0);
  }
  else
  {
    a1[32] = -22;
  }
  return 0;
}
