__int64 __fastcall cnss_aop_interface_init(__int64 *a1)
{
  __int64 v1; // x9
  unsigned __int64 v3; // x0
  __int64 v4; // x6
  __int64 v5; // x7
  int v6; // w20
  unsigned __int64 v7; // x22
  const char *v8; // x1
  unsigned __int64 StatusReg; // x8
  __int64 v10; // x0
  const char *v11; // x1
  __int64 v12; // x8
  unsigned __int64 v13; // x0
  unsigned int v14; // w20
  const char *v15; // x1
  __int16 v16; // w9
  const char *v17; // x8
  const char *v18; // x2
  const char *v19; // x5
  __int64 v20; // x7
  unsigned __int64 v21; // x8
  const char *v22; // x1
  __int16 v23; // w9
  const char *v24; // x8
  char vars0; // [xsp+0h] [xbp+0h]

  v1 = *a1;
  a1[950] = 1000;
  a1[955] = 0;
  a1[948] = v1 + 16;
  *((_BYTE *)a1 + 7592) = 1;
  *((_BYTE *)a1 + 7608) = 0;
  v3 = mbox_request_channel(a1 + 948, 0);
  v6 = v3;
  if ( v3 < 0xFFFFFFFFFFFFF001LL )
  {
    a1[955] = v3;
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
    v18 = "cnss_mbox_init";
    v19 = "Mbox channel initialized\n";
LABEL_28:
    cnss_debug_ipc_log_print(v10, v11, v18, 7u, 7u, v19, v4, v5, vars0);
    goto LABEL_29;
  }
  v7 = _ReadStatusReg(SP_EL0);
  if ( (*(_DWORD *)(v7 + 16) & 0xF0000) != 0 )
  {
    v8 = "irq";
  }
  else if ( (*(_DWORD *)(v7 + 16) & 0xFF00) != 0 )
  {
    v8 = "soft_irq";
  }
  else
  {
    v8 = (const char *)(v7 + 2320);
  }
  cnss_debug_ipc_log_print(
    cnss_ipc_log_context,
    v8,
    "cnss_mbox_init",
    7u,
    7u,
    "Failed to get mbox channel[%d]\n",
    (unsigned int)v3,
    v5,
    vars0);
  if ( v6 )
  {
    v12 = *a1;
    a1[956] = 0;
    v13 = qmp_get(v12 + 16);
    v14 = v13;
    if ( v13 >= 0xFFFFFFFFFFFFF001LL )
    {
      if ( (*(_DWORD *)(v7 + 16) & 0xF0000) != 0 )
      {
        v15 = "irq";
      }
      else if ( (*(_DWORD *)(v7 + 16) & 0xFF00) != 0 )
      {
        v15 = "soft_irq";
      }
      else
      {
        v15 = (const char *)(v7 + 2320);
      }
      cnss_debug_ipc_log_print(
        cnss_ipc_log_context,
        v15,
        "cnss_qmp_init",
        3u,
        3u,
        "Failed to get qmp: %d\n",
        v13,
        v5,
        vars0);
      if ( v14 )
        return v14;
      goto LABEL_29;
    }
    a1[956] = v13;
    v10 = cnss_ipc_log_context;
    if ( (*(_DWORD *)(v7 + 16) & 0xF0000) != 0 )
    {
      v11 = "irq";
    }
    else if ( (*(_DWORD *)(v7 + 16) & 0xFF00) != 0 )
    {
      v11 = "soft_irq";
    }
    else
    {
      v11 = (const char *)(v7 + 2320);
    }
    v18 = "cnss_qmp_init";
    v19 = "QMP initialized\n";
    goto LABEL_28;
  }
LABEL_29:
  v14 = cnss_aop_pdc_reconfig(a1);
  if ( v14 )
  {
    v21 = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(v21 + 16) & 0xF0000) != 0 )
    {
      v22 = "irq";
    }
    else
    {
      v23 = *(_DWORD *)(v21 + 16);
      v24 = (const char *)(v21 + 2320);
      if ( (v23 & 0xFF00) != 0 )
        v22 = "soft_irq";
      else
        v22 = v24;
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v22,
      "cnss_aop_interface_init",
      3u,
      3u,
      "Failed to reconfig WLAN PDC, err = %d\n",
      v14,
      v20,
      vars0);
  }
  return v14;
}
