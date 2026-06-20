__int64 __fastcall cnss_pci_suspend_pwroff(__int64 a1, __int64 a2)
{
  _BYTE *v2; // x20
  __int64 plat_priv_by_rc_num; // x19
  __int64 v4; // x1
  __int64 v5; // x2
  __int64 v6; // x3
  __int64 v7; // x4
  __int64 v8; // x5
  __int64 v9; // x6
  __int64 v10; // x7
  unsigned int v11; // w0
  __int64 v12; // x7
  unsigned __int64 StatusReg; // x8
  const char *v14; // x1
  __int16 v15; // w9
  const char *v16; // x8
  char vars0; // [xsp+0h] [xbp+0h]

  v2 = *(_BYTE **)(a1 + 352);
  plat_priv_by_rc_num = cnss_get_plat_priv_by_rc_num(*(unsigned int *)(*(_QWORD *)(a1 + 16) + 252LL), a2);
  v11 = cnss_suspend_pci_link(v2, v4, v5, v6, v7, v8, v9, v10);
  if ( v11 )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v14 = "irq";
    }
    else
    {
      v15 = *(_DWORD *)(StatusReg + 16);
      v16 = (const char *)(StatusReg + 2320);
      if ( (v15 & 0xFF00) != 0 )
        v14 = "soft_irq";
      else
        v14 = v16;
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v14,
      "cnss_pci_suspend_pwroff",
      3u,
      3u,
      "Failed to suspend PCI link, err = %d\n",
      v11,
      v12,
      vars0);
  }
  return cnss_power_off_device(plat_priv_by_rc_num);
}
