__int64 __fastcall osif_twt_send_get_capabilities_response(__int64 a1, __int64 a2)
{
  unsigned int v4; // w22
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  unsigned __int8 v13; // w21
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  char v22; // w8
  unsigned __int8 v23; // w21
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
  unsigned __int8 v40; // w24
  bool is_vdev_connected; // w21
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  double v50; // d0
  double v51; // d1
  double v52; // d2
  double v53; // d3
  double v54; // d4
  double v55; // d5
  double v56; // d6
  double v57; // d7
  __int64 result; // x0
  unsigned int v59; // w22
  double v60; // d0
  double v61; // d1
  double v62; // d2
  double v63; // d3
  double v64; // d4
  double v65; // d5
  double v66; // d6
  double v67; // d7
  __int64 v68; // x0
  double v69; // d0
  double v70; // d1
  double v71; // d2
  double v72; // d3
  double v73; // d4
  double v74; // d5
  double v75; // d6
  double v76; // d7
  __int64 v77; // x20
  __int64 v78; // x22
  __int64 v79; // x19
  int v80; // w0
  double v81; // d0
  double v82; // d1
  double v83; // d2
  double v84; // d3
  double v85; // d4
  double v86; // d5
  double v87; // d6
  double v88; // d7
  const char *v89; // x2
  _WORD *v90; // x20
  unsigned int connected_band; // w23
  char v92; // w22
  double v93; // d0
  double v94; // d1
  double v95; // d2
  double v96; // d3
  double v97; // d4
  double v98; // d5
  double v99; // d6
  double v100; // d7
  unsigned __int8 v101; // w23
  double v102; // d0
  double v103; // d1
  double v104; // d2
  double v105; // d3
  double v106; // d4
  double v107; // d5
  double v108; // d6
  double v109; // d7
  unsigned int v110; // [xsp+Ch] [xbp-34h] BYREF
  __int64 v111; // [xsp+10h] [xbp-30h] BYREF
  unsigned int v112; // [xsp+18h] [xbp-28h] BYREF
  char v113[4]; // [xsp+1Ch] [xbp-24h] BYREF
  char v114[4]; // [xsp+20h] [xbp-20h] BYREF
  char v115[4]; // [xsp+24h] [xbp-1Ch] BYREF
  unsigned __int8 v116[4]; // [xsp+28h] [xbp-18h] BYREF
  unsigned int v117; // [xsp+2Ch] [xbp-14h] BYREF
  int v118; // [xsp+30h] [xbp-10h] BYREF
  __int16 v119; // [xsp+34h] [xbp-Ch]
  __int64 v120; // [xsp+38h] [xbp-8h]

  v120 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(unsigned __int8 *)(a2 + 104);
  v116[0] = 0;
  v115[0] = 0;
  v114[0] = 0;
  v113[0] = 0;
  v119 = 0;
  v118 = 0;
  v112 = 0;
  v111 = 0;
  v110 = 0;
  ucfg_twt_cfg_get_requestor(a1, v115);
  qdf_trace_msg(
    0x48u,
    8u,
    "%s: twt_req: %d",
    v5,
    v6,
    v7,
    v8,
    v9,
    v10,
    v11,
    v12,
    "osif_twt_send_get_capabilities_response",
    (unsigned __int8)v115[0]);
  v13 = v115[0];
  ucfg_twt_cfg_get_bcast_requestor(a1, v114);
  qdf_trace_msg(
    0x48u,
    8u,
    "%s: twt_bcast_req: %d",
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    "osif_twt_send_get_capabilities_response",
    (unsigned __int8)v114[0]);
  if ( v114[0] )
    v22 = 4;
  else
    v22 = 0;
  v23 = v22 | v13;
  ucfg_twt_cfg_get_flex_sched(a1, v113);
  qdf_trace_msg(
    0x48u,
    8u,
    "%s: flex sched: %d",
    v24,
    v25,
    v26,
    v27,
    v28,
    v29,
    v30,
    v31,
    "osif_twt_send_get_capabilities_response",
    (unsigned __int8)v113[0]);
  if ( v113[0] )
    v40 = v23 | 8;
  else
    v40 = v23;
  is_vdev_connected = wlan_cm_is_vdev_connected(a2, v32, v33, v34, v35, v36, v37, v38, v39);
  qdf_trace_msg(
    0x48u,
    8u,
    "%s: is_sta_connected:%d self_cap: 0x%x",
    v42,
    v43,
    v44,
    v45,
    v46,
    v47,
    v48,
    v49,
    "osif_twt_send_get_capabilities_response",
    is_vdev_connected,
    v40);
  if ( is_vdev_connected )
  {
    if ( (wlan_cm_host_roam_in_progress(a1, v4) & 1) != 0 )
    {
      qdf_trace_msg(
        0x48u,
        8u,
        "%s: vdev_id:%d sta connected, roam in progress",
        v50,
        v51,
        v52,
        v53,
        v54,
        v55,
        v56,
        v57,
        "osif_twt_send_get_capabilities_response",
        v4);
      result = 4294967280LL;
      goto LABEL_21;
    }
    connected_band = ucfg_cm_get_connected_band(a2, v50, v51, v52, v53, v54, v55, v56, v57);
    ucfg_twt_cfg_get_24ghz_enabled(a1, v113);
    v92 = (connected_band == 1) & v113[0];
    qdf_trace_msg(
      0x48u,
      8u,
      "%s: connected_band:%d val:%d is_twt_24ghz_allowed:%d",
      v93,
      v94,
      v95,
      v96,
      v97,
      v98,
      v99,
      v100,
      "osif_twt_send_get_capabilities_response",
      connected_band);
    v101 = v115[0];
    if ( (unsigned int)osif_fill_peer_macaddr(a2, &v118) )
    {
      result = 4;
      goto LABEL_21;
    }
    result = ucfg_twt_get_peer_capabilities(a1, (unsigned __int8 *)&v118, v116);
    if ( (_DWORD)result )
      goto LABEL_21;
    v40 |= v92 & v101;
    qdf_trace_msg(
      0x48u,
      8u,
      "%s: peer_cap: 0x%x",
      v102,
      v103,
      v104,
      v105,
      v106,
      v107,
      v108,
      v109,
      "osif_twt_send_get_capabilities_response",
      v116[0]);
    v59 = 68;
  }
  else
  {
    v59 = 60;
  }
  ucfg_twt_tgt_caps_get_wake_dur_and_wake_intvl(a1, &v112, (_DWORD *)&v111 + 1, &v111, &v110);
  qdf_trace_msg(
    0x48u,
    8u,
    "%s: min_wake_dur:%u max_wake_dur:%u min_wake_intvl:%u max_wake_intvl:%u",
    v60,
    v61,
    v62,
    v63,
    v64,
    v65,
    v66,
    v67,
    "osif_twt_send_get_capabilities_response",
    v112,
    HIDWORD(v111),
    (unsigned int)v111,
    v110);
  v68 = _cfg80211_alloc_reply_skb(***(_QWORD ***)(a2 + 608), 103, 197, v59);
  if ( v68 )
  {
    v77 = *(_QWORD *)(v68 + 216);
    v78 = *(unsigned int *)(v68 + 208);
    v79 = v68;
    v80 = nla_put(v68, 32770, 0, 0);
    v89 = "%s: TWT: nla_nest_start error";
    if ( (v80 & 0x80000000) == 0 )
    {
      v90 = (_WORD *)(v77 + v78);
      if ( v90 )
      {
        LOWORD(v117) = v40;
        if ( (unsigned int)nla_put(v79, 2, 2, &v117)
          || is_vdev_connected && (LOWORD(v117) = v116[0], (unsigned int)nla_put(v79, 3, 2, &v117)) )
        {
          v89 = "%s: TWT: Failed to fill capabilities";
        }
        else if ( (_DWORD)v111 && (v117 = v111, (unsigned int)nla_put(v79, 4, 4, &v117)) )
        {
          v89 = "%s: TWT: Failed to fill min_wake_intvl capabilities";
        }
        else if ( v110 && (v117 = v110, (unsigned int)nla_put(v79, 5, 4, &v117)) )
        {
          v89 = "%s: TWT: Failed to fill max_wake_intvl capabilities";
        }
        else if ( v112 && (v117 = v112, (unsigned int)nla_put(v79, 6, 4, &v117)) )
        {
          v89 = "%s: TWT: Failed to fill min_wake_duration capabilities";
        }
        else
        {
          if ( !HIDWORD(v111) || (v117 = HIDWORD(v111), !(unsigned int)nla_put(v79, 7, 4, &v117)) )
          {
            *v90 = *(_WORD *)(v79 + 216) + *(_DWORD *)(v79 + 208) - (_WORD)v90;
            result = 4 * (unsigned int)((unsigned int)cfg80211_vendor_cmd_reply(v79) != 0);
            goto LABEL_21;
          }
          v89 = "%s: TWT: Failed to fill max_wake_duration capabilities";
        }
      }
    }
    qdf_trace_msg(0x48u, 2u, v89, v81, v82, v83, v84, v85, v86, v87, v88, "osif_twt_send_get_capabilities_response");
    sk_skb_reason_drop(0, v79, 2);
    result = 16;
  }
  else
  {
    qdf_trace_msg(
      0x48u,
      2u,
      "%s: TWT: get_caps alloc reply skb failed",
      v69,
      v70,
      v71,
      v72,
      v73,
      v74,
      v75,
      v76,
      "osif_twt_send_get_capabilities_response");
    result = 2;
  }
LABEL_21:
  _ReadStatusReg(SP_EL0);
  return result;
}
