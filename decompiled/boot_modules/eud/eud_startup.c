__int64 __fastcall eud_startup(__int64 a1)
{
  writel_relaxed(1u, (unsigned int *)(*(_QWORD *)(a1 + 16) + 68LL));
  __dsb(0xEu);
  return 0;
}
