__int64 __fastcall cnss_shutdown(
        __int64 result,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  __int64 v8; // x19
  unsigned __int64 StatusReg; // x8
  const char *v10; // x1
  unsigned __int64 v11; // x8
  const char *v12; // x1
  __int16 v13; // w9
  const char *v14; // x8
  __int16 v15; // w9
  const char *v16; // x8
  char v17; // [xsp+0h] [xbp+0h]

  v8 = *(_QWORD *)(result + 168);
  if ( v8 )
  {
    if ( *(_BYTE *)(v8 + 7880) == 1 )
    {
      StatusReg = _ReadStatusReg(SP_EL0);
      if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
      {
        v10 = "irq";
      }
      else
      {
        v15 = *(_DWORD *)(StatusReg + 16);
        v16 = (const char *)(StatusReg + 2320);
        if ( (v15 & 0xFF00) != 0 )
          v10 = "soft_irq";
        else
          v10 = v16;
      }
      cnss_debug_ipc_log_print(
        cnss_ipc_log_context,
        v10,
        "cnss_shutdown",
        6u,
        6u,
        "wlan cnss do shutdown\n",
        a7,
        a8,
        v17);
      return cnss_power_off_device(v8);
    }
  }
  else
  {
    v11 = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(v11 + 16) & 0xF0000) != 0 )
    {
      v12 = "irq";
    }
    else
    {
      v13 = *(_DWORD *)(v11 + 16);
      v14 = (const char *)(v11 + 2320);
      if ( (v13 & 0xFF00) != 0 )
        v12 = "soft_irq";
      else
        v12 = v14;
    }
    return cnss_debug_ipc_log_print(
             cnss_ipc_log_context,
             v12,
             "cnss_shutdown",
             3u,
             3u,
             "plat priv is null\n",
             a7,
             a8,
             v17);
  }
  return result;
}
