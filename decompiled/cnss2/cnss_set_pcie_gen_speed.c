__int64 __fastcall cnss_set_pcie_gen_speed(__int64 a1, __int64 a2)
{
  unsigned __int8 v2; // w19
  __int64 v3; // x0
  __int64 v4; // x6
  __int64 v5; // x7
  __int64 v6; // x20
  unsigned __int64 v8; // x8
  const char *v9; // x1
  unsigned __int64 StatusReg; // x8
  const char *v11; // x1
  __int16 v12; // w9
  const char *v13; // x8
  __int16 v14; // w9
  const char *v15; // x8
  char v16; // [xsp+0h] [xbp+0h]

  v2 = a2;
  v3 = cnss_bus_dev_to_plat_priv(a1, a2);
  if ( !v3 )
    return 4294967274LL;
  v6 = v3 + 4096;
  if ( (*(_BYTE *)(v3 + 7512) & 1) != 0 )
  {
    if ( (unsigned int)v2 - 4 < 0xFFFFFFFD )
      return 4294967274LL;
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v11 = "irq";
    }
    else
    {
      v14 = *(_DWORD *)(StatusReg + 16);
      v15 = (const char *)(StatusReg + 2320);
      if ( (v14 & 0xFF00) != 0 )
        v11 = "soft_irq";
      else
        v11 = v15;
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v11,
      "cnss_set_pcie_gen_speed",
      7u,
      7u,
      "WLAN provided PCIE gen speed: %d\n",
      v2,
      v5,
      v16);
    *(_BYTE *)(v6 + 3440) = v2;
    return 0;
  }
  else
  {
    v8 = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(v8 + 16) & 0xF0000) != 0 )
    {
      v9 = "irq";
    }
    else
    {
      v12 = *(_DWORD *)(v8 + 16);
      v13 = (const char *)(v8 + 2320);
      if ( (v12 & 0xFF00) != 0 )
        v9 = "soft_irq";
      else
        v9 = v13;
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v9,
      "cnss_set_pcie_gen_speed",
      3u,
      3u,
      "Firmware does not support PCIe gen switch\n",
      v4,
      v5,
      v16);
    return 4294967201LL;
  }
}
