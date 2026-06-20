__int64 __fastcall wma_check_and_process_rmf_frame(
        __int64 *a1,
        unsigned __int8 a2,
        __int64 *a3,
        __int64 a4,
        __int64 a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13)
{
  __int64 v17; // x27
  __int64 v18; // x22
  _QWORD *peer; // x0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 v29; // x24
  char peer_pmf_status; // w25
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  __int64 result; // x0
  char v48; // w8
  __int64 v49; // x23
  _BYTE *key; // x0
  char v51; // w8
  int v52; // w10
  int v53; // w26
  const char *v54; // x2
  const char *v55; // x3
  __int64 v56; // x28
  int v57; // w24
  int param; // w0
  __int64 v59; // x4
  const char *v60; // x2
  const char *v61; // x3
  int v62; // w9
  int v63; // w8
  __int64 v64; // x24
  __int64 v65; // x25
  __int64 v66; // x26
  _QWORD *peer_by_mac; // x0
  __int64 v68; // x23
  __int64 comp_private_obj; // x0
  double v70; // d0
  double v71; // d1
  double v72; // d2
  double v73; // d3
  double v74; // d4
  double v75; // d5
  double v76; // d6
  double v77; // d7
  unsigned __int64 v78; // x8
  unsigned __int64 *v79; // x9
  __int64 v80; // x22
  __int64 v81; // x24
  double v82; // d0
  double v83; // d1
  double v84; // d2
  double v85; // d3
  double v86; // d4
  double v87; // d5
  double v88; // d6
  double v89; // d7
  __int64 v90; // x20
  int v91; // w25
  unsigned __int8 mmie_size; // w0
  unsigned __int64 v93; // x26
  unsigned __int8 v94; // w24
  double v95; // d0
  double v96; // d1
  double v97; // d2
  double v98; // d3
  double v99; // d4
  double v100; // d5
  double v101; // d6
  double v102; // d7
  double v103; // d0
  double v104; // d1
  double v105; // d2
  double v106; // d3
  double v107; // d4
  double v108; // d5
  double v109; // d6
  double v110; // d7
  const char *v111; // x2
  double v112; // d0
  double v113; // d1
  double v114; // d2
  double v115; // d3
  double v116; // d4
  double v117; // d5
  double v118; // d6
  double v119; // d7
  __int64 v120; // x8
  __int64 v121; // x1
  unsigned __int8 *v122; // x8
  int v123; // w9
  int v124; // w10
  __int64 v125; // x5
  __int64 v126; // x4
  __int64 v127; // x5
  __int64 v128; // x6
  __int64 v129; // x7
  unsigned __int8 v130[4]; // [xsp+10h] [xbp-10h] BYREF
  unsigned __int8 v131[4]; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v132; // [xsp+18h] [xbp-8h]

  v132 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v17 = a1[65] + 488LL * a2;
  v18 = *a3;
  if ( (*(_DWORD *)(v17 + 164) | 2) == 7 || *(_BYTE *)(v17 + 210) )
  {
    if ( (*(_BYTE *)(v18 + 4) & 1) != 0 )
      goto LABEL_17;
    if ( *(_DWORD *)(v18 + 4) == -1 && *(__int16 *)(v18 + 8) == -1 )
      goto LABEL_17;
    if ( v18 == -10 )
    {
      qdf_trace_msg(0x36u, 2u, "%s: peer_mac is NULL", a6, a7, a8, a9, a10, a11, a12, a13, "wma_get_peer_pmf_status");
    }
    else
    {
      peer = wlan_objmgr_get_peer(a1[3], *(_BYTE *)(a1[4] + 40), (_BYTE *)(v18 + 10), 8u);
      if ( peer )
      {
        v29 = (__int64)peer;
        peer_pmf_status = mlme_get_peer_pmf_status((__int64)peer);
        wlan_objmgr_peer_release_ref(v29, 8u, v31, v32, v33, v34, v35, v36, v37, v38);
        qdf_trace_msg(
          0x36u,
          8u,
          "get is_pmf_enabled %d for %02x:%02x:%02x:**:**:%02x",
          v39,
          v40,
          v41,
          v42,
          v43,
          v44,
          v45,
          v46,
          peer_pmf_status & 1,
          *(unsigned __int8 *)(v18 + 10),
          *(unsigned __int8 *)(v18 + 11),
          *(unsigned __int8 *)(v18 + 12),
          *(unsigned __int8 *)(v18 + 15));
        if ( (peer_pmf_status & 1) != 0 )
          goto LABEL_17;
      }
      else
      {
        qdf_trace_msg(
          0x36u,
          8u,
          "%s: Peer of peer_mac %02x:%02x:%02x:**:**:%02x not found",
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          v28,
          "wma_get_peer_pmf_status",
          *(unsigned __int8 *)(v18 + 10),
          *(unsigned __int8 *)(v18 + 11),
          *(unsigned __int8 *)(v18 + 12),
          *(unsigned __int8 *)(v18 + 15));
      }
    }
    if ( (*(_DWORD *)(v17 + 164) | 2) == 7 && (*(_BYTE *)(v18 + 1) & 0x40) != 0 )
    {
LABEL_17:
      v131[0] = 0;
      v48 = *(_BYTE *)(v18 + 4);
      v130[0] = 0;
      if ( (*(_BYTE *)(v18 + 1) & 0x40) == 0 )
      {
        if ( (v48 & 1) == 0 )
        {
          v49 = jiffies;
          if ( wma_process_rmf_frame___last_ticks_162 - jiffies + 125 < 0 )
          {
            qdf_trace_msg(
              0x36u,
              2u,
              "%s: Rx unprotected unicast mgmt frame",
              a6,
              a7,
              a8,
              a9,
              a10,
              a11,
              a12,
              a13,
              "wma_process_rmf_frame");
            wma_process_rmf_frame___last_ticks_162 = v49;
          }
          *(_BYTE *)(a4 + 46) = 15;
          goto LABEL_22;
        }
        if ( (*(_BYTE *)(a5 + 68) & 4) != 0 )
          v53 = *(unsigned __int16 *)(a5 + 66);
        else
          v53 = 0;
        v56 = *(_QWORD *)(a5 + 224);
        v57 = *(_DWORD *)(a5 + 112);
        param = wlan_crypto_get_param(*(_QWORD *)v17, 3u);
        v59 = (unsigned int)param;
        if ( param <= 0 )
          goto LABEL_41;
        if ( (param & 0x40) != 0 )
        {
          v91 = 6;
          mmie_size = cds_get_mmie_size();
        }
        else
        {
          if ( (param & 0x800) != 0 )
          {
            v91 = 11;
          }
          else
          {
            if ( (param & 0x1000) == 0 )
            {
LABEL_41:
              v60 = "%s: Invalid key cipher %d";
              v61 = "wma_process_bip";
LABEL_59:
              qdf_trace_msg(0x36u, 2u, v60, a6, a7, a8, a9, a10, a11, a12, a13, v61, v59);
              goto LABEL_60;
            }
            v91 = 12;
          }
          mmie_size = cds_get_gmac_mmie_size();
        }
        v93 = v56 + (unsigned int)(v57 + v53);
        if ( v93 - v18 < (unsigned __int64)mmie_size + 24 )
        {
          v54 = "%s: Invalid frame length";
          v55 = "wma_process_bip";
          goto LABEL_35;
        }
        if ( (unsigned int)(v91 - 11) >= 2 )
        {
          v94 = mmie_size;
          if ( (wmi_service_enabled(*a1, 0x6Au, a6, a7, a8, a9, a10, a11, a12, a13) & 1) == 0
            && ((unsigned __int8)wlan_crypto_is_mmie_valid(
                                   *(_QWORD *)v17,
                                   (_BYTE *)v18,
                                   v93,
                                   v112,
                                   v113,
                                   v114,
                                   v115,
                                   v116,
                                   v117,
                                   v118,
                                   v119)
              & 1) == 0 )
          {
            v111 = "%s: BC/MC MIC error or MMIE not present, dropping the frame";
            goto LABEL_91;
          }
        }
        else
        {
          v94 = mmie_size;
          if ( (wmi_service_enabled(*a1, 0x96u, a6, a7, a8, a9, a10, a11, a12, a13) & 1) == 0
            && ((unsigned __int8)wlan_crypto_is_mmie_valid(
                                   *(_QWORD *)v17,
                                   (_BYTE *)v18,
                                   v93,
                                   v95,
                                   v96,
                                   v97,
                                   v98,
                                   v99,
                                   v100,
                                   v101,
                                   v102)
              & 1) == 0 )
          {
            v111 = "%s: BC/MC GMAC MIC error or MMIE not present, dropping the frame";
LABEL_91:
            qdf_trace_msg(0x36u, 8u, v111, v103, v104, v105, v106, v107, v108, v109, v110, "wma_process_bip");
            goto LABEL_60;
          }
        }
        skb_trim(a5, *(_DWORD *)(a5 + 112) - (unsigned int)v94);
LABEL_22:
        result = 0;
        *a3 = *(_QWORD *)(a5 + 224);
        goto LABEL_61;
      }
      if ( (v48 & 1) != 0 )
      {
        v54 = "%s: Encrypted BC/MC frame dropping the frame";
      }
      else
      {
        if ( (*(_DWORD *)(v17 + 164) | 2) == 7 )
        {
          key = (_BYTE *)wlan_crypto_get_key(*(_QWORD *)v17, v18 + 10, 0);
          v51 = 8;
          v130[0] = 8;
          if ( key && *key == 32 )
            v51 = 16;
          v131[0] = v51;
          goto LABEL_29;
        }
        if ( !(unsigned int)mlme_get_peer_mic_len(
                              a1[3],
                              *(_BYTE *)(a1[4] + 40),
                              (unsigned __int8 *)(v18 + 10),
                              v131,
                              v130,
                              a6,
                              a7,
                              a8,
                              a9,
                              a10,
                              a11,
                              a12,
                              a13) )
        {
LABEL_29:
          if ( (*(_BYTE *)(a5 + 68) & 4) != 0 )
            v52 = *(unsigned __int16 *)(a5 + 66);
          else
            v52 = 0;
          v62 = *(_DWORD *)(a5 + 112);
          if ( v130[0] + (unsigned __int64)v131[0] + 24 > (unsigned int)(v62 + v52) )
          {
            if ( (*(_BYTE *)(a5 + 68) & 4) != 0 )
              v63 = *(unsigned __int16 *)(a5 + 66);
            else
              v63 = 0;
            v60 = "%s: Buffer length less than expected %d";
            v61 = "wma_process_rmf_frame";
            v59 = (unsigned int)(v63 + v62);
            goto LABEL_59;
          }
          v64 = *(_QWORD *)(a5 + 224);
          v65 = *(unsigned int *)(v64 + 28);
          v66 = *(unsigned __int16 *)(v64 + 24);
          peer_by_mac = wlan_objmgr_get_peer_by_mac(a1[3], (_BYTE *)(v18 + 10), 8u);
          if ( peer_by_mac )
          {
            v68 = (__int64)peer_by_mac;
            comp_private_obj = wlan_objmgr_peer_get_comp_private_obj((__int64)peer_by_mac, 0);
            if ( comp_private_obj )
            {
              v78 = v66 | (v65 << 16);
              if ( *(_BYTE *)comp_private_obj )
              {
                v79 = (unsigned __int64 *)(comp_private_obj + 8);
                if ( v78 <= *(_QWORD *)(comp_private_obj + 8) )
                {
                  v80 = jiffies;
                  if ( wma_is_ccmp_pn_replay_attack___last_ticks - jiffies + 125 < 0 )
                  {
                    v81 = comp_private_obj;
                    qdf_trace_msg(
                      0x36u,
                      2u,
                      "%s: PN Replay attack detected",
                      v70,
                      v71,
                      v72,
                      v73,
                      v74,
                      v75,
                      v76,
                      v77,
                      "wma_is_ccmp_pn_replay_attack");
                    comp_private_obj = v81;
                    wma_is_ccmp_pn_replay_attack___last_ticks = v80;
                  }
                  ++*(_DWORD *)(comp_private_obj + 16);
                  wlan_objmgr_peer_release_ref(v68, 8u, v70, v71, v72, v73, v74, v75, v76, v77);
                  v90 = jiffies;
                  if ( wma_process_rmf_frame___last_ticks - jiffies + 125 < 0 )
                  {
                    qdf_trace_msg(
                      0x36u,
                      2u,
                      "%s: Dropping the frame",
                      v82,
                      v83,
                      v84,
                      v85,
                      v86,
                      v87,
                      v88,
                      v89,
                      "wma_process_rmf_frame");
                    wma_process_rmf_frame___last_ticks = v90;
                  }
                  goto LABEL_60;
                }
              }
              else
              {
                *(_BYTE *)comp_private_obj = 1;
                v79 = (unsigned __int64 *)(comp_private_obj + 8);
              }
              *v79 = v78;
            }
            wlan_objmgr_peer_release_ref(v68, 8u, v70, v71, v72, v73, v74, v75, v76, v77);
          }
          qdf_mem_move((void *)(v64 + v130[0]), (const void *)v18, 0x18u);
          v120 = *(_QWORD *)(a5 + 40);
          v121 = v130[0];
          if ( v120 )
            *(_QWORD *)(a5 + 40) = v120 + v130[0];
          skb_pull(a5, v121);
          skb_trim(a5, *(_DWORD *)(a5 + 112) - (unsigned int)v131[0]);
          v122 = *(unsigned __int8 **)(a5 + 224);
          *(_QWORD *)(a4 + 16) = v122;
          if ( (*(_BYTE *)(a5 + 68) & 4) != 0 )
            v123 = *(unsigned __int16 *)(a5 + 66);
          else
            v123 = 0;
          v124 = *(_DWORD *)(a5 + 112);
          v125 = *(unsigned int *)(a4 + 36);
          *(_QWORD *)(a4 + 64) = a5;
          *(_DWORD *)(a4 + 32) = v124 + v123;
          if ( v124 + v123 < (unsigned int)v125 )
          {
            qdf_trace_msg(
              0x36u,
              2u,
              "%s: mpdu len %d less than hdr %d, dropping frame",
              a6,
              a7,
              a8,
              a9,
              a10,
              a11,
              a12,
              a13,
              "wma_process_rmf_frame");
            goto LABEL_60;
          }
          v59 = (unsigned int)(v124 + v123 - v125);
          *(_DWORD *)(a4 + 40) = v59;
          if ( (unsigned int)v59 > 0x900 )
          {
            v60 = "%s: Data Len %d greater than max, dropping frame";
            v61 = "wma_process_rmf_frame";
            goto LABEL_59;
          }
          *(_QWORD *)(a4 + 24) = &v122[v125];
          if ( v122 == (unsigned __int8 *)-16LL )
          {
            v128 = 0;
            v126 = 0;
            v127 = 0;
            v129 = 0;
          }
          else
          {
            v126 = v122[16];
            v127 = v122[17];
            v128 = v122[18];
            v129 = v122[21];
          }
          qdf_trace_msg(
            0x36u,
            8u,
            "%s: BSSID: %02x:%02x:%02x:**:**:%02x tsf_delta: %u",
            a6,
            a7,
            a8,
            a9,
            a10,
            a11,
            a12,
            a13,
            "wma_process_rmf_frame",
            v126,
            v127,
            v128,
            v129,
            *(_DWORD *)(a4 + 48));
          goto LABEL_22;
        }
        v54 = "%s: Failed to get mic hdr and length";
      }
      v55 = "wma_process_rmf_frame";
LABEL_35:
      qdf_trace_msg(0x36u, 2u, v54, a6, a7, a8, a9, a10, a11, a12, a13, v55);
LABEL_60:
      cds_pkt_return_packet(a4);
      result = 4294967274LL;
      goto LABEL_61;
    }
  }
  result = 0;
LABEL_61:
  _ReadStatusReg(SP_EL0);
  return result;
}
