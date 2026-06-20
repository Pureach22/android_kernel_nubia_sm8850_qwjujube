__int64 __fastcall cnss_wlfw_xo_trim_ind_cb(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        _BYTE *a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  unsigned __int64 StatusReg; // x22
  int v9; // w9
  const char *v11; // x1
  const char *v12; // x1
  __int64 v13; // x19
  _BYTE *v14; // x0
  __int64 v15; // x6
  __int64 v16; // x7
  __int64 v17; // x21
  const char *v19; // x1
  char vars0; // [xsp+0h] [xbp+0h]
  char vars0a; // [xsp+0h] [xbp+0h]

  StatusReg = _ReadStatusReg(SP_EL0);
  v9 = *(_DWORD *)(StatusReg + 16) & 0xF0000;
  if ( a3 )
  {
    if ( v9 )
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
    v13 = a1 - 856;
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v11,
      "cnss_wlfw_xo_trim_ind_cb",
      7u,
      7u,
      "Received XO_TRIM with trim val: %d\n",
      (unsigned __int8)*a4,
      a8,
      vars0);
    v14 = (_BYTE *)_kmalloc_cache_noprof(of_find_compatible_node, 3520, 1);
    v17 = (__int64)v14;
    if ( v14 )
    {
      *v14 = *a4;
    }
    else
    {
      if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
      {
        v19 = "irq";
      }
      else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
      {
        v19 = "soft_irq";
      }
      else
      {
        v19 = (const char *)(StatusReg + 2320);
      }
      cnss_debug_ipc_log_print(
        cnss_ipc_log_context,
        v19,
        "cnss_wlfw_xo_trim_ind_cb",
        3u,
        3u,
        "Failed to allocate memory\n",
        v15,
        v16,
        vars0a);
    }
    return cnss_driver_event_post(v13, 0x16u, 0, v17);
  }
  else
  {
    if ( v9 )
    {
      v12 = "irq";
    }
    else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      v12 = "soft_irq";
    }
    else
    {
      v12 = (const char *)(StatusReg + 2320);
    }
    return cnss_debug_ipc_log_print(
             cnss_ipc_log_context,
             v12,
             "cnss_wlfw_xo_trim_ind_cb",
             3u,
             3u,
             "Spurious XO_TRIM indication\n",
             a7,
             a8,
             vars0);
  }
}
