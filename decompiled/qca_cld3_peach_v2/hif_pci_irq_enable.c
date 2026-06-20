__int64 __fastcall hif_pci_irq_enable(__int64 a1, char a2)
{
  int v3; // w21
  __int64 v4; // x0
  int v5; // w8
  int v6; // w8
  _DWORD *v7; // x8

  v3 = 1 << a2;
  v4 = raw_spin_lock_irqsave(a1 + 31112);
  v5 = *(_DWORD *)(a1 + 652);
  *(_QWORD *)(a1 + 31120) = v4;
  v6 = v5 & ~v3;
  *(_DWORD *)(a1 + 652) = v6;
  if ( !v6 && !*(_DWORD *)(a1 + 30776) && *(_DWORD *)(a1 + 600) != 1 && !*(_DWORD *)(a1 + 684) )
  {
    v7 = *(_DWORD **)(a1 + 616);
    hif_write32_mb_reg_window(a1, *(_QWORD *)(a1 + 40) + (v7[74] | v7[68]), v7[77] | v7[76] | v7[221]);
    hif_read32_mb_reg_window(
      a1,
      *(_QWORD *)(a1 + 40)
    + (unsigned int)(*(_DWORD *)(*(_QWORD *)(a1 + 616) + 296LL) | *(_DWORD *)(*(_QWORD *)(a1 + 616) + 272LL)));
  }
  if ( *(_BYTE *)(a1 + 584) == 1 )
    hif_target_sleep_state_adjust(a1);
  raw_spin_unlock_irqrestore(a1 + 31112, *(_QWORD *)(a1 + 31120));
  return hif_fw_interrupt_handler(0, a1);
}
