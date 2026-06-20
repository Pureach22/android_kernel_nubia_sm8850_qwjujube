__int64 __fastcall ieee80211_chandef_ht_oper(__int64 result, _QWORD *a2)
{
  int v2; // w8
  __int64 v3; // x2

  if ( result )
  {
    v2 = *(_BYTE *)(result + 1) & 3;
    if ( (*(_BYTE *)(result + 1) & 3) != 0 )
    {
      if ( v2 == 3 )
      {
        v3 = 2;
      }
      else
      {
        if ( v2 != 1 )
          return 0;
        v3 = 3;
      }
    }
    else
    {
      v3 = 1;
    }
    cfg80211_chandef_create(a2, *a2, v3);
    return 1;
  }
  return result;
}
