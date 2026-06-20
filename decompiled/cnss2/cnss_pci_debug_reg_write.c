__int64 __fastcall cnss_pci_debug_reg_write(unsigned int *a1, __int64 a2, __int64 a3, char a4)
{
  __int64 result; // x0
  unsigned int v6; // w20
  unsigned int v7; // w21
  __int64 v8; // x2
  __int64 v9; // x3
  __int64 v10; // x4
  __int64 v11; // x5
  __int64 v12; // x6
  __int64 v13; // x7
  unsigned int sync; // w0
  __int64 v15; // x1
  __int64 v16; // x2
  __int64 v17; // x3
  __int64 v18; // x4
  __int64 v19; // x5
  __int64 v20; // x6
  __int64 v21; // x7
  int v22; // w22
  unsigned __int64 StatusReg; // x10
  unsigned int v24; // w9
  const char *v25; // x1
  __int16 v26; // w11
  const char *v27; // x10
  __int64 v28; // x7
  unsigned int v29; // w20
  __int64 v30; // x8
  unsigned int v31; // w9
  __int64 v32; // x9
  __int64 v33; // x8
  unsigned int v34; // w20
  unsigned __int64 v35; // x9
  const char *v36; // x1
  __int16 v37; // w10
  const char *v38; // x9
  unsigned int v39; // w20
  __int64 v40; // x21
  char v41; // [xsp+0h] [xbp-10h]

  if ( (a4 & 1) != 0 )
    return cnss_pci_reg_write(a1, a2, a3);
  v6 = a2;
  v7 = a3;
  result = cnss_pcie_is_device_down(*(_QWORD *)(*(_QWORD *)a1 + 352LL));
  if ( !(_DWORD)result )
  {
    sync = cnss_pci_pm_runtime_get_sync(a1, 0, v8, v9, v10, v11, v12, v13);
    if ( (sync & 0x80000000) != 0 )
      goto LABEL_27;
    v22 = cnss_pci_force_wake_get((__int64 *)a1, v15, v16, v17, v18, v19, v20, v21);
    sync = cnss_pci_reg_write(a1, v6, v7);
    if ( sync )
    {
      StatusReg = _ReadStatusReg(SP_EL0);
      if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
      {
        v24 = sync;
        v25 = "irq";
      }
      else
      {
        v26 = *(_DWORD *)(StatusReg + 16);
        v27 = (const char *)(StatusReg + 2320);
        v24 = sync;
        if ( (v26 & 0xFF00) != 0 )
          v25 = "soft_irq";
        else
          v25 = v27;
      }
      v28 = v6;
      v29 = v24;
      cnss_debug_ipc_log_print(
        cnss_ipc_log_context,
        v25,
        "cnss_pci_debug_reg_write",
        3u,
        3u,
        "Failed to write 0x%x to register offset 0x%x, err = %d\n",
        v7,
        v28,
        v24);
      sync = v29;
    }
    if ( v22 )
      goto LABEL_27;
    v30 = *(_QWORD *)(*(_QWORD *)a1 + 352LL);
    if ( v30 )
    {
      v31 = *(_DWORD *)(v30 + 24) - 4353;
      if ( v31 > 0x11 || ((1 << v31) & 0x32245) == 0 )
        goto LABEL_27;
      v32 = *(_QWORD *)(v30 + 344);
      if ( v32 )
      {
        v33 = *(_QWORD *)(v30 + 8);
        if ( v33 )
        {
          if ( (*(_QWORD *)(v33 + 552) & 0x800) == 0 )
          {
            v34 = sync;
            mhi_device_put(*(_QWORD *)(v32 + 16));
LABEL_26:
            sync = v34;
          }
LABEL_27:
          v39 = sync;
          if ( a1 )
          {
            v40 = *(_QWORD *)a1;
            *(_QWORD *)(v40 + 720) = ktime_get_mono_fast_ns();
          }
          cnss_pci_pm_runtime_put_autosuspend(a1, 0, v16, v17, v18, v19, v20, v21);
          return v39;
        }
      }
    }
    v35 = _ReadStatusReg(SP_EL0);
    v34 = sync;
    if ( (*(_DWORD *)(v35 + 16) & 0xF0000) != 0 )
    {
      v36 = "irq";
    }
    else
    {
      v37 = *(_DWORD *)(v35 + 16);
      v38 = (const char *)(v35 + 2320);
      if ( (v37 & 0xFF00) != 0 )
        v36 = "soft_irq";
      else
        v36 = v38;
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v36,
      "cnss_pci_force_wake_put",
      3u,
      3u,
      "Failed to release force wake\n",
      v20,
      v21,
      v41);
    goto LABEL_26;
  }
  return result;
}
