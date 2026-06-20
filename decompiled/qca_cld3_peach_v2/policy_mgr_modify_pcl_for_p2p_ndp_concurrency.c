__int64 __fastcall policy_mgr_modify_pcl_for_p2p_ndp_concurrency(__int64 a1, _DWORD *a2, unsigned int *a3)
{
  __int64 context; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x21
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 result; // x0
  unsigned int v25; // w22
  __int64 v26; // x22
  unsigned __int64 v27; // x23
  int *v28; // x24
  int v29; // w25
  unsigned __int64 v30; // x8
  int v31; // w9
  unsigned int v32; // w8
  __int64 v33; // x23
  unsigned __int64 v34; // x24
  unsigned int *v35; // x28
  unsigned __int64 v36; // x8
  unsigned int v37; // w25
  unsigned int v38; // w10
  unsigned int *v39; // x8
  __int64 v40; // x23
  unsigned __int64 v41; // x25
  int *v42; // x24
  int v43; // w26
  unsigned __int64 v44; // x8
  _DWORD *v45; // x9
  int v46; // w8
  int v47; // w10
  unsigned __int64 v48; // x23
  unsigned int *v49; // x27
  unsigned int *v50; // x8
  unsigned int v51; // w10
  unsigned int v52; // w28
  __int64 v53; // x8
  int *v54; // x9
  __int64 v55; // x9
  unsigned int *v56; // x8
  int v57; // w8
  unsigned int v58; // w8
  unsigned int *v59; // x10
  __int64 v60; // x4
  __int64 v61; // x8
  _DWORD *v62; // x11
  _DWORD *v63; // x13
  __int64 v64; // x12
  unsigned int v65; // [xsp+Ch] [xbp-514h] BYREF
  unsigned int v66; // [xsp+10h] [xbp-510h] BYREF
  unsigned int v67; // [xsp+14h] [xbp-50Ch] BYREF
  int v68; // [xsp+18h] [xbp-508h] BYREF
  char v69; // [xsp+1Ch] [xbp-504h]
  int v70; // [xsp+20h] [xbp-500h] BYREF
  char v71; // [xsp+24h] [xbp-4FCh]
  int v72; // [xsp+28h] [xbp-4F8h] BYREF
  char v73; // [xsp+2Ch] [xbp-4F4h]
  _DWORD s[306]; // [xsp+30h] [xbp-4F0h] BYREF
  __int64 v75; // [xsp+4F8h] [xbp-28h] BYREF
  __int64 v76; // [xsp+500h] [xbp-20h]
  unsigned int v77; // [xsp+508h] [xbp-18h]
  __int64 v78; // [xsp+510h] [xbp-10h]

  v78 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v77 = 0;
  v75 = 0;
  v76 = 0;
  v73 = 0;
  v72 = 0;
  LOBYTE(v67) = 0;
  LOBYTE(v66) = 0;
  v71 = 0;
  v70 = 0;
  v69 = 0;
  v68 = 0;
  memset(s, 0, sizeof(s));
  v65 = 0;
  context = policy_mgr_get_context(a1);
  if ( context )
  {
    v15 = context;
    qdf_mutex_acquire(context + 56);
    policy_mgr_get_ml_and_non_ml_mode_count(
      a1,
      &v67,
      (__int64)&v70,
      &v66,
      (__int64)&v68,
      (unsigned __int64)&v75,
      (unsigned __int64)&v72,
      0);
    qdf_mutex_release(v15 + 56);
    result = 0;
    if ( (unsigned __int8)v66 <= 1u )
    {
      if ( !(_BYTE)v66 || !(_BYTE)v67 )
      {
        v25 = v75;
        if ( (_BYTE)v67 )
        {
          if ( !wlan_reg_is_24ghz_ch_freq(v75) )
            v25 = v75;
          if ( (unsigned __int8)v67 >= 2u )
          {
            if ( !wlan_reg_is_24ghz_ch_freq(HIDWORD(v75)) )
              v25 = HIDWORD(v75);
            if ( (unsigned __int8)v67 >= 3u )
            {
              if ( !wlan_reg_is_24ghz_ch_freq(v76) )
                v25 = v76;
              if ( (unsigned __int8)v67 >= 4u )
              {
                if ( !wlan_reg_is_24ghz_ch_freq(HIDWORD(v76)) )
                  v25 = HIDWORD(v76);
                if ( (unsigned __int8)v67 >= 5u )
                {
                  if ( !wlan_reg_is_24ghz_ch_freq(v77) )
                    v25 = v77;
                  if ( (unsigned __int8)v67 > 5u )
                    goto LABEL_83;
                }
              }
            }
          }
        }
        if ( v25
          && v25 != (unsigned int)wlan_nan_get_24ghz_social_ch_freq(*(_QWORD *)(v15 + 8))
          && v25 != (unsigned int)wlan_nan_get_5ghz_social_ch_freq(*(_QWORD *)(v15 + 8))
          && (wlan_reg_is_dfs_for_freq(*(_QWORD *)(v15 + 8), v25, v16, v17, v18, v19, v20, v21, v22, v23) & 1) == 0 )
        {
          goto LABEL_55;
        }
        if ( *a3 )
        {
          v26 = *(_QWORD *)(v15 + 8);
          v27 = 0;
          v28 = a2;
          while ( 1 )
          {
            v29 = *v28;
            if ( v29 == (unsigned int)wlan_nan_get_5ghz_social_ch_freq(v26) )
              break;
            v30 = *a3;
            ++v27;
            v28 += 3;
            if ( v27 >= v30 )
            {
              v25 = 0;
              if ( !(_DWORD)v30 )
                goto LABEL_74;
              goto LABEL_33;
            }
          }
          v31 = v28[2];
          v25 = 1;
          s[0] = *v28;
          s[1] = 255;
          v32 = *a3;
          s[2] = v31;
          v65 = 1;
          if ( !v32 )
            goto LABEL_74;
LABEL_33:
          v33 = *(_QWORD *)(v15 + 8);
          v34 = 0;
          v35 = a2;
          do
          {
            if ( wlan_reg_is_5ghz_ch_freq(*v35) || wlan_reg_is_6ghz_chan_freq(*v35) )
            {
              v37 = *v35;
              if ( v37 != (unsigned int)wlan_nan_get_5ghz_social_ch_freq(v33) )
              {
                if ( v25 > 0x65 )
                {
LABEL_54:
                  while ( 1 )
                  {
                    __break(1u);
LABEL_55:
                    if ( !wlan_reg_is_24ghz_ch_freq(v25)
                      || v25 == (unsigned int)wlan_nan_get_24ghz_social_ch_freq(*(_QWORD *)(v15 + 8)) )
                    {
                      break;
                    }
                    policy_mgr_append_5g_nan_social_ch(*(_QWORD *)(v15 + 8), a2, a3, s, &v65, 255);
                    policy_mgr_append_5g_non_nan_social_ch(*(_QWORD *)(v15 + 8), a2, a3, s, &v65, 235);
                    v55 = *a3;
                    if ( !(_DWORD)v55 )
                      goto LABEL_73;
                    v56 = a2 + 2;
                    while ( *(v56 - 2) != v25 )
                    {
                      --v55;
                      v56 += 3;
                      if ( !v55 )
                        goto LABEL_73;
                    }
                    if ( v65 <= 0x65 )
                    {
                      v58 = *v56;
                      v59 = &s[3 * v65++];
                      *v59 = v25;
                      v59[1] = 215;
                      v59[2] = v58;
LABEL_73:
                      policy_mgr_append_2g_nan_social_ch(*(_QWORD *)(v15 + 8), a2, a3, s, &v65, 195);
                      policy_mgr_append_2g_non_nan_social_ch(*(_QWORD *)(v15 + 8), a2, a3, s, &v65, 175);
                      policy_mger_remove_duplicate_freq_with_weight(s, &v65, v25, 175);
                      goto LABEL_74;
                    }
                  }
                  if ( wlan_reg_is_5ghz_ch_freq(v25) || wlan_reg_is_6ghz_chan_freq(v25) )
                  {
                    v53 = *a3;
                    if ( (_DWORD)v53 )
                    {
                      v54 = a2 + 2;
                      while ( *(v54 - 2) != v25 )
                      {
                        --v53;
                        v54 += 3;
                        if ( !v53 )
                          goto LABEL_70;
                      }
                      v57 = *v54;
                      s[0] = v25;
                      s[1] = 255;
                      s[2] = v57;
                      v65 = 1;
                    }
LABEL_70:
                    policy_mgr_append_5g_nan_social_ch(*(_QWORD *)(v15 + 8), a2, a3, s, &v65, 235);
                    policy_mgr_append_5g_non_nan_social_ch(*(_QWORD *)(v15 + 8), a2, a3, s, &v65, 215);
                    policy_mger_remove_duplicate_freq_with_weight(s, &v65, v25, 215);
                    policy_mgr_append_2g_nan_social_ch(*(_QWORD *)(v15 + 8), a2, a3, s, &v65, 195);
                    policy_mgr_append_2g_non_nan_social_ch(*(_QWORD *)(v15 + 8), a2, a3, s, &v65, 175);
                  }
                  goto LABEL_74;
                }
                v38 = v35[2];
                v39 = &s[3 * v25++];
                *v39 = *v35;
                v39[1] = 235;
                v39[2] = v38;
              }
            }
            v36 = *a3;
            ++v34;
            v35 += 3;
          }
          while ( v34 < v36 );
          v65 = v25;
          if ( (_DWORD)v36 )
          {
            v40 = *(_QWORD *)(v15 + 8);
            v41 = 0;
            v42 = a2;
            while ( 1 )
            {
              v43 = *v42;
              if ( v43 == (unsigned int)wlan_nan_get_24ghz_social_ch_freq(v40) )
                break;
              v44 = *a3;
              ++v41;
              v42 += 3;
              if ( v41 >= v44 )
                goto LABEL_47;
            }
            if ( v25 > 0x65 )
              goto LABEL_54;
            v45 = &s[3 * v25];
            v46 = *v42;
            v47 = v42[2];
            v65 = ++v25;
            *v45 = v46;
            v45[1] = 215;
            LODWORD(v44) = *a3;
            v45[2] = v47;
LABEL_47:
            if ( (_DWORD)v44 )
            {
              v15 = *(_QWORD *)(v15 + 8);
              v48 = 0;
              v49 = a2;
              do
              {
                if ( wlan_reg_is_24ghz_ch_freq(*v49) )
                {
                  v52 = *v49;
                  if ( v52 != (unsigned int)wlan_nan_get_24ghz_social_ch_freq(v15) )
                  {
                    if ( v25 > 0x65 )
                      goto LABEL_54;
                    v50 = &s[3 * v25];
                    v51 = v49[2];
                    ++v25;
                    *v50 = *v49;
                    v50[1] = 195;
                    v50[2] = v51;
                  }
                }
                ++v48;
                v49 += 3;
              }
              while ( v48 < *a3 );
              goto LABEL_75;
            }
          }
        }
LABEL_74:
        v25 = v65;
LABEL_75:
        v60 = *a3;
        if ( (_DWORD)v60 != v25 )
          qdf_trace_msg(
            0x4Fu,
            8u,
            "%s: No.of channels are different in original(%d) and modified PCL(%d)",
            v16,
            v17,
            v18,
            v19,
            v20,
            v21,
            v22,
            v23,
            "policy_mgr_modify_pcl_for_p2p_ndp_concurrency",
            v60,
            v25);
        *a3 = v25;
        if ( v25 )
        {
          v61 = 0;
          while ( v61 != 309 )
          {
            v62 = &s[v61];
            v63 = &a2[v61];
            v61 += 3;
            v64 = *(_QWORD *)v62;
            LODWORD(v62) = v62[2];
            *(_QWORD *)v63 = v64;
            v63[2] = (_DWORD)v62;
            if ( 3LL * v25 == v61 )
              goto LABEL_81;
          }
LABEL_83:
          __break(0x5512u);
        }
      }
LABEL_81:
      result = 0;
    }
  }
  else
  {
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: context is NULL",
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      "policy_mgr_modify_pcl_for_p2p_ndp_concurrency");
    result = 4;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
