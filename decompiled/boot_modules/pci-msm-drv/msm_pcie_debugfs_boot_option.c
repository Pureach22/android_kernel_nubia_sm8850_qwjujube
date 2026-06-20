size_t __fastcall msm_pcie_debugfs_boot_option(__int64 a1, unsigned __int64 a2, size_t a3)
{
  size_t v3; // x19
  int v4; // w0
  unsigned int v5; // w4
  char v6; // w8
  __int64 v8; // x8
  unsigned int v9; // w4
  __int64 v10; // x8
  unsigned int v11; // w4
  __int64 v12; // x8
  unsigned int v13; // w4
  __int64 v14; // x8
  unsigned int v15; // w4
  __int64 v16; // x8
  unsigned int v17; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v18; // [xsp+8h] [xbp-8h]

  v3 = a3;
  v18 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v17 = 0;
  v4 = msm_pcie_debugfs_parse_input(a2, a3, (__int64)&v17);
  if ( v4 )
  {
    v3 = v4;
    goto LABEL_9;
  }
  v5 = v17;
  if ( v17 > 3 )
  {
    printk(&unk_2F7B3);
    goto LABEL_9;
  }
  v6 = rc_sel;
  if ( (rc_sel & 1) != 0 )
  {
    v8 = msm_pcie_dev[0];
    *(_DWORD *)(msm_pcie_dev[0] + 1332) = v17;
    if ( v8 )
      ipc_log_string(
        *(_QWORD *)(v8 + 1712),
        "DBG_FS:%s: PCIe: RC%d: boot_option is now 0x%x\n",
        "msm_pcie_debugfs_boot_option",
        0,
        v5);
    printk(&unk_289BC);
    v6 = rc_sel;
    if ( (rc_sel & 2) == 0 )
    {
LABEL_6:
      if ( (v6 & 4) == 0 )
        goto LABEL_7;
      goto LABEL_17;
    }
  }
  else if ( (rc_sel & 2) == 0 )
  {
    goto LABEL_6;
  }
  v9 = v17;
  v10 = qword_30B50;
  *(_DWORD *)(qword_30B50 + 1332) = v17;
  if ( v10 )
    ipc_log_string(
      *(_QWORD *)(v10 + 1712),
      "DBG_FS:%s: PCIe: RC%d: boot_option is now 0x%x\n",
      "msm_pcie_debugfs_boot_option",
      1,
      v9);
  printk(&unk_289BC);
  v6 = rc_sel;
  if ( (rc_sel & 4) == 0 )
  {
LABEL_7:
    if ( (v6 & 8) == 0 )
      goto LABEL_8;
    goto LABEL_20;
  }
LABEL_17:
  v11 = v17;
  v12 = qword_30B58;
  *(_DWORD *)(qword_30B58 + 1332) = v17;
  if ( v12 )
    ipc_log_string(
      *(_QWORD *)(v12 + 1712),
      "DBG_FS:%s: PCIe: RC%d: boot_option is now 0x%x\n",
      "msm_pcie_debugfs_boot_option",
      2,
      v11);
  printk(&unk_289BC);
  v6 = rc_sel;
  if ( (rc_sel & 8) == 0 )
  {
LABEL_8:
    if ( (v6 & 0x10) == 0 )
      goto LABEL_9;
    goto LABEL_23;
  }
LABEL_20:
  v13 = v17;
  v14 = qword_30B60;
  *(_DWORD *)(qword_30B60 + 1332) = v17;
  if ( v14 )
    ipc_log_string(
      *(_QWORD *)(v14 + 1712),
      "DBG_FS:%s: PCIe: RC%d: boot_option is now 0x%x\n",
      "msm_pcie_debugfs_boot_option",
      3,
      v13);
  printk(&unk_289BC);
  if ( (rc_sel & 0x10) != 0 )
  {
LABEL_23:
    v15 = v17;
    v16 = qword_30B68;
    *(_DWORD *)(qword_30B68 + 1332) = v17;
    if ( v16 )
      ipc_log_string(
        *(_QWORD *)(v16 + 1712),
        "DBG_FS:%s: PCIe: RC%d: boot_option is now 0x%x\n",
        "msm_pcie_debugfs_boot_option",
        4,
        v15);
    printk(&unk_289BC);
  }
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return v3;
}
