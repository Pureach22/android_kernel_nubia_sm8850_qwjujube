__int64 __fastcall cnss_send_buffer_to_afcmem(__int64 a1, const void *a2, unsigned int a3, unsigned __int8 a4)
{
  __int64 v7; // x0
  __int64 v8; // x7
  __int64 v9; // x6
  unsigned __int64 StatusReg; // x8
  __int64 v11; // x0
  const char *v12; // x1
  unsigned __int64 v14; // x8
  int v15; // w8
  int v16; // w9
  __int64 v17; // x12
  __int16 v18; // w9
  const char *v19; // x8
  const char *v20; // x5
  __int16 v21; // w9
  const char *v22; // x8
  __int64 v23; // x8
  _DWORD *v24; // x21
  unsigned __int64 v25; // x8
  const char *v26; // x1
  __int16 v27; // w9
  const char *v28; // x8
  char vars0; // [xsp+0h] [xbp+0h]

  v7 = cnss_bus_dev_to_plat_priv(a1, (__int64)a2);
  if ( !v7 )
    return 4294967274LL;
  v9 = a4;
  if ( a4 >= 2u )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    v11 = cnss_ipc_log_context;
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v12 = "irq";
    }
    else
    {
      v18 = *(_DWORD *)(StatusReg + 16);
      v19 = (const char *)(StatusReg + 2320);
      if ( (v18 & 0xFF00) != 0 )
        v12 = "soft_irq";
      else
        v12 = v19;
    }
    v20 = "Invalid slot id %d\n";
LABEL_22:
    cnss_debug_ipc_log_print(v11, v12, "cnss_send_buffer_to_afcmem", 3u, 3u, v20, v9, v8, vars0);
    return 4294967274LL;
  }
  if ( a3 > 0x1000 )
  {
    v14 = _ReadStatusReg(SP_EL0);
    v11 = cnss_ipc_log_context;
    if ( (*(_DWORD *)(v14 + 16) & 0xF0000) != 0 )
    {
      v12 = "irq";
    }
    else
    {
      v21 = *(_DWORD *)(v14 + 16);
      v22 = (const char *)(v14 + 2320);
      if ( (v21 & 0xFF00) != 0 )
        v12 = "soft_irq";
      else
        v12 = v22;
    }
    v20 = "len %d greater than slot size";
    v9 = a3;
    goto LABEL_22;
  }
  v15 = *(_DWORD *)(v7 + 1720);
  if ( !v15 )
    goto LABEL_27;
  v16 = 0;
  while ( 1 )
  {
    v17 = v7 + 1728 + 40LL * v16;
    if ( *(_DWORD *)(v17 + 28) == 10 )
      break;
    if ( v15 == ++v16 )
      goto LABEL_27;
  }
  v23 = *(_QWORD *)(v17 + 8);
  if ( v23 )
  {
    v24 = (_DWORD *)(v23 + (a4 << 12));
    memcpy(v24, a2, a3);
    if ( a3 != 4096 )
      memset((char *)v24 + a3, 0, 4096 - a3);
    v24[1] = 1;
    return 0;
  }
  else
  {
LABEL_27:
    v25 = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(v25 + 16) & 0xF0000) != 0 )
    {
      v26 = "irq";
    }
    else
    {
      v27 = *(_DWORD *)(v25 + 16);
      v28 = (const char *)(v25 + 2320);
      if ( (v27 & 0xFF00) != 0 )
        v26 = "soft_irq";
      else
        v26 = v28;
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v26,
      "cnss_send_buffer_to_afcmem",
      3u,
      3u,
      "AFC mem is not available\n",
      a4,
      v8,
      vars0);
    return 4294967284LL;
  }
}
