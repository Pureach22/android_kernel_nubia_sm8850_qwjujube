char *__fastcall ieee80211_parse_tpe(char *result, unsigned __int8 *a2, unsigned __int8 a3)
{
  __int64 v4; // x21
  int v5; // w8
  int v6; // w10
  unsigned int v7; // w11
  unsigned __int64 v8; // x9
  __int64 v9; // x8
  __int64 v10; // x23
  __int64 *v11; // x20
  char *v12; // x22
  size_t v13; // x21
  size_t v14; // x19
  char *v15; // x22
  char v17; // w8
  __int64 v18; // x8

  if ( !a3 || (char)*a2 < 0 )
    return result;
  v4 = *a2 & 7;
  v5 = (*a2 >> 3) & 7;
  if ( (unsigned int)v5 > 1 )
  {
    if ( v5 == 3 )
    {
LABEL_11:
      if ( (unsigned int)v4 > 4 )
        return result;
      v6 = 1 << (v4 - 1);
      if ( (*a2 & 7) == 0 )
        LOBYTE(v6) = 1;
      v7 = (unsigned __int8)(v6 + 1);
      if ( v7 > a3 || v7 < a3 && (unsigned __int8)(v6 + (a2[(unsigned __int8)v6 + 1] & 0xF) + 2) > (unsigned int)a3 )
        return result;
      goto LABEL_17;
    }
    if ( v5 != 2 )
      return result;
  }
  else if ( v5 )
  {
    goto LABEL_11;
  }
  if ( (unsigned int)v4 > 3 || (int)v4 + 2 > (unsigned int)a3 )
    return result;
LABEL_17:
  v8 = (unsigned __int64)*a2 >> 6;
  if ( v5 > 1 )
  {
    if ( v5 != 2 )
    {
      v9 = 66;
LABEL_22:
      v10 = (__int64)&result[19 * (unsigned int)v8 + v9];
      *(_BYTE *)v10 = 1;
      v11 = (__int64 *)(v10 + 1);
      if ( (_DWORD)v4 )
      {
        v12 = (char *)(a2 + 1);
        v13 = 1LL << ((unsigned __int8)v4 - 1);
        result = (char *)memcpy((void *)(v10 + 1), a2 + 1, v13);
        *(_BYTE *)(v10 + 17) = v13;
        *(_BYTE *)(v10 + 18) = v13;
        if ( v13 + 1 < a3 )
        {
          if ( 16 - (int)v13 >= (v12[v13] & 0xFu) )
            v14 = v12[v13] & 0xF;
          else
            v14 = (unsigned int)(16 - v13);
          result = (char *)memcpy((char *)v11 + v13, &v12[v13 + 1], v14);
          *(_BYTE *)(v10 + 17) += v14;
        }
      }
      else
      {
        v18 = 0x101010101010101LL * a2[1];
        *(_BYTE *)(v10 + 17) = 16;
        *v11 = v18;
        *(_QWORD *)(v10 + 9) = v18;
      }
      return result;
    }
    v15 = &result[8 * (unsigned int)v8 - (unsigned int)v8 + 14];
  }
  else
  {
    if ( v5 )
    {
      v9 = 28;
      goto LABEL_22;
    }
    v15 = &result[8 * v8 - v8];
  }
  *v15 = 1;
  result = (char *)memcpy(v15 + 1, a2 + 1, v4 + 1);
  v15[6] = v4 + 1;
  if ( a3 >= 6u && (_DWORD)v4 == 3 )
  {
    v17 = a2[5];
    v15[6] = 5;
    v15[5] = v17;
  }
  return result;
}
