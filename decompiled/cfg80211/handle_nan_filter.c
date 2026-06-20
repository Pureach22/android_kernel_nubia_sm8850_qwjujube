__int64 __fastcall handle_nan_filter(_WORD *a1, __int64 a2, char a3)
{
  int v3; // w20
  unsigned int v6; // w19
  int v7; // w9
  int v8; // w8
  unsigned __int16 *v9; // x10
  unsigned int v10; // w12
  __int64 v11; // x12
  unsigned __int64 v12; // x23
  __int64 v13; // x24
  unsigned __int16 *v14; // x22
  int v15; // w26
  int v16; // w27
  _WORD *v17; // x25
  unsigned int v18; // w8
  __int64 v19; // x0
  unsigned __int64 v20; // x9
  unsigned __int64 v21; // x8
  int v22; // w9
  __int64 v23; // x10
  unsigned int v24; // w8
  __int64 v25; // x8
  unsigned __int64 StatusReg; // x22
  __int64 v28; // x25

  LOBYTE(v3) = a3;
  v6 = 0;
  v7 = (unsigned __int16)(*a1 - 4);
  if ( (unsigned int)v7 >= 4 )
  {
    v8 = 0;
    v9 = a1 + 2;
    do
    {
      v10 = *v9;
      if ( v10 < 4 )
        break;
      if ( v7 < v10 )
        break;
      v8 += (unsigned __int16)(v10 - 4);
      ++v6;
      v11 = (v10 + 3) & 0x1FFFC;
      v7 -= v11;
      v9 = (unsigned __int16 *)((char *)v9 + v11);
    }
    while ( v7 > 3 );
    if ( v8 > 254 )
      return (unsigned int)-22;
    if ( (v6 & 0x80000000) != 0 )
      return v6;
  }
  v12 = 16LL * v6;
  v13 = _kmalloc_noprof(v12, 3520);
  if ( v13 )
  {
LABEL_10:
    v14 = a1 + 2;
    v15 = (unsigned __int16)(*a1 - 4);
    if ( (unsigned int)v15 >= 4 )
    {
      v16 = 0;
      v17 = a1 + 2;
      _ReadStatusReg(SP_EL0);
      do
      {
        v18 = (unsigned __int16)*v17;
        if ( v18 < 4 || v15 < v18 )
          break;
        v19 = kmemdup_noprof(v17 + 2, (unsigned __int16)(*v17 - 4), 3264);
        v20 = 16LL * v16;
        if ( v12 <= v20 )
          goto LABEL_30;
        v21 = v13 + v20;
        *(_QWORD *)(v13 + 16LL * v16) = v19;
        if ( !v19 )
        {
          v6 = (unsigned __int16)(*a1 - 4);
          if ( v6 >= 4 )
          {
            v3 = 0;
            do
            {
              v24 = *v14;
              if ( v24 < 4 || v6 < v24 )
                break;
              if ( v12 <= 16LL * v3 )
                goto LABEL_30;
              kfree(*(_QWORD *)(v13 + 16LL * v3++));
              v25 = (*v14 + 3) & 0x1FFFC;
              v6 -= v25;
              v14 = (unsigned __int16 *)((char *)v14 + v25);
            }
            while ( (int)v6 > 3 );
          }
          kfree(v13);
          return (unsigned int)-12;
        }
        if ( v12 < (v20 | 8) )
        {
LABEL_30:
          __break(1u);
          v12 = 16LL * v6;
          StatusReg = _ReadStatusReg(SP_EL0);
          v28 = *(_QWORD *)(StatusReg + 80);
          *(_QWORD *)(StatusReg + 80) = &handle_nan_filter__alloc_tag;
          v13 = _kmalloc_noprof(v12, 3520);
          *(_QWORD *)(StatusReg + 80) = v28;
          if ( v13 )
            goto LABEL_10;
          return (unsigned int)-12;
        }
        v22 = (unsigned __int16)*v17;
        ++v16;
        v23 = (v22 + 3) & 0x1FFFC;
        *(_BYTE *)(v21 + 8) = v22 - 4;
        v15 -= v23;
        v17 = (_WORD *)((char *)v17 + v23);
      }
      while ( v15 > 3 );
    }
    if ( (v3 & 1) != 0 )
    {
      *(_BYTE *)(a2 + 96) = v6;
      v6 = 0;
      *(_QWORD *)(a2 + 88) = v13;
    }
    else
    {
      *(_BYTE *)(a2 + 97) = v6;
      v6 = 0;
      *(_QWORD *)(a2 + 80) = v13;
    }
  }
  else
  {
    return (unsigned int)-12;
  }
  return v6;
}
