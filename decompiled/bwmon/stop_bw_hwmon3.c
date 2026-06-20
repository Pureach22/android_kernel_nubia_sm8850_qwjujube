__int64 __fastcall stop_bw_hwmon3(__int64 a1)
{
  __int64 v1; // x19
  __int64 v2; // t1
  int v3; // w0

  v1 = a1;
  *(_BYTE *)(a1 + 224) = 0;
  cancel_work_sync(a1 + 192);
  raw_spin_lock(&mon_irq_lock);
  v2 = *(_QWORD *)(v1 - 40);
  v1 -= 40;
  v3 = readl_relaxed(v2 + 12);
  writel_relaxed(v3 & 0xFFFFFFF0, *(_QWORD *)v1 + 12LL);
  raw_spin_unlock(&mon_irq_lock);
  __dsb(0xFu);
  synchronize_irq(*(unsigned int *)(v1 + 20));
  free_irq(*(unsigned int *)(v1 + 20), v1);
  writel_relaxed(*(unsigned int *)(v1 + 300), *(_QWORD *)v1 + 16LL);
  __dsb(0xFu);
  writel_relaxed(2, *(_QWORD *)v1 + 20LL);
  __dsb(0xEu);
  writel_relaxed(0, *(_QWORD *)v1 + 20LL);
  __dsb(0xFu);
  writel_relaxed(15, *(_QWORD *)v1 + 8LL);
  __dsb(0xEu);
  return writel_relaxed(0, *(_QWORD *)v1 + 8LL);
}
