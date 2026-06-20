__int64 __fastcall aw9620x_get_bin_checksum(__int64 a1, unsigned int a2, unsigned int a3)
{
  unsigned int v3; // w9
  int v4; // w8
  unsigned int i; // w10
  int v6; // w11
  int v7; // w12
  int v8; // w11

  if ( !a3 )
    return 0;
  v3 = 0;
  v4 = 0;
  for ( i = 0; i < a3; i += 4 )
  {
    if ( i < a2 )
    {
      v6 = (*(unsigned __int8 *)(a1 + v3 + 3) << 24)
         | (*(unsigned __int8 *)(a1 + v3 + 2) << 16)
         | (*(unsigned __int8 *)(a1 + v3 + 1) << 8);
      v7 = *(unsigned __int8 *)(a1 + v3);
      v3 += 4;
      v8 = v6 | v7;
    }
    else
    {
      v8 = -1;
    }
    v4 += v8;
  }
  return (unsigned int)-v4;
}
