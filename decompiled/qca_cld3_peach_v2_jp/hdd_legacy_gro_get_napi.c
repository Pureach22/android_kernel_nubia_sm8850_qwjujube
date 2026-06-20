__int64 __fastcall hdd_legacy_gro_get_napi(__int64 a1, char a2)
{
  __int64 result; // x0
  __int64 v5; // x8

  result = hdd_napi_get_all();
  if ( result )
  {
    result = hif_get_napi((*(_DWORD *)(a1 + 72) >> 18) & 0xF, result);
    if ( result )
    {
      v5 = 2696;
      if ( (a2 & 1) != 0 )
        v5 = 5456;
      result += v5;
    }
  }
  return result;
}
