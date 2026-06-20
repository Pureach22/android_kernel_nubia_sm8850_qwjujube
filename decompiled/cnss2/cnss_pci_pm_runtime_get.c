__int64 __fastcall cnss_pci_pm_runtime_get(
        unsigned int *a1,
        unsigned int a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  __int64 v8; // x30
  __int64 v9; // x19
  unsigned __int64 StatusReg; // x9
  unsigned int v11; // w20
  unsigned int *v12; // x21
  const char *v13; // x1
  __int16 v15; // w10
  const char *v16; // x9
  unsigned int v24; // w9
  unsigned int v26; // w10
  char v27; // [xsp+0h] [xbp+0h]

  if ( !a1 )
    return 4294967277LL;
  v9 = *(_QWORD *)a1;
  if ( (*(_DWORD *)(*(_QWORD *)a1 + 700LL) & 0xFFFFFFFE) == 2 )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    v11 = a2;
    v12 = a1;
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v13 = "irq";
    }
    else
    {
      v15 = *(_DWORD *)(StatusReg + 16);
      v16 = (const char *)(StatusReg + 2320);
      if ( (v15 & 0xFF00) != 0 )
        v13 = "soft_irq";
      else
        v13 = v16;
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_long_context,
      v13,
      "cnss_pci_pm_runtime_get",
      7u,
      7u,
      "Runtime PM resume is requested by %ps\n",
      v8,
      a8,
      v27);
    a1 = v12;
    a2 = v11;
  }
  if ( a2 <= 1 )
  {
    _X8 = a1 + 42;
    __asm { PRFM            #0x11, [X8] }
    do
      v24 = __ldxr(_X8);
    while ( __stxr(v24 + 1, _X8) );
    _X9 = &a1[a2 + 44];
    __asm { PRFM            #0x11, [X9] }
    do
      v26 = __ldxr(_X9);
    while ( __stxr(v26 + 1, _X9) );
    __isb(0xFu);
    *(_QWORD *)&a1[2 * a2 + 48] = 10 * (_ReadStatusReg(CNTVCT_EL0) / 0xC0);
  }
  return _pm_runtime_resume(v9 + 200, 5);
}
