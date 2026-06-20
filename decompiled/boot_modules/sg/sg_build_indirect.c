__int64 __fastcall sg_build_indirect(__int64 a1, __int64 a2, unsigned int a3)
{
  int v4; // w20
  unsigned __int64 v5; // x21
  __int64 v6; // x0
  __int64 result; // x0
  int v8; // w9
  signed int v9; // w23
  __int64 v10; // x8
  unsigned __int64 v11; // x8
  bool v12; // cf
  unsigned int v13; // w8
  unsigned int v14; // w20
  _BOOL4 v15; // w8
  unsigned __int64 v16; // x28
  signed int v17; // w22
  int v18; // w27
  int v19; // w8
  int v20; // w25
  _BOOL4 v21; // w9
  __int64 i; // x22
  bool v23; // cc
  unsigned int v24; // [xsp+14h] [xbp-Ch]
  _BOOL4 v25; // [xsp+1Ch] [xbp-4h]

  if ( (a3 & 0x80000000) != 0 )
    return 4294967282LL;
  if ( a3 <= 1 )
    v4 = 1;
  else
    v4 = a3;
  v5 = *(unsigned int *)(*(_QWORD *)(a2 + 16) + 80LL);
  v6 = _kmalloc_noprof(8 * (int)v5, 10528);
  *(_QWORD *)(a1 + 16) = v6;
  if ( !v6 )
    return 4294967284LL;
  result = (unsigned int)v5;
  *(_DWORD *)(a1 + 4) = 8 * v5;
  if ( (v5 & 0x80000000) == 0 )
  {
    v8 = scatter_elem_sz;
    v9 = (v4 + 511) & 0xFFFFFE00;
    v10 = scatter_elem_sz;
    if ( scatter_elem_sz != scatter_elem_sz_prev )
    {
      if ( (unsigned int)scatter_elem_sz <= 0xFFF )
      {
        v8 = 4096;
        scatter_elem_sz = 4096;
      }
      scatter_elem_sz_prev = v8;
    }
    v11 = v10 - 1;
    v12 = v11 >= 0x1000;
    v13 = 64 - __clz(v11 >> 12);
    _ReadStatusReg(SP_EL0);
    if ( v12 )
      v14 = v13;
    else
      v14 = 0;
    v15 = v9 > 0;
    v24 = v14;
    if ( !(_DWORD)v5 )
      v15 = 0;
    v25 = v15;
    while ( v15 )
    {
      v16 = 0;
      v17 = v9;
      v18 = 1 << (v14 + 12);
      v19 = scatter_elem_sz_prev;
      while ( 1 )
      {
        v20 = v17 >= v19 ? v19 : v17;
        *(_QWORD *)(*(_QWORD *)(a1 + 16) + 8 * v16) = _alloc_pages_noprof(272672, v14, 0, 0);
        if ( !*(_QWORD *)(*(_QWORD *)(a1 + 16) + 8 * v16) )
          break;
        v19 = scatter_elem_sz_prev;
        if ( v20 == scatter_elem_sz_prev && v18 > scatter_elem_sz_prev )
        {
          scatter_elem_sz_prev = 1 << (v14 + 12);
          scatter_elem_sz = 1 << (v14 + 12);
          v19 = 1 << (v14 + 12);
        }
        ++v16;
        v21 = v17 - v18 > 0;
        if ( v17 - v18 >= 1 )
        {
          v17 -= v18;
          if ( v16 < v5 )
            continue;
        }
        goto LABEL_34;
      }
      if ( v16 )
      {
        for ( i = 0; i != v16; ++i )
          _free_pages(*(_QWORD *)(*(_QWORD *)(a1 + 16) + 8 * i), v14);
      }
      v15 = v25;
      v23 = (int)v14-- <= 0;
      result = 4294967284LL;
      if ( v23 )
        return result;
    }
    v14 = v24;
    v21 = v9 > 0;
    LOWORD(v16) = 0;
LABEL_34:
    *(_DWORD *)(a1 + 24) = v14;
    if ( v21 )
      result = 4294967284LL;
    else
      result = 0;
    *(_WORD *)a1 = v16;
    *(_DWORD *)(a1 + 8) = v9;
  }
  return result;
}
