__int64 __fastcall stop_bw_hwmon2(__int64 a1)
{
  int v2; // w0
  int v3; // w0
  __int64 result; // x0

  *(_BYTE *)(a1 + 224) = 0;
  cancel_work_sync(a1 + 192);
  raw_spin_lock(&mon_irq_lock);
  v2 = readl_relaxed(*(_QWORD *)(a1 - 32) + 268LL);
  writel_relaxed(v2 & (unsigned int)~(1 << *(_DWORD *)(a1 - 24)), *(_QWORD *)(a1 - 32) + 268LL);
  v3 = readl_relaxed(*(_QWORD *)(a1 - 40) + 268LL);
  writel_relaxed(v3 & 0xFFFFFF0F, *(_QWORD *)(a1 - 40) + 268LL);
  raw_spin_unlock(&mon_irq_lock);
  __dsb(0xFu);
  synchronize_irq(*(unsigned int *)(a1 - 20));
  free_irq(*(unsigned int *)(a1 - 20), a1 - 40);
  writel_relaxed(*(unsigned int *)(a1 + 260), *(_QWORD *)(a1 - 40) + 672LL);
  __dsb(0xFu);
  writel_relaxed(2, *(_QWORD *)(a1 - 40) + 676LL);
  __dsb(0xFu);
  writel_relaxed(240, *(_QWORD *)(a1 - 40) + 264LL);
  __dsb(0xFu);
  result = writel_relaxed((unsigned int)(1 << *(_DWORD *)(a1 - 24)), *(_QWORD *)(a1 - 32) + 264LL);
  __dsb(0xFu);
  return result;
}
