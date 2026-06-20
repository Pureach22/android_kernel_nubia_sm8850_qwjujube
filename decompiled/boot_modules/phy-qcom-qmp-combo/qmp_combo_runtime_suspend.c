__int64 __fastcall qmp_combo_runtime_suspend(__int64 a1)
{
  __int64 v1; // x20
  __int64 v2; // x22
  __int64 v3; // x19
  __int64 v4; // x21
  int v5; // w8
  __int64 v6; // x23
  __int64 v7; // x24
  __int64 v8; // x26
  int v10; // w25
  int v11; // w0
  __int64 v12; // x26
  int v13; // w0
  __int64 v14; // x26
  int v15; // w0
  __int64 v16; // x26
  int v17; // w0
  __int64 v18; // x21
  int v19; // w0
  __int64 v20; // x19
  __int64 v21; // x20

  v1 = *(_QWORD *)(a1 + 152);
  if ( *(_DWORD *)(v1 + 256) )
  {
    v2 = *(_QWORD *)(v1 + 88);
    v3 = *(_QWORD *)(a1 + 592);
    v4 = *(_QWORD *)(v1 + 8);
    if ( !v2 )
      v2 = *(_QWORD *)(v1 + 48);
    v5 = *(_DWORD *)(v1 + 272);
    v7 = *(_QWORD *)(v1 + 72);
    v6 = *(_QWORD *)(v1 + 80);
    v8 = *(unsigned int *)(*(_QWORD *)(v4 + 280) + 16LL);
    if ( v5 == 10 || v5 == 5 )
      v10 = 3;
    else
      v10 = 17;
    v11 = readl((unsigned int *)(v2 + v8));
    writel(v11 | 1, (unsigned int *)(v2 + v8));
    readl((unsigned int *)(v2 + v8));
    v12 = *(unsigned int *)(*(_QWORD *)(v4 + 280) + 16LL);
    v13 = readl((unsigned int *)(v2 + v12));
    writel(v13 & 0xFFFFFFFE, (unsigned int *)(v2 + v12));
    readl((unsigned int *)(v2 + v12));
    v14 = *(unsigned int *)(*(_QWORD *)(v4 + 280) + 12LL);
    v15 = readl((unsigned int *)(v2 + v14));
    writel(v15 & 0xFFFFFFEC, (unsigned int *)(v2 + v14));
    readl((unsigned int *)(v2 + v14));
    v16 = *(unsigned int *)(*(_QWORD *)(v4 + 280) + 12LL);
    v17 = readl((unsigned int *)(v2 + v16));
    writel(v17 | v10, (unsigned int *)(v2 + v16));
    readl((unsigned int *)(v2 + v16));
    if ( v6 || (v6 = v7) != 0 )
    {
      v18 = *(unsigned int *)(*(_QWORD *)(v4 + 280) + 24LL);
      v19 = readl((unsigned int *)(v6 + v18));
      writel(v19 & 0xFFFFFFFE, (unsigned int *)(v6 + v18));
      readl((unsigned int *)(v6 + v18));
    }
    *(_DWORD *)(v3 + 520) |= 0xCu;
    v20 = *(_QWORD *)(v1 + 128);
    clk_disable(v20);
    clk_unprepare(v20);
    clk_set_parent(*(_QWORD *)(v1 + 136), *(_QWORD *)(v1 + 152));
    LODWORD(v20) = *(_DWORD *)(v1 + 168);
    v21 = *(_QWORD *)(v1 + 160);
    clk_bulk_disable((unsigned int)v20, v21);
    clk_bulk_unprepare((unsigned int)v20, v21);
  }
  return 0;
}
