__int64 __fastcall get_bytes_and_clear2(__int64 a1)
{
  unsigned int v2; // w8
  unsigned int v3; // w8
  unsigned int v4; // w0
  __int64 v5; // x9
  unsigned int v6; // w0
  __int64 v7; // x9
  __int64 v8; // x20

  writel_relaxed(*(unsigned int *)(a1 + 260), *(_QWORD *)(a1 - 40) + 672LL);
  __dsb(0xFu);
  v2 = *(_DWORD *)(a1 + 268);
  if ( v2 )
  {
    v3 = __clz(v2) ^ 0x1F;
  }
  else
  {
    v4 = readl_relaxed(*(_QWORD *)(a1 - 40) + 728LL);
    v3 = (__clz(v4) >> 3) ^ 3;
    if ( !v4 )
      v3 = 0;
  }
  v5 = *(_QWORD *)(a1 - 40);
  *(_DWORD *)(a1 + 268) = 0;
  v6 = readl_relaxed(v5 + 4 * v3 + 736);
  if ( v6 )
    v7 = v6 + 1LL;
  else
    v7 = 0;
  v8 = v7 << *(_BYTE *)(a1 + 272);
  writel_relaxed(1, *(_QWORD *)(a1 - 40) + 676LL);
  __dsb(0xFu);
  writel_relaxed(240, *(_QWORD *)(a1 - 40) + 264LL);
  __dsb(0xFu);
  writel_relaxed((unsigned int)(1 << *(_DWORD *)(a1 - 24)), *(_QWORD *)(a1 - 32) + 264LL);
  __dsb(0xFu);
  writel_relaxed(*(_DWORD *)(a1 + 260) | 1u, *(_QWORD *)(a1 - 40) + 672LL);
  return v8;
}
