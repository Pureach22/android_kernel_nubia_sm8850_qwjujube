__int64 __fastcall cnss_pci_dev_crash_shutdown(
        __int64 *a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  __int64 v8; // x6
  __int64 v9; // x20
  unsigned __int64 v10; // x9
  const char *v12; // x1
  unsigned __int64 StatusReg; // x8
  const char *v14; // x1
  __int16 v15; // w10
  const char *v16; // x9
  __int16 v17; // w9
  const char *v18; // x8
  __int64 v20; // x8
  void (__fastcall *v21)(_QWORD); // x8
  __int64 v22; // x0
  unsigned __int64 v23; // x8
  const char *v24; // x1
  __int16 v25; // w9
  const char *v26; // x8
  unsigned __int64 v33; // x9
  unsigned __int64 v36; // x10
  char vars0; // [xsp+0h] [xbp+0h]

  if ( !a1 )
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
      "cnss_pci_dev_crash_shutdown",
      3u,
      3u,
      "pci_priv is NULL\n",
      a7,
      a8,
      vars0);
    return 4294967277LL;
  }
  v8 = *((unsigned int *)a1 + 6);
  if ( (unsigned int)(v8 - 4352) <= 0x12 && ((1 << *((_DWORD *)a1 + 6)) & 0x6448F) != 0 )
  {
    v9 = a1[1];
    _X8 = (unsigned __int64 *)(v9 + 552);
    __asm { PRFM            #0x11, [X8] }
    do
      v33 = __ldxr(_X8);
    while ( __stxr(v33 | 0x40000, _X8) );
    v10 = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(v10 + 16) & 0xF0000) != 0 )
    {
      v12 = "irq";
    }
    else
    {
      v15 = *(_DWORD *)(v10 + 16);
      v16 = (const char *)(v10 + 2320);
      if ( (v15 & 0xFF00) != 0 )
        v12 = "soft_irq";
      else
        v12 = v16;
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v12,
      "cnss_qca6290_crash_shutdown",
      7u,
      7u,
      "Crash shutdown with driver_state 0x%lx\n",
      *(_QWORD *)(v9 + 552),
      a8,
      vars0);
    cnss_pci_collect_dump_info(a1, 1);
    _X8 = (unsigned __int64 *)(v9 + 552);
    __asm { PRFM            #0x11, [X8] }
    do
      v36 = __ldxr(_X8);
    while ( __stxr(v36 & 0xFFFFFFFFFFFBFFFFLL, _X8) );
    return 0;
  }
  if ( (_DWORD)v8 != 62 )
  {
    v23 = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(v23 + 16) & 0xF0000) != 0 )
    {
      v24 = "irq";
    }
    else
    {
      v25 = *(_DWORD *)(v23 + 16);
      v26 = (const char *)(v23 + 2320);
      if ( (v25 & 0xFF00) != 0 )
        v24 = "soft_irq";
      else
        v24 = v26;
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v24,
      "cnss_pci_dev_crash_shutdown",
      3u,
      3u,
      "Unknown device_id found: 0x%x\n",
      v8,
      a8,
      vars0);
    return 4294967277LL;
  }
  v20 = a1[5];
  if ( !v20 )
    return 0;
  v21 = *(void (__fastcall **)(_QWORD))(v20 + 56);
  if ( !v21 )
    return 0;
  v22 = *a1;
  if ( *((_DWORD *)v21 - 1) != -1303601879 )
    __break(0x8228u);
  v21(v22);
  return 0;
}
