__int64 __fastcall hif_pci_configure_grp_irq(__int64 a1, __int64 a2)
{
  unsigned int pci_slot; // w21
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  unsigned __int64 v13; // x22
  unsigned __int64 v14; // x24
  unsigned int v15; // w27
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 v24; // x28
  unsigned int v25; // w4
  unsigned int v26; // w8
  unsigned int v27; // w0
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  __int64 v37; // x0

  *(_QWORD *)(a2 + 280) = &hif_exec_grp_irq_disable;
  *(_QWORD *)(a2 + 288) = hif_pci_get_irq_name;
  *(_QWORD *)(a2 + 264) = hif_dummy_grp_done;
  *(_QWORD *)(a2 + 272) = hif_exec_grp_irq_enable;
  pci_slot = pld_get_pci_slot(*(_QWORD *)(*(_QWORD *)(a1 + 576) + 40LL));
  if ( (pci_slot & 0x80000000) == 0 )
  {
    if ( *(_DWORD *)(a2 + 16) )
      goto LABEL_3;
LABEL_15:
    *(_BYTE *)(a2 + 2682) = 1;
    return 0;
  }
  qdf_trace_msg(0x3Du, 2u, "%s: Invalid PCI SLOT %d", v5, v6, v7, v8, v9, v10, v11, v12, "hif_get_pci_slot", pci_slot);
  v37 = printk(
          &unk_AAA255,
          "0",
          "hif_get_pci_slot",
          "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/hif/src/pcie/if_pci.c");
  dump_stack(v37);
  pci_slot = 0;
  if ( !*(_DWORD *)(a2 + 16) )
    goto LABEL_15;
LABEL_3:
  v13 = 0;
  while ( v13 != 25 )
  {
    v14 = a2 + 4 * v13;
    v15 = *(_DWORD *)(v14 + 20);
    if ( *(_DWORD *)(a1 + 3984) )
      irq_modify_status(v15, 0, 0x80000);
    v24 = (pld_is_one_msi(*(_QWORD *)(*(_QWORD *)(a1 + 576) + 40LL)) & 1) != 0 ? 2176LL : 16512LL;
    qdf_trace_msg(
      0x3Du,
      8u,
      "%s: request_irq = %d for grp %d irq_flags 0x%lx",
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      "hif_pci_configure_grp_irq",
      v15,
      *(unsigned int *)(a2 + 232),
      v24);
    if ( pci_slot > 4 )
      break;
    v25 = *(_DWORD *)(a2 + 232);
    if ( v25 > 0x12 )
      break;
    scnprintf((char *)&dp_irqname + 450 * pci_slot + 25 * v25, 25, "pci%u_wlan_grp_dp_%u", pci_slot, v25);
    v26 = *(_DWORD *)(a2 + 232);
    if ( v26 > 0x12 )
      break;
    v27 = pld_srng_request_irq(
            *(_QWORD *)(*(_QWORD *)(a1 + 576) + 40LL),
            v15,
            (__int64)hif_ext_group_interrupt_handler,
            v24,
            (__int64)&dp_irqname + 450 * pci_slot + 25 * v26,
            a2);
    if ( v27 )
    {
      qdf_trace_msg(
        0x3Du,
        2u,
        "%s: request_irq failed ret = %d",
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        "hif_pci_configure_grp_irq",
        v27);
      return 4294967282LL;
    }
    *(_DWORD *)(v14 + 120) = v15;
    ((void (__fastcall *)(__int64, _QWORD, _QWORD, _QWORD))hif_affinity_mgr_init_grp_irq)(
      a1,
      *(unsigned int *)(a2 + 232),
      (unsigned int)v13++,
      v15);
    if ( v13 >= *(unsigned int *)(a2 + 16) )
      goto LABEL_15;
  }
  __break(0x5512u);
  return hif_exec_grp_irq_enable();
}
