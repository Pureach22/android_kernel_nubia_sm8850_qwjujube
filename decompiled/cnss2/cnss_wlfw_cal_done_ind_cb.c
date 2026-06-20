_DWORD *__fastcall cnss_wlfw_cal_done_ind_cb(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  unsigned __int64 StatusReg; // x24
  const char *v12; // x1
  __int64 v13; // x22
  const char *v14; // x23
  unsigned int v15; // w0
  __int64 v16; // x7
  __int64 v17; // x6
  __int64 v18; // x7
  _DWORD *result; // x0
  const char *v20; // x1
  char v21; // [xsp+0h] [xbp+0h]
  char v22; // [xsp+0h] [xbp+0h]
  char v23; // [xsp+0h] [xbp+0h]

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
    "cnss_wlfw_cal_done_ind_cb",
    7u,
    7u,
    "Received Cal done indication. File size: %d\n",
    *(_QWORD *)(a4 + 8),
    a8,
    v21);
  v13 = cnss_ipc_log_context;
  if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
  {
    v14 = "irq";
  }
  else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    v14 = "soft_irq";
  }
  else
  {
    v14 = (const char *)(StatusReg + 2320);
  }
  v15 = jiffies_to_msecs(jiffies - *(_QWORD *)(a1 + 3240));
  cnss_debug_ipc_log_print(v13, v14, "cnss_wlfw_cal_done_ind_cb", 6u, 6u, "Calibration took %d ms\n", v15, v16, v22);
  if ( a3 )
  {
    if ( *(_BYTE *)a4 )
      *(_DWORD *)(a1 + 3252) = *(_QWORD *)(a4 + 8);
    result = (_DWORD *)_kmalloc_cache_noprof(of_find_compatible_node, 3520, 4);
    if ( result )
    {
      *result = 0;
      return (_DWORD *)cnss_driver_event_post(a1 - 856, 6u, 0, (__int64)result);
    }
  }
  else
  {
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v20 = "irq";
    }
    else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      v20 = "soft_irq";
    }
    else
    {
      v20 = (const char *)(StatusReg + 2320);
    }
    return (_DWORD *)cnss_debug_ipc_log_print(
                       cnss_ipc_log_context,
                       v20,
                       "cnss_wlfw_cal_done_ind_cb",
                       3u,
                       3u,
                       "Spurious indication\n",
                       v17,
                       v18,
                       v23);
  }
  return result;
}
