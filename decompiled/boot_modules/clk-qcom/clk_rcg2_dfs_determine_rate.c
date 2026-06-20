__int64 __fastcall clk_rcg2_dfs_determine_rate(__int64 a1, _QWORD *a2)
{
  __int64 v4; // x8
  __int64 v5; // x0
  __int64 v6; // x21
  __int64 v7; // x23
  int v8; // w28
  __int64 v9; // x0
  __int64 v10; // x27
  int v11; // w8
  char v12; // w8
  unsigned int v13; // w24
  unsigned int v14; // w8
  int num_parents; // w0
  unsigned int v16; // w8
  int v17; // w24
  __int64 v18; // x20
  __int64 v19; // x22
  unsigned __int64 rate; // x0
  __int64 v21; // x26
  _BYTE *v22; // x8
  __int64 parent_by_index; // x0
  int v24; // w22
  unsigned __int64 v25; // x20
  __int64 v26; // x24
  int v27; // w9
  __int64 v28; // x0
  unsigned int v29; // w8
  unsigned __int16 v30; // w9
  __int64 v31; // x10
  __int64 result; // x0
  unsigned int v33; // w20
  _QWORD *v34; // [xsp+8h] [xbp-18h]
  unsigned int v35; // [xsp+10h] [xbp-10h] BYREF
  int v36; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v37; // [xsp+18h] [xbp-8h]

  v37 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 - 8);
  if ( v4 )
  {
LABEL_22:
    result = freq_tbl_determine_rate_0(a1, v4, a2, 1);
  }
  else
  {
    v5 = _kmalloc_cache_noprof(trace_raw_output_prep, 3520, 216);
    v6 = v5;
    if ( v5 )
    {
      v34 = a2;
      v7 = 0;
      *(_QWORD *)(a1 - 8) = v5;
      while ( 1 )
      {
        v8 = 4 * v7;
        v9 = *(_QWORD *)(a1 + 24);
        v10 = v6 + 24 * v7;
        v11 = *(_DWORD *)(a1 - 48);
        v36 = 0;
        v35 = 0;
        regmap_read(v9, (unsigned int)(4 * v7 + v11 + 28), &v35);
        v12 = *(_BYTE *)(a1 - 43);
        v13 = v35;
        *(_BYTE *)(v10 + 9) = 1;
        v14 = v13 & ~(unsigned int)(-1LL << v12);
        if ( v14 )
          *(_BYTE *)(v10 + 9) = v14;
        num_parents = clk_hw_get_num_parents(a1);
        if ( num_parents >= 1 )
        {
          v16 = num_parents;
          v17 = (v13 >> 8) & 7;
          v18 = 0;
          v19 = 0;
          rate = 0;
          v21 = v16;
          while ( 1 )
          {
            v22 = (_BYTE *)(*(_QWORD *)(a1 - 40) + v18);
            if ( v17 == (unsigned __int8)v22[1] )
            {
              *(_BYTE *)(v10 + 8) = *v22;
              parent_by_index = clk_hw_get_parent_by_index(a1, (unsigned int)v19);
              if ( !parent_by_index )
              {
                v33 = -22;
                goto LABEL_25;
              }
              rate = clk_hw_get_rate(parent_by_index);
            }
            ++v19;
            v18 += 2;
            if ( v21 == v19 )
              goto LABEL_14;
          }
        }
        rate = 0;
LABEL_14:
        v24 = v35 & 0x3000;
        if ( (v35 & 0x3000) == 0 )
          break;
        v25 = rate;
        v26 = -1LL << *(_BYTE *)(a1 - 44);
        regmap_read(*(_QWORD *)(a1 + 24), (unsigned int)(v8 + *(_DWORD *)(a1 - 48) + 92), &v36);
        v27 = *(_DWORD *)(a1 - 48);
        v28 = *(_QWORD *)(a1 + 24);
        v36 &= ~(_DWORD)v26;
        *(_WORD *)(v10 + 10) = v36;
        regmap_read(v28, (unsigned int)(v8 + v27 + 156), &v36);
        rate = v25;
        v29 = *(unsigned __int16 *)(v10 + 10);
        v30 = v29 + (~(_WORD)v36 & ~(_WORD)v26);
        *(_WORD *)(v10 + 12) = v30;
        v31 = *(unsigned __int8 *)(v10 + 9);
        if ( *(_BYTE *)(v10 + 9) )
          goto LABEL_16;
LABEL_17:
        if ( v24 )
          rate = rate % v30 * v29 / v30 + rate / v30 * v29;
        ++v7;
        *(_QWORD *)v10 = rate;
        if ( v7 == 8 )
        {
          v4 = *(_QWORD *)(a1 - 8);
          a2 = v34;
          goto LABEL_22;
        }
      }
      v29 = *(unsigned __int16 *)(v10 + 10);
      v30 = *(_WORD *)(v10 + 12);
      v31 = *(unsigned __int8 *)(v10 + 9);
      if ( !*(_BYTE *)(v10 + 9) )
        goto LABEL_17;
LABEL_16:
      rate = 2 * ((rate % (v31 + 1)) & 0x7FFF) / (unsigned int)(v31 + 1) + 2 * (rate / (v31 + 1));
      goto LABEL_17;
    }
    v33 = -12;
LABEL_25:
    clk_hw_get_name(a1);
    printk(&unk_29208);
    result = v33;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
