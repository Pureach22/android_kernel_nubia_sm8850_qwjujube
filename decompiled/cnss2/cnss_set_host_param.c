__int64 __fastcall cnss_set_host_param(
        __int64 a1,
        _QWORD *a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  __int64 v9; // x0
  __int64 v10; // x19
  __int64 v11; // x6
  __int64 v12; // x7
  __int64 *v13; // x21
  __int64 v14; // x0
  _QWORD *v15; // x8
  unsigned __int64 StatusReg; // x8
  __int64 v18; // x0
  const char *v19; // x1
  unsigned __int64 v20; // x8
  __int16 v21; // w9
  const char *v22; // x8
  const char *v23; // x5
  unsigned __int64 v24; // x8
  __int64 v25; // x0
  const char *v26; // x1
  __int16 v27; // w9
  const char *v28; // x8
  __int16 v29; // w9
  const char *v30; // x8
  const char *v31; // x5
  unsigned __int64 v32; // x8
  __int16 v33; // w9
  const char *v34; // x8
  char v35; // [xsp+0h] [xbp+0h]

  if ( !a1 )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    v18 = cnss_ipc_log_context;
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v19 = "irq";
    }
    else
    {
      v21 = *(_DWORD *)(StatusReg + 16);
      v22 = (const char *)(StatusReg + 2320);
      if ( (v21 & 0xFF00) != 0 )
        v19 = "soft_irq";
      else
        v19 = v22;
    }
    v23 = "Invalid dev pointer\n";
    goto LABEL_24;
  }
  v9 = cnss_bus_dev_to_plat_priv(a1, (__int64)a2);
  if ( !v9 )
    return 4294967277LL;
  if ( !a2 )
  {
    v20 = _ReadStatusReg(SP_EL0);
    v18 = cnss_ipc_log_context;
    if ( (*(_DWORD *)(v20 + 16) & 0xF0000) != 0 )
    {
      v19 = "irq";
    }
    else
    {
      v27 = *(_DWORD *)(v20 + 16);
      v28 = (const char *)(v20 + 2320);
      if ( (v27 & 0xFF00) != 0 )
        v19 = "soft_irq";
      else
        v19 = v28;
    }
    v23 = "Invalid host_param pointer\n";
LABEL_24:
    cnss_debug_ipc_log_print(v18, v19, "cnss_set_host_param", 3u, 3u, v23, a7, a8, v35);
    return 4294967274LL;
  }
  v10 = v9;
  v13 = (__int64 *)_kmalloc_cache_noprof(of_find_compatible_node, 3264, 8);
  if ( !v13 )
  {
    v32 = _ReadStatusReg(SP_EL0);
    v25 = cnss_ipc_log_context;
    if ( (*(_DWORD *)(v32 + 16) & 0xF0000) != 0 )
    {
      v26 = "irq";
    }
    else
    {
      v33 = *(_DWORD *)(v32 + 16);
      v34 = (const char *)(v32 + 2320);
      if ( (v33 & 0xFF00) != 0 )
        v26 = "soft_irq";
      else
        v26 = v34;
    }
    v31 = "Failed to allocate memory for host_param\n";
    goto LABEL_35;
  }
  v14 = kstrdup(*a2, 3264);
  *v13 = v14;
  if ( !v14 )
  {
    kfree(v13);
    v24 = _ReadStatusReg(SP_EL0);
    v25 = cnss_ipc_log_context;
    if ( (*(_DWORD *)(v24 + 16) & 0xF0000) != 0 )
    {
      v26 = "irq";
    }
    else
    {
      v29 = *(_DWORD *)(v24 + 16);
      v30 = (const char *)(v24 + 2320);
      if ( (v29 & 0xFF00) != 0 )
        v26 = "soft_irq";
      else
        v26 = v30;
    }
    v31 = "Failed to allocate memory for chip_name\n";
LABEL_35:
    cnss_debug_ipc_log_print(v25, v26, "cnss_set_host_param", 3u, 3u, v31, v11, v12, v35);
    return 4294967284LL;
  }
  v15 = *(_QWORD **)(v10 + 8000);
  if ( v15 )
  {
    kfree(*v15);
    kfree(*(_QWORD *)(v10 + 8000));
  }
  *(_QWORD *)(v10 + 8000) = v13;
  return 0;
}
