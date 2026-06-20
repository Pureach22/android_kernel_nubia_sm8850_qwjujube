__int64 __fastcall wlan_cfg80211_coap_offload(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  const char *v14; // x2
  __int64 result; // x0
  int v16; // w20
  unsigned int v17; // w21
  unsigned int v18; // w0
  __int64 v19; // x0
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  __int64 v28; // x23
  __int64 v29; // x0
  __int64 v30; // x25
  __int64 v31; // x0
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  int v40; // w0
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  int v49; // w24
  const char *v50; // x2
  const char *v51; // x3
  __int64 v52; // x0
  __int64 v53; // x0
  __int64 v54; // x25
  __int64 v55; // x0
  double v56; // d0
  double v57; // d1
  double v58; // d2
  double v59; // d3
  double v60; // d4
  double v61; // d5
  double v62; // d6
  double v63; // d7
  int v64; // w0
  unsigned int v65; // w0
  const char *v66; // x2
  const char *v67; // x3
  const char *v68; // x3
  unsigned int v69; // w0
  double v70; // d0
  double v71; // d1
  double v72; // d2
  double v73; // d3
  double v74; // d4
  double v75; // d5
  double v76; // d6
  double v77; // d7
  unsigned int v78; // w24
  const char *v79; // x3
  unsigned int v80; // w0
  __int64 v81; // x0
  int v82; // w8
  int v83; // w8
  unsigned int v84; // w0
  double v85; // d0
  double v86; // d1
  double v87; // d2
  double v88; // d3
  double v89; // d4
  double v90; // d5
  double v91; // d6
  double v92; // d7
  unsigned int v93; // w22
  const char *v94; // x3
  unsigned int v95; // w0
  __int64 v96; // x4
  unsigned int v97; // w19
  unsigned int v98; // w10
  __int16 v99; // t1
  __int16 v100; // w9
  int v101; // w8
  __int64 v102; // [xsp+0h] [xbp-E0h] BYREF
  __int64 v103; // [xsp+8h] [xbp-D8h]
  __int64 v104; // [xsp+10h] [xbp-D0h]
  _WORD *v105; // [xsp+18h] [xbp-C8h]
  _WORD *v106; // [xsp+20h] [xbp-C0h]
  __int64 v107; // [xsp+28h] [xbp-B8h]
  __int64 v108; // [xsp+30h] [xbp-B0h] BYREF
  __int64 v109; // [xsp+38h] [xbp-A8h]
  __int64 v110; // [xsp+40h] [xbp-A0h]
  __int64 v111; // [xsp+48h] [xbp-98h]
  __int64 v112; // [xsp+50h] [xbp-90h]
  _WORD *v113; // [xsp+58h] [xbp-88h]
  __int64 v114; // [xsp+60h] [xbp-80h]
  _WORD *v115; // [xsp+68h] [xbp-78h]
  unsigned __int64 v116; // [xsp+70h] [xbp-70h] BYREF
  __int64 v117; // [xsp+78h] [xbp-68h]
  __int64 v118; // [xsp+80h] [xbp-60h]
  _WORD *v119; // [xsp+88h] [xbp-58h]
  __int16 *v120; // [xsp+90h] [xbp-50h]
  __int64 v121; // [xsp+98h] [xbp-48h]
  __int64 v122; // [xsp+A0h] [xbp-40h] BYREF
  __int64 v123; // [xsp+A8h] [xbp-38h]
  __int64 v124; // [xsp+B0h] [xbp-30h]
  __int64 v125; // [xsp+B8h] [xbp-28h]
  __int16 *v126; // [xsp+C0h] [xbp-20h]
  __int64 v127; // [xsp+C8h] [xbp-18h]
  _WORD *v128; // [xsp+D0h] [xbp-10h]
  __int64 v129; // [xsp+D8h] [xbp-8h]

  v129 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v106 = nullptr;
  v107 = 0;
  v104 = 0;
  v105 = nullptr;
  v102 = 0;
  v103 = 0;
  if ( !(unsigned int)_nla_parse(&v102, 5, a3, a4, &coap_offload_policy, 31, 0) )
  {
    if ( !v103 )
    {
      v14 = "%s: no attr action";
      goto LABEL_3;
    }
    if ( !v104 )
    {
      v14 = "%s: no attr req id";
      goto LABEL_3;
    }
    v16 = *(_DWORD *)(v103 + 4);
    v17 = *(_DWORD *)(v104 + 4);
    v18 = -22;
    if ( v16 > 1 )
    {
      if ( v16 != 2 )
      {
        if ( v16 == 3 )
        {
          v65 = ucfg_coap_offload_periodic_tx_disable();
LABEL_63:
          v18 = qdf_status_to_os_return(v65);
          goto LABEL_64;
        }
        if ( v16 == 4 )
        {
          v19 = osif_request_alloc(&wlan_cfg80211_coap_offload_cache_get_params);
          if ( v19 )
          {
            v28 = v19;
            v29 = osif_request_priv(v19);
            v30 = v29 + 16;
            *(_QWORD *)(v29 + 16) = v29 + 16;
            *(_QWORD *)(v29 + 24) = v29 + 16;
            *(_QWORD *)(v29 + 32) = 0;
            *(_DWORD *)(v29 + 4) = v17;
            *(_BYTE *)v29 = *(_BYTE *)(a2 + 104);
            v31 = osif_request_cookie(v28);
            v40 = ucfg_coap_offload_cache_get(
                    a2,
                    v17,
                    (__int64)wlan_cfg80211_coap_cache_get_cbk,
                    v31,
                    v32,
                    v33,
                    v34,
                    v35,
                    v36,
                    v37,
                    v38,
                    v39);
            if ( v40 )
            {
              v49 = v40;
              v50 = "%s: Unable to get cache";
              v51 = "wlan_cfg80211_coap_offload_cache_get";
LABEL_21:
              qdf_trace_msg(0x9Cu, 2u, v50, v41, v42, v43, v44, v45, v46, v47, v48, v51);
LABEL_61:
              osif_request_put(v28);
              goto LABEL_62;
            }
            v69 = osif_request_wait_for_response(v28);
            if ( v69 )
            {
              v78 = v69;
              v79 = "wlan_cfg80211_coap_offload_cache_get";
LABEL_45:
              qdf_trace_msg(0x9Cu, 2u, "%s: Target response timed out", v70, v71, v72, v73, v74, v75, v76, v77, v79);
              v81 = v78;
LABEL_60:
              v49 = qdf_status_from_os_return(v81);
              goto LABEL_61;
            }
            v84 = wlan_cfg80211_coap_offload_cache_deliver(a1, v30);
            if ( v84 )
            {
              v93 = v84;
              v94 = "wlan_cfg80211_coap_offload_cache_get";
LABEL_59:
              qdf_trace_msg(0x9Cu, 2u, "%s: Failed to deliver buf info", v85, v86, v87, v88, v89, v90, v91, v92, v94);
              v81 = v93;
              goto LABEL_60;
            }
            goto LABEL_65;
          }
          v67 = "wlan_cfg80211_coap_offload_cache_get";
          goto LABEL_33;
        }
        goto LABEL_64;
      }
      v125 = 0;
      v126 = nullptr;
      v123 = 0;
      v124 = 0;
      v122 = 0;
      v119 = nullptr;
      v120 = nullptr;
      v117 = 0;
      v118 = 0;
      v116 = 0;
      if ( !v106 )
      {
        v66 = "%s: No ATTR periodic tx";
LABEL_36:
        v68 = "wlan_cfg80211_coap_offload_periodic_tx_enable";
LABEL_40:
        qdf_trace_msg(0x9Cu, 2u, v66, v6, v7, v8, v9, v10, v11, v12, v13, v68);
        v18 = -22;
        goto LABEL_64;
      }
      if ( ((__int16)v106[1] & 0x80000000) == 0 )
      {
        do_trace_netlink_extack("NLA_F_NESTED is missing");
LABEL_35:
        v66 = "%s: Invalid ATTR";
        goto LABEL_36;
      }
      if ( (unsigned int)_nla_parse(
                           &v122,
                           4,
                           v106 + 2,
                           (unsigned __int16)(*v106 - 4),
                           &coap_offload_periodic_tx_policy,
                           31,
                           0) )
        goto LABEL_35;
      if ( !v125 )
      {
        v66 = "%s: no ATTR period";
        goto LABEL_36;
      }
      v82 = *(_DWORD *)(v125 + 4);
      v112 = 0;
      v113 = nullptr;
      v110 = 0;
      v111 = 0;
      LODWORD(v119) = v82;
      v108 = 0;
      v109 = 0;
      if ( v123 )
      {
        if ( (*(__int16 *)(v123 + 2) & 0x80000000) == 0 )
        {
          do_trace_netlink_extack("NLA_F_NESTED is missing");
LABEL_71:
          v66 = "%s: Invalid ATTR";
          goto LABEL_72;
        }
        if ( (unsigned int)_nla_parse(
                             &v108,
                             5,
                             v123 + 4,
                             (unsigned __int16)(*(_WORD *)v123 - 4),
                             &coap_offload_tx_ipv4_policy,
                             31,
                             0) )
          goto LABEL_71;
        if ( v109 )
        {
          LODWORD(v117) = *(_DWORD *)(v109 + 4);
          if ( v110 )
            WORD2(v117) = *(_DWORD *)(v110 + 4);
          if ( v111 )
          {
            LODWORD(v118) = *(_DWORD *)(v111 + 4);
            BYTE4(v118) = v112 != 0;
            if ( v113 )
            {
              v98 = *(unsigned __int8 *)(a2 + 104);
              HIWORD(v118) = *((_DWORD *)v113 + 1);
              v116 = __PAIR64__(v17, v98);
              if ( v126 )
              {
                v99 = *v126;
                v120 = v126 + 2;
                HIDWORD(v119) = (unsigned __int16)(v99 - 4);
                v65 = ucfg_coap_offload_periodic_tx_enable();
                goto LABEL_63;
              }
              v66 = "%s: no ATTR msg";
              goto LABEL_36;
            }
            v66 = "%s: no ATTR dest IPv4 port";
          }
          else
          {
            v66 = "%s: no ATTR IPv4 dest addr";
          }
        }
        else
        {
          v66 = "%s: no ATTR src addr";
        }
      }
      else
      {
        v66 = "%s: No ATTR TX IPv4";
      }
LABEL_72:
      v68 = "wlan_cfg80211_coap_offload_fill_tx_ipv4";
      goto LABEL_40;
    }
    if ( v16 )
    {
      if ( v16 == 1 )
      {
        v52 = osif_request_alloc("(");
        if ( v52 )
        {
          v28 = v52;
          v53 = osif_request_priv(v52);
          v54 = v53 + 16;
          *(_QWORD *)(v53 + 16) = v53 + 16;
          *(_QWORD *)(v53 + 24) = v53 + 16;
          *(_QWORD *)(v53 + 32) = 0;
          *(_DWORD *)(v53 + 4) = v17;
          *(_BYTE *)v53 = *(_BYTE *)(a2 + 104);
          v55 = osif_request_cookie(v28);
          v64 = ucfg_coap_offload_reply_disable(
                  a2,
                  v17,
                  (__int64)wlan_cfg80211_coap_cache_get_cbk,
                  v55,
                  v56,
                  v57,
                  v58,
                  v59,
                  v60,
                  v61,
                  v62,
                  v63);
          if ( v64 )
          {
            v49 = v64;
            v50 = "%s: Failed to disable offload reply";
            v51 = "wlan_cfg80211_coap_offload_reply_disable";
            goto LABEL_21;
          }
          v80 = osif_request_wait_for_response(v28);
          if ( v80 )
          {
            v78 = v80;
            v79 = "wlan_cfg80211_coap_offload_reply_disable";
            goto LABEL_45;
          }
          v95 = wlan_cfg80211_coap_offload_cache_deliver(a1, v54);
          if ( v95 )
          {
            v93 = v95;
            v94 = "wlan_cfg80211_coap_offload_reply_disable";
            goto LABEL_59;
          }
LABEL_65:
          v49 = 0;
          goto LABEL_61;
        }
        v67 = "wlan_cfg80211_coap_offload_reply_disable";
LABEL_33:
        v49 = 2;
        qdf_trace_msg(0x9Cu, 2u, "%s: Request allocation failure", v20, v21, v22, v23, v24, v25, v26, v27, v67);
LABEL_62:
        v65 = v49;
        goto LABEL_63;
      }
LABEL_64:
      v96 = *(unsigned __int8 *)(a2 + 104);
      v97 = v18;
      qdf_trace_msg(
        0x9Cu,
        8u,
        "%s: vdev_id %u action %u req id %u ret %d",
        v6,
        v7,
        v8,
        v9,
        v10,
        v11,
        v12,
        v13,
        "wlan_cfg80211_coap_offload",
        v96,
        (unsigned int)v16,
        v17,
        v18);
      result = v97;
      goto LABEL_4;
    }
    v120 = nullptr;
    v121 = 0;
    v118 = 0;
    v119 = nullptr;
    v116 = 0;
    v117 = 0;
    v114 = 0;
    v115 = nullptr;
    v112 = 0;
    v113 = nullptr;
    v110 = 0;
    v111 = 0;
    v108 = 0;
    v109 = 0;
    if ( !v105 )
    {
      v66 = "%s: No ATTR reply";
LABEL_39:
      v68 = "wlan_cfg80211_coap_offload_reply_enable";
      goto LABEL_40;
    }
    if ( ((__int16)v105[1] & 0x80000000) == 0 )
    {
      do_trace_netlink_extack("NLA_F_NESTED is missing");
LABEL_38:
      v66 = "%s: Invalid ATTR";
      goto LABEL_39;
    }
    if ( (unsigned int)_nla_parse(&v116, 5, v105 + 2, (unsigned __int16)(*v105 - 4), &coap_offload_reply_policy, 31, 0) )
      goto LABEL_38;
    if ( !v117 )
    {
      v66 = "%s: No ATTR IPv4";
      goto LABEL_39;
    }
    LODWORD(v108) = *(unsigned __int8 *)(a2 + 104);
    HIDWORD(v108) = v17;
    v83 = *(_DWORD *)(v117 + 4);
    v127 = 0;
    v128 = nullptr;
    v125 = 0;
    v126 = nullptr;
    HIDWORD(v109) = v83;
    v123 = 0;
    v124 = 0;
    v122 = 0;
    if ( v119 )
    {
      if ( v119 == (_WORD *)-4LL )
      {
        v66 = "%s: Invalid filter";
      }
      else
      {
        if ( ((__int16)v119[1] & 0x80000000) == 0 )
        {
          do_trace_netlink_extack("NLA_F_NESTED is missing");
LABEL_75:
          v66 = "%s: Invalid ATTR";
          goto LABEL_76;
        }
        if ( (unsigned int)_nla_parse(
                             &v122,
                             6,
                             v119 + 2,
                             (unsigned __int16)(*v119 - 4),
                             &coap_offload_filter_policy,
                             31,
                             0) )
          goto LABEL_75;
        if ( v123 )
        {
          HIDWORD(v110) = *(_DWORD *)(v123 + 4);
          LOBYTE(v111) = v124 != 0;
          if ( v126 )
          {
            WORD1(v111) = v126[2];
            if ( v127 )
            {
              HIDWORD(v111) = *(_DWORD *)(v127 + 4);
              if ( v128 )
              {
                LODWORD(v112) = (unsigned __int16)(*v128 - 4);
                if ( (_DWORD)v112 )
                {
                  v113 = v128 + 2;
                  if ( v120 )
                  {
                    v100 = *v120;
                    v115 = v120 + 2;
                    LODWORD(v114) = (unsigned __int16)(v100 - 4);
                    if ( v121 )
                      v101 = *(_DWORD *)(v121 + 4);
                    else
                      v101 = 40000;
                    LODWORD(v109) = v101;
                    v65 = ucfg_coap_offload_reply_enable();
                    goto LABEL_63;
                  }
                  v66 = "%s: No ATTR msg";
                  goto LABEL_39;
                }
                v66 = "%s: invalid match data len";
              }
              else
              {
                v66 = "%s: no ATTR match data";
              }
            }
            else
            {
              v66 = "%s: no ATTR match offset";
            }
          }
          else
          {
            v66 = "%s: no ATTR dest IPv4 port";
          }
        }
        else
        {
          v66 = "%s: no ATTR dest IPv4";
        }
      }
    }
    else
    {
      v66 = "%s: No ATTR filter";
    }
LABEL_76:
    v68 = "wlan_cfg80211_coap_offload_reply_fill_filter";
    goto LABEL_40;
  }
  v14 = "%s: Invalid ATTR";
LABEL_3:
  qdf_trace_msg(0x9Cu, 2u, v14, v6, v7, v8, v9, v10, v11, v12, v13, "wlan_cfg80211_coap_offload");
  result = 4294967274LL;
LABEL_4:
  _ReadStatusReg(SP_EL0);
  return result;
}
