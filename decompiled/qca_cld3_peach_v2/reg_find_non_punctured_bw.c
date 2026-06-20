__int64 __fastcall reg_find_non_punctured_bw(int a1, unsigned __int16 a2)
{
  unsigned __int8 v2; // w8
  unsigned int v3; // w9
  char v4; // w10
  unsigned int v5; // w8

  if ( a2 )
  {
    v2 = 0;
    do
    {
      v3 = a2;
      v4 = a2 & 1;
      a2 >>= 1;
      v2 += v4;
    }
    while ( v3 > 1 );
    v5 = 20 * v2;
  }
  else
  {
    v5 = 0;
  }
  if ( v5 >= (unsigned __int16)a1 )
    return 0;
  else
    return a1 - v5;
}
