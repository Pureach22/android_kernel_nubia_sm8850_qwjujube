__int64 __fastcall wcd_mbhc_adc_detect_anc_plug_type(_QWORD *a1)
{
  char v2; // w0
  __int64 v3; // x8
  __int64 v4; // x1
  int v5; // w20
  int v7; // w22
  __int64 v8; // x0
  void (__fastcall *v9)(__int64, __int64, __int64); // x8
  __int64 v10; // x1
  __int64 v11; // x8
  char v12; // w0
  __int64 v13; // x1
  int v14; // w21
  __int64 v15; // x1
  int v16; // w23
  unsigned __int64 v17; // x24
  int v18; // w0
  unsigned int v19; // w25
  unsigned int v20; // w26
  int v21; // w0
  int v22; // w0
  int v23; // w0
  int v24; // w0
  int v25; // w0
  _BOOL4 v26; // w24
  __int64 v27; // x8
  __int64 v28; // x1
  __int64 v29; // x1
  __int64 v30; // x1
  __int64 v31; // x1
  __int64 v32; // x1
  __int64 v33; // x1
  __int64 v34; // x1
  __int64 v35; // x1
  __int64 v36; // x0
  void (__fastcall *v37)(__int64, __int64, __int64); // x8
  __int64 v38; // x1
  int v39; // w0

  if ( (unsigned int)(*(_DWORD *)(a1[14] + 80LL) - 5) < 0xFFFFFFFC || !*(_QWORD *)(a1[15] + 208LL) )
    return 0;
  if ( *(_DWORD *)(a1[107] + 760LL) )
  {
    v2 = snd_soc_component_read(a1[27]);
    v3 = a1[107];
    v4 = *(unsigned int *)(v3 + 760);
    v5 = (unsigned __int8)(v2 & *(_BYTE *)(v3 + 764)) >> *(_BYTE *)(v3 + 765);
    if ( (_DWORD)v4 )
      snd_soc_component_update_bits(a1[27], v4, *(unsigned __int8 *)(v3 + 764), 0);
  }
  else
  {
    v5 = 234;
  }
  wcd_mbhc_hs_elec_irq(a1, 0, 0);
  if ( *(_DWORD *)(a1[107] + 184LL) )
    v7 = (unsigned __int8)(snd_soc_component_read(a1[27]) & *(_BYTE *)(a1[107] + 188LL)) >> *(_BYTE *)(a1[107] + 189LL);
  else
    v7 = 65514;
  v8 = a1[27];
  v9 = *(void (__fastcall **)(__int64, __int64, __int64))(a1[15] + 208LL);
  v10 = *(unsigned int *)(a1[14] + 80LL);
  if ( *((_DWORD *)v9 - 1) != -1208669315 )
    __break(0x8228u);
  v9(v8, v10, 2);
  v11 = a1[107];
  if ( *(_DWORD *)(v11 + 168) )
  {
    v12 = snd_soc_component_read(a1[27]);
    v11 = a1[107];
    v13 = *(unsigned int *)(v11 + 168);
    v14 = (unsigned __int8)(v12 & *(_BYTE *)(v11 + 172)) >> *(_BYTE *)(v11 + 173);
    if ( (_DWORD)v13 )
    {
      snd_soc_component_update_bits(a1[27], v13, *(unsigned __int8 *)(v11 + 172), 0);
      v11 = a1[107];
    }
    v15 = *(unsigned int *)(v11 + 504);
    if ( !(_DWORD)v15 )
      goto LABEL_18;
  }
  else
  {
    v14 = 234;
    v15 = *(unsigned int *)(v11 + 504);
    if ( !(_DWORD)v15 )
      goto LABEL_18;
  }
  snd_soc_component_update_bits(
    a1[27],
    v15,
    *(unsigned __int8 *)(v11 + 508),
    (unsigned int)(1 << *(_BYTE *)(v11 + 509)));
  v11 = a1[107];
LABEL_18:
  if ( *(_DWORD *)(v11 + 744) )
    v16 = (unsigned __int8)(snd_soc_component_read(a1[27]) & *(_BYTE *)(a1[107] + 748LL)) >> *(_BYTE *)(a1[107] + 749LL);
  else
    v16 = 234;
  usleep_range_state(20000, 20100, 2);
  if ( *(_DWORD *)(a1[107] + 232LL) )
    v17 = (unsigned __int8)(snd_soc_component_read(a1[27]) & *(_BYTE *)(a1[107] + 236LL)) >> *(_BYTE *)(a1[107] + 237LL);
  else
    v17 = 234;
  if ( wcd_swch_level_remove((__int64)a1) )
    goto LABEL_63;
  v18 = wcd_measure_adc_once(a1, 2);
  if ( !v18 )
    goto LABEL_31;
  if ( v17 >= 4 )
    goto LABEL_88;
  if ( v18 < dword_E7C0[v17] )
  {
    v19 = 0;
    v20 = 1;
  }
  else
  {
LABEL_31:
    v20 = 0;
    v19 = 1;
  }
  if ( !wcd_swch_level_remove((__int64)a1) )
  {
    v21 = wcd_measure_adc_once(a1, 2);
    if ( !v21 )
      goto LABEL_37;
    if ( v17 > 3 )
      goto LABEL_88;
    if ( v21 < dword_E7C0[v17] )
      ++v20;
    else
LABEL_37:
      ++v19;
    if ( !wcd_swch_level_remove((__int64)a1) )
    {
      v22 = wcd_measure_adc_once(a1, 2);
      if ( !v22 )
        goto LABEL_43;
      if ( v17 > 3 )
        goto LABEL_88;
      if ( v22 < dword_E7C0[v17] )
        ++v20;
      else
LABEL_43:
        ++v19;
      if ( !wcd_swch_level_remove((__int64)a1) )
      {
        v23 = wcd_measure_adc_once(a1, 2);
        if ( !v23 )
          goto LABEL_49;
        if ( v17 > 3 )
          goto LABEL_88;
        if ( v23 < dword_E7C0[v17] )
          ++v20;
        else
LABEL_49:
          ++v19;
        if ( !wcd_swch_level_remove((__int64)a1) )
        {
          v24 = wcd_measure_adc_once(a1, 2);
          if ( !v24 )
            goto LABEL_55;
          if ( v17 > 3 )
            goto LABEL_88;
          if ( v24 < dword_E7C0[v17] )
            ++v20;
          else
LABEL_55:
            ++v19;
          if ( !wcd_swch_level_remove((__int64)a1) )
          {
            v25 = wcd_measure_adc_once(a1, 2);
            if ( !v25 )
              goto LABEL_61;
            if ( v17 > 3 )
              goto LABEL_88;
            if ( v25 < dword_E7C0[v17] )
              ++v20;
            else
LABEL_61:
              ++v19;
            if ( wcd_swch_level_remove((__int64)a1) )
              goto LABEL_63;
            v39 = wcd_measure_adc_once(a1, 2);
            if ( !v39 )
              goto LABEL_86;
            if ( v17 <= 3 )
            {
              if ( v39 < dword_E7C0[v17] )
              {
                ++v20;
LABEL_87:
                v26 = v20 > v19;
                goto LABEL_64;
              }
LABEL_86:
              ++v19;
              goto LABEL_87;
            }
LABEL_88:
            __break(0x5512u);
            return wcd_cancel_hs_detect_plug();
          }
        }
      }
    }
  }
LABEL_63:
  v26 = 0;
LABEL_64:
  v27 = a1[107];
  v28 = *(unsigned int *)(v27 + 744);
  if ( (_DWORD)v28 )
  {
    snd_soc_component_update_bits(
      a1[27],
      v28,
      *(unsigned __int8 *)(v27 + 748),
      (unsigned int)(v16 << *(_BYTE *)(v27 + 749)));
    v27 = a1[107];
  }
  v29 = *(unsigned int *)(v27 + 504);
  if ( (_DWORD)v29 )
  {
    snd_soc_component_update_bits(a1[27], v29, *(unsigned __int8 *)(v27 + 508), 0);
    v27 = a1[107];
  }
  v30 = *(unsigned int *)(v27 + 184);
  if ( (_DWORD)v30 )
  {
    snd_soc_component_update_bits(a1[27], v30, *(unsigned __int8 *)(v27 + 188), 0);
    v27 = a1[107];
  }
  v31 = *(unsigned int *)(v27 + 536);
  if ( (_DWORD)v31 )
  {
    snd_soc_component_update_bits(a1[27], v31, *(unsigned __int8 *)(v27 + 540), 0);
    v27 = a1[107];
  }
  v32 = *(unsigned int *)(v27 + 184);
  if ( (_DWORD)v32 )
  {
    snd_soc_component_update_bits(
      a1[27],
      v32,
      *(unsigned __int8 *)(v27 + 188),
      (unsigned int)(1 << *(_BYTE *)(v27 + 189)));
    v27 = a1[107];
    v33 = *(unsigned int *)(v27 + 184);
    if ( (_DWORD)v33 )
    {
      snd_soc_component_update_bits(
        a1[27],
        v33,
        *(unsigned __int8 *)(v27 + 188),
        (unsigned int)(v7 << *(_BYTE *)(v27 + 189)));
      v27 = a1[107];
    }
  }
  v34 = *(unsigned int *)(v27 + 760);
  if ( (_DWORD)v34 )
  {
    snd_soc_component_update_bits(
      a1[27],
      v34,
      *(unsigned __int8 *)(v27 + 764),
      (unsigned int)(v5 << *(_BYTE *)(v27 + 765)));
    v27 = a1[107];
  }
  v35 = *(unsigned int *)(v27 + 168);
  if ( (_DWORD)v35 )
    snd_soc_component_update_bits(
      a1[27],
      v35,
      *(unsigned __int8 *)(v27 + 172),
      (unsigned int)(v14 << *(_BYTE *)(v27 + 173)));
  v36 = a1[27];
  v37 = *(void (__fastcall **)(__int64, __int64, __int64))(a1[15] + 208LL);
  v38 = *(unsigned int *)(a1[14] + 80LL);
  if ( *((_DWORD *)v37 - 1) != -1208669315 )
    __break(0x8228u);
  v37(v36, v38, 3);
  return v26;
}
