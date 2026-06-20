__int64 __fastcall csr_roam_get_phy_mode_band_for_bss(__int64 a1, __int64 a2)
{
  char v2; // w23
  int v4; // w25
  unsigned int v6; // w19
  int v7; // w21
  int cfg_dot11_mode_from_csr_phy_mode; // w0
  unsigned int v9; // w21
  int v10; // w24
  bool v11; // zf
  __int64 v14; // x8
  char v15; // w25
  int v16; // w0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  char is_11n_allowed; // w25
  unsigned int v26; // w20
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  char fw_wlan_feat_caps; // w0
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  int v45; // w8
  _BOOL4 v46; // w8
  int v47; // [xsp+8h] [xbp-8h]

  v2 = *(_BYTE *)a2;
  v4 = *(_DWORD *)(a1 + 17204);
  v6 = *(_DWORD *)(a2 + 8);
  v7 = wlan_get_opmode_from_vdev_id(*(_QWORD *)(a1 + 21632), *(_BYTE *)a2) & 0xFFFFFFFD;
  cfg_dot11_mode_from_csr_phy_mode = csr_get_cfg_dot11_mode_from_csr_phy_mode(v7 == 1);
  v11 = v7 == 1;
  v9 = *(unsigned __int8 *)(a2 + 1);
  v10 = cfg_dot11_mode_from_csr_phy_mode;
  if ( v11 )
  {
    if ( cfg_dot11_mode_from_csr_phy_mode && cfg_dot11_mode_from_csr_phy_mode != 9 )
      goto LABEL_5;
  }
  else
  {
    v11 = cfg_dot11_mode_from_csr_phy_mode == 9 || v4 == 0;
    if ( !v11 && v4 != 9 && cfg_dot11_mode_from_csr_phy_mode != 0 )
    {
LABEL_5:
      if ( !v6 )
      {
        *(_DWORD *)(a2 + 20) = *(_DWORD *)(*(_QWORD *)(a1 + 8) + 1036LL) == 0;
        goto LABEL_51;
      }
      goto LABEL_47;
    }
  }
  v14 = *(_QWORD *)(a1 + 8);
  v10 = *(_DWORD *)(a1 + 17204);
  v15 = *(_BYTE *)(v14 + 2875);
  if ( v10 > 7 )
  {
    if ( v10 <= 11 )
    {
      if ( (unsigned int)(v10 - 10) >= 2 )
      {
        if ( v10 == 8 )
        {
          v10 = 4;
          if ( (wma_get_fw_wlan_feat_caps(2) & 1) != 0 )
          {
            if ( v15 & 1 | !wlan_reg_is_24ghz_ch_freq(v6) )
              v10 = 8;
            else
              v10 = 4;
          }
          goto LABEL_47;
        }
        if ( (wma_get_fw_wlan_feat_caps(14) & 1) != 0 )
        {
          v10 = 12;
LABEL_47:
          v16 = wlan_reg_freq_to_band(v6);
          goto LABEL_48;
        }
        goto LABEL_34;
      }
      if ( (wma_get_fw_wlan_feat_caps(13) & 1) == 0 )
        goto LABEL_38;
      goto LABEL_37;
    }
    if ( (unsigned int)(v10 - 12) < 2 )
    {
      if ( (wma_get_fw_wlan_feat_caps(14) & 1) == 0 )
      {
LABEL_34:
        if ( (wma_get_fw_wlan_feat_caps(13) & 1) != 0 )
        {
          v10 = 10;
          goto LABEL_47;
        }
        goto LABEL_38;
      }
LABEL_37:
      v10 = *(_DWORD *)(a1 + 17204);
      goto LABEL_47;
    }
    goto LABEL_65;
  }
  if ( v10 <= 2 )
  {
    if ( v10 == 1 )
    {
      v16 = 1;
      goto LABEL_48;
    }
    if ( v10 != 2 )
      goto LABEL_65;
LABEL_31:
    v16 = 0;
    goto LABEL_48;
  }
  switch ( v10 )
  {
    case 3:
      goto LABEL_31;
    case 4:
      goto LABEL_47;
    case 5:
LABEL_38:
      v10 = 4;
      if ( (wma_get_fw_wlan_feat_caps(2) & 1) != 0 )
      {
        if ( v15 & 1 | !wlan_reg_is_24ghz_ch_freq(v6) )
          v10 = 5;
        else
          v10 = 4;
      }
      goto LABEL_47;
  }
LABEL_65:
  if ( !v6 )
  {
    v45 = *(_DWORD *)(v14 + 1036);
    v11 = v45 == 1;
    v46 = v45 != 1;
    if ( v11 )
      v10 = 2;
    else
      v10 = 1;
    *(_DWORD *)(a2 + 20) = v46;
    goto LABEL_51;
  }
  v11 = !wlan_reg_is_24ghz_ch_freq(v6);
  v16 = v11;
  if ( v11 )
    v10 = 1;
  else
    v10 = 2;
LABEL_48:
  *(_DWORD *)(a2 + 20) = v16;
  if ( v6 == 2484 && wlan_reg_is_24ghz_ch_freq(0x9B4u) )
  {
    v10 = 2;
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: Switching to Dot11B mode",
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      "csr_roam_get_phy_mode_band_for_bss");
  }
LABEL_51:
  if ( wlan_reg_is_24ghz_ch_freq(v6) && (*(_BYTE *)(*(_QWORD *)(a1 + 8) + 2875LL) & 1) == 0 && (v10 == 8 || v10 == 5) )
    v10 = 4;
  is_11n_allowed = wlan_vdev_id_is_11n_allowed(*(_QWORD *)(a1 + 21632), v2);
  if ( ((is_11n_allowed & 1) == 0 || v9 && wlan_vdev_id_is_open_cipher(*(_QWORD *)(a1 + 21632), v2))
    && (unsigned int)v10 <= 0xC
    && ((1 << v10) & 0x1430) != 0 )
  {
    if ( wlan_reg_is_24ghz_ch_freq(v6) )
      v10 = 3;
    else
      v10 = 1;
  }
  v26 = *(_DWORD *)(a2 + 4);
  v47 = wma_get_fw_wlan_feat_caps(13) & 1;
  qdf_trace_msg(
    0x34u,
    8u,
    "%s: dot11mode: %d phyMode %d is_11n_allowed %d privacy %d chan freq %d fw sup AX %d",
    v27,
    v28,
    v29,
    v30,
    v31,
    v32,
    v33,
    v34,
    "csr_roam_get_phy_mode_band_for_bss",
    (unsigned int)v10,
    v26,
    is_11n_allowed & 1,
    v9,
    v6,
    v47);
  fw_wlan_feat_caps = wma_get_fw_wlan_feat_caps(14);
  qdf_trace_msg(
    0x34u,
    8u,
    "%s: BE :%d",
    v36,
    v37,
    v38,
    v39,
    v40,
    v41,
    v42,
    v43,
    "csr_roam_get_phy_mode_band_for_bss",
    fw_wlan_feat_caps & 1);
  return (unsigned int)v10;
}
