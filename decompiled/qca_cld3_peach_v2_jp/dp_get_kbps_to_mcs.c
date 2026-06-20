__int64 __fastcall dp_get_kbps_to_mcs(int a1, __int64 a2, int a3, double a4, double a5, double a6, long double a7)
{
  __int64 v7; // x18
  __int128 v8; // q15
  unsigned int v9; // w11
  unsigned int v10; // w9
  unsigned int v11; // w8
  int v12; // w10
  __int16 v13; // w10
  __int64 result; // x0
  __int64 v15; // x12
  unsigned __int64 v16; // x15
  bool v17; // cc
  int v18; // w9
  unsigned __int64 j; // x11
  unsigned __int64 i; // x11

  switch ( a3 )
  {
    case 2:
      v9 = 75;
      v10 = 12;
      v11 = 8;
      break;
    case 7:
      v9 = 803;
      v10 = 412;
      v11 = 14;
      break;
    case 3:
      v9 = 411;
      v10 = 76;
      v11 = 12;
      break;
    default:
      return 0;
  }
  v12 = 1000 * a1;
  if ( (_DWORD)a2 )
  {
    if ( v12 != 48000 )
    {
      if ( v12 <= 4999 )
      {
        if ( v12 != 1000 )
        {
          if ( v12 != 2000 )
            goto LABEL_23;
          goto LABEL_20;
        }
LABEL_25:
        v13 = -3;
        return (unsigned __int16)(v13 + v10) / v11 * v11 - (unsigned __int16)(v13 + v10);
      }
      if ( v12 != 5000 )
      {
        if ( v12 != 11000 )
        {
LABEL_23:
          if ( v9 < v10 )
            return 0xFFFFFFFFLL;
          v15 = v9;
          result = 1000;
          a2 = v9;
          v16 = 36LL * v9;
          while ( v16 >> 4 <= 0x710 )
          {
            if ( *(_DWORD *)((char *)&dp_11abgnratetable + v16) )
            {
              if ( v16 > 0x7103 )
                goto LABEL_57;
              if ( 1000 * (*(_DWORD *)((char *)&dp_11abgnratetable + v16 + 12) / 0x3E8u) == v12 )
              {
                v18 = a2 - v10;
                return (unsigned int)(v18 % (int)v11);
              }
            }
            v17 = a2-- <= v10;
            v16 -= 36LL;
            if ( v17 )
            {
              if ( v9 < v10 )
                return 0xFFFFFFFFLL;
              result = 0xFFFFFFFFLL;
              for ( i = 36LL * v9; i >> 4 <= 0x710; i -= 36LL )
              {
                if ( *(_DWORD *)((char *)&dp_11abgnratetable + i) )
                {
                  if ( i >> 3 > 0xE20 )
                    goto LABEL_57;
                  if ( 1000 * (*(_DWORD *)((char *)&dp_11abgnratetable + i + 8) / 0x3E8u) == v12 )
                    goto LABEL_54;
                }
                v17 = v15-- <= v10;
                if ( v17 )
                  return result;
              }
              goto LABEL_57;
            }
          }
          goto LABEL_57;
        }
        goto LABEL_28;
      }
LABEL_29:
      v13 = -1;
      return (unsigned __int16)(v13 + v10) / v11 * v11 - (unsigned __int16)(v13 + v10);
    }
LABEL_14:
    v13 = -4;
    return (unsigned __int16)(v13 + v10) / v11 * v11 - (unsigned __int16)(v13 + v10);
  }
  if ( v12 == 48000 )
    goto LABEL_14;
  if ( v12 > 4999 )
  {
    if ( v12 == 5000 )
      goto LABEL_29;
    if ( v12 == 11000 )
    {
LABEL_28:
      v13 = 0;
      return (unsigned __int16)(v13 + v10) / v11 * v11 - (unsigned __int16)(v13 + v10);
    }
  }
  else
  {
    if ( v12 == 1000 )
      goto LABEL_25;
    if ( v12 == 2000 )
    {
LABEL_20:
      v13 = -2;
      return (unsigned __int16)(v13 + v10) / v11 * v11 - (unsigned __int16)(v13 + v10);
    }
  }
  if ( v9 < v10 )
    return 0xFFFFFFFFLL;
  v15 = v9;
  result = 0xFFFFFFFFLL;
  for ( j = 36LL * v9; j >> 4 <= 0x710; j -= 36LL )
  {
    if ( *(_DWORD *)((char *)&dp_11abgnratetable + j) )
    {
      if ( j >> 3 > 0xE20 )
        break;
      if ( 1000 * (*(_DWORD *)((char *)&dp_11abgnratetable + j + 8) / 0x3E8u) == v12 )
      {
LABEL_54:
        v18 = v15 - v10;
        return (unsigned int)(v18 % (int)v11);
      }
    }
    v17 = v15-- <= v10;
    if ( v17 )
      return result;
  }
LABEL_57:
  __break(1u);
  *(long double *)(v7 + 336) = a7;
  *(_OWORD *)(v7 + 352) = v8;
  return dp_get_context_size_be(result, a2);
}
