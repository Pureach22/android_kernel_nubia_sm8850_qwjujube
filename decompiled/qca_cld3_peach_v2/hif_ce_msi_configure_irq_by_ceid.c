__int64 __fastcall hif_ce_msi_configure_irq_by_ceid(__int64 a1, int a2)
{
  __int64 result; // x0
  __int64 v5; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  unsigned int v14; // w22
  unsigned int pci_slot; // w21
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  int v24; // w27
  unsigned int msi_irq; // w23
  char is_one_msi; // w0
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  __int64 v35; // x8
  __int64 v36; // x24
  __int64 v37; // x25
  __int64 v38; // x0
  int v39; // [xsp+1Ch] [xbp-14h] BYREF
  _QWORD v40[2]; // [xsp+20h] [xbp-10h] BYREF

  v40[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 > 11 )
    goto LABEL_2;
  v5 = *(_QWORD *)(*(_QWORD *)(a1 + 576) + 40LL);
  v40[0] = 0;
  v39 = 0;
  if ( (unsigned int)pld_get_user_msi_assignment(v5, (__int64)"CE", (__int64)v40, (__int64)v40 + 4, (__int64)&v39) )
  {
    qdf_trace_msg(
      0x3Du,
      2u,
      "%s: Failed to get CE msi config",
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      "hif_ce_msi_configure_irq_by_ceid");
    result = 4294967274LL;
    goto LABEL_15;
  }
  if ( (unsigned int)a2 < 0xC )
  {
    v14 = *(unsigned __int8 *)(*(_QWORD *)(a1 + 664) + a2);
    pci_slot = pld_get_pci_slot(*(_QWORD *)(*(_QWORD *)(a1 + 576) + 40LL));
    if ( (pci_slot & 0x80000000) != 0 )
    {
      qdf_trace_msg(
        0x3Du,
        2u,
        "%s: Invalid PCI SLOT %d",
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        "hif_get_pci_slot",
        pci_slot);
      v38 = printk(
              &unk_AAA255,
              "0",
              "hif_get_pci_slot",
              "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/hif/src/pcie/if_pci.c");
      dump_stack(v38);
      pci_slot = 0;
    }
    v24 = v39;
    msi_irq = pld_get_msi_irq(*(_QWORD *)(*(_QWORD *)(a1 + 576) + 40LL), v39 + v14);
    is_one_msi = pld_is_one_msi(*(_QWORD *)(*(_QWORD *)(a1 + 576) + 40LL));
    v35 = a1 + 56LL * a2;
    if ( (is_one_msi & 1) != 0 )
      v36 = 2176;
    else
      v36 = 128;
    v37 = v35 + 26448;
    qdf_trace_msg(
      0x3Du,
      8u,
      "%s: %s: (ce_id %d, irq_id %d, msi_data %d, irq %d flag 0x%lx tasklet %pK)",
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      "hif_ce_msi_configure_irq_by_ceid",
      "hif_ce_msi_configure_irq_by_ceid",
      (unsigned int)a2,
      v14,
      v24 + v14,
      msi_irq,
      v36,
      v35 + 26448);
    if ( *(_BYTE *)(v37 + 44) != 1 )
      goto LABEL_14;
    *(_DWORD *)(a1 + 4LL * a2 + 30848) = msi_irq;
    ((void (__fastcall *)(__int64, _QWORD, _QWORD))hif_affinity_mgr_init_ce_irq)(a1, (unsigned int)a2, msi_irq);
    if ( pci_slot <= 4 )
    {
      scnprintf((char *)&ce_irqname + 300 * pci_slot + 25 * a2, 25, "pci%u_wlan_ce_%u", pci_slot, a2);
      if ( (unsigned int)pld_srng_request_irq(
                           *(_QWORD *)(*(_QWORD *)(a1 + 576) + 40LL),
                           msi_irq,
                           (__int64)hif_ce_interrupt_handler,
                           v36,
                           (__int64)&ce_irqname + 300 * pci_slot + 25 * a2,
                           v37) )
      {
LABEL_2:
        result = 4294967274LL;
LABEL_15:
        _ReadStatusReg(SP_EL0);
        return result;
      }
LABEL_14:
      result = 0;
      goto LABEL_15;
    }
  }
  __break(0x5512u);
  return hif_ce_interrupt_handler();
}
