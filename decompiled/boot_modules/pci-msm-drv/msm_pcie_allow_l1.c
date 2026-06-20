__int64 __fastcall msm_pcie_allow_l1(__int64 a1)
{
  __int64 v1; // x8
  __int64 v2; // x8
  __int64 v4; // x19
  int v6; // w7
  int v7; // w7
  unsigned int v8; // w20

  if ( !a1 )
    return 4294967277LL;
  v1 = a1;
  while ( !*(_BYTE *)(v1 + 108) || (*(_WORD *)(v1 + 114) & 0xF0) != 0x40 )
  {
    if ( (*(_BYTE *)(v1 + 2851) & 0x80) != 0 )
      v1 = *(_QWORD *)(v1 + 3288);
    v2 = *(_QWORD *)(v1 + 16);
    if ( *(_QWORD *)(v2 + 16) )
    {
      v1 = *(_QWORD *)(v2 + 56);
      if ( v1 )
        continue;
    }
    return 4294967277LL;
  }
  v4 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v1 + 16) + 232LL) + 200LL);
  if ( !v4 )
    return 0;
  mutex_lock(v4 + 1120);
  mutex_lock(v4 + 1480);
  if ( *(_BYTE *)(v4 + 1216) != 1 )
  {
    if ( (*(_BYTE *)(v4 + 1218) & 1) == 0 )
    {
      ipc_log_string(
        *(_QWORD *)(v4 + 1696),
        "DBG2:%s: PCIe: RC%d: %02x:%02x.%01x: l1 not supported\n",
        "msm_pcie_allow_l1",
        *(unsigned int *)(v4 + 1348),
        *(unsigned __int8 *)(*(_QWORD *)(a1 + 16) + 248LL),
        (unsigned __int8)*(_DWORD *)(a1 + 56) >> 3,
        *(_DWORD *)(a1 + 56) & 7);
      goto LABEL_24;
    }
    v6 = *(_DWORD *)(v4 + 1176);
    if ( v6 != 1 )
    {
      ipc_log_string(
        *(_QWORD *)(v4 + 1696),
        "DBG2:%s: PCIe: RC%d: %02x:%02x.%01x: lnk_sts %d\n",
        "msm_pcie_allow_l1",
        *(_DWORD *)(v4 + 1348),
        *(unsigned __int8 *)(*(_QWORD *)(a1 + 16) + 248LL),
        (unsigned __int8)*(_DWORD *)(a1 + 56) >> 3,
        *(_DWORD *)(a1 + 56) & 7,
        v6);
      v8 = -22;
      goto LABEL_25;
    }
    v7 = *(_DWORD *)(v4 + 1528) - 1;
    *(_DWORD *)(v4 + 1528) = v7;
    if ( v7 < 0 )
    {
      ipc_log_string(
        *(_QWORD *)(v4 + 1704),
        "ERR:%s: PCIe: RC%d: %02x:%02x.%01x: unbalanced prevent_l1: %d < 0\n",
        "msm_pcie_allow_l1",
        *(_DWORD *)(v4 + 1348),
        *(unsigned __int8 *)(*(_QWORD *)(a1 + 16) + 248LL),
        (unsigned __int8)*(_DWORD *)(a1 + 56) >> 3,
        *(_DWORD *)(a1 + 56) & 7,
        v7);
      ipc_log_string(
        *(_QWORD *)(v4 + 1696),
        "%s: PCIe: RC%d: %02x:%02x.%01x: unbalanced prevent_l1: %d < 0\n",
        "msm_pcie_allow_l1",
        *(_DWORD *)(v4 + 1348),
        *(unsigned __int8 *)(*(_QWORD *)(a1 + 16) + 248LL),
        (unsigned __int8)*(_DWORD *)(a1 + 56) >> 3,
        *(_DWORD *)(a1 + 56) & 7,
        *(_DWORD *)(v4 + 1528));
      printk(&unk_2F581);
      if ( *(_DWORD *)(v4 + 1528) )
        goto LABEL_24;
    }
    else if ( v7 )
    {
      goto LABEL_24;
    }
    if ( *(_BYTE *)(v4 + 1218) == 1 )
      pci_walk_bus(*(_QWORD *)(*(_QWORD *)(v4 + 8) + 16LL), msm_pcie_config_l1_enable, v4);
    msm_pcie_write_mask((unsigned int *)(*(_QWORD *)(v4 + 872) + 32LL), 32, 0);
    ipc_log_string(
      *(_QWORD *)(v4 + 1696),
      "DBG2:%s: PCIe: RC%d: %02x:%02x.%01x: exit\n",
      "msm_pcie_allow_l1",
      *(unsigned int *)(v4 + 1348),
      *(unsigned __int8 *)(*(_QWORD *)(a1 + 16) + 248LL),
      (unsigned __int8)*(_DWORD *)(a1 + 56) >> 3,
      *(_DWORD *)(a1 + 56) & 7);
    goto LABEL_24;
  }
  ipc_log_string(
    *(_QWORD *)(v4 + 1696),
    "DBG2:%s: PCIe: RC%d: debugfs_l1 is set so no-op\n",
    "msm_pcie_allow_l1",
    *(_DWORD *)(v4 + 1348));
LABEL_24:
  v8 = 0;
LABEL_25:
  mutex_unlock(v4 + 1480);
  mutex_unlock(v4 + 1120);
  return v8;
}
