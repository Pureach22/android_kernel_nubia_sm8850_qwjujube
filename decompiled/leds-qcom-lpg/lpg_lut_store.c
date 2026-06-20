__int64 __fastcall lpg_lut_store(__int64 a1, __int64 a2, unsigned __int64 a3, unsigned int *a4, _DWORD *a5)
{
  __int64 v10; // x0
  __int64 v11; // x1
  unsigned int next_zero_area_off; // w0
  unsigned int v13; // w24
  unsigned __int64 v14; // x8
  int v15; // w26
  int v16; // w25
  __int64 v17; // x0
  __int64 v18; // x1
  __int64 result; // x0
  __int16 v20; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v21; // [xsp+8h] [xbp-8h]

  v21 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(_QWORD *)(a1 + 88);
  v11 = *(unsigned int *)(a1 + 84);
  v20 = 0;
  next_zero_area_off = bitmap_find_next_zero_area_off(v10, v11, 0, (unsigned int)a3, 0, 0);
  v13 = next_zero_area_off;
  if ( *(_DWORD *)(a1 + 84) <= next_zero_area_off )
  {
    result = 4294967284LL;
  }
  else
  {
    if ( a3 )
    {
      v14 = 0;
      v15 = 1;
      v16 = 2 * next_zero_area_off + 64;
      do
      {
        v17 = *(_QWORD *)(a1 + 8);
        v18 = (unsigned int)(v16 + *(_DWORD *)(a1 + 80));
        v20 = *(_DWORD *)(a2 + 8 * v14 + 4);
        regmap_bulk_write(v17, v18, &v20, 2);
        v14 = v15;
        v16 += 2;
        ++v15;
      }
      while ( v14 < a3 );
    }
    _bitmap_set(*(_QWORD *)(a1 + 88), v13, (unsigned int)a3);
    result = 0;
    *a4 = v13;
    *a5 = v13 + a3 - 1;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
