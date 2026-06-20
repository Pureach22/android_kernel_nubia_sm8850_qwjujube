__int64 __fastcall qcom_cpucp_rx_interrupt(__int64 a1, _QWORD *a2)
{
  unsigned int *v2; // x21
  signed int v4; // w22
  __int64 v5; // x0
  __int64 v6; // x8
  __int64 v7; // x20

  v2 = (unsigned int *)a2[19];
  if ( v2[8] )
  {
    v4 = 0;
    do
    {
      if ( (readl(a2[21] + v2[4] + v2[6] * v4) & 8) != 0 )
      {
        writel(8, a2[21] + v2[5] + v2[6] * v4);
        __dsb(0xFu);
        v5 = raw_spin_lock_irqsave(a2[18] + 4LL * v4);
        v6 = a2[17];
        v7 = v5;
        if ( *(_QWORD *)(v6 + 248LL * v4 + 240) <= 0xFFFFFFFFFFFFF000LL )
          mbox_chan_received_data(v6 + 248LL * v4, 0);
        raw_spin_unlock_irqrestore(a2[18] + 4LL * v4, v7);
      }
      ++v4;
    }
    while ( v4 < v2[8] );
  }
  return 1;
}
