__int64 __fastcall _reset_clock_residency_stats(__int64 a1)
{
  __int64 v1; // x8
  unsigned __int64 v2; // x20

  v1 = *(_QWORD *)(a1 + 3904);
  v2 = *(_QWORD *)(v1 + 64);
  if ( v2 < v2 + 72LL * *(unsigned int *)(v1 + 72) )
  {
    do
    {
      if ( *(_BYTE *)(v2 + 20) == 1 )
      {
        reset_residency_stats(v2);
        v1 = *(_QWORD *)(a1 + 3904);
      }
      v2 += 72LL;
    }
    while ( v2 < *(_QWORD *)(v1 + 64) + 72 * (unsigned __int64)*(unsigned int *)(v1 + 72) );
  }
  return 0;
}
