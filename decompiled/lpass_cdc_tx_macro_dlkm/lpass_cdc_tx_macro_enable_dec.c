__int64 __fastcall lpass_cdc_tx_macro_enable_dec(__int64 a1, __int64 a2, int a3)
{
  __int64 v5; // x8
  __int64 v6; // x19
  unsigned __int64 v7; // x25
  int v8; // w22
  __int64 updated; // x0
  __int64 v11; // x23
  __int64 v12; // x26
  int v13; // w24
  __int64 result; // x0
  char v15; // w0
  __int64 v16; // x8
  __int64 v17; // x1
  __int64 v18; // x1
  __int64 v19; // x0
  __int64 v20; // x2
  __int64 v21; // x3
  __int64 v22; // x21
  unsigned int v23; // w8
  __int64 v24; // x3
  __int64 v25; // x21
  int v26; // w20
  __int64 v27; // x1
  __int64 v28; // x0
  __int64 v29; // x3
  int v30; // w8
  int v31; // w8
  int v32; // w8
  __int64 v33; // x3
  unsigned int v34; // w0
  __int64 v35; // x21
  _BYTE *v36; // x21
  int v37; // w8
  unsigned int v38; // w0
  int v39; // w8
  __int64 v45; // [xsp+8h] [xbp-28h] BYREF
  __int64 v46; // [xsp+10h] [xbp-20h] BYREF
  __int64 v47; // [xsp+18h] [xbp-18h] BYREF
  _BYTE v48[8]; // [xsp+20h] [xbp-10h] BYREF
  __int64 v49; // [xsp+28h] [xbp-8h]

  v49 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 40);
  v45 = 0;
  v46 = 0;
  v6 = v5 - 208;
  if ( (lpass_cdc_tx_macro_get_data(v5 - 208, &v46, &v45, "lpass_cdc_tx_macro_enable_dec") & 1) == 0 )
  {
    result = 4294967274LL;
    goto LABEL_93;
  }
  v7 = *(unsigned __int8 *)(a1 + 76);
  v8 = (_DWORD)v7 << 7;
  updated = snd_soc_component_read(v6, (unsigned int)(((_DWORD)v7 << 7) + 1024));
  if ( v7 >= 8 )
    goto LABEL_95;
  v11 = v45;
  v12 = v45 + 4 * v7;
  v13 = 8 * v7;
  *(_DWORD *)(v12 + 2688) = updated & 0xF;
  if ( (lpass_cdc_tx_macro_get_data(v6, v48, &v47, "is_msm_dmic_enabled") & 1) != 0
    && (snd_soc_component_read(v6, (unsigned int)(v13 + 260)) & 3) == 0 )
  {
    v22 = *(_QWORD *)(a1 + 40) - 208LL;
    v23 = snd_soc_component_read(v22, (unsigned int)(v13 + 256));
    result = 0;
    if ( a3 > 3 )
    {
      if ( a3 == 4 )
        goto LABEL_25;
      if ( a3 != 8 )
        goto LABEL_93;
      v24 = 0;
    }
    else
    {
      if ( a3 != 1 )
        goto LABEL_7;
      v24 = 1;
    }
    lpass_cdc_dmic_clk_enable(v22, (v23 >> 4) - 1, 0, v24);
  }
  result = 0;
  if ( a3 > 3 )
  {
    if ( a3 != 4 )
    {
      if ( a3 == 8 )
      {
        snd_soc_component_update_bits(v6, (unsigned int)(v8 + 1024), 32, 0);
        snd_soc_component_update_bits(v6, (unsigned int)(v8 + 1024), 64, 64);
        snd_soc_component_update_bits(v6, (unsigned int)(v8 + 1024), 64, 0);
        snd_soc_component_update_bits(v6, (unsigned int)(v8 + 1028), 6, 0);
        snd_soc_component_update_bits(v6, (unsigned int)(v8 + 1024), 16, 0);
        snd_soc_component_update_bits(v6, (unsigned int)(v8 + 1024), 15, 4);
        if ( *(_BYTE *)(v11 + 2644) == 1 )
        {
          snd_soc_component_update_bits(v6, (unsigned int)(v8 + 1028), 1, 0);
          snd_soc_component_update_bits(v6, 1068, 64, 0);
          *(_BYTE *)(v11 + 2684) = 0;
          snd_soc_component_update_bits(v6, 12508, 15, 0);
        }
        v18 = (unsigned int)(v8 + 1072);
        v19 = v6;
        v20 = 255;
        v21 = 3;
        goto LABEL_91;
      }
LABEL_93:
      _ReadStatusReg(SP_EL0);
      return result;
    }
LABEL_25:
    v25 = v11 + 120LL * (unsigned int)v7;
    v26 = *(unsigned __int8 *)(v25 + 617);
    snd_soc_component_update_bits(v6, (unsigned int)(v8 + 1024), 16, 16);
    if ( (cancel_delayed_work_sync(v25 + 624) & 1) != 0 && v26 != 2 )
    {
      snd_soc_component_update_bits(v6, (unsigned int)(v8 + 1028), 96, (unsigned int)(32 * v26));
      v47 = 0;
      if ( (lpass_cdc_tx_macro_get_data(v6, v48, &v47, "is_amic_enabled") & 1) != 0
        && (snd_soc_component_read(v6, (unsigned int)(v13 + 260)) & 1) != 0
        && (compoundliteral_103[v47] & 1) == 0 )
      {
        v27 = (unsigned int)(v8 + 1048);
        v28 = v6;
        v29 = 2;
      }
      else
      {
        v27 = (unsigned int)(v8 + 1048);
        v28 = v6;
        v29 = 3;
      }
      snd_soc_component_update_bits(v28, v27, 3, v29);
      usleep_range_state(1000, 1010, 2);
      snd_soc_component_update_bits(v6, (unsigned int)(v8 + 1048), 3, 1);
    }
    mutex_lock(v11 + 72);
    v30 = *(_DWORD *)(v11 + 2724) - 1;
    *(_DWORD *)(v11 + 2724) = v30;
    if ( !v30 )
    {
      pm_relax(*(_QWORD *)v11);
      v30 = *(_DWORD *)(v11 + 2724);
    }
    if ( v30 < 0 )
      *(_DWORD *)(v11 + 2724) = 0;
    mutex_unlock(v11 + 72);
    if ( (snd_soc_component_read(v6, (unsigned int)(v13 + 260)) & 1) != 0 )
      snd_soc_component_update_bits(v6, 136, 1, 0);
    if ( *(_BYTE *)(v11 + 2721) != 1 )
      goto LABEL_92;
    v18 = (unsigned int)(v8 + 1032);
    v19 = v6;
    v20 = 1;
    v21 = 1;
    goto LABEL_91;
  }
  if ( a3 == 1 )
  {
    v18 = (unsigned int)(v8 + 1028);
    v19 = v6;
    v20 = 6;
    v21 = (unsigned int)(2 * *(_DWORD *)(v12 + 2648));
    goto LABEL_91;
  }
LABEL_7:
  if ( a3 != 2 )
    goto LABEL_93;
  if ( *(_BYTE *)(v11 + 2720) != 1 )
    goto LABEL_45;
  v15 = snd_soc_component_read(v6, (unsigned int)(v13 + 256));
  if ( (v15 & 0xFu) - 1 >= 4 )
  {
    if ( (v15 & 0xFu) - 5 >= 3 )
    {
      if ( (v15 & 0xC) != 8 )
        goto LABEL_45;
      v17 = 192;
      v16 = 2;
    }
    else
    {
      v17 = 212;
      v16 = 1;
    }
  }
  else
  {
    v16 = 0;
    v17 = 208;
  }
  snd_soc_component_update_bits(v6, v17, 14, 2 * (unsigned int)*(unsigned __int16 *)(v11 + 2 * v16 + 2528));
LABEL_45:
  usleep_range_state(5000, 5050, 2);
  snd_soc_component_update_bits(v6, (unsigned int)(v8 + 2100), 255, 89);
  snd_soc_component_update_bits(v6, (unsigned int)(v8 + 2104), 255, 6);
  snd_soc_component_update_bits(v6, (unsigned int)(v8 + 1028), 255, 0);
  snd_soc_component_update_bits(v6, (unsigned int)(v8 + 2048), 255, 65);
  v47 = 0;
  if ( (lpass_cdc_tx_macro_get_data(v6, v48, &v47, "is_amic_enabled") & 1) != 0
    && (snd_soc_component_read(v6, (unsigned int)(v13 + 260)) & 1) != 0
    && compoundliteral_103[v47] != 1 )
  {
    snd_soc_component_update_bits(v6, (unsigned int)(v8 + 1072), 255, 1);
  }
  if ( (unsigned int)(*(_DWORD *)(v11 + 2728) - 1) > 0x1D )
    goto LABEL_72;
  v31 = *(_DWORD *)(v11 + 2732);
  if ( (*(_BYTE *)(v11 + 2644) & 1) != 0 )
  {
    snd_soc_component_update_bits(v6, (unsigned int)(v31 + v8), 255, *(unsigned int *)(v11 + 2740));
    if ( *(int *)(v11 + 2728) <= 3 )
      goto LABEL_72;
    snd_soc_component_update_bits(v6, (unsigned int)(*(_DWORD *)(v11 + 2744) + v8), 255, *(unsigned int *)(v11 + 2752));
    if ( *(int *)(v11 + 2728) < 7 )
      goto LABEL_72;
    snd_soc_component_update_bits(v6, (unsigned int)(*(_DWORD *)(v11 + 2756) + v8), 255, *(unsigned int *)(v11 + 2764));
    if ( *(int *)(v11 + 2728) < 10 )
      goto LABEL_72;
    snd_soc_component_update_bits(v6, (unsigned int)(*(_DWORD *)(v11 + 2768) + v8), 255, *(unsigned int *)(v11 + 2776));
    if ( *(int *)(v11 + 2728) < 13 )
      goto LABEL_72;
    snd_soc_component_update_bits(v6, (unsigned int)(*(_DWORD *)(v11 + 2780) + v8), 255, *(unsigned int *)(v11 + 2788));
    if ( *(int *)(v11 + 2728) < 16 )
      goto LABEL_72;
    snd_soc_component_update_bits(v6, (unsigned int)(*(_DWORD *)(v11 + 2792) + v8), 255, *(unsigned int *)(v11 + 2800));
    if ( *(int *)(v11 + 2728) < 19 )
      goto LABEL_72;
    snd_soc_component_update_bits(v6, (unsigned int)(*(_DWORD *)(v11 + 2804) + v8), 255, *(unsigned int *)(v11 + 2812));
    if ( *(int *)(v11 + 2728) < 22 )
      goto LABEL_72;
    snd_soc_component_update_bits(v6, (unsigned int)(*(_DWORD *)(v11 + 2816) + v8), 255, *(unsigned int *)(v11 + 2824));
    if ( *(int *)(v11 + 2728) < 25 )
      goto LABEL_72;
    snd_soc_component_update_bits(v6, (unsigned int)(*(_DWORD *)(v11 + 2828) + v8), 255, *(unsigned int *)(v11 + 2836));
    if ( *(int *)(v11 + 2728) < 28 )
      goto LABEL_72;
    v32 = *(_DWORD *)(v11 + 2840);
    v33 = *(unsigned int *)(v11 + 2848);
  }
  else
  {
    snd_soc_component_update_bits(v6, (unsigned int)(v31 + v8), 255, *(unsigned int *)(v11 + 2736));
    if ( *(int *)(v11 + 2728) <= 3 )
      goto LABEL_72;
    snd_soc_component_update_bits(v6, (unsigned int)(*(_DWORD *)(v11 + 2744) + v8), 255, *(unsigned int *)(v11 + 2748));
    if ( *(int *)(v11 + 2728) < 7 )
      goto LABEL_72;
    snd_soc_component_update_bits(v6, (unsigned int)(*(_DWORD *)(v11 + 2756) + v8), 255, *(unsigned int *)(v11 + 2760));
    if ( *(int *)(v11 + 2728) < 10 )
      goto LABEL_72;
    snd_soc_component_update_bits(v6, (unsigned int)(*(_DWORD *)(v11 + 2768) + v8), 255, *(unsigned int *)(v11 + 2772));
    if ( *(int *)(v11 + 2728) < 13 )
      goto LABEL_72;
    snd_soc_component_update_bits(v6, (unsigned int)(*(_DWORD *)(v11 + 2780) + v8), 255, *(unsigned int *)(v11 + 2784));
    if ( *(int *)(v11 + 2728) < 16 )
      goto LABEL_72;
    snd_soc_component_update_bits(v6, (unsigned int)(*(_DWORD *)(v11 + 2792) + v8), 255, *(unsigned int *)(v11 + 2796));
    if ( *(int *)(v11 + 2728) < 19 )
      goto LABEL_72;
    snd_soc_component_update_bits(v6, (unsigned int)(*(_DWORD *)(v11 + 2804) + v8), 255, *(unsigned int *)(v11 + 2808));
    if ( *(int *)(v11 + 2728) < 22 )
      goto LABEL_72;
    snd_soc_component_update_bits(v6, (unsigned int)(*(_DWORD *)(v11 + 2816) + v8), 255, *(unsigned int *)(v11 + 2820));
    if ( *(int *)(v11 + 2728) < 25 )
      goto LABEL_72;
    snd_soc_component_update_bits(v6, (unsigned int)(*(_DWORD *)(v11 + 2828) + v8), 255, *(unsigned int *)(v11 + 2832));
    if ( *(int *)(v11 + 2728) < 28 )
      goto LABEL_72;
    v32 = *(_DWORD *)(v11 + 2840);
    v33 = *(unsigned int *)(v11 + 2844);
  }
  updated = snd_soc_component_update_bits(v6, (unsigned int)(v32 + v8), 255, v33);
  if ( *(int *)(v11 + 2728) <= 30 )
  {
LABEL_72:
    snd_soc_component_update_bits(v6, (unsigned int)(v8 + 1024), 32, 32);
    v47 = 0;
    if ( (lpass_cdc_tx_macro_get_data(v6, v48, &v47, "is_amic_enabled") & 1) == 0
      || (snd_soc_component_read(v6, (unsigned int)(v13 + 260)) & 1) == 0
      || (compoundliteral_103[v47] & 1) != 0 )
    {
      snd_soc_component_update_bits(v6, (unsigned int)(v8 + 1048), 1, 0);
      usleep_range_state(1000, 1010, 2);
    }
    v34 = snd_soc_component_read(v6, (unsigned int)(v8 + 1028));
    v35 = v11 + 608 + 120LL * (unsigned int)v7;
    *(_BYTE *)(v35 + 9) = (v34 >> 5) & 3;
    v36 = (_BYTE *)(v35 + 9);
    if ( ((v34 >> 5) & 3) != 2 )
      snd_soc_component_update_bits(v6, (unsigned int)(v8 + 1028), 96, 64);
    if ( (lpass_cdc_tx_macro_get_data(v6, v48, &v47, "is_amic_enabled") & 1) != 0 )
      snd_soc_component_read(v6, (unsigned int)(v13 + 260));
    if ( *v36 != 2 )
    {
      mutex_lock(v11 + 72);
      v37 = *(_DWORD *)(v11 + 2724);
      *(_DWORD *)(v11 + 2724) = v37 + 1;
      if ( !v37 )
        pm_stay_awake(*(_QWORD *)v11);
      mutex_unlock(v11 + 72);
      queue_delayed_work_on(32, system_freezable_wq, v11 + 608 + 120LL * (unsigned int)v7 + 16, 75);
      snd_soc_component_update_bits(v6, (unsigned int)(v8 + 1048), 3, 2);
      v47 = 0;
      if ( (lpass_cdc_tx_macro_get_data(v6, v48, &v47, "is_amic_enabled") & 1) == 0
        || (snd_soc_component_read(v6, (unsigned int)(v13 + 260)) & 1) == 0
        || (compoundliteral_103[v47] & 1) != 0 )
      {
        snd_soc_component_update_bits(v6, (unsigned int)(v8 + 1048), 3, 0);
      }
      snd_soc_component_update_bits(v6, (unsigned int)(v8 + 1048), 3, 1);
      usleep_range_state(6000, 6010, 2);
    }
    v38 = snd_soc_component_read(v6, (unsigned int)(v8 + 1036));
    snd_soc_component_write(v6, (unsigned int)(v8 + 1036), v38);
    if ( *(_BYTE *)(v11 + 2644) != 1 )
      goto LABEL_92;
    snd_soc_component_update_bits(v6, 12508, 15, *(unsigned int *)(v11 + 2680));
    snd_soc_component_update_bits(v6, (unsigned int)(v8 + 1028), 1, 1);
    v39 = *(unsigned __int8 *)(v11 + 2685);
    *(_BYTE *)(v11 + 2684) = 1;
    if ( v39 != 1 )
      goto LABEL_92;
    v19 = v6;
    v18 = 1068;
    v20 = 64;
    v21 = 64;
LABEL_91:
    snd_soc_component_update_bits(v19, v18, v20, v21);
LABEL_92:
    result = 0;
    goto LABEL_93;
  }
LABEL_95:
  __break(0x5512u);
  __asm { SUBG            SP, X6, #0xE0, #2 }
  return lpass_cdc_tx_macro_mclk_event(updated);
}
