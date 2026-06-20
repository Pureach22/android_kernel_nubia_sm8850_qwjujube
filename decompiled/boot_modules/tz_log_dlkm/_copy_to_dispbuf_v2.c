__int64 __fastcall copy_to_dispbuf_v2(__int64 a1, _DWORD *a2, unsigned int a3, unsigned int a4, __int64 a5, int a6)
{
  unsigned int v6; // w9
  unsigned int v7; // w8

  if ( !a3 )
    return 0;
  v6 = a2[1];
  v7 = 0;
  if ( v6 != *(_DWORD *)(a1 + 4) && a4 )
  {
    v7 = 0;
    do
    {
      *(_BYTE *)(a5 + a6 + v7) = *(_BYTE *)(a1 + 8 + v6);
      v6 = (a2[1] + 1) % a3;
      a2[1] = v6;
      if ( !v6 )
        ++*a2;
      ++v7;
    }
    while ( v6 != *(_DWORD *)(a1 + 4) && v7 < a4 );
  }
  return v7;
}
