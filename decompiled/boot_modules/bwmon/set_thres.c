__int64 __fastcall set_thres(__int64 a1, unsigned __int64 a2)
{
  __int64 v4; // x21
  char v5; // w0

  writel_relaxed(*(unsigned int *)(a1 + 260), *(_QWORD *)(a1 - 40) + 640LL);
  __dsb(0xFu);
  v4 = (unsigned int)readl_relaxed(*(_QWORD *)(a1 - 40) + 648LL);
  v5 = readl_relaxed(*(_QWORD *)(a1 - 40) + 256LL);
  if ( (v5 & 2) != 0 && *(_BYTE *)(*(_QWORD *)(a1 - 16) + 1LL) )
    v4 += 0xFFFFFFFFLL;
  if ( (v5 & 1) != 0 && **(_BYTE **)(a1 - 16) == 1 )
    v4 += (unsigned int)readl_relaxed(*(_QWORD *)(a1 - 40) + 656LL);
  writel_relaxed(1, *(_QWORD *)(a1 - 40) + 644LL);
  __dsb(0xFu);
  writel_relaxed(3, *(_QWORD *)(a1 - 40) + 264LL);
  __dsb(0xFu);
  writel_relaxed((unsigned int)(1 << *(_DWORD *)(a1 - 24)), *(_QWORD *)(a1 - 32) + 264LL);
  __dsb(0xFu);
  if ( **(_BYTE **)(a1 - 16) == 1 && a2 <= 0x7A120 )
    LODWORD(a2) = 500000;
  writel_relaxed((unsigned int)a2, *(_QWORD *)(a1 - 40) + 656LL);
  writel_relaxed(*(_DWORD *)(a1 + 260) | 1u, *(_QWORD *)(a1 - 40) + 640LL);
  return v4;
}
