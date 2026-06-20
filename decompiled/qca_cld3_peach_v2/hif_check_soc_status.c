__int64 __fastcall hif_check_soc_status(__int64 a1)
{
  __int64 v2; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  unsigned int v11; // w0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  unsigned int v20; // w0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  unsigned __int16 v29; // w20
  unsigned int *v30; // x8
  __int64 v31; // x9
  __int64 v32; // x21
  const char *v34; // x2
  __int64 result; // x0
  unsigned int v36; // w0
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  __int16 v45; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v46; // [xsp+8h] [xbp-8h]

  v46 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 30768);
  v45 = 0;
  pld_pci_read_config_word(v2, 2u, (__int64)&v45);
  if ( v45 == *(_WORD *)(a1 + 30908) )
  {
    v11 = hif_read32_mb_reg_window(
            a1,
            *(_QWORD *)(a1 + 30720)
          + *(unsigned int *)(*(_QWORD *)(a1 + 632) + 160LL)
          + *(unsigned int *)(*(_QWORD *)(a1 + 632) + 152LL));
    qdf_trace_msg(
      0x3Du,
      8u,
      "%s: RTC_STATE_ADDRESS is %08x",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "hif_check_soc_status",
      v11);
    hif_write32_mb_reg_window(
      a1,
      *(_QWORD *)(a1 + 30720) + *(_DWORD *)(*(_QWORD *)(a1 + 632) + 160LL) + *(_DWORD *)(*(_QWORD *)(a1 + 632) + 168LL),
      *(_DWORD *)(*(_QWORD *)(a1 + 632) + 172LL));
    v20 = hif_read32_mb_reg_window(
            a1,
            *(_QWORD *)(a1 + 30720)
          + *(unsigned int *)(*(_QWORD *)(a1 + 632) + 160LL)
          + *(unsigned int *)(*(_QWORD *)(a1 + 632) + 168LL));
    qdf_trace_msg(
      0x3Du,
      8u,
      "%s: PCIE_SOC_WAKE_ADDRESS is %08x",
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      "hif_check_soc_status",
      v20);
    v29 = 0;
    if ( (*(_BYTE *)(a1 + 648) & 1) != 0 )
      goto LABEL_4;
LABEL_3:
    if ( (*(_DWORD *)(*(_QWORD *)(a1 + 632) + 196LL)
        & ~((*(_DWORD *)(*(_QWORD *)(a1 + 632) + 176LL)
           & (unsigned int)hif_read32_mb_reg_window(
                             a1,
                             *(_QWORD *)(a1 + 30720)
                           + *(unsigned int *)(*(_QWORD *)(a1 + 632) + 160LL)
                           + *(unsigned int *)(*(_QWORD *)(a1 + 632) + 152LL))) >> *(_DWORD *)(*(_QWORD *)(a1 + 632)
                                                                                             + 180LL))) == 0 )
    {
      v36 = hif_read32_mb_reg_window(
              a1,
              *(_QWORD *)(a1 + 30720) + **(unsigned int **)(a1 + 616) + *(unsigned int *)(*(_QWORD *)(a1 + 616) + 708LL));
      qdf_trace_msg(
        0x3Du,
        8u,
        "%s: Power register is %08x",
        v37,
        v38,
        v39,
        v40,
        v41,
        v42,
        v43,
        v44,
        "hif_check_soc_status",
        v36);
      result = 0;
      goto LABEL_13;
    }
LABEL_4:
    while ( 1 )
    {
      v30 = *(unsigned int **)(a1 + 632);
      v31 = *(_QWORD *)(a1 + 30720) + v30[40];
      if ( v29 >= 0x3E8u )
        break;
      hif_write32_mb_reg_window(a1, v31 + v30[42], v30[43]);
      v32 = -100;
      do
        _const_udelay(4295000);
      while ( !__CFADD__(v32++, 1) );
      v29 += 100;
      if ( (*(_BYTE *)(a1 + 648) & 1) == 0 )
        goto LABEL_3;
    }
    hif_read32_mb_reg_window(a1, v31 + v30[38]);
    hif_read32_mb_reg_window(
      a1,
      *(_QWORD *)(a1 + 30720)
    + *(unsigned int *)(*(_QWORD *)(a1 + 632) + 160LL)
    + *(unsigned int *)(*(_QWORD *)(a1 + 632) + 168LL));
    v34 = "%s: wake up timeout, %08x, %08x";
  }
  else
  {
    v34 = "%s: Device ID does match (read 0x%x, expect 0x%x)";
  }
  qdf_trace_msg(0x3Du, 2u, v34, v3, v4, v5, v6, v7, v8, v9, v10, "hif_check_soc_status");
  result = 4294967283LL;
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return result;
}
