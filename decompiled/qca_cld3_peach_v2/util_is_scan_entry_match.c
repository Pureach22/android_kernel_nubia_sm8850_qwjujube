__int64 __fastcall util_is_scan_entry_match(__int64 a1, unsigned __int8 *a2)
{
  __int16 v2; // w8
  __int64 v3; // x20
  unsigned __int8 *v4; // x19
  size_t v6; // x2
  size_t v7; // x2
  __int64 v8; // x9
  unsigned __int8 *v9; // x8
  int v10; // w11
  unsigned __int8 *v11; // x9
  int v12; // w10
  int v13; // t1
  int v14; // w9
  int v15; // w10
  unsigned __int8 *i; // x8
  int v17; // t1

  v2 = *(_WORD *)(a1 + 70);
  if ( (v2 & 1) != (*((_WORD *)a2 + 35) & 1) )
    return 0;
  if ( (v2 & 1) == 0 )
  {
LABEL_5:
    if ( (v2 & 2) != 0 )
    {
      if ( *(_DWORD *)(a1 + 1192) == *((_DWORD *)a2 + 298) )
      {
        v6 = *(unsigned __int8 *)(a1 + 13);
        if ( (_DWORD)v6 == a2[13] && !(unsigned int)qdf_mem_cmp((const void *)(a1 + 14), a2 + 14, v6) )
          return 1;
      }
    }
    else if ( (v2 & 1) == 0 && !(unsigned int)qdf_mem_cmp((const void *)(a1 + 1), a2 + 1, 6u) )
    {
      return 1;
    }
    return 0;
  }
  v3 = a1;
  v4 = a2;
  if ( (unsigned int)qdf_mem_cmp((const void *)(a1 + 1), a2 + 1, 6u) )
  {
    v2 = *(_WORD *)(v3 + 70);
    a1 = v3;
    a2 = v4;
    goto LABEL_5;
  }
  v7 = *(unsigned __int8 *)(v3 + 13);
  v8 = v3;
  v9 = v4;
  if ( (_DWORD)v7 != v4[13] )
  {
LABEL_17:
    if ( !(_DWORD)v7 )
      return 1;
    v10 = *(unsigned __int8 *)(v8 + 14);
    if ( !*(_BYTE *)(v8 + 14) )
      return 1;
    v11 = (unsigned __int8 *)(v8 + 15);
    v12 = v7 - 1;
    while ( (v10 | 0x20) == 0x20 )
    {
      if ( !v12 )
        return 1;
      v13 = *v11++;
      v10 = v13;
      --v12;
    }
    v14 = v9[13];
    if ( !v9[13] )
      return 1;
    v15 = v9[14];
    if ( !v9[14] )
      return 1;
    for ( i = v9 + 15; ; ++i )
    {
      --v14;
      if ( (v15 | 0x20) != 0x20 )
        break;
      if ( !v14 )
        return 1;
      v17 = *i;
      v15 = v17;
    }
    return 0;
  }
  if ( (unsigned int)qdf_mem_cmp((const void *)(v3 + 14), v4 + 14, v7) )
  {
    LODWORD(v7) = *(unsigned __int8 *)(v3 + 13);
    v8 = v3;
    v9 = v4;
    goto LABEL_17;
  }
  return 1;
}
