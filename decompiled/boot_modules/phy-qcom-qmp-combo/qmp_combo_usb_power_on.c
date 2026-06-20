__int64 __fastcall qmp_combo_usb_power_on(__int64 a1)
{
  _QWORD *v1; // x20
  __int64 v2; // x22
  __int64 v3; // x25
  __int64 v4; // x27
  __int64 v5; // x24
  __int64 v6; // x26
  __int64 v7; // x21
  __int64 v8; // x8
  int v9; // w19
  bool v10; // cc
  __int64 v11; // x19
  unsigned int v12; // w0
  unsigned int v13; // w0
  __int64 v14; // x8
  int v15; // w19
  _BYTE *v16; // x23
  __int64 v17; // x28
  _BYTE *v18; // x23
  _BYTE *v19; // x23
  __int64 v20; // x8
  int v21; // w19
  _BYTE *v22; // x23
  _BYTE *v23; // x23
  __int64 v24; // x8
  int v25; // w19
  _BYTE *v26; // x23
  __int64 v27; // x8
  int v28; // w19
  _BYTE *v29; // x23
  __int64 v30; // x19
  int v31; // w0
  __int64 v32; // x19
  int v33; // w0
  __int64 v34; // x0
  __int64 v35; // x22
  __int64 v36; // x19
  __int64 v37; // x0
  __int64 v38; // x19
  unsigned int v40; // w21
  __int64 v41; // x19
  __int64 v42; // [xsp+8h] [xbp-8h]

  v1 = *(_QWORD **)(a1 + 152);
  v2 = v1[1];
  v4 = v1[4];
  v3 = v1[5];
  v6 = v1[7];
  v5 = v1[8];
  v7 = v1[6];
  v8 = *(_QWORD *)(v2 + 8);
  v9 = *(_DWORD *)(v2 + 16);
  v42 = v1[11];
  if ( v8 )
    v10 = v9 < 1;
  else
    v10 = 1;
  if ( !v10 )
  {
    v17 = v1[3];
    v18 = (_BYTE *)(v8 + 8);
    do
    {
      if ( *v18 )
        writel(*((_DWORD *)v18 - 1), (unsigned int *)(v17 + *((unsigned int *)v18 - 2)));
      --v9;
      v18 += 12;
    }
    while ( v9 );
  }
  clk_set_parent(v1[17], v1[18]);
  v11 = v1[16];
  v12 = clk_prepare(v11);
  if ( v12 )
  {
    v40 = v12;
LABEL_62:
    dev_err(*v1, "pipe_clk enable failed err=%d\n", v40);
    return v40;
  }
  v13 = clk_enable(v11);
  if ( v13 )
  {
    v40 = v13;
    clk_unprepare(v11);
    goto LABEL_62;
  }
  v14 = *(_QWORD *)(v2 + 24);
  v15 = *(_DWORD *)(v2 + 32);
  if ( v14 && v15 >= 1 )
  {
    v16 = (_BYTE *)(v14 + 8);
    do
    {
      if ( (*v16 & 1) != 0 )
        writel(*((_DWORD *)v16 - 1), (unsigned int *)(v4 + *((unsigned int *)v16 - 2)));
      --v15;
      v16 += 12;
    }
    while ( v15 );
    v14 = *(_QWORD *)(v2 + 24);
    v15 = *(_DWORD *)(v2 + 32);
  }
  if ( v14 && v15 >= 1 )
  {
    v19 = (_BYTE *)(v14 + 8);
    do
    {
      if ( (*v19 & 2) != 0 )
        writel(*((_DWORD *)v19 - 1), (unsigned int *)(v6 + *((unsigned int *)v19 - 2)));
      --v15;
      v19 += 12;
    }
    while ( v15 );
  }
  v20 = *(_QWORD *)(v2 + 40);
  v21 = *(_DWORD *)(v2 + 48);
  if ( v20 && v21 >= 1 )
  {
    v22 = (_BYTE *)(v20 + 8);
    do
    {
      if ( (*v22 & 1) != 0 )
        writel(*((_DWORD *)v22 - 1), (unsigned int *)(v3 + *((unsigned int *)v22 - 2)));
      --v21;
      v22 += 12;
    }
    while ( v21 );
    v20 = *(_QWORD *)(v2 + 40);
    v21 = *(_DWORD *)(v2 + 48);
  }
  if ( v20 && v21 >= 1 )
  {
    v23 = (_BYTE *)(v20 + 8);
    do
    {
      if ( (*v23 & 2) != 0 )
        writel(*((_DWORD *)v23 - 1), (unsigned int *)(v5 + *((unsigned int *)v23 - 2)));
      --v21;
      v23 += 12;
    }
    while ( v21 );
  }
  v24 = *(_QWORD *)(v2 + 56);
  if ( v24 )
  {
    v25 = *(_DWORD *)(v2 + 64);
    if ( v25 >= 1 )
    {
      v26 = (_BYTE *)(v24 + 8);
      do
      {
        if ( *v26 )
          writel(*((_DWORD *)v26 - 1), (unsigned int *)(v7 + *((unsigned int *)v26 - 2)));
        --v25;
        v26 += 12;
      }
      while ( v25 );
    }
  }
  if ( v42 )
  {
    v27 = *(_QWORD *)(v2 + 72);
    if ( v27 )
    {
      v28 = *(_DWORD *)(v2 + 80);
      if ( v28 >= 1 )
      {
        v29 = (_BYTE *)(v27 + 8);
        do
        {
          if ( *v29 )
            writel(*((_DWORD *)v29 - 1), (unsigned int *)(v42 + *((unsigned int *)v29 - 2)));
          --v28;
          v29 += 12;
        }
        while ( v28 );
      }
    }
  }
  if ( *(_BYTE *)(v2 + 288) == 1 )
    usleep_range_state(10, 20, 2);
  v30 = **(unsigned int **)(v2 + 280);
  v31 = readl((unsigned int *)(v7 + v30));
  writel(v31 & 0xFFFFFFFE, (unsigned int *)(v7 + v30));
  readl((unsigned int *)(v7 + v30));
  v32 = *(unsigned int *)(*(_QWORD *)(v2 + 280) + 4LL);
  v33 = readl((unsigned int *)(v7 + v32));
  writel(v33 | 3, (unsigned int *)(v7 + v32));
  v34 = readl((unsigned int *)(v7 + v32));
  v35 = *(unsigned int *)(*(_QWORD *)(v2 + 280) + 8LL);
  v36 = ktime_get(v34);
  v37 = readl((unsigned int *)(v7 + v35));
  if ( (v37 & 0x40) == 0 )
    return 0;
  v38 = v36 + 10000000;
  while ( ktime_get(v37) <= v38 )
  {
    usleep_range_state(51, 200, 2);
    __yield();
    v37 = readl((unsigned int *)(v7 + v35));
    if ( (v37 & 0x40) == 0 )
      return 0;
  }
  if ( (readl((unsigned int *)(v7 + v35)) & 0x40) == 0 )
    return 0;
  dev_err(*v1, "phy initialization timed-out\n");
  v41 = v1[16];
  clk_disable(v41);
  clk_unprepare(v41);
  return 4294967186LL;
}
