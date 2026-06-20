__int64 __fastcall qce_set_irqs(__int64 a1, char a2)
{
  __int64 v2; // x0

  v2 = *(_QWORD *)(a1 + 392);
  if ( (a2 & 1) != 0 )
    return sps_bam_enable_irqs(v2);
  else
    return sps_bam_disable_irqs(v2);
}
