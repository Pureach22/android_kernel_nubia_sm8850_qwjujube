__int64 __fastcall reg_skip_invalid_chan_freq(
        __int64 a1,
        __int64 a2,
        unsigned int *a3,
        int a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 v12; // x23
  unsigned int v17; // w24
  const char *v18; // x2
  unsigned int dfs_master_capability; // w0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  unsigned int v29; // w24
  char v30; // w25
  int v31; // w27
  int v32; // w9
  int *v33; // x28
  unsigned int v34; // w23
  __int64 v35; // x1
  int channel_state_for_pwrmode; // w26
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  char is_nan_allowed_on_freq; // w0
  int v46; // w8
  char indoor_ch_support; // w0
  bool v48; // zf
  __int64 v49; // x26
  const char *v50; // x2
  __int64 v51; // x26
  const char *v52; // x2
  __int16 v53; // [xsp+14h] [xbp-2Ch]
  __int64 v54; // [xsp+18h] [xbp-28h]
  unsigned int v55; // [xsp+20h] [xbp-20h] BYREF
  _BYTE v56[4]; // [xsp+24h] [xbp-1Ch] BYREF
  _BYTE v57[4]; // [xsp+28h] [xbp-18h] BYREF
  _BYTE v58[4]; // [xsp+2Ch] [xbp-14h] BYREF
  _BYTE v59[4]; // [xsp+30h] [xbp-10h] BYREF
  _BYTE v60[4]; // [xsp+34h] [xbp-Ch] BYREF
  __int64 v61; // [xsp+38h] [xbp-8h]

  v61 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = *(_QWORD *)(a1 + 80);
  v58[0] = 0;
  v57[0] = 0;
  v56[0] = 0;
  v55 = 0;
  if ( !v12 )
  {
    v17 = 16;
    v18 = "%s: invalid psoc";
    goto LABEL_7;
  }
  if ( !(unsigned int)ucfg_mlme_get_indoor_channel_support(v12, v58) )
  {
    ucfg_mlme_get_etsi_srd_chan_in_master_mode(v12, v56);
    dfs_master_capability = ucfg_mlme_get_dfs_master_capability(v12, v57);
    if ( dfs_master_capability )
    {
      v17 = dfs_master_capability;
      v18 = "%s: failed to get dfs master capable";
      goto LABEL_7;
    }
    wlan_reg_get_cur_6g_ap_pwr_type(a1, &v55);
    if ( v55 > 3 )
      v29 = 13;
    else
      v29 = dword_A2FB68[v55];
    if ( !a4 )
    {
LABEL_78:
      v17 = 0;
      goto LABEL_8;
    }
    v30 = 0;
    v54 = v12;
    while ( 1 )
    {
      if ( (a4 & 8) != 0 )
      {
        v30 = 1;
        v32 = 8;
        if ( *a3 )
          break;
        goto LABEL_14;
      }
      if ( (a4 & 0x200) != 0 )
      {
        v30 = 2;
        v32 = 512;
        if ( *a3 )
          break;
        goto LABEL_14;
      }
      if ( (a4 & 0x1000) == 0 )
        goto LABEL_78;
      v32 = 4096;
      if ( *a3 )
        break;
LABEL_14:
      v31 = ~v32;
LABEL_15:
      a4 &= v31;
      if ( !a4 )
        goto LABEL_78;
    }
    v33 = (int *)(a2 + 16);
    v34 = 0;
    v31 = ~v32;
    v53 = v32;
    while ( 1 )
    {
      v35 = (unsigned int)*(v33 - 4);
      if ( (a4 & 0x1000) != 0 )
      {
        is_nan_allowed_on_freq = wlan_is_nan_allowed_on_freq(a1, v35);
        v46 = *v33;
        if ( (is_nan_allowed_on_freq & 1) == 0 )
        {
          v46 &= v31;
          *v33 = v46;
        }
        if ( v46 )
          goto LABEL_26;
LABEL_77:
        qdf_trace_msg(
          0x51u,
          8u,
          "%s: removing freq %d",
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          v28,
          "reg_remove_freq",
          *(unsigned int *)(a2 + 24LL * (int)v34));
        qdf_mem_set((void *)(a2 + 24LL * (int)v34), 0x18u, 0);
        goto LABEL_26;
      }
      channel_state_for_pwrmode = reg_get_channel_state_for_pwrmode(
                                    a1,
                                    v35,
                                    v29,
                                    v21,
                                    v22,
                                    v23,
                                    v24,
                                    v25,
                                    v26,
                                    v27,
                                    v28);
      if ( (wlan_reg_is_freq_indoor(a1, (unsigned int)*(v33 - 4)) & 1) != 0 )
      {
        if ( (a4 & 0x200) != 0 )
        {
          indoor_ch_support = ucfg_p2p_get_indoor_ch_support(v54);
          if ( (channel_state_for_pwrmode & 0xFFFFFFFB) != 0 && (indoor_ch_support & 1) != 0 )
            goto LABEL_40;
        }
        else if ( (channel_state_for_pwrmode & 0xFFFFFFFB) != 0 && (v58[0] & 1) != 0 )
        {
          goto LABEL_40;
        }
        v48 = (*v33 & v31) == 0;
        *v33 &= v31;
        if ( v48 )
        {
          qdf_trace_msg(
            0x51u,
            8u,
            "%s: removing freq %d",
            v37,
            v38,
            v39,
            v40,
            v41,
            v42,
            v43,
            v44,
            "reg_remove_freq",
            *(unsigned int *)(a2 + 24LL * (int)v34));
          qdf_mem_set((void *)(a2 + 24LL * (int)v34), 0x18u, 0);
        }
      }
LABEL_40:
      if ( (v56[0] & (unsigned __int8)v30) == 0
        && (reg_is_etsi_srd_chan_for_freq(a1, (unsigned int)*(v33 - 4)) & 1) != 0 )
      {
        v48 = (*v33 & v31) == 0;
        *v33 &= v31;
        if ( v48 )
        {
          qdf_trace_msg(
            0x51u,
            8u,
            "%s: removing freq %d",
            v37,
            v38,
            v39,
            v40,
            v41,
            v42,
            v43,
            v44,
            "reg_remove_freq",
            *(unsigned int *)(a2 + 24LL * (int)v34));
          qdf_mem_set((void *)(a2 + 24LL * (int)v34), 0x18u, 0);
        }
      }
      v49 = *(_QWORD *)(a1 + 80);
      v60[0] = 0;
      v59[0] = 0;
      if ( !v49 )
      {
        v50 = "%s: invalid psoc";
        goto LABEL_51;
      }
      if ( (unsigned int)ucfg_mlme_get_dfs_master_capability(v49, v60) )
      {
        v50 = "%s: failed to get dfs master capable";
LABEL_51:
        qdf_trace_msg(0x51u, 2u, v50, v37, v38, v39, v40, v41, v42, v43, v44, "reg_update_list_for_dfs_channel");
        goto LABEL_52;
      }
      if ( (unsigned int)ucfg_mlme_get_dfs_discard_mode(v49, v59) )
      {
        v50 = "%s: failed to get dfs discard mode";
        goto LABEL_51;
      }
      if ( (wlan_reg_is_dfs_for_freq(a1, (unsigned int)*(v33 - 4)) & 1) != 0
        && (v60[0] != 1 || v59[0] == 3 || (v53 & 0x200) != 0 && v59[0] == 2 || (v53 & 8) != 0 && v59[0] == 1) )
      {
        v48 = (*v33 & v31) == 0;
        *v33 &= v31;
        if ( v48 )
        {
          qdf_trace_msg(
            0x51u,
            8u,
            "%s: removing freq %d",
            v21,
            v22,
            v23,
            v24,
            v25,
            v26,
            v27,
            v28,
            "reg_remove_freq",
            *(unsigned int *)(a2 + 24LL * (int)v34));
          qdf_mem_set((void *)(a2 + 24LL * (int)v34), 0x18u, 0);
        }
      }
LABEL_52:
      v51 = *(_QWORD *)(a1 + 80);
      v60[0] = 0;
      if ( !v51 )
      {
        v52 = "%s: invalid psoc";
        goto LABEL_57;
      }
      if ( (wlan_reg_is_passive_for_freq(a1, (unsigned int)*(v33 - 4)) & 1) != 0 )
      {
        if ( (unsigned int)ucfg_mlme_get_passive_discard_mode(v51, v60) )
        {
          v52 = "%s: failed to get passive discard mode";
LABEL_57:
          qdf_trace_msg(0x51u, 2u, v52, v21, v22, v23, v24, v25, v26, v27, v28, "reg_update_list_for_passive_channel");
          goto LABEL_26;
        }
        switch ( v60[0] )
        {
          case 1:
            if ( (v53 & 8) != 0 )
            {
LABEL_75:
              v48 = (*v33 & v31) == 0;
              *v33 &= v31;
              if ( !v48 )
                break;
              goto LABEL_77;
            }
            break;
          case 2:
            if ( (v53 & 0x200) != 0 )
              goto LABEL_75;
            break;
          case 3:
            goto LABEL_75;
          default:
            qdf_trace_msg(
              0x51u,
              8u,
              "%s: mode not handled %d",
              v21,
              v22,
              v23,
              v24,
              v25,
              v26,
              v27,
              v28,
              "reg_update_list_for_passive_channel");
            break;
        }
      }
LABEL_26:
      ++v34;
      v33 += 6;
      if ( v34 >= *a3 )
        goto LABEL_15;
    }
  }
  v17 = 16;
  v18 = "%s: failed to get indoor channel skip info";
LABEL_7:
  qdf_trace_msg(0x51u, 2u, v18, a5, a6, a7, a8, a9, a10, a11, a12, "reg_skip_invalid_chan_freq");
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return v17;
}
