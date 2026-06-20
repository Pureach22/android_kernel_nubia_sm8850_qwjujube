__int64 __fastcall cnss_wlfw_pin_result_ind_cb(
        _DWORD *a1,
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
  const char *v15; // x1
  const char *v16; // x1
  char v18; // [xsp+0h] [xbp-10h]
  char v19; // [xsp+0h] [xbp-10h]

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
    "cnss_wlfw_pin_result_ind_cb",
    7u,
    7u,
    "Received QMI WLFW pin connect result indication\n",
    a7,
    a8,
    v18);
  if ( a3 )
  {
    if ( *(_BYTE *)a4 )
      a1[1346] = *(_DWORD *)(a4 + 4);
    if ( *(_BYTE *)(a4 + 8) )
      a1[1347] = *(_DWORD *)(a4 + 12);
    if ( *(_BYTE *)(a4 + 16) )
      a1[1348] = *(_DWORD *)(a4 + 20);
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
             "cnss_wlfw_pin_result_ind_cb",
             7u,
             7u,
             "Pin connect Result: pwr_pin: 0x%x phy_io_pin: 0x%x rf_io_pin: 0x%x\n",
             *(unsigned int *)(a4 + 4),
             *(unsigned int *)(a4 + 12),
             *(_DWORD *)(a4 + 20));
  }
  else
  {
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
    return cnss_debug_ipc_log_print(
             cnss_ipc_log_context,
             v16,
             "cnss_wlfw_pin_result_ind_cb",
             3u,
             3u,
             "Spurious indication\n",
             v13,
             v14,
             v19);
  }
}
