bool __fastcall handle_eud_irq(__int64 a1, __int64 a2)
{
  char v3; // w21
  char v4; // w19
  int v5; // w0
  int i; // w22
  unsigned int v7; // w0
  __int64 v8; // x8
  unsigned int v9; // w23
  __int64 v10; // x21
  __int64 v11; // x0
  char v12; // w0
  __int64 v13; // x1
  __int64 v14; // x0
  char v15; // w0
  __int64 v16; // x1
  char v17; // w0
  unsigned int *v18; // x1

  v3 = readl_relaxed(*(_QWORD *)(a2 + 24) + 36LL);
  v4 = readb_relaxed(*(_QWORD *)(a2 + 24) + 68LL);
  if ( (v4 & 1) == 0 )
  {
    if ( (v4 & 2) == 0 )
      goto LABEL_3;
    goto LABEL_22;
  }
  if ( (unsigned int)readl_relaxed(*(_QWORD *)(a2 + 24) + 12LL) == 144 )
  {
    raw_spin_lock(a2 + 40);
    v5 = readl_relaxed(*(_QWORD *)(a2 + 24) + 16LL);
    if ( v5 )
    {
      for ( i = v5; i; --i )
      {
        v7 = readl_relaxed(*(_QWORD *)(a2 + 24) + 20LL);
        v8 = *(_QWORD *)(a2 + 400);
        v9 = v7;
        ++*(_DWORD *)(a2 + 272);
        if ( v8 )
        {
          if ( (_BYTE)v7 && jiffies - v8 < 0 )
          {
            if ( (unsigned int)sysrq_mask() )
            {
              handle_sysrq(v9);
              *(_QWORD *)(a2 + 400) = 0;
              continue;
            }
            if ( (uart_try_toggle_sysrq(a2 + 40, v9) & 1) != 0 )
              continue;
          }
          *(_QWORD *)(a2 + 400) = 0;
        }
        uart_insert_char(a2 + 40, 0, 0, v9, 0);
      }
    }
    raw_spin_unlock(a2 + 40);
    tty_flip_buffer_push(*(_QWORD *)(a2 + 248));
  }
  v4 &= ~1u;
  if ( (v4 & 2) == 0 )
  {
LABEL_3:
    if ( (v4 & 4) == 0 )
      goto LABEL_4;
    goto LABEL_29;
  }
LABEL_22:
  if ( (v3 & 2) != 0 )
  {
    v10 = *(_QWORD *)(a2 + 248);
    writel_relaxed(0x90u, *(unsigned int **)(a2 + 24));
    if ( (unsigned int)readl_relaxed(*(_QWORD *)(a2 + 24)) == 144 )
    {
      raw_spin_lock(a2 + 40);
      while ( *(_DWORD *)(v10 + 376) == *(_DWORD *)(v10 + 380) )
      {
        writel_relaxed(0, (unsigned int *)(*(_QWORD *)(a2 + 56) + 8LL));
        ++*(_DWORD *)(a2 + 276);
      }
      __dmb(0xAu);
      ++*(_DWORD *)(v10 + 380);
      raw_spin_unlock(a2 + 40);
    }
  }
  v4 &= ~2u;
  if ( (v4 & 4) == 0 )
  {
LABEL_4:
    if ( (v4 & 8) == 0 )
      goto LABEL_5;
LABEL_30:
    v14 = *(_QWORD *)(a2 + 24) + 116LL;
    *(_QWORD *)(a2 + 12) = 0x800000005LL;
    v15 = readl_relaxed(v14);
    v16 = system_wq;
    *(_BYTE *)(a2 + 21) = (v15 & 0x40) != 0;
    queue_work_on(32, v16, a2 + 584);
    writel_relaxed(1u, (unsigned int *)(*(_QWORD *)(a2 + 24) + 132LL));
    __dsb(0xEu);
    writel_relaxed(0, (unsigned int *)(*(_QWORD *)(a2 + 24) + 132LL));
    v4 &= ~8u;
    if ( (v4 & 0x10) == 0 )
      return v4 == 0;
    goto LABEL_31;
  }
LABEL_29:
  v11 = *(_QWORD *)(a2 + 24) + 116LL;
  *(_QWORD *)(a2 + 12) = 0x400000001LL;
  v12 = readl_relaxed(v11);
  v13 = system_wq;
  *(_BYTE *)(a2 + 20) = (v12 & 0x10) != 0;
  queue_work_on(32, v13, a2 + 584);
  writel_relaxed(1u, (unsigned int *)(*(_QWORD *)(a2 + 24) + 128LL));
  __dsb(0xEu);
  writel_relaxed(0, (unsigned int *)(*(_QWORD *)(a2 + 24) + 128LL));
  v4 &= ~4u;
  if ( (v4 & 8) != 0 )
    goto LABEL_30;
LABEL_5:
  if ( (v4 & 0x10) == 0 )
    return v4 == 0;
LABEL_31:
  v17 = readl_relaxed(*(_QWORD *)(a2 + 24) + 4120LL);
  v18 = (unsigned int *)(*(_QWORD *)(a2 + 24) + 4120LL);
  if ( (v17 & 1) != 0 )
  {
    writel_relaxed(0, v18);
    __dsb(0xEu);
    _const_udelay(429500);
    writel_relaxed(1u, (unsigned int *)(*(_QWORD *)(a2 + 24) + 4120LL));
  }
  else
  {
    writel_relaxed(1u, v18);
  }
  __dsb(0xEu);
  v4 &= ~0x10u;
  return v4 == 0;
}
