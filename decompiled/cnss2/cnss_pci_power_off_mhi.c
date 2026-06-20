__int64 __fastcall cnss_pci_power_off_mhi(
        __int64 result,
        char a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  unsigned __int64 StatusReg; // x8
  const char *v9; // x1
  __int64 v11; // x20
  int v12; // w1
  __int16 v13; // w9
  const char *v14; // x8
  unsigned __int64 v21; // x10
  unsigned __int64 v24; // x9
  char vars0; // [xsp+0h] [xbp+0h]

  if ( (*(_QWORD *)(*(_QWORD *)(result + 8) + 6680LL) & 0x80) == 0 )
  {
    if ( (*(_QWORD *)(result + 352) & 4) != 0 )
    {
      v11 = result;
      cnss_wlan_adsp_pc_enable(result, 1);
      _X8 = (unsigned __int64 *)(v11 + 352);
      __asm { PRFM            #0x11, [X8] }
      do
        v21 = __ldxr(_X8);
      while ( __stxr(v21 & 0xFFFFFFFFFFFFFFBFLL, _X8) );
      _X8 = (unsigned __int64 *)(v11 + 352);
      __asm { PRFM            #0x11, [X8] }
      do
        v24 = __ldxr(_X8);
      while ( __stxr(v24 | 8, _X8) );
      if ( *(_BYTE *)(v11 + 49) || (a2 & 1) != 0 )
        v12 = 5;
      else
        v12 = 4;
      return cnss_pci_set_mhi_state(v11, v12);
    }
    else
    {
      StatusReg = _ReadStatusReg(SP_EL0);
      if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
      {
        v9 = "irq";
      }
      else
      {
        v13 = *(_DWORD *)(StatusReg + 16);
        v14 = (const char *)(StatusReg + 2320);
        if ( (v13 & 0xFF00) != 0 )
          v9 = "soft_irq";
        else
          v9 = v14;
      }
      return cnss_debug_ipc_log_print(
               cnss_ipc_log_context,
               v9,
               "cnss_pci_power_off_mhi",
               7u,
               7u,
               "MHI is already powered off\n",
               a7,
               a8,
               vars0);
    }
  }
  return result;
}
