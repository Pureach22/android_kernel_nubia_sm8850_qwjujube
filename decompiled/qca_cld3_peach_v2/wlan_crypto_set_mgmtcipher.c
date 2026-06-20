__int64 __fastcall wlan_crypto_set_mgmtcipher(__int64 a1, int a2)
{
  int v2; // w8
  int v3; // w9

  v2 = 0;
  v3 = 0;
  *(_DWORD *)(a1 + 12) = 0;
  do
  {
    if ( ((1 << v3) & a2) != 0 && (unsigned __int16)v3 <= 0xCu && ((1 << v3) & 0x1940) != 0 )
    {
      v2 |= 1 << v3;
      *(_DWORD *)(a1 + 12) = v2;
    }
    ++v3;
  }
  while ( v3 != 18 );
  return 0;
}
