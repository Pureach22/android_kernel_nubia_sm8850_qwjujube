__int64 __fastcall eud_start_tx(__int64 a1)
{
  __int64 result; // x0

  result = writel_relaxed(2u, (unsigned int *)(*(_QWORD *)(a1 + 16) + 68LL));
  __dsb(0xEu);
  return result;
}
