__int64 __fastcall dp_mst_connector_post_init(__int64 a1, __int64 a2)
{
  __int64 result; // x0

  result = 4294967274LL;
  if ( a1 && a2 )
  {
    if ( *(_BYTE *)(a2 + 35) == 1 )
    {
      result = 0;
      *(_QWORD *)(a1 + 2912) = 0;
    }
    else
    {
      return 0;
    }
  }
  return result;
}
