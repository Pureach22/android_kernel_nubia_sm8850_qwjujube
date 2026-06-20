__int64 __fastcall wlan_cfg80211_tdls_oper(__int64 a1, unsigned __int8 *a2, int a3)
{
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  unsigned int v14; // w22
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x8
  __int64 v24; // x21
  __int64 v25; // x21
  unsigned int v26; // w0
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  __int64 result; // x0
  __int64 v36; // x4
  __int64 v37; // x5
  __int64 v38; // x6
  __int64 v39; // x7
  int v40; // w21
  const char *v41; // x4
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
  const char *v58; // x4
  double v59; // d0
  double v60; // d1
  double v61; // d2
  double v62; // d3
  double v63; // d4
  double v64; // d5
  double v65; // d6
  double v66; // d7
  double v67; // d0
  double v68; // d1
  double v69; // d2
  double v70; // d3
  double v71; // d4
  double v72; // d5
  double v73; // d6
  double v74; // d7

  if ( !(unsigned int)qdf_mem_cmp(a2, &wlan_cfg80211_tdls_validate_mac_addr_temp_mac, 6u) )
  {
    if ( a2 )
    {
      v36 = *a2;
      v37 = a2[1];
      v38 = a2[2];
      v39 = a2[5];
    }
    else
    {
      v38 = 0;
      v36 = 0;
      v37 = 0;
      v39 = 0;
    }
    qdf_trace_msg(
      0x48u,
      8u,
      "%s: Invalid Mac address %02x:%02x:%02x:**:**:%02x cmd declined.",
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      "wlan_cfg80211_tdls_validate_mac_addr",
      v36,
      v37,
      v38,
      v39);
    return 4294967274LL;
  }
  v14 = a3 - 1;
  if ( a3 <= 1 )
  {
    if ( !a3 )
    {
      qdf_trace_msg(
        0x48u,
        3u,
        "%s: We don't support in-driver setup/teardown/discovery",
        v6,
        v7,
        v8,
        v9,
        v10,
        v11,
        v12,
        v13,
        "wlan_cfg80211_tdls_oper");
      return 4294966772LL;
    }
    if ( a3 != 1 )
      goto LABEL_24;
    v40 = 6;
    v41 = "TDLS_SETUP";
  }
  else
  {
    switch ( a3 )
    {
      case 2:
        v40 = 7;
        v41 = "TDLS_TEARDOWN";
        break;
      case 3:
        v40 = 4;
        v41 = "TDLS_ENABLE_LINK";
        break;
      case 4:
        qdf_trace_msg(
          0x48u,
          8u,
          "%s: %s start",
          v6,
          v7,
          v8,
          v9,
          v10,
          v11,
          v12,
          v13,
          "wlan_cfg80211_tdls_oper",
          "TDLS_DISABLE_LINK");
        v23 = *(_QWORD *)(a1 + 608);
        *(_DWORD *)(a1 + 60) &= ~0x10u;
        if ( v23 )
        {
          v24 = *(_QWORD *)(v23 + 16);
          if ( v24 )
          {
            *(_DWORD *)(v24 + 32) = 0;
            v25 = v24 + 32;
            v26 = ucfg_tdls_oper(a1, a2, 5, v15, v16, v17, v18, v19, v20, v21, v22);
            if ( v26 )
            {
              qdf_trace_msg(
                0x48u,
                2u,
                "%s: ucfg_tdls_disable_link fail %d",
                v27,
                v28,
                v29,
                v30,
                v31,
                v32,
                v33,
                v34,
                "wlan_cfg80211_tdls_oper",
                v26);
              return 4294967291LL;
            }
            else if ( wait_for_completion_timeout(v25, 2500) )
            {
              return 0;
            }
            else
            {
              qdf_trace_msg(
                0x48u,
                2u,
                "%s: timeout for tdls disable link %ld",
                v67,
                v68,
                v69,
                v70,
                v71,
                v72,
                v73,
                v74,
                "wlan_cfg80211_tdls_oper",
                0);
              return 0xFFFFFFFFLL;
            }
          }
        }
        qdf_trace_msg(
          0x48u,
          2u,
          "%s: osif priv or tdls priv is NULL",
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          "wlan_cfg80211_tdls_oper");
        return 4294967274LL;
      default:
LABEL_24:
        qdf_trace_msg(
          0x48u,
          8u,
          "%s: %s start",
          v6,
          v7,
          v8,
          v9,
          v10,
          v11,
          v12,
          v13,
          "wlan_cfg80211_tdls_oper",
          "UNKNOWN:ERR");
        qdf_trace_msg(
          0x48u,
          2u,
          "%s: unsupported event %d",
          v59,
          v60,
          v61,
          v62,
          v63,
          v64,
          v65,
          v66,
          "wlan_cfg80211_tdls_oper",
          (unsigned int)a3);
        return 4294966772LL;
    }
  }
  qdf_trace_msg(0x48u, 8u, "%s: %s start", v6, v7, v8, v9, v10, v11, v12, v13, "wlan_cfg80211_tdls_oper", v41);
  result = ucfg_tdls_oper(a1, a2, v40, v42, v43, v44, v45, v46, v47, v48, v49);
  if ( (_DWORD)result )
  {
    if ( v14 > 2 )
      v58 = "UNKNOWN:ERR";
    else
      v58 = off_A2BE20[v14];
    qdf_trace_msg(
      0x48u,
      2u,
      "%s: %s fail %d",
      v50,
      v51,
      v52,
      v53,
      v54,
      v55,
      v56,
      v57,
      "wlan_cfg80211_tdls_oper",
      v58,
      (unsigned int)result);
    return 4294967291LL;
  }
  return result;
}
