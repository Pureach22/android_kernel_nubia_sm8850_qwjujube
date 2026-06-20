__int64 __fastcall smp2p_update_bits(__int64 a1, int a2, int a3)
{
  __int64 v6; // x22
  int v7; // w23
  unsigned int v8; // w20
  __int64 v9; // x19
  __int64 v10; // x0

  v6 = raw_spin_lock_irqsave(a1 + 96);
  v7 = readl(*(unsigned int **)(a1 + 32));
  v8 = v7 & ~a2 | a3;
  writel(v8, *(_QWORD *)(a1 + 32));
  raw_spin_unlock_irqrestore(a1 + 96, v6);
  ipc_log_string(
    ilc,
    "[%s]: %d: %s: orig:0x%0x new:0x%0x\n",
    "smp2p_update_bits",
    *(_DWORD *)(*(_QWORD *)(a1 + 16) + 52LL),
    *(const char **)(a1 + 24),
    v7,
    v8);
  if ( v8 != v7 )
  {
    v9 = *(_QWORD *)(a1 + 16);
    __dsb(0xEu);
    v10 = *(_QWORD *)(v9 + 136);
    if ( v10 )
    {
      mbox_send_message(v10, 0);
      mbox_client_txdone(*(_QWORD *)(v9 + 136), 0);
    }
    else
    {
      regmap_write(*(_QWORD *)(v9 + 64), *(unsigned int *)(v9 + 72), 1LL << *(_DWORD *)(v9 + 76));
    }
  }
  return 0;
}
