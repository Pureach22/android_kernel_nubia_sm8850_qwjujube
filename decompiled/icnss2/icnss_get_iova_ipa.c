__int64 __fastcall icnss_get_iova_ipa(__int64 a1, _QWORD *a2, _QWORD *a3)
{
  __int64 v4; // x9

  if ( !a1 )
    return 4294967277LL;
  if ( !*(_QWORD *)(a1 + 616) )
    return 4294967274LL;
  v4 = *(_QWORD *)(a1 + 600);
  *a2 = v4;
  *a3 = *(_QWORD *)(a1 + 616);
  return 0;
}
