__int64 __fastcall wlan_hdd_set_wlm_latency_level(
        __int64 a1,
        unsigned int a2,
        unsigned int a3,
        char a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 v12; // x20
  __int64 v14; // x22
  __int64 v15; // x24
  __int64 v19; // x0
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  __int64 v28; // x19
  __int64 v29; // x0
  __int64 v30; // x8
  unsigned int v31; // w0
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  unsigned int v40; // w20
  unsigned int v41; // w0
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  unsigned int v50; // w20
  __int64 v51; // x0
  double v52; // d0
  double v53; // d1
  double v54; // d2
  double v55; // d3
  double v56; // d4
  double v57; // d5
  double v58; // d6
  double v59; // d7
  __int64 v60; // x21

  if ( *(_DWORD *)(a1 + 40) )
  {
    v12 = jiffies;
    if ( wlan_hdd_set_wlm_latency_level___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: WLM offload is supported in STA mode only",
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        a12,
        "wlan_hdd_set_wlm_latency_level");
      wlan_hdd_set_wlm_latency_level___last_ticks = v12;
    }
    return 16;
  }
  else
  {
    v14 = a1 + 49152;
    v15 = *(_QWORD *)(a1 + 24);
    *(_BYTE *)(a1 + 52193) = 1;
    v19 = osif_request_alloc(wlan_hdd_set_wlm_latency_level_params);
    if ( v19 )
    {
      v28 = v19;
      v29 = osif_request_cookie(v19);
      v30 = *(_QWORD *)(v14 + 3680);
      *(_QWORD *)(v14 + 3032) = v29;
      *(_BYTE *)(v14 + 3040) = 1;
      v31 = ((__int64 (__fastcall *)(_QWORD, _QWORD, _QWORD, _QWORD, _QWORD))sme_set_wlm_latency_level)(
              *(_QWORD *)(v15 + 16),
              *(unsigned __int8 *)(v30 + 8),
              a2,
              a3,
              a4 & 1);
      if ( v31 )
      {
        v40 = v31;
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: Failure while sending command to fw",
          v32,
          v33,
          v34,
          v35,
          v36,
          v37,
          v38,
          v39,
          "wlan_hdd_set_wlm_latency_level");
      }
      else
      {
        v41 = osif_request_wait_for_response(v28);
        if ( v41 )
        {
          v50 = v41;
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: SME timed out while retrieving latency level",
            v42,
            v43,
            v44,
            v45,
            v46,
            v47,
            v48,
            v49,
            "wlan_hdd_set_wlm_latency_level");
          v40 = qdf_status_from_os_return(v50);
        }
        else
        {
          v51 = osif_request_priv(v28);
          if ( v51 )
          {
            v60 = v51;
            qdf_trace_msg(
              0x33u,
              8u,
              "%s: latency level received from FW:%d",
              v52,
              v53,
              v54,
              v55,
              v56,
              v57,
              v58,
              v59,
              "wlan_hdd_set_wlm_latency_level",
              *(unsigned int *)(v51 + 4));
            v40 = 0;
            *(_WORD *)(v14 + 2946) = *(_DWORD *)(v60 + 4);
          }
          else
          {
            qdf_trace_msg(
              0x33u,
              2u,
              "%s: invalid get latency level",
              v52,
              v53,
              v54,
              v55,
              v56,
              v57,
              v58,
              v59,
              "wlan_hdd_set_wlm_latency_level");
            v40 = 16;
          }
        }
      }
      osif_request_put(v28);
      *(_WORD *)(v14 + 3040) = 0;
      *(_QWORD *)(v14 + 3032) = 0;
      return v40;
    }
    else
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Request allocation failure",
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        "wlan_hdd_set_wlm_latency_level");
      return 16;
    }
  }
}
