__int64 __fastcall rpmh_rsc_get_channel(__int64 a1)
{
  int v3; // w20

  if ( *(_DWORD *)(a1 + 52) == 1 )
    return 0;
  do
    v3 = readl_relaxed(*(_QWORD *)(a1 + 24) + *(unsigned int *)(*(_QWORD *)(a1 + 1664) + 80LL));
  while ( (unsigned int)readl_relaxed(*(_QWORD *)(a1 + 24) + *(unsigned int *)(*(_QWORD *)(a1 + 1664) + 84LL)) != v3 );
  if ( (v3 & 1) != 0 )
    return 1;
  if ( (v3 & 2) != 0 )
    return 0;
  return 4294967280LL;
}
