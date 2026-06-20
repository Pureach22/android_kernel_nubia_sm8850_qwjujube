__int64 __fastcall cnss_pci_handle_dev_sol_irq(
        __int64 *a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  __int64 v9; // x20
  char v10; // w0
  unsigned __int64 StatusReg; // x20
  const char *v12; // x1
  unsigned __int64 v13; // x8
  const char *v14; // x1
  __int64 v15; // x7
  __int64 v16; // x22
  __int64 result; // x0
  const char *v18; // x1
  __int16 v19; // w9
  const char *v20; // x8
  void (__fastcall *v21)(__int64, __int64); // x8
  __int64 v22; // x0
  unsigned __int64 v29; // x9
  char v30; // [xsp+0h] [xbp-10h]
  char v31; // [xsp+0h] [xbp-10h]

  if ( a1 )
  {
    v9 = a1[1];
    cnss_ignore_qmi_failure(1);
    _X8 = (unsigned __int64 *)(v9 + 552);
    __asm { PRFM            #0x11, [X8] }
    do
      v29 = __ldxr(_X8);
    while ( __stxr(v29 | 0x800, _X8) );
    timer_delete((timer_t)(v9 + 6272));
    *((_DWORD *)a1 + 92) = 0;
    v10 = mod_timer(a1 + 50, jiffies + 1250LL);
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
      "__cnss_start_rddm_timer",
      7u,
      7u,
      "Start RDDM timer @%s(%d), ret %d\n",
      (__int64)"cnss_pci_handle_mhi_sys_err",
      7828,
      v10);
    v16 = a1[5];
    result = 0;
    if ( (*(_QWORD *)(a1[1] + 552) & 0x20) == 0 && v16 )
    {
      if ( *(_QWORD *)(v16 + 104) )
      {
        if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
        {
          v18 = "irq";
        }
        else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
        {
          v18 = "soft_irq";
        }
        else
        {
          v18 = (const char *)(StatusReg + 2320);
        }
        cnss_debug_ipc_log_print(
          cnss_ipc_log_context,
          v18,
          "cnss_pci_update_status",
          7u,
          7u,
          "Update driver status: %d\n",
          4,
          v15,
          v31);
        v21 = *(void (__fastcall **)(__int64, __int64))(v16 + 104);
        v22 = *a1;
        if ( *((_DWORD *)v21 - 1) != -1174368176 )
          __break(0x8228u);
        v21(v22, 4);
      }
      return 0;
    }
  }
  else
  {
    v13 = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(v13 + 16) & 0xF0000) != 0 )
    {
      v14 = "irq";
    }
    else
    {
      v19 = *(_DWORD *)(v13 + 16);
      v20 = (const char *)(v13 + 2320);
      if ( (v19 & 0xFF00) != 0 )
        v14 = "soft_irq";
      else
        v14 = v20;
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v14,
      "cnss_pci_handle_dev_sol_irq",
      3u,
      3u,
      "pci priv is null\n",
      a7,
      a8,
      v30);
    return 4294967277LL;
  }
  return result;
}
