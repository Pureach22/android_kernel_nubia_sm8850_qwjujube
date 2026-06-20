__int64 __fastcall ieee80211_iter_max_chans(__int64 result, int *a2)
{
  int v2; // w8

  v2 = *a2;
  if ( (unsigned int)*a2 <= *(_DWORD *)(result + 8) )
    v2 = *(_DWORD *)(result + 8);
  *a2 = v2;
  return result;
}
