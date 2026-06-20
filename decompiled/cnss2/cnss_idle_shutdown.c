__int64 __fastcall cnss_idle_shutdown(__int64 a1, __int64 a2)
{
  __int64 v2; // x0
  __int64 v3; // x6
  __int64 v4; // x7
  unsigned __int64 StatusReg; // x19
  int v6; // w9
  __int64 v7; // x21
  const char *v8; // x1
  unsigned __int64 v9; // x8
  const char *v10; // x1
  const char *v11; // x1
  __int16 v12; // w9
  const char *v13; // x8
  __int64 v15; // x6
  __int64 v16; // x7
  const char *v17; // x1
  char v18; // [xsp+0h] [xbp+0h]
  char v19; // [xsp+0h] [xbp+0h]

  v2 = cnss_bus_dev_to_plat_priv(a1, a2);
  if ( v2 )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    v6 = *(_DWORD *)(StatusReg + 16) & 0xF0000;
    if ( (*(_QWORD *)(v2 + 552) & 0x8000) != 0 )
    {
      if ( v6 )
      {
        v11 = "irq";
      }
      else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
      {
        v11 = "soft_irq";
      }
      else
      {
        v11 = (const char *)(StatusReg + 2320);
      }
      cnss_debug_ipc_log_print(
        cnss_ipc_log_context,
        v11,
        "cnss_idle_shutdown",
        7u,
        7u,
        "System suspend or resume in progress, ignore idle shutdown\n",
        v3,
        v4,
        v18);
      return 4294967285LL;
    }
    else
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
      cnss_debug_ipc_log_print(
        cnss_ipc_log_context,
        v8,
        "cnss_idle_shutdown",
        7u,
        7u,
        "Doing idle shutdown\n",
        v3,
        v4,
        v18);
      if ( (*(_QWORD *)(v7 + 552) & 0x200) != 0 || (*(_QWORD *)(v7 + 552) & 0x800) != 0 )
      {
        if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
        {
          v17 = "irq";
        }
        else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
        {
          v17 = "soft_irq";
        }
        else
        {
          v17 = (const char *)(StatusReg + 2320);
        }
        cnss_debug_ipc_log_print(
          cnss_ipc_log_context,
          v17,
          "cnss_idle_shutdown",
          7u,
          7u,
          "Recovery in progress. Ignore IDLE Shutdown\n",
          v15,
          v16,
          v19);
        return 4294967280LL;
      }
      else
      {
        return cnss_driver_event_post(v7, 0xEu, 3, 0);
      }
    }
  }
  else
  {
    v9 = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(v9 + 16) & 0xF0000) != 0 )
    {
      v10 = "irq";
    }
    else
    {
      v12 = *(_DWORD *)(v9 + 16);
      v13 = (const char *)(v9 + 2320);
      if ( (v12 & 0xFF00) != 0 )
        v10 = "soft_irq";
      else
        v10 = v13;
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v10,
      "cnss_idle_shutdown",
      3u,
      3u,
      "plat_priv is NULL\n",
      v3,
      v4,
      v18);
    return 4294967277LL;
  }
}
