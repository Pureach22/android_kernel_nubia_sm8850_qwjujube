__int64 __fastcall msm_pci_probe(_QWORD *a1)
{
  __int64 v1; // x21
  _QWORD *v3; // x0
  int v4; // w0
  unsigned int v6; // w19

  v1 = *(_QWORD *)(*(_QWORD *)(a1[2] + 232LL) + 200LL);
  if ( !v1 || !*(_QWORD *)v1 )
  {
    printk(&unk_29A45);
    return 4294967277LL;
  }
  ipc_log_string(*(_QWORD *)(v1 + 1704), "DBG1:%s: PCIe: RC%d: PCI Probe\n", "msm_pci_probe", *(_DWORD *)(v1 + 1348));
  ipc_log_string(*(_QWORD *)(v1 + 1696), "%s: PCIe: RC%d: PCI Probe\n", "msm_pci_probe", *(_DWORD *)(v1 + 1348));
  if ( !a1[118] )
    return 4294967277LL;
  v3 = (_QWORD *)devm_kmalloc(a1 + 25, 16, 3520);
  if ( !v3 )
    return 4294967284LL;
  *v3 = v1;
  v3[1] = a1;
  a1[44] = v3;
  v4 = dma_set_mask(a1 + 25, -1);
  if ( v4 )
  {
    v6 = v4;
    ipc_log_string(*(_QWORD *)(v1 + 1704), "ERR:%s: DMA set mask failed (%d)\n", "msm_pci_probe", v4);
    ipc_log_string(*(_QWORD *)(v1 + 1696), "%s: DMA set mask failed (%d)\n", "msm_pci_probe", v6);
    printk(&unk_2F7E1);
    return v6;
  }
  else
  {
    dma_set_coherent_mask(a1 + 25, -1);
    return 0;
  }
}
