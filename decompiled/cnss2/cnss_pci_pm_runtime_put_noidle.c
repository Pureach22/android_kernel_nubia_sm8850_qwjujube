__int64 __fastcall cnss_pci_pm_runtime_put_noidle(
        __int64 result,
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
  unsigned int v11; // w9
  unsigned int v14; // w11
  unsigned __int64 v15; // x8
  const char *v16; // x1
  __int16 v17; // w9
  const char *v18; // x8
  unsigned int v25; // w9
  unsigned int v27; // w10
  char vars0; // [xsp+0h] [xbp+0h]

  if ( result )
  {
    v8 = *(_QWORD *)result;
    if ( *(_DWORD *)(*(_QWORD *)result + 680LL) )
    {
      if ( a2 <= 1 )
      {
        _X8 = (unsigned int *)(result + 172);
        __asm { PRFM            #0x11, [X8] }
        do
          v25 = __ldxr(_X8);
        while ( __stxr(v25 + 1, _X8) );
        _X9 = (unsigned int *)(result + 4LL * a2 + 184);
        __asm { PRFM            #0x11, [X9] }
        do
          v27 = __ldxr(_X9);
        while ( __stxr(v27 + 1, _X9) );
        __isb(0xFu);
        StatusReg = _ReadStatusReg(CNTVCT_EL0);
        v8 = *(_QWORD *)result;
        *(_QWORD *)(result + 8LL * a2 + 208) = 10 * (StatusReg / 0xC0);
      }
      v11 = *(_DWORD *)(v8 + 680);
      do
      {
        if ( !v11 )
          break;
        _X13 = (unsigned int *)(v8 + 680);
        __asm { PRFM            #0x11, [X13] }
        while ( 1 )
        {
          v14 = __ldxr(_X13);
          if ( v14 != v11 )
            break;
          if ( !__stlxr(v11 - 1, _X13) )
          {
            __dmb(0xBu);
            break;
          }
        }
        _ZF = v14 == v11;
        v11 = v14;
      }
      while ( !_ZF );
    }
    else
    {
      v15 = _ReadStatusReg(SP_EL0);
      if ( (*(_DWORD *)(v15 + 16) & 0xF0000) != 0 )
      {
        v16 = "irq";
      }
      else
      {
        v17 = *(_DWORD *)(v15 + 16);
        v18 = (const char *)(v15 + 2320);
        if ( (v17 & 0xFF00) != 0 )
          v16 = "soft_irq";
        else
          v16 = v18;
      }
      return cnss_debug_ipc_log_print(
               cnss_ipc_log_context,
               v16,
               "cnss_pci_pm_runtime_put_noidle",
               7u,
               7u,
               "Ignore excessive runtime PM put operation\n",
               a7,
               a8,
               vars0);
    }
  }
  return result;
}
