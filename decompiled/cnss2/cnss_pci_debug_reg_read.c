__int64 __fastcall cnss_pci_debug_reg_read(__int64 *a1, __int64 a2, __int64 a3, char a4)
{
  __int64 result; // x0
  unsigned int v7; // w20
  unsigned int sync; // w0
  int v9; // w21
  __int64 v10; // x6
  __int64 v11; // x7
  unsigned __int64 StatusReg; // x10
  unsigned int v13; // w9
  const char *v14; // x1
  __int16 v15; // w11
  const char *v16; // x10
  __int64 v17; // x6
  unsigned int v18; // w20
  __int64 v19; // x8
  unsigned int v20; // w9
  __int64 v21; // x9
  __int64 v22; // x8
  unsigned int v23; // w20
  unsigned __int64 v24; // x9
  const char *v25; // x1
  __int16 v26; // w10
  const char *v27; // x9
  unsigned int v28; // w20
  __int64 v29; // x21
  char vars0; // [xsp+0h] [xbp+0h]

  if ( (a4 & 1) != 0 )
    return cnss_pci_reg_read(a1, a2, a3);
  v7 = a2;
  result = cnss_pcie_is_device_down(*(_QWORD *)(*a1 + 352));
  if ( !(_DWORD)result )
  {
    sync = cnss_pci_pm_runtime_get_sync(a1, 0);
    if ( (sync & 0x80000000) != 0 )
      goto LABEL_27;
    v9 = cnss_pci_force_wake_get(a1);
    sync = cnss_pci_reg_read(a1, v7, a3);
    if ( sync )
    {
      StatusReg = _ReadStatusReg(SP_EL0);
      if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
      {
        v13 = sync;
        v14 = "irq";
      }
      else
      {
        v15 = *(_DWORD *)(StatusReg + 16);
        v16 = (const char *)(StatusReg + 2320);
        v13 = sync;
        if ( (v15 & 0xFF00) != 0 )
          v14 = "soft_irq";
        else
          v14 = v16;
      }
      v17 = v7;
      v18 = v13;
      cnss_debug_ipc_log_print(
        cnss_ipc_log_context,
        v14,
        "cnss_pci_debug_reg_read",
        3u,
        3u,
        "Failed to read register offset 0x%x, err = %d\n",
        v17,
        v13,
        vars0);
      sync = v18;
    }
    if ( v9 )
      goto LABEL_27;
    v19 = *(_QWORD *)(*a1 + 352);
    if ( v19 )
    {
      v20 = *(_DWORD *)(v19 + 24) - 4353;
      if ( v20 > 0x11 || ((1 << v20) & 0x32245) == 0 )
        goto LABEL_27;
      v21 = *(_QWORD *)(v19 + 344);
      if ( v21 )
      {
        v22 = *(_QWORD *)(v19 + 8);
        if ( v22 )
        {
          if ( (*(_QWORD *)(v22 + 552) & 0x800) == 0 )
          {
            v23 = sync;
            mhi_device_put(*(_QWORD *)(v21 + 16));
LABEL_26:
            sync = v23;
          }
LABEL_27:
          v28 = sync;
          if ( a1 )
          {
            v29 = *a1;
            *(_QWORD *)(v29 + 720) = ktime_get_mono_fast_ns();
          }
          cnss_pci_pm_runtime_put_autosuspend(a1, 0);
          return v28;
        }
      }
    }
    v24 = _ReadStatusReg(SP_EL0);
    v23 = sync;
    if ( (*(_DWORD *)(v24 + 16) & 0xF0000) != 0 )
    {
      v25 = "irq";
    }
    else
    {
      v26 = *(_DWORD *)(v24 + 16);
      v27 = (const char *)(v24 + 2320);
      if ( (v26 & 0xFF00) != 0 )
        v25 = "soft_irq";
      else
        v25 = v27;
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v25,
      "cnss_pci_force_wake_put",
      3u,
      3u,
      "Failed to release force wake\n",
      v10,
      v11,
      vars0);
    goto LABEL_26;
  }
  return result;
}
