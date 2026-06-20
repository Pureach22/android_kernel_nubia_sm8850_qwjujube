__int64 __fastcall smp2p_irq_get_irqchip_state(__int64 a1, int a2, _BYTE *a3)
{
  __int64 v3; // x8

  if ( a2 != 3 )
    return 4294967274LL;
  v3 = *(_QWORD *)(*(_QWORD *)(a1 + 48) + 32LL);
  if ( !v3 )
    return 4294967277LL;
  *a3 = ((unsigned __int64)(unsigned int)readl(v3) >> *(_QWORD *)(a1 + 8)) & 1;
  return 0;
}
