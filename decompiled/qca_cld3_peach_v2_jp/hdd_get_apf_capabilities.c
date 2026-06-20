__int64 __fastcall hdd_get_apf_capabilities(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v10; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x19
  __int64 v20; // x0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  unsigned int apf_capabilities; // w0
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  unsigned int v38; // w21
  unsigned int v39; // w21
  unsigned int v40; // w0
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  const char *v49; // x2
  _DWORD *v50; // x22
  double v51; // d0
  double v52; // d1
  double v53; // d2
  double v54; // d3
  double v55; // d4
  double v56; // d5
  double v57; // d6
  double v58; // d7
  __int64 v59; // x0
  double v60; // d0
  double v61; // d1
  double v62; // d2
  double v63; // d3
  double v64; // d4
  double v65; // d5
  double v66; // d6
  double v67; // d7
  __int64 v68; // x21
  double v69; // d0
  double v70; // d1
  double v71; // d2
  double v72; // d3
  double v73; // d4
  double v74; // d5
  double v75; // d6
  double v76; // d7
  double v77; // d0
  double v78; // d1
  double v79; // d2
  double v80; // d3
  double v81; // d4
  double v82; // d5
  double v83; // d6
  double v84; // d7
  double v86; // d0
  double v87; // d1
  double v88; // d2
  double v89; // d3
  double v90; // d4
  double v91; // d5
  double v92; // d6
  double v93; // d7
  int v94; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v95; // [xsp+8h] [xbp-8h]

  v95 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  qdf_trace_msg(0x33u, 8u, "%s: enter", a2, a3, a4, a5, a6, a7, a8, a9, "hdd_get_apf_capabilities");
  v10 = osif_request_alloc(hdd_get_apf_capabilities_params);
  if ( v10 )
  {
    v19 = v10;
    v20 = osif_request_cookie(v10);
    apf_capabilities = sme_get_apf_capabilities(
                         *(_QWORD *)(a1 + 16),
                         (__int64)hdd_get_apf_capabilities_cb,
                         v20,
                         v21,
                         v22,
                         v23,
                         v24,
                         v25,
                         v26,
                         v27,
                         v28);
    if ( apf_capabilities )
    {
      v38 = apf_capabilities;
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Unable to retrieve APF caps",
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        "hdd_get_apf_capabilities");
      v39 = qdf_status_to_os_return(v38);
    }
    else
    {
      v40 = osif_request_wait_for_response(v19);
      if ( v40 )
      {
        v39 = v40;
        v49 = "%s: Target response timed out";
      }
      else
      {
        v50 = (_DWORD *)osif_request_priv(v19);
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: enter",
          v51,
          v52,
          v53,
          v54,
          v55,
          v56,
          v57,
          v58,
          "hdd_post_get_apf_capabilities_rsp");
        v59 = _cfg80211_alloc_reply_skb(*(_QWORD *)(a1 + 24), 103, 197, 32);
        if ( v59 )
        {
          v68 = v59;
          *(_DWORD *)(a1 + 3608) = *v50;
          qdf_trace_msg(
            0x33u,
            8u,
            "%s: APF Version: %u APF max bytes: %u",
            v60,
            v61,
            v62,
            v63,
            v64,
            v65,
            v66,
            v67,
            "hdd_post_get_apf_capabilities_rsp");
          v94 = v50[2];
          if ( !(unsigned int)nla_put(v68, 4, 4, &v94) )
          {
            v94 = *v50;
            if ( !(unsigned int)nla_put(v68, 2, 4, &v94) )
            {
              cfg80211_vendor_cmd_reply(v68);
              qdf_trace_msg(
                0x33u,
                8u,
                "%s: exit",
                v86,
                v87,
                v88,
                v89,
                v90,
                v91,
                v92,
                v93,
                "hdd_post_get_apf_capabilities_rsp");
              v39 = 0;
              goto LABEL_14;
            }
          }
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: nla put failure",
            v69,
            v70,
            v71,
            v72,
            v73,
            v74,
            v75,
            v76,
            "hdd_post_get_apf_capabilities_rsp");
          sk_skb_reason_drop(0, v68, 2);
          v39 = -22;
        }
        else
        {
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: wlan_cfg80211_vendor_cmd_alloc_reply_skb failed",
            v60,
            v61,
            v62,
            v63,
            v64,
            v65,
            v66,
            v67,
            "hdd_post_get_apf_capabilities_rsp");
          v39 = -12;
        }
        v49 = "%s: Failed to post get apf capabilities";
      }
      qdf_trace_msg(0x33u, 2u, v49, v41, v42, v43, v44, v45, v46, v47, v48, "hdd_get_apf_capabilities");
    }
LABEL_14:
    osif_request_put(v19);
    qdf_trace_msg(0x33u, 8u, "%s: exit", v77, v78, v79, v80, v81, v82, v83, v84, "hdd_get_apf_capabilities");
    goto LABEL_15;
  }
  qdf_trace_msg(
    0x33u,
    2u,
    "%s: Unable to allocate request",
    v11,
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    "hdd_get_apf_capabilities");
  v39 = -22;
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return v39;
}
