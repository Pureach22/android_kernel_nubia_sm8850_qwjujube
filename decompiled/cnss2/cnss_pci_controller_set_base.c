__int64 __fastcall cnss_pci_controller_set_base(
        __int64 result,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  char v8; // w29
  unsigned int v9; // w8
  bool v10; // cc
  int v11; // w8
  __int64 v13; // x19
  unsigned __int64 StatusReg; // x8
  const char *v15; // x1
  __int16 v16; // w9
  const char *v17; // x8

  v9 = *(_DWORD *)(result + 24) - 4359;
  v10 = v9 > 0xB;
  v11 = (1 << v9) & 0xC81;
  if ( !v10 && v11 != 0 )
  {
    v13 = result;
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v15 = "irq";
    }
    else
    {
      v16 = *(_DWORD *)(StatusReg + 16);
      v17 = (const char *)(StatusReg + 2320);
      if ( (v16 & 0xFF00) != 0 )
        v15 = "soft_irq";
      else
        v15 = v17;
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v15,
      "cnss_pci_controller_set_base",
      7u,
      7u,
      "Remove MHI satellite configuration\n",
      a7,
      a8,
      v8);
    return mhi_controller_set_base(*(_QWORD *)(v13 + 344));
  }
  return result;
}
