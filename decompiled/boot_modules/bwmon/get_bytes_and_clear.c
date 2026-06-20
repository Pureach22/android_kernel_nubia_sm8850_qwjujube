__int64 __fastcall get_bytes_and_clear(__int64 a1)
{
  __int64 v2; // x20
  char v3; // w0

  writel_relaxed(*(unsigned int *)(a1 + 260), *(_QWORD *)(a1 - 40) + 640LL);
  __dsb(0xFu);
  v2 = (unsigned int)readl_relaxed(*(_QWORD *)(a1 - 40) + 648LL);
  v3 = readl_relaxed(*(_QWORD *)(a1 - 40) + 256LL);
  if ( (v3 & 2) != 0 && *(_BYTE *)(*(_QWORD *)(a1 - 16) + 1LL) )
    v2 += 0xFFFFFFFFLL;
  if ( (v3 & 1) != 0 && **(_BYTE **)(a1 - 16) == 1 )
    v2 += (unsigned int)readl_relaxed(*(_QWORD *)(a1 - 40) + 656LL);
  writel_relaxed(1, *(_QWORD *)(a1 - 40) + 644LL);
  __dsb(0xFu);
  writel_relaxed(3, *(_QWORD *)(a1 - 40) + 264LL);
  __dsb(0xFu);
  writel_relaxed((unsigned int)(1 << *(_DWORD *)(a1 - 24)), *(_QWORD *)(a1 - 32) + 264LL);
  __dsb(0xFu);
  writel_relaxed(*(_DWORD *)(a1 + 260) | 1u, *(_QWORD *)(a1 - 40) + 640LL);
  return v2;
}
