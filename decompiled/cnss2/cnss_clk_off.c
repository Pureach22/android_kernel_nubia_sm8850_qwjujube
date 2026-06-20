__int64 __fastcall cnss_clk_off(__int64 result)
{
  __int64 v1; // x20
  __int64 v2; // x19
  unsigned __int64 v3; // x8

  v1 = *(_QWORD *)(result + 8);
  if ( v1 != result )
  {
    v2 = result;
    do
    {
      v3 = *(_QWORD *)(v1 + 16);
      if ( v3 )
      {
        if ( v3 <= 0xFFFFFFFFFFFFF000LL )
          result = cnss_clk_off_single(v1);
      }
      v1 = *(_QWORD *)(v1 + 8);
    }
    while ( v1 != v2 );
  }
  return result;
}
