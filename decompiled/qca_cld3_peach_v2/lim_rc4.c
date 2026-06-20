void *__fastcall lim_rc4(_BYTE *a1, char *a2, __int64 a3, unsigned int a4, int a5)
{
  void *result; // x0
  __int64 i; // x8
  _BYTE *v12; // x9
  char v13; // w10
  unsigned __int16 v14; // w8
  unsigned __int16 v15; // w9
  __int64 j; // x10
  char v17; // w12
  int v18; // w8
  int v19; // w9
  char v20; // w12
  char v21; // t1
  int v22; // w10
  char v23; // w11
  _BYTE s[258]; // [xsp+6h] [xbp-10Ah] BYREF
  __int64 v25; // [xsp+108h] [xbp-8h]

  v25 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  result = memset(s, 0, sizeof(s));
  for ( i = 0; i != 256; i += 2 )
  {
    v12 = &s[i];
    v13 = i | 1;
    v12[2] = i;
    v12[3] = v13;
  }
  v14 = 0;
  v15 = 0;
  for ( j = 2; j != 258; ++j )
  {
    v17 = s[j];
    if ( v14 < 0x10u )
      v15 = (unsigned __int8)(v17 + v15 + *(_BYTE *)(a3 + v14));
    s[j] = s[v15 + 2];
    if ( a4 > (unsigned __int16)(v14 + 1) )
      ++v14;
    else
      v14 = 0;
    s[v15 + 2] = v17;
  }
  if ( (_WORD)a5 )
  {
    v18 = 0;
    v19 = 0;
    do
    {
      v22 = (unsigned __int8)s[(unsigned __int8)++v19 + 2];
      v18 += v22;
      v23 = s[(unsigned __int8)v18 + 2];
      s[(unsigned __int8)v19 + 2] = v23;
      s[(unsigned __int8)v18 + 2] = v22;
      if ( a2 )
      {
        v21 = *a2++;
        v20 = v21;
      }
      else
      {
        v20 = 0;
      }
      --a5;
      *a1++ = v20 ^ s[(unsigned __int8)(v23 + v22) + 2];
    }
    while ( (_WORD)a5 );
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
