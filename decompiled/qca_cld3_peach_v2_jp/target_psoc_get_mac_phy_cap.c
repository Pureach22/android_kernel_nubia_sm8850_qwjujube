_DWORD *__fastcall target_psoc_get_mac_phy_cap(_DWORD *a1)
{
  unsigned int v1; // w9
  _DWORD *result; // x0
  __int64 v4; // x8

  v1 = a1[126];
  result = a1 + 268;
  if ( v1 <= 0xA )
  {
    if ( *result == v1 )
    {
      v4 = 0;
    }
    else if ( a1[332] == v1 )
    {
      v4 = 1;
    }
    else if ( a1[396] == v1 )
    {
      v4 = 2;
    }
    else if ( a1[460] == v1 )
    {
      v4 = 3;
    }
    else if ( a1[524] == v1 )
    {
      v4 = 4;
    }
    else if ( a1[588] == v1 )
    {
      v4 = 5;
    }
    else if ( a1[652] == v1 )
    {
      v4 = 6;
    }
    else
    {
      if ( a1[716] != v1 )
        return nullptr;
      v4 = 7;
    }
    result += 64 * v4;
  }
  return result;
}
