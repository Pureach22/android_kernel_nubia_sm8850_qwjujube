bool __fastcall wlan_is_ie_valid(__int64 a1, unsigned __int64 a2)
{
  unsigned __int64 v2; // x8
  bool v3; // cf

  if ( a2 >= 2 )
  {
    while ( 1 )
    {
      v2 = *(unsigned __int8 *)(a1 + 1);
      v3 = a2 - 2 >= v2;
      a2 = a2 - 2 - v2;
      if ( !v3 )
        break;
      a1 += v2 + 2;
      if ( a2 <= 1 )
        return a2 == 0;
    }
    a2 = 1;
  }
  return a2 == 0;
}
