__int64 __fastcall hif_pci_device_warm_reset(
        __int64 result,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x22
  __int64 v10; // x19
  int v11; // w20
  unsigned int v12; // w0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  unsigned int v21; // w0
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int64 v30; // x20
  bool v31; // cf
  unsigned int v32; // w21
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  int v41; // w0
  int v42; // w21
  unsigned int v43; // w0
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  int v52; // w0
  unsigned int v53; // w0
  double v54; // d0
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7
  __int64 v62; // x19
  double v63; // d0
  double v64; // d1
  double v65; // d2
  double v66; // d3
  double v67; // d4
  double v68; // d5
  double v69; // d6
  double v70; // d7

  v9 = *(_QWORD *)(result + 30720);
  if ( v9 )
  {
    v10 = result;
    qdf_trace_msg(0x3Du, 8u, "%s: Target Warm Reset", a2, a3, a4, a5, a6, a7, a8, a9, "hif_pci_device_warm_reset");
    hif_write32_mb_reg_window(
      v10,
      v9 + *(_DWORD *)(*(_QWORD *)(v10 + 632) + 160LL) + *(_DWORD *)(*(_QWORD *)(v10 + 632) + 168LL),
      *(_DWORD *)(*(_QWORD *)(v10 + 632) + 172LL));
    v11 = 10;
    do
    {
      if ( (*(_BYTE *)(v10 + 648) & 1) == 0
        && (*(_DWORD *)(*(_QWORD *)(v10 + 632) + 196LL)
          & ~((*(_DWORD *)(*(_QWORD *)(v10 + 632) + 176LL)
             & (unsigned int)hif_read32_mb_reg_window(
                               v10,
                               v9
                             + *(unsigned int *)(*(_QWORD *)(v10 + 632) + 160LL)
                             + *(unsigned int *)(*(_QWORD *)(v10 + 632) + 152LL))) >> *(_DWORD *)(*(_QWORD *)(v10 + 632)
                                                                                                + 180LL))) == 0 )
      {
        break;
      }
      _const_udelay(4295000);
      --v11;
    }
    while ( v11 );
    v12 = hif_read32_mb_reg_window(
            v10,
            v9
          + (unsigned int)(*(_DWORD *)(*(_QWORD *)(v10 + 616) + 712LL) | *(_DWORD *)(*(_QWORD *)(v10 + 616) + 272LL)));
    qdf_trace_msg(
      0x3Du,
      8u,
      "%s: Host Intr Cause reg 0x%x: value : 0x%x",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "hif_pci_device_warm_reset",
      (unsigned int)(*(_DWORD *)(*(_QWORD *)(v10 + 616) + 712LL) | *(_DWORD *)(*(_QWORD *)(v10 + 616) + 272LL)),
      v12);
    v21 = hif_read32_mb_reg_window(
            v10,
            v9
          + (unsigned int)(*(_DWORD *)(*(_QWORD *)(v10 + 616) + 736LL) | *(_DWORD *)(*(_QWORD *)(v10 + 616) + 272LL)));
    qdf_trace_msg(
      0x3Du,
      8u,
      "%s: Target CPU Intr Cause 0x%x",
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      "hif_pci_device_warm_reset",
      v21);
    hif_read32_mb_reg_window(
      v10,
      v9 + (unsigned int)(*(_DWORD *)(*(_QWORD *)(v10 + 616) + 296LL) | *(_DWORD *)(*(_QWORD *)(v10 + 616) + 272LL)));
    hif_write32_mb_reg_window(
      v10,
      v9 + (*(_DWORD *)(*(_QWORD *)(v10 + 616) + 296LL) | *(_DWORD *)(*(_QWORD *)(v10 + 616) + 272LL)),
      0);
    hif_write32_mb_reg_window(
      v10,
      v9 + *(_DWORD *)(*(_QWORD *)(v10 + 616) + 300LL) + *(_DWORD *)(*(_QWORD *)(v10 + 616) + 272LL),
      *(_DWORD *)(*(_QWORD *)(v10 + 616) + 308LL)
    | *(_DWORD *)(*(_QWORD *)(v10 + 616) + 304LL)
    | *(_DWORD *)(*(_QWORD *)(v10 + 616) + 884LL));
    v30 = -100;
    do
    {
      _const_udelay(4295000);
      v31 = __CFADD__(v30++, 1);
    }
    while ( !v31 );
    hif_read32_mb_reg_window(v10, v9 + *(unsigned int *)(*(_QWORD *)(v10 + 616) + 260LL));
    hif_write32_mb_reg_window(v10, v9 + *(_DWORD *)(*(_QWORD *)(v10 + 616) + 260LL), 0);
    v32 = hif_read32_mb_reg_window(
            v10,
            v9 + (unsigned int)(*(_DWORD *)(*(_QWORD *)(v10 + 616) + 740LL) + **(_DWORD **)(v10 + 616)));
    qdf_trace_msg(
      0x3Du,
      8u,
      "%s: addr 0x%x : 0x%x",
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      "hif_pci_device_warm_reset",
      (unsigned int)(*(_DWORD *)(*(_QWORD *)(v10 + 616) + 740LL) + **(_DWORD **)(v10 + 616)),
      v32);
    hif_write32_mb_reg_window(
      v10,
      v9 + *(_DWORD *)(*(_QWORD *)(v10 + 616) + 740LL) + **(_DWORD **)(v10 + 616),
      v32 & ~*(_DWORD *)(*(_QWORD *)(v10 + 616) + 744LL));
    v41 = hif_read32_mb_reg_window(
            v10,
            v9 + (unsigned int)(*(_DWORD *)(*(_QWORD *)(v10 + 616) + 716LL) | **(_DWORD **)(v10 + 616)));
    hif_write32_mb_reg_window(
      v10,
      v9 + (*(_DWORD *)(*(_QWORD *)(v10 + 616) + 716LL) | **(_DWORD **)(v10 + 616)),
      *(_DWORD *)(*(_QWORD *)(v10 + 616) + 728LL) | v41);
    v42 = hif_read32_mb_reg_window(
            v10,
            v9 + (unsigned int)(*(_DWORD *)(*(_QWORD *)(v10 + 616) + 716LL) | **(_DWORD **)(v10 + 616)));
    _const_udelay(4295000);
    _const_udelay(4295000);
    _const_udelay(4295000);
    _const_udelay(4295000);
    _const_udelay(4295000);
    _const_udelay(4295000);
    _const_udelay(4295000);
    _const_udelay(4295000);
    _const_udelay(4295000);
    _const_udelay(4295000);
    hif_write32_mb_reg_window(
      v10,
      v9 + (*(_DWORD *)(*(_QWORD *)(v10 + 616) + 716LL) | **(_DWORD **)(v10 + 616)),
      v42 & ~*(_DWORD *)(*(_QWORD *)(v10 + 616) + 728LL));
    hif_read32_mb_reg_window(
      v10,
      v9 + (unsigned int)(*(_DWORD *)(*(_QWORD *)(v10 + 616) + 716LL) | **(_DWORD **)(v10 + 616)));
    _const_udelay(4295000);
    _const_udelay(4295000);
    _const_udelay(4295000);
    _const_udelay(4295000);
    _const_udelay(4295000);
    _const_udelay(4295000);
    _const_udelay(4295000);
    _const_udelay(4295000);
    _const_udelay(4295000);
    _const_udelay(4295000);
    v43 = hif_read32_mb_reg_window(
            v10,
            v9
          + (unsigned int)(*(_DWORD *)(*(_QWORD *)(v10 + 616) + 736LL) | *(_DWORD *)(*(_QWORD *)(v10 + 616) + 272LL)));
    qdf_trace_msg(
      0x3Du,
      8u,
      "%s: Target CPU Intr Cause after CE reset 0x%x",
      v44,
      v45,
      v46,
      v47,
      v48,
      v49,
      v50,
      v51,
      "hif_pci_device_warm_reset",
      v43);
    v52 = hif_read32_mb_reg_window(
            v10,
            v9 + (unsigned int)(*(_DWORD *)(*(_QWORD *)(v10 + 616) + 716LL) | **(_DWORD **)(v10 + 616)));
    hif_write32_mb_reg_window(
      v10,
      v9 + (*(_DWORD *)(*(_QWORD *)(v10 + 616) + 716LL) | **(_DWORD **)(v10 + 616)),
      *(_DWORD *)(*(_QWORD *)(v10 + 616) + 732LL) | v52);
    v53 = hif_read32_mb_reg_window(
            v10,
            v9 + (unsigned int)(*(_DWORD *)(*(_QWORD *)(v10 + 616) + 716LL) | **(_DWORD **)(v10 + 616)));
    qdf_trace_msg(
      0x3Du,
      8u,
      "%s: RESET_CONTROL after cpu warm reset 0x%x",
      v54,
      v55,
      v56,
      v57,
      v58,
      v59,
      v60,
      v61,
      "hif_pci_device_warm_reset",
      v53);
    v62 = -100;
    do
    {
      _const_udelay(4295000);
      v31 = __CFADD__(v62++, 1);
    }
    while ( !v31 );
    return qdf_trace_msg(
             0x3Du,
             8u,
             "%s: Target Warm reset complete",
             v63,
             v64,
             v65,
             v66,
             v67,
             v68,
             v69,
             v70,
             "hif_pci_device_warm_reset");
  }
  return result;
}
