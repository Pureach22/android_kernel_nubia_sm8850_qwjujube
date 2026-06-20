__int64 __fastcall lim_send_t2lm_action_req_frame(__int64 a1, unsigned __int8 *a2, __int16 *a3, __int64 a4)
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
  unsigned int v17; // w20
  _QWORD *v18; // x22
  __int64 session_by_vdev_id; // x0
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  __int64 v28; // x19
  __int64 v29; // x0
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  __int64 v38; // x26
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  double v47; // d0
  double v48; // d1
  double v49; // d2
  double v50; // d3
  double v51; // d4
  double v52; // d5
  double v53; // d6
  double v54; // d7
  __int16 v55; // w9
  int v56; // w8
  __int64 v57; // x5
  int v58; // w10
  int v59; // w11
  int v60; // w12
  int v61; // w13
  __int64 result; // x0
  unsigned int packed_t2lm_neg_reqSize; // w0
  double v64; // d0
  double v65; // d1
  double v66; // d2
  double v67; // d3
  double v68; // d4
  double v69; // d5
  double v70; // d6
  double v71; // d7
  unsigned int v72; // w24
  double v73; // d0
  double v74; // d1
  double v75; // d2
  double v76; // d3
  double v77; // d4
  double v78; // d5
  double v79; // d6
  double v80; // d7
  char *v81; // x25
  void *v82; // x0
  double v83; // d0
  double v84; // d1
  double v85; // d2
  double v86; // d3
  double v87; // d4
  double v88; // d5
  double v89; // d6
  double v90; // d7
  unsigned int v91; // w9
  _QWORD *v92; // x23
  __int16 v93; // w9
  __int64 v94; // x5
  _BYTE *v95; // x22
  unsigned int v96; // w0
  double v97; // d0
  double v98; // d1
  double v99; // d2
  double v100; // d3
  double v101; // d4
  double v102; // d5
  double v103; // d6
  double v104; // d7
  char v105; // w21
  const char *v106; // x2
  __int64 v107; // x4
  double v108; // d0
  double v109; // d1
  double v110; // d2
  double v111; // d3
  double v112; // d4
  double v113; // d5
  double v114; // d6
  double v115; // d7
  _QWORD *v116; // x0
  int v117; // w0
  __int16 v118; // w2
  unsigned int v119; // w19
  int v120; // [xsp+8h] [xbp-268h]
  int v121; // [xsp+10h] [xbp-260h]
  int v122; // [xsp+18h] [xbp-258h]
  int v123; // [xsp+20h] [xbp-250h]
  __int64 v124; // [xsp+48h] [xbp-228h] BYREF
  unsigned int v125; // [xsp+54h] [xbp-21Ch] BYREF
  int v126[2]; // [xsp+58h] [xbp-218h] BYREF
  _WORD s[260]; // [xsp+60h] [xbp-210h] BYREF
  __int64 v128; // [xsp+268h] [xbp-8h]

  v128 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(s, 0, sizeof(s));
  *(_QWORD *)v126 = 0;
  v125 = 0;
  v124 = 0;
  context = _cds_get_context(53, (__int64)"lim_send_t2lm_action_req_frame", v8, v9, v10, v11, v12, v13, v14, v15);
  if ( context )
  {
    if ( a1 )
    {
      v17 = *(unsigned __int8 *)(a1 + 168);
      v18 = context;
      session_by_vdev_id = pe_find_session_by_vdev_id(context, *(unsigned __int8 *)(a1 + 168));
      if ( session_by_vdev_id )
      {
        v28 = session_by_vdev_id;
        qdf_mem_set(s, 0x208u, 0);
        v29 = _qdf_mem_malloc(0x1Au, "lim_send_t2lm_action_req_frame", 8182);
        if ( v29 )
        {
          v38 = v29;
          if ( wlan_mlo_add_t2lm_ie(v29, a4, a1) )
          {
            HIBYTE(s[3]) = *(_BYTE *)(v38 + 1) - 1;
            qdf_mem_copy(&s[4], (const void *)(v38 + 3), HIBYTE(s[3]));
            _qdf_mem_free(v38);
            v55 = *a3;
            v56 = *((_DWORD *)a3 + 1);
            s[2] = 1;
            v57 = *(unsigned __int8 *)(v28 + 30);
            s[0] = v55;
            LOBYTE(s[1]) = v56;
            LOBYTE(s[3]) = 1;
            if ( a2 )
            {
              v58 = *a2;
              v59 = a2[1];
              v60 = a2[2];
              v61 = a2[5];
            }
            else
            {
              v60 = 0;
              v58 = 0;
              v59 = 0;
              v61 = 0;
            }
            qdf_trace_msg(
              0x35u,
              8u,
              "%s: Sending a T2LM negotiation Request token %d from %02x:%02x:%02x:**:**:%02x to %02x:%02x:%02x:**:**:%02x",
              v47,
              v48,
              v49,
              v50,
              v51,
              v52,
              v53,
              v54,
              "lim_send_t2lm_action_req_frame",
              (unsigned __int8)v56,
              v57,
              *(unsigned __int8 *)(v28 + 31),
              *(unsigned __int8 *)(v28 + 32),
              *(unsigned __int8 *)(v28 + 35),
              v58,
              v59,
              v60,
              v61);
            packed_t2lm_neg_reqSize = dot11f_get_packed_t2lm_neg_reqSize(v18, s, &v125);
            if ( (packed_t2lm_neg_reqSize & 0x10000000) != 0 )
            {
              qdf_trace_msg(
                0x35u,
                2u,
                "%s: Failed to calculate packed size for a T2LM negotiation Request (0x%08x).",
                v64,
                v65,
                v66,
                v67,
                v68,
                v69,
                v70,
                v71,
                "lim_send_t2lm_action_req_frame",
                packed_t2lm_neg_reqSize);
              v125 = 520;
            }
            else if ( packed_t2lm_neg_reqSize )
            {
              qdf_trace_msg(
                0x35u,
                3u,
                "%s: There were warnings while calculating packed size for a T2LM negotiation Request (0x%08x).",
                v64,
                v65,
                v66,
                v67,
                v68,
                v69,
                v70,
                v71,
                "lim_send_t2lm_action_req_frame");
            }
            v72 = v125;
            if ( (unsigned int)cds_packet_alloc((unsigned __int16)v125 + 24, v126, &v124) || !v124 )
            {
              v106 = "%s: Failed to allocate %d bytes for a T2LM req action frm";
              v107 = v72 + 24;
LABEL_34:
              qdf_trace_msg(
                0x35u,
                2u,
                v106,
                v73,
                v74,
                v75,
                v76,
                v77,
                v78,
                v79,
                v80,
                "lim_send_t2lm_action_req_frame",
                v107);
              goto LABEL_35;
            }
            qdf_mem_set(*(void **)v126, v72 + 24, 0);
            v81 = *(char **)v126;
            v82 = (void *)(*(_QWORD *)v126 + 4LL);
            **(_BYTE **)v126 = -48;
            qdf_mem_copy(v82, a2, 6u);
            v81[10] = *(_BYTE *)(v28 + 30);
            v81[11] = *(_BYTE *)(v28 + 31);
            v81[12] = *(_BYTE *)(v28 + 32);
            v81[13] = *(_BYTE *)(v28 + 33);
            v81[14] = *(_BYTE *)(v28 + 34);
            v81[15] = *(_BYTE *)(v28 + 35);
            qdf_mem_copy(v81 + 16, a2, 6u);
            v91 = *((unsigned __int16 *)v18 + 10802);
            v92 = v18;
            if ( v91 <= 0xFFE )
              v93 = v91 + 1;
            else
              v93 = 2048;
            *((_WORD *)v18 + 10802) = v93;
            *((_WORD *)v81 + 11) = (16 * (v93 & 0xF)) | *((_WORD *)v81 + 11) & 0xFF0F;
            v94 = (unsigned __int8)(*((_WORD *)v18 + 10802) >> 4);
            *((_WORD *)v81 + 11) = (16 * *((_WORD *)v18 + 10802)) & 0xFF00 | (16 * (v93 & 0xF));
            qdf_trace_msg(
              0x35u,
              8u,
              "%s: seqNumLo=%d, seqNumHi=%d, mgmtSeqNum=%d, fragNum=%d",
              v83,
              v84,
              v85,
              v86,
              v87,
              v88,
              v89,
              v90,
              "lim_populate_mac_header",
              v93 & 0xF,
              v94,
              *((unsigned __int16 *)v18 + 10802),
              0);
            v95 = *(_BYTE **)v126;
            *(_BYTE *)(*(_QWORD *)v126 + 16LL) = *(_BYTE *)(v28 + 24);
            v95[17] = *(_BYTE *)(v28 + 25);
            v95[18] = *(_BYTE *)(v28 + 26);
            v95[19] = *(_BYTE *)(v28 + 27);
            v95[20] = *(_BYTE *)(v28 + 28);
            v95[21] = *(_BYTE *)(v28 + 29);
            lim_set_protected_bit(v92, v28, a2, v95);
            v96 = dot11f_pack_t2lm_neg_req(v92, s, *(_QWORD *)v126 + 24LL, v125, &v125);
            if ( (v96 & 0x10000000) == 0 )
            {
              if ( v96 )
                qdf_trace_msg(
                  0x35u,
                  3u,
                  "%s: There were warnings while packing T2LM req (0x%08x)",
                  v97,
                  v98,
                  v99,
                  v100,
                  v101,
                  v102,
                  v103,
                  v104,
                  "lim_send_t2lm_action_req_frame");
              if ( wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(v28 + 284)) && (*(_DWORD *)(v28 + 7036) & 0xFFFFFFFE) != 2 )
                v105 = 0;
              else
                v105 = 64;
              qdf_trace(53, 2u, *(_WORD *)(v28 + 8), (unsigned __int8)*(_WORD *)v95 >> 4);
              v116 = _cds_get_context(
                       54,
                       (__int64)"lim_send_t2lm_action_req_frame",
                       v108,
                       v109,
                       v110,
                       v111,
                       v112,
                       v113,
                       v114,
                       v115);
              LOWORD(v123) = *(_DWORD *)(v28 + 284);
              LOBYTE(v121) = v17;
              LOBYTE(v120) = v105;
              LOBYTE(v122) = 0;
              v117 = wma_tx_packet(
                       v116,
                       v124,
                       v72 + 24,
                       3,
                       1,
                       7,
                       lim_tx_complete,
                       *(_QWORD *)v126,
                       &lim_mgmt_t2lm_req_tx_complete,
                       v120,
                       v121,
                       v122,
                       v123,
                       12,
                       0,
                       0);
              v118 = *(_WORD *)(v28 + 8);
              v119 = v117;
              qdf_trace(53, 5u, v118, v117);
              if ( !v119 )
              {
                result = 0;
                goto LABEL_36;
              }
              v106 = "%s: wma_tx_frame FAILED! Status [%d]";
              v107 = v119;
              goto LABEL_34;
            }
            qdf_trace_msg(
              0x35u,
              2u,
              "%s: Failed to pack a T2LM negotiation request (0x%08x)",
              v97,
              v98,
              v99,
              v100,
              v101,
              v102,
              v103,
              v104,
              "lim_send_t2lm_action_req_frame",
              v96);
            cds_packet_free(v124);
          }
          else
          {
            qdf_trace_msg(
              0x35u,
              8u,
              "%s: Failed to populate T2LM IE",
              v39,
              v40,
              v41,
              v42,
              v43,
              v44,
              v45,
              v46,
              "lim_send_t2lm_action_req_frame");
            _qdf_mem_free(v38);
          }
LABEL_35:
          result = 16;
          goto LABEL_36;
        }
        qdf_trace_msg(
          0x35u,
          2u,
          "%s: Malloc failed",
          v30,
          v31,
          v32,
          v33,
          v34,
          v35,
          v36,
          v37,
          "lim_send_t2lm_action_req_frame");
        result = 29;
      }
      else
      {
        qdf_trace_msg(
          0x35u,
          2u,
          "%s: session not found for given vdev_id %d",
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          "lim_send_t2lm_action_req_frame",
          v17);
        result = 4;
      }
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
LABEL_36:
  _ReadStatusReg(SP_EL0);
  return result;
}
