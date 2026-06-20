__int64 __fastcall clk_edp_pixel_set_rate(__int64 a1, __int64 a2, __int64 a3)
{
  int *v3; // x8
  __int64 *v4; // x9
  int v5; // w20
  __int64 v6; // x10
  __int64 v7; // x11
  __int64 v8; // x19
  int v9; // w21
  int *v10; // x9
  __int64 v11; // x22
  __int64 v12; // x11
  __int64 v13; // x12
  __int64 v14; // x11
  int v16; // t1
  __int64 v17; // x8
  int v18; // w9
  __int64 result; // x0
  int v20; // [xsp+Ch] [xbp-24h] BYREF
  __int64 v21; // [xsp+10h] [xbp-20h] BYREF
  __int64 v22; // [xsp+18h] [xbp-18h]
  __int64 v23; // [xsp+20h] [xbp-10h]
  __int64 v24; // [xsp+28h] [xbp-8h]

  v24 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = (int *)&frac_table_675m;
  v4 = *(__int64 **)(a1 - 8);
  if ( a3 == 810000000 )
    v3 = (int *)&frac_table_810m;
  v5 = *v3;
  v7 = *v4;
  v6 = v4[1];
  v23 = v4[2];
  v21 = v7;
  v22 = v6;
  if ( v5 )
  {
    v8 = a1 - 48;
    v9 = ~(-1 << *(_BYTE *)(a1 - 43));
    v10 = v3 + 2;
    while ( 1 )
    {
      v11 = *(v10 - 1);
      v12 = v11 * a2 / v5;
      v13 = v12 - 100000;
      v14 = v12 + 100000;
      if ( v13 <= a3 && v14 >= a3 )
        break;
      v16 = *v10;
      v10 += 2;
      v5 = v16;
      if ( !v16 )
        goto LABEL_11;
    }
    v17 = *(_QWORD *)(a1 + 24);
    v18 = *(_DWORD *)(a1 - 48);
    v20 = 0;
    regmap_read(v17, (unsigned int)(v18 + 4), &v20);
    WORD1(v22) = v5;
    WORD2(v22) = v11;
    BYTE1(v22) = v20 & v9;
    result = clk_rcg2_configure(v8, &v21);
  }
  else
  {
LABEL_11:
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
