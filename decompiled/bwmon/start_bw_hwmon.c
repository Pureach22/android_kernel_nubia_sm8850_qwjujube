__int64 __fastcall start_bw_hwmon(__int64 a1, __int64 a2)
{
  __int64 *v2; // x9
  __int64 v4; // x8
  __int64 v5; // x0
  __int64 v7; // x4
  __int64 v8; // x21
  int v9; // w0
  __int64 v10; // x0
  __int64 v11; // x0
  unsigned int v12; // w0
  int v13; // w0
  __int64 v14; // x0
  __int64 v15; // x8
  __int64 result; // x0
  __int64 v17; // x8
  unsigned int v18; // w19

  v2 = *(__int64 **)(a1 - 8);
  v4 = *(_QWORD *)(a1 + 176);
  v5 = *(unsigned int *)(a1 - 20);
  v7 = v2[14];
  if ( !v7 )
    v7 = *v2;
  v8 = *(unsigned int *)(v4 + 40);
  v9 = request_threaded_irq(v5, bwmon_intr_handler, bwmon_intr_thread, 8320, v7, a1 - 40);
  if ( v9 < 0 )
  {
    v17 = *(_QWORD *)(a1 - 8);
    v18 = v9;
    dev_err(v17, "Unable to register interrupt handler! (%d)\n", v9);
    return v18;
  }
  else
  {
    *(_QWORD *)(a1 + 192) = 0xFFFFFFFE00000LL;
    *(_QWORD *)(a1 + 200) = a1 + 200;
    *(_QWORD *)(a1 + 208) = a1 + 200;
    v10 = *(unsigned int *)(a1 + 260);
    *(_QWORD *)(a1 + 216) = bwmon_monitor_work;
    writel_relaxed(v10, *(_QWORD *)(a1 - 40) + 640LL);
    __dsb(0xFu);
    writel_relaxed(1, *(_QWORD *)(a1 - 40) + 644LL);
    __dsb(0xFu);
    writel_relaxed(
      ((unsigned int)((((unsigned __int64)(v8 * a2 + 999) >> 3) * (unsigned __int128)0x20C49BA5E353F7CFuLL) >> 64) << 16)
    & 0xFFF00000,
      *(_QWORD *)(a1 - 40) + 656LL);
    v11 = *(unsigned int *)(a1 + 280);
    if ( (_DWORD)v11 )
    {
      writel_relaxed(v11, *(_QWORD *)(a1 - 40) + 664LL);
      writel_relaxed(*(unsigned int *)(a1 + 284), *(_QWORD *)(a1 - 40) + 668LL);
    }
    writel_relaxed(3, *(_QWORD *)(a1 - 40) + 264LL);
    __dsb(0xFu);
    writel_relaxed((unsigned int)(1 << *(_DWORD *)(a1 - 24)), *(_QWORD *)(a1 - 32) + 264LL);
    __dsb(0xFu);
    raw_spin_lock(&mon_irq_lock);
    v12 = readl_relaxed(*(_QWORD *)(a1 - 32) + 268LL);
    writel_relaxed((1 << *(_DWORD *)(a1 - 24)) | v12, *(_QWORD *)(a1 - 32) + 268LL);
    v13 = readl_relaxed(*(_QWORD *)(a1 - 40) + 268LL);
    writel_relaxed(v13 | 1u, *(_QWORD *)(a1 - 40) + 268LL);
    raw_spin_unlock(&mon_irq_lock);
    __dsb(0xFu);
    v14 = writel_relaxed(*(_DWORD *)(a1 + 260) | 1u, *(_QWORD *)(a1 - 40) + 640LL);
    v15 = ktime_get(v14);
    result = 0;
    *(_BYTE *)(a1 + 224) = 1;
    *(_QWORD *)(a1 + 184) = v15;
  }
  return result;
}
