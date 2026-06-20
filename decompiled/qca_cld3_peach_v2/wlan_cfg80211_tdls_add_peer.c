__int64 __fastcall wlan_cfg80211_tdls_add_peer(__int64 a1, unsigned __int8 *a2)
{
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 v12; // x4
  __int64 v13; // x5
  __int64 v14; // x6
  __int64 v15; // x7
  __int64 v16; // x4
  __int64 v17; // x5
  __int64 v18; // x6
  __int64 v19; // x7
  unsigned int *v20; // x0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 v29; // x8
  unsigned int *v30; // x19
  _DWORD *v31; // x22
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  unsigned int v40; // w0
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  unsigned int v49; // w20
  double v51; // d0
  double v52; // d1
  double v53; // d2
  double v54; // d3
  double v55; // d4
  double v56; // d5
  double v57; // d6
  double v58; // d7

  if ( !(unsigned int)qdf_mem_cmp(a2, &wlan_cfg80211_tdls_validate_mac_addr_temp_mac, 6u) )
  {
    if ( a2 )
    {
      v16 = *a2;
      v17 = a2[1];
      v18 = a2[2];
      v19 = a2[5];
    }
    else
    {
      v18 = 0;
      v16 = 0;
      v17 = 0;
      v19 = 0;
    }
    qdf_trace_msg(
      0x48u,
      8u,
      "%s: Invalid Mac address %02x:%02x:%02x:**:**:%02x cmd declined.",
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      "wlan_cfg80211_tdls_validate_mac_addr",
      v16,
      v17,
      v18,
      v19);
    return (unsigned int)-22;
  }
  if ( a2 )
  {
    v12 = *a2;
    v13 = a2[1];
    v14 = a2[2];
    v15 = a2[5];
  }
  else
  {
    v14 = 0;
    v12 = 0;
    v13 = 0;
    v15 = 0;
  }
  qdf_trace_msg(
    0x48u,
    8u,
    "%s: Add TDLS peer %02x:%02x:%02x:**:**:%02x",
    v4,
    v5,
    v6,
    v7,
    v8,
    v9,
    v10,
    v11,
    "wlan_cfg80211_tdls_add_peer",
    v12,
    v13,
    v14,
    v15);
  v20 = (unsigned int *)_qdf_mem_malloc(0x10u, "wlan_cfg80211_tdls_add_peer", 127);
  if ( !v20 )
    return (unsigned int)-22;
  v29 = *(_QWORD *)(a1 + 680);
  v30 = v20;
  if ( v29 && (v31 = *(_DWORD **)(v29 + 16)) != nullptr )
  {
    v20[3] = *(unsigned __int8 *)(a1 + 168);
    qdf_mem_copy(v20, a2, 6u);
    *v31 = 0;
    v40 = ucfg_tdls_add_peer(a1, v30, v32, v33, v34, v35, v36, v37, v38, v39);
    if ( v40 )
    {
      qdf_trace_msg(
        0x48u,
        2u,
        "%s: ucfg_tdls_add_peer returned err %d",
        v41,
        v42,
        v43,
        v44,
        v45,
        v46,
        v47,
        v48,
        "wlan_cfg80211_tdls_add_peer",
        v40);
      v49 = -5;
    }
    else
    {
      if ( wait_for_completion_timeout(v31, 1250) )
      {
        if ( !v31[56] )
        {
          v49 = 0;
          goto LABEL_13;
        }
        qdf_trace_msg(
          0x48u,
          2u,
          "%s: tdls add peer failed, status:%d",
          v51,
          v52,
          v53,
          v54,
          v55,
          v56,
          v57,
          v58,
          "wlan_cfg80211_tdls_add_peer");
      }
      else
      {
        qdf_trace_msg(
          0x48u,
          2u,
          "%s: timeout for tdls add peer indication %ld",
          v51,
          v52,
          v53,
          v54,
          v55,
          v56,
          v57,
          v58,
          "wlan_cfg80211_tdls_add_peer",
          0);
      }
      v49 = -1;
    }
  }
  else
  {
    qdf_trace_msg(
      0x48u,
      2u,
      "%s: osif_tdls_vdev or osif_priv is NULL for the current vdev",
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      "wlan_cfg80211_tdls_add_peer");
    v49 = -22;
  }
LABEL_13:
  _qdf_mem_free((__int64)v30);
  return v49;
}
