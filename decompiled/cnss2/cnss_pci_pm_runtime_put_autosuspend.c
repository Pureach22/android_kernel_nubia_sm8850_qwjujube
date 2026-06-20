__int64 __fastcall cnss_pci_pm_runtime_put_autosuspend(
        unsigned int *a1,
        unsigned int a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  __int64 v8; // x8
  unsigned __int64 StatusReg; // x9
  unsigned __int64 v12; // x8
  const char *v13; // x1
  __int16 v14; // w9
  const char *v15; // x8
  unsigned int v22; // w9
  unsigned int v24; // w10
  char vars0; // [xsp+0h] [xbp+0h]

  if ( !a1 )
    return 4294967277LL;
  v8 = *(_QWORD *)a1;
  if ( *(_DWORD *)(*(_QWORD *)a1 + 680LL) )
  {
    if ( a2 <= 1 )
    {
      _X8 = a1 + 43;
      __asm { PRFM            #0x11, [X8] }
      do
        v22 = __ldxr(_X8);
      while ( __stxr(v22 + 1, _X8) );
      _X9 = &a1[a2 + 46];
      __asm { PRFM            #0x11, [X9] }
      do
        v24 = __ldxr(_X9);
      while ( __stxr(v24 + 1, _X9) );
      __isb(0xFu);
      StatusReg = _ReadStatusReg(CNTVCT_EL0);
      v8 = *(_QWORD *)a1;
      *(_QWORD *)&a1[2 * a2 + 52] = 10 * (StatusReg / 0xC0);
    }
    return _pm_runtime_suspend(v8 + 200, 13);
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
      v14 = *(_DWORD *)(v12 + 16);
      v15 = (const char *)(v12 + 2320);
      if ( (v14 & 0xFF00) != 0 )
        v13 = "soft_irq";
      else
        v13 = v15;
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v13,
      "cnss_pci_pm_runtime_put_autosuspend",
      7u,
      7u,
      "Ignore excessive runtime PM put operation\n",
      a7,
      a8,
      vars0);
    return 4294967274LL;
  }
}
