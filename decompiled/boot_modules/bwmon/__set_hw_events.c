__int64 __fastcall _set_hw_events(__int64 a1, unsigned int a2, int a3)
{
  unsigned int v4; // w0
  unsigned int *v6; // x8
  unsigned int v8; // w12
  unsigned __int64 v9; // x8
  unsigned __int64 v10; // x9
  int v11; // w10
  char v12; // w11
  bool v13; // cc
  char v14; // w12
  unsigned __int64 v15; // x13
  __int64 v16; // x8
  unsigned __int64 v17; // x12
  __int64 v18; // x9
  unsigned __int64 v19; // x8
  unsigned int v20; // w21
  unsigned __int64 v21; // x23
  unsigned __int64 v22; // x22
  __int64 v23; // x8
  unsigned int v24; // w0
  unsigned int *v25; // x1
  __int64 v26; // x8
  int v28; // w11
  unsigned int v29; // w0
  __int64 v30; // x9

  v4 = *(_DWORD *)(a1 + 260);
  v6 = *(unsigned int **)(a1 - 40);
  if ( a3 )
  {
    if ( a3 == 1 )
    {
      writel_relaxed(v4, v6 + 168);
      __dsb(0xFu);
      writel_relaxed(1u, (unsigned int *)(*(_QWORD *)(a1 - 40) + 676LL));
      __dsb(0xFu);
      writel_relaxed(0xF0u, (unsigned int *)(*(_QWORD *)(a1 - 40) + 264LL));
      __dsb(0xFu);
      writel_relaxed(1 << *(_DWORD *)(a1 - 24), (unsigned int *)(*(_QWORD *)(a1 - 32) + 264LL));
      __dsb(0xFu);
    }
    else
    {
      writel_relaxed(v4, v6 + 4);
      __dsb(0xFu);
      writel_relaxed(1u, (unsigned int *)(*(_QWORD *)(a1 - 40) + 20LL));
      __dsb(0xEu);
      writel_relaxed(0, (unsigned int *)(*(_QWORD *)(a1 - 40) + 20LL));
      __dsb(0xFu);
      writel_relaxed(0xFu, (unsigned int *)(*(_QWORD *)(a1 - 40) + 8LL));
      __dsb(0xEu);
      writel_relaxed(0, (unsigned int *)(*(_QWORD *)(a1 - 40) + 8LL));
    }
  }
  else
  {
    writel_relaxed(v4, v6 + 160);
    __dsb(0xFu);
    writel_relaxed(1u, (unsigned int *)(*(_QWORD *)(a1 - 40) + 644LL));
    __dsb(0xFu);
    writel_relaxed(3u, (unsigned int *)(*(_QWORD *)(a1 - 40) + 264LL));
    __dsb(0xFu);
    writel_relaxed(1 << *(_DWORD *)(a1 - 24), (unsigned int *)(*(_QWORD *)(a1 - 32) + 264LL));
    __dsb(0xFu);
  }
  if ( *(_DWORD *)(a1 + 264) != a2 )
  {
    v28 = *(_DWORD *)(a1 + 256);
    *(_DWORD *)(a1 + 264) = a2;
    v29 = v28 * (a2 % 0x3E8) / 0x3E8 + v28 * (a2 / 0x3E8);
    if ( HIBYTE(v29) )
    {
      printk(&unk_C59F, 0xFFFFFF, 0xFFFFFF);
      v29 = 0xFFFFFF;
    }
    v30 = 680;
    if ( a3 == 2 )
      v30 = 32;
    writel_relaxed(v29, (unsigned int *)(*(_QWORD *)(a1 - 40) + v30));
  }
  v8 = *(unsigned __int8 *)(a1 + 272);
  v9 = *(_QWORD *)(a1 + 232) * a2;
  v10 = *(_QWORD *)(a1 + 240) * a2;
  if ( *(_DWORD *)(a1 + 248) >= 0xFFu )
    v11 = 255;
  else
    v11 = *(_DWORD *)(a1 + 248);
  v12 = 20 - v8;
  v13 = v8 > 0x14;
  v14 = v8 - 20;
  v15 = v9 >> v14;
  v16 = v9 << v12;
  v17 = v10 >> v14;
  v18 = v10 << v12;
  if ( v13 )
    v16 = v15;
  v19 = v16 + 999;
  if ( v13 )
    v18 = v17;
  v20 = (v11 << 8) | 0x1FF00FF;
  v21 = v19 / 0x3E8;
  v22 = (v18 + 999) / 0x3E8uLL;
  if ( *(_DWORD *)(a1 + 276) < (unsigned int)(v19 / 0x3E8) || (unsigned int)v22 > (unsigned int)v21 )
  {
    printk(&unk_C42B, (unsigned int)v21, (unsigned int)v22);
    if ( (unsigned int)v21 >= *(_DWORD *)(a1 + 276) )
      LODWORD(v21) = *(_DWORD *)(a1 + 276);
    if ( (unsigned int)v22 >= (int)v21 - 1 )
      LODWORD(v22) = v21 - 1;
  }
  v23 = *(_QWORD *)(a1 - 40);
  if ( a3 == 2 )
  {
    writel_relaxed(v21, (unsigned int *)(v23 + 36));
    writel_relaxed(v22, (unsigned int *)(*(_QWORD *)(a1 - 40) + 40LL));
    writel_relaxed(0, (unsigned int *)(*(_QWORD *)(a1 - 40) + 44LL));
    writel_relaxed(v20, (unsigned int *)(*(_QWORD *)(a1 - 40) + 52LL));
    v24 = *(_DWORD *)(a1 + 260) | 1;
    v25 = (unsigned int *)(*(_QWORD *)(a1 - 40) + 16LL);
  }
  else
  {
    writel_relaxed(v21, (unsigned int *)(v23 + 684));
    writel_relaxed(v22, (unsigned int *)(*(_QWORD *)(a1 - 40) + 688LL));
    writel_relaxed(0, (unsigned int *)(*(_QWORD *)(a1 - 40) + 692LL));
    writel_relaxed(v20, (unsigned int *)(*(_QWORD *)(a1 - 40) + 700LL));
    v26 = *(_QWORD *)(a1 - 40);
    v24 = *(_DWORD *)(a1 + 260) | 1;
    if ( a3 )
      v25 = (unsigned int *)(v26 + 672);
    else
      v25 = (unsigned int *)(v26 + 640);
  }
  return writel_relaxed(v24, v25);
}
