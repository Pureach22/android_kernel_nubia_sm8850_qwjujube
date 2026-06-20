__int64 __fastcall wcd9378_wcd_mbhc_calc_impedance(__int64 a1, int *a2, int *a3)
{
  __int64 v6; // x19
  __int64 v7; // x25
  char v8; // w24
  _WORD *v9; // x23
  void *v10; // x21
  int v11; // w8
  unsigned int v12; // w8
  _WORD *v13; // x9
  __int64 v14; // x10
  void *v15; // x11
  __int64 v16; // x27
  int v17; // w8
  __int64 v18; // x1
  __int16 v19; // w0
  int v20; // w8
  int v21; // w9
  __int64 v22; // x0
  int v23; // w8
  int *v24; // x23
  int v25; // w8
  __int64 v26; // x1
  __int16 v27; // w0
  int v28; // w8
  int v29; // w9
  unsigned int v30; // w9
  unsigned int v31; // w8
  __int64 result; // x0
  void *v33; // x1
  __int64 v34; // x1
  __int16 v35; // w0
  int v36; // w8
  int v37; // w9
  int v38; // w8
  unsigned int v39; // w9
  signed int v40; // w10
  int v41; // w11
  unsigned int v42; // w12
  bool v43; // cc
  unsigned int v44; // w13
  unsigned int v45; // w9
  int v46; // w8
  __int16 v47; // [xsp+10h] [xbp-30h]
  __int16 v48; // [xsp+14h] [xbp-2Ch]
  int *v49; // [xsp+18h] [xbp-28h]
  __int16 v50; // [xsp+20h] [xbp-20h]
  __int16 v51; // [xsp+24h] [xbp-1Ch]
  __int16 v52; // [xsp+28h] [xbp-18h]
  int v53; // [xsp+2Ch] [xbp-14h] BYREF
  _QWORD v54[2]; // [xsp+30h] [xbp-10h] BYREF

  v54[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)(a1 + 216);
  v54[0] = 0;
  v53 = 0;
  v7 = *(_QWORD *)(*(_QWORD *)(v6 + 24) + 152LL);
  if ( (mutex_is_locked(a1 + 744) & 1) == 0 && (wcd9378_wcd_mbhc_calc_impedance___already_done & 1) == 0 )
  {
    wcd9378_wcd_mbhc_calc_impedance___already_done = 1;
    _warn_printk("%s: BCL should have acquired\n", "wcd9378_wcd_mbhc_calc_impedance");
    __break(0x800u);
  }
  v50 = snd_soc_component_read(v6, 1075314719);
  v51 = snd_soc_component_read(v6, 1075314720);
  v52 = snd_soc_component_read(v6, 1075314721);
  v48 = snd_soc_component_read(v6, 1075314774);
  v47 = snd_soc_component_read(v6, 1075314979);
  v8 = snd_soc_component_read(v6, 1075314709);
  if ( v8 < 0 )
    regmap_update_bits_base(*(_QWORD *)(v7 + 48), 1075314709, 128, 0, 0, 0, 0);
  v49 = a3;
  if ( *(_BYTE *)(a1 + 163) == 1 )
    regmap_update_bits_base(*(_QWORD *)(v7 + 48), 1075314708, 128, 0, 0, 0, 0);
  regmap_update_bits_base(*(_QWORD *)(v7 + 48), 1075314708, 1, 0, 0, 0, 0);
  regmap_update_bits_base(*(_QWORD *)(v7 + 48), 1075314914, 192, 0, 0, 0, 0);
  usleep_range_state(1000, 1010, 2);
  v9 = &unk_5F5D8;
  v10 = &unk_5F86C;
  wcd9378_mbhc_zdet_ramp(v6, &unk_5F5D8, (char *)v54 + 4, 0, &unk_5F86C);
  v11 = HIDWORD(v54[0]);
  if ( (unsigned int)(HIDWORD(v54[0]) - 400001) >= 0xFFFA627F )
  {
    v16 = 12;
  }
  else
  {
    v12 = HIDWORD(v54[0]) >> 8;
    v13 = &unk_5F5F0;
    if ( (unsigned int)(HIDWORD(v54[0]) - 400001) >= 0x200B20 )
      v14 = 36;
    else
      v14 = 24;
    if ( (unsigned int)(HIDWORD(v54[0]) - 400001) >= 0x200B20 )
    {
      v15 = &unk_5F87C;
    }
    else
    {
      v13 = &unk_5F5E4;
      v15 = &unk_5F874;
    }
    if ( v12 >= 0x7D )
      v9 = v13;
    else
      v9 = &unk_5F5CC;
    if ( v12 >= 0x7D )
      v10 = v15;
    else
      v10 = &L__const_wcd9378_wcd_mbhc_calc_impedance_d1_a;
    if ( v12 >= 0x7D )
      v16 = v14;
    else
      v16 = 0;
    wcd9378_mbhc_zdet_ramp(v6, v9, (char *)v54 + 4, 0, v10);
    v11 = HIDWORD(v54[0]);
    if ( SHIDWORD(v54[0]) > 100000000 )
    {
      v10 = &unk_5F86C;
      v9 = &unk_5F5D8;
      v17 = 268435454;
      v16 = 12;
      goto LABEL_35;
    }
  }
  if ( v11 >= 400000 )
    v18 = 1075315912;
  else
    v18 = 1075315911;
  *a2 = v11 / 1000;
  v19 = snd_soc_component_read(v6, v18);
  if ( (v19 & 0x80) != 0 )
  {
    v20 = v19 & 0x7F;
    v21 = -25;
  }
  else
  {
    v20 = v19;
    if ( v19 < -399 )
      goto LABEL_36;
    v21 = 25;
  }
  v17 = 10000 * *a2 / (v20 * v21 + 10000);
LABEL_35:
  *a2 = v17;
LABEL_36:
  v22 = wcd9378_mbhc_zdet_ramp(v6, v9, 0, v54, v10);
  v23 = v54[0];
  if ( (unsigned int)(LODWORD(v54[0]) - 400001) >= 0xFFFA627F )
  {
    v24 = v49;
  }
  else
  {
    if ( LODWORD(v54[0]) <= 0x2625A0 )
      goto LABEL_40;
    if ( (unsigned __int64)(v16 - 45) < 0xFFFFFFFFFFFFFFD1LL )
    {
      __break(1u);
      return wcd9378_get_hwdep_fw_cal(v22);
    }
    if ( v9[1] != 6 )
    {
LABEL_40:
      if ( *a2 == 268435454 )
      {
        if ( LODWORD(v54[0]) >> 8 >= 0x7D )
        {
          if ( (unsigned int)(LODWORD(v54[0]) - 400001) >= 0x200B20 )
          {
            if ( HIDWORD(v54[0]) > 0x2625A0 )
            {
              v10 = &unk_5F87C;
              v9 = &unk_5F5F0;
            }
          }
          else
          {
            v10 = &unk_5F874;
            v9 = &unk_5F5E4;
          }
        }
        else
        {
          v10 = &L__const_wcd9378_wcd_mbhc_calc_impedance_d1_a;
          v9 = &unk_5F5CC;
        }
        wcd9378_mbhc_zdet_ramp(v6, v9, 0, v54, v10);
        v23 = v54[0];
      }
    }
    v24 = v49;
    if ( v23 > 100000000 )
    {
      v25 = 268435454;
      goto LABEL_59;
    }
  }
  if ( v23 >= 400000 )
    v26 = 1075315914;
  else
    v26 = 1075315913;
  *v24 = v23 / 1000;
  v27 = snd_soc_component_read(v6, v26);
  if ( (v27 & 0x80) != 0 )
  {
    v28 = v27 & 0x7F;
    v29 = -25;
  }
  else
  {
    v28 = v27;
    if ( v27 < -399 )
      goto LABEL_60;
    v29 = 25;
  }
  v25 = 10000 * *v24 / (v28 * v29 + 10000);
LABEL_59:
  *v24 = v25;
LABEL_60:
  v30 = *a2;
  v31 = *v24;
  if ( *a2 == 268435454 )
  {
    if ( v31 == 268435454 )
      goto LABEL_69;
    goto LABEL_68;
  }
  if ( v31 != 268435454 && (v30 > 1 || v31 <= 2) && (v30 < 3 || v31 > 1) )
  {
    snd_soc_component_update_bits(v6, 1075314904, 1, 1);
    snd_soc_component_update_bits(v6, 1075314898, 64, 1);
    if ( (unsigned int)*a2 >= 0x20 )
      v33 = &unk_5F5D8;
    else
      v33 = &unk_5F5CC;
    wcd9378_mbhc_zdet_ramp(v6, v33, &v53, 0, v10);
    snd_soc_component_update_bits(v6, 1075314898, 64, 0);
    snd_soc_component_update_bits(v6, 1075314904, 1, 0);
    if ( v53 >= 400000 )
      v34 = 1075315912;
    else
      v34 = 1075315911;
    v53 /= 1000;
    v35 = snd_soc_component_read(v6, v34);
    if ( (v35 & 0x80) != 0 )
    {
      v36 = v35 & 0x7F;
      v37 = -25;
    }
    else
    {
      v36 = v35;
      if ( v35 <= -400 )
      {
        v38 = v53;
        goto LABEL_86;
      }
      v37 = 25;
    }
    v38 = 10000 * v53 / (v36 * v37 + 10000);
    v53 = v38;
LABEL_86:
    v39 = *a2;
    v40 = 9 * v39 / (v39 + 9);
    v41 = v40 - v38;
    if ( v38 > v40 )
      v41 = v38 - v40;
    v42 = v38 - v39;
    v44 = v39 - v38;
    v43 = v39 > v38;
    v45 = v38 + v39;
    if ( v43 )
      v42 = v44;
    if ( v41 * v45 <= v42 * (v38 + v40) )
      v46 = 1;
    else
      v46 = 2;
    *(_DWORD *)(a1 + 388) = v46;
    regmap_update_bits_base(*(_QWORD *)(v7 + 48), 1075314914, 192, 192, 0, 0, 0);
    goto LABEL_69;
  }
LABEL_68:
  *(_DWORD *)(a1 + 388) = 1;
LABEL_69:
  snd_soc_component_write(v6, 1075314719, (unsigned int)v50);
  snd_soc_component_write(v6, 1075314720, (unsigned int)v51);
  snd_soc_component_write(v6, 1075314721, (unsigned int)v52);
  regmap_update_bits_base(*(_QWORD *)(v7 + 48), 1075314708, 1, 1, 0, 0, 0);
  if ( *(_BYTE *)(a1 + 163) == 1 )
    regmap_update_bits_base(*(_QWORD *)(v7 + 48), 1075314708, 128, 128, 0, 0, 0);
  snd_soc_component_write(v6, 1075314979, (unsigned int)v47);
  result = snd_soc_component_write(v6, 1075314774, (unsigned int)v48);
  if ( v8 < 0 )
    result = regmap_update_bits_base(*(_QWORD *)(v7 + 48), 1075314709, 128, 128, 0, 0, 0);
  _ReadStatusReg(SP_EL0);
  return result;
}
