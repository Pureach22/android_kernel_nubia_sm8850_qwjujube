__int64 __fastcall cnss_pci_register_driver_hdlr(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  __int64 v8; // x20
  __int64 result; // x0
  unsigned __int64 StatusReg; // x8
  const char *v12; // x1
  __int16 v13; // w9
  const char *v14; // x8
  unsigned __int64 v21; // x9
  unsigned __int64 v24; // x10
  unsigned __int64 v27; // x9
  char vars0; // [xsp+0h] [xbp+0h]

  v8 = *(_QWORD *)(a1 + 8);
  if ( (*(_QWORD *)(v8 + 552) & 0x10000) != 0 )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v12 = "irq";
    }
    else
    {
      v13 = *(_DWORD *)(StatusReg + 16);
      v14 = (const char *)(StatusReg + 2320);
      if ( (v13 & 0xFF00) != 0 )
        v12 = "soft_irq";
      else
        v12 = v14;
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v12,
      "cnss_pci_register_driver_hdlr",
      7u,
      7u,
      "Reboot or shutdown is in progress, ignore register driver\n",
      a7,
      a8,
      vars0);
    return 4294967274LL;
  }
  else
  {
    _X8 = (unsigned __int64 *)(v8 + 552);
    __asm { PRFM            #0x11, [X8] }
    do
      v21 = __ldxr(_X8);
    while ( __stxr(v21 | 0x10, _X8) );
    *(_QWORD *)(a1 + 40) = a2;
    result = cnss_pci_dev_powerup(a1, a2, a3, a4, a5, a6, a7, a8);
    if ( (_DWORD)result )
    {
      _X8 = (unsigned __int64 *)(v8 + 552);
      __asm { PRFM            #0x11, [X8] }
      do
        v24 = __ldxr(_X8);
      while ( __stxr(v24 & 0xFFFFFFFFFFFFFFEFLL, _X8) );
      *(_QWORD *)(a1 + 40) = 0;
    }
    else
    {
      _X8 = (unsigned __int64 *)(v8 + 552);
      __asm { PRFM            #0x11, [X8] }
      do
        v27 = __ldxr(_X8);
      while ( __stxr(v27 | 0x4000000, _X8) );
      return 0;
    }
  }
  return result;
}
