__int64 __fastcall hdd_tx_latency_stats_cb(
        unsigned __int8 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  _QWORD *context; // x22
  unsigned int gfp_flags; // w0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  unsigned int v22; // w20
  _QWORD *link_info_by_vdev; // x0
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  int v33; // w5
  __int64 v34; // x25
  unsigned int v35; // w23
  _QWORD *v36; // x26
  __int64 v37; // x0
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  __int64 v46; // x21
  __int64 v47; // x23
  __int64 v48; // x22
  _WORD *v49; // x25
  _QWORD *v50; // x23
  unsigned int v51; // w21
  _QWORD *v52; // x26
  int v53; // w24
  double v54; // d0
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7
  double v62; // d0
  double v63; // d1
  double v64; // d2
  double v65; // d3
  double v66; // d4
  double v67; // d5
  double v68; // d6
  double v69; // d7

  context = _cds_get_context(51, (__int64)"hdd_tx_latency_stats_cb", a3, a4, a5, a6, a7, a8, a9, a10);
  gfp_flags = cds_get_gfp_flags();
  if ( context )
  {
    if ( a2 && (v22 = gfp_flags, !qdf_list_empty((_QWORD *)a2)) )
    {
      link_info_by_vdev = (_QWORD *)hdd_get_link_info_by_vdev((__int64)context, a1);
      if ( link_info_by_vdev )
      {
        v33 = *(_DWORD *)(a2 + 16);
        v34 = jiffies;
        if ( v33 )
          v35 = ((212 * v33 + 7) & 0xFFFFFFFC) + 16;
        else
          v35 = 0;
        if ( hdd_tx_latency_stats_cb___last_ticks - jiffies + 125 < 0 )
        {
          v36 = link_info_by_vdev;
          qdf_trace_msg(
            0x33u,
            8u,
            "%s: vdev id %d stats cnt %d",
            v25,
            v26,
            v27,
            v28,
            v29,
            v30,
            v31,
            v32,
            "hdd_tx_latency_stats_cb",
            a1);
          link_info_by_vdev = v36;
          hdd_tx_latency_stats_cb___last_ticks = v34;
        }
        v37 = _cfg80211_alloc_event_skb(context[3], *link_info_by_vdev + 112LL, 103, 197, 0, 65, v35, v22);
        if ( v37 )
        {
          v46 = *(_QWORD *)(v37 + 216);
          v47 = *(unsigned int *)(v37 + 208);
          v48 = v37;
          if ( (nla_put(v37, 32773, 0, 0) & 0x80000000) != 0 || (v49 = (_WORD *)(v46 + v47)) == nullptr )
          {
            sk_skb_reason_drop(0, v48, 2);
            qdf_trace_msg(
              0x33u,
              2u,
              "%s: failed to put peers",
              v62,
              v63,
              v64,
              v65,
              v66,
              v67,
              v68,
              v69,
              "hdd_tx_latency_stats_cb");
            return 2;
          }
          else
          {
            v50 = *(_QWORD **)a2;
            if ( *(_QWORD *)a2 == a2 )
            {
LABEL_20:
              *v49 = *(_WORD *)(v48 + 216) + *(_DWORD *)(v48 + 208) - (_WORD)v49;
              _cfg80211_send_event_skb(v48, v22);
              return 0;
            }
            else
            {
              v51 = 0;
              while ( 1 )
              {
                v52 = (_QWORD *)*v50;
                qdf_list_remove_node(a2, v50);
                v53 = hdd_tx_latency_fill_link_stats(v48, v50, v51);
                _qdf_mem_free((__int64)v50);
                if ( v53 )
                  break;
                ++v51;
                v50 = v52;
                if ( v52 == (_QWORD *)a2 )
                  goto LABEL_20;
              }
              qdf_trace_msg(
                0x33u,
                2u,
                "%s: failed to populate stats for idx %d",
                v54,
                v55,
                v56,
                v57,
                v58,
                v59,
                v60,
                v61,
                "hdd_tx_latency_stats_cb",
                v51);
              sk_skb_reason_drop(0, v48, 2);
              return 2;
            }
          }
        }
        else
        {
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: event alloc failed vdev id %d, len %d",
            v38,
            v39,
            v40,
            v41,
            v42,
            v43,
            v44,
            v45,
            "hdd_tx_latency_stats_cb",
            a1,
            v35);
          return 2;
        }
      }
      else
      {
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: adapter NULL for vdev id %d",
          v25,
          v26,
          v27,
          v28,
          v29,
          v30,
          v31,
          v32,
          "hdd_tx_latency_stats_cb",
          a1);
        return 4;
      }
    }
    else
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: invalid stats list",
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        "hdd_tx_latency_stats_cb");
      return 4;
    }
  }
  else
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: HDD context is NULL",
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "hdd_tx_latency_stats_cb");
    return 5;
  }
}
