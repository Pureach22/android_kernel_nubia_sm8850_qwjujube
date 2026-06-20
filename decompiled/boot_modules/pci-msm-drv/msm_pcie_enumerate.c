__int64 __fastcall msm_pcie_enumerate(unsigned int a1)
{
  __int64 v2; // x19
  char v3; // w8
  _QWORD *v4; // x21
  int v5; // w0
  unsigned int v6; // w20
  unsigned __int64 v7; // x20
  _QWORD *v8; // x9
  int v9; // w0
  int v10; // w8
  __int64 v11; // x20
  int v12; // w0
  int v13; // w20
  __int64 v14; // x21
  int v15; // w0
  __int64 domain_bus_and_slot; // x0
  __int64 v17; // x21
  __int64 v18; // x0
  char v19; // w8
  void *v21; // x0
  void *v22; // x0
  _QWORD v23[3]; // [xsp+8h] [xbp-18h] BYREF

  v23[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 >= 5 )
    __break(0x5512u);
  v2 = msm_pcie_dev[a1];
  v23[0] = v23;
  v23[1] = v23;
  if ( v2 )
  {
    mutex_lock(v2 + 1072);
    ipc_log_string(*(_QWORD *)(v2 + 1704), "DBG1:%s: Enumerate RC%d\n", "msm_pcie_enumerate", a1);
    ipc_log_string(*(_QWORD *)(v2 + 1696), "%s: Enumerate RC%d\n", "msm_pcie_enumerate", a1);
    v3 = *(_BYTE *)(v2 + 1356);
    *(_BYTE *)(v2 + 3156) = 0;
    if ( (v3 & 1) != 0 )
    {
      if ( *(_BYTE *)(v2 + 1357) == 1 )
      {
        ipc_log_string(
          *(_QWORD *)(v2 + 1704),
          "ERR:%s: PCIe: RC%d: has already been enumerated.\n",
          "msm_pcie_enumerate",
          *(_DWORD *)(v2 + 1348));
        ipc_log_string(
          *(_QWORD *)(v2 + 1696),
          "%s: PCIe: RC%d: has already been enumerated.\n",
          "msm_pcie_enumerate",
          *(_DWORD *)(v2 + 1348));
        printk(&unk_284F3);
        LODWORD(v7) = 0;
        goto LABEL_25;
      }
      v4 = *(_QWORD **)(v2 + 16);
      v5 = msm_pcie_enable(v2);
      if ( v5 )
      {
        LODWORD(v7) = v5;
        ipc_log_string(
          *(_QWORD *)(v2 + 1704),
          "ERR:%s: PCIe: RC%d: failed to enable\n",
          "msm_pcie_enumerate",
          *(_DWORD *)(v2 + 1348));
        ipc_log_string(
          *(_QWORD *)(v2 + 1696),
          "%s: PCIe: RC%d: failed to enable\n",
          "msm_pcie_enumerate",
          *(_DWORD *)(v2 + 1348));
        v22 = &unk_2655E;
      }
      else
      {
        v6 = readl_relaxed_0(*(unsigned int **)(v2 + 904));
        ipc_log_string(
          *(_QWORD *)(v2 + 1704),
          "DBG1:%s: PCIe: RC%d: vendor-id:0x%x device_id:0x%x\n",
          "msm_pcie_enumerate",
          *(_DWORD *)(v2 + 1348),
          (unsigned __int16)v6,
          HIWORD(v6));
        ipc_log_string(
          *(_QWORD *)(v2 + 1696),
          "%s: PCIe: RC%d: vendor-id:0x%x device_id:0x%x\n",
          "msm_pcie_enumerate",
          *(_DWORD *)(v2 + 1348),
          (unsigned __int16)v6,
          HIWORD(v6));
        if ( (*(_BYTE *)(v2 + 1340) & 1) == 0 )
        {
          LODWORD(v7) = msm_msi_init(*(_QWORD *)v2 + 16LL);
          if ( (_DWORD)v7 )
            goto LABEL_25;
        }
        v8 = v4 + 119;
        do
        {
          v8 = (_QWORD *)*v8;
          if ( v8 == v4 + 119 )
            goto LABEL_28;
        }
        while ( (*(_QWORD *)(v8[2] + 24LL) & 0x1F00LL) != 0x1000 );
        if ( !v8 )
        {
LABEL_28:
          ipc_log_string(
            *(_QWORD *)(v2 + 1704),
            "ERR:%s: PCIe: RC%d: Fetching bus resource failed\n",
            "msm_pcie_enumerate",
            *(_DWORD *)(v2 + 1348));
          ipc_log_string(
            *(_QWORD *)(v2 + 1696),
            "%s: PCIe: RC%d: Fetching bus resource failed\n",
            "msm_pcie_enumerate",
            *(_DWORD *)(v2 + 1348));
          v21 = &unk_27D3A;
          goto LABEL_29;
        }
        v7 = pci_ecam_create(*(_QWORD *)v2 + 16LL, *(_QWORD *)(v2 + 408));
        if ( v7 < 0xFFFFFFFFFFFFF001LL )
        {
          *(_QWORD *)(v7 + 200) = v2;
          v4[117] = v7;
          v4[115] = &unk_30E80;
          v9 = pci_host_probe(v4);
          if ( !v9 )
          {
            v10 = *(unsigned __int8 *)(v2 + 1992);
            *(_BYTE *)(v2 + 1357) = 1;
            if ( v10 == 1 )
              queue_work_on(32, mpcie_wq, v2 + 1864);
            v11 = *(_QWORD *)(v2 + 904);
            v12 = readl_relaxed_0((unsigned int *)(v11 + 4));
            writel_relaxed_0(v12 | 6u, v11 + 4);
            readl_relaxed_0((unsigned int *)(v11 + 4));
            v13 = *(_DWORD *)(v2 + 1304);
            if ( v13 && *(_BYTE *)(v2 + 1664) == 1 )
            {
              v14 = *(_QWORD *)(v2 + 904);
              v15 = readl_relaxed_0((unsigned int *)(v14 + 152));
              writel_relaxed_0(v15 & 0xFFFFFFF0 | v13, v14 + 152);
              readl_relaxed_0((unsigned int *)(v14 + 152));
            }
            if ( (of_get_pci_domain_nr(*(_QWORD *)(*(_QWORD *)v2 + 760LL)) & 0x80000000) != 0 )
            {
              LODWORD(v7) = -22;
              goto LABEL_25;
            }
            domain_bus_and_slot = pci_get_domain_bus_and_slot();
            if ( domain_bus_and_slot )
            {
              v17 = domain_bus_and_slot;
              pci_dev_put();
              *(_QWORD *)(v2 + 8) = v17;
              pci_walk_bus(*(_QWORD *)(v17 + 16), msm_pcie_config_device_info, v2);
              pci_walk_bus(*(_QWORD *)(*(_QWORD *)(v2 + 8) + 16LL), msm_pcie_check_l1ss_support, v2);
              msm_pcie_config_link_pm(v2);
              pci_save_state(v17);
              v18 = pci_store_saved_state(v17);
              v19 = *(_BYTE *)(v2 + 1332);
              LODWORD(v7) = 0;
              *(_QWORD *)(v2 + 1184) = v18;
              if ( (v19 & 1) != 0 )
                *(_BYTE *)(v17 + 536) |= 2u;
              goto LABEL_25;
            }
            ipc_log_string(
              *(_QWORD *)(v2 + 1704),
              "ERR:%s: PCIe: RC%d: Did not find PCI device.\n",
              "msm_pcie_enumerate",
              *(_DWORD *)(v2 + 1348));
            ipc_log_string(
              *(_QWORD *)(v2 + 1696),
              "%s: PCIe: RC%d: Did not find PCI device.\n",
              "msm_pcie_enumerate",
              *(_DWORD *)(v2 + 1348));
            v21 = &unk_2D432;
LABEL_29:
            printk(v21);
            LODWORD(v7) = -19;
            goto LABEL_25;
          }
          LODWORD(v7) = v9;
          ipc_log_string(
            *(_QWORD *)(v2 + 1704),
            "ERR:%s: PCIe: RC%d: pci_host_probe failed %d\n",
            "msm_pcie_enumerate",
            *(_DWORD *)(v2 + 1348),
            v9);
          ipc_log_string(
            *(_QWORD *)(v2 + 1696),
            "%s: PCIe: RC%d: pci_host_probe failed %d\n",
            "msm_pcie_enumerate",
            *(_DWORD *)(v2 + 1348),
            v7);
          printk(&unk_25B8A);
LABEL_25:
          mutex_unlock(v2 + 1072);
          goto LABEL_26;
        }
        ipc_log_string(
          *(_QWORD *)(v2 + 1704),
          "ERR:%s: PCIe: RC%d: ECAM creation failed\n",
          "msm_pcie_enumerate",
          *(_DWORD *)(v2 + 1348));
        ipc_log_string(
          *(_QWORD *)(v2 + 1696),
          "%s: PCIe: RC%d: ECAM creation failed\n",
          "msm_pcie_enumerate",
          *(_DWORD *)(v2 + 1348));
        v22 = &unk_2B86A;
      }
      printk(v22);
      goto LABEL_25;
    }
    ipc_log_string(
      *(_QWORD *)(v2 + 1704),
      "DBG1:%s: PCIe: RC%d: has not been successfully probed yet\n",
      "msm_pcie_enumerate",
      a1);
    ipc_log_string(
      *(_QWORD *)(v2 + 1696),
      "%s: PCIe: RC%d: has not been successfully probed yet\n",
      "msm_pcie_enumerate",
      a1);
    LODWORD(v7) = -517;
    goto LABEL_25;
  }
  LODWORD(v7) = -517;
LABEL_26:
  _ReadStatusReg(SP_EL0);
  return (unsigned int)v7;
}
