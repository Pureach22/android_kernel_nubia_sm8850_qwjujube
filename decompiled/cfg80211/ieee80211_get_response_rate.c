__int64 __fastcall ieee80211_get_response_rate(__int64 a1, unsigned int a2, int a3)
{
  __int64 v3; // x9
  __int64 v4; // x8
  __int64 v5; // x10
  __int64 result; // x0

  v3 = *(unsigned int *)(a1 + 24);
  v4 = *(_QWORD *)(a1 + 8);
  if ( (int)v3 < 1 )
    return *(_QWORD *)(a1 + 8);
  v5 = 0;
  result = *(_QWORD *)(a1 + 8);
  do
  {
    if ( (((unsigned __int64)a2 >> v5) & 1) != 0 && *(unsigned __int16 *)(v4 + 4) <= a3 )
      result = v4;
    ++v5;
    v4 += 12;
  }
  while ( v3 != v5 );
  return result;
}
