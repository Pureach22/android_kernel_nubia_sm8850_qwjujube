__int64 __fastcall cfg80211_remove_links(__int64 result)
{
  unsigned int v1; // w8
  __int64 v2; // x19
  unsigned int v3; // w20
  bool v4; // w9

  if ( *(_DWORD *)(result + 8) == 3 )
  {
    v1 = *(unsigned __int16 *)(result + 1472);
    v2 = result;
    if ( *(_WORD *)(result + 1472) )
    {
      v3 = 0;
      v4 = 0;
      do
      {
        if ( v4 || (((unsigned __int64)v1 >> v3) & 1) != 0 )
        {
          result = cfg80211_remove_link(v2, v3);
          v1 = *(unsigned __int16 *)(v2 + 1472);
        }
        v4 = v1 == 0;
        if ( !v1 )
          break;
      }
      while ( v3++ < 0xE );
    }
  }
  return result;
}
