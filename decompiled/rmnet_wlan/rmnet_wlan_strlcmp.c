__int64 __fastcall rmnet_wlan_strlcmp(__int64 a1, unsigned __int8 *a2, __int64 a3)
{
  unsigned __int8 *v3; // x8
  int v4; // w9
  int v5; // w10
  __int64 result; // x0
  int v7; // t1

  v3 = (unsigned __int8 *)(a1 + 1);
  do
  {
    if ( !a3 )
      break;
    v4 = *(v3 - 1);
    v5 = *a2;
    result = (unsigned int)(v4 - v5);
    if ( v4 != v5 )
      return result;
    v7 = *v3++;
    ++a2;
    --a3;
  }
  while ( v7 );
  return 0;
}
