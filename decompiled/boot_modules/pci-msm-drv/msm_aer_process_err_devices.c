__int64 __fastcall msm_aer_process_err_devices(__int64 result, int a2)
{
  __int64 v2; // x19
  __int64 v3; // x0
  int v4; // w8
  __int64 v5; // x0
  __int64 v6; // x0
  __int64 v7; // x0
  __int64 v8; // x0
  __int64 v9; // x28
  __int64 v11; // x26
  __int64 v12; // x25
  int v13; // w21
  __int64 v14; // x0
  char v15; // w8
  int v16; // w0
  __int64 v17; // x1
  __int64 v18; // x1
  _QWORD v19[2]; // [xsp+0h] [xbp-10h] BYREF

  v19[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(int *)(result + 48) < 1 )
    goto LABEL_53;
  v2 = result;
  v3 = *(_QWORD *)(result + 8);
  if ( !v3 )
    goto LABEL_23;
  result = msm_aer_get_device_error_info(v3, v2);
  if ( (_DWORD)result )
    result = msm_aer_print_error(*(_QWORD *)(v2 + 8), (__int64 *)v2);
  v4 = *(_DWORD *)(v2 + 48);
  if ( v4 <= 1 )
    goto LABEL_22;
  v5 = *(_QWORD *)(v2 + 16);
  if ( !v5 )
    goto LABEL_23;
  result = msm_aer_get_device_error_info(v5, v2);
  if ( (_DWORD)result )
    result = msm_aer_print_error(*(_QWORD *)(v2 + 16), (__int64 *)v2);
  v4 = *(_DWORD *)(v2 + 48);
  if ( v4 < 3 )
    goto LABEL_22;
  v6 = *(_QWORD *)(v2 + 24);
  if ( !v6 )
    goto LABEL_23;
  result = msm_aer_get_device_error_info(v6, v2);
  if ( (_DWORD)result )
    result = msm_aer_print_error(*(_QWORD *)(v2 + 24), (__int64 *)v2);
  v4 = *(_DWORD *)(v2 + 48);
  if ( v4 < 4 )
    goto LABEL_22;
  v7 = *(_QWORD *)(v2 + 32);
  if ( !v7 )
    goto LABEL_23;
  result = msm_aer_get_device_error_info(v7, v2);
  if ( (_DWORD)result )
    result = msm_aer_print_error(*(_QWORD *)(v2 + 32), (__int64 *)v2);
  v4 = *(_DWORD *)(v2 + 48);
  if ( v4 < 5 )
    goto LABEL_22;
  v8 = *(_QWORD *)(v2 + 40);
  if ( !v8 )
  {
LABEL_23:
    v9 = 1;
    while ( 1 )
    {
      if ( v9 == 6 )
        goto LABEL_54;
      result = *(_QWORD *)(v2 + 8 * v9);
      if ( !result )
        goto LABEL_53;
      result = msm_aer_get_device_error_info(result, v2);
      if ( (_DWORD)result )
        break;
LABEL_26:
      if ( v9++ >= *(int *)(v2 + 48) )
        goto LABEL_53;
    }
    v11 = *(_QWORD *)v2;
    v12 = *(_QWORD *)(v2 + 8 * v9);
    v19[0] = 0;
    v13 = *(unsigned __int16 *)(v12 + 74);
    if ( (*(_BYTE *)(v11 + 3048) & 1) == 0 && (*(_BYTE *)(v11 + 1568) & 1) == 0 && *(_DWORD *)(v11 + 1176) == 1 )
    {
      *(_BYTE *)(v11 + 3048) = 1;
      if ( (*(_DWORD *)(v2 + 52) & 0x30000) != 0x20000 || *(_BYTE *)(v11 + 3049) == 1 )
      {
        v14 = raw_spin_lock_irqsave(v11 + 1060);
        v15 = *(_BYTE *)(v11 + 1056);
        *(_QWORD *)(v11 + 1064) = v14;
        if ( (v15 & 1) == 0 )
        {
          if ( v11 )
          {
            ipc_log_string(
              *(_QWORD *)(v11 + 1696),
              "DBG2:%s: PCIe: RC%d is currently in drv suspend.\n",
              "msm_handle_error_source",
              *(_DWORD *)(v11 + 1348));
            v18 = *(_QWORD *)(v11 + 1064);
          }
          else
          {
            v18 = v14;
          }
          result = raw_spin_unlock_irqrestore(v11 + 1060, v18);
          goto LABEL_26;
        }
        pcie_parf_dump(v11);
        pcie_dm_core_dump(v11);
        pcie_phy_dump(v11);
        pcie_sm_dump(v11);
        if ( *(_QWORD *)(v11 + 3128) )
        {
          v16 = crm_dump_regs("pcie_crm");
          if ( v11 )
          {
            if ( v16 )
              ipc_log_string(
                *(_QWORD *)(v11 + 1712),
                "DUMP:%s: PCIe: RC%d Error dumping crm regs %d\n",
                "pcie_crm_dump",
                *(_DWORD *)(v11 + 1348),
                v16);
          }
        }
        raw_spin_unlock_irqrestore(v11 + 1060, *(_QWORD *)(v11 + 1064));
        if ( (*(_BYTE *)(v11 + 3049) & 1) != 0 )
          panic("AER error severity %d\n", *(_WORD *)(v2 + 54) & 3);
      }
    }
    a2 = *(_WORD *)(v2 + 54) & 3;
    if ( a2 )
    {
      if ( a2 != 2 )
        goto LABEL_55;
      if ( !v13 )
        goto LABEL_25;
      v17 = (unsigned int)(v13 + 16);
    }
    else
    {
      if ( !v13 )
        goto LABEL_25;
      pci_read_config_dword(v12, (unsigned int)(v13 + 4), (char *)v19 + 4);
      pci_read_config_dword(v12, (unsigned int)(v13 + 12), v19);
      HIDWORD(v19[0]) &= ~LODWORD(v19[0]);
      if ( !HIDWORD(v19[0]) )
        goto LABEL_25;
      v17 = (unsigned int)(v13 + 4);
    }
    pci_write_config_dword(v12, v17);
LABEL_25:
    pcie_capability_clear_and_set_word_unlocked(v12, 10, 0, 7);
    result = pci_dev_put(v12);
    goto LABEL_26;
  }
  result = msm_aer_get_device_error_info(v8, v2);
  if ( (_DWORD)result )
    result = msm_aer_print_error(*(_QWORD *)(v2 + 40), (__int64 *)v2);
  v4 = *(_DWORD *)(v2 + 48);
  if ( v4 > 5 )
  {
LABEL_54:
    __break(0x5512u);
LABEL_55:
    panic("AER error severity %d\n", a2);
  }
LABEL_22:
  if ( v4 >= 1 )
    goto LABEL_23;
LABEL_53:
  _ReadStatusReg(SP_EL0);
  return result;
}
