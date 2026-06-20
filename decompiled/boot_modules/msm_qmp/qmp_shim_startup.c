__int64 __fastcall qmp_shim_startup(__int64 a1)
{
  __int64 v1; // x8
  __int64 v2; // x8

  v1 = *(_QWORD *)(a1 + 240);
  if ( !v1 )
    return 4294967274LL;
  v2 = *(_QWORD *)(v1 + 496);
  if ( !v2 )
    return 4294967274LL;
  if ( *(_QWORD *)(v2 + 136) )
    return 0;
  return 4294967285LL;
}
