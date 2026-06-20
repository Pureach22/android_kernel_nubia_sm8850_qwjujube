__int64 __fastcall hdd_update_tgt_services(__int64 *a1, __int64 a2)
{
  _DWORD *v4; // x21
  __int64 v5; // x0
  char v6; // w1
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  int is_arp_offload_enabled; // w0
  __int64 v16; // x21
  unsigned int v17; // w22
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  char v34; // w8
  char v35; // w8
  _BOOL8 v36; // x1
  __int64 v37; // x0
  __int64 v38; // x0
  char v39; // w8
  char v40; // w8
  __int64 v41; // x0
  char v42; // w8
  __int64 v43; // x0
  __int64 result; // x0
  char v45[4]; // [xsp+0h] [xbp-20h] BYREF
  int v46; // [xsp+4h] [xbp-1Ch] BYREF
  _BYTE v47[4]; // [xsp+8h] [xbp-18h] BYREF
  _BYTE v48[4]; // [xsp+Ch] [xbp-14h] BYREF
  _BYTE v49[4]; // [xsp+10h] [xbp-10h] BYREF
  char v50[4]; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v51; // [xsp+18h] [xbp-8h]

  v51 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = (_DWORD *)a1[13];
  v5 = *a1;
  v6 = *(_BYTE *)(a2 + 4);
  v49[0] = 0;
  v48[0] = 0;
  v47[0] = 0;
  v46 = 0;
  v45[0] = 0;
  wlan_mlme_set_sap_uapsd_flag(v5, v6);
  if ( (unsigned int)(*v4 - 11) <= 1 && (*(_BYTE *)(a2 + 40) & 1) == 0 )
  {
    *v4 = 9;
    if ( *(_DWORD *)(a2 + 12) )
      goto LABEL_5;
    goto LABEL_32;
  }
  if ( (*v4 & 0xFFFFFFFE) == 8 && !*(_DWORD *)(a2 + 12) )
LABEL_32:
    *v4 = 0;
LABEL_5:
  if ( *(_BYTE *)(a2 + 54) == 1 )
  {
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: dot11Mode %d override target en_11be to false",
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      "hdd_update_tgt_services");
    *(_BYTE *)(a2 + 54) = 0;
  }
  is_arp_offload_enabled = ucfg_pmo_is_arp_offload_enabled(*a1);
  ucfg_pmo_set_arp_offload_enabled(*a1, is_arp_offload_enabled & *(_DWORD *)(a2 + 16) & 1);
  v16 = *a1;
  v17 = ucfg_pmo_is_igmp_offload_enabled(*a1) & 1;
  ucfg_pmo_set_igmp_offload_enabled(v16, *(_BYTE *)(a2 + 53) & v17);
  qdf_trace_msg(
    0x33u,
    4u,
    "%s: fw cap to handle igmp %d igmp_offload_enable ini %d",
    v18,
    v19,
    v20,
    v21,
    v22,
    v23,
    v24,
    v25,
    "hdd_intersect_igmp_offload_setting",
    *(unsigned __int8 *)(a2 + 53),
    v17);
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: PNO Capability in f/w = %d",
    v26,
    v27,
    v28,
    v29,
    v30,
    v31,
    v32,
    v33,
    "hdd_update_tgt_services",
    *(unsigned __int8 *)(a2 + 24));
  if ( *(_BYTE *)(a2 + 24) == 1 )
    ucfg_scan_set_pno_offload(*a1, 1);
  cfg_tdls_set_fw_support(*a1, *(unsigned __int8 *)(a2 + 32));
  cfg_tdls_get_off_channel_enable(*a1, v48);
  if ( v48[0] == 1 )
    v34 = *(_BYTE *)(a2 + 33);
  else
    v34 = 0;
  cfg_tdls_set_off_channel_enable(*a1, v34 & 1);
  cfg_tdls_get_buffer_sta_enable(*a1, v47);
  if ( v47[0] == 1 )
    v35 = *(_BYTE *)(a2 + 34);
  else
    v35 = 0;
  cfg_tdls_set_buffer_sta_enable(*a1, v35 & 1);
  cfg_tdls_get_uapsd_mask(*a1, &v46);
  v36 = v46 && (*(_BYTE *)(a2 + 35) & 1) != 0;
  cfg_tdls_set_sleep_sta_enable(*a1, v36);
  v37 = *a1;
  v50[0] = 0;
  ucfg_mlme_get_roaming_offload(v37, v50);
  ucfg_mlme_set_roaming_offload(*a1, *(_BYTE *)(a2 + 39) & v50[0]);
  if ( !(unsigned int)wlan_mlme_get_sap_get_peer_info(*a1, v45) )
  {
    v38 = *a1;
    v45[0] &= *(_BYTE *)(a2 + 41);
    wlan_mlme_set_sap_get_peer_info(v38, v45[0]);
  }
  ucfg_mlme_is_mawc_enabled(*a1, v49);
  ucfg_mlme_set_mawc_enabled(*a1, *(_BYTE *)(a2 + 43) & v49[0]);
  hdd_update_tdls_config(a1);
  sme_update_tgt_services(a1[2], a2);
  *((_BYTE *)a1 + 6776) = *(_BYTE *)(a2 + 49);
  *((_BYTE *)a1 + 6920) = *(_BYTE *)(a2 + 50);
  if ( *(_BYTE *)(a2 + 51) == 1 )
    v39 = *(_BYTE *)(cfg_psoc_get_values(*a1) + 2720);
  else
    v39 = 0;
  *((_BYTE *)a1 + 6921) = v39 & 1;
  if ( *(_BYTE *)(a2 + 52) == 1 )
    v40 = *(_BYTE *)(cfg_psoc_get_values(*a1) + 2524);
  else
    v40 = 0;
  v41 = *a1;
  *((_BYTE *)a1 + 72) = v40 & 1;
  ucfg_tdls_update_fw_11ax_capability(v41, *(unsigned __int8 *)(a2 + 37));
  if ( *(_BYTE *)(a2 + 55) == 1 )
    v42 = *(_BYTE *)(cfg_psoc_get_values(*a1) + 2704);
  else
    v42 = 0;
  v43 = *a1;
  *((_BYTE *)a1 + 7097) = v42 & 1;
  ucfg_update_fw_tdls_6g_capability(v43, *(unsigned __int8 *)(a2 + 38));
  ucfg_tdls_update_fw_wideband_capability(*a1, *(unsigned __int8 *)(a2 + 36));
  result = ucfg_psoc_mlme_set_11be_capab(*a1, *(_BYTE *)(a2 + 54));
  _ReadStatusReg(SP_EL0);
  return result;
}
