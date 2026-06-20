_DWORD *__fastcall cnss_wlfw_fw_ready_ind_cb(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  unsigned __int64 StatusReg; // x8
  const char *v9; // x1
  unsigned __int64 v10; // x8
  const char *v11; // x1
  unsigned __int64 v13; // x20
  const char *v14; // x1
  __int16 v15; // w9
  const char *v16; // x8
  _DWORD *result; // x0
  __int16 v18; // w9
  const char *v19; // x8
  char v20; // [xsp+0h] [xbp+0h]

  if ( a3 )
  {
    if ( (*(_QWORD *)(a1 - 328) | 2LL) == 0x1103 )
    {
      StatusReg = _ReadStatusReg(SP_EL0);
      if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
      {
        v9 = "irq";
      }
      else
      {
        v15 = *(_DWORD *)(StatusReg + 16);
        v16 = (const char *)(StatusReg + 2320);
        if ( (v15 & 0xFF00) != 0 )
          v9 = "soft_irq";
        else
          v9 = v16;
      }
      return (_DWORD *)cnss_debug_ipc_log_print(
                         cnss_ipc_log_context,
                         v9,
                         "cnss_wlfw_fw_ready_ind_cb",
                         7u,
                         7u,
                         "Ignore FW Ready Indication for HST/HSP",
                         a7,
                         a8,
                         v20);
    }
    else
    {
      v13 = _ReadStatusReg(SP_EL0);
      if ( (*(_DWORD *)(v13 + 16) & 0xF0000) != 0 )
      {
        v14 = "irq";
      }
      else if ( (*(_DWORD *)(v13 + 16) & 0xFF00) != 0 )
      {
        v14 = "soft_irq";
      }
      else
      {
        v14 = (const char *)(v13 + 2320);
      }
      cnss_debug_ipc_log_print(
        cnss_ipc_log_context,
        v14,
        "cnss_wlfw_fw_ready_ind_cb",
        7u,
        7u,
        "Received QMI WLFW FW ready indication.\n",
        a7,
        a8,
        v20);
      result = (_DWORD *)_kmalloc_cache_noprof(of_find_compatible_node, 3520, 4);
      if ( result )
      {
        *result = 0;
        return (_DWORD *)cnss_driver_event_post(a1 - 856, 6u, 0, (__int64)result);
      }
    }
  }
  else
  {
    v10 = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(v10 + 16) & 0xF0000) != 0 )
    {
      v11 = "irq";
    }
    else
    {
      v18 = *(_DWORD *)(v10 + 16);
      v19 = (const char *)(v10 + 2320);
      if ( (v18 & 0xFF00) != 0 )
        v11 = "soft_irq";
      else
        v11 = v19;
    }
    return (_DWORD *)cnss_debug_ipc_log_print(
                       cnss_ipc_log_context,
                       v11,
                       "cnss_wlfw_fw_ready_ind_cb",
                       3u,
                       3u,
                       "Spurious indication\n",
                       a7,
                       a8,
                       v20);
  }
  return result;
}
