__int64 __fastcall cnss_wlfw_fw_init_done_ind_cb(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  unsigned __int64 StatusReg; // x22
  const char *v12; // x1
  __int64 v13; // x6
  __int64 v14; // x7
  __int64 v15; // x6
  const char *v16; // x1
  const char *v17; // x1
  char v19; // [xsp+0h] [xbp+0h]
  char v20; // [xsp+0h] [xbp+0h]

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
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
  cnss_debug_ipc_log_print(
    cnss_ipc_log_context,
    v12,
    "cnss_wlfw_fw_init_done_ind_cb",
    7u,
    7u,
    "Received QMI WLFW FW initialization done indication\n",
    a7,
    a8,
    v19);
  if ( a3 )
  {
    if ( *(_BYTE *)(a4 + 12) )
    {
      v15 = *(_QWORD *)(a4 + 16);
      *(_QWORD *)(a1 + 6672) = v15;
      if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
      {
        v16 = "irq";
      }
      else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
      {
        v16 = "soft_irq";
      }
      else
      {
        v16 = (const char *)(StatusReg + 2320);
      }
      cnss_debug_ipc_log_print(
        cnss_ipc_log_context,
        v16,
        "cnss_wlfw_fw_init_done_ind_cb",
        7u,
        7u,
        "SKU features enabled: %llu",
        v15,
        v14,
        v20);
    }
    return cnss_driver_event_post(a1 - 856, 4u, 0, 0);
  }
  else
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
    return cnss_debug_ipc_log_print(
             cnss_ipc_log_context,
             v17,
             "cnss_wlfw_fw_init_done_ind_cb",
             3u,
             3u,
             "Spurious indication\n",
             v13,
             v14,
             v20);
  }
}
