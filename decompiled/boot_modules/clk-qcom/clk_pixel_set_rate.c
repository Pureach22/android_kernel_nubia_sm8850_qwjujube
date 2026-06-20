__int64 __fastcall clk_pixel_set_rate(__int64 a1, __int64 a2, unsigned __int64 a3)
{
  char v6; // w24
  int num_parents; // w23
  unsigned int v8; // w8
  __int64 v9; // x9
  unsigned __int8 *v10; // x10
  unsigned __int64 v11; // x10
  __int16 v12; // w21
  __int16 v13; // w22
  unsigned __int64 v14; // x11
  unsigned __int64 v15; // x10
  __int64 result; // x0
  unsigned __int64 v17; // x10
  __int64 v18; // [xsp+8h] [xbp-28h] BYREF
  __int64 v19; // [xsp+10h] [xbp-20h] BYREF
  __int64 v20; // [xsp+18h] [xbp-18h]
  __int64 v21; // [xsp+20h] [xbp-10h]
  __int64 v22; // [xsp+28h] [xbp-8h]

  v22 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_BYTE *)(a1 - 43);
  v20 = 0;
  v21 = 0;
  v18 = 0;
  v19 = 0;
  num_parents = clk_hw_get_num_parents(a1);
  regmap_read(*(_QWORD *)(a1 + 24), (unsigned int)(*(_DWORD *)(a1 - 48) + 4), &v18);
  v8 = ((unsigned int)v18 >> 8) & 7;
  LODWORD(v18) = v8;
  if ( num_parents >= 1 )
  {
    v9 = (unsigned int)num_parents;
    v10 = (unsigned __int8 *)(*(_QWORD *)(a1 - 40) + 1LL);
    while ( v8 != *v10 )
    {
      --v9;
      v10 += 2;
      if ( !v9 )
        goto LABEL_7;
    }
    LOBYTE(v20) = *(v10 - 1);
  }
LABEL_7:
  v11 = 8 * a2 / 3uLL;
  if ( v11 - 100000 <= a3 && v11 + 100000 >= a3 )
  {
    v12 = 8;
    v13 = 3;
LABEL_20:
    regmap_read(*(_QWORD *)(a1 + 24), (unsigned int)(*(_DWORD *)(a1 - 48) + 4), (char *)&v18 + 4);
    WORD1(v20) = v13;
    WORD2(v20) = v12;
    BYTE1(v20) = BYTE4(v18) & ~(-1 << v6);
    result = clk_rcg2_configure(a1 - 48, &v19);
    goto LABEL_21;
  }
  v14 = (unsigned __int64)(9 * a2) >> 1;
  if ( v14 - 100000 <= a3 && v14 + 100000 >= a3 )
  {
    v12 = 9;
LABEL_13:
    v13 = 2;
    goto LABEL_20;
  }
  v15 = (unsigned __int64)(9 * a2) >> 2;
  if ( v15 - 100000 <= a3 && v15 + 100000 >= a3 )
  {
    v12 = 9;
    v13 = 4;
    goto LABEL_20;
  }
  if ( a2 - 100000 <= a3 && a2 + 100000 >= a3 )
  {
    v13 = 1;
    v12 = 1;
    goto LABEL_20;
  }
  result = 4294967274LL;
  v17 = (unsigned __int64)(3 * a2) >> 1;
  if ( v17 - 100000 <= a3 && v17 + 100000 >= a3 )
  {
    v12 = 3;
    goto LABEL_13;
  }
LABEL_21:
  _ReadStatusReg(SP_EL0);
  return result;
}
