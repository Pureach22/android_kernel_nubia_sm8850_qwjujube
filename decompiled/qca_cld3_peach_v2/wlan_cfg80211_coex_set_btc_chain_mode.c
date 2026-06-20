__int64 __fastcall wlan_cfg80211_coex_set_btc_chain_mode(__int64 a1, __int64 a2, unsigned int a3)
{
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  const char *v12; // x2
  const char *v13; // x3
  __int64 result; // x0
  __int64 v15; // x4
  __int64 v16; // x22
  unsigned int v17; // w19
  __int64 v18; // x8
  __int64 *v19; // x20
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  unsigned int btc_chain_mode; // w0
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  __int64 v37; // x4
  const char *v38; // x2
  __int64 v39; // x21
  unsigned int v40; // w0
  unsigned int v41; // w0
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  unsigned int v50; // w23
  __int64 v51; // x5
  __int64 v52; // x21
  unsigned int v53; // w0
  unsigned int v54; // w0
  __int64 v55; // x21
  unsigned int v56; // w0
  unsigned int v57; // w0
  __int64 v58; // x21
  unsigned int v59; // w0
  unsigned int v60; // w0
  __int64 v61; // x21
  unsigned int v62; // w0
  unsigned int v63; // w0
  __int64 v64; // x20
  unsigned int v65; // w0
  unsigned int v66; // w0
  double v67; // d0
  double v68; // d1
  double v69; // d2
  double v70; // d3
  double v71; // d4
  double v72; // d5
  double v73; // d6
  double v74; // d7
  int v75; // [xsp+Ch] [xbp-24h] BYREF
  __int64 v76; // [xsp+10h] [xbp-20h] BYREF
  __int64 v77; // [xsp+18h] [xbp-18h]
  __int64 v78; // [xsp+20h] [xbp-10h]
  __int64 v79; // [xsp+28h] [xbp-8h]

  v79 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v77 = 0;
  v78 = 0;
  v76 = 0;
  if ( !(unsigned int)_nla_parse(&v76, 2, a2, a3, &btc_chain_mode_policy, 31, 0) )
  {
    if ( !v77 )
    {
      v12 = "%s: btc chain mode - no attr mode";
      goto LABEL_3;
    }
    v15 = *(unsigned int *)(v77 + 4);
    if ( (unsigned int)v15 >= 3 )
    {
      qdf_trace_msg(
        0x70u,
        2u,
        "%s: Invalid btc chain mode %d",
        v4,
        v5,
        v6,
        v7,
        v8,
        v9,
        v10,
        v11,
        "wlan_cfg80211_coex_set_btc_chain_mode");
      goto LABEL_5;
    }
    v16 = v78;
    v17 = dword_B2BEC0[v15];
    qdf_trace_msg(
      0x70u,
      8u,
      "%s: vdev_id %u mode %u restart %u",
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      "wlan_cfg80211_coex_set_btc_chain_mode",
      *(unsigned __int8 *)(a1 + 168),
      v17,
      v78 != 0);
    v75 = 0;
    if ( a1 )
    {
      v18 = *(_QWORD *)(a1 + 216);
      if ( v18 )
      {
        v19 = *(__int64 **)(v18 + 80);
        if ( v19 )
        {
          if ( !wlan_objmgr_psoc_get_comp_private_obj(*(_QWORD *)(v18 + 80), 0x21u) )
          {
            qdf_trace_msg(
              0x70u,
              2u,
              "%s: %s:%u, Failed to get coex psoc object",
              v20,
              v21,
              v22,
              v23,
              v24,
              v25,
              v26,
              v27,
              "wlan_psoc_get_coex_obj_fl",
              "__wlan_cfg80211_coex_set_btc_chain_mode",
              74);
            goto LABEL_5;
          }
          btc_chain_mode = ucfg_coex_psoc_get_btc_chain_mode((__int64)v19, &v75, v20, v21, v22, v23, v24, v25, v26, v27);
          if ( btc_chain_mode )
          {
            v37 = btc_chain_mode;
            v38 = "%s: failed to get cur BTC chain mode, status %d";
LABEL_17:
            qdf_trace_msg(
              0x70u,
              2u,
              v38,
              v29,
              v30,
              v31,
              v32,
              v33,
              v34,
              v35,
              v36,
              "__wlan_cfg80211_coex_set_btc_chain_mode",
              v37);
            result = 4294967282LL;
            goto LABEL_6;
          }
          if ( v75 == v17 )
          {
            result = 4294967182LL;
            goto LABEL_6;
          }
          if ( (unsigned int)ucfg_coex_psoc_set_btc_chain_mode((__int64)v19, v17) )
          {
            v38 = "%s: unable to set BTC chain mode to %d";
            v37 = v17;
            goto LABEL_17;
          }
          v39 = v19[9];
          if ( v39 )
          {
            v40 = ucfg_coex_send_btc_chain_mode(v29, v30, v31, v32, v33, v34, v35, v36, v19[9], v17);
            v41 = qdf_status_to_os_return(v40);
            if ( v41 )
            {
              v50 = v41;
              v51 = 0;
LABEL_54:
              qdf_trace_msg(
                0x70u,
                2u,
                "%s: Failed to set btc chain mode to %d for vdev %d",
                v42,
                v43,
                v44,
                v45,
                v46,
                v47,
                v48,
                v49,
                "__wlan_cfg80211_coex_set_btc_chain_mode",
                v17,
                v51);
              result = v50;
              goto LABEL_6;
            }
            qdf_trace_msg(
              0x70u,
              8u,
              "%s: Set btc chain mode to %d for vdev %d",
              v42,
              v43,
              v44,
              v45,
              v46,
              v47,
              v48,
              v49,
              "__wlan_cfg80211_coex_set_btc_chain_mode",
              v17,
              0);
            if ( v16 )
              wlan_coex_config_updated(v39, 0, v29, v30, v31, v32, v33, v34, v35, v36);
          }
          v52 = v19[10];
          if ( v52 )
          {
            v53 = ucfg_coex_send_btc_chain_mode(v29, v30, v31, v32, v33, v34, v35, v36, v19[10], v17);
            v54 = qdf_status_to_os_return(v53);
            if ( v54 )
            {
              v50 = v54;
              v51 = 1;
              goto LABEL_54;
            }
            qdf_trace_msg(
              0x70u,
              8u,
              "%s: Set btc chain mode to %d for vdev %d",
              v42,
              v43,
              v44,
              v45,
              v46,
              v47,
              v48,
              v49,
              "__wlan_cfg80211_coex_set_btc_chain_mode",
              v17,
              1);
            if ( v16 )
              wlan_coex_config_updated(v52, 0, v29, v30, v31, v32, v33, v34, v35, v36);
          }
          v55 = v19[11];
          if ( v55 )
          {
            v56 = ucfg_coex_send_btc_chain_mode(v29, v30, v31, v32, v33, v34, v35, v36, v19[11], v17);
            v57 = qdf_status_to_os_return(v56);
            if ( v57 )
            {
              v50 = v57;
              v51 = 2;
              goto LABEL_54;
            }
            qdf_trace_msg(
              0x70u,
              8u,
              "%s: Set btc chain mode to %d for vdev %d",
              v42,
              v43,
              v44,
              v45,
              v46,
              v47,
              v48,
              v49,
              "__wlan_cfg80211_coex_set_btc_chain_mode",
              v17,
              2);
            if ( v16 )
              wlan_coex_config_updated(v55, 0, v29, v30, v31, v32, v33, v34, v35, v36);
          }
          v58 = v19[12];
          if ( v58 )
          {
            v59 = ucfg_coex_send_btc_chain_mode(v29, v30, v31, v32, v33, v34, v35, v36, v19[12], v17);
            v60 = qdf_status_to_os_return(v59);
            if ( v60 )
            {
              v50 = v60;
              v51 = 3;
              goto LABEL_54;
            }
            qdf_trace_msg(
              0x70u,
              8u,
              "%s: Set btc chain mode to %d for vdev %d",
              v42,
              v43,
              v44,
              v45,
              v46,
              v47,
              v48,
              v49,
              "__wlan_cfg80211_coex_set_btc_chain_mode",
              v17,
              3);
            if ( v16 )
              wlan_coex_config_updated(v58, 0, v29, v30, v31, v32, v33, v34, v35, v36);
          }
          v61 = v19[13];
          if ( v61 )
          {
            v62 = ucfg_coex_send_btc_chain_mode(v29, v30, v31, v32, v33, v34, v35, v36, v19[13], v17);
            v63 = qdf_status_to_os_return(v62);
            if ( v63 )
            {
              v50 = v63;
              v51 = 4;
              goto LABEL_54;
            }
            qdf_trace_msg(
              0x70u,
              8u,
              "%s: Set btc chain mode to %d for vdev %d",
              v42,
              v43,
              v44,
              v45,
              v46,
              v47,
              v48,
              v49,
              "__wlan_cfg80211_coex_set_btc_chain_mode",
              v17,
              4);
            if ( v16 )
              wlan_coex_config_updated(v61, 0, v29, v30, v31, v32, v33, v34, v35, v36);
          }
          v64 = v19[14];
          if ( v64 )
          {
            v65 = ucfg_coex_send_btc_chain_mode(v29, v30, v31, v32, v33, v34, v35, v36, v64, v17);
            v66 = qdf_status_to_os_return(v65);
            if ( v66 )
            {
              v50 = v66;
              v51 = 5;
              goto LABEL_54;
            }
            qdf_trace_msg(
              0x70u,
              8u,
              "%s: Set btc chain mode to %d for vdev %d",
              v42,
              v43,
              v44,
              v45,
              v46,
              v47,
              v48,
              v49,
              "__wlan_cfg80211_coex_set_btc_chain_mode",
              v17,
              5);
            if ( v16 )
              wlan_coex_config_updated(v64, 0, v67, v68, v69, v70, v71, v72, v73, v74);
          }
          result = 0;
          goto LABEL_6;
        }
      }
      v12 = "%s: NULL psoc";
    }
    else
    {
      v12 = "%s: Null vdev";
    }
    v13 = "__wlan_cfg80211_coex_set_btc_chain_mode";
    goto LABEL_4;
  }
  v12 = "%s: Invalid btc chain mode ATTR";
LABEL_3:
  v13 = "wlan_cfg80211_coex_set_btc_chain_mode";
LABEL_4:
  qdf_trace_msg(0x70u, 2u, v12, v4, v5, v6, v7, v8, v9, v10, v11, v13);
LABEL_5:
  result = 4294967274LL;
LABEL_6:
  _ReadStatusReg(SP_EL0);
  return result;
}
