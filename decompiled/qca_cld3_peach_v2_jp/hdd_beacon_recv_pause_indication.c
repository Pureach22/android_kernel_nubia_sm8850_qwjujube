__int64 *__fastcall hdd_beacon_recv_pause_indication(
        __int64 a1,
        unsigned __int8 a2,
        int a3,
        int a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 *result; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 *v25; // x26
  __int64 v26; // x25
  unsigned int v27; // w20
  unsigned int gfp_flags; // w21
  __int64 v29; // x0
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  __int64 v38; // x20
  int is_beacon_reporting_do_not_resume; // w24
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  int v48; // w22
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  int v57; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v58; // [xsp+8h] [xbp-8h]

  v58 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  result = (__int64 *)_wlan_hdd_validate_context(
                        a1,
                        (__int64)"hdd_beacon_recv_pause_indication",
                        a5,
                        a6,
                        a7,
                        a8,
                        a9,
                        a10,
                        a11,
                        a12);
  if ( !(_DWORD)result )
  {
    result = (__int64 *)hdd_get_link_info_by_vdev(a1, a2);
    if ( result )
    {
      v25 = result;
      result = (__int64 *)_hdd_validate_adapter(
                            *result,
                            (__int64)"hdd_beacon_recv_pause_indication",
                            v17,
                            v18,
                            v19,
                            v20,
                            v21,
                            v22,
                            v23,
                            v24);
      if ( !(_DWORD)result )
      {
        v26 = *v25;
        if ( (a4 & 1) != 0 )
          v27 = 32;
        else
          v27 = 40;
        gfp_flags = cds_get_gfp_flags();
        v29 = _cfg80211_alloc_event_skb(*(_QWORD *)(a1 + 24), v26 + 112, 103, 197, 0, 38, v27, gfp_flags);
        if ( v29 )
        {
          v38 = v29;
          is_beacon_reporting_do_not_resume = sme_is_beacon_reporting_do_not_resume(
                                                *(_QWORD *)(a1 + 16),
                                                *((unsigned __int8 *)v25 + 8),
                                                v30,
                                                v31,
                                                v32,
                                                v33,
                                                v34,
                                                v35,
                                                v36,
                                                v37);
          if ( (a4 & 1) != 0 )
          {
            if ( (sme_is_beacon_report_started(
                    *(_QWORD *)(a1 + 16),
                    *((unsigned __int8 *)v25 + 8),
                    v40,
                    v41,
                    v42,
                    v43,
                    v44,
                    v45,
                    v46,
                    v47)
                & 1) != 0 )
              hdd_handle_beacon_reporting_stop_op(a1, v26);
            v48 = 2;
          }
          else
          {
            if ( (is_beacon_reporting_do_not_resume & 1) != 0 )
              hdd_handle_beacon_reporting_stop_op(a1, v26);
            v48 = a3 == 0;
          }
          v57 = 3;
          if ( (unsigned int)nla_put(v38, 1, 4, &v57)
            || (v57 = v48, (unsigned int)nla_put(v38, 11, 4, &v57))
            || ((a4 | is_beacon_reporting_do_not_resume) & 1) == 0 && (unsigned int)nla_put(v38, 12, 0, 0) )
          {
            qdf_trace_msg(
              0x33u,
              2u,
              "%s: QCA_WLAN_VENDOR_ATTR put fail",
              v49,
              v50,
              v51,
              v52,
              v53,
              v54,
              v55,
              v56,
              "hdd_beacon_recv_pause_indication");
            result = (__int64 *)sk_skb_reason_drop(0, v38, 2);
          }
          else
          {
            result = (__int64 *)_cfg80211_send_event_skb(v38, gfp_flags);
          }
        }
        else
        {
          result = (__int64 *)qdf_trace_msg(
                                0x33u,
                                2u,
                                "%s: wlan_cfg80211_vendor_event_alloc failed",
                                v30,
                                v31,
                                v32,
                                v33,
                                v34,
                                v35,
                                v36,
                                v37,
                                "hdd_beacon_recv_pause_indication");
        }
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
