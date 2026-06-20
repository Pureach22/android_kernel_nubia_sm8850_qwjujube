__int64 __fastcall clk_edp_pixel_determine_rate(__int64 a1, _QWORD *a2)
{
  __int64 v4; // x8
  __int64 v5; // x1
  char v6; // w22
  unsigned int src_index; // w0
  __int64 parent_by_index; // x0
  unsigned __int64 rate; // x0
  unsigned int *v10; // x9
  unsigned int v11; // w21
  int v12; // w22
  unsigned int *v13; // x10
  __int64 v14; // x13
  unsigned __int64 v15; // x14
  unsigned __int64 v16; // x13
  unsigned int v18; // t1
  __int64 result; // x0
  int v20; // w8
  __int64 v21; // x0
  unsigned __int64 v22; // x20
  unsigned __int64 v23; // x8
  int v24; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v25; // [xsp+8h] [xbp-8h]

  v25 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 - 8);
  v5 = *(_QWORD *)(a1 - 40);
  v6 = *(_BYTE *)(a1 - 43);
  v24 = 0;
  src_index = qcom_find_src_index(a1, v5, *(unsigned __int8 *)(v4 + 8));
  parent_by_index = clk_hw_get_parent_by_index(a1, src_index);
  a2[5] = parent_by_index;
  if ( !parent_by_index )
    goto LABEL_12;
  rate = clk_hw_get_rate(parent_by_index);
  v10 = (unsigned int *)&frac_table_675m;
  a2[4] = rate;
  if ( rate == 810000000 )
    v10 = (unsigned int *)&frac_table_810m;
  v11 = *v10;
  if ( *v10 )
  {
    v12 = ~(-1 << v6);
    v13 = v10 + 2;
    while ( 1 )
    {
      v14 = a2[1] * (int)*(v13 - 1) / (int)v11;
      v15 = v14 - 100000;
      v16 = v14 + 100000;
      if ( rate >= v15 && rate <= v16 )
        break;
      v18 = *v13;
      v13 += 2;
      v11 = v18;
      if ( !v18 )
        goto LABEL_12;
    }
    v20 = *(_DWORD *)(a1 - 48);
    v21 = *(_QWORD *)(a1 + 24);
    v22 = *(v13 - 1);
    regmap_read(v21, (unsigned int)(v20 + 4), &v24);
    v23 = a2[4];
    if ( (v24 & v12) != 0 )
      v23 = 2 * (v23 % ((v24 & (unsigned int)v12) + 1)) / ((v24 & (unsigned int)v12) + 1)
          + 2 * (v23 / ((v24 & (unsigned int)v12) + 1));
    if ( (_DWORD)v22 )
      v23 = v23 % v22 * v11 / v22 + v23 / v22 * v11;
    result = 0;
    a2[1] = v23;
  }
  else
  {
LABEL_12:
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
