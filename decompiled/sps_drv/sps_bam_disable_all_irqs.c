__int64 __fastcall sps_bam_disable_all_irqs(__int64 a1)
{
  __int64 v2; // x20
  __int64 *i; // x21

  v2 = raw_spin_lock_irqsave(a1 + 228);
  bam_set_global_irq(a1 + 216, *(_DWORD *)(a1 + 128), 0, 0);
  for ( i = *(__int64 **)(a1 + 504); i != (__int64 *)(a1 + 504); i = (__int64 *)*i )
  {
    if ( i != (__int64 *)-2290649225LL && i && (i[80] & 1) == 0 )
      bam_pipe_set_irq(a1 + 216, *((_DWORD *)i + 47), 0, 0, *(_DWORD *)(a1 + 128));
  }
  __dsb(0xEu);
  *(_BYTE *)(a1 + 824) = 1;
  return raw_spin_unlock_irqrestore(a1 + 228, v2);
}
