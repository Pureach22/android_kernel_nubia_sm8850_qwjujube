__int64 __fastcall cnss_pci_update_status(
        __int64 *a1,
        unsigned int a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  __int64 v8; // x20
  unsigned int v9; // w8
  unsigned __int64 StatusReg; // x9
  const char *v13; // x1
  __int16 v15; // w10
  const char *v16; // x9
  _DWORD *v17; // x8
  __int64 v18; // x0
  char v19; // [xsp+0h] [xbp+0h]

  if ( !a1 )
    return 4294967277LL;
  v8 = a1[5];
  v9 = -22;
  if ( (*(_QWORD *)(a1[1] + 552) & 0x20) == 0 && v8 )
  {
    if ( *(_QWORD *)(v8 + 104) )
    {
      StatusReg = _ReadStatusReg(SP_EL0);
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
        cnss_ipc_log_context,
        v13,
        "cnss_pci_update_status",
        7u,
        7u,
        "Update driver status: %d\n",
        a2,
        a8,
        v19);
      v17 = *(_DWORD **)(v8 + 104);
      v18 = *a1;
      if ( *(v17 - 1) != -1174368176 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, _QWORD))v17)(v18, a2);
      return 0;
    }
    else
    {
      return (unsigned int)-22;
    }
  }
  return v9;
}
