__int64 __fastcall qcom_cc_register_rcg_dfs(__int64 a1, __int64 a2, unsigned __int64 a3)
{
  unsigned __int64 v6; // x8
  int v7; // w22
  int **v8; // x8
  int *v9; // x24
  int *v10; // x25
  int v11; // w9
  __int64 v12; // x8
  __int64 result; // x0
  int v14; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v15; // [xsp+8h] [xbp-8h]

  v15 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a3 )
  {
    v6 = 0;
    v7 = 1;
    while ( 1 )
    {
      v8 = (int **)(a2 + 16 * v6);
      v14 = 0;
      v9 = *v8;
      v10 = v8[1];
      v11 = **v8;
      *((_BYTE *)*v8 + 200) |= 4u;
      if ( (unsigned int)regmap_read(a1, (unsigned int)(v11 + 20), &v14) )
        break;
      if ( (v14 & 1) != 0 )
      {
        v12 = *((_QWORD *)v10 + 6);
        *((_QWORD *)v10 + 1) = clk_rcg2_dfs_ops;
        *((_QWORD *)v10 + 6) = v12 | 0x40;
        *((_QWORD *)v9 + 5) = 0;
      }
      v6 = v7++;
      if ( v6 >= a3 )
        goto LABEL_7;
    }
    result = 4294967274LL;
  }
  else
  {
LABEL_7:
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
