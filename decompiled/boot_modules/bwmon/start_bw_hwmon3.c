__int64 __fastcall start_bw_hwmon3(__int64 a1)
{
  __int64 *v1; // x8
  __int64 v3; // x0
  __int64 v4; // x4
  int v5; // w0
  __int64 v6; // x8
  __int64 v7; // x0
  __int64 v8; // x21
  unsigned int v9; // w10
  unsigned int v10; // w11
  unsigned __int64 v11; // x8
  char v12; // w12
  bool v13; // cc
  char v14; // w11
  unsigned __int64 v15; // x9
  unsigned __int64 v16; // x13
  __int64 v17; // x8
  unsigned __int64 v18; // x11
  __int64 v19; // x9
  unsigned __int64 v20; // x8
  unsigned int v21; // w20
  unsigned __int64 v22; // x22
  unsigned __int64 v23; // x21
  __int64 v24; // x0
  int v25; // w0
  __int64 v26; // x0
  __int64 v27; // x8
  __int64 v29; // x8
  unsigned int v30; // w19
  int v31; // w11
  __int64 v32; // x0

  v1 = *(__int64 **)(a1 - 8);
  v3 = *(unsigned int *)(a1 - 20);
  v4 = v1[14];
  if ( !v4 )
    v4 = *v1;
  v5 = request_threaded_irq(v3, bwmon_intr_handler3, bwmon_intr_thread, 8320, v4, a1 - 40);
  if ( v5 < 0 )
  {
    v29 = *(_QWORD *)(a1 - 8);
    v30 = v5;
    dev_err(v29, "Unable to register interrupt handler! (%d)\n", v5);
    return v30;
  }
  else
  {
    *(_QWORD *)(a1 + 192) = 0xFFFFFFFE00000LL;
    *(_QWORD *)(a1 + 200) = a1 + 200;
    *(_QWORD *)(a1 + 208) = a1 + 200;
    v6 = *(_QWORD *)(a1 - 40);
    v7 = *(unsigned int *)(a1 + 260);
    *(_QWORD *)(a1 + 216) = bwmon_monitor_work;
    writel_relaxed(v7, v6 + 16);
    __dsb(0xFu);
    writel_relaxed(1, *(_QWORD *)(a1 - 40) + 20LL);
    __dsb(0xEu);
    writel_relaxed(0, *(_QWORD *)(a1 - 40) + 20LL);
    __dsb(0xFu);
    v8 = *(unsigned int *)(*(_QWORD *)(a1 + 176) + 40LL);
    if ( *(_DWORD *)(a1 + 264) != (_DWORD)v8 )
    {
      v31 = *(_DWORD *)(a1 + 256);
      *(_DWORD *)(a1 + 264) = v8;
      v32 = v31 * ((unsigned int)v8 % 0x3E8) / 0x3E8 + v31 * ((unsigned int)v8 / 0x3E8);
      if ( BYTE3(v32) )
      {
        printk(&unk_C59F, 0xFFFFFF, 0xFFFFFF);
        v32 = 0xFFFFFF;
      }
      writel_relaxed(v32, *(_QWORD *)(a1 - 40) + 32LL);
    }
    v9 = *(_DWORD *)(a1 + 248);
    v10 = *(unsigned __int8 *)(a1 + 272);
    v11 = *(_QWORD *)(a1 + 232) * v8;
    if ( v9 >= 0xFF )
      v9 = 255;
    v12 = 20 - v10;
    v13 = v10 > 0x14;
    v14 = v10 - 20;
    v15 = *(_QWORD *)(a1 + 240) * v8;
    v16 = v11 >> v14;
    v17 = v11 << v12;
    v18 = v15 >> v14;
    v19 = v15 << v12;
    if ( v13 )
      v17 = v16;
    v20 = v17 + 999;
    if ( v13 )
      v19 = v18;
    v21 = (v9 << 8) | 0x1FF00FF;
    v22 = v20 / 0x3E8;
    v23 = (v19 + 999) / 0x3E8uLL;
    if ( *(_DWORD *)(a1 + 276) < (unsigned int)(v20 / 0x3E8) || (unsigned int)v23 > (unsigned int)v22 )
    {
      printk(&unk_C42B, (unsigned int)v22, (unsigned int)v23);
      if ( (unsigned int)v22 >= *(_DWORD *)(a1 + 276) )
        LODWORD(v22) = *(_DWORD *)(a1 + 276);
      if ( (unsigned int)v23 >= (int)v22 - 1 )
        LODWORD(v23) = v22 - 1;
    }
    writel_relaxed((unsigned int)v22, *(_QWORD *)(a1 - 40) + 36LL);
    writel_relaxed((unsigned int)v23, *(_QWORD *)(a1 - 40) + 40LL);
    writel_relaxed(0, *(_QWORD *)(a1 - 40) + 44LL);
    writel_relaxed(v21, *(_QWORD *)(a1 - 40) + 52LL);
    writel_relaxed(2502232321LL, *(_QWORD *)(a1 - 40) + 48LL);
    v24 = *(unsigned int *)(a1 + 280);
    if ( (_DWORD)v24 )
    {
      writel_relaxed(v24, *(_QWORD *)(a1 - 40) + 24LL);
      writel_relaxed(*(unsigned int *)(a1 + 284), *(_QWORD *)(a1 - 40) + 28LL);
    }
    writel_relaxed(15, *(_QWORD *)(a1 - 40) + 8LL);
    __dsb(0xEu);
    writel_relaxed(0, *(_QWORD *)(a1 - 40) + 8LL);
    raw_spin_lock(&mon_irq_lock);
    v25 = readl_relaxed(*(_QWORD *)(a1 - 40) + 12LL);
    writel_relaxed(v25 | 0xFu, *(_QWORD *)(a1 - 40) + 12LL);
    raw_spin_unlock(&mon_irq_lock);
    __dsb(0xFu);
    v26 = writel_relaxed(*(_DWORD *)(a1 + 260) | 1u, *(_QWORD *)(a1 - 40) + 16LL);
    v27 = ktime_get(v26);
    *(_QWORD *)(a1 + 184) = v27;
    *(_BYTE *)(a1 + 224) = 1;
    return 0;
  }
}
