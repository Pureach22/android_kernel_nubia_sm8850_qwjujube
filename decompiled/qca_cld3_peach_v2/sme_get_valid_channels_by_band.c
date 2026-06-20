__int64 __fastcall sme_get_valid_channels_by_band(__int64 a1, unsigned __int8 a2, __int64 a3, _BYTE *a4)
{
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  const char *v16; // x2
  __int64 result; // x0
  unsigned int cfg_valid_channels; // w0
  unsigned int v19; // w19
  __int64 v20; // x24
  __int64 v21; // x23
  unsigned int v22; // w22
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 v31; // x8
  __int64 v32; // x24
  unsigned int v33; // w22
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  __int64 v42; // x8
  __int64 v43; // x22
  __int64 v44; // x8
  unsigned int v45; // w21
  unsigned __int64 v46; // x8
  __int64 v47; // x24
  unsigned int v48; // w22
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  __int64 v57; // x8
  __int64 v58; // x22
  unsigned int v59; // w21
  __int64 v60; // x8
  __int64 v61; // x22
  unsigned int v62; // w21
  __int64 v63; // x8
  unsigned __int64 v64; // x8
  unsigned __int64 v65; // x8
  __int64 v66; // x9
  _DWORD *v67; // x10
  int *v68; // x9
  unsigned __int64 v69; // x11
  int v70; // w12
  int v71; // w13
  unsigned int v72; // [xsp+4h] [xbp-19Ch] BYREF
  _DWORD s[100]; // [xsp+8h] [xbp-198h] BYREF
  __int64 v74; // [xsp+198h] [xbp-8h]

  v74 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(s, 0, sizeof(s));
  v72 = 100;
  if ( !a3 || !a4 )
  {
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: Output channel list/NumChannels is NULL",
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      "sme_get_valid_channels_by_band");
    result = 4;
    goto LABEL_75;
  }
  if ( a2 < 8u )
  {
    cfg_valid_channels = sme_get_cfg_valid_channels((__int64)s, &v72, v8, v9, v10, v11, v12, v13, v14, v15);
    if ( cfg_valid_channels )
    {
      v19 = cfg_valid_channels;
      qdf_trace_msg(
        0x34u,
        2u,
        "%s: Fail to get valid channel list (err=%d)",
        v8,
        v9,
        v10,
        v11,
        v12,
        v13,
        v14,
        v15,
        "sme_get_valid_channels_by_band",
        cfg_valid_channels);
      result = v19;
      goto LABEL_75;
    }
    if ( a2 <= 2u )
    {
      switch ( a2 )
      {
        case 0u:
          qdf_trace_msg(
            0x34u,
            8u,
            "%s: Unspec Band, return all %d valid channels",
            v8,
            v9,
            v10,
            v11,
            v12,
            v13,
            v14,
            v15,
            "sme_get_valid_channels_by_band",
            v72);
          v21 = v72;
          if ( v72 )
          {
            if ( v72 >= 3 )
            {
              v64 = v72 - 1LL;
              if ( v64 >= 0x64 )
                v64 = 100;
              v65 = v64 + 1;
              v66 = v65 & 1;
              if ( (v65 & 1) == 0 )
                v66 = 2;
              v67 = (_DWORD *)(a3 + 4);
              v46 = v65 - v66;
              v68 = &s[1];
              v69 = v46;
              do
              {
                v70 = *(v68 - 1);
                v71 = *v68;
                v69 -= 2LL;
                v68 += 2;
                *(v67 - 1) = v70;
                *v67 = v71;
                v67 += 2;
              }
              while ( v69 );
            }
            else
            {
              v46 = 0;
            }
            while ( v46 != 100 )
            {
              if ( (v46 & 0x3FFFFFFFFFFFFFFFLL) == 0x64 )
                goto LABEL_77;
              *(_DWORD *)(a3 + 4 * v46) = s[v46];
              if ( v21 == ++v46 )
                goto LABEL_74;
            }
LABEL_76:
            __break(0x5512u);
LABEL_77:
            __break(1u);
          }
LABEL_74:
          result = 0;
          *a4 = v21;
          goto LABEL_75;
        case 1u:
          qdf_trace_msg(
            0x34u,
            8u,
            "%s: WIFI_BAND_BG (2.4 GHz)",
            v8,
            v9,
            v10,
            v11,
            v12,
            v13,
            v14,
            v15,
            "sme_get_valid_channels_by_band");
          if ( v72 )
          {
            v61 = 0;
            LOBYTE(v21) = 0;
            while ( v61 != 100 )
            {
              v62 = s[v61];
              if ( wlan_reg_is_24ghz_ch_freq(v62) )
              {
                v63 = (unsigned __int8)v21;
                LOBYTE(v21) = v21 + 1;
                *(_DWORD *)(a3 + 4 * v63) = v62;
              }
              if ( v72 <= (unsigned int)++v61 )
                goto LABEL_74;
            }
            goto LABEL_76;
          }
          break;
        case 2u:
          qdf_trace_msg(
            0x34u,
            8u,
            "%s: WIFI_BAND_A (5 GHz without DFS)",
            v8,
            v9,
            v10,
            v11,
            v12,
            v13,
            v14,
            v15,
            "sme_get_valid_channels_by_band");
          if ( v72 )
          {
            v32 = 0;
            LOBYTE(v21) = 0;
            while ( v32 != 100 )
            {
              v33 = s[v32];
              if ( wlan_reg_is_5ghz_ch_freq(v33)
                && (wlan_reg_is_dfs_for_freq(*(_QWORD *)(a1 + 21632), v33, v34, v35, v36, v37, v38, v39, v40, v41) & 1) == 0 )
              {
                v42 = (unsigned __int8)v21;
                LOBYTE(v21) = v21 + 1;
                *(_DWORD *)(a3 + 4 * v42) = v33;
              }
              if ( v72 <= (unsigned int)++v32 )
                goto LABEL_74;
            }
            goto LABEL_76;
          }
          break;
        default:
          goto LABEL_43;
      }
    }
    else if ( a2 > 5u )
    {
      if ( a2 == 6 )
      {
        qdf_trace_msg(
          0x34u,
          8u,
          "%s: WIFI_BAND_A_WITH_DFS (5 GHz with DFS)",
          v8,
          v9,
          v10,
          v11,
          v12,
          v13,
          v14,
          v15,
          "sme_get_valid_channels_by_band");
        if ( v72 )
        {
          v58 = 0;
          LOBYTE(v21) = 0;
          while ( v58 != 100 )
          {
            v59 = s[v58];
            if ( wlan_reg_is_5ghz_ch_freq(v59) )
            {
              v60 = (unsigned __int8)v21;
              LOBYTE(v21) = v21 + 1;
              *(_DWORD *)(a3 + 4 * v60) = v59;
            }
            if ( v72 <= (unsigned int)++v58 )
              goto LABEL_74;
          }
          goto LABEL_76;
        }
      }
      else
      {
        if ( a2 != 7 )
          goto LABEL_43;
        qdf_trace_msg(
          0x34u,
          8u,
          "%s: WIFI_BAND_ABG_WITH_DFS (2.4 GHz+5 GHz with DFS)",
          v8,
          v9,
          v10,
          v11,
          v12,
          v13,
          v14,
          v15,
          "sme_get_valid_channels_by_band");
        if ( v72 )
        {
          v43 = 0;
          LOBYTE(v21) = 0;
          while ( v43 != 100 )
          {
            v45 = s[v43];
            if ( wlan_reg_is_24ghz_ch_freq(v45) || wlan_reg_is_5ghz_ch_freq(v45) )
            {
              v44 = (unsigned __int8)v21;
              LOBYTE(v21) = v21 + 1;
              *(_DWORD *)(a3 + 4 * v44) = v45;
            }
            if ( v72 <= (unsigned int)++v43 )
              goto LABEL_74;
          }
          goto LABEL_76;
        }
      }
    }
    else
    {
      if ( a2 != 3 )
      {
        if ( a2 == 4 )
        {
          qdf_trace_msg(
            0x34u,
            8u,
            "%s: WIFI_BAND_A_DFS (5 GHz DFS only)",
            v8,
            v9,
            v10,
            v11,
            v12,
            v13,
            v14,
            v15,
            "sme_get_valid_channels_by_band");
          if ( v72 )
          {
            v20 = 0;
            LOBYTE(v21) = 0;
            while ( v20 != 100 )
            {
              v22 = s[v20];
              if ( wlan_reg_is_5ghz_ch_freq(v22)
                && (wlan_reg_is_dfs_for_freq(*(_QWORD *)(a1 + 21632), v22, v23, v24, v25, v26, v27, v28, v29, v30) & 1) != 0 )
              {
                v31 = (unsigned __int8)v21;
                LOBYTE(v21) = v21 + 1;
                *(_DWORD *)(a3 + 4 * v31) = v22;
              }
              if ( v72 <= (unsigned int)++v20 )
                goto LABEL_74;
            }
            goto LABEL_76;
          }
          goto LABEL_64;
        }
LABEL_43:
        v16 = "%s: Unknown wifi Band: %d";
        goto LABEL_5;
      }
      qdf_trace_msg(
        0x34u,
        8u,
        "%s: WIFI_BAND_ABG (2.4 GHz + 5 GHz; no DFS)",
        v8,
        v9,
        v10,
        v11,
        v12,
        v13,
        v14,
        v15,
        "sme_get_valid_channels_by_band");
      if ( v72 )
      {
        v47 = 0;
        LOBYTE(v21) = 0;
        while ( v47 != 100 )
        {
          v48 = s[v47];
          if ( (wlan_reg_is_24ghz_ch_freq(v48) || wlan_reg_is_5ghz_ch_freq(v48))
            && (wlan_reg_is_dfs_for_freq(*(_QWORD *)(a1 + 21632), v48, v49, v50, v51, v52, v53, v54, v55, v56) & 1) == 0 )
          {
            v57 = (unsigned __int8)v21;
            LOBYTE(v21) = v21 + 1;
            *(_DWORD *)(a3 + 4 * v57) = v48;
          }
          if ( v72 <= (unsigned int)++v47 )
            goto LABEL_74;
        }
        goto LABEL_76;
      }
    }
LABEL_64:
    LOBYTE(v21) = 0;
    goto LABEL_74;
  }
  v16 = "%s: Invalid wifi Band: %d";
LABEL_5:
  qdf_trace_msg(0x34u, 2u, v16, v8, v9, v10, v11, v12, v13, v14, v15, "sme_get_valid_channels_by_band", a2);
  result = 4;
LABEL_75:
  _ReadStatusReg(SP_EL0);
  return result;
}
