__int64 __fastcall icnss_set_feature_list(__int64 a1, int a2)
{
  __int64 result; // x0

  result = 4294967274LL;
  if ( a1 )
  {
    if ( a2 <= 63 )
    {
      *(_QWORD *)(a1 + 6120) |= 1 << a2;
      return 0;
    }
  }
  return result;
}
