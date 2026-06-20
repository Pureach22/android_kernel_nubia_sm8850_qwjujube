__int64 __fastcall cnss_wlfw_process_twt_cfg_ind(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        unsigned __int8 *a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  unsigned __int64 v9; // x21
  __int64 v10; // x0
  int v12; // w8
  const char *v13; // x1
  unsigned __int64 StatusReg; // x8
  const char *v15; // x1
  __int64 result; // x0
  __int16 v17; // w9
  const char *v18; // x8
  const char *v19; // x5
  char v20; // [xsp+0h] [xbp-50h]

  if ( !a3 )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    v10 = cnss_ipc_log_context;
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v15 = "irq";
    }
    else
    {
      v17 = *(_DWORD *)(StatusReg + 16);
      v18 = (const char *)(StatusReg + 2320);
      if ( (v17 & 0xFF00) != 0 )
        v15 = "soft_irq";
      else
        v15 = v18;
    }
    v19 = "FW->CNSS: TWT_CFG_IND: Spurious indication\n";
    return cnss_debug_ipc_log_print(v10, v15, "cnss_wlfw_process_twt_cfg_ind", 3u, 3u, v19, a7, a8, v20);
  }
  v9 = _ReadStatusReg(SP_EL0);
  v10 = cnss_ipc_log_context;
  v12 = *(_DWORD *)(v9 + 16) & 0xF0000;
  if ( !a4 )
  {
    if ( v12 )
    {
      v15 = "irq";
    }
    else if ( (*(_DWORD *)(v9 + 16) & 0xFF00) != 0 )
    {
      v15 = "soft_irq";
    }
    else
    {
      v15 = (const char *)(v9 + 2320);
    }
    v19 = "FW->CNSS: TWT_CFG_IND: Invalid indication\n";
    return cnss_debug_ipc_log_print(v10, v15, "cnss_wlfw_process_twt_cfg_ind", 3u, 3u, v19, a7, a8, v20);
  }
  if ( v12 )
  {
    v13 = "irq";
  }
  else if ( (*(_DWORD *)(v9 + 16) & 0xFF00) != 0 )
  {
    v13 = "soft_irq";
  }
  else
  {
    v13 = (const char *)(v9 + 2320);
  }
  cnss_debug_ipc_log_print(
    cnss_ipc_log_context,
    v13,
    "cnss_wlfw_process_twt_cfg_ind",
    7u,
    7u,
    "FW->CNSS: TWT_CFG_IND: %x %llx, %x %x, %x %x, %x %x, %x %x, %x %x\n",
    *a4,
    *((_QWORD *)a4 + 1),
    a4[16]);
  result = kmemdup_noprof(a4);
  if ( result )
    return cnss_driver_event_post(a1 - 856, 0x10u, 0, result);
  return result;
}
