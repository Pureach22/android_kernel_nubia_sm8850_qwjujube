__int64 __fastcall hif_pci_legacy_ce_interrupt_handler(int a1, __int64 a2)
{
  __int64 v2; // x23
  int v4; // w8
  unsigned int v5; // w22
  unsigned __int64 v6; // x20
  __int64 v7; // x21
  _DWORD *v9; // x8
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  double v50; // d0
  double v51; // d1
  double v52; // d2
  double v53; // d3
  double v54; // d4
  double v55; // d5
  double v56; // d6
  double v57; // d7
  unsigned int v58; // w0
  double v59; // d0
  double v60; // d1
  double v61; // d2
  double v62; // d3
  double v63; // d4
  double v64; // d5
  double v65; // d6
  double v66; // d7
  unsigned int v67; // w0
  double v68; // d0
  double v69; // d1
  double v70; // d2
  double v71; // d3
  double v72; // d4
  double v73; // d5
  double v74; // d6
  double v75; // d7
  unsigned int v76; // w22
  unsigned int v77; // w0
  double v78; // d0
  double v79; // d1
  double v80; // d2
  double v81; // d3
  double v82; // d4
  double v83; // d5
  double v84; // d6
  double v85; // d7
  unsigned int v86; // w22
  unsigned int v87; // w0
  double v88; // d0
  double v89; // d1
  double v90; // d2
  double v91; // d3
  double v92; // d4
  double v93; // d5
  double v94; // d6
  double v95; // d7
  unsigned int v96; // w22
  unsigned int v97; // w0
  double v98; // d0
  double v99; // d1
  double v100; // d2
  double v101; // d3
  double v102; // d4
  double v103; // d5
  double v104; // d6
  double v105; // d7
  int v106; // w0
  int v107; // w21
  int v108; // w22
  _DWORD *v109; // x8
  unsigned int v117; // w9
  unsigned __int64 v120; // x8
  unsigned int v121; // [xsp+10h] [xbp-10h] BYREF
  _WORD v122[2]; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v123; // [xsp+18h] [xbp-8h]

  v2 = a2 + 28672;
  v123 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_DWORD *)(a2 + 30776);
  v122[0] = 0;
  v121 = 0;
  if ( v4 )
  {
LABEL_2:
    if ( *(_BYTE *)(a2 + 584) && (hif_target_sleep_state_adjust(a2) & 0x80000000) == 0 )
    {
      v5 = (*(_DWORD *)(*(_QWORD *)(a2 + 624) + 192LL)
          & (unsigned int)hif_read32_mb_reg_window(
                            a2,
                            *(_QWORD *)(a2 + 40)
                          + (unsigned int)(*(_DWORD *)(*(_QWORD *)(a2 + 624) + 64LL)
                                         + *(_DWORD *)(*(_QWORD *)(a2 + 624) + 60LL)))) >> *(_DWORD *)(*(_QWORD *)(a2 + 624) + 196LL);
      if ( v5 )
      {
        hif_target_sleep_state_adjust(a2);
        v6 = 0;
        *(_DWORD *)(a2 + 652) = v5;
        v7 = a2 + 26448;
        do
        {
          if ( v6 >= *(unsigned int *)(a2 + 656) )
            break;
          if ( ((1 << v6) & v5) != 0 )
          {
            if ( v6 >= 0xD )
              __break(0x5512u);
            v5 &= ~(1 << v6);
            ce_dispatch_interrupt(v6, v7);
          }
          ++v6;
          v7 += 56;
        }
        while ( v5 );
      }
      else
      {
        if ( *(_DWORD *)(a2 + 600) != 1 && !*(_DWORD *)(a2 + 684) )
        {
          v109 = *(_DWORD **)(a2 + 616);
          hif_write32_mb_reg_window(
            a2,
            *(_QWORD *)(a2 + 40) + (unsigned int)(v109[74] | v109[68]),
            (unsigned int)(v109[77] | v109[76]) | v109[221]);
          hif_read32_mb_reg_window(
            a2,
            *(_QWORD *)(a2 + 40)
          + (unsigned int)(*(_DWORD *)(*(_QWORD *)(a2 + 616) + 296LL) | *(_DWORD *)(*(_QWORD *)(a2 + 616) + 272LL)));
        }
        hif_target_sleep_state_adjust(a2);
      }
    }
    goto LABEL_24;
  }
  if ( (hif_target_sleep_state_adjust(a2) & 0x80000000) != 0 )
    goto LABEL_24;
  hif_write32_mb_reg_window(
    a2,
    *(_QWORD *)(a2 + 30720)
  + (unsigned int)(*(_DWORD *)(*(_QWORD *)(a2 + 616) + 296LL) | *(_DWORD *)(*(_QWORD *)(a2 + 616) + 272LL)),
    0);
  v9 = *(_DWORD **)(a2 + 616);
  hif_write32_mb_reg_window(
    a2,
    *(_QWORD *)(a2 + 30720) + (unsigned int)(v9[75] | v9[68]),
    (unsigned int)(v9[77] | v9[76]) | v9[221]);
  if ( (unsigned int)hif_read32_mb_reg_window(
                       a2,
                       *(_QWORD *)(a2 + 30720)
                     + (unsigned int)(*(_DWORD *)(*(_QWORD *)(a2 + 616) + 296LL)
                                    | *(_DWORD *)(*(_QWORD *)(a2 + 616) + 272LL))) == -559038737 )
  {
    qdf_trace_msg(
      0x3Du,
      2u,
      "%s: SoC returns 0xdeadbeef!!",
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      "hif_pci_legacy_ce_interrupt_handler");
    pci_read_config_word(*(_QWORD *)(a2 + 30768), 0, v122);
    qdf_trace_msg(
      0x3Du,
      2u,
      "%s: PCI Vendor ID = 0x%04x",
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      "hif_pci_legacy_ce_interrupt_handler",
      v122[0]);
    pci_read_config_word(*(_QWORD *)(a2 + 30768), 2, v122);
    qdf_trace_msg(
      0x3Du,
      2u,
      "%s: PCI Device ID = 0x%04x",
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      "hif_pci_legacy_ce_interrupt_handler",
      v122[0]);
    pci_read_config_word(*(_QWORD *)(a2 + 30768), 4, v122);
    qdf_trace_msg(
      0x3Du,
      2u,
      "%s: PCI Command = 0x%04x",
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      "hif_pci_legacy_ce_interrupt_handler",
      v122[0]);
    pci_read_config_word(*(_QWORD *)(a2 + 30768), 6, v122);
    qdf_trace_msg(
      0x3Du,
      2u,
      "%s: PCI Status = 0x%04x",
      v42,
      v43,
      v44,
      v45,
      v46,
      v47,
      v48,
      v49,
      "hif_pci_legacy_ce_interrupt_handler",
      v122[0]);
    pci_read_config_dword(*(_QWORD *)(a2 + 30768), 16, &v121);
    qdf_trace_msg(
      0x3Du,
      2u,
      "%s: PCI BAR0 = 0x%08x",
      v50,
      v51,
      v52,
      v53,
      v54,
      v55,
      v56,
      v57,
      "hif_pci_legacy_ce_interrupt_handler",
      v121);
    v58 = hif_read32_mb_reg_window(
            a2,
            *(_QWORD *)(a2 + 30720)
          + *(unsigned int *)(*(_QWORD *)(a2 + 632) + 160LL)
          + *(unsigned int *)(*(_QWORD *)(a2 + 632) + 152LL));
    qdf_trace_msg(
      0x3Du,
      2u,
      "%s: RTC_STATE_ADDRESS = 0x%08x",
      v59,
      v60,
      v61,
      v62,
      v63,
      v64,
      v65,
      v66,
      "hif_pci_legacy_ce_interrupt_handler",
      v58);
    v67 = hif_read32_mb_reg_window(
            a2,
            *(_QWORD *)(a2 + 30720)
          + *(unsigned int *)(*(_QWORD *)(a2 + 632) + 160LL)
          + *(unsigned int *)(*(_QWORD *)(a2 + 632) + 168LL));
    qdf_trace_msg(
      0x3Du,
      2u,
      "%s: PCIE_SOC_WAKE_ADDRESS = 0x%08x",
      v68,
      v69,
      v70,
      v71,
      v72,
      v73,
      v74,
      v75,
      "hif_pci_legacy_ce_interrupt_handler",
      v67);
    v76 = hif_read32_mb_reg_window(a2, *(_QWORD *)(a2 + 30720) + 524296LL);
    v77 = hif_read32_mb_reg_window(a2, *(_QWORD *)(a2 + 30720) + 524300LL);
    qdf_trace_msg(
      0x3Du,
      2u,
      "%s: 0x80008 = 0x%08x, 0x8000c = 0x%08x",
      v78,
      v79,
      v80,
      v81,
      v82,
      v83,
      v84,
      v85,
      "hif_pci_legacy_ce_interrupt_handler",
      v76,
      v77);
    v86 = hif_read32_mb_reg_window(a2, *(_QWORD *)(a2 + 30720) + 524304LL);
    v87 = hif_read32_mb_reg_window(a2, *(_QWORD *)(a2 + 30720) + 524308LL);
    qdf_trace_msg(
      0x3Du,
      2u,
      "%s: 0x80010 = 0x%08x, 0x80014 = 0x%08x",
      v88,
      v89,
      v90,
      v91,
      v92,
      v93,
      v94,
      v95,
      "hif_pci_legacy_ce_interrupt_handler",
      v86,
      v87);
    v96 = hif_read32_mb_reg_window(a2, *(_QWORD *)(a2 + 30720) + 524312LL);
    v97 = hif_read32_mb_reg_window(a2, *(_QWORD *)(a2 + 30720) + 524316LL);
    qdf_trace_msg(
      0x3Du,
      2u,
      "%s: 0x80018 = 0x%08x, 0x8001c = 0x%08x",
      v98,
      v99,
      v100,
      v101,
      v102,
      v103,
      v104,
      v105,
      "hif_pci_legacy_ce_interrupt_handler",
      v96,
      v97);
  }
  v106 = hif_read32_mb_reg_window(a2, *(_QWORD *)(a2 + 40) + *(unsigned int *)(v2 + 472));
  if ( v106 == -1 )
  {
    if ( (hif_target_sleep_state_adjust(a2) & 0x80000000) != 0 )
      goto LABEL_24;
    goto LABEL_2;
  }
  v107 = v106;
  v108 = *(_DWORD *)(*(_QWORD *)(a2 + 632) + 184LL);
  if ( (hif_target_sleep_state_adjust(a2) & 0x80000000) != 0 )
    goto LABEL_24;
  if ( (v108 & v107) == 0 )
    goto LABEL_2;
  *(_DWORD *)(v2 + 2228) = a1;
  *(_DWORD *)(a2 + 720) = 1;
  _X8 = (unsigned int *)(a2 + 672);
  __asm { PRFM            #0x11, [X8] }
  do
    v117 = __ldxr(_X8);
  while ( __stxr(v117 + 1, _X8) );
  _X9 = (unsigned __int64 *)(a2 + 30792);
  __asm { PRFM            #0x11, [X9] }
  do
    v120 = __ldxr(_X9);
  while ( __stlxr(v120 | 1, _X9) );
  __dmb(0xBu);
  if ( (v120 & 1) == 0 )
    _tasklet_schedule(a2 + 30784);
LABEL_24:
  _ReadStatusReg(SP_EL0);
  return 1;
}
