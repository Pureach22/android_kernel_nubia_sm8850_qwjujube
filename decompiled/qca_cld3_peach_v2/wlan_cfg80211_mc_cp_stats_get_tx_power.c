__int64 __fastcall wlan_cfg80211_mc_cp_stats_get_tx_power(__int64 a1, _DWORD *a2)
{
  __int64 v4; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x19
  __int64 v14; // x0
  __int64 v15; // x9
  unsigned int v16; // w10
  __int64 bsspeer; // x0
  __int64 v18; // x22
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  unsigned int v35; // w0
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  unsigned int v44; // w22
  unsigned int v45; // w22
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  unsigned int tx_power; // w0
  double v55; // d0
  double v56; // d1
  double v57; // d2
  double v58; // d3
  double v59; // d4
  double v60; // d5
  double v61; // d6
  double v62; // d7
  unsigned int v63; // w20
  unsigned int v65; // w0
  double v66; // d0
  double v67; // d1
  double v68; // d2
  double v69; // d3
  double v70; // d4
  double v71; // d5
  double v72; // d6
  double v73; // d7
  _DWORD *v74; // x0
  __int64 v75; // [xsp+8h] [xbp-38h] BYREF
  __int64 (__fastcall *v76)(); // [xsp+10h] [xbp-30h]
  unsigned __int64 v77; // [xsp+18h] [xbp-28h]
  _QWORD v78[4]; // [xsp+20h] [xbp-20h] BYREF

  v78[3] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v77 = 0;
  memset(v78, 0, 24);
  v75 = 0;
  v76 = nullptr;
  v4 = osif_request_alloc(wlan_cfg80211_mc_cp_stats_get_tx_power_params);
  v13 = v4;
  if ( !v4 )
  {
    qdf_trace_msg(
      0x48u,
      2u,
      "%s: Request allocation failure, return cached value",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "wlan_cfg80211_mc_cp_stats_get_tx_power");
    v45 = 0;
    goto LABEL_6;
  }
  v14 = osif_request_cookie(v4);
  v15 = *(_QWORD *)(a1 + 216);
  v16 = *(unsigned __int8 *)(a1 + 168);
  v75 = v14;
  v76 = get_tx_power_cb;
  v77 = __PAIR64__(*(unsigned __int8 *)(v15 + 40), v16);
  bsspeer = wlan_objmgr_vdev_try_get_bsspeer(a1, 0x26u);
  if ( !bsspeer )
  {
    v45 = -22;
LABEL_11:
    osif_request_put(v13);
    goto LABEL_12;
  }
  v18 = bsspeer;
  qdf_mem_copy(v78, (const void *)(bsspeer + 48), 6u);
  wlan_objmgr_peer_release_ref(v18, 0x26u, v19, v20, v21, v22, v23, v24, v25, v26);
  v35 = ucfg_mc_cp_stats_send_stats_request(a1, 0, (__int64)&v75, v27, v28, v29, v30, v31, v32, v33, v34);
  if ( v35 )
  {
    v44 = v35;
    qdf_trace_msg(
      0x48u,
      2u,
      "%s: wlan_mc_cp_stats_request_tx_power status: %d",
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      v42,
      v43,
      "wlan_cfg80211_mc_cp_stats_get_tx_power",
      v35);
    v45 = qdf_status_to_os_return(v44);
    goto LABEL_6;
  }
  v65 = osif_request_wait_for_response(v13);
  if ( v65 )
  {
    v45 = v65;
    qdf_trace_msg(
      0x48u,
      2u,
      "%s: wait failed or timed out ret: %d",
      v66,
      v67,
      v68,
      v69,
      v70,
      v71,
      v72,
      v73,
      "wlan_cfg80211_mc_cp_stats_get_tx_power",
      v65);
    goto LABEL_6;
  }
  v74 = (_DWORD *)osif_request_priv(v13);
  v45 = 0;
  if ( v74 )
  {
    *a2 = *v74;
    goto LABEL_11;
  }
LABEL_6:
  tx_power = ucfg_mc_cp_stats_get_tx_power(a1, a2, v46, v47, v48, v49, v50, v51, v52, v53);
  if ( tx_power )
  {
    v63 = tx_power;
    qdf_trace_msg(
      0x48u,
      2u,
      "%s: ucfg_mc_cp_stats_get_tx_power status: %d",
      v55,
      v56,
      v57,
      v58,
      v59,
      v60,
      v61,
      v62,
      "wlan_cfg80211_mc_cp_stats_get_tx_power",
      tx_power);
    v45 = qdf_status_to_os_return(v63);
  }
  if ( v13 )
    goto LABEL_11;
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return v45;
}
