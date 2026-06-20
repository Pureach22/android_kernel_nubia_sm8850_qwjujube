__int64 __fastcall cnss_get_fw_cap(__int64 a1, __int64 a2)
{
  int v2; // w19
  __int64 v3; // x0
  __int64 v4; // x7
  unsigned __int64 v5; // x8
  __int64 v6; // x21
  unsigned __int64 StatusReg; // x8
  const char *v8; // x1
  __int16 v9; // w9
  const char *v10; // x8
  unsigned __int64 v11; // x8
  const char *v12; // x1
  __int16 v13; // w9
  const char *v14; // x8
  const char *v15; // x7
  char v17; // [xsp+0h] [xbp+0h]

  v2 = a2;
  v3 = cnss_bus_dev_to_plat_priv(a1, a2);
  if ( !v3 || (v5 = *(_QWORD *)(v3 + 7520)) == 0 )
  {
    LOBYTE(v6) = 0;
    return v6 & 1;
  }
  if ( v2 > 2 )
  {
    if ( v2 == 3 )
    {
      v6 = (v5 >> 5) & 1;
      goto LABEL_19;
    }
    if ( v2 == 4 )
    {
      v6 = (v5 >> 6) & 1;
      goto LABEL_19;
    }
LABEL_11:
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v8 = "irq";
    }
    else
    {
      v9 = *(_DWORD *)(StatusReg + 16);
      v10 = (const char *)(StatusReg + 2320);
      if ( (v9 & 0xFF00) != 0 )
        v8 = "soft_irq";
      else
        v8 = v10;
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v8,
      "cnss_get_fw_cap",
      3u,
      3u,
      "Invalid FW Capability: 0x%x\n",
      (unsigned int)v2,
      v4,
      v17);
    LOBYTE(v6) = 0;
    goto LABEL_19;
  }
  if ( !v2 )
  {
    LODWORD(v6) = *(_DWORD *)(v3 + 7528);
    goto LABEL_19;
  }
  if ( v2 != 2 )
    goto LABEL_11;
  v6 = (v5 >> 3) & 1;
LABEL_19:
  v11 = _ReadStatusReg(SP_EL0);
  if ( (*(_DWORD *)(v11 + 16) & 0xF0000) != 0 )
  {
    v12 = "irq";
  }
  else
  {
    v13 = *(_DWORD *)(v11 + 16);
    v14 = (const char *)(v11 + 2320);
    if ( (v13 & 0xFF00) != 0 )
      v12 = "soft_irq";
    else
      v12 = v14;
  }
  if ( (v6 & 1) != 0 )
    v15 = "supported";
  else
    v15 = "not supported";
  cnss_debug_ipc_log_print(
    cnss_ipc_log_context,
    v12,
    "cnss_get_fw_cap",
    7u,
    7u,
    "FW Capability 0x%x is %s\n",
    (unsigned int)v2,
    (__int64)v15,
    v17);
  return v6 & 1;
}
