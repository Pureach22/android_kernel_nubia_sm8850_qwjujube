__int64 __fastcall cnss_wlan_adsp_pc_enable(
        __int64 a1,
        char a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  char v8; // w29
  __int64 v9; // x19
  char v10; // w21
  unsigned __int64 StatusReg; // x8
  const char *v12; // x8
  __int64 result; // x0
  __int64 v15; // x7
  unsigned __int64 v16; // x8
  const char *v17; // x1
  __int16 v18; // w9
  const char *v19; // x6
  __int16 v20; // w9
  const char *v21; // x8
  const char *v22; // x6

  if ( *(_BYTE *)(a1 + 697) != 1 )
    return 0;
  v9 = *(_QWORD *)(a1 + 8);
  v10 = a2 & 1;
  if ( *(_BYTE *)(v9 + 7724) == (a2 & 1) )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v12 = "irq";
    }
    else
    {
      v18 = *(_DWORD *)(StatusReg + 16);
      v12 = (const char *)(StatusReg + 2320);
      if ( (v18 & 0xFF00) != 0 )
        v12 = "soft_irq";
    }
    if ( (a2 & 1) != 0 )
      v19 = "Enabled";
    else
      v19 = "Disabled";
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v12,
      "cnss_wlan_adsp_pc_enable",
      7u,
      7u,
      "ADSP power collapse already %s\n",
      (__int64)v19,
      a8,
      v8);
    return 0;
  }
  else
  {
    result = msm_pcie_pm_control(64, *(unsigned __int8 *)(*(_QWORD *)(*(_QWORD *)a1 + 16LL) + 248LL));
    if ( !(_DWORD)result )
    {
      v16 = _ReadStatusReg(SP_EL0);
      if ( (*(_DWORD *)(v16 + 16) & 0xF0000) != 0 )
      {
        v17 = "irq";
      }
      else
      {
        v20 = *(_DWORD *)(v16 + 16);
        v21 = (const char *)(v16 + 2320);
        if ( (v20 & 0xFF00) != 0 )
          v17 = "soft_irq";
        else
          v17 = v21;
      }
      if ( (a2 & 1) != 0 )
        v22 = "Enable";
      else
        v22 = "Disable";
      cnss_debug_ipc_log_print(
        cnss_ipc_log_context,
        v17,
        "cnss_wlan_adsp_pc_enable",
        7u,
        7u,
        "%s ADSP power collapse\n",
        (__int64)v22,
        v15,
        v8);
      *(_BYTE *)(v9 + 7724) = v10;
      return 0;
    }
  }
  return result;
}
