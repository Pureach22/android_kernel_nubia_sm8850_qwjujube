__int64 __fastcall hif_pci_target_sleep_state_adjust(
        __int64 a1,
        char a2,
        char a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x29
  __int64 v12; // x30
  __int64 v14; // x22
  char v17; // w24
  __int64 v18; // x1
  int v19; // w8
  __int64 v20; // x24
  unsigned int multiplier; // w0
  __int64 v22; // x8
  __int64 v23; // x9
  unsigned int v24; // w20
  unsigned int v25; // w21
  unsigned int v26; // w22
  unsigned int v27; // w23
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  int v36; // w23
  int v37; // w24
  int v38; // [xsp+0h] [xbp-60h]
  __int64 v39; // [xsp+8h] [xbp-58h]
  __int64 v40; // [xsp+18h] [xbp-48h]

  if ( (*(_BYTE *)(a1 + 648) & 1) != 0 )
    return 4294967283LL;
  v40 = v12;
  v14 = *(_QWORD *)(a1 + 40);
  if ( *(_DWORD *)(a1 + 684) )
  {
    qdf_trace_msg(
      0x3Du,
      2u,
      "%s: Invalid access, PCIe link is down",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "hif_pci_target_sleep_state_adjust");
    hif_pci_target_sleep_state_adjust_debug = 1;
    return 4294967283LL;
  }
  if ( hif_pci_target_sleep_state_adjust_debug == 1 )
  {
    qdf_trace_msg(
      0x3Du,
      2u,
      "%s: Invalid access, PCIe link is suspended",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "hif_pci_target_sleep_state_adjust");
    a3 = 1;
  }
  v17 = a3;
  v18 = raw_spin_lock_irqsave(a1 + 27272);
  *(_QWORD *)(a1 + 27280) = v18;
  if ( (a2 & 1) != 0 )
  {
    v19 = *(_DWORD *)(a1 + 27304) - 1;
    *(_DWORD *)(a1 + 27304) = v19;
    if ( !v19 )
    {
      *(_BYTE *)(a1 + 27308) = 0;
      *(_QWORD *)(a1 + 27376) = jiffies;
    }
    if ( (*(_BYTE *)(a1 + 27309) & 1) == 0 )
    {
      *(_BYTE *)(a1 + 27309) = 1;
      timer_delete((timer_t)(a1 + 27312));
      v20 = jiffies;
      multiplier = qdf_timer_get_multiplier();
      *(_QWORD *)(a1 + 27328) = v20 - multiplier + 16LL * multiplier;
      add_timer(a1 + 27312);
      v18 = *(_QWORD *)(a1 + 27280);
    }
    raw_spin_unlock_irqrestore(a1 + 27272, v18);
  }
  else
  {
    if ( *(_BYTE *)(a1 + 27309) == 1 )
    {
      *(_BYTE *)(a1 + 27308) = 1;
    }
    else if ( !*(_DWORD *)(a1 + 27304) )
    {
      hif_write32_mb_reg_window(
        a1,
        v14 + *(_DWORD *)(*(_QWORD *)(a1 + 632) + 160LL) + *(_DWORD *)(*(_QWORD *)(a1 + 632) + 168LL),
        *(_DWORD *)(*(_QWORD *)(a1 + 632) + 172LL));
      v18 = *(_QWORD *)(a1 + 27280);
    }
    ++*(_DWORD *)(a1 + 27304);
    raw_spin_unlock_irqrestore(a1 + 27272, v18);
    if ( (v17 & 1) != 0 && (*(_BYTE *)(a1 + 27308) & 1) == 0 )
    {
      v36 = 0;
      v37 = 5;
      if ( (*(_BYTE *)(a1 + 648) & 1) != 0 )
        goto LABEL_31;
LABEL_30:
      if ( (*(_DWORD *)(*(_QWORD *)(a1 + 632) + 196LL)
          & ~((*(_DWORD *)(*(_QWORD *)(a1 + 632) + 176LL)
             & (unsigned int)hif_read32_mb_reg_window(
                               a1,
                               v14
                             + *(unsigned int *)(*(_QWORD *)(a1 + 632) + 160LL)
                             + *(unsigned int *)(*(_QWORD *)(a1 + 632) + 152LL))) >> *(_DWORD *)(*(_QWORD *)(a1 + 632)
                                                                                               + 180LL))) != 0 )
      {
LABEL_31:
        while ( v36 <= 8000 )
        {
          _udelay((unsigned int)v37);
          v36 += v37;
          if ( v37 < 50 )
            v37 += 5;
          if ( (*(_BYTE *)(a1 + 648) & 1) == 0 )
            goto LABEL_30;
        }
        hif_log_soc_wakeup_timeout(a1);
        return 4294967283LL;
      }
      *(_BYTE *)(a1 + 27308) = 1;
      if ( v36 > hif_pci_target_sleep_state_adjust_max_delay )
        hif_pci_target_sleep_state_adjust_max_delay = v36;
    }
  }
  if ( hif_pci_target_sleep_state_adjust_debug == 1 && *(_BYTE *)(a1 + 27308) == 1 )
  {
    v22 = *(_QWORD *)(a1 + 616);
    v23 = *(_QWORD *)(a1 + 30720);
    hif_pci_target_sleep_state_adjust_debug = 0;
    v24 = hif_read32_mb_reg_window(a1, v23 + *(unsigned int *)(v22 + 272) + *(unsigned int *)(v22 + 296));
    v25 = hif_read32_mb_reg_window(
            a1,
            *(_QWORD *)(a1 + 30720)
          + *(unsigned int *)(*(_QWORD *)(a1 + 616) + 272LL)
          + *(unsigned int *)(*(_QWORD *)(a1 + 616) + 712LL));
    v26 = hif_read32_mb_reg_window(
            a1,
            *(_QWORD *)(a1 + 30720)
          + *(unsigned int *)(*(_QWORD *)(a1 + 616) + 272LL)
          + *(unsigned int *)(*(_QWORD *)(a1 + 616) + 736LL));
    v27 = hif_read32_mb_reg_window(
            a1,
            *(_QWORD *)(a1 + 30720)
          + *(unsigned int *)(*(_QWORD *)(a1 + 616) + 272LL)
          + *(unsigned int *)(*(_QWORD *)(a1 + 616) + 300LL));
    v38 = hif_read32_mb_reg_window(
            a1,
            *(_QWORD *)(a1 + 30720)
          + *(unsigned int *)(*(_QWORD *)(a1 + 624) + 60LL)
          + *(unsigned int *)(*(_QWORD *)(a1 + 624) + 64LL));
    qdf_trace_msg(
      0x3Du,
      2u,
      "%s: INTR_ENABLE_REG = 0x%08x, INTR_CAUSE_REG = 0x%08x, CPU_INTR_REG = 0x%08x, INTR_CLR_REG = 0x%08x, CE_INTERRUPT_"
      "SUMMARY_REG = 0x%08x",
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      "hif_pci_target_sleep_state_adjust",
      v24,
      v25,
      v26,
      v27,
      v38,
      v39,
      v11,
      v40);
  }
  return 0;
}
