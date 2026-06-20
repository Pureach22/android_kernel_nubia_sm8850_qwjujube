__int64 __fastcall cnss_pci_update_drv_supported(
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
  __int64 v10; // x8
  unsigned __int64 v11; // x8
  const char *v12; // x1
  __int16 v13; // w9
  const char *v14; // x8
  __int64 result; // x0
  __int64 v16; // x21
  __int64 v17; // x20
  __int64 v18; // x0
  _BOOL4 v19; // w21
  unsigned __int64 StatusReg; // x8
  const char *v21; // x1
  __int16 v22; // w9
  const char *v23; // x8
  const char *v24; // x6
  char v25; // [xsp+0h] [xbp+0h]

  v8 = *a1;
  if ( *a1 )
  {
    while ( !*(_BYTE *)(v8 + 108) || (*(_WORD *)(v8 + 114) & 0xF0) != 0x40 )
    {
      if ( (*(_BYTE *)(v8 + 2851) & 0x80) != 0 )
        v8 = *(_QWORD *)(v8 + 3288);
      v10 = *(_QWORD *)(v8 + 16);
      if ( *(_QWORD *)(v10 + 16) )
      {
        v8 = *(_QWORD *)(v10 + 56);
        if ( v8 )
          continue;
      }
      goto LABEL_8;
    }
    v16 = *(_QWORD *)(v8 + 944);
    v17 = a1[1];
    v18 = *(_QWORD *)(v16 + 112);
    if ( v18 )
    {
      if ( of_find_property(v18, "qcom,drv-supported", 0) )
        v19 = 1;
      else
        v19 = of_find_property(*(_QWORD *)(v16 + 112), "qcom,drv-name", 0) != 0;
    }
    else
    {
      v19 = 0;
    }
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v21 = "irq";
    }
    else
    {
      v22 = *(_DWORD *)(StatusReg + 16);
      v23 = (const char *)(StatusReg + 2320);
      if ( (v22 & 0xFF00) != 0 )
        v21 = "soft_irq";
      else
        v21 = v23;
    }
    if ( v19 )
      v24 = "supported";
    else
      v24 = "not supported";
    result = cnss_debug_ipc_log_print(
               cnss_ipc_log_context,
               v21,
               "cnss_pci_update_drv_supported",
               7u,
               7u,
               "PCIe DRV is %s\n",
               (__int64)v24,
               a8,
               v25);
    *((_BYTE *)a1 + 697) = v19;
    if ( v19 )
    {
      *(_DWORD *)(v17 + 448) |= 4u;
      return cnss_set_feature_list(v17, 1);
    }
  }
  else
  {
LABEL_8:
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
    result = cnss_debug_ipc_log_print(
               cnss_ipc_log_context,
               v12,
               "cnss_pci_update_drv_supported",
               3u,
               3u,
               "PCIe DRV is not supported as root port is null\n",
               a7,
               a8,
               v25);
    *((_BYTE *)a1 + 697) = 0;
  }
  return result;
}
