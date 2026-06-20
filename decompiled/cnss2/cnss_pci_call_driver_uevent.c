__int64 __fastcall cnss_pci_call_driver_uevent(
        __int64 *a1,
        unsigned int a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  __int64 v8; // x22
  unsigned __int64 StatusReg; // x8
  const char *v13; // x1
  unsigned __int64 v14; // x8
  const char *v15; // x1
  __int16 v16; // w9
  const char *v17; // x8
  __int64 result; // x0
  __int16 v19; // w9
  const char *v20; // x8
  _DWORD *v21; // x8
  __int64 v22; // x0
  char v23; // [xsp+0h] [xbp-20h]
  _QWORD v24[3]; // [xsp+8h] [xbp-18h] BYREF

  v24[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = a1[5];
  v24[0] = 0;
  if ( v8 && *(_QWORD *)(v8 + 112) )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v13 = "irq";
    }
    else
    {
      v19 = *(_DWORD *)(StatusReg + 16);
      v20 = (const char *)(StatusReg + 2320);
      if ( (v19 & 0xFF00) != 0 )
        v13 = "soft_irq";
      else
        v13 = v20;
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v13,
      "cnss_pci_call_driver_uevent",
      7u,
      7u,
      "Calling driver uevent: %d\n",
      a2,
      a8,
      v23);
    v21 = *(_DWORD **)(v8 + 112);
    v22 = *a1;
    LODWORD(v24[0]) = a2;
    v24[1] = a3;
    if ( *(v21 - 1) != 1109088313 )
      __break(0x8228u);
    result = ((__int64 (__fastcall *)(__int64, _QWORD *))v21)(v22, v24);
  }
  else
  {
    v14 = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(v14 + 16) & 0xF0000) != 0 )
    {
      v15 = "irq";
    }
    else
    {
      v16 = *(_DWORD *)(v14 + 16);
      v17 = (const char *)(v14 + 2320);
      if ( (v16 & 0xFF00) != 0 )
        v15 = "soft_irq";
      else
        v15 = v17;
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v15,
      "cnss_pci_call_driver_uevent",
      7u,
      7u,
      "Hang event driver ops is NULL\n",
      a7,
      a8,
      v23);
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
