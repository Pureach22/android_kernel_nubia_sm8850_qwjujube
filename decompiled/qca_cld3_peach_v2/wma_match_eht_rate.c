__int64 __fastcall wma_match_eht_rate(unsigned int a1, int a2, _BYTE *a3, _BYTE *a4, int *a5, _DWORD *a6, _BYTE *a7)
{
  __int64 v11; // x26
  unsigned __int64 v12; // x27
  __int64 v13; // x20
  __int64 result; // x0
  int v15; // w8
  int v19; // [xsp+34h] [xbp-6Ch]
  int v20; // [xsp+38h] [xbp-68h]
  int v21; // [xsp+3Ch] [xbp-64h]

  *a7 = 0;
  if ( (a2 & 0x3E000) == 0 )
    return 0;
  v11 = 0;
  v20 = a2 & 0x1C000;
  v21 = a2 & 0x18000;
  v19 = a2 & 0x1E000;
  while ( 2 )
  {
    v12 = 0;
    v13 = 31 * v11;
    do
    {
      if ( (a2 & 0x20000) != 0 )
      {
        result = wma_mcs_rate_match(a1, 1, &eht_mcs_nss1[3 * v12 + 25 + v13], &eht_mcs_nss2[3 * v12 + 25 + v13], a3, a5);
        if ( (_WORD)result )
          goto LABEL_23;
      }
      if ( (a2 & 0x10000) != 0 )
      {
        result = wma_mcs_rate_match(a1, 1, &eht_mcs_nss1[3 * v12 + 19 + v13], &eht_mcs_nss2[3 * v12 + 19 + v13], a3, a5);
        if ( (_WORD)result )
          goto LABEL_23;
      }
      if ( v21 )
      {
        result = wma_mcs_rate_match(a1, 1, &eht_mcs_nss1[3 * v12 + 13 + v13], &eht_mcs_nss2[3 * v12 + 13 + v13], a3, a5);
        if ( (_WORD)result )
        {
          v15 = -65537;
LABEL_22:
          *a6 &= v15;
LABEL_23:
          if ( v12 == 1 )
            *a4 = 1;
          *a7 = v11;
          return result;
        }
      }
      if ( v20 )
      {
        result = wma_mcs_rate_match(a1, 1, &eht_mcs_nss1[3 * v12 + 7 + v13], &eht_mcs_nss2[3 * v12 + 7 + v13], a3, a5);
        if ( (_WORD)result )
        {
          v15 = -98305;
          goto LABEL_22;
        }
      }
      if ( v19 )
      {
        result = wma_mcs_rate_match(
                   a1,
                   1,
                   &eht_mcs_nss1[31 * v11 + 1 + 3 * v12],
                   &eht_mcs_nss2[31 * v11 + 1 + 3 * v12],
                   a3,
                   a5);
        if ( (_WORD)result )
        {
          v15 = 0x2000;
          goto LABEL_22;
        }
      }
      if ( (unsigned __int8)v11 > 4u )
        break;
      ++v12;
    }
    while ( v12 < ((0x202010202uLL >> (8 * (unsigned __int8)v11)) & 3) );
    ++v11;
    result = 0;
    if ( v11 != 14 )
      continue;
    return result;
  }
}
