__int64 __fastcall hif_napi_serialize(__int64 a1, int a2)
{
  __int64 result; // x0
  unsigned __int64 v3; // x2

  if ( !a1 )
    return 4294967274LL;
  if ( a2 != 1 )
  {
    if ( !a2 )
    {
      result = hif_napi_event(a1, 7, 0);
      napi_serialize_reqs = 0;
      return result;
    }
    return 4294967274LL;
  }
  v3 = napi_serialize_reqs++;
  return hif_napi_event(a1, 6, v3);
}
