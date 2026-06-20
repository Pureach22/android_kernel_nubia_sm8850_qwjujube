__int64 __fastcall alpha_pll_fabia_prepare(__int64 a1)
{
  __int64 v2; // x8
  int v3; // w21
  int v4; // w22
  __int64 result; // x0
  unsigned __int64 rate; // x0
  unsigned __int64 *v7; // x8
  unsigned __int64 *v8; // x9
  int v9; // w23
  unsigned __int64 *v10; // x10
  unsigned __int64 v11; // x21
  unsigned __int64 v12; // x22
  __int64 parent; // x0
  unsigned __int64 v14; // x21
  __int64 v15; // x0
  unsigned __int64 v16; // x22
  unsigned __int64 v17; // x9
  char v18; // w10
  unsigned int v20; // w0
  unsigned int v21; // w19
  int v22; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v23; // [xsp+8h] [xbp-8h]

  v23 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 - 40);
  v22 = 0;
  v3 = *(unsigned __int8 *)(v2 + 4);
  v4 = *(unsigned __int8 *)(v2 + 3);
  clk_hw_get_name(a1);
  result = clk_prepare_regmap(a1);
  if ( !(_DWORD)result )
  {
    result = regmap_read(*(_QWORD *)(a1 + 24), *(unsigned int *)(a1 - 48), &v22);
    if ( !(_DWORD)result )
    {
      if ( (v22 & 4) == 0 )
      {
        rate = clk_hw_get_rate(a1);
        v7 = *(unsigned __int64 **)(a1 - 24);
        v8 = &v7[3 * *(_QWORD *)(a1 - 16)];
        if ( v7 >= v8 )
          goto LABEL_25;
        v9 = v3 - v4;
        v10 = *(unsigned __int64 **)(a1 - 24);
        while ( *v10 > rate || v10[1] < rate )
        {
          v10 += 3;
          if ( v10 >= v8 )
            goto LABEL_25;
        }
        if ( !v10 )
        {
LABEL_25:
          printk(&unk_28895);
          result = 4294967274LL;
          goto LABEL_23;
        }
        v11 = *v7;
        v12 = v7[1];
        parent = clk_hw_get_parent(a1);
        if ( !parent )
        {
          result = 4294967274LL;
          goto LABEL_23;
        }
        v14 = (54 * (v12 + v11) + 50) / 0x64;
        v15 = clk_hw_get_rate(parent);
        v16 = v14;
        v17 = v14 % (unsigned int)v15;
        if ( v17 )
        {
          v18 = 16;
          if ( v9 == 4 )
            v18 = 32;
          v16 = 1000
              * (((((unsigned __int64)(unsigned int)((v17 << v18) / (unsigned int)v15) * v15) >> v18)
                + (unsigned int)(v14 / (unsigned int)v15) * v15
                + 999)
               / 0x3E8);
        }
        if ( v16 < v14 || v14 + 500 < v16 )
        {
          clk_hw_get_name(a1);
          printk(&unk_28661);
          result = 4294967274LL;
          goto LABEL_23;
        }
        regmap_write(
          *(_QWORD *)(a1 + 24),
          *(_DWORD *)(a1 - 48) + (unsigned int)*(unsigned __int8 *)(*(_QWORD *)(a1 - 40) + 2LL),
          v14 / (unsigned int)v15);
        v20 = clk_alpha_pll_enable(a1);
        if ( v20 )
        {
          v21 = v20;
          printk(&unk_29639);
          result = v21;
          goto LABEL_23;
        }
        clk_alpha_pll_disable(a1);
      }
      result = 0;
    }
  }
LABEL_23:
  _ReadStatusReg(SP_EL0);
  return result;
}
