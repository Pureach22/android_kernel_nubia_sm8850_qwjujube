__int64 __fastcall csr_roam_get_phy_mode_band_for_bss(__int64 a1, __int64 a2)
{
  unsigned __int8 v2; // w23
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
  int v36; // w8
  _BOOL4 v37; // w8
  int v38; // [xsp+8h] [xbp-8h]

  v2 = *(_BYTE *)a2;
  v4 = *(_DWORD *)(a1 + 17132);
  v6 = *(_DWORD *)(a2 + 8);
  v7 = wlan_get_opmode_from_vdev_id(*(_QWORD *)(a1 + 21560), *(_BYTE *)a2) & 0xFFFFFFFD;
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
        goto LABEL_46;
      }
      goto LABEL_42;
    }
  }
  v14 = *(_QWORD *)(a1 + 8);
  v10 = *(_DWORD *)(a1 + 17132);
  v15 = *(_BYTE *)(v14 + 2671);
  if ( v10 <= 7 )
  {
    if ( v10 <= 2 )
    {
      if ( v10 == 1 )
      {
        v16 = 1;
        goto LABEL_43;
      }
      if ( v10 != 2 )
        goto LABEL_61;
    }
    else if ( v10 != 3 )
    {
      if ( v10 != 4 )
      {
        if ( v10 != 5 )
          goto LABEL_61;
        goto LABEL_34;
      }
LABEL_42:
      v16 = wlan_reg_freq_to_band(v6);
      goto LABEL_43;
    }
    v16 = 0;
    goto LABEL_43;
  }
  if ( (unsigned int)(v10 - 10) < 2 )
  {
    if ( (wma_get_fw_wlan_feat_caps(13) & 1) != 0 )
    {
      v10 = *(_DWORD *)(a1 + 17132);
      goto LABEL_42;
    }
    goto LABEL_34;
  }
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
    goto LABEL_42;
  }
  if ( v10 == 9 )
  {
    if ( (wma_get_fw_wlan_feat_caps(13) & 1) != 0 )
    {
      v10 = 10;
      goto LABEL_42;
    }
LABEL_34:
    v10 = 4;
    if ( (wma_get_fw_wlan_feat_caps(2) & 1) != 0 )
    {
      if ( v15 & 1 | !wlan_reg_is_24ghz_ch_freq(v6) )
        v10 = 5;
      else
        v10 = 4;
    }
    goto LABEL_42;
  }
LABEL_61:
  if ( !v6 )
  {
    v36 = *(_DWORD *)(v14 + 1036);
    v11 = v36 == 1;
    v37 = v36 != 1;
    if ( v11 )
      v10 = 2;
    else
      v10 = 1;
    *(_DWORD *)(a2 + 20) = v37;
    goto LABEL_46;
  }
  v11 = !wlan_reg_is_24ghz_ch_freq(v6);
  v16 = v11;
  if ( v11 )
    v10 = 1;
  else
    v10 = 2;
LABEL_43:
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
LABEL_46:
  if ( wlan_reg_is_24ghz_ch_freq(v6) && (*(_BYTE *)(*(_QWORD *)(a1 + 8) + 2671LL) & 1) == 0 && (v10 == 8 || v10 == 5) )
    v10 = 4;
  is_11n_allowed = wlan_vdev_id_is_11n_allowed(*(_QWORD *)(a1 + 21560), v2);
  if ( ((is_11n_allowed & 1) == 0 || v9 && wlan_vdev_id_is_open_cipher(*(_QWORD *)(a1 + 21560), v2))
    && (unsigned int)v10 <= 0xA
    && ((1 << v10) & 0x430) != 0 )
  {
    if ( wlan_reg_is_24ghz_ch_freq(v6) )
      v10 = 3;
    else
      v10 = 1;
  }
  v26 = *(_DWORD *)(a2 + 4);
  v38 = wma_get_fw_wlan_feat_caps(13) & 1;
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
    v38);
  return (unsigned int)v10;
}
