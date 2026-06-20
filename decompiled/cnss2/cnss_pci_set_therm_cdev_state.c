__int64 __fastcall cnss_pci_set_therm_cdev_state(
        __int64 *a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  __int64 v8; // x8
  __int64 (__fastcall *v9)(_QWORD); // x8
  __int64 v10; // x0
  unsigned __int64 StatusReg; // x8
  const char *v13; // x1
  unsigned __int64 v14; // x8
  const char *v15; // x1
  __int16 v16; // w9
  const char *v17; // x8
  __int16 v18; // w9
  const char *v19; // x8
  char vars0; // [xsp+0h] [xbp+0h]

  if ( a1 )
  {
    v8 = a1[5];
    if ( v8 && (v9 = *(__int64 (__fastcall **)(_QWORD))(v8 + 160)) != nullptr )
    {
      v10 = *a1;
      if ( *((_DWORD *)v9 - 1) != 2121954381 )
        __break(0x8228u);
      return v9(v10);
    }
    else
    {
      StatusReg = _ReadStatusReg(SP_EL0);
      if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
      {
        v13 = "irq";
      }
      else
      {
        v16 = *(_DWORD *)(StatusReg + 16);
        v17 = (const char *)(StatusReg + 2320);
        if ( (v16 & 0xFF00) != 0 )
          v13 = "soft_irq";
        else
          v13 = v17;
      }
      cnss_debug_ipc_log_print(
        cnss_ipc_log_context,
        v13,
        "cnss_pci_set_therm_cdev_state",
        3u,
        3u,
        "driver_ops or set_therm_cdev_state is NULL\n",
        a7,
        a8,
        vars0);
      return 4294967274LL;
    }
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
      v18 = *(_DWORD *)(v14 + 16);
      v19 = (const char *)(v14 + 2320);
      if ( (v18 & 0xFF00) != 0 )
        v15 = "soft_irq";
      else
        v15 = v19;
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v15,
      "cnss_pci_set_therm_cdev_state",
      3u,
      3u,
      "pci_priv is NULL!\n",
      a7,
      a8,
      vars0);
    return 4294967277LL;
  }
}
