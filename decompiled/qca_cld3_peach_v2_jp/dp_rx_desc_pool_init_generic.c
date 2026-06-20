__int64 __fastcall dp_rx_desc_pool_init_generic(__int64 a1, __int64 a2, int a3)
{
  __int64 *v3; // x8
  unsigned int v4; // w9
  unsigned int v5; // w11
  char v6; // w14
  int v7; // w13
  int v8; // w12

  v3 = *(__int64 **)(a2 + 48);
  if ( v3 )
  {
    v4 = *(unsigned __int16 *)(a2 + 8);
    v5 = 0;
    do
    {
      v6 = *((_BYTE *)v3 + 30);
      *((_BYTE *)v3 + 28) = a3;
      v7 = v5 % v4;
      v8 = (a3 << 16) | ((v5 / v4) << 8);
      ++v5;
      *((_DWORD *)v3 + 6) = v8 | v7;
      *((_BYTE *)v3 + 30) = v6 & 0xFE;
      v3 = (__int64 *)*v3;
    }
    while ( v3 );
  }
  return 0;
}
