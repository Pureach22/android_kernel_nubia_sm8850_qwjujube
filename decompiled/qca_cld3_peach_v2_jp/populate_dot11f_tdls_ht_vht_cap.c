__int64 __fastcall populate_dot11f_tdls_ht_vht_cap(
        __int64 a1,
        int a2,
        unsigned __int8 *a3,
        unsigned __int8 *a4,
        __int64 a5)
{
  __int64 v10; // x0
  int is_fw_wideband_capable; // w0
  __int64 v12; // x25
  int v13; // w24
  bool is_24ghz_ch_freq; // w0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x8
  unsigned int v24; // w8
  unsigned int v25; // w26
  __int64 v26; // x9
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  __int16 v35; // w8
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  __int64 v44; // x0
  __int64 v45; // x1
  __int64 v46; // x2
  __int64 v47; // x3
  unsigned __int8 v48; // w9
  __int64 v49; // x12
  __int16 v50; // w8
  int v51; // w15
  __int16 v52; // w11
  __int16 v53; // w9
  __int16 v54; // w10
  __int16 v55; // w13
  __int64 v56; // x4
  __int16 v57; // w10
  __int64 result; // x0
  size_t v59; // [xsp+0h] [xbp-10h] BYREF
  __int64 v60; // [xsp+8h] [xbp-8h]

  v60 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(_QWORD *)(a5 + 16);
  v59 = 0;
  is_fw_wideband_capable = wlan_cfg80211_tdls_is_fw_wideband_capable(v10);
  v12 = *(_QWORD *)(a1 + 8);
  v13 = is_fw_wideband_capable;
  is_24ghz_ch_freq = wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(a5 + 284));
  v23 = 21528;
  if ( is_24ghz_ch_freq )
    v23 = 21518;
  v24 = *(unsigned __int8 *)(a1 + v23);
  if ( v24 >= *(unsigned __int8 *)(a1 + 21596) )
    v25 = *(unsigned __int8 *)(a1 + 21596);
  else
    v25 = v24;
  if ( (unsigned int)(a2 - 7) >= 7 && a2 != 5 && a2 || (*(_BYTE *)(a5 + 8764) & 1) != 0 )
  {
    *a3 = 0;
    goto LABEL_18;
  }
  populate_dot11f_ht_caps((_QWORD *)a1, a5, (__int64)a3, v15, v16, v17, v18, v19, v20, v21, v22);
  v26 = *(_QWORD *)(a1 + 8);
  v59 = 16;
  wlan_mlme_get_cfg_str(a3 + 4, v26 + 2856, &v59, v27, v28, v29, v30, v31, v32, v33, v34);
  if ( !wlan_reg_is_5ghz_ch_freq(*(_DWORD *)(a5 + 284))
    || (wlan_reg_is_dfs_for_freq(*(_QWORD *)(a1 + 21560), *(_DWORD *)(a5 + 284), v15, v16, v17, v18, v19, v20, v21, v22)
      & 1) != 0
    || ((v13 ^ 1) & 1) != 0 )
  {
    if ( *(_DWORD *)(a5 + 7176) )
      goto LABEL_16;
    v35 = *(_WORD *)(a3 + 1) & 0xFFFD;
  }
  else
  {
    v35 = *(_WORD *)(a3 + 1) | 2;
  }
  *(_WORD *)(a3 + 1) = v35;
LABEL_16:
  if ( v25 == 1 )
    a3[5] = 0;
LABEL_18:
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: HT present: %hu, Chan Width: %hu",
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    "populate_dot11f_tdls_ht_vht_cap",
    *a3,
    (*(unsigned __int16 *)(a3 + 1) >> 1) & 1,
    v59,
    v60);
  if ( (!wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(a5 + 284)) || (*(_BYTE *)(v12 + 2671) & 1) == 0)
    && !wlan_reg_is_5ghz_ch_freq(*(_DWORD *)(a5 + 284))
    || (unsigned int)(a2 - 8) >= 6 && a2
    || (wma_get_fw_wlan_feat_caps(2) & 1) == 0 )
  {
    v56 = 0;
    *a4 = 0;
    goto LABEL_33;
  }
  v44 = populate_dot11f_vht_caps(a1, a5, (__int64)a4, v36, v37, v38, v39, v40, v41, v42, v43);
  v48 = a4[3] & 0xE7;
  v49 = -1LL << (2 * (unsigned __int8)v25);
  *(_WORD *)(a4 + 1) &= 0xE7FFu;
  v50 = *((_WORD *)a4 + 4);
  if ( v25 >= 2 )
    v51 = 2;
  else
    v51 = v25;
  a4[3] = v48;
  v52 = *(_WORD *)(v12 + 2632);
  *((_WORD *)a4 + 3) = v52;
  v53 = *((_WORD *)a4 + 6);
  *((_WORD *)a4 + 4) = v50 & 0xE000 | *(_WORD *)(v12 + 2640) & 0x1FFF;
  v54 = *(_WORD *)(v12 + 2636);
  *((_WORD *)a4 + 5) = v54;
  v55 = *(_WORD *)(v12 + 2644);
  *((_WORD *)a4 + 5) = v54 | v49;
  *((_WORD *)a4 + 3) = v52 | v49;
  *((_WORD *)a4 + 6) = v53 & 0xE000 | v55 & 0x1FFF;
  if ( (unsigned int)(v51 - 1) <= 3 )
  {
    v56 = *a4;
    v57 = vht_supported_datarate_bw80_gi400ns[v51 - 1] & 0x1FFF;
    *((_WORD *)a4 + 6) = v57 | v53 & 0xE000;
    *((_WORD *)a4 + 4) = v57 | v50 & 0xE000;
LABEL_33:
    result = qdf_trace_msg(
               0x35u,
               8u,
               "%s: VHT present: %hu, Chan Width: %u",
               v36,
               v37,
               v38,
               v39,
               v40,
               v41,
               v42,
               v43,
               "populate_dot11f_tdls_ht_vht_cap",
               v56,
               (*(unsigned __int16 *)(a4 + 1) >> 2) & 3);
    _ReadStatusReg(SP_EL0);
    return result;
  }
  __break(0x5512u);
  return populate_dot11f_tdls_offchannel_params(v44, v45, v46, v47);
}
