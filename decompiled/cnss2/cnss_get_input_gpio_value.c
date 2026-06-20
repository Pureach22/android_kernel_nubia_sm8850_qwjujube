__int64 __fastcall cnss_get_input_gpio_value(__int64 a1, unsigned int a2)
{
  __int64 v3; // x0
  unsigned int v4; // w0
  unsigned __int64 StatusReg; // x8
  const char *v6; // x1
  __int64 v8; // x0
  __int16 v9; // w9
  const char *v10; // x8
  char v11; // [xsp+0h] [xbp+0h]

  if ( (a2 & 0x80000000) != 0 )
    return 4294967274LL;
  v3 = gpio_to_desc(a2);
  v4 = gpiod_direction_input(v3);
  if ( v4 )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v6 = "irq";
    }
    else
    {
      v9 = *(_DWORD *)(StatusReg + 16);
      v10 = (const char *)(StatusReg + 2320);
      if ( (v9 & 0xFF00) != 0 )
        v6 = "soft_irq";
      else
        v6 = v10;
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v6,
      "cnss_get_input_gpio_value",
      3u,
      3u,
      "Failed to set direction of GPIO(%d), err = %d",
      a2,
      v4,
      v11);
    return 4294967274LL;
  }
  else
  {
    v8 = gpio_to_desc(a2);
    return gpiod_get_raw_value(v8);
  }
}
