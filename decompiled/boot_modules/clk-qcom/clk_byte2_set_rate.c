__int64 __fastcall clk_byte2_set_rate(__int64 a1, unsigned __int64 a2, __int64 a3)
{
  int num_parents; // w21
  __int64 v7; // x9
  unsigned __int64 v8; // x8
  int v9; // w10
  int v10; // w8
  __int64 v11; // x0
  int v12; // w8
  __int64 v13; // x9
  unsigned __int8 *v14; // x10
  __int64 result; // x0
  unsigned int v16; // [xsp+Ch] [xbp-24h] BYREF
  __int64 v17; // [xsp+10h] [xbp-20h] BYREF
  __int64 v18; // [xsp+18h] [xbp-18h]
  __int64 v19; // [xsp+20h] [xbp-10h]
  __int64 v20; // [xsp+28h] [xbp-8h]

  v20 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v18 = 0;
  v19 = 0;
  v17 = 0;
  num_parents = clk_hw_get_num_parents(a1);
  v7 = -1LL << *(_BYTE *)(a1 - 43);
  v16 = 0;
  v8 = (a2 + 2 * a3 - 1) / a2;
  v9 = *(_DWORD *)(a1 - 48);
  if ( (unsigned int)v7 <= -(int)v8 )
    v10 = -(int)v8;
  else
    LOBYTE(v10) = v7;
  v11 = *(_QWORD *)(a1 + 24);
  BYTE1(v18) = ~(_BYTE)v10;
  regmap_read(v11, (unsigned int)(v9 + 4), &v16);
  v12 = (v16 >> 8) & 7;
  v16 = v12;
  if ( num_parents < 1 )
  {
LABEL_8:
    result = 4294967274LL;
  }
  else
  {
    v13 = (unsigned int)num_parents;
    v14 = (unsigned __int8 *)(*(_QWORD *)(a1 - 40) + 1LL);
    while ( v12 != *v14 )
    {
      --v13;
      v14 += 2;
      if ( !v13 )
        goto LABEL_8;
    }
    LOBYTE(v18) = *(v14 - 1);
    result = clk_rcg2_configure(a1 - 48, &v17);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
