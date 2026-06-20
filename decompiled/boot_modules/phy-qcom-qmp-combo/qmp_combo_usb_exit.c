__int64 __fastcall qmp_combo_usb_exit(__int64 a1)
{
  __int64 v1; // x21
  _QWORD *v3; // x20
  __int64 v4; // x19
  __int64 v5; // x22
  __int64 v6; // x19
  __int64 v7; // x23
  int v8; // w0
  __int64 v9; // x19
  __int64 v10; // x23
  int v11; // w0
  __int64 v12; // x19
  __int64 v13; // x20
  int v14; // w0
  __int64 v15; // x22
  int v16; // w8
  unsigned int v17; // w19
  __int64 v18; // x20

  v1 = *(_QWORD *)(a1 + 152);
  mutex_lock(v1 + 208);
  if ( *(_DWORD *)(v1 + 276) != 4 && *(_DWORD *)(v1 + 280) )
  {
    v3 = *(_QWORD **)(a1 + 152);
    v4 = v3[16];
    v5 = v3[1];
    clk_disable(v4);
    clk_unprepare(v4);
    clk_set_parent(v3[17], v3[19]);
    v6 = v3[6];
    v7 = **(unsigned int **)(v5 + 280);
    v8 = readl((unsigned int *)(v6 + v7));
    writel(v8 | 1, (unsigned int *)(v6 + v7));
    readl((unsigned int *)(v6 + v7));
    v9 = v3[6];
    v10 = *(unsigned int *)(*(_QWORD *)(v5 + 280) + 4LL);
    v11 = readl((unsigned int *)(v9 + v10));
    writel(v11 & 0xFFFFFFFC, (unsigned int *)(v9 + v10));
    readl((unsigned int *)(v9 + v10));
    v12 = v3[6];
    v13 = *(unsigned int *)(*(_QWORD *)(v5 + 280) + 20LL);
    v14 = readl((unsigned int *)(v12 + v13));
    writel(v14 & 0xFFFFFFFE, (unsigned int *)(v12 + v13));
    readl((unsigned int *)(v12 + v13));
    v15 = *(_QWORD *)(v1 + 8);
    v16 = *(_DWORD *)(v1 + 256) - 1;
    *(_DWORD *)(v1 + 256) = v16;
    if ( !v16 )
    {
      v17 = *(_DWORD *)(v1 + 168);
      v18 = *(_QWORD *)(v1 + 160);
      clk_bulk_disable(v17, v18);
      clk_bulk_unprepare(v17, v18);
      regulator_bulk_disable(*(unsigned int *)(v15 + 272), *(_QWORD *)(v1 + 200));
    }
    --*(_DWORD *)(v1 + 280);
  }
  mutex_unlock(v1 + 208);
  return 0;
}
