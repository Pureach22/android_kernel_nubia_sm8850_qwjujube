__int64 __fastcall cnss_wlan_device_init(__int64 a1)
{
  __int64 result; // x0
  unsigned int v3; // w20
  unsigned int v4; // w21
  unsigned __int64 StatusReg; // x27
  __int64 v6; // x7
  const char *v7; // x1
  unsigned int v8; // w20
  char v9; // [xsp+0h] [xbp+0h]

  if ( (*(_QWORD *)(a1 + 6680) & 2) != 0 )
    return 0;
  result = ((__int64 (*)(void))cnss_power_on_device)();
  if ( !(_DWORD)result )
  {
    v3 = 1;
    v4 = 500;
    StatusReg = _ReadStatusReg(SP_EL0);
    while ( 1 )
    {
      result = cnss_bus_init(a1);
      if ( (_DWORD)result == -517 )
        break;
      if ( !(_DWORD)result )
        return result;
      if ( v3 == 5 )
        break;
      cnss_power_off_device(a1);
      v7 = "irq";
      if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) == 0 )
      {
        if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
          v7 = "soft_irq";
        else
          v7 = (const char *)(StatusReg + 2320);
      }
      cnss_debug_ipc_log_print(
        cnss_ipc_log_context,
        v7,
        "cnss_wlan_device_init",
        7u,
        7u,
        "Retry cnss_bus_init #%d\n",
        v3,
        v6,
        v9);
      msleep(v4);
      result = cnss_power_on_device(a1, 1);
      ++v3;
      v4 += 500;
      if ( (_DWORD)result )
        return result;
    }
    v8 = result;
    cnss_power_off_device(a1);
    return v8;
  }
  return result;
}
