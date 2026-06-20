__int64 __fastcall recovery_store(__int64 a1, int a2, char *s, __int64 a4)
{
  __int64 v4; // x20
  __int64 v6; // x6
  __int64 v7; // x7
  char v8; // w9
  unsigned __int64 StatusReg; // x21
  __int64 v10; // x0
  const char *v11; // x1
  unsigned __int64 v12; // x8
  const char *v13; // x1
  const char *v14; // x6
  const char *v15; // x1
  __int16 v16; // w9
  const char *v17; // x8
  const char *v18; // x6
  char v20; // [xsp+0h] [xbp-10h]
  char v21; // [xsp+0h] [xbp-10h]
  int v22; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v23; // [xsp+8h] [xbp-8h]

  v23 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 152);
  v22 = 0;
  if ( v4 )
  {
    if ( sscanf(s, "%du", &v22) == 1 )
    {
      v8 = v22;
      StatusReg = _ReadStatusReg(SP_EL0);
      v10 = cnss_ipc_log_context;
      *(_BYTE *)(v4 + 544) = v8 & 1;
      *(_BYTE *)(v4 + 545) = (v8 & 2) != 0;
      if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
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
      if ( (v8 & 1) != 0 )
        v14 = "Enable";
      else
        v14 = "Disable";
      cnss_debug_ipc_log_print(
        v10,
        v11,
        "recovery_store",
        7u,
        7u,
        "%s WLAN recovery, count is %zu\n",
        (__int64)v14,
        a4,
        v20);
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
      if ( *(_BYTE *)(v4 + 545) )
        v18 = "Enable";
      else
        v18 = "Disable";
      cnss_debug_ipc_log_print(
        cnss_ipc_log_context,
        v15,
        "recovery_store",
        7u,
        7u,
        "%s PCSS recovery, count is %zu\n",
        (__int64)v18,
        a4,
        v21);
      cnss_send_subsys_restart_level_msg(v4);
    }
    else
    {
      v12 = _ReadStatusReg(SP_EL0);
      if ( (*(_DWORD *)(v12 + 16) & 0xF0000) != 0 )
      {
        v13 = "irq";
      }
      else
      {
        v16 = *(_DWORD *)(v12 + 16);
        v17 = (const char *)(v12 + 2320);
        if ( (v16 & 0xFF00) != 0 )
          v13 = "soft_irq";
        else
          v13 = v17;
      }
      cnss_debug_ipc_log_print(
        cnss_ipc_log_context,
        v13,
        "recovery_store",
        3u,
        3u,
        "Invalid recovery sysfs command\n",
        v6,
        v7,
        v20);
      a4 = -22;
    }
  }
  else
  {
    a4 = -19;
  }
  _ReadStatusReg(SP_EL0);
  return a4;
}
