__int64 __fastcall cnss_wlfw_fw_mem_ready_ind_cb(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  unsigned __int64 StatusReg; // x21
  const char *v11; // x1
  __int64 v12; // x6
  __int64 v13; // x7
  const char *v15; // x1
  char vars0; // [xsp+0h] [xbp+0h]
  char vars0a; // [xsp+0h] [xbp+0h]

  StatusReg = _ReadStatusReg(SP_EL0);
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
  cnss_debug_ipc_log_print(
    cnss_ipc_log_context,
    v11,
    "cnss_wlfw_fw_mem_ready_ind_cb",
    7u,
    7u,
    "Received QMI WLFW FW memory ready indication\n",
    a7,
    a8,
    vars0);
  if ( a3 )
    return cnss_driver_event_post(a1 - 856, 3u, 0, 0);
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
  return cnss_debug_ipc_log_print(
           cnss_ipc_log_context,
           v15,
           "cnss_wlfw_fw_mem_ready_ind_cb",
           3u,
           3u,
           "Spurious indication\n",
           v12,
           v13,
           vars0a);
}
