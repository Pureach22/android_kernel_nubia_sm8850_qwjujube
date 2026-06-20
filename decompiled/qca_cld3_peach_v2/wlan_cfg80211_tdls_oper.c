__int64 __fastcall wlan_cfg80211_tdls_oper(__int64 tdls_link_vdev, unsigned __int8 *a2, int a3)
{
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  char is_mlo_vdev; // w20
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  int v23; // w23
  const char *v24; // x4
  __int64 v25; // x4
  __int64 v26; // x5
  __int64 v27; // x6
  __int64 v28; // x7
  __int64 result; // x0
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  __int64 v38; // x8
  __int64 v39; // x22
  __int64 v40; // x22
  unsigned int v41; // w0
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  unsigned int *v50; // x8
  double v51; // d0
  double v52; // d1
  double v53; // d2
  double v54; // d3
  double v55; // d4
  double v56; // d5
  double v57; // d6
  double v58; // d7
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
  unsigned int v75; // w20

  if ( (unsigned int)qdf_mem_cmp(a2, &wlan_cfg80211_tdls_validate_mac_addr_temp_mac, 6u) )
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
    is_mlo_vdev = wlan_vdev_mlme_is_mlo_vdev(tdls_link_vdev, v6, v7, v8, v9, v10, v11, v12, v13);
    if ( (is_mlo_vdev & 1) != 0 )
    {
      tdls_link_vdev = ucfg_tdls_get_tdls_link_vdev(tdls_link_vdev, 0x57u);
      if ( !tdls_link_vdev )
      {
        qdf_trace_msg(
          0x48u,
          2u,
          "%s: no tdls link vdev",
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
      }
    }
    if ( a3 > 2 )
    {
      if ( a3 != 3 )
      {
        if ( a3 == 4 )
        {
          qdf_trace_msg(
            0x48u,
            8u,
            "%s: %s start",
            v15,
            v16,
            v17,
            v18,
            v19,
            v20,
            v21,
            v22,
            "wlan_cfg80211_tdls_oper",
            "TDLS_DISABLE_LINK");
          v38 = *(_QWORD *)(tdls_link_vdev + 680);
          *(_DWORD *)(tdls_link_vdev + 60) &= ~0x10u;
          if ( v38 && (v39 = *(_QWORD *)(v38 + 16)) != 0 )
          {
            *(_DWORD *)(v39 + 32) = 0;
            v40 = v39 + 32;
            v41 = ucfg_tdls_oper(tdls_link_vdev, a2, 5, v30, v31, v32, v33, v34, v35, v36, v37);
            if ( v41 )
            {
              qdf_trace_msg(
                0x48u,
                2u,
                "%s: ucfg_tdls_disable_link fail %d",
                v42,
                v43,
                v44,
                v45,
                v46,
                v47,
                v48,
                v49,
                "wlan_cfg80211_tdls_oper",
                v41);
              result = 4294967291LL;
            }
            else if ( wait_for_completion_timeout(v40, 2500) )
            {
              result = 0;
            }
            else
            {
              qdf_trace_msg(
                0x48u,
                2u,
                "%s: timeout for tdls disable link %ld",
                v51,
                v52,
                v53,
                v54,
                v55,
                v56,
                v57,
                v58,
                "wlan_cfg80211_tdls_oper",
                0);
              result = 0xFFFFFFFFLL;
            }
          }
          else
          {
            qdf_trace_msg(
              0x48u,
              2u,
              "%s: osif priv or tdls priv is NULL",
              v30,
              v31,
              v32,
              v33,
              v34,
              v35,
              v36,
              v37,
              "wlan_cfg80211_tdls_oper");
            result = 4294967274LL;
          }
          goto LABEL_27;
        }
        goto LABEL_21;
      }
      v23 = 4;
      v24 = "TDLS_ENABLE_LINK";
    }
    else
    {
      if ( a3 != 1 )
      {
        if ( a3 == 2 )
        {
          v23 = 7;
          v24 = "TDLS_TEARDOWN";
          goto LABEL_24;
        }
LABEL_21:
        qdf_trace_msg(
          0x48u,
          8u,
          "%s: %s start",
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
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
        result = 4294966772LL;
LABEL_27:
        if ( (is_mlo_vdev & 1) != 0 )
        {
          v75 = result;
          ucfg_tdls_put_tdls_link_vdev(tdls_link_vdev, 0x57u, v50, v51, v52, v53, v54, v55, v56, v57, v58);
          return v75;
        }
        return result;
      }
      v23 = 6;
      v24 = "TDLS_SETUP";
    }
LABEL_24:
    qdf_trace_msg(0x48u, 8u, "%s: %s start", v15, v16, v17, v18, v19, v20, v21, v22, "wlan_cfg80211_tdls_oper", v24);
    result = ucfg_tdls_oper(tdls_link_vdev, a2, v23, v67, v68, v69, v70, v71, v72, v73, v74);
    if ( (_DWORD)result )
    {
      qdf_trace_msg(
        0x48u,
        2u,
        "%s: %s fail %d",
        v51,
        v52,
        v53,
        v54,
        v55,
        v56,
        v57,
        v58,
        "wlan_cfg80211_tdls_oper",
        off_B2E1B8[a3 - 1],
        (unsigned int)result);
      result = 4294967291LL;
    }
    goto LABEL_27;
  }
  if ( a2 )
  {
    v25 = *a2;
    v26 = a2[1];
    v27 = a2[2];
    v28 = a2[5];
  }
  else
  {
    v27 = 0;
    v25 = 0;
    v26 = 0;
    v28 = 0;
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
    v25,
    v26,
    v27,
    v28);
  return 4294967274LL;
}
