__int64 __fastcall lpass_cdc_rx_macro_set_idle_detect_thr(__int64 result, __int64 a2, unsigned int a3, int a4)
{
  __int64 v4; // x19
  __int64 v5; // x20
  __int64 v6; // x2
  int v7; // w20
  int v8; // w22
  __int64 v9; // x21
  unsigned int *v10; // x23
  unsigned int v11; // w8
  unsigned int v12; // w9
  unsigned int v13; // w9
  __int64 v14; // x10
  _QWORD *v15; // x11
  __int64 v16; // x9
  __int64 v17; // x12
  __int64 v18; // x8
  int v19; // w9
  _QWORD *v20; // x12
  __int64 v21; // x11
  __int64 v22; // x13
  int v23; // w11
  _QWORD *v24; // x12
  __int64 v25; // x11
  __int64 v26; // x13
  int v27; // w11
  _QWORD *v28; // x11
  __int64 v29; // x10
  __int64 v30; // x12
  int v31; // w8
  unsigned int v32; // w20
  unsigned int v33; // w8
  __int64 v34; // x0
  __int64 v35; // x19
  __int64 v36; // [xsp+8h] [xbp-18h] BYREF
  __int64 v37; // [xsp+10h] [xbp-10h]
  __int64 v38; // [xsp+18h] [xbp-8h]

  v38 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v36 = 0;
  v37 = 0;
  if ( a3 > 1 || !*(_BYTE *)(a2 + 473) )
    goto LABEL_87;
  v4 = result;
  if ( a4 )
  {
    if ( a4 != 1 )
      goto LABEL_84;
    v5 = a2;
    result = snd_soc_component_read(result, (2 * a3) | 0x1184);
    a2 = v5;
    if ( (unsigned int)(result & 0xF) - 1 > 5 )
      goto LABEL_84;
    LODWORD(v36) = (result & 0xF) - 1;
    v7 = 1;
  }
  else
  {
    v8 = 2 * a3;
    v9 = a2;
    v10 = (unsigned int *)&v36;
    v11 = (snd_soc_component_read(result, 2 * a3 + 4486) & 0xF) - 5;
    if ( v11 > 5 )
    {
      v7 = 0;
    }
    else
    {
      v10 = (unsigned int *)&v36 + 1;
      v7 = 1;
      LODWORD(v36) = v11;
    }
    v12 = ((unsigned __int8)snd_soc_component_read(v4, (unsigned int)(v8 + 4486)) >> 4) - 5;
    if ( v12 <= 5 )
    {
      ++v7;
      *v10++ = v12;
    }
    v13 = ((unsigned __int8)snd_soc_component_read(v4, (unsigned int)(v8 + 4487)) >> 4) - 5;
    if ( v13 > 5 )
    {
      result = snd_soc_component_read(v4, v8 | 0x1188u);
      a2 = v9;
      if ( !v7 )
        goto LABEL_84;
    }
    else
    {
      *v10 = v13;
      ++v7;
      result = snd_soc_component_read(v4, v8 | 0x1188u);
      a2 = v9;
    }
  }
  v14 = a2 + 312;
  v15 = (_QWORD *)(a2 + 312 + 8 * ((unsigned __int64)(int)v36 >> 6));
  v16 = 1;
  v17 = 1LL << v36;
  v18 = a2 + 440;
  if ( (v15[1] & (1LL << v36)) == 0 )
  {
    if ( (v15[2] & v17) != 0 )
    {
      v16 = 2;
    }
    else if ( (v15[3] & v17) != 0 )
    {
      v16 = 3;
    }
    else if ( (v15[4] & v17) != 0 )
    {
      v16 = 4;
    }
    else if ( (v15[5] & v17) != 0 )
    {
      v16 = 5;
    }
    else if ( (v15[6] & v17) != 0 )
    {
      v16 = 6;
    }
    else
    {
      if ( (v15[7] & v17) == 0 )
      {
        v19 = 0;
        if ( v7 == 1 )
          goto LABEL_79;
        goto LABEL_29;
      }
      v16 = 7;
    }
  }
  v19 = *(unsigned __int16 *)(v18 + 2 * v16);
  if ( v7 == 1 )
  {
LABEL_79:
    if ( v19 == 16 )
    {
      v32 = 255;
      v33 = *(unsigned __int8 *)(a2 + 472);
      if ( !*(_BYTE *)(a2 + 472) )
        goto LABEL_86;
LABEL_85:
      if ( v32 >= v33 )
      {
LABEL_87:
        _ReadStatusReg(SP_EL0);
        return result;
      }
LABEL_86:
      v34 = v4;
      v35 = a2;
      result = snd_soc_component_write(v34, 6032, v32);
      *(_BYTE *)(v35 + 472) = v32;
      goto LABEL_87;
    }
    if ( v19 == 32 || v19 == 24 )
    {
      v32 = 3;
      v33 = *(unsigned __int8 *)(a2 + 472);
      if ( !*(_BYTE *)(a2 + 472) )
        goto LABEL_86;
      goto LABEL_85;
    }
LABEL_84:
    v32 = 0;
    v33 = *(unsigned __int8 *)(a2 + 472);
    if ( !*(_BYTE *)(a2 + 472) )
      goto LABEL_86;
    goto LABEL_85;
  }
LABEL_29:
  v20 = (_QWORD *)(v14 + 8 * ((unsigned __int64)SHIDWORD(v36) >> 6));
  v21 = 1;
  v22 = 1LL << SBYTE4(v36);
  if ( (v20[1] & (1LL << SBYTE4(v36))) == 0 )
  {
    if ( (v20[2] & v22) != 0 )
    {
      v21 = 2;
    }
    else if ( (v20[3] & v22) != 0 )
    {
      v21 = 3;
    }
    else if ( (v20[4] & v22) != 0 )
    {
      v21 = 4;
    }
    else if ( (v20[5] & v22) != 0 )
    {
      v21 = 5;
    }
    else if ( (v20[6] & v22) != 0 )
    {
      v21 = 6;
    }
    else
    {
      if ( (v20[7] & v22) == 0 )
        goto LABEL_44;
      v21 = 7;
    }
  }
  v23 = *(unsigned __int16 *)(v18 + 2 * v21);
  if ( v19 <= v23 )
    v19 = v23;
LABEL_44:
  if ( v7 == 2 )
    goto LABEL_79;
  v24 = (_QWORD *)(v14 + 8 * ((unsigned __int64)(int)v37 >> 6));
  v25 = 1;
  v26 = 1LL << v37;
  if ( (v24[1] & (1LL << v37)) == 0 )
  {
    if ( (v24[2] & v26) != 0 )
    {
      v25 = 2;
    }
    else if ( (v24[3] & v26) != 0 )
    {
      v25 = 3;
    }
    else if ( (v24[4] & v26) != 0 )
    {
      v25 = 4;
    }
    else if ( (v24[5] & v26) != 0 )
    {
      v25 = 5;
    }
    else if ( (v24[6] & v26) != 0 )
    {
      v25 = 6;
    }
    else
    {
      if ( (v24[7] & v26) == 0 )
        goto LABEL_62;
      v25 = 7;
    }
  }
  v27 = *(unsigned __int16 *)(v18 + 2 * v25);
  if ( v19 <= v27 )
    v19 = v27;
LABEL_62:
  if ( v7 == 3 )
    goto LABEL_79;
  v28 = (_QWORD *)(v14 + 8 * ((unsigned __int64)SHIDWORD(v37) >> 6));
  v29 = 1;
  v30 = 1LL << SBYTE4(v37);
  if ( (v28[1] & (1LL << SBYTE4(v37))) == 0 )
  {
    if ( (v28[2] & v30) != 0 )
    {
      v29 = 2;
    }
    else if ( (v28[3] & v30) != 0 )
    {
      v29 = 3;
    }
    else if ( (v28[4] & v30) != 0 )
    {
      v29 = 4;
    }
    else if ( (v28[5] & v30) != 0 )
    {
      v29 = 5;
    }
    else if ( (v28[6] & v30) != 0 )
    {
      v29 = 6;
    }
    else
    {
      if ( (v28[7] & v30) == 0 )
        goto LABEL_78;
      v29 = 7;
    }
  }
  v31 = *(unsigned __int16 *)(v18 + 2 * v29);
  if ( v19 <= v31 )
    v19 = v31;
LABEL_78:
  if ( v7 == 4 )
    goto LABEL_79;
  __break(1u);
  return lpass_cdc_rx_macro_enable_interp_clk(result, a2, v6);
}
