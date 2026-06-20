__int64 *__fastcall hdd_oem_event_handler_cb(
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
  _QWORD *context; // x19
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 *result; // x0
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  __int64 *v46; // x21
  __int64 v47; // x0
  __int64 v48; // x22
  __int64 v49; // x0
  size_t v50; // x8
  __int64 v51; // x23
  void *v52; // x0
  const char *v53; // x2
  unsigned int v54; // w1
  __int64 v55; // x0
  __int64 v56; // x21
  unsigned int v57; // w0
  double v58; // d0
  double v59; // d1
  double v60; // d2
  double v61; // d3
  double v62; // d4
  double v63; // d5
  double v64; // d6
  double v65; // d7

  context = _cds_get_context(51, (__int64)"hdd_oem_event_handler_cb", a3, a4, a5, a6, a7, a8, a9, a10);
  qdf_trace_msg(0x33u, 8u, "%s: enter", v13, v14, v15, v16, v17, v18, v19, v20, "hdd_oem_event_handler_cb");
  result = (__int64 *)_wlan_hdd_validate_context(
                        (__int64)context,
                        (__int64)"hdd_oem_event_handler_cb",
                        v21,
                        v22,
                        v23,
                        v24,
                        v25,
                        v26,
                        v27,
                        v28);
  if ( !(_DWORD)result )
  {
    if ( !a1 || !*(_QWORD *)(a1 + 24) )
    {
      v53 = "%s: Invalid oem event data";
      goto LABEL_11;
    }
    result = (__int64 *)hdd_get_link_info_by_vdev((__int64)context, a2);
    if ( result )
    {
      v46 = result;
      result = (__int64 *)_hdd_validate_adapter(
                            *result,
                            (__int64)"hdd_oem_event_handler_cb",
                            v38,
                            v39,
                            v40,
                            v41,
                            v42,
                            v43,
                            v44,
                            v45);
      if ( !(_DWORD)result )
      {
        if ( *(_BYTE *)(*v46 + 52464) == 1 )
        {
          v47 = osif_request_get(*(_QWORD *)(*v46 + 52456));
          if ( v47 )
          {
            v48 = v47;
            v49 = osif_request_priv(v47);
            v50 = *(_QWORD *)(a1 + 8);
            v51 = v49;
            *(_QWORD *)(v49 + 8) = v50;
            v52 = (void *)_qdf_mem_malloc(v50, "hdd_oem_event_handler_cb", 1260);
            *(_QWORD *)(v51 + 24) = v52;
            if ( !v52 )
              return (__int64 *)osif_request_put(v48);
            qdf_mem_copy(v52, *(const void **)(a1 + 24), *(unsigned int *)(v51 + 8));
            *(_BYTE *)v51 = *((_BYTE *)v46 + 8);
            osif_request_complete(v48);
            osif_request_put(v48);
            goto LABEL_21;
          }
          v53 = "%s: Invalid request";
        }
        else
        {
          v55 = _cfg80211_alloc_event_skb(
                  context[3],
                  *v46 + 112,
                  103,
                  197,
                  0,
                  40,
                  ((*(_DWORD *)(a1 + 8) + 7) & 0xFFFFFFFC) + 16,
                  3264);
          if ( v55 )
          {
            v56 = v55;
            v57 = nla_put(v55, 1, *(unsigned int *)(a1 + 8), *(_QWORD *)(a1 + 24));
            if ( v57 )
            {
              qdf_trace_msg(
                0x33u,
                2u,
                "%s: OEM event put fails status %d",
                v58,
                v59,
                v60,
                v61,
                v62,
                v63,
                v64,
                v65,
                "hdd_oem_event_handler_cb",
                v57);
              return (__int64 *)sk_skb_reason_drop(0, v56, 2);
            }
            _cfg80211_send_event_skb(v56, 3264);
LABEL_21:
            sme_oem_event_deinit(context[2]);
            v53 = "%s: exit";
            v54 = 8;
            return (__int64 *)qdf_trace_msg(
                                0x33u,
                                v54,
                                v53,
                                v30,
                                v31,
                                v32,
                                v33,
                                v34,
                                v35,
                                v36,
                                v37,
                                "hdd_oem_event_handler_cb");
          }
          v53 = "%s: wlan_cfg80211_vendor_event_alloc failed";
        }
LABEL_11:
        v54 = 2;
        return (__int64 *)qdf_trace_msg(
                            0x33u,
                            v54,
                            v53,
                            v30,
                            v31,
                            v32,
                            v33,
                            v34,
                            v35,
                            v36,
                            v37,
                            "hdd_oem_event_handler_cb");
      }
    }
  }
  return result;
}
