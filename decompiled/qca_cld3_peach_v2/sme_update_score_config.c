void *__fastcall sme_update_score_config(__int64 a1, int a2, unsigned __int8 a3)
{
  __int64 v6; // x0
  _BOOL4 v7; // w23
  __int16 v8; // w22
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  char fw_wlan_feat_caps; // w20
  char v18; // w21
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  char v27; // w23
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  __int16 v36; // w8
  __int16 v37; // w9
  __int16 v38; // w20
  __int16 v39; // w20
  __int16 v40; // w21
  __int16 v41; // w21
  bool v42; // zf
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  __int64 v51; // x0
  __int16 v52; // w8
  void *result; // x0
  bool v54; // [xsp+0h] [xbp-50h] BYREF
  int v55; // [xsp+4h] [xbp-4Ch] BYREF
  int v56; // [xsp+8h] [xbp-48h] BYREF
  _BYTE v57[4]; // [xsp+Ch] [xbp-44h] BYREF
  _QWORD v58[3]; // [xsp+10h] [xbp-40h] BYREF
  __int64 v59; // [xsp+28h] [xbp-28h]
  __int64 v60; // [xsp+30h] [xbp-20h]
  __int64 v61; // [xsp+38h] [xbp-18h]
  __int64 v62; // [xsp+40h] [xbp-10h]
  __int64 v63; // [xsp+48h] [xbp-8h]

  v63 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)(a1 + 21624);
  v61 = 0;
  v62 = 0;
  v59 = 0;
  v60 = 0;
  memset(v58, 0, sizeof(v58));
  v57[0] = 0;
  v55 = 0;
  v56 = 0;
  v54 = 0;
  ucfg_psoc_mlme_get_11be_capab(v6, &v54);
  v7 = v54;
  v8 = 8 * v54;
  qdf_mem_set(v58, 0x38u, 0);
  sme_populate_nss_chain_params(a1, (__int64)v58, 0, a3, v9, v10, v11, v12, v13, v14, v15, v16);
  LOBYTE(v55) = v59;
  BYTE1(v55) = BYTE4(v59);
  if ( v7 || a2 == 1024 || a2 == 4096 || a2 == 2048 )
    v8 |= 4u;
  if ( (v8 & 4) != 0 || a2 == 512 || a2 == 256 )
    v8 |= 2u;
  if ( (v8 & 2) != 0 || a2 == 64 || a2 == 16 )
  {
    v8 |= 1u;
    HIWORD(v55) = v8;
  }
  fw_wlan_feat_caps = wma_get_fw_wlan_feat_caps(13);
  v18 = wma_get_fw_wlan_feat_caps(2);
  if ( (unsigned int)wlan_mlme_get_vht_for_24ghz(*(_QWORD *)(a1 + 21624), v57) )
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: Failed to get vht_for_24ghz",
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      "sme_update_score_config");
  v27 = v57[0];
  if ( (unsigned int)wlan_mlme_get_vht_enable_tx_bf(*(_QWORD *)(a1 + 21624), v57) )
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: unable to get vht_enable_tx_bf",
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      "sme_update_score_config");
  v36 = v8 & 0xFFFB;
  if ( (fw_wlan_feat_caps & 1) != 0 )
    v36 = v8;
  if ( (v18 & 1) == 0 )
    v36 &= ~2u;
  v37 = v36 | 0x10;
  if ( (v27 & 1) == 0 )
    v37 = v36;
  if ( (v36 & 2) != 0 )
    v36 = v37;
  if ( v57[0] )
    v38 = v36 | 0x20;
  else
    v38 = v36;
  ucfg_mlme_get_channel_bonding_24ghz(*(_QWORD *)(a1 + 21624), &v56);
  v39 = v38 & 0xFE3F;
  v40 = (v56 & 1) << 7;
  ucfg_mlme_get_channel_bonding_5ghz(*(_QWORD *)(a1 + 21624), &v56);
  v41 = ((v56 & 1) << 6) | v40;
  v42 = (mlme_max_chan_switch_is_set(*(_QWORD *)(a1 + 21624)) & 1) == 0;
  v51 = *(_QWORD *)(a1 + 21624);
  if ( v42 )
    v52 = 0;
  else
    v52 = 256;
  HIWORD(v55) = v41 | v52 | v39;
  result = wlan_psoc_set_phy_config(v51, &v55, v43, v44, v45, v46, v47, v48, v49, v50);
  _ReadStatusReg(SP_EL0);
  return result;
}
