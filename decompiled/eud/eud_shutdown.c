__int64 __fastcall eud_shutdown(__int64 a1)
{
  __int64 result; // x0

  result = writel_relaxed(0xFFFFFFFF, (unsigned int *)(*(_QWORD *)(a1 + 16) + 68LL));
  __dsb(0xEu);
  return result;
}
