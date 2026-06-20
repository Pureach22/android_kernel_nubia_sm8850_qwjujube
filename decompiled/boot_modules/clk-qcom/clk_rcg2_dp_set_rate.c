__int64 __fastcall clk_rcg2_dp_set_rate(__int64 a1, __int64 a2, __int64 a3)
{
  char v6; // w23
  int num_parents; // w21
  int v8; // w8
  __int64 result; // x0
  char v10; // w8
  int v11; // w9
  __int64 v12; // x10
  unsigned __int8 *v13; // x11
  __int16 v14; // w8
  __int16 v15; // w9
  __int64 v16; // [xsp+8h] [xbp-38h] BYREF
  __int64 v17; // [xsp+10h] [xbp-30h] BYREF
  unsigned int v18; // [xsp+1Ch] [xbp-24h] BYREF
  __int64 v19; // [xsp+20h] [xbp-20h] BYREF
  __int64 v20; // [xsp+28h] [xbp-18h]
  __int64 v21; // [xsp+30h] [xbp-10h]
  __int64 v22; // [xsp+38h] [xbp-8h]

  v22 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_BYTE *)(a1 - 43);
  v20 = 0;
  v21 = 0;
  v19 = 0;
  v18 = 0;
  num_parents = clk_hw_get_num_parents(a1);
  v8 = -*(unsigned __int8 *)(a1 - 44);
  v16 = 0;
  v17 = 0;
  rational_best_approximation(a3, a2, 0xFFFFFFFFFFFFFFFFLL >> v8, 0xFFFFFFFFFFFFFFFFLL >> v8, &v16, &v17);
  result = 4294967274LL;
  if ( v17 && v16 )
  {
    regmap_read(*(_QWORD *)(a1 + 24), (unsigned int)(*(_DWORD *)(a1 - 48) + 4), &v18);
    v10 = v18;
    v11 = (v18 >> 8) & 7;
    v18 = v11;
    if ( num_parents >= 1 )
    {
      v12 = (unsigned int)num_parents;
      v13 = (unsigned __int8 *)(*(_QWORD *)(a1 - 40) + 1LL);
      while ( v11 != *v13 )
      {
        --v12;
        v13 += 2;
        if ( !v12 )
          goto LABEL_9;
      }
      LOBYTE(v20) = *(v13 - 1);
    }
LABEL_9:
    BYTE1(v20) = v10 & ~(-1 << v6);
    if ( v17 == v16 )
      v14 = 0;
    else
      v14 = v17;
    if ( v17 == v16 )
      v15 = 0;
    else
      v15 = v16;
    WORD1(v20) = v14;
    WORD2(v20) = v15;
    result = clk_rcg2_configure(a1 - 48, &v19);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
