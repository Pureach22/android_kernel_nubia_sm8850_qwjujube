__int64 __fastcall qmp_combo_runtime_resume(__int64 a1)
{
  __int64 v1; // x22
  unsigned int v2; // w20
  __int64 v3; // x21
  __int64 result; // x0
  unsigned int v6; // w0
  unsigned int v7; // w19
  __int64 v8; // x20
  int v9; // w0
  int v10; // w0
  __int64 v11; // x19
  __int64 v12; // x20
  __int64 v13; // x21
  __int64 v14; // x22
  int v15; // w0
  __int64 v16; // x21
  int v17; // w0
  __int64 v18; // x21
  int v19; // w0
  __int64 v20; // x20
  int v21; // w0
  int v22; // w21
  __int64 v23; // x0

  v1 = *(_QWORD *)(a1 + 152);
  *(_DWORD *)(*(_QWORD *)(a1 + 592) + 520LL) &= 0xFFFFFFF3;
  if ( *(_DWORD *)(v1 + 256) )
  {
    v2 = *(_DWORD *)(v1 + 168);
    v3 = *(_QWORD *)(v1 + 160);
    result = clk_bulk_prepare(v2, v3);
    if ( (_DWORD)result )
      return result;
    v6 = clk_bulk_enable(v2, v3);
    if ( v6 )
    {
      v7 = v6;
LABEL_5:
      clk_bulk_unprepare(v2, v3);
      return v7;
    }
    clk_set_parent(*(_QWORD *)(v1 + 136), *(_QWORD *)(v1 + 144));
    v8 = *(_QWORD *)(v1 + 128);
    v9 = clk_prepare(v8);
    if ( v9 )
    {
      v22 = v9;
    }
    else
    {
      v10 = clk_enable(v8);
      if ( !v10 )
      {
        v11 = *(_QWORD *)(v1 + 88);
        v12 = *(_QWORD *)(v1 + 8);
        if ( !v11 )
          v11 = *(_QWORD *)(v1 + 48);
        v13 = *(_QWORD *)(v1 + 80);
        if ( v13 || (v13 = *(_QWORD *)(v1 + 72)) != 0 )
        {
          v14 = *(unsigned int *)(*(_QWORD *)(v12 + 280) + 24LL);
          v15 = readl((unsigned int *)(v13 + v14));
          writel(v15 | 1, (unsigned int *)(v13 + v14));
          readl((unsigned int *)(v13 + v14));
        }
        v16 = *(unsigned int *)(*(_QWORD *)(v12 + 280) + 12LL);
        v17 = readl((unsigned int *)(v11 + v16));
        writel(v17 & 0xFFFFFFEC, (unsigned int *)(v11 + v16));
        readl((unsigned int *)(v11 + v16));
        v18 = *(unsigned int *)(*(_QWORD *)(v12 + 280) + 16LL);
        v19 = readl((unsigned int *)(v11 + v18));
        writel(v19 | 1, (unsigned int *)(v11 + v18));
        readl((unsigned int *)(v11 + v18));
        v20 = *(unsigned int *)(*(_QWORD *)(v12 + 280) + 16LL);
        v21 = readl((unsigned int *)(v11 + v20));
        writel(v21 & 0xFFFFFFFE, (unsigned int *)(v11 + v20));
        readl((unsigned int *)(v11 + v20));
        return 0;
      }
      v22 = v10;
      clk_unprepare(v8);
    }
    v23 = a1;
    v7 = v22;
    dev_err(v23, "pipe_clk enable failed, err=%d\n", v22);
    v2 = *(_DWORD *)(v1 + 168);
    v3 = *(_QWORD *)(v1 + 160);
    clk_bulk_disable(v2, v3);
    goto LABEL_5;
  }
  return 0;
}
