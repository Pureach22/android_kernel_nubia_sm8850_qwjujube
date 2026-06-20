__int64 __fastcall cnss_power_up(__int64 a1, __int64 a2)
{
  __int64 v2; // x0
  __int64 v3; // x6
  __int64 v4; // x7
  unsigned __int64 StatusReg; // x21
  int v6; // w9
  __int64 v7; // x19
  const char *v8; // x1
  const char *v9; // x1
  __int64 result; // x0
  unsigned int v11; // w20
  __int64 v12; // x0
  __int64 v13; // x7
  int v14; // w8
  const char *v15; // x1
  char v16; // [xsp+0h] [xbp+0h]
  char v17; // [xsp+0h] [xbp+0h]

  v2 = cnss_bus_dev_to_plat_priv(a1, a2);
  StatusReg = _ReadStatusReg(SP_EL0);
  v6 = *(_DWORD *)(StatusReg + 16) & 0xF0000;
  if ( v2 )
  {
    v7 = v2;
    if ( v6 )
    {
      v8 = "irq";
    }
    else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      v8 = "soft_irq";
    }
    else
    {
      v8 = (const char *)(StatusReg + 2320);
    }
    cnss_debug_ipc_log_print(cnss_ipc_log_context, v8, "cnss_power_up", 7u, 7u, "Powering up device\n", v3, v4, v16);
    result = cnss_driver_event_post(v7, 0xBu, 1, 0);
    if ( !(_DWORD)result )
    {
      if ( *(_QWORD *)(v7 + 528) == 62 )
      {
        return 0;
      }
      else
      {
        v11 = 4 * cnss_get_qmi_timeout(v7);
        *(_DWORD *)(v7 + 6312) = 0;
        v12 = _msecs_to_jiffies(v11);
        v14 = wait_for_completion_timeout(v7 + 6312, v12);
        result = 0;
        if ( !v14 )
        {
          if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
          {
            v15 = "irq";
          }
          else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
          {
            v15 = "soft_irq";
          }
          else
          {
            v15 = (const char *)(StatusReg + 2320);
          }
          cnss_debug_ipc_log_print(
            cnss_ipc_log_context,
            v15,
            "cnss_power_up",
            3u,
            3u,
            "Timeout (%ums) waiting for power up to complete\n",
            v11,
            v13,
            v17);
          return 4294967285LL;
        }
      }
    }
  }
  else
  {
    if ( v6 )
    {
      v9 = "irq";
    }
    else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      v9 = "soft_irq";
    }
    else
    {
      v9 = (const char *)(StatusReg + 2320);
    }
    cnss_debug_ipc_log_print(cnss_ipc_log_context, v9, "cnss_power_up", 3u, 3u, "plat_priv is NULL\n", v3, v4, v16);
    return 4294967277LL;
  }
  return result;
}
