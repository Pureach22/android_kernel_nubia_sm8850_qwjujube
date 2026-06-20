__int64 __fastcall dwc3_msm_power_collapse_por(__int64 a1)
{
  __int64 v1; // x8
  unsigned int *v3; // x0
  __int64 v4; // x20
  __int64 v6; // x21
  int v7; // w0
  __int64 v8; // x21
  int v9; // w0
  int v10; // w0
  int v11; // w0
  int v12; // w0
  __int64 v13; // x19
  int v14; // w0

  v1 = *(_QWORD *)(a1 + 40);
  if ( !v1 )
    return 0;
  if ( (*(_BYTE *)(a1 + 2582) & 1) != 0 )
    return 4294967274LL;
  v3 = *(unsigned int **)(a1 + 16);
  v4 = *(_QWORD *)(v1 + 168);
  if ( v3 )
  {
    if ( (unsigned int)readl(v3) != 15 )
      return 4294967274LL;
  }
  if ( (unsigned int)readl((unsigned int *)(*(_QWORD *)(a1 + 8) + 49440LL)) < 0x10000 )
    return 4294967274LL;
  if ( *(_BYTE *)(a1 + 756) == 1 )
  {
    v6 = *(_QWORD *)(a1 + 8);
    v7 = readl((unsigned int *)(v6 + 1017948));
    writel(v7 | 4, (unsigned int *)(v6 + 1017948));
    readl((unsigned int *)(v6 + 1017948));
  }
  if ( *(_BYTE *)(a1 + 736) == 1 )
  {
    v8 = *(_QWORD *)(a1 + 8);
    v9 = readl((unsigned int *)(v8 + 49424));
    writel(v9 & 0xFEFFCFFF | 0x1000000, (unsigned int *)(v8 + 49424));
    readl((unsigned int *)(v8 + 49424));
    if ( (*(_BYTE *)(v4 + 1379) & 0x10) == 0 )
    {
      v10 = readl((unsigned int *)(*(_QWORD *)(a1 + 8) + 49664LL));
      writel(v10 | 0x100, (unsigned int *)(*(_QWORD *)(a1 + 8) + 49664LL));
      v11 = readl((unsigned int *)(*(_QWORD *)(a1 + 8) + 49436LL));
      writel(v11 | 0x100, (unsigned int *)(*(_QWORD *)(a1 + 8) + 49436LL));
    }
    if ( *(_BYTE *)(a1 + 2560) == 1 )
    {
      v12 = readl((unsigned int *)(*(_QWORD *)(a1 + 8) + 49664LL));
      writel(v12 | 0x40, (unsigned int *)(*(_QWORD *)(a1 + 8) + 49664LL));
    }
  }
  if ( *(_BYTE *)(a1 + 2562) == 1 && *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 40) + 168LL) + 1248LL) == 13105 )
  {
    v13 = *(_QWORD *)(a1 + 8);
    v14 = readl((unsigned int *)(v13 + 53284));
    writel(v14 | 0x400, (unsigned int *)(v13 + 53284));
    readl((unsigned int *)(v13 + 53284));
  }
  return 0;
}
