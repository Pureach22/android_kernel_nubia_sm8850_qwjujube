__int64 __fastcall osif_dp_get_nud_stats(
        __int64 a1,
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
  _QWORD *context; // x24
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  unsigned int pkt_type_bitmap_value; // w0
  __int64 v22; // x8
  unsigned int v23; // w22
  __int64 v24; // x19
  __int64 v25; // x0
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  __int64 v34; // x20
  __int64 v35; // x0
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  double v52; // d0
  double v53; // d1
  double v54; // d2
  double v55; // d3
  double v56; // d4
  double v57; // d5
  double v58; // d6
  double v59; // d7
  __int64 v60; // x8
  _DWORD *v61; // x8
  unsigned int v62; // w21
  double v63; // d0
  double v64; // d1
  double v65; // d2
  double v66; // d3
  double v67; // d4
  double v68; // d5
  double v69; // d6
  double v70; // d7
  const char *v71; // x2
  double v72; // d0
  double v73; // d1
  double v74; // d2
  double v75; // d3
  double v76; // d4
  double v77; // d5
  double v78; // d6
  double v79; // d7
  double v80; // d0
  double v81; // d1
  double v82; // d2
  double v83; // d3
  double v84; // d4
  double v85; // d5
  double v86; // d6
  double v87; // d7
  __int64 arp_stats; // x0
  _WORD *v90; // x24
  __int64 v91; // x0
  double v92; // d0
  double v93; // d1
  double v94; // d2
  double v95; // d3
  double v96; // d4
  double v97; // d5
  double v98; // d6
  double v99; // d7
  __int64 v100; // x23
  double v101; // d0
  double v102; // d1
  double v103; // d2
  double v104; // d3
  double v105; // d4
  double v106; // d5
  double v107; // d6
  double v108; // d7
  double v109; // d0
  double v110; // d1
  double v111; // d2
  double v112; // d3
  double v113; // d4
  double v114; // d5
  double v115; // d6
  double v116; // d7
  __int64 v117; // [xsp+8h] [xbp-18h] BYREF
  _WORD v118[2]; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v119; // [xsp+18h] [xbp-8h]

  v119 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v117 = 0;
  context = _cds_get_context(71, (__int64)"osif_dp_get_nud_stats", a3, a4, a5, a6, a7, a8, a9, a10);
  pkt_type_bitmap_value = ucfg_dp_get_pkt_type_bitmap_value(a2, v13, v14, v15, v16, v17, v18, v19, v20);
  v22 = *(_QWORD *)(a2 + 216);
  v23 = pkt_type_bitmap_value;
  if ( v22 )
    v24 = *(_QWORD *)(v22 + 80);
  else
    v24 = 0;
  v25 = osif_request_alloc(osif_dp_get_nud_stats_params);
  if ( v25 )
  {
    v34 = v25;
    v35 = osif_request_cookie(v25);
    ucfg_dp_set_nud_stats_cb(v24, v35, v36, v37, v38, v39, v40, v41, v42, v43);
    LOBYTE(v117) = 1;
    HIDWORD(v117) = (unsigned __int8)ucfg_dp_get_link_id(a2, v44, v45, v46, v47, v48, v49, v50, v51);
    if ( ucfg_dp_nud_fail_data_stall_evt_enabled()
      && !(unsigned __int8)ucfg_dp_nud_tracking_enabled(v24)
      && (v23 & 1) != 0 )
    {
      qdf_trace_msg(0x3Bu, 2u, "Data stall due to NUD failure", v52, v53, v54, v55, v56, v57, v58, v59);
      if ( context && *context )
      {
        v60 = *(_QWORD *)(*context + 64LL);
        if ( v60 )
        {
          v61 = *(_DWORD **)(v60 + 88);
          if ( v61 )
          {
            if ( *(v61 - 1) != -889045584 )
              __break(0x8228u);
            ((void (__fastcall *)(_QWORD *, __int64, __int64, _QWORD, __int64, __int64))v61)(context, 3, 258, 0, 255, 2);
          }
        }
      }
      else
      {
        qdf_trace_msg(
          0x45u,
          1u,
          "%s invalid instance",
          v52,
          v53,
          v54,
          v55,
          v56,
          v57,
          v58,
          v59,
          "cdp_post_data_stall_event");
      }
    }
    if ( (unsigned int)ucfg_dp_req_get_arp_stats(v24, (__int64)&v117, v52, v53, v54, v55, v56, v57, v58, v59) )
    {
      v71 = "%s: Unable to sent ARP stats request";
    }
    else
    {
      if ( (unsigned int)osif_request_wait_for_response(v34) )
      {
        qdf_trace_msg(
          0x45u,
          2u,
          "%s: timedout while retrieving NUD stats",
          v80,
          v81,
          v82,
          v83,
          v84,
          v85,
          v86,
          v87,
          "osif_dp_get_nud_stats");
        v62 = -110;
        goto LABEL_22;
      }
      arp_stats = ucfg_dp_get_arp_stats(a2, v80, v81, v82, v83, v84, v85, v86, v87);
      if ( arp_stats )
      {
        v90 = (_WORD *)arp_stats;
        v91 = _cfg80211_alloc_reply_skb(a1, 103, 197, 800);
        if ( v91 )
        {
          v100 = v91;
          v118[0] = *v90;
          if ( (unsigned int)nla_put(v91, 1, 2, v118)
            || (v118[0] = v90[6], (unsigned int)nla_put(v100, 2, 2, v118))
            || (v118[0] = v90[6], (unsigned int)nla_put(v100, 3, 2, v118))
            || (v118[0] = v90[9], (unsigned int)nla_put(v100, 4, 2, v118))
            || (v118[0] = v90[8], (unsigned int)nla_put(v100, 5, 2, v118))
            || (v118[0] = v90[1], (unsigned int)nla_put(v100, 6, 2, v118))
            || (v118[0] = v90[4], (unsigned int)nla_put(v100, 7, 2, v118))
            || (v118[0] = v90[7], (unsigned int)nla_put(v100, 8, 2, v118)) )
          {
            qdf_trace_msg(
              0x45u,
              2u,
              "%s: nla put fail",
              v101,
              v102,
              v103,
              v104,
              v105,
              v106,
              v107,
              v108,
              "osif_dp_get_nud_stats");
            sk_skb_reason_drop(0, v100, 2);
            v62 = -22;
          }
          else
          {
            if ( (ucfg_dp_get_con_status_value(a2, v101, v102, v103, v104, v105, v106, v107, v108) & 1) != 0 )
              nla_put(v100, 9, 0, 0);
            if ( (ucfg_dp_get_dad_value(a2, v109, v110, v111, v112, v113, v114, v115, v116) & 1) != 0 )
              nla_put(v100, 10, 0, 0);
            if ( v23 >= 2 && (unsigned int)osif_dp_populate_connectivity_check_stats_info(a2, v100) )
            {
              v62 = -22;
            }
            else
            {
              cfg80211_vendor_cmd_reply(v100);
              v62 = 0;
            }
          }
        }
        else
        {
          qdf_trace_msg(
            0x45u,
            2u,
            "%s: wlan_cfg80211_vendor_cmd_alloc_reply_skb failed",
            v92,
            v93,
            v94,
            v95,
            v96,
            v97,
            v98,
            v99,
            "osif_dp_get_nud_stats");
          v62 = -12;
        }
        goto LABEL_22;
      }
      v71 = "%s: Unable to get ARP stats";
    }
    qdf_trace_msg(0x45u, 2u, v71, v63, v64, v65, v66, v67, v68, v69, v70, "osif_dp_get_nud_stats");
    v62 = -22;
LABEL_22:
    ucfg_dp_clear_nud_stats_cb(v24, v72, v73, v74, v75, v76, v77, v78, v79);
    osif_request_put(v34);
    goto LABEL_23;
  }
  qdf_trace_msg(
    0x45u,
    2u,
    "%s: Request allocation failure",
    v26,
    v27,
    v28,
    v29,
    v30,
    v31,
    v32,
    v33,
    "osif_dp_get_nud_stats");
  v62 = -12;
LABEL_23:
  _ReadStatusReg(SP_EL0);
  return v62;
}
