__int64 __fastcall wlan_hdd_cfg80211_get_concurrency_matrix(__int64 a1, __int64 a2, __int64 a3, unsigned int a4)
{
  __int64 v8; // x0
  __int64 result; // x0
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  int v26; // w0
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  const char *v35; // x2
  unsigned int v36; // w19
  unsigned int v37; // w21
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  unsigned int v46; // w20
  double v47; // d0
  double v48; // d1
  double v49; // d2
  double v50; // d3
  double v51; // d4
  double v52; // d5
  double v53; // d6
  double v54; // d7
  double v55; // d0
  double v56; // d1
  double v57; // d2
  double v58; // d3
  double v59; // d4
  double v60; // d5
  double v61; // d6
  double v62; // d7
  double v63; // d0
  double v64; // d1
  double v65; // d2
  double v66; // d3
  double v67; // d4
  double v68; // d5
  double v69; // d6
  double v70; // d7
  __int64 v71; // x0
  double v72; // d0
  double v73; // d1
  double v74; // d2
  double v75; // d3
  double v76; // d4
  double v77; // d5
  double v78; // d6
  double v79; // d7
  __int64 v80; // x19
  double v81; // d0
  double v82; // d1
  double v83; // d2
  double v84; // d3
  double v85; // d4
  double v86; // d5
  double v87; // d6
  double v88; // d7
  __int64 v89; // x0
  __int64 v90; // x1
  __int64 v91; // [xsp+8h] [xbp-58h] BYREF
  unsigned int v92; // [xsp+14h] [xbp-4Ch] BYREF
  __int64 v93; // [xsp+18h] [xbp-48h] BYREF
  __int64 v94; // [xsp+20h] [xbp-40h]
  __int64 v95; // [xsp+28h] [xbp-38h]
  __int64 v96; // [xsp+30h] [xbp-30h]
  _QWORD v97[5]; // [xsp+38h] [xbp-28h] BYREF

  v97[4] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = *(_QWORD *)(a1 + 488);
  v91 = 0;
  result = _osif_psoc_sync_op_start(v8, &v91, (__int64)"wlan_hdd_cfg80211_get_concurrency_matrix");
  if ( (_DWORD)result )
    goto LABEL_11;
  memset(v97, 0, 32);
  v95 = 0;
  v96 = 0;
  v93 = 0;
  v94 = 0;
  if ( a1 )
  {
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: enter(%s)",
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      "__wlan_hdd_cfg80211_get_concurrency_matrix",
      *(_QWORD *)(a2 + 32) + 296LL);
    if ( (unsigned int)hdd_get_conparam() == 5 )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Command not allowed in FTM mode",
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        "__wlan_hdd_cfg80211_get_concurrency_matrix");
      v26 = -1;
LABEL_10:
      v36 = v26;
      _osif_psoc_sync_op_stop(v91, (__int64)"wlan_hdd_cfg80211_get_concurrency_matrix");
      result = v36;
LABEL_11:
      _ReadStatusReg(SP_EL0);
      return result;
    }
    v26 = _wlan_hdd_validate_context(
            a1 + 1536,
            (__int64)"__wlan_hdd_cfg80211_get_concurrency_matrix",
            v18,
            v19,
            v20,
            v21,
            v22,
            v23,
            v24,
            v25);
    if ( v26 )
      goto LABEL_10;
    if ( (unsigned int)_nla_parse(&v93, 3, a3, a4, &wlan_hdd_get_concurrency_matrix_policy, 31, 0) )
    {
      v35 = "%s: Invalid ATTR";
    }
    else
    {
      if ( v94 )
      {
        v37 = *(unsigned __int8 *)(v94 + 4);
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: Max feature set size: %d",
          v27,
          v28,
          v29,
          v30,
          v31,
          v32,
          v33,
          v34,
          "__wlan_hdd_cfg80211_get_concurrency_matrix",
          *(unsigned __int8 *)(v94 + 4));
        if ( v37 >= 2 )
          v46 = 2;
        else
          v46 = v37;
        v97[0] = 0x4100000009LL;
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: Number of feature sets: %d",
          v38,
          v39,
          v40,
          v41,
          v42,
          v43,
          v44,
          v45,
          "__wlan_hdd_cfg80211_get_concurrency_matrix",
          v46);
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: Feature set matrix",
          v47,
          v48,
          v49,
          v50,
          v51,
          v52,
          v53,
          v54,
          "__wlan_hdd_cfg80211_get_concurrency_matrix");
        if ( v37 )
        {
          qdf_trace_msg(
            0x33u,
            8u,
            "%s: [%d] 0x%02X",
            v55,
            v56,
            v57,
            v58,
            v59,
            v60,
            v61,
            v62,
            "__wlan_hdd_cfg80211_get_concurrency_matrix",
            0,
            LODWORD(v97[0]));
          if ( v37 != 1 )
            qdf_trace_msg(
              0x33u,
              8u,
              "%s: [%d] 0x%02X",
              v63,
              v64,
              v65,
              v66,
              v67,
              v68,
              v69,
              v70,
              "__wlan_hdd_cfg80211_get_concurrency_matrix",
              1,
              HIDWORD(v97[0]));
        }
        v71 = _cfg80211_alloc_reply_skb(a1, 103, 197, 4 * v46 + 20);
        if ( !v71 )
        {
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: Feature set matrix: buffer alloc fail",
            v72,
            v73,
            v74,
            v75,
            v76,
            v77,
            v78,
            v79,
            "__wlan_hdd_cfg80211_get_concurrency_matrix");
          v26 = -12;
          goto LABEL_10;
        }
        v80 = v71;
        v92 = v46;
        if ( !(unsigned int)nla_put(v71, 2, 4, &v92) && !(unsigned int)nla_put(v80, 3, 4 * v46, v97) )
        {
          v26 = cfg80211_vendor_cmd_reply(v80);
          goto LABEL_10;
        }
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: nla put fail",
          v81,
          v82,
          v83,
          v84,
          v85,
          v86,
          v87,
          v88,
          "__wlan_hdd_cfg80211_get_concurrency_matrix");
        sk_skb_reason_drop(0, v80, 2);
        goto LABEL_9;
      }
      v35 = "%s: Attr max feature set size failed";
    }
    qdf_trace_msg(0x33u, 2u, v35, v27, v28, v29, v30, v31, v32, v33, v34, "__wlan_hdd_cfg80211_get_concurrency_matrix");
LABEL_9:
    v26 = -22;
    goto LABEL_10;
  }
  __break(0x800u);
  v89 = (*(__int64 (**)(void))"%s: Failed to detach peer")();
  return wlan_denylist_action_on_bssid(v89, v90);
}
