__int64 __fastcall eud_tx_empty(__int64 a1)
{
  return ((unsigned int)readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 16) + 68LL)) >> 1) & 1;
}
