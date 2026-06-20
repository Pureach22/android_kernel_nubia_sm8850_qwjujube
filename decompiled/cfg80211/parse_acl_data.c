__int64 __fastcall parse_acl_data(__int64 a1, __int64 a2)
{
  __int64 v2; // x9
  __int64 v3; // x10
  unsigned int v4; // w20
  _WORD *v5; // x10
  unsigned int v6; // w9
  unsigned int v7; // w21
  unsigned __int16 *v8; // x10
  unsigned int v9; // w11
  bool v10; // cc
  __int64 result; // x0
  unsigned __int64 v13; // x19
  __int64 v14; // x8
  _WORD *v15; // x10
  int v16; // w8
  int v17; // w9
  unsigned __int16 *v18; // x10
  unsigned int v19; // w13
  unsigned __int64 v20; // x13
  bool v21; // cf
  unsigned __int64 v22; // x13
  unsigned __int64 v23; // x1
  int v24; // w13
  int v25; // w15
  __int64 v26; // x13
  __int64 v27; // x13
  unsigned __int64 StatusReg; // x23
  __int64 v29; // x24

  if ( !*(_WORD *)(a1 + 98) )
    return -95;
  v2 = *(_QWORD *)(a2 + 32);
  v3 = *(_QWORD *)(v2 + 1320);
  if ( !v3 )
    return -22;
  v4 = *(_DWORD *)(v3 + 4);
  if ( v4 > 1 )
    return -22;
  v5 = *(_WORD **)(v2 + 1328);
  if ( !v5 )
    return -22;
  v6 = (unsigned __int16)(*v5 - 4);
  if ( v6 < 4 )
  {
    v7 = 0;
  }
  else
  {
    v7 = 0;
    v8 = v5 + 2;
    do
    {
      v9 = *v8;
      if ( v9 < 4 || v6 < v9 )
        break;
      if ( v9 != 10 )
        return -22;
      v10 = (int)v6 <= 15;
      v6 -= 12;
      ++v7;
      v8 += 6;
    }
    while ( !v10 );
    if ( (int)v7 > *(unsigned __int16 *)(a1 + 98) )
      return -95;
  }
  v13 = 6LL * v7 + 8;
  result = _kmalloc_noprof(v13, 3520);
  if ( !result )
    return -12;
LABEL_18:
  v14 = *(_QWORD *)(a2 + 32);
  *(_DWORD *)(result + 4) = v7;
  v15 = *(_WORD **)(v14 + 1328);
  v16 = (unsigned __int16)(*v15 - 4);
  if ( (unsigned int)v16 >= 4 )
  {
    v17 = 0;
    v18 = v15 + 2;
    do
    {
      v19 = *v18;
      if ( v19 < 4 || v16 < v19 )
        break;
      v20 = 6LL * v17 + 8;
      v21 = v13 >= v20;
      v22 = v13 - v20;
      if ( v21 )
        v23 = v22;
      else
        v23 = 0;
      if ( v23 <= 5 )
      {
        _fortify_panic(17, v23);
        StatusReg = _ReadStatusReg(SP_EL0);
        v29 = *(_QWORD *)(StatusReg + 80);
        *(_QWORD *)(StatusReg + 80) = &parse_acl_data__alloc_tag;
        v13 = 6LL * v7 + 8;
        result = _kmalloc_noprof(v13, 3520);
        *(_QWORD *)(StatusReg + 80) = v29;
        if ( result )
          goto LABEL_18;
        return -12;
      }
      v24 = v17;
      v25 = *((_DWORD *)v18 + 1);
      ++v17;
      v26 = result + 8 + 6LL * v24;
      *(_WORD *)(v26 + 4) = v18[4];
      *(_DWORD *)v26 = v25;
      v27 = (*v18 + 3) & 0x1FFFC;
      v16 -= v27;
      v18 = (unsigned __int16 *)((char *)v18 + v27);
    }
    while ( v16 > 3 );
  }
  *(_DWORD *)result = v4;
  return result;
}
