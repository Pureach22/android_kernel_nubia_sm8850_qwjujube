__int64 __fastcall dsi_ctrl_hw_kickoff_non_embedded_mode(__int64 a1, __int64 a2, unsigned int a3)
{
  int v6; // w0
  int v7; // w9
  int v8; // w0
  int v9; // w0
  __int64 result; // x0

  v6 = readl_relaxed_20((unsigned int *)(*(_QWORD *)a1 + 60LL));
  v7 = v6 & 0xAFFFFFF;
  if ( *(_BYTE *)(a2 + 11) )
    v7 = v6 | 0x4000000;
  writel_relaxed_17(
    v7 & 0xFFFFFFF | ((*(_BYTE *)(a2 + 8) & 0x3F) << 16) | 0x21000000,
    (unsigned int *)(*(_QWORD *)a1 + 60LL));
  v8 = readl_relaxed_20((unsigned int *)(*(_QWORD *)a1 + 912LL));
  writel_relaxed_17(v8 & 0xFFFFFFFD | (2 * ((a3 >> 12) & 1)), (unsigned int *)(*(_QWORD *)a1 + 912LL));
  v9 = readl_relaxed_20((unsigned int *)(*(_QWORD *)a1 + 80LL));
  writel_relaxed_17(v9 | 0x110033, (unsigned int *)(*(_QWORD *)a1 + 80LL));
  writel_relaxed_17(*(_DWORD *)a2, (unsigned int *)(*(_QWORD *)a1 + 72LL));
  result = writel_relaxed_17(*(_DWORD *)(a2 + 4) & 0xFFFFFF, (unsigned int *)(*(_QWORD *)a1 + 76LL));
  __dsb(0xEu);
  if ( (a3 & 1) == 0 )
    return writel_relaxed_17(1u, (unsigned int *)(*(_QWORD *)a1 + 144LL));
  return result;
}
