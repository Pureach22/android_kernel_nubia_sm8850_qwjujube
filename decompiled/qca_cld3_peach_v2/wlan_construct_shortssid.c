__int64 __fastcall wlan_construct_shortssid(char *a1, unsigned __int8 a2)
{
  unsigned int v2; // w8
  __int64 v3; // x9
  char v4; // t1

  v2 = -1;
  if ( !a1 || a2 > 0x20u )
    return v2;
  if ( a2 )
  {
    v3 = a2;
    do
    {
      v4 = *a1++;
      --v3;
      v2 = wlan_shortssid_table[(unsigned __int8)(v4 ^ v2)] ^ (v2 >> 8);
    }
    while ( v3 );
    return ~v2;
  }
  return 0;
}
