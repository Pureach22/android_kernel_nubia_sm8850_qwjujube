__int64 __fastcall wlfw_new_server(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  __int64 v8; // x19
  __int64 v10; // x6
  unsigned __int64 v11; // x21
  const char *v12; // x1
  unsigned __int64 StatusReg; // x8
  const char *v14; // x1
  _DWORD *v15; // x3
  int v16; // w9
  __int16 v17; // w9
  const char *v18; // x8
  char vars0; // [xsp+0h] [xbp+0h]

  v8 = a1 - 856;
  if ( a1 != 856 )
  {
    v10 = *(_QWORD *)(a1 - 304);
    if ( (v10 & 0x80000) != 0 )
    {
      StatusReg = _ReadStatusReg(SP_EL0);
      if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
      {
        v14 = "irq";
      }
      else
      {
        v17 = *(_DWORD *)(StatusReg + 16);
        v18 = (const char *)(StatusReg + 2320);
        if ( (v17 & 0xFF00) != 0 )
          v14 = "soft_irq";
        else
          v14 = v18;
      }
      cnss_debug_ipc_log_print(
        cnss_ipc_log_context,
        v14,
        "wlfw_new_server",
        6u,
        6u,
        "WLFW server delete in progress, Ignore server arrive, state: 0x%lx\n",
        v10,
        a8,
        vars0);
      return 0;
    }
  }
  v11 = _ReadStatusReg(SP_EL0);
  if ( (*(_DWORD *)(v11 + 16) & 0xF0000) != 0 )
  {
    v12 = "irq";
  }
  else if ( (*(_DWORD *)(v11 + 16) & 0xFF00) != 0 )
  {
    v12 = "soft_irq";
  }
  else
  {
    v12 = (const char *)(v11 + 2320);
  }
  cnss_debug_ipc_log_print(
    cnss_ipc_log_context,
    v12,
    "wlfw_new_server",
    7u,
    7u,
    "WLFW server arriving: node %u port %u\n",
    *(unsigned int *)(a2 + 12),
    *(unsigned int *)(a2 + 16),
    vars0);
  v15 = (_DWORD *)_kmalloc_cache_noprof(of_find_compatible_node, 3520, 8);
  if ( v15 )
  {
    v16 = *(_DWORD *)(a2 + 16);
    *v15 = *(_DWORD *)(a2 + 12);
    v15[1] = v16;
    cnss_driver_event_post(v8, 0, 0, (__int64)v15);
    return 0;
  }
  return 4294967284LL;
}
