__int64 __fastcall wlan_crypto_set_mcastcipher(__int64 a1, int a2)
{
  __int64 v2; // x9
  int v3; // w10
  unsigned int v4; // w8
  int v5; // w14
  bool v6; // cc

  v2 = 0;
  v3 = 0;
  v4 = 4;
  *(_DWORD *)(a1 + 8) = 0;
  do
  {
    v5 = 1 << v2;
    v6 = ((1 << v2) & a2) == 0 || (unsigned __int16)v2 > 0x10u;
    if ( !v6 && ((0x1E6BFu >> v2) & 1) != 0 && ((*(_DWORD *)(a1 + 16) >> dword_9DECB0[v2]) & 1) != 0 )
    {
      v4 = 0;
      v3 |= v5;
      *(_DWORD *)(a1 + 8) = v3;
    }
    ++v2;
    a2 &= ~v5;
  }
  while ( (_DWORD)v2 != 18 );
  return v4;
}
