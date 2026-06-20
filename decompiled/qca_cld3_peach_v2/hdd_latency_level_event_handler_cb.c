__int64 __fastcall hdd_latency_level_event_handler_cb(
        __int64 a1,
        unsigned __int8 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 *context; // x19
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 result; // x0
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int64 link_info_by_vdev; // x0
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  __int64 v39; // x21
  __int64 v40; // x22
  __int64 v41; // x0
  __int64 v42; // x19
  __int64 v43; // x0
  const char *v44; // x2
  unsigned int v45; // w1
  __int64 v46; // x4
  double v47; // d0
  double v48; // d1
  double v49; // d2
  double v50; // d3
  double v51; // d4
  double v52; // d5
  double v53; // d6
  double v54; // d7
  unsigned int v55; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v56; // [xsp+8h] [xbp-8h]

  v56 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  context = _cds_get_context(51, (__int64)"hdd_latency_level_event_handler_cb", a3, a4, a5, a6, a7, a8, a9, a10);
  v55 = 0;
  qdf_trace_msg(0x33u, 8u, "%s: enter", v13, v14, v15, v16, v17, v18, v19, v20, "hdd_latency_level_event_handler_cb");
  result = _wlan_hdd_validate_context(context, "hdd_latency_level_event_handler_cb");
  if ( !(_DWORD)result )
  {
    if ( !a1 )
    {
      v44 = "%s: Invalid latency level event data";
      goto LABEL_8;
    }
    link_info_by_vdev = hdd_get_link_info_by_vdev(context);
    if ( link_info_by_vdev )
    {
      v39 = *(_QWORD *)link_info_by_vdev;
      v40 = *(_QWORD *)link_info_by_vdev + 49152LL;
      if ( *(_BYTE *)(*(_QWORD *)link_info_by_vdev + 52193LL) != 1 )
      {
        v46 = (unsigned __int16)*(_DWORD *)(a1 + 4);
        *(_WORD *)(*(_QWORD *)link_info_by_vdev + 52098LL) = *(_DWORD *)(a1 + 4);
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: adapter->latency_level:%d",
          v31,
          v32,
          v33,
          v34,
          v35,
          v36,
          v37,
          v38,
          "hdd_latency_level_event_handler_cb",
          v46);
        if ( (unsigned int)ucfg_mlme_get_latency_host_flags(*context, *(_BYTE *)(v40 + 2946), &v55) )
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: failed to get latency host flags",
            v47,
            v48,
            v49,
            v50,
            v51,
            v52,
            v53,
            v54,
            "hdd_latency_level_event_handler_cb");
        else
          hdd_set_wlm_host_latency_level(context, v39, v55);
        goto LABEL_14;
      }
      v41 = osif_request_get(*(_QWORD *)(*(_QWORD *)link_info_by_vdev + 52184LL));
      if ( v41 )
      {
        v42 = v41;
        v43 = osif_request_priv(v41);
        *(_DWORD *)(v43 + 4) = *(_DWORD *)(a1 + 4);
        *(_BYTE *)v43 = *(_BYTE *)a1;
        osif_request_complete(v42);
        osif_request_put(v42);
LABEL_14:
        v44 = "%s: exit";
        v45 = 8;
        goto LABEL_15;
      }
      v44 = "%s: Invalid request";
LABEL_8:
      v45 = 2;
LABEL_15:
      result = qdf_trace_msg(
                 0x33u,
                 v45,
                 v44,
                 v22,
                 v23,
                 v24,
                 v25,
                 v26,
                 v27,
                 v28,
                 v29,
                 "hdd_latency_level_event_handler_cb");
      goto LABEL_16;
    }
    result = qdf_trace_msg(
               0x33u,
               2u,
               "%s: adapter is NULL vdev_id = %d",
               v31,
               v32,
               v33,
               v34,
               v35,
               v36,
               v37,
               v38,
               "hdd_latency_level_event_handler_cb",
               a2);
  }
LABEL_16:
  _ReadStatusReg(SP_EL0);
  return result;
}
