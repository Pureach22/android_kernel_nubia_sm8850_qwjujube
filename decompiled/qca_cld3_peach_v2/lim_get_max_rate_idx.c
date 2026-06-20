__int64 __fastcall lim_get_max_rate_idx(unsigned __int8 *a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x9
  __int64 result; // x0
  __int64 v7; // x10
  char *v8; // x13
  unsigned int v9; // w15
  unsigned __int64 v10; // x14
  char v11; // w16
  char v12; // t1
  unsigned int v13; // w16
  unsigned int v14; // w17
  __int64 v15; // x9
  unsigned __int8 *v16; // x8
  char v17; // t1
  unsigned int v18; // w10

  v4 = *a1;
  result = a1[1] & 0x7F;
  if ( (unsigned int)v4 < 2 )
    return result;
  if ( (unsigned int)(v4 - 13) < 0xFFFFFFF5 )
  {
    __break(0x5512u);
    return lim_update_nss(result, a2, a3, a4);
  }
  if ( (_DWORD)v4 == 2 )
  {
    v7 = 1;
LABEL_15:
    v15 = v4 - v7;
    v16 = &a1[v7 + 1];
    do
    {
      v17 = *v16++;
      v18 = v17 & 0x7F;
      if ( v18 <= (unsigned __int8)result )
        result = (unsigned __int8)result;
      else
        result = v18;
      --v15;
    }
    while ( v15 );
    return result;
  }
  v8 = (char *)(a1 + 3);
  LOBYTE(v9) = result;
  v7 = (v4 - 1) | 1;
  v10 = (v4 - 1) & 0xFFFFFFFFFFFFFFFELL;
  do
  {
    v11 = *(v8 - 1);
    v12 = *v8;
    v8 += 2;
    LODWORD(result) = (unsigned __int8)result;
    v9 = (unsigned __int8)v9;
    v13 = v11 & 0x7F;
    v14 = v12 & 0x7F;
    if ( v13 > (unsigned __int8)result )
      LODWORD(result) = v13;
    if ( v14 > (unsigned __int8)v9 )
      v9 = v14;
    v10 -= 2LL;
  }
  while ( v10 );
  if ( (unsigned int)result <= v9 )
    result = v9;
  else
    result = (unsigned int)result;
  if ( v4 - 1 != ((v4 - 1) & 0xFFFFFFFFFFFFFFFELL) )
    goto LABEL_15;
  return result;
}
