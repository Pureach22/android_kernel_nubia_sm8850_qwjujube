__int64 __fastcall rpmh_rsc_restore_noirq(__int64 a1)
{
  __int64 v1; // x19
  __int64 v2; // x20
  __int64 v3; // x21
  __int64 v4; // x23
  __int64 v5; // x8
  _QWORD *v6; // x22
  int v7; // w0
  __int64 v8; // x23
  int v9; // w0

  v1 = *(_QWORD *)(a1 + 152);
  if ( *(int *)(v1 + 20) >= 1 )
  {
    v2 = 0;
    v3 = 1664;
    do
    {
      v4 = *(_QWORD *)(v1 + 24);
      v5 = v4 + v3;
      if ( *(_BYTE *)(v4 + v3 - 1603) == 1 )
      {
        v6 = (_QWORD *)(v5 - 1632);
        if ( *(_BYTE *)(v5 - 896) == 1 )
        {
          v7 = readl_relaxed((unsigned int *)(*v6 + *(unsigned int *)(*(_QWORD *)(v4 + v3) + 16LL)));
          writel_relaxed(
            *(_DWORD *)(v4 + v3 - 1084) | v7,
            (unsigned int *)(*v6 + *(unsigned int *)(*(_QWORD *)(v4 + v3) + 16LL)));
        }
        v8 = v4 + v3;
        if ( *(_BYTE *)(v8 - 560) == 1 )
        {
          v9 = readl_relaxed((unsigned int *)(*v6 + *(unsigned int *)(*(_QWORD *)v8 + 16LL)));
          writel_relaxed(*(_DWORD *)(v8 - 748) | v9, (unsigned int *)(*v6 + *(unsigned int *)(*(_QWORD *)v8 + 16LL)));
        }
      }
      ++v2;
      v3 += 1688;
    }
    while ( v2 < *(int *)(v1 + 20) );
  }
  return 0;
}
