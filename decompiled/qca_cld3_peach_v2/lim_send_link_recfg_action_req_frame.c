__int64 __fastcall lim_send_link_recfg_action_req_frame(unsigned int a1, unsigned __int8 *a2, __int64 a3, __int64 a4)
{
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  _QWORD *context; // x0
  __int64 v17; // x21
  __int64 session_by_vdev_id; // x0
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  __int64 v27; // x20
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  __int64 result; // x0
  unsigned int v37; // w0
  int v38; // w24
  unsigned int v39; // w23
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  int v56; // w9
  int v57; // w10
  __int64 v58; // x0
  _WORD *v59; // x0
  int v60; // w9
  int v61; // w10
  int v62; // w11
  int v63; // w12
  unsigned int packed_link_recfg_reqSize; // w0
  double v65; // d0
  double v66; // d1
  double v67; // d2
  double v68; // d3
  double v69; // d4
  double v70; // d5
  double v71; // d6
  double v72; // d7
  size_t v73; // x24
  double v74; // d0
  double v75; // d1
  double v76; // d2
  double v77; // d3
  double v78; // d4
  double v79; // d5
  double v80; // d6
  double v81; // d7
  char *v82; // x25
  void *v83; // x0
  double v84; // d0
  double v85; // d1
  double v86; // d2
  double v87; // d3
  double v88; // d4
  double v89; // d5
  double v90; // d6
  double v91; // d7
  unsigned int v92; // w9
  __int16 v93; // w9
  __int64 v94; // x5
  _BYTE *v95; // x25
  unsigned int v96; // w0
  double v97; // d0
  double v98; // d1
  double v99; // d2
  double v100; // d3
  double v101; // d4
  double v102; // d5
  double v103; // d6
  double v104; // d7
  double v105; // d0
  double v106; // d1
  double v107; // d2
  double v108; // d3
  double v109; // d4
  double v110; // d5
  double v111; // d6
  double v112; // d7
  char v113; // w23
  const char *v114; // x2
  __int64 v115; // x4
  double v116; // d0
  double v117; // d1
  double v118; // d2
  double v119; // d3
  double v120; // d4
  double v121; // d5
  double v122; // d6
  double v123; // d7
  double v124; // d0
  double v125; // d1
  double v126; // d2
  double v127; // d3
  double v128; // d4
  double v129; // d5
  double v130; // d6
  double v131; // d7
  const void *v132; // x22
  __int64 v133; // x0
  _QWORD *v134; // x0
  unsigned int v135; // w19
  __int64 v136; // x8
  __int64 v137; // x8
  __int64 v138; // x21
  void *v139; // x0
  double v140; // d0
  double v141; // d1
  double v142; // d2
  double v143; // d3
  double v144; // d4
  double v145; // d5
  double v146; // d6
  double v147; // d7
  int v148; // [xsp+8h] [xbp-168h]
  int v149; // [xsp+10h] [xbp-160h]
  int v150; // [xsp+18h] [xbp-158h]
  int v151; // [xsp+20h] [xbp-150h]
  __int64 v152; // [xsp+40h] [xbp-130h] BYREF
  int v153[2]; // [xsp+48h] [xbp-128h] BYREF
  unsigned int v154; // [xsp+54h] [xbp-11Ch] BYREF
  int v155; // [xsp+58h] [xbp-118h] BYREF
  __int16 v156; // [xsp+5Ch] [xbp-114h] BYREF
  _WORD s[132]; // [xsp+60h] [xbp-110h] BYREF
  __int64 v158; // [xsp+168h] [xbp-8h]

  v158 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(s, 0, sizeof(s));
  v154 = 0;
  v155 = 0;
  v152 = 0;
  *(_QWORD *)v153 = 0;
  context = _cds_get_context(53, (__int64)"lim_send_link_recfg_action_req_frame", v8, v9, v10, v11, v12, v13, v14, v15);
  if ( context )
  {
    if ( a4 )
    {
      v17 = (__int64)context;
      session_by_vdev_id = pe_find_session_by_vdev_id(context, a1);
      if ( session_by_vdev_id )
      {
        v27 = session_by_vdev_id;
        qdf_mem_set(s, 0x108u, 0);
        *(_WORD *)(v27 + 10872) = 0;
        qdf_mem_set((void *)(v27 + 10874), 0x92Cu, 0);
        if ( (unsigned int)populate_rv_mlo_ie(*(_QWORD *)(v27 + 16), v27, a4) )
        {
          qdf_trace_msg(
            0x35u,
            2u,
            "%s: Failed to populate Recfg MLO IE",
            v28,
            v29,
            v30,
            v31,
            v32,
            v33,
            v34,
            v35,
            "lim_send_link_recfg_action_req_frame");
LABEL_47:
          result = 16;
          goto LABEL_48;
        }
        v37 = ((__int64 (__fastcall *)(__int64))lim_caculate_mlo_ie_length)(v27 + 10874);
        v38 = (unsigned __int16)v37;
        v39 = v37;
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: Reconfig ML IE len %d",
          v40,
          v41,
          v42,
          v43,
          v44,
          v45,
          v46,
          v47,
          "lim_send_link_recfg_action_req_frame",
          (unsigned __int16)v37);
        *(_WORD *)(v27 + 10872) = v39;
        v56 = *(_DWORD *)(a3 + 4);
        v57 = *(unsigned __int8 *)(a4 + 120);
        s[0] = *(_WORD *)a3;
        LOBYTE(s[1]) = v56;
        if ( v57 )
        {
          v58 = *(_QWORD *)(v27 + 16);
          v156 = 0;
          if ( (wlan_crypto_get_param(v58, 5u) & 0x4000) != 0 )
          {
            v59 = (_WORD *)dph_lookup_hash_entry(v48, v49, v50, v51, v52, v53, v54, v55, v17, a2, &v156, v27 + 360);
            if ( v59 )
            {
              if ( (*v59 & 0x800) != 0 )
              {
                qdf_trace_msg(
                  0x35u,
                  8u,
                  "%s: Add oci ie",
                  v48,
                  v49,
                  v50,
                  v51,
                  v52,
                  v53,
                  v54,
                  v55,
                  "lim_send_link_recfg_action_req_frame");
                populate_oci_ie(v17, *(unsigned int *)(a4 + 4), &v155);
                if ( (_BYTE)v155 )
                  qdf_mem_copy(&s[130], &v155, 4u);
              }
            }
          }
        }
        if ( a2 )
        {
          v60 = *a2;
          v61 = a2[1];
          v62 = a2[2];
          v63 = a2[5];
        }
        else
        {
          v62 = 0;
          v60 = 0;
          v61 = 0;
          v63 = 0;
        }
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: Sending a Link Reconfiguration Request frame token %d from %02x:%02x:%02x:**:**:%02x to %02x:%02x:%02x:**:**:%02x",
          v48,
          v49,
          v50,
          v51,
          v52,
          v53,
          v54,
          v55,
          "lim_send_link_recfg_action_req_frame",
          LOBYTE(s[1]),
          *(unsigned __int8 *)(v27 + 30),
          *(unsigned __int8 *)(v27 + 31),
          *(unsigned __int8 *)(v27 + 32),
          *(unsigned __int8 *)(v27 + 35),
          v60,
          v61,
          v62,
          v63);
        packed_link_recfg_reqSize = dot11f_get_packed_link_recfg_reqSize(v17, s, &v154);
        if ( (packed_link_recfg_reqSize & 0x10000000) != 0 )
        {
          qdf_trace_msg(
            0x35u,
            2u,
            "%s: Failed to calculate packed size for a Link Reconfig Request frame (0x%08x).",
            v65,
            v66,
            v67,
            v68,
            v69,
            v70,
            v71,
            v72,
            "lim_send_link_recfg_action_req_frame",
            packed_link_recfg_reqSize);
          v154 = 264;
        }
        else if ( packed_link_recfg_reqSize )
        {
          qdf_trace_msg(
            0x35u,
            3u,
            "%s: There were warnings while calculating packed size for a Link Reconfig Request frame (0x%08x).",
            v65,
            v66,
            v67,
            v68,
            v69,
            v70,
            v71,
            v72,
            "lim_send_link_recfg_action_req_frame");
        }
        v73 = v38 + v154 + 24;
        if ( (unsigned int)cds_packet_alloc(v73, v153, &v152) || !v152 )
        {
          v114 = "%s: Failed to allocate %d bytes for a Link Reconfig req action frm";
          v115 = (unsigned int)v73;
        }
        else
        {
          qdf_mem_set(*(void **)v153, (unsigned int)v73, 0);
          v82 = *(char **)v153;
          v83 = (void *)(*(_QWORD *)v153 + 4LL);
          **(_BYTE **)v153 = -48;
          qdf_mem_copy(v83, a2, 6u);
          v82[10] = *(_BYTE *)(v27 + 30);
          v82[11] = *(_BYTE *)(v27 + 31);
          v82[12] = *(_BYTE *)(v27 + 32);
          v82[13] = *(_BYTE *)(v27 + 33);
          v82[14] = *(_BYTE *)(v27 + 34);
          v82[15] = *(_BYTE *)(v27 + 35);
          qdf_mem_copy(v82 + 16, a2, 6u);
          v92 = *(unsigned __int16 *)(v17 + 21604);
          if ( v92 <= 0xFFE )
            v93 = v92 + 1;
          else
            v93 = 2048;
          *(_WORD *)(v17 + 21604) = v93;
          *((_WORD *)v82 + 11) = (16 * (v93 & 0xF)) | *((_WORD *)v82 + 11) & 0xFF0F;
          v94 = (unsigned __int8)(*(_WORD *)(v17 + 21604) >> 4);
          *((_WORD *)v82 + 11) = (16 * *(_WORD *)(v17 + 21604)) & 0xFF00 | (16 * (v93 & 0xF));
          qdf_trace_msg(
            0x35u,
            8u,
            "%s: seqNumLo=%d, seqNumHi=%d, mgmtSeqNum=%d, fragNum=%d",
            v84,
            v85,
            v86,
            v87,
            v88,
            v89,
            v90,
            v91,
            "lim_populate_mac_header",
            v93 & 0xF,
            v94,
            *(unsigned __int16 *)(v17 + 21604),
            0);
          v95 = *(_BYTE **)v153;
          *(_BYTE *)(*(_QWORD *)v153 + 16LL) = *(_BYTE *)(v27 + 24);
          v95[17] = *(_BYTE *)(v27 + 25);
          v95[18] = *(_BYTE *)(v27 + 26);
          v95[19] = *(_BYTE *)(v27 + 27);
          v95[20] = *(_BYTE *)(v27 + 28);
          v95[21] = *(_BYTE *)(v27 + 29);
          lim_set_protected_bit(v17, v27, a2, v95);
          v96 = dot11f_pack_link_recfg_req(v17, s, *(_QWORD *)v153 + 24LL, v154, &v154);
          if ( (v96 & 0x10000000) != 0 )
          {
            qdf_trace_msg(
              0x35u,
              2u,
              "%s: Failed to pack a Link Reconfig action request frm (0x%08x)",
              v97,
              v98,
              v99,
              v100,
              v101,
              v102,
              v103,
              v104,
              "lim_send_link_recfg_action_req_frame",
              v96);
            cds_packet_free(v152);
            goto LABEL_47;
          }
          if ( v96 )
            qdf_trace_msg(
              0x35u,
              3u,
              "%s: There were warnings while packing Link Reconfig req frm (0x%08x)",
              v97,
              v98,
              v99,
              v100,
              v101,
              v102,
              v103,
              v104,
              "lim_send_link_recfg_action_req_frame");
          if ( (_WORD)v39 )
          {
            if ( (unsigned int)lim_fill_complete_mlo_ie(v27, v39, *(_QWORD *)v153 + v154 + 24LL) )
            {
              qdf_trace_msg(
                0x35u,
                8u,
                "%s: assemble rv ml ie error",
                v105,
                v106,
                v107,
                v108,
                v109,
                v110,
                v111,
                v112,
                "lim_send_link_recfg_action_req_frame");
              LOWORD(v39) = 0;
            }
            v154 += (unsigned __int16)v39;
          }
          if ( wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(v27 + 284)) && (*(_DWORD *)(v27 + 7036) & 0xFFFFFFFE) != 2 )
            v113 = 0;
          else
            v113 = 64;
          qdf_trace(53, 2u, *(_WORD *)(v27 + 8), (unsigned __int8)*(_WORD *)v95 >> 4);
          qdf_trace_msg(
            0x35u,
            8u,
            "%s: Link Reconfig tx dump:",
            v116,
            v117,
            v118,
            v119,
            v120,
            v121,
            v122,
            v123,
            "lim_send_link_recfg_action_req_frame");
          ((void (__fastcall *)(__int64, __int64, _QWORD, _QWORD))qdf_trace_hex_dump)(
            53,
            8,
            *(_QWORD *)v153,
            (unsigned int)v73);
          if ( (_DWORD)v73 )
          {
            v132 = *(const void **)v153;
            if ( *(_QWORD *)v153 )
            {
              v133 = pe_find_session_by_vdev_id(v17, a1);
              if ( v133 )
              {
                if ( !*(_DWORD *)(v133 + 7036) )
                {
                  v136 = *(_QWORD *)(v133 + 16);
                  if ( v136 )
                  {
                    v137 = *(_QWORD *)(v136 + 1360);
                    if ( v137 )
                    {
                      v138 = *(_QWORD *)(v137 + 3888);
                      if ( v138 )
                      {
                        *(_DWORD *)(v138 + 3216) = v73;
                        v139 = (void *)_qdf_mem_malloc(v73, "lim_store_link_recfg_req_frame", 8413);
                        *(_QWORD *)(v138 + 3224) = v139;
                        if ( v139 )
                        {
                          qdf_mem_copy(v139, v132, *(unsigned int *)(v138 + 3216));
                          qdf_trace_msg(
                            0x35u,
                            8u,
                            "%s: Link Recfg Frame len is %d",
                            v140,
                            v141,
                            v142,
                            v143,
                            v144,
                            v145,
                            v146,
                            v147,
                            "lim_store_link_recfg_req_frame",
                            *(unsigned int *)(v138 + 3216));
                        }
                      }
                    }
                  }
                }
              }
            }
          }
          v134 = _cds_get_context(
                   54,
                   (__int64)"lim_send_link_recfg_action_req_frame",
                   v124,
                   v125,
                   v126,
                   v127,
                   v128,
                   v129,
                   v130,
                   v131);
          LOWORD(v151) = *(_DWORD *)(v27 + 284);
          LOBYTE(v149) = a1;
          LOBYTE(v148) = v113;
          LOBYTE(v150) = 0;
          v135 = wma_tx_packet(
                   v134,
                   v152,
                   (unsigned int)v73,
                   3,
                   1,
                   7,
                   lim_tx_complete,
                   *(_QWORD *)v153,
                   lim_mgmt_link_recfg_req_tx_complete,
                   v148,
                   v149,
                   v150,
                   v151,
                   12,
                   0,
                   0);
          qdf_trace(53, 5u, *(_WORD *)(v27 + 8), v135);
          if ( !v135 )
          {
            result = 0;
            goto LABEL_48;
          }
          v114 = "%s: wma_tx_frame FAILED! Status [%d]";
          v115 = v135;
        }
        qdf_trace_msg(
          0x35u,
          2u,
          v114,
          v74,
          v75,
          v76,
          v77,
          v78,
          v79,
          v80,
          v81,
          "lim_send_link_recfg_action_req_frame",
          v115);
        goto LABEL_47;
      }
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: session not found for given vdev_id %d",
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        "lim_send_link_recfg_action_req_frame",
        (unsigned __int8)a1);
      result = 4;
    }
    else
    {
      result = 29;
    }
  }
  else
  {
    result = 4;
  }
LABEL_48:
  _ReadStatusReg(SP_EL0);
  return result;
}
