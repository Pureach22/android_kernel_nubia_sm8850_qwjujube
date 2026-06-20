double __fastcall _reg_dmav1_setup_demura_common_en(__int64 a1, __int64 a2, _DWORD *a3)
{
  int v5; // w8
  unsigned int v6; // w8
  unsigned int v7; // w8
  unsigned int v8; // w8
  unsigned int v9; // w8
  unsigned int v10; // w8
  int v11; // w8
  int v12; // w8
  int v13; // w9
  unsigned int v14; // w10
  unsigned int v15; // w8
  __int64 v16; // x8
  __int64 v17; // x11
  unsigned int v18; // w12
  unsigned int v19; // w13
  int v20; // w12
  int v21; // w14
  unsigned int v22; // w11
  int v23; // w8
  int v24; // w13
  int v25; // w12
  int v26; // w8
  unsigned int v27; // w10
  int v28; // w10
  unsigned int v29; // w11
  unsigned int v30; // w10
  int v31; // w2
  int v32; // w3
  int v33; // w4
  int v34; // w8
  int v35; // w2

  v5 = (*(_DWORD *)(a1 + 8372) != 8) << 31;
  *a3 = v5;
  v6 = v5 & 0xF8FFFFFF | ((*(_DWORD *)(a1 + 6380) & 7) << 24);
  *a3 = v6;
  v7 = v6 & 0xFF8FFFFF | ((*(_DWORD *)(a1 + 6384) & 7) << 20);
  *a3 = v7;
  v8 = v7 & 0xFFF0FFFF | ((*(_DWORD *)(a1 + 8368) & 0xF) << 16);
  *a3 = v8;
  v9 = v8 & 0xFFFF0FFF | ((*(_DWORD *)(a1 + 8364) & 0xF) << 12);
  *a3 = v9;
  v10 = v9 & 0xFFFFF0FF | ((*(_DWORD *)(a1 + 8360) & 0xF) << 8);
  *a3 = v10;
  v11 = v10 | (32 * (*(_DWORD *)(a1 + 8268) != 0));
  *a3 = v11;
  v12 = v11 | (16 * (*(_DWORD *)(a1 + 8312) != 0));
  *a3 = v12;
  v13 = v12 | (8 * (*(_DWORD *)(a1 + 8264) != 0));
  *a3 = v13;
  if ( *(_DWORD *)(a1 + 12) )
  {
    if ( (*(_BYTE *)(a2 + 100) & 1) == 0 )
    {
      printk(&unk_21E451, a2);
      goto LABEL_28;
    }
    if ( (*(_BYTE *)a1 & 2) != 0 )
    {
      v16 = *(unsigned int *)(a1 + 8560);
      if ( (unsigned int)v16 >= 4 )
      {
        _drm_err("Invalid cfg0_param_7: %d\n", v16);
        _drm_err("Failed to parse cfg0_param_7 param\n");
        goto LABEL_28;
      }
      v14 = dword_29D1CC[v16];
      v15 = v16 + 1;
    }
    else
    {
      v14 = 1;
      v15 = 1;
    }
    if ( *(_DWORD *)(a2 + 140) )
      v17 = 92;
    else
      v17 = 40;
    v18 = *(_DWORD *)(a2 + 108);
    v19 = v18 + *(_DWORD *)(a2 + v17);
    v20 = v18 / v15;
    v21 = v19 / v15;
    v22 = (v14 + *(_DWORD *)(a2 + 96) - 1) / v14;
    v23 = v19 % v15;
    v24 = v21 - v20;
    v25 = *(_DWORD *)(a1 + 8360);
    if ( v23 )
      v26 = v24 + 1;
    else
      v26 = v24;
    v27 = v22 >> 1;
    if ( *(_DWORD *)(a1 + 8) )
      v28 = *(_DWORD *)(a1 + 8364) * v27 + (*(_DWORD *)(a1 + 8368) + v25) * (v22 >> 2);
    else
      v28 = (*(_DWORD *)(a1 + 8364) + v25 + *(_DWORD *)(a1 + 8368)) * v27;
    v29 = *(_DWORD *)(a2 + 28);
    v30 = ((unsigned int)(v28 + 31) >> 4) & 0xFFFFFFE;
    if ( v29 <= 1 )
      v29 = 1;
    v31 = v30 / v29;
    v33 = *(_DWORD *)(a2 + 112);
    v32 = *(_DWORD *)(a2 + 116);
    if ( v26 != *(_DWORD *)(a2 + 144) + v32 + *(_DWORD *)(a2 + 148) || v31 != v33 )
    {
      _drm_err("invalid hfc cfg exp h %d exp w %d act h %d act w %d\n", v26, v31, v32, v33);
      _drm_err(
        "c0_depth %d c1_depth %d c2 depth %d hw_cfg->panel_width %d\n",
        *(_DWORD *)(a1 + 8360),
        *(_DWORD *)(a1 + 8364),
        *(_DWORD *)(a1 + 8368),
        *(_DWORD *)(a2 + 96));
      goto LABEL_28;
    }
    v34 = *(_DWORD *)(a1 + 8372);
    v35 = *(_DWORD *)(a2 + 104);
    if ( v34 == 2 )
    {
      if ( v35 == 10 )
      {
LABEL_23:
        *a3 = v13 | 4;
        goto LABEL_28;
      }
    }
    else if ( v34 == 8 && v35 == 12 )
    {
      goto LABEL_23;
    }
    _drm_err("invalid HFC plane dcfg->src_id %d hw_cfg->skip_planes[SB_PLANE_REAL].plane %d\n", v34, v35);
  }
LABEL_28:
  *a3 |= 2 * (*(_DWORD *)(a1 + 6376) != 0);
  return _drm_dev_dbg(0, 0, 1, "demura common en %x\n");
}
