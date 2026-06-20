__int64 __fastcall lpg_blink_set(__int64 result, unsigned __int64 *a2, unsigned __int64 *a3)
{
  unsigned __int64 v3; // x8
  __int64 v4; // x9
  __int64 v5; // x21
  int v6; // w25
  unsigned int v7; // w22
  __int64 v8; // x27
  __int64 v9; // x26
  int v10; // w20
  __int64 v11; // x23
  __int64 v12; // x0
  __int64 v13; // x9
  __int64 v14; // x11
  char *v15; // x8
  unsigned __int64 v16; // x13
  int *v17; // x10
  unsigned __int64 v18; // x14
  __int64 v19; // x12
  unsigned __int64 v20; // x9
  __int64 v21; // x11
  __int64 v22; // x10
  char v23; // w8
  int v24; // w9
  __int64 v25; // x8
  unsigned __int64 v26; // x9
  int v27; // w10
  __int16 v28; // w8
  int v29; // w8
  __int64 v30; // x8
  unsigned __int64 v31; // x9
  __int64 v32; // [xsp+8h] [xbp-18h]

  v3 = *a2;
  v4 = *(_QWORD *)result;
  v5 = result;
  if ( !*a2 )
  {
    if ( *a3 )
    {
      v3 = 0;
    }
    else
    {
      *a2 = 500;
      *a3 = 500;
      v3 = *a2;
    }
  }
  v32 = v4;
  if ( *(_DWORD *)(result + 920) )
  {
    v6 = 0;
    v7 = 0;
    v8 = 1000000 * v3;
    v9 = result + 928;
    v10 = 1000000 * (*(_DWORD *)a3 + v3);
    while ( 1 )
    {
      v11 = *(_QWORD *)(v9 + 8LL * v6);
      v12 = lpg_calc_freq(v11, v10 & 0xFFFFFFC0);
      v13 = *(unsigned int *)(v11 + 68);
      if ( *(_DWORD *)(v11 + 20) == 12 )
      {
        if ( (unsigned int)v13 >= 8 )
          goto LABEL_29;
        v14 = *(unsigned int *)(v11 + 56);
        if ( (unsigned int)v14 > 4 )
          goto LABEL_29;
        v15 = (char *)&lpg_pwm_resolution_hi_res + 4 * v13;
        v16 = 20;
        v17 = &lpg_clk_rates_hi_res[v14];
        v18 = 32;
      }
      else
      {
        if ( (unsigned int)v13 > 1 )
          goto LABEL_29;
        v14 = *(unsigned int *)(v11 + 56);
        if ( (unsigned int)v14 > 3 )
          goto LABEL_29;
        v15 = (char *)&lpg_pwm_resolution + 4 * v13;
        v16 = 16;
        v17 = &lpg_clk_rates[v14];
        v18 = 8;
      }
      v19 = *(unsigned int *)(v11 + 60);
      if ( (unsigned int)v19 > 3 )
        goto LABEL_29;
      if ( v16 <= 4 * v14 )
        break;
      v20 = 4 * v13;
      if ( v18 <= v20 || v16 <= 4 * v14 || v18 <= v20 )
        break;
      v21 = lpg_pre_divs[v19];
      v22 = (unsigned int)*v17;
      v23 = *(_DWORD *)v15;
      v24 = 1 << *(_DWORD *)(v11 + 64);
      *(_BYTE *)(v11 + 46) = 1;
      v25 = -1LL << v23;
      *(_BYTE *)(v11 + 72) = 0;
      v26 = v8 * v22 / (unsigned __int64)(1000000000 * v21 * v24);
      v27 = *(_DWORD *)(v11 + 12);
      if ( (unsigned int)v26 >= ~(_DWORD)v25 )
        v28 = ~(_WORD)v25;
      else
        v28 = v26;
      *(_WORD *)(v11 + 44) = v28;
      v7 |= v27;
      result = lpg_apply((__int64 *)v11);
      if ( (unsigned int)++v6 >= *(_DWORD *)(v5 + 920) )
        goto LABEL_25;
    }
    __break(1u);
LABEL_29:
    __break(0x5512u);
    return lpg_pattern_set(v12);
  }
  else
  {
    v7 = 0;
LABEL_25:
    v29 = *(_DWORD *)(v32 + 128);
    if ( v29 )
      result = regmap_update_bits_base(*(_QWORD *)(v32 + 8), (unsigned int)(v29 + 70), v7, v7, 0, 0, 0);
    v30 = *(_QWORD *)(v5 + 928);
    v31 = *(_QWORD *)(v30 + 48) * *(unsigned __int16 *)(v30 + 44);
    *a2 = v31 / 0x1E848000;
    *a3 = (*(_QWORD *)(v30 + 48) - (v31 >> 9)) / 0xF4240;
  }
  return result;
}
