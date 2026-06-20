__int64 __fastcall clk_rcg2_crmc_populate_freq_table(__int64 a1)
{
  __int64 v1; // x19
  __int64 v2; // x24
  unsigned __int64 v3; // x20
  __int64 i; // x26
  unsigned __int64 v5; // x8
  unsigned int v6; // w23
  __int64 v7; // x21
  __int64 v8; // x0
  int v9; // w22
  unsigned __int64 v10; // x27
  unsigned __int64 v11; // x28
  unsigned __int64 v12; // x21
  char v13; // w8
  unsigned int v14; // w22
  unsigned __int64 v15; // x25
  unsigned int v16; // w8
  unsigned __int64 v17; // x23
  int num_parents; // w0
  int v19; // w9
  unsigned __int64 v20; // x22
  __int64 v21; // x1
  unsigned __int8 *v22; // x8
  __int64 parent_by_index; // x0
  unsigned __int64 v24; // x25
  unsigned int v25; // w27
  __int64 v26; // x23
  unsigned __int64 v27; // x19
  unsigned __int64 v28; // x20
  __int64 v29; // x22
  __int64 v30; // x26
  __int64 v31; // x24
  char is_regmap_clk; // w0
  __int64 v33; // x1
  unsigned __int64 v34; // x2
  __int64 v35; // x8
  __int64 v36; // x0
  __int64 (__fastcall *v37)(__int64, __int64, unsigned __int64); // x8
  __int64 rate; // x0
  unsigned __int64 v39; // x9
  __int64 result; // x0
  unsigned __int64 StatusReg; // x21
  __int64 v42; // x22
  unsigned __int64 v43; // [xsp+0h] [xbp-20h]
  unsigned int v44; // [xsp+8h] [xbp-18h]
  unsigned int v45; // [xsp+10h] [xbp-10h] BYREF
  unsigned int v46; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v47; // [xsp+18h] [xbp-8h]

  v1 = a1;
  v47 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 168);
  v3 = 24LL * *(unsigned __int8 *)(v2 + 45) + 24;
  for ( i = _kmalloc_noprof(v3, 3520); i; *(_QWORD *)(StatusReg + 80) = v42 )
  {
    v5 = 0;
    v6 = 0;
    *(_QWORD *)(v1 + 40) = i;
    while ( 1 )
    {
      if ( v5 >= *(unsigned __int8 *)(v2 + 45) )
      {
        result = 0;
        goto LABEL_38;
      }
      v7 = *(_QWORD *)(v1 + 168);
      v46 = 0;
      v45 = 0;
      v8 = *(_QWORD *)(v7 + 8);
      if ( !v8 )
      {
        printk(&unk_28D75);
        result = 4294967277LL;
        goto LABEL_38;
      }
      v9 = *(unsigned __int8 *)(v1 + 176);
      v10 = v5 + 1;
      v11 = 24 * v5;
      regmap_read(
        v8,
        (unsigned int)(*(_DWORD *)(v7 + 36) * v9 + *(_DWORD *)(v7 + 40) * (v5 + 1) + *(_DWORD *)(v7 + 24)),
        &v46);
      regmap_read(
        *(_QWORD *)(v7 + 8),
        (unsigned int)(*(_DWORD *)(v7 + 36) * v9 + *(_DWORD *)(v7 + 40) * v10 + *(_DWORD *)(v7 + 28)),
        &v45);
      v12 = v11 + 9;
      if ( v3 < v11 + 9 )
        break;
      v13 = *(_BYTE *)(v1 + 5);
      v14 = v46;
      v15 = i + v11;
      v44 = v6;
      *(_BYTE *)(i + v11 + 9) = 1;
      v16 = v14 & ~(unsigned int)(-1LL << v13);
      if ( v16 )
      {
        if ( v3 < v12 )
          break;
        *(_BYTE *)(v15 + 9) = v16;
      }
      v17 = v45;
      num_parents = clk_hw_get_num_parents(v1 + 48);
      if ( !num_parents )
      {
LABEL_30:
        if ( !*(_QWORD *)(v1 + 64) )
          clk_hw_get_name(v1 + 48);
        printk(&unk_28ECD);
LABEL_33:
        result = 4294967274LL;
        goto LABEL_38;
      }
      v19 = (v14 >> 8) & 7;
      v20 = v17 >> 16;
      v21 = 0;
      v22 = (unsigned __int8 *)(*(_QWORD *)(v1 + 8) + 1LL);
      while ( v19 != *v22 )
      {
        ++v21;
        v22 += 2;
        if ( num_parents == v21 )
          goto LABEL_30;
      }
      if ( v3 <= v11 + 8 )
        break;
      *(_BYTE *)(v15 + 8) = *(v22 - 1);
      parent_by_index = clk_hw_get_parent_by_index(v1 + 48, v21);
      if ( !parent_by_index )
        goto LABEL_33;
      if ( (_BYTE)v17 )
      {
        v43 = i + v11;
        v24 = v10;
        v25 = (unsigned __int8)v17;
        v26 = v1;
        v27 = v3;
        v28 = v20;
        v29 = i;
        v30 = v2;
        v31 = parent_by_index;
        is_regmap_clk = clk_is_regmap_clk(parent_by_index);
        v33 = v25;
        v10 = v24;
        v15 = v43;
        v34 = v28;
        v3 = v27;
        v1 = v26;
        if ( (is_regmap_clk & 1) == 0 )
          goto LABEL_30;
        v35 = *(_QWORD *)(v31 + 88);
        v36 = v31;
        if ( !v35 )
          goto LABEL_30;
        v37 = *(__int64 (__fastcall **)(__int64, __int64, unsigned __int64))(v35 + 24);
        if ( !v37 )
          goto LABEL_30;
        v2 = v30;
        i = v29;
        if ( *((_DWORD *)v37 - 1) != -668627400 )
          __break(0x8228u);
        rate = v37(v36, v33, v34);
        if ( !rate )
          goto LABEL_30;
      }
      else
      {
        rate = clk_hw_get_rate(parent_by_index);
        if ( !rate )
          goto LABEL_30;
      }
      if ( v3 < v12 || v3 <= v11 )
        break;
      v39 = ((unsigned __int64)*(unsigned __int8 *)(v15 + 9) + 2 * rate)
          / ((unsigned __int64)*(unsigned __int8 *)(v15 + 9) + 1);
      v5 = v10;
      v6 = v39;
      *(_QWORD *)v15 = v39;
      if ( v39 <= v44 )
      {
        if ( v3 > v11 )
        {
          result = 0;
          *(_QWORD *)v15 = 0;
          goto LABEL_38;
        }
        break;
      }
    }
    __break(1u);
    StatusReg = _ReadStatusReg(SP_EL0);
    v42 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &clk_rcg2_crmc_populate_freq_table__alloc_tag;
    v3 = 24LL * *(unsigned __int8 *)(v2 + 45) + 24;
    i = _kmalloc_noprof(v3, 3520);
  }
  result = 4294967284LL;
LABEL_38:
  _ReadStatusReg(SP_EL0);
  return result;
}
