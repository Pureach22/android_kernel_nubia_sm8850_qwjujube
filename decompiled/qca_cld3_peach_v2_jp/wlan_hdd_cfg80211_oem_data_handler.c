__int64 __fastcall wlan_hdd_cfg80211_oem_data_handler(__int64 a1, __int64 a2, __int64 a3, unsigned int a4)
{
  __int64 v8; // x0
  __int64 result; // x0
  __int64 v10; // x23
  __int64 *v11; // x19
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  int v20; // w0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  __int64 v37; // x23
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  const char *v46; // x2
  unsigned int v47; // w19
  _WORD *v48; // x8
  int v49; // w9
  char v50; // w3
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
  double v61; // d0
  double v62; // d1
  double v63; // d2
  double v64; // d3
  double v65; // d4
  double v66; // d5
  double v67; // d6
  double v68; // d7
  int v69; // w22
  int v70; // w0
  double v71; // d0
  double v72; // d1
  double v73; // d2
  double v74; // d3
  double v75; // d4
  double v76; // d5
  double v77; // d6
  double v78; // d7
  unsigned int v79; // w0
  __int64 v80; // x0
  double v81; // d0
  double v82; // d1
  double v83; // d2
  double v84; // d3
  double v85; // d4
  double v86; // d5
  double v87; // d6
  double v88; // d7
  __int64 v89; // x22
  __int64 v90; // x0
  double v91; // d0
  double v92; // d1
  double v93; // d2
  double v94; // d3
  double v95; // d4
  double v96; // d5
  double v97; // d6
  double v98; // d7
  __int64 v99; // x20
  double v100; // d0
  double v101; // d1
  double v102; // d2
  double v103; // d3
  double v104; // d4
  double v105; // d5
  double v106; // d6
  double v107; // d7
  __int64 v108; // [xsp+8h] [xbp-68h] BYREF
  __int64 v109; // [xsp+10h] [xbp-60h] BYREF
  __int64 v110; // [xsp+18h] [xbp-58h]
  __int64 v111; // [xsp+20h] [xbp-50h]
  _WORD *v112; // [xsp+28h] [xbp-48h]
  __int64 v113; // [xsp+30h] [xbp-40h]
  __int64 v114; // [xsp+38h] [xbp-38h]
  _BYTE v115[4]; // [xsp+44h] [xbp-2Ch] BYREF
  __int64 v116; // [xsp+48h] [xbp-28h] BYREF
  _WORD *v117; // [xsp+50h] [xbp-20h]
  __int64 v118; // [xsp+58h] [xbp-18h]
  __int64 v119; // [xsp+60h] [xbp-10h]
  __int64 v120; // [xsp+68h] [xbp-8h]

  v120 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = *(_QWORD *)(a2 + 32);
  v108 = 0;
  result = _osif_vdev_sync_op_start(v8, &v108, "wlan_hdd_cfg80211_oem_data_handler");
  if ( !(_DWORD)result )
  {
    v10 = *(_QWORD *)(a2 + 32);
    v115[0] = 0;
    v113 = 0;
    v114 = 0;
    v11 = *(__int64 **)(v10 + 2712);
    v111 = 0;
    v112 = nullptr;
    v109 = 0;
    v110 = 0;
    v118 = 0;
    v119 = 0;
    v116 = 0;
    v117 = nullptr;
    if ( (unsigned int)hdd_get_conparam() == 5 )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Command not allowed in FTM mode",
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        "__wlan_hdd_cfg80211_oem_data_handler");
      v20 = -1;
LABEL_12:
      v47 = v20;
      _osif_vdev_sync_op_stop(v108, "wlan_hdd_cfg80211_oem_data_handler");
      result = v47;
      goto LABEL_13;
    }
    v20 = _wlan_hdd_validate_context(
            (__int64)v11,
            (__int64)"__wlan_hdd_cfg80211_oem_data_handler",
            v12,
            v13,
            v14,
            v15,
            v16,
            v17,
            v18,
            v19);
    if ( v20 )
      goto LABEL_12;
    if ( (unsigned int)_hdd_validate_adapter(
                         v10 + 2688,
                         (__int64)"__wlan_hdd_cfg80211_oem_data_handler",
                         v21,
                         v22,
                         v23,
                         v24,
                         v25,
                         v26,
                         v27,
                         v28) )
    {
LABEL_11:
      v20 = -22;
      goto LABEL_12;
    }
    v37 = v10 + 53248;
    if ( *(_BYTE *)(v37 + 1888) == 1 )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: oem request already in progress",
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        "__wlan_hdd_cfg80211_oem_data_handler");
      v20 = -16;
      goto LABEL_12;
    }
    if ( (unsigned int)_nla_parse(&v116, 3, a3, a4, &oem_data_attr_policy, 31, 0) )
    {
      v46 = "%s: Invalid attributes";
LABEL_10:
      qdf_trace_msg(0x33u, 2u, v46, v38, v39, v40, v41, v42, v43, v44, v45, "__wlan_hdd_cfg80211_oem_data_handler");
      goto LABEL_11;
    }
    v48 = v117;
    if ( !v117 )
    {
      v46 = "%s: oem data is missing!";
      goto LABEL_10;
    }
    if ( v118 )
    {
      v49 = *(unsigned __int8 *)(v118 + 4);
      BYTE1(v111) = v49 != 0;
      if ( !v49 )
        goto LABEL_23;
    }
    else if ( (v111 & 0x100) == 0 )
    {
      goto LABEL_23;
    }
    if ( (unsigned int)policy_mgr_get_mac_id_by_session_id(*v11, *(_BYTE *)(*(_QWORD *)(v37 + 2264) + 8LL), v115) )
    {
      v46 = "%s: get mac id failed";
      goto LABEL_10;
    }
    v48 = v117;
    BYTE2(v111) = 1;
    LOBYTE(v111) = v115[0];
LABEL_23:
    v110 = (unsigned __int16)(*v48 - 4);
    if ( !(_DWORD)v110 )
    {
      v46 = "%s: oem data len is 0!";
      goto LABEL_10;
    }
    v50 = *(_BYTE *)(*(_QWORD *)(v37 + 2264) + 8LL);
    v112 = v48 + 2;
    LOBYTE(v109) = v50;
    if ( v119 )
    {
      *(_BYTE *)(v37 + 1904) = 1;
    }
    else if ( (*(_BYTE *)(v37 + 1904) & 1) == 0 )
    {
      v79 = sme_oem_data_cmd(v11[2], hdd_oem_event_handler_cb, &v109);
      v20 = qdf_status_to_os_return(v79);
      goto LABEL_12;
    }
    *(_BYTE *)(v37 + 1888) = 1;
    qdf_runtime_pm_prevent_suspend(v11 + 216);
    v51 = osif_request_alloc(&_wlan_hdd_cfg80211_oem_data_handler_params);
    if ( !v51 )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: request allocation failure",
        v52,
        v53,
        v54,
        v55,
        v56,
        v57,
        v58,
        v59,
        "__wlan_hdd_cfg80211_oem_data_handler");
      v69 = -12;
LABEL_43:
      *(_BYTE *)(v37 + 1888) = 0;
      *(_BYTE *)(v37 + 1904) = 0;
      qdf_runtime_pm_allow_suspend(v11 + 216);
      v20 = v69;
      goto LABEL_12;
    }
    v60 = v51;
    *(_QWORD *)(v37 + 1896) = osif_request_cookie(v51);
    if ( (unsigned int)sme_oem_data_cmd(v11[2], hdd_oem_event_handler_cb, &v109) )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Failure while sending command to fw",
        v61,
        v62,
        v63,
        v64,
        v65,
        v66,
        v67,
        v68,
        "__wlan_hdd_cfg80211_oem_data_handler");
      v69 = -11;
    }
    else
    {
      v70 = osif_request_wait_for_response(v60);
      if ( v70 )
      {
        v69 = v70;
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: Timedout while retrieving oem get data",
          v71,
          v72,
          v73,
          v74,
          v75,
          v76,
          v77,
          v78,
          "__wlan_hdd_cfg80211_oem_data_handler");
      }
      else
      {
        v80 = osif_request_priv(v60);
        if ( v80 && *(_QWORD *)(v80 + 24) )
        {
          v89 = v80;
          v90 = _cfg80211_alloc_reply_skb(a1, 103, 197, ((*(_DWORD *)(v80 + 8) + 7) & 0xFFFFFFFC) + 16);
          if ( !v90 )
          {
            qdf_trace_msg(
              0x33u,
              2u,
              "%s: wlan_cfg80211_vendor_cmd_alloc_reply_skb failed",
              v91,
              v92,
              v93,
              v94,
              v95,
              v96,
              v97,
              v98,
              "__wlan_hdd_cfg80211_oem_data_handler");
            v69 = -12;
            goto LABEL_42;
          }
          v99 = v90;
          if ( !(unsigned int)nla_put(v90, 1, *(unsigned int *)(v89 + 8), *(_QWORD *)(v89 + 24)) )
          {
            cfg80211_vendor_cmd_reply(v99);
            v69 = 0;
            goto LABEL_42;
          }
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: nla put failure",
            v100,
            v101,
            v102,
            v103,
            v104,
            v105,
            v106,
            v107,
            "__wlan_hdd_cfg80211_oem_data_handler");
          sk_skb_reason_drop(0, v99, 2);
        }
        else
        {
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: invalid get_oem_data",
            v81,
            v82,
            v83,
            v84,
            v85,
            v86,
            v87,
            v88,
            "__wlan_hdd_cfg80211_oem_data_handler");
        }
        v69 = -22;
      }
    }
LABEL_42:
    osif_request_put(v60);
    goto LABEL_43;
  }
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return result;
}
