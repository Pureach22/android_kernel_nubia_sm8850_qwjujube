__int64 __fastcall cnss_reset_afcmem(__int64 a1, __int64 a2)
{
  unsigned __int8 v2; // w19
  __int64 v3; // x0
  __int64 v4; // x7
  unsigned __int64 v5; // x8
  const char *v6; // x1
  int v8; // w8
  int v9; // w9
  __int64 v10; // x12
  __int16 v11; // w9
  const char *v12; // x8
  __int64 v13; // x8
  unsigned __int64 StatusReg; // x8
  const char *v15; // x1
  __int16 v16; // w9
  const char *v17; // x8
  char v18; // [xsp+0h] [xbp+0h]

  v2 = a2;
  v3 = cnss_bus_dev_to_plat_priv(a1, a2);
  if ( !v3 )
    return 4294967274LL;
  if ( v2 <= 1u )
  {
    v8 = *(_DWORD *)(v3 + 1720);
    if ( !v8 )
      goto LABEL_17;
    v9 = 0;
    while ( 1 )
    {
      v10 = v3 + 1728 + 40LL * v9;
      if ( *(_DWORD *)(v10 + 28) == 10 )
        break;
      if ( v8 == ++v9 )
        goto LABEL_17;
    }
    v13 = *(_QWORD *)(v10 + 8);
    if ( v13 )
    {
      memset((void *)(v13 + (v2 << 12)), 0, 0x1000u);
      return 0;
    }
    else
    {
LABEL_17:
      StatusReg = _ReadStatusReg(SP_EL0);
      if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
      {
        v15 = "irq";
      }
      else
      {
        v16 = *(_DWORD *)(StatusReg + 16);
        v17 = (const char *)(StatusReg + 2320);
        if ( (v16 & 0xFF00) != 0 )
          v15 = "soft_irq";
        else
          v15 = v17;
      }
      cnss_debug_ipc_log_print(
        cnss_ipc_log_context,
        v15,
        "cnss_reset_afcmem",
        3u,
        3u,
        "AFC mem is not available\n",
        v2,
        v4,
        v18);
      return 4294967284LL;
    }
  }
  else
  {
    v5 = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(v5 + 16) & 0xF0000) != 0 )
    {
      v6 = "irq";
    }
    else
    {
      v11 = *(_DWORD *)(v5 + 16);
      v12 = (const char *)(v5 + 2320);
      if ( (v11 & 0xFF00) != 0 )
        v6 = "soft_irq";
      else
        v6 = v12;
    }
    cnss_debug_ipc_log_print(cnss_ipc_log_context, v6, "cnss_reset_afcmem", 3u, 3u, "Invalid slot id %d\n", v2, v4, v18);
    return 4294967274LL;
  }
}
