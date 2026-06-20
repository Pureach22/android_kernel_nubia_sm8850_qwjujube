__int64 __fastcall msm_vidc_scale_clocks_iris4(__int64 a1)
{
  __int64 v1; // x20
  int v3; // w8
  unsigned __int64 clock_freq; // x22
  unsigned __int64 v5; // x23
  unsigned __int64 v6; // x24
  unsigned __int64 v7; // x0
  unsigned __int64 v8; // x8
  unsigned __int64 v9; // x9
  unsigned __int64 v10; // x10
  unsigned __int64 v11; // x11
  unsigned __int64 v12; // x8
  unsigned __int64 v13; // x8
  unsigned __int64 v14; // x8
  __int64 v15; // x27
  __int64 *v16; // x11
  int v17; // w4
  int v18; // w8
  int v19; // w9
  unsigned __int64 v20; // x21
  unsigned __int64 v21; // x22
  int v22; // w10
  unsigned __int64 v23; // x23
  bool v24; // zf
  unsigned __int64 v25; // x24
  char v26; // w28
  bool v28; // zf
  int v29; // w13
  __int64 v30; // x8
  unsigned __int64 v31; // x25
  unsigned __int64 v32; // x26
  __int64 v33; // x20
  __int64 v34; // x19
  __int64 v35; // x28
  __int64 v36; // x27
  int v37; // w8
  __int64 v38; // x9
  __int64 v39; // x11
  int v40; // w8
  __int64 v41; // x9
  __int64 v42; // x11
  int v43; // w8
  __int64 v44; // x9
  __int64 v45; // x11
  int v46; // w8
  __int64 v47; // x9
  __int64 v48; // x11
  int v49; // w8
  int v50; // w25
  __int64 v51; // x26
  __int64 v52; // x20
  __int64 v54; // x9
  __int64 v55; // x10
  __int64 v56; // x11
  __int64 v57; // x9
  __int64 v58; // x10
  __int64 v59; // x8
  char v60; // [xsp+4h] [xbp-1Ch]
  __int64 v61; // [xsp+8h] [xbp-18h]
  __int64 v62; // [xsp+10h] [xbp-10h]
  int v63; // [xsp+1Ch] [xbp-4h]

  v1 = *(_QWORD *)(a1 + 320);
  if ( *(_DWORD *)(a1 + 1916) < 0x10u
    || *(_DWORD *)(a1 + 312) == 8
    || (is_sub_state(a1, 2) & 1) != 0
    || (is_sub_state(a1, 1) & 1) != 0 )
  {
    v3 = *(_DWORD *)(a1 + 312);
    *(_DWORD *)(a1 + 2120) = *(_DWORD *)(a1 + 38432);
    if ( v3 != 8 )
      msm_vidc_calc_freq_iris4(a1, a1 + 2120);
    clock_freq = get_clock_freq(v1, "video_cc_mvs0_clk_src");
    v5 = get_clock_freq(v1, "video_cc_mvs0a_clk_src");
    v6 = get_clock_freq(v1, "video_cc_mvs0b_clk_src");
    v7 = get_clock_freq(v1, "video_cc_mvs0c_clk_src");
    v8 = *(_QWORD *)(a1 + 2136);
    v9 = *(_QWORD *)(a1 + 2144);
    v10 = *(_QWORD *)(a1 + 2152);
    v11 = *(_QWORD *)(a1 + 2160);
    *(_DWORD *)(a1 + 1992) = 0;
    if ( v8 <= clock_freq )
      v8 = clock_freq;
    *(_QWORD *)(a1 + 1952) = v8;
    if ( v9 <= v5 )
      v12 = v5;
    else
      v12 = v9;
    *(_QWORD *)(a1 + 1960) = v12;
    if ( v10 <= v6 )
      v13 = v6;
    else
      v13 = v10;
    *(_QWORD *)(a1 + 1968) = v13;
    if ( v11 <= v7 )
      v14 = v7;
    else
      v14 = v11;
    *(_QWORD *)(a1 + 1976) = v14;
  }
  else
  {
    v54 = msm_vidc_apv_clock_voting;
    v55 = msm_vidc_bse_clock_voting;
    v56 = msm_vidc_tensilica_clock_voting;
    if ( msm_vidc_clock_voting
      || msm_vidc_vpp_clock_voting
      && msm_vidc_apv_clock_voting
      && msm_vidc_bse_clock_voting
      && msm_vidc_tensilica_clock_voting )
    {
      *(_QWORD *)(a1 + 1952) = msm_vidc_vpp_clock_voting;
      *(_QWORD *)(a1 + 1960) = v54;
      *(_QWORD *)(a1 + 1968) = v55;
      *(_QWORD *)(a1 + 1976) = v56;
      *(_DWORD *)(a1 + 1992) = 0;
    }
    else
    {
      *(_DWORD *)(a1 + 2120) = *(_DWORD *)(a1 + 38432);
      msm_vidc_calc_freq_iris4(a1, a1 + 2120);
      v57 = *(_QWORD *)(a1 + 2144);
      v58 = *(_QWORD *)(a1 + 2152);
      *(_QWORD *)(a1 + 1952) = *(_QWORD *)(a1 + 2136);
      v59 = *(_QWORD *)(a1 + 2160);
      *(_QWORD *)(a1 + 1960) = v57;
      *(_QWORD *)(a1 + 1968) = v58;
      *(_QWORD *)(a1 + 1976) = v59;
      msm_vidc_apply_dcvs(a1);
    }
  }
  v15 = *(_QWORD *)(a1 + 320);
  v62 = a1;
  mutex_lock(v15 + 3856);
  v16 = *(__int64 **)(v15 + 3528);
  if ( v16 == (__int64 *)(v15 + 3528) )
  {
    v26 = 0;
    v25 = 0;
    v23 = 0;
    v21 = 0;
    v20 = 0;
    LOBYTE(v63) = 1;
    goto LABEL_41;
  }
  v17 = msm_vidc_vpp_clock_voting;
  v18 = msm_vidc_apv_clock_voting;
  v19 = msm_vidc_bse_clock_voting;
  v20 = 0;
  v21 = 0;
  v22 = msm_vidc_tensilica_clock_voting;
  v23 = 0;
  if ( msm_vidc_vpp_clock_voting )
    v24 = msm_vidc_apv_clock_voting == 0;
  else
    v24 = 1;
  v25 = 0;
  v26 = 0;
  v28 = v24 || msm_vidc_bse_clock_voting == 0 || msm_vidc_tensilica_clock_voting == 0;
  LOBYTE(v63) = 1;
  v29 = !v28;
  while ( 1 )
  {
    if ( !*((_DWORD *)v16 + 9608) || *((_BYTE *)v16 + 38408) != 1 )
      goto LABEL_32;
    if ( v29 )
      break;
    v25 += v16[247];
    v23 += v16[246];
    v21 += v16[245];
    v20 += v16[244];
    v26 |= *((_DWORD *)v16 + 498);
    v63 &= ((_DWORD)v16[249] & 2u) >> 1;
LABEL_32:
    v16 = (__int64 *)*v16;
    if ( v16 == (__int64 *)(v15 + 3528) )
      goto LABEL_41;
  }
  if ( (msm_vidc_debug & 4) != 0 )
  {
    printk(&unk_912AE, "low ", 0xFFFFFFFFLL, "codec", (unsigned int)msm_vidc_vpp_clock_voting);
    v17 = msm_vidc_vpp_clock_voting;
    v18 = msm_vidc_apv_clock_voting;
    v19 = msm_vidc_bse_clock_voting;
    v22 = msm_vidc_tensilica_clock_voting;
  }
  v20 = v17;
  v21 = v18;
  v23 = v19;
  v25 = v22;
  LOBYTE(v63) = 0;
LABEL_41:
  v60 = v26;
  mutex_unlock(v15 + 3856);
  v30 = *(_QWORD *)(v15 + 3904);
  v61 = v15;
  v31 = *(_QWORD *)(v30 + 64);
  v32 = v31 + 72LL * *(unsigned int *)(v30 + 72);
  if ( v31 < v32 )
  {
    LODWORD(v33) = 0x7FFFFFFF;
    LODWORD(v34) = 0x7FFFFFFF;
    LODWORD(v35) = 0x7FFFFFFF;
    LODWORD(v36) = 0x7FFFFFFF;
    while ( v20 && !strcmp(*(const char **)(v31 + 8), "video_cc_mvs0_clk_src") )
    {
      v33 = *(unsigned int *)(v31 + 56);
      v37 = v33 - 1;
      v38 = v33 - 1;
      if ( (int)v33 - 1 >= -1 )
        v37 = -1;
      while ( 1 )
      {
        LODWORD(v33) = v33 - 1;
        if ( (int)v33 < 0 )
          break;
        v39 = v38-- & 0x7FFFFFFF;
        if ( *(_QWORD *)(*(_QWORD *)(v31 + 64) + 8 * v39) >= v20 )
          goto LABEL_51;
      }
      LODWORD(v33) = v37;
      if ( v21 )
        goto LABEL_52;
LABEL_61:
      if ( v23 && !strcmp(*(const char **)(v31 + 8), "video_cc_mvs0b_clk_src") )
      {
        v35 = *(unsigned int *)(v31 + 56);
        v43 = v35 - 1;
        v44 = v35 - 1;
        if ( (int)v35 - 1 >= -1 )
          v43 = -1;
        while ( 1 )
        {
          LODWORD(v35) = v35 - 1;
          if ( (int)v35 < 0 )
            break;
          v45 = v44-- & 0x7FFFFFFF;
          if ( *(_QWORD *)(*(_QWORD *)(v31 + 64) + 8 * v45) >= v23 )
            goto LABEL_67;
        }
        LODWORD(v35) = v43;
        if ( !v25 )
          goto LABEL_44;
LABEL_68:
        if ( !strcmp(*(const char **)(v31 + 8), "video_cc_mvs0c_clk_src") )
        {
          v34 = *(unsigned int *)(v31 + 56);
          v46 = v34 - 1;
          v47 = v34 - 1;
          if ( (int)v34 - 1 >= -1 )
            v46 = -1;
          while ( 1 )
          {
            LODWORD(v34) = v34 - 1;
            if ( (int)v34 < 0 )
              break;
            v48 = v47-- & 0x7FFFFFFF;
            if ( *(_QWORD *)(*(_QWORD *)(v31 + 64) + 8 * v48) >= v25 )
              goto LABEL_44;
          }
          LODWORD(v34) = v46;
        }
        goto LABEL_44;
      }
LABEL_67:
      if ( v25 )
        goto LABEL_68;
LABEL_44:
      v31 += 72LL;
      if ( v31 >= v32 )
        goto LABEL_77;
    }
LABEL_51:
    if ( !v21 )
      goto LABEL_61;
LABEL_52:
    if ( !strcmp(*(const char **)(v31 + 8), "video_cc_mvs0a_clk_src") )
    {
      v36 = *(unsigned int *)(v31 + 56);
      v40 = v36 - 1;
      v41 = v36 - 1;
      if ( (int)v36 - 1 >= -1 )
        v40 = -1;
      while ( 1 )
      {
        LODWORD(v36) = v36 - 1;
        if ( (int)v36 < 0 )
          break;
        v42 = v41-- & 0x7FFFFFFF;
        if ( *(_QWORD *)(*(_QWORD *)(v31 + 64) + 8 * v42) >= v21 )
          goto LABEL_61;
      }
      LODWORD(v36) = v40;
    }
    goto LABEL_61;
  }
  LODWORD(v36) = 0x7FFFFFFF;
  LODWORD(v35) = 0x7FFFFFFF;
  LODWORD(v34) = 0x7FFFFFFF;
  LODWORD(v33) = 0x7FFFFFFF;
LABEL_77:
  if ( (int)v36 >= (int)v35 )
    v49 = v35;
  else
    v49 = v36;
  if ( (int)v33 < v49 )
    v49 = v33;
  if ( v49 >= (int)v34 )
    v49 = v34;
  v50 = v49 & ~(v49 >> 31);
  if ( (v60 & 1) != 0 )
  {
    v51 = v61;
    v52 = v62;
    v50 -= v50 > (int)get_max_clock_index(v61);
  }
  else
  {
    v51 = v61;
    v52 = v62;
    if ( (v63 & 1) != 0 && v50 < (int)get_min_clock_index(v61) )
      ++v50;
  }
  if ( v52 )
  {
    if ( (msm_vidc_debug & 8) != 0 )
    {
      printk(&unk_88DA0, "perf", v52 + 340, "msm_vidc_get_freq_corner", v20);
      if ( (msm_vidc_debug & 8) != 0 )
        printk(&unk_92054, "perf", v52 + 340, "msm_vidc_get_freq_corner", v60 & 1);
    }
  }
  *(_DWORD *)(v51 + 6408) = v50;
  return (unsigned int)v50;
}
