__int64 __fastcall wcd938x_mbhc_irq_control(__int64 a1, __int64 a2, char a3)
{
  __int64 v3; // x0

  v3 = *(_QWORD *)(*(_QWORD *)(a1 + 24) + 152LL) + 304LL;
  if ( (a3 & 1) != 0 )
    return wcd_enable_irq(v3, a2);
  else
    return wcd_disable_irq(v3, a2);
}
