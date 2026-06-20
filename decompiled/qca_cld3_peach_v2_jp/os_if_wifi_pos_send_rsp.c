__int64 __fastcall os_if_wifi_pos_send_rsp(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        unsigned int a10,
        int a11,
        unsigned int a12,
        char *a13)
{
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  unsigned __int8 v25; // w24
  int *v26; // x26
  unsigned __int8 v27; // t1
  const char *v28; // x2
  const char *v29; // x3
  __int64 result; // x0
  __int64 v31; // x0
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  __int64 v40; // x24
  __int64 v41; // x23
  __int16 v42; // w8
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  unsigned int v51; // w20
  unsigned int v52; // w25
  __int64 v53; // x0
  double v54; // d0
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7
  __int64 v62; // x24
  __int64 v63; // x22
  __int64 v64; // x23
  double v65; // d0
  double v66; // d1
  double v67; // d2
  double v68; // d3
  double v69; // d4
  double v70; // d5
  double v71; // d6
  double v72; // d7
  _WORD *v73; // x22
  double v74; // d0
  double v75; // d1
  double v76; // d2
  double v77; // d3
  double v78; // d4
  double v79; // d5
  double v80; // d6
  double v81; // d7
  unsigned int v82; // w20
  __int64 v83; // x28
  __int64 v84; // x0
  double v85; // d0
  double v86; // d1
  double v87; // d2
  double v88; // d3
  double v89; // d4
  double v90; // d5
  double v91; // d6
  double v92; // d7
  __int64 v93; // x23
  __int64 v94; // x20
  __int64 v95; // x21
  double v96; // d0
  double v97; // d1
  double v98; // d2
  double v99; // d3
  double v100; // d4
  double v101; // d5
  double v102; // d6
  double v103; // d7
  __int64 v104; // x20
  __int64 v105; // x21
  _WORD *v106; // x22
  int v107; // w25
  int *v108; // x20
  __int64 v109; // x27
  __int64 v110; // x21
  _WORD *v111; // x27
  __int64 v112; // x0
  __int64 v113; // x21
  __int64 v114; // x20
  __int64 v115; // x22
  double v116; // d0
  double v117; // d1
  double v118; // d2
  double v119; // d3
  double v120; // d4
  double v121; // d5
  double v122; // d6
  double v123; // d7
  _WORD *v124; // x22
  double v125; // d0
  double v126; // d1
  double v127; // d2
  double v128; // d3
  double v129; // d4
  double v130; // d5
  double v131; // d6
  double v132; // d7
  const char *v133; // x3
  int v134; // w8
  __int64 v135; // x4
  __int64 v136; // x0
  __int64 v137; // x20
  __int64 v138; // x22
  __int64 v139; // x20
  __int64 v140; // x23
  _WORD *v141; // x20
  const char *v142; // x3
  _WORD *v143; // [xsp+0h] [xbp-30h]
  _WORD *v144; // [xsp+8h] [xbp-28h] BYREF
  unsigned int v145; // [xsp+14h] [xbp-1Ch] BYREF
  __int64 v146; // [xsp+18h] [xbp-18h] BYREF
  int v147; // [xsp+24h] [xbp-Ch] BYREF
  __int64 v148; // [xsp+28h] [xbp-8h]

  v148 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a10 )
  {
    v28 = "%s: invalid dest pid";
    v29 = "os_if_wifi_pos_send_rsp";
    goto LABEL_8;
  }
  if ( (ucfg_wifi_pos_is_nl_rsp() & 1) != 0 )
  {
    if ( a11 > 4 )
    {
      if ( a11 != 7 )
      {
        if ( a11 == 5 )
        {
          while ( 1 )
          {
            v51 = ((a12 + 7) & 0xFFFFFFFC) - 7693;
            v146 = 0;
            v145 = 3264;
            if ( v51 >= 0xFFFFE17F )
              v52 = a12;
            else
              v52 = 7688;
            v144 = nullptr;
            v53 = cld80211_oem_rsp_alloc_skb(a10, &v146, &v144, &v145);
            if ( !v53 )
            {
              qdf_trace_msg(
                0x48u,
                2u,
                "%s: alloc_skb failed",
                v54,
                v55,
                v56,
                v57,
                v58,
                v59,
                v60,
                v61,
                "os_if_create_oemdata_resp");
              goto LABEL_63;
            }
            v62 = v53;
            v147 = 5;
            nla_put(v53, 4, 4, &v147);
            v63 = *(_QWORD *)(v62 + 216);
            v64 = *(unsigned int *)(v62 + 208);
            if ( (nla_put(v62, 32773, 0, 0) & 0x80000000) != 0 )
              break;
            v73 = (_WORD *)(v63 + v64);
            if ( !v73 )
              break;
            if ( v51 <= 0xFFFFE17E )
              nla_put(v62, 1, 0, 0);
            nla_put(v62, 2, v52, a13);
            *v73 = *(_WORD *)(v62 + 216) + *(_DWORD *)(v62 + 208) - (_WORD)v73;
            qdf_trace_msg(
              0x48u,
              8u,
              "%s: sending oem rsp: type: %d to pid (%d)",
              v43,
              v44,
              v45,
              v46,
              v47,
              v48,
              v49,
              v50,
              "os_if_create_oemdata_resp",
              5,
              a10);
            result = cld80211_oem_send_reply((_DWORD *)v62, v146, v144, v145);
            a13 += 7688;
            a12 -= 7688;
            if ( v51 >= 0xFFFFE17F )
              goto LABEL_66;
          }
          qdf_trace_msg(
            0x48u,
            2u,
            "%s: failed to fill CHAN_RESP attributes",
            v65,
            v66,
            v67,
            v68,
            v69,
            v70,
            v71,
            v72,
            "os_if_create_oemdata_resp");
          consume_skb(v62);
LABEL_63:
          v28 = "%s: failed to alloc memory for oem_nl_resp";
          v29 = "os_if_send_oem_data_nl_resp";
          goto LABEL_8;
        }
        goto LABEL_44;
      }
      v146 = 0;
      v145 = 3264;
      v144 = nullptr;
      v136 = cld80211_oem_rsp_alloc_skb(a10, &v146, &v144, &v145);
      if ( v136 )
      {
        v113 = v136;
        v147 = 7;
        nla_put(v136, 4, 4, &v147);
        v137 = *(_QWORD *)(v113 + 216);
        v138 = *(unsigned int *)(v113 + 208);
        if ( (nla_put(v113, 32773, 0, 0) & 0x80000000) == 0 )
        {
          v124 = (_WORD *)(v137 + v138);
          if ( v124 )
          {
            nla_put(v113, 1, 6, a13);
            LOBYTE(v147) = a13[6];
            nla_put(v113, 2, 1, &v147);
            LOBYTE(v147) = a13[7];
            nla_put(v113, 3, 1, &v147);
            v147 = *((_DWORD *)a13 + 2);
            nla_put(v113, 4, 4, &v147);
            v147 = *((_DWORD *)a13 + 3);
            nla_put(v113, 5, 4, &v147);
            v139 = *(_QWORD *)(v113 + 216);
            v140 = *(unsigned int *)(v113 + 208);
            if ( (nla_put(v113, 32774, 0, 0) & 0x80000000) == 0 )
            {
              v141 = (_WORD *)(v139 + v140);
              if ( v141 )
              {
                v147 = *((_DWORD *)a13 + 4);
                nla_put(v113, 4, 4, &v147);
                v147 = *((_DWORD *)a13 + 6);
                nla_put(v113, 5, 4, &v147);
                v147 = *((_DWORD *)a13 + 7);
                nla_put(v113, 6, 4, &v147);
                v147 = *((_DWORD *)a13 + 8);
                nla_put(v113, 7, 4, &v147);
                v147 = *((_DWORD *)a13 + 9);
                nla_put(v113, 8, 4, &v147);
                v147 = *((_DWORD *)a13 + 10);
                nla_put(v113, 9, 4, &v147);
                v147 = *((_DWORD *)a13 + 11);
                nla_put(v113, 10, 4, &v147);
                v133 = "os_if_wifi_pos_send_peer_nl_status";
                v135 = 7;
                *v141 = *(_DWORD *)(v113 + 216) + *(_DWORD *)(v113 + 208) - (_WORD)v141;
                v134 = *(_DWORD *)(v113 + 216) + *(_DWORD *)(v113 + 208) - (_DWORD)v124;
                goto LABEL_55;
              }
            }
          }
        }
        v142 = "os_if_wifi_pos_send_peer_nl_status";
LABEL_65:
        qdf_trace_msg(0x48u, 2u, "%s: nla_nest_start failed", v116, v117, v118, v119, v120, v121, v122, v123, v142);
        result = consume_skb(v113);
        goto LABEL_66;
      }
      v28 = "%s: alloc_skb failed";
      v29 = "os_if_wifi_pos_send_peer_nl_status";
    }
    else
    {
      if ( a11 != 3 )
      {
        if ( a11 == 4 )
        {
          v27 = *a13;
          v26 = (int *)(a13 + 1);
          v25 = v27;
          while ( 1 )
          {
            v146 = 0;
            v83 = v25 >= 0x70u ? 112LL : v25;
            v145 = 3264;
            v144 = nullptr;
            v84 = cld80211_oem_rsp_alloc_skb(a10, &v146, &v144, &v145);
            if ( !v84 )
              break;
            v93 = v84;
            v147 = 4;
            nla_put(v84, 4, 4, &v147);
            v94 = *(_QWORD *)(v93 + 216);
            v95 = *(unsigned int *)(v93 + 208);
            if ( (nla_put(v93, 32773, 0, 0) & 0x80000000) != 0 )
              goto LABEL_56;
            v143 = (_WORD *)(v94 + v95);
            if ( !(v94 + v95) )
              goto LABEL_56;
            if ( v25 >= 0x71u )
              nla_put(v93, 1, 0, 0);
            v147 = v83;
            nla_put(v93, 2, 4, &v147);
            v104 = *(_QWORD *)(v93 + 216);
            v105 = *(unsigned int *)(v93 + 208);
            if ( (nla_put(v93, 32771, 0, 0) & 0x80000000) != 0 )
              goto LABEL_56;
            v106 = (_WORD *)(v104 + v105);
            if ( !(v104 + v105) )
              goto LABEL_56;
            if ( v25 )
            {
              v107 = 0;
              v108 = v26;
              while ( 1 )
              {
                v109 = *(_QWORD *)(v93 + 216);
                v110 = *(unsigned int *)(v93 + 208);
                if ( (nla_put(v93, v107 | 0x8000u, 0, 0) & 0x80000000) != 0 )
                  break;
                v111 = (_WORD *)(v109 + v110);
                if ( !v111 )
                  break;
                v147 = *v108;
                nla_put(v93, 4, 4, &v147);
                v147 = v108[2];
                nla_put(v93, 5, 4, &v147);
                v147 = v108[3];
                nla_put(v93, 6, 4, &v147);
                v147 = v108[4];
                nla_put(v93, 7, 4, &v147);
                v147 = v108[5];
                nla_put(v93, 8, 4, &v147);
                v147 = v108[6];
                nla_put(v93, 9, 4, &v147);
                v147 = v108[7];
                nla_put(v93, 10, 4, &v147);
                ++v107;
                v108 += 8;
                *v111 = *(_WORD *)(v93 + 216) + *(_DWORD *)(v93 + 208) - (_WORD)v111;
                if ( (_DWORD)v83 == v107 )
                  goto LABEL_27;
              }
LABEL_56:
              qdf_trace_msg(
                0x48u,
                2u,
                "%s: failed to fill CHAN_RESP attributes",
                v96,
                v97,
                v98,
                v99,
                v100,
                v101,
                v102,
                v103,
                "os_if_create_ch_nl_resp",
                v143);
              consume_skb(v93);
              goto LABEL_57;
            }
LABEL_27:
            *v106 = *(_DWORD *)(v93 + 216) + *(_DWORD *)(v93 + 208) - (_WORD)v106;
            v82 = v25;
            *v143 = *(_WORD *)(v93 + 216) + *(_WORD *)(v93 + 208) - (_WORD)v143;
            qdf_trace_msg(
              0x48u,
              8u,
              "%s: sending oem rsp: type: %d to pid (%d)",
              v96,
              v97,
              v98,
              v99,
              v100,
              v101,
              v102,
              v103,
              "os_if_create_ch_nl_resp",
              4,
              a10,
              v143);
            result = cld80211_oem_send_reply((_DWORD *)v93, v146, v144, v145);
            v26 += 8 * v83;
            v25 -= v83;
            if ( v82 <= 0x70 )
              goto LABEL_66;
          }
          qdf_trace_msg(
            0x48u,
            2u,
            "%s: alloc_skb failed",
            v85,
            v86,
            v87,
            v88,
            v89,
            v90,
            v91,
            v92,
            "os_if_create_ch_nl_resp");
LABEL_57:
          v28 = "%s: failed to alloc memory for ch_nl_resp";
          v29 = "os_if_send_chan_nl_resp";
          goto LABEL_8;
        }
LABEL_44:
        result = qdf_trace_msg(
                   0x48u,
                   2u,
                   "%s: response message is invalid :%d",
                   v17,
                   v18,
                   v19,
                   v20,
                   v21,
                   v22,
                   v23,
                   v24,
                   "os_if_send_nl_resp",
                   (unsigned int)a11);
        goto LABEL_66;
      }
      v146 = 0;
      v145 = 3264;
      v144 = nullptr;
      v112 = cld80211_oem_rsp_alloc_skb(a10, &v146, &v144, &v145);
      if ( v112 )
      {
        v113 = v112;
        v147 = 3;
        nla_put(v112, 4, 4, &v147);
        v114 = *(_QWORD *)(v113 + 216);
        v115 = *(unsigned int *)(v113 + 208);
        if ( (nla_put(v113, 32773, 0, 0) & 0x80000000) == 0 )
        {
          v124 = (_WORD *)(v114 + v115);
          if ( v124 )
          {
            nla_put(v113, 1, 8, "QUALCOMM");
            v147 = *((_DWORD *)a13 + 2);
            nla_put(v113, 2, 4, &v147);
            v147 = *((_DWORD *)a13 + 3);
            nla_put(v113, 3, 4, &v147);
            LOBYTE(v147) = a13[16];
            nla_put(v113, 4, 1, &v147);
            LOBYTE(v147) = a13[17];
            nla_put(v113, 5, 1, &v147);
            LOBYTE(v147) = a13[18];
            nla_put(v113, 6, 1, &v147);
            LOBYTE(v147) = a13[19];
            nla_put(v113, 7, 1, &v147);
            LOWORD(v147) = *((_WORD *)a13 + 10);
            nla_put(v113, 8, 2, &v147);
            LOWORD(v147) = *((_WORD *)a13 + 11);
            nla_put(v113, 9, 2, &v147);
            LOWORD(v147) = *((_WORD *)a13 + 12);
            nla_put(v113, 10, 2, &v147);
            LOWORD(v147) = *((_WORD *)a13 + 13);
            nla_put(v113, 11, 2, &v147);
            LOWORD(v147) = *((_WORD *)a13 + 14);
            nla_put(v113, 12, 2, &v147);
            nla_put(v113, 13, 8, a13 + 160);
            v133 = "os_if_send_cap_nl_resp";
            v134 = *(_DWORD *)(v113 + 216) + *(_DWORD *)(v113 + 208) - (_DWORD)v124;
            v135 = 3;
LABEL_55:
            *v124 = v134;
            qdf_trace_msg(
              0x48u,
              8u,
              "%s: sending oem rsp: type: %d to pid (%d)",
              v125,
              v126,
              v127,
              v128,
              v129,
              v130,
              v131,
              v132,
              v133,
              v135,
              a10);
            result = cld80211_oem_send_reply((_DWORD *)v113, v146, v144, v145);
            goto LABEL_66;
          }
        }
        v142 = "os_if_send_cap_nl_resp";
        goto LABEL_65;
      }
      v28 = "%s: alloc_skb failed";
      v29 = "os_if_send_cap_nl_resp";
    }
LABEL_8:
    result = qdf_trace_msg(0x48u, 2u, v28, a1, a2, a3, a4, a5, a6, a7, a8, v29, v143);
    goto LABEL_66;
  }
  v31 = _alloc_skb((a12 + 23) & 0xFFFFFFFC, 2080, 0, 0xFFFFFFFFLL);
  if ( v31 )
  {
    v40 = *(_QWORD *)(v31 + 224);
    v41 = v31;
    *(_QWORD *)(v40 + 8) = 0;
    *(_DWORD *)v40 = a12 + 20;
    *(_DWORD *)(v40 + 4) = 25;
    if ( (unsigned int)(a11 - 1) >= 7 )
    {
      qdf_trace_msg(
        0x48u,
        2u,
        "%s: response message is invalid :%d",
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        v39,
        "map_wifi_pos_cmd_to_ani_msg_rsp",
        (unsigned int)a11);
      v42 = -22;
    }
    else
    {
      v42 = word_A2BFEC[a11 - 1];
    }
    *(_WORD *)(v40 + 16) = v42;
    qdf_mem_copy((void *)(v40 + 20), a13, a12);
    *(_WORD *)(v40 + 18) = a12;
    skb_put(v41, (a12 + 23) & 0xFFFFFFFC);
    qdf_trace_msg(
      0x48u,
      8u,
      "%s: sending oem rsp: type: %d len(%d) to pid (%d)",
      v74,
      v75,
      v76,
      v77,
      v78,
      v79,
      v80,
      v81,
      "os_if_wifi_pos_send_rsp",
      *(unsigned __int16 *)(v40 + 16),
      a12,
      a10);
    result = nl_srv_ucast_oem(v41, a10);
  }
  else
  {
    result = qdf_trace_msg(
               0x48u,
               1u,
               "%s: alloc_skb failed",
               v32,
               v33,
               v34,
               v35,
               v36,
               v37,
               v38,
               v39,
               "os_if_wifi_pos_send_rsp");
  }
LABEL_66:
  _ReadStatusReg(SP_EL0);
  return result;
}
