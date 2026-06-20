bool __fastcall cfg80211_is_element_inherited(unsigned __int8 *a1, unsigned __int8 *a2)
{
  int v2; // w8
  _BOOL8 result; // x0
  unsigned int v4; // w13
  __int64 v5; // x11
  __int64 v6; // x9
  unsigned int v7; // w10
  unsigned __int8 *v8; // x9
  __int64 v9; // x10
  int v10; // w12
  int v11; // t1
  bool v13; // w11

  v2 = *a1;
  if ( v2 == 71 || v2 == 255 && a1[1] >= 2u && a1[2] == 107 )
    return 0;
  if ( !a2 )
    return 1;
  v4 = a2[1];
  if ( v4 < 2 )
    return 1;
  v5 = a2[3];
  v6 = v5 + 3;
  if ( (int)v5 + 3 > v4 )
    return 1;
  v7 = a2[v5 + 4];
  if ( (unsigned int)v6 + v7 > v4 )
    return 1;
  if ( v2 == 255 )
  {
    if ( !a2[v5 + 4] )
      return 1;
    v2 = a1[2];
    v8 = &a2[v6 + 2];
  }
  else
  {
    if ( !a2[3] )
      return 1;
    v8 = a2 + 4;
    v7 = a2[3];
  }
  v9 = v7 - 1LL;
  do
  {
    v11 = *v8++;
    v10 = v11;
    v13 = v9-- != 0;
    result = v10 != v2;
  }
  while ( v10 != v2 && v13 );
  return result;
}
