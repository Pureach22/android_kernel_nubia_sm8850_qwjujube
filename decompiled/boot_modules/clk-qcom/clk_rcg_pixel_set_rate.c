__int64 __fastcall clk_rcg_pixel_set_rate(__int64 a1, __int64 a2, unsigned __int64 a3)
{
  int num_parents; // w23
  __int64 result; // x0
  __int64 v8; // x9
  _BYTE *v9; // x10
  __int16 v10; // w9
  __int16 v11; // w8
  unsigned __int64 v12; // x9
  unsigned int v13; // [xsp+Ch] [xbp-24h] BYREF
  __int64 v14; // [xsp+10h] [xbp-20h] BYREF
  __int64 v15; // [xsp+18h] [xbp-18h]
  __int64 v16; // [xsp+20h] [xbp-10h]
  __int64 v17; // [xsp+28h] [xbp-8h]

  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v15 = 0;
  v16 = 0;
  v14 = 0;
  v13 = 0;
  num_parents = clk_hw_get_num_parents(a1);
  result = regmap_read(*(_QWORD *)(a1 + 24), *(unsigned int *)(a1 - 48), &v13);
  if ( !(_DWORD)result )
  {
    if ( num_parents >= 1 )
    {
      v8 = (unsigned int)num_parents;
      v9 = (_BYTE *)(*(_QWORD *)(a1 - 16) + 1LL);
      while ( ((v13 >> *(_BYTE *)(a1 - 24)) & 7) != *v9 )
      {
        --v8;
        v9 += 2;
        if ( !v8 )
          goto LABEL_8;
      }
      LOBYTE(v15) = *(v9 - 1);
    }
LABEL_8:
    v10 = 1;
    BYTE1(v15) = 1;
    if ( 2 * a2 - 100000 <= a3 && 2 * a2 + 100000 >= a3 )
    {
      v11 = 2;
LABEL_17:
      WORD1(v15) = v10;
      WORD2(v15) = v11;
      _clk_rcg_set_rate(a1 - 48, &v14);
      result = 0;
      goto LABEL_18;
    }
    if ( 3 * a2 - 100000 <= a3 && 3 * a2 + 100000 >= a3 )
    {
      v11 = 3;
      v10 = 1;
      goto LABEL_17;
    }
    result = 4294967274LL;
    v12 = 16 * a2 / 3uLL;
    if ( v12 - 100000 <= a3 && v12 + 100000 >= a3 )
    {
      v11 = 16;
      v10 = 3;
      goto LABEL_17;
    }
  }
LABEL_18:
  _ReadStatusReg(SP_EL0);
  return result;
}
