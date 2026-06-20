__int64 __fastcall os_if_dp_send_flow_stats(__int64 a1, __int64 a2, unsigned int a3, unsigned int a4)
{
  __int64 pdev_by_id; // x0
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  _QWORD *v16; // x23
  __int64 v17; // x19
  unsigned int len; // w0
  __int64 v19; // x0
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  __int64 v28; // x22
  unsigned int v29; // w0
  unsigned int *v30; // x8
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  unsigned int v39; // w20
  unsigned int *v40; // x8
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
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

  pdev_by_id = wlan_objmgr_get_pdev_by_id(a1, 0, 0x61u);
  if ( pdev_by_id )
  {
    v16 = *(_QWORD **)(pdev_by_id + 24);
    if ( v16 )
    {
      v17 = pdev_by_id;
      len = os_if_dp_flow_stats_update_or_get_len(0, a2, a4);
      v19 = _cfg80211_alloc_event_skb(*v16, 0, 103, 197, 0, a3, len, 3264);
      if ( v19 )
      {
        v28 = v19;
        v29 = os_if_dp_flow_stats_update_or_get_len(v19, a2, a4);
        if ( (v29 & 0x80000000) == 0 )
        {
          v39 = v29;
          _cfg80211_send_event_skb(v28, 3264);
          wlan_objmgr_pdev_release_ref(v17, 0x61u, v40, v41, v42, v43, v44, v45, v46, v47, v48);
          return v39;
        }
        wlan_objmgr_pdev_release_ref(v17, 0x61u, v30, v31, v32, v33, v34, v35, v36, v37, v38);
        qdf_trace_msg(
          0x48u,
          2u,
          "%s: STC: flow sample nla_put api failed",
          v59,
          v60,
          v61,
          v62,
          v63,
          v64,
          v65,
          v66,
          "os_if_dp_send_flow_stats");
        sk_skb_reason_drop(0, v28, 2);
      }
      else
      {
        qdf_trace_msg(
          0x48u,
          2u,
          "%s: STC: vendor event alloc failed for flow sample",
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          "os_if_dp_send_flow_stats");
        wlan_objmgr_pdev_release_ref(v17, 0x61u, v50, v51, v52, v53, v54, v55, v56, v57, v58);
      }
    }
    else
    {
      qdf_trace_msg(
        0x48u,
        2u,
        "%s: PDEV OS private structure is NULL",
        v8,
        v9,
        v10,
        v11,
        v12,
        v13,
        v14,
        v15,
        "os_if_dp_send_flow_stats");
    }
  }
  return 4294967274LL;
}
