__int64 __fastcall _clk_rcg2_set_rate(unsigned __int64 a1, __int64 a2, int a3)
{
  __int64 v5; // x0
  __int64 freq; // x21
  __int64 v7; // x22
  __int64 v8; // x23
  char v9; // w24
  __int64 result; // x0
  __int64 v11; // x21
  __int64 v12; // x22
  unsigned __int64 v13; // x1
  unsigned int src_index; // w22
  __int64 v15; // x0
  unsigned int v16; // w23
  __int64 parent_by_index; // x0
  __int64 v18; // x0
  __int64 v19; // x24
  __int64 v20; // x25
  unsigned int v21; // w26
  unsigned int v22; // w0
  __int64 v23; // x0
  __int64 v24; // x1
  int v25; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v26; // [xsp+8h] [xbp-8h]

  v26 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 - 8);
  if ( a3 )
  {
    freq = qcom_find_freq(v5);
    if ( !freq )
      goto LABEL_29;
  }
  else
  {
    freq = qcom_find_freq_floor(v5);
    if ( !freq )
      goto LABEL_29;
  }
  if ( *(_BYTE *)(a1 - 16) == 1 && (*(_BYTE *)(a1 + 155) & 1) == 0 )
  {
LABEL_15:
    result = 0;
    *(_QWORD *)(a1 - 24) = a2;
    goto LABEL_30;
  }
  if ( (*(_BYTE *)(a1 + 152) & 1) == 0 )
  {
    v7 = 0;
    v8 = 0;
LABEL_9:
    v9 = 0;
    goto LABEL_10;
  }
  v13 = 1000 * ((clk_get_rate(*(_QWORD *)(a1 + 8)) + 500) / 0x3E8uLL);
  *(_QWORD *)(a1 - 24) = v13;
  if ( v13 != cxo_f )
  {
    v15 = qcom_find_freq(*(_QWORD *)(a1 - 8));
    if ( v15 )
    {
      src_index = qcom_find_src_index(a1, *(_QWORD *)(a1 - 40), *(unsigned __int8 *)(v15 + 8));
      goto LABEL_20;
    }
LABEL_29:
    result = 4294967274LL;
    goto LABEL_30;
  }
  src_index = 0;
LABEL_20:
  v16 = qcom_find_src_index(a1, *(_QWORD *)(a1 - 40), *(unsigned __int8 *)(freq + 8));
  parent_by_index = clk_hw_get_parent_by_index(a1, src_index);
  if ( !parent_by_index )
    goto LABEL_29;
  v7 = parent_by_index;
  v18 = clk_hw_get_parent_by_index(a1, v16);
  if ( !v18 )
    goto LABEL_29;
  v19 = *(_QWORD *)(v7 + 8);
  v8 = v18;
  v20 = *(_QWORD *)(v18 + 8);
  result = clk_prepare(v19);
  if ( (_DWORD)result )
    goto LABEL_30;
  v21 = clk_prepare(v20);
  if ( v21 )
  {
LABEL_28:
    clk_unprepare(v19);
    result = v21;
    goto LABEL_30;
  }
  v21 = clk_enable(v19);
  if ( v21 )
  {
LABEL_27:
    clk_unprepare(v20);
    goto LABEL_28;
  }
  v22 = clk_enable(v20);
  if ( v22 )
  {
    v21 = v22;
    clk_disable(v19);
    goto LABEL_27;
  }
  v23 = *(_QWORD *)(a1 + 24);
  v24 = *(unsigned int *)(a1 - 48);
  v25 = 0;
  regmap_read(v23, v24, &v25);
  if ( (v25 & 2) == 0 )
  {
    clk_rcg2_set_force_enable(a1);
    goto LABEL_9;
  }
  v9 = 1;
LABEL_10:
  result = clk_rcg2_configure((int *)(a1 - 48), (_QWORD *)freq);
  if ( !(_DWORD)result )
  {
    if ( (*(_BYTE *)(a1 + 152) & 1) != 0 )
    {
      if ( (v9 & 1) == 0 )
        regmap_update_bits_base(*(_QWORD *)(a1 + 24), *(unsigned int *)(a1 - 48), 2, 0, 0, 0, 0);
      v11 = *(_QWORD *)(v7 + 8);
      v12 = *(_QWORD *)(v8 + 8);
      clk_disable(v12);
      clk_disable(v11);
      clk_unprepare(v12);
      clk_unprepare(v11);
    }
    goto LABEL_15;
  }
LABEL_30:
  _ReadStatusReg(SP_EL0);
  return result;
}
