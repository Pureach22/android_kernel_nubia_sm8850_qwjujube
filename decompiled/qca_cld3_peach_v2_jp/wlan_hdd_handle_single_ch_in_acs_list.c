__int64 __fastcall wlan_hdd_handle_single_ch_in_acs_list(__int64 a1)
{
  __int64 v2; // x8
  __int64 *v3; // x20
  unsigned int *v4; // x8
  unsigned int v5; // w9
  unsigned int v6; // w21
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  double v15; // d0
  unsigned int v16; // w1
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  char v40; // w0
  int v41; // w8
  int v42; // w9
  __int64 result; // x0
  int v44; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v45; // [xsp+8h] [xbp-8h]

  v45 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)a1;
  v44 = 0;
  v3 = *(__int64 **)(v2 + 24);
  ucfg_mlme_get_channel_bonding_24ghz(*v3, &v44);
  v4 = *(unsigned int **)(a1 + 1432);
  v5 = *v4;
  *(_DWORD *)(a1 + 1424) = *v4;
  *(_DWORD *)(a1 + 1428) = v5;
  v6 = *v4;
  *(_DWORD *)(a1 + 1980) = *v4;
  if ( v6 <= (unsigned int)wlan_reg_ch_to_freq(0xDu) && *(_WORD *)(a1 + 1458) && !v44 )
  {
    *(_WORD *)(a1 + 1458) = 0;
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: 2.4ghz channel resetting BW to %d 2.4 cbmode %d",
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      "wlan_hdd_handle_single_ch_in_acs_list",
      0,
      0);
  }
  wlan_sap_set_sap_ctx_acs_cfg(*(_QWORD *)(a1 + 272), a1 + 280);
  v15 = sap_config_acs_result(v3[2], *(_QWORD *)(a1 + 272), *(unsigned int *)(a1 + 1984));
  v16 = *(_DWORD *)(a1 + 1984);
  *(_DWORD *)(a1 + 728) = *(unsigned __int16 *)(a1 + 1458);
  *(_BYTE *)(a1 + 732) = wlan_reg_freq_to_chan(v3[1], v16, v15, v17, v18, v19, v20, v21, v22, v23);
  *(_BYTE *)(a1 + 733) = wlan_reg_freq_to_chan(v3[1], *(_DWORD *)(a1 + 1988), v24, v25, v26, v27, v28, v29, v30, v31);
  v40 = wlan_reg_freq_to_chan(v3[1], *(_DWORD *)(a1 + 1992), v32, v33, v34, v35, v36, v37, v38, v39);
  v41 = *(_DWORD *)(a1 + 1988);
  v42 = *(_DWORD *)(a1 + 1992);
  *(_BYTE *)(a1 + 734) = v40;
  *(_DWORD *)(a1 + 736) = v41;
  *(_DWORD *)(a1 + 740) = v42;
  wlan_hdd_cfg80211_acs_ch_select_evt((__int64 *)a1, 1);
  result = ((__int64 (__fastcall *)(_QWORD, __int64))wlansap_dcs_set_wlan_interference_mitigation_on_band)(
             *(_QWORD *)(a1 + 272),
             a1 + 280);
  _ReadStatusReg(SP_EL0);
  return result;
}
