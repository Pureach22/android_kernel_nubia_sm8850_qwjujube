__int64 __fastcall cnss_pci_shutdown_cleanup(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  int v8; // w0
  unsigned __int64 StatusReg; // x9
  unsigned int v10; // w19
  const char *v11; // x1
  unsigned __int64 v12; // x8
  const char *v13; // x1
  __int16 v14; // w10
  const char *v15; // x9
  __int16 v16; // w9
  const char *v17; // x8
  unsigned __int64 v25; // x10
  char v26; // [xsp+0h] [xbp-10h]

  if ( a1 )
  {
    _X8 = (unsigned __int64 *)(*(_QWORD *)(a1 + 8) + 6680LL);
    __asm { PRFM            #0x11, [X8] }
    do
      v25 = __ldxr(_X8);
    while ( __stxr(v25 & 0xFFFFFFFFFFFFBFFFLL, _X8) );
    *(_DWORD *)(a1 + 440) = 0;
    v8 = timer_delete((timer_t)(a1 + 400));
    StatusReg = _ReadStatusReg(SP_EL0);
    v10 = v8;
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v11 = "irq";
    }
    else
    {
      v14 = *(_DWORD *)(StatusReg + 16);
      v15 = (const char *)(StatusReg + 2320);
      if ( (v14 & 0xFF00) != 0 )
        v11 = "soft_irq";
      else
        v11 = v15;
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v11,
      "__cnss_del_rddm_timer",
      7u,
      7u,
      "Delete RDDM timer @%s(%d), ret %d\n",
      (__int64)"cnss_pci_shutdown_cleanup",
      2021,
      v8);
  }
  else
  {
    v12 = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(v12 + 16) & 0xF0000) != 0 )
    {
      v13 = "irq";
    }
    else
    {
      v16 = *(_DWORD *)(v12 + 16);
      v17 = (const char *)(v12 + 2320);
      if ( (v16 & 0xFF00) != 0 )
        v13 = "soft_irq";
      else
        v13 = v17;
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v13,
      "cnss_pci_shutdown_cleanup",
      3u,
      3u,
      "pci_priv is NULL\n",
      a7,
      a8,
      v26);
    return (unsigned int)-19;
  }
  return v10;
}
