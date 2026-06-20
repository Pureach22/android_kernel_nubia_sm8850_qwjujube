__int64 __fastcall cnss_pci_prevent_l1(
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
  unsigned int v10; // w19
  unsigned __int64 StatusReg; // x8
  const char *v12; // x1
  __int16 v13; // w9
  const char *v14; // x8
  char vars0; // [xsp+0h] [xbp+0h]

  v8 = *(_QWORD *)(a1 + 152);
  if ( v8 )
  {
    mutex_lock(v8 + 600);
    v10 = _cnss_pci_prevent_l1(a1);
    mutex_unlock(v8 + 600);
  }
  else
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
      "cnss_pci_prevent_l1",
      3u,
      3u,
      "pci_priv is NULL\n",
      a7,
      a8,
      vars0);
    return (unsigned int)-19;
  }
  return v10;
}
