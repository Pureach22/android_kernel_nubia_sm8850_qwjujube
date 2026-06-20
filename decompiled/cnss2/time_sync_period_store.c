__int64 __fastcall time_sync_period_store(__int64 a1, int a2, char *s, __int64 a4)
{
  __int64 v4; // x19
  __int64 v6; // x6
  __int64 v7; // x7
  unsigned int v8; // w8
  unsigned __int64 v9; // x8
  __int64 v10; // x0
  const char *v11; // x1
  __int64 result; // x0
  unsigned __int64 StatusReg; // x8
  unsigned int v14; // w9
  unsigned int v15; // w1
  __int16 v16; // w9
  const char *v17; // x8
  const char *v18; // x5
  __int16 v19; // w9
  const char *v20; // x8
  unsigned __int64 v21; // x8
  __int16 v22; // w9
  const char *v23; // x8
  char v24; // [xsp+0h] [xbp-10h]
  unsigned int v25; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v26; // [xsp+8h] [xbp-8h]

  v26 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 152);
  v25 = 0;
  if ( v4 )
  {
    if ( sscanf(s, "%du", &v25) != 1 )
    {
      StatusReg = _ReadStatusReg(SP_EL0);
      v10 = cnss_ipc_log_context;
      if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
      {
        v11 = "irq";
      }
      else
      {
        v16 = *(_DWORD *)(StatusReg + 16);
        v17 = (const char *)(StatusReg + 2320);
        if ( (v16 & 0xFF00) != 0 )
          v11 = "soft_irq";
        else
          v11 = v17;
      }
      v18 = "Invalid time sync sysfs command\n";
      goto LABEL_28;
    }
    v8 = v25;
    if ( v25 <= 0x7CF )
    {
      v9 = _ReadStatusReg(SP_EL0);
      v10 = cnss_ipc_log_context;
      if ( (*(_DWORD *)(v9 + 16) & 0xF0000) != 0 )
      {
        v11 = "irq";
      }
      else
      {
        v19 = *(_DWORD *)(v9 + 16);
        v20 = (const char *)(v9 + 2320);
        if ( (v19 & 0xFF00) != 0 )
          v11 = "soft_irq";
        else
          v11 = v20;
      }
      v18 = "Invalid time sync value\n";
LABEL_28:
      cnss_debug_ipc_log_print(v10, v11, "time_sync_period_store", 3u, 3u, v18, v6, v7, v24);
      result = -22;
      goto LABEL_29;
    }
    v14 = *(_DWORD *)(v4 + 6708);
    *(_DWORD *)(v4 + 6712) = v25;
    if ( v14 >= v8 )
      v15 = v8;
    else
      v15 = v14;
    v25 = v15;
    if ( v15 == -1 )
    {
      v21 = _ReadStatusReg(SP_EL0);
      v10 = cnss_ipc_log_context;
      if ( (*(_DWORD *)(v21 + 16) & 0xF0000) != 0 )
      {
        v11 = "irq";
      }
      else
      {
        v22 = *(_DWORD *)(v21 + 16);
        v23 = (const char *)(v21 + 2320);
        if ( (v22 & 0xFF00) != 0 )
          v11 = "soft_irq";
        else
          v11 = v23;
      }
      v18 = "Invalid min time sync value\n";
      goto LABEL_28;
    }
    cnss_bus_update_time_sync_period(v4);
    result = a4;
  }
  else
  {
    result = -19;
  }
LABEL_29:
  _ReadStatusReg(SP_EL0);
  return result;
}
