__int64 __fastcall cnss_pci_set_wlaon_pwr_ctrl(
        __int64 result,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  __int64 v8; // x19
  char v9; // w20
  char v10; // w21
  int v11; // w0
  int v12; // w8
  char v13; // w23
  char v14; // w22
  _QWORD *v15; // x19
  unsigned int v16; // w0
  unsigned __int64 StatusReg; // x24
  __int64 v18; // x8
  int v19; // w9
  __int64 v20; // x7
  const char *v21; // x1
  const char *v22; // x1
  const char *v23; // x5
  unsigned int v24; // w20
  unsigned int v25; // w20
  __int64 v26; // x3
  __int64 v27; // x4
  __int64 v28; // x5
  __int64 v29; // x6
  __int64 v30; // x7
  unsigned int v31; // w0
  int v32; // w9
  const char *v33; // x1
  __int64 v34; // x6
  __int64 v35; // x7
  __int64 v36; // x8
  unsigned int v37; // w9
  __int64 v38; // x9
  __int64 v39; // x8
  unsigned __int64 v40; // x8
  const char *v41; // x1
  __int16 v42; // w9
  const char *v43; // x8
  char v44; // [xsp+0h] [xbp-10h]
  char v45; // [xsp+0h] [xbp-10h]
  unsigned int v46; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v47; // [xsp+8h] [xbp-8h]

  v47 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !*(_BYTE *)(*(_QWORD *)(result + 8) + 7491LL) )
    goto LABEL_4;
  if ( !*(_BYTE *)(result + 48) )
    goto LABEL_4;
  if ( *(_BYTE *)(result + 49) )
    goto LABEL_4;
  if ( (a3 & 1) != 0 )
  {
    v8 = result;
    v9 = a3;
    v10 = a2;
    v11 = cnss_pci_force_wake_get((__int64 *)result, a2, a3, a4, a5, a6, a7, a8);
    LOBYTE(a2) = v10;
    LOBYTE(a3) = v9;
    v12 = v11;
    result = v8;
    if ( v12 )
      goto LABEL_4;
  }
  v13 = a2;
  v14 = a3;
  v46 = 0;
  v15 = (_QWORD *)result;
  v16 = cnss_pci_reg_read((_QWORD *)result, 33030940, &v46, a4, a5, a6, a7, a8);
  StatusReg = _ReadStatusReg(SP_EL0);
  v18 = cnss_ipc_log_context;
  v19 = *(_DWORD *)(StatusReg + 16) & 0xF0000;
  if ( v16 )
  {
    v20 = v16;
    if ( v19 )
    {
      v21 = "irq";
    }
    else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      v21 = "soft_irq";
    }
    else
    {
      v21 = (const char *)(StatusReg + 2320);
    }
    v23 = "Failed to read register offset 0x%x, err = %d\n";
  }
  else
  {
    if ( v19 )
    {
      v22 = "irq";
    }
    else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      v22 = "soft_irq";
    }
    else
    {
      v22 = (const char *)(StatusReg + 2320);
    }
    v24 = v46;
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v22,
      "cnss_pci_set_wlaon_pwr_ctrl",
      7u,
      7u,
      "Read register offset 0x%x, val = 0x%x\n",
      33030940,
      v46,
      v44);
    v25 = v24 & 0xFFFFFFFA | v13 & 1;
    v31 = cnss_pci_reg_write(v15, 33030940, v25, v26, v27, v28, v29, v30);
    v18 = cnss_ipc_log_context;
    v32 = *(_DWORD *)(StatusReg + 16) & 0xF0000;
    if ( !v31 )
    {
      if ( v32 )
      {
        v33 = "irq";
      }
      else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
      {
        v33 = "soft_irq";
      }
      else
      {
        v33 = (const char *)(StatusReg + 2320);
      }
      result = cnss_debug_ipc_log_print(
                 cnss_ipc_log_context,
                 v33,
                 "cnss_pci_set_wlaon_pwr_ctrl",
                 7u,
                 7u,
                 "Write val 0x%x to register offset 0x%x\n",
                 v25,
                 33030940,
                 v44);
      if ( (v13 & 1) != 0 )
        result = usleep_range_state(1000, 2000, 2);
      goto LABEL_29;
    }
    v20 = v31;
    if ( v32 )
    {
      v21 = "irq";
    }
    else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      v21 = "soft_irq";
    }
    else
    {
      v21 = (const char *)(StatusReg + 2320);
    }
    v23 = "Failed to write register offset 0x%x, err = %d\n";
  }
  result = cnss_debug_ipc_log_print(v18, v21, "cnss_pci_set_wlaon_pwr_ctrl", 3u, 3u, v23, 33030940, v20, v44);
LABEL_29:
  if ( (v14 & 1) == 0 )
    goto LABEL_4;
  v36 = *(_QWORD *)(*v15 + 352LL);
  if ( !v36 )
    goto LABEL_37;
  v37 = *(_DWORD *)(v36 + 24) - 4353;
  if ( v37 > 0x11 || ((1 << v37) & 0x32245) == 0 )
    goto LABEL_4;
  v38 = *(_QWORD *)(v36 + 344);
  if ( v38 && (v39 = *(_QWORD *)(v36 + 8)) != 0 )
  {
    if ( (*(_QWORD *)(v39 + 552) & 0x800) == 0 )
      result = mhi_device_put(*(_QWORD *)(v38 + 16));
  }
  else
  {
LABEL_37:
    v40 = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(v40 + 16) & 0xF0000) != 0 )
    {
      v41 = "irq";
    }
    else
    {
      v42 = *(_DWORD *)(v40 + 16);
      v43 = (const char *)(v40 + 2320);
      if ( (v42 & 0xFF00) != 0 )
        v41 = "soft_irq";
      else
        v41 = v43;
    }
    result = cnss_debug_ipc_log_print(
               cnss_ipc_log_context,
               v41,
               "cnss_pci_force_wake_put",
               3u,
               3u,
               "Failed to release force wake\n",
               v34,
               v35,
               v45);
  }
LABEL_4:
  _ReadStatusReg(SP_EL0);
  return result;
}
