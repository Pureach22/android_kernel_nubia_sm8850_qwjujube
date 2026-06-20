__int64 __fastcall wcd938x_wcd_mbhc_calc_impedance(__int64 a1, int *a2, int *a3)
{
  __int64 v6; // x19
  __int64 v7; // x24
  __int16 v8; // w22
  _WORD *v9; // x23
  void *v10; // x21
  int v11; // w8
  __int64 v12; // x10
  _WORD *v13; // x12
  void *v14; // x9
  __int64 v15; // x25
  int v16; // w8
  __int64 v17; // x1
  __int16 v18; // w0
  int v19; // w8
  int v20; // w9
  __int64 v21; // x0
  int v22; // w8
  unsigned int v23; // w9
  void *v24; // x1
  int *v25; // x23
  int v26; // w8
  __int64 v27; // x1
  __int16 v28; // w0
  int v29; // w8
  int v30; // w9
  unsigned int v31; // w9
  unsigned int v32; // w8
  __int64 result; // x0
  void *v34; // x1
  int v35; // w8
  __int64 v36; // x1
  __int16 v37; // w0
  int v38; // w8
  int v39; // w9
  int v40; // w8
  unsigned int v41; // w9
  signed int v42; // w10
  int v43; // w11
  unsigned int v44; // w12
  bool v45; // cc
  unsigned int v46; // w13
  unsigned int v47; // w9
  int v48; // w8
  char v49; // [xsp+Ch] [xbp-34h]
  __int16 v50; // [xsp+10h] [xbp-30h]
  __int16 v51; // [xsp+14h] [xbp-2Ch]
  int *v52; // [xsp+18h] [xbp-28h]
  __int16 v53; // [xsp+24h] [xbp-1Ch]
  __int16 v54; // [xsp+28h] [xbp-18h]
  int v55; // [xsp+2Ch] [xbp-14h] BYREF
  _QWORD v56[2]; // [xsp+30h] [xbp-10h] BYREF

  v56[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)(a1 + 216);
  v56[0] = 0;
  v55 = 0;
  v7 = *(_QWORD *)(*(_QWORD *)(v6 + 24) + 152LL);
  if ( (mutex_is_locked(a1 + 744) & 1) == 0 && (wcd938x_wcd_mbhc_calc_impedance___already_done & 1) == 0 )
  {
    wcd938x_wcd_mbhc_calc_impedance___already_done = 1;
    _warn_printk("%s: BCL should have acquired\n", "wcd938x_wcd_mbhc_calc_impedance");
    __break(0x800u);
  }
  v53 = snd_soc_component_read(v6, 12319);
  v54 = snd_soc_component_read(v6, 12320);
  v8 = snd_soc_component_read(v6, 12321);
  v51 = snd_soc_component_read(v6, 12374);
  v50 = snd_soc_component_read(v6, 12579);
  v49 = snd_soc_component_read(v6, 12309);
  if ( v49 < 0 )
    regmap_update_bits_base(*(_QWORD *)(v7 + 32), 12309, 128, 0, 0, 0, 0);
  v52 = a3;
  if ( *(_BYTE *)(a1 + 163) == 1 )
    regmap_update_bits_base(*(_QWORD *)(v7 + 32), 12308, 128, 0, 0, 0, 0);
  regmap_update_bits_base(*(_QWORD *)(v7 + 32), 12308, 1, 0, 0, 0, 0);
  regmap_update_bits_base(*(_QWORD *)(v7 + 32), 12514, 192, 0, 0, 0, 0);
  usleep_range_state(1000, 1010, 2);
  v9 = &unk_21B58;
  v10 = &unk_21E30;
  wcd938x_mbhc_zdet_ramp(v6, &unk_21B58, (char *)v56 + 4, 0, &unk_21E30);
  v11 = HIDWORD(v56[0]);
  if ( (unsigned int)(HIDWORD(v56[0]) - 400001) >= 0xFFFA627F )
  {
    v15 = 12;
  }
  else
  {
    v12 = 36;
    v13 = &unk_21B70;
    v14 = &unk_21E40;
    if ( (unsigned int)(HIDWORD(v56[0]) - 400001) >> 8 < 0xC35 )
    {
      v12 = 24;
      v13 = &unk_21B64;
      v14 = &unk_21E38;
    }
    if ( SHIDWORD(v56[0]) >= 32000 )
      v9 = v13;
    else
      v9 = &unk_21B4C;
    if ( SHIDWORD(v56[0]) >= 32000 )
      v10 = v14;
    else
      v10 = &L__const_wcd938x_wcd_mbhc_calc_impedance_d1_a;
    if ( SHIDWORD(v56[0]) >= 32000 )
      v15 = v12;
    else
      v15 = 0;
    wcd938x_mbhc_zdet_ramp(v6, v9, (char *)v56 + 4, 0, v10);
    v11 = HIDWORD(v56[0]);
    if ( SHIDWORD(v56[0]) > 100000000 )
    {
      v10 = &unk_21E30;
      v9 = &unk_21B58;
      v16 = 268435454;
      v15 = 12;
      goto LABEL_31;
    }
  }
  *a2 = v11 / 1000;
  if ( v11 < 400000 )
    v17 = 13511;
  else
    v17 = 13512;
  v18 = snd_soc_component_read(v6, v17);
  if ( (v18 & 0x80) != 0 )
  {
    v19 = v18 & 0x7F;
    v20 = -25;
  }
  else
  {
    v19 = v18;
    if ( v18 < -399 )
      goto LABEL_32;
    v20 = 25;
  }
  v16 = 10000 * *a2 / (v19 * v20 + 10000);
LABEL_31:
  *a2 = v16;
LABEL_32:
  v21 = wcd938x_mbhc_zdet_ramp(v6, v9, 0, v56, v10);
  v22 = v56[0];
  v23 = LODWORD(v56[0]) - 400001;
  if ( (unsigned int)(LODWORD(v56[0]) - 400001) >= 0xFFFA627F )
  {
    v25 = v52;
  }
  else
  {
    if ( SLODWORD(v56[0]) >= 1200001 )
    {
      if ( (unsigned __int64)(v15 - 45) < 0xFFFFFFFFFFFFFFD1LL )
      {
        __break(1u);
        return wcd938x_get_hwdep_fw_cal(v21);
      }
      if ( v9[1] == 6 )
        goto LABEL_40;
    }
    if ( *a2 != 268435454 )
    {
LABEL_40:
      v25 = v52;
    }
    else
    {
      if ( SLODWORD(v56[0]) >= 32000 )
      {
        if ( v23 >> 8 >= 0xC35 )
          v24 = v9;
        else
          v24 = &unk_21B64;
        if ( v23 >> 8 < 0xC35 )
          v10 = &unk_21E38;
        if ( SLODWORD(v56[0]) >= 1200001 )
        {
          v10 = &unk_21E40;
          v24 = &unk_21B70;
        }
      }
      else
      {
        v10 = &L__const_wcd938x_wcd_mbhc_calc_impedance_d1_a;
        v24 = &unk_21B4C;
      }
      v25 = v52;
      wcd938x_mbhc_zdet_ramp(v6, v24, 0, v56, v10);
      v22 = v56[0];
    }
    if ( v22 > 100000000 )
    {
      v26 = 268435454;
      goto LABEL_59;
    }
  }
  *v25 = v22 / 1000;
  if ( v22 < 400000 )
    v27 = 13513;
  else
    v27 = 13514;
  v28 = snd_soc_component_read(v6, v27);
  if ( (v28 & 0x80) != 0 )
  {
    v29 = v28 & 0x7F;
    v30 = -25;
  }
  else
  {
    v29 = v28;
    if ( v28 < -399 )
      goto LABEL_60;
    v30 = 25;
  }
  v26 = 10000 * *v25 / (v29 * v30 + 10000);
LABEL_59:
  *v25 = v26;
LABEL_60:
  v31 = *a2;
  v32 = *v25;
  if ( *a2 == 268435454 )
  {
    if ( v32 == 268435454 )
      goto LABEL_69;
    goto LABEL_68;
  }
  if ( v32 != 268435454 && (v31 > 1 || v32 <= 2) && (v31 < 3 || v32 > 1) )
  {
    snd_soc_component_update_bits(v6, 12504, 2, 2);
    snd_soc_component_update_bits(v6, 12498, 64, 1);
    if ( (unsigned int)*a2 >= 0x20 )
      v34 = &unk_21B58;
    else
      v34 = &unk_21B4C;
    wcd938x_mbhc_zdet_ramp(v6, v34, &v55, 0, v10);
    snd_soc_component_update_bits(v6, 12498, 64, 0);
    snd_soc_component_update_bits(v6, 12504, 2, 0);
    v35 = v55;
    v55 /= 1000;
    if ( v35 < 400000 )
      v36 = 13511;
    else
      v36 = 13512;
    v37 = snd_soc_component_read(v6, v36);
    if ( (v37 & 0x80) != 0 )
    {
      v38 = v37 & 0x7F;
      v39 = -25;
    }
    else
    {
      v38 = v37;
      if ( v37 <= -400 )
      {
        v40 = v55;
        goto LABEL_86;
      }
      v39 = 25;
    }
    v40 = 10000 * v55 / (v38 * v39 + 10000);
    v55 = v40;
LABEL_86:
    v41 = *a2;
    v42 = 9 * v41 / (v41 + 9);
    v43 = v42 - v40;
    if ( v40 > v42 )
      v43 = v40 - v42;
    v44 = v40 - v41;
    v46 = v41 - v40;
    v45 = v41 > v40;
    v47 = v40 + v41;
    if ( v45 )
      v44 = v46;
    if ( v43 * v47 <= v44 * (v40 + v42) )
      v48 = 1;
    else
      v48 = 2;
    *(_DWORD *)(a1 + 388) = v48;
    regmap_update_bits_base(*(_QWORD *)(v7 + 32), 12514, 192, 192, 0, 0, 0);
    goto LABEL_69;
  }
LABEL_68:
  *(_DWORD *)(a1 + 388) = 1;
LABEL_69:
  snd_soc_component_write(v6, 12319, (unsigned int)v53);
  snd_soc_component_write(v6, 12320, (unsigned int)v54);
  snd_soc_component_write(v6, 12321, (unsigned int)v8);
  regmap_update_bits_base(*(_QWORD *)(v7 + 32), 12308, 1, 1, 0, 0, 0);
  if ( *(_BYTE *)(a1 + 163) == 1 )
    regmap_update_bits_base(*(_QWORD *)(v7 + 32), 12308, 128, 128, 0, 0, 0);
  snd_soc_component_write(v6, 12579, (unsigned int)v50);
  result = snd_soc_component_write(v6, 12374, (unsigned int)v51);
  if ( v49 < 0 )
    result = regmap_update_bits_base(*(_QWORD *)(v7 + 32), 12309, 128, 128, 0, 0, 0);
  _ReadStatusReg(SP_EL0);
  return result;
}
