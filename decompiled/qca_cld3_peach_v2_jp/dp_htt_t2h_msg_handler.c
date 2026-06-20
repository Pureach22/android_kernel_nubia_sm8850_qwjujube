__int64 __fastcall dp_htt_t2h_msg_handler(
        __int64 result,
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
  int v10; // w8
  __int64 v11; // x19
  unsigned int *v12; // x20
  unsigned __int64 v13; // x8
  __int64 v14; // x21
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x8
  const char *v24; // x3
  unsigned int v25; // w20
  unsigned int v26; // w22
  unsigned int v27; // w21
  __int64 v28; // x23
  __int64 v29; // x0
  unsigned __int64 v30; // x21
  __int64 v31; // x24
  __int64 v32; // x25
  unsigned int v33; // w22
  unsigned int v34; // w23
  unsigned int v35; // w21
  unsigned int v36; // w22
  unsigned int v37; // w24
  unsigned int v38; // w27
  unsigned int v39; // w28
  __int64 v40; // x23
  unsigned int v41; // w25
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  unsigned int v50; // w24
  unsigned int v51; // w28
  unsigned int v52; // w21
  unsigned int v53; // w23
  __int64 v54; // x27
  unsigned int v55; // w22
  double v56; // d0
  double v57; // d1
  double v58; // d2
  double v59; // d3
  double v60; // d4
  double v61; // d5
  double v62; // d6
  double v63; // d7
  unsigned int v64; // w8
  unsigned int v65; // w20
  unsigned int v66; // w20
  unsigned int v67; // w21
  unsigned int v68; // w22
  unsigned int v69; // w0
  double v70; // d0
  double v71; // d1
  double v72; // d2
  double v73; // d3
  double v74; // d4
  double v75; // d5
  double v76; // d6
  double v77; // d7
  unsigned int v78; // w21
  char v79; // w24
  unsigned int v80; // w23
  __int64 v81; // x25
  unsigned int v82; // w22
  unsigned int v83; // w21
  unsigned int v84; // w22
  unsigned int v85; // w20
  unsigned int v86; // w0
  double v87; // d0
  double v88; // d1
  double v89; // d2
  double v90; // d3
  double v91; // d4
  double v92; // d5
  double v93; // d6
  double v94; // d7
  __int64 v95; // x3
  __int64 v96; // x4
  double v97; // d0
  double v98; // d1
  double v99; // d2
  double v100; // d3
  double v101; // d4
  double v102; // d5
  double v103; // d6
  double v104; // d7
  __int64 v105; // x8
  __int64 v106; // [xsp+8h] [xbp-18h]
  int v107; // [xsp+10h] [xbp-10h] BYREF
  __int16 v108; // [xsp+14h] [xbp-Ch]
  __int64 v109; // [xsp+18h] [xbp-8h]

  v109 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(_DWORD *)(a2 + 52);
  v11 = *(_QWORD *)(a2 + 16);
  if ( v10 )
  {
    if ( v10 != 9 )
      ++*(_DWORD *)(result + 92);
  }
  else
  {
    v12 = *(unsigned int **)(v11 + 224);
    v13 = *v12;
    switch ( (unsigned __int8)*v12 )
    {
      case 0u:
        v14 = result;
        if ( (htc_dec_return_htt_runtime_cnt(*(_QWORD *)(result + 48)) & 0x80000000) != 0 )
        {
          v23 = v14;
          ++*(_DWORD *)(v14 + 108);
        }
        else
        {
          htc_pm_runtime_put();
          v23 = v14;
        }
        v95 = (unsigned __int8)BYTE2(*v12);
        *(_BYTE *)(v23 + 88) = BYTE2(*v12);
        v96 = (unsigned __int8)BYTE1(*v12);
        *(_BYTE *)(v23 + 89) = BYTE1(*v12);
        result = qdf_trace_msg(
                   0x3Fu,
                   7u,
                   "target uses HTT version %d.%d; host uses %d.%d",
                   v15,
                   v16,
                   v17,
                   v18,
                   v19,
                   v20,
                   v21,
                   v22,
                   v95,
                   v96,
                   3,
                   143);
        v105 = v14;
        if ( *(_BYTE *)(v14 + 88) != 3 )
        {
          result = qdf_trace_msg(
                     0x3Fu,
                     3u,
                     "*** Incompatible host/target HTT versions!",
                     v97,
                     v98,
                     v99,
                     v100,
                     v101,
                     v102,
                     v103,
                     v104);
          v105 = v14;
        }
        if ( *(unsigned __int8 *)(v105 + 89) != 143 )
          result = qdf_trace_msg(
                     0x3Fu,
                     7u,
                     "*** Warning: host/target HTT versions are different, though compatible!",
                     v97,
                     v98,
                     v99,
                     v100,
                     v101,
                     v102,
                     v103,
                     v104);
        break;
      case 3u:
        v30 = v13 >> 16;
        v31 = *(_QWORD *)(result + 8);
        v32 = result;
        v33 = HIWORD(v12[2]);
        v34 = (unsigned int)v13 >> 8;
        qdf_trace_msg(
          0x3Fu,
          8u,
          "HTT_T2H_MSG_TYPE_PEER_MAP msg for peer id %d vdev id %d n",
          a3,
          a4,
          a5,
          a6,
          a7,
          a8,
          a9,
          a10,
          HIWORD(*v12),
          BYTE1(v13));
        LODWORD(v31) = *(_QWORD *)(*(_QWORD *)(v31 + 13088) + 8 * v30) != 0;
        dp_check_is_wds_valid(*(_QWORD *)(v32 + 8), (unsigned int)v30, v33, v34, v12 + 1, (unsigned int)v31);
        result = dp_rx_peer_map_handler(
                   *(_QWORD *)(v32 + 8),
                   (unsigned int)v30,
                   v33,
                   v34,
                   v12 + 1,
                   0,
                   (unsigned int)v31);
        break;
      case 4u:
        v29 = *(_QWORD *)(result + 8);
        v108 = 0;
        v107 = 0;
        result = dp_rx_peer_unmap_handler(v29, WORD1(v13), (unsigned int)v13 >> 8, &v107, 0, 0xFFFFFFFFLL);
        break;
      case 5u:
        result = dp_htt_rx_addba_handler(
                   *(_QWORD *)(result + 8),
                   (unsigned int)v13 >> 20,
                   WORD1(v13) & 0xF,
                   (unsigned int)BYTE1(v13) + 1);
        break;
      case 6u:
        v66 = (unsigned int)v13 >> 20;
        v67 = (unsigned __int16)v13 >> 10;
        v68 = WORD1(v13) & 0xF;
        v69 = dp_rx_delba_ind_handler(
                *(_QWORD *)(result + 8),
                (unsigned int)v13 >> 20,
                v68,
                (unsigned __int16)v13 >> 10);
        result = qdf_trace_msg(
                   0x3Fu,
                   4u,
                   "%s: DELBA PeerID %d BAW %d TID %d stat %d",
                   v70,
                   v71,
                   v72,
                   v73,
                   v74,
                   v75,
                   v76,
                   v77,
                   "dp_htt_t2h_msg_handler",
                   v66,
                   v67,
                   v68,
                   v69);
        break;
      case 0xBu:
        result = dp_rx_sec_ind_handler(
                   *(_QWORD *)(result + 8),
                   WORD1(v13),
                   ((unsigned int)v13 >> 8) & 0x7F,
                   ((unsigned int)v13 >> 15) & 1,
                   v12 + 1,
                   v12 + 3);
        break;
      case 0x1Cu:
        result = dp_txrx_fw_stats_handler(*(_QWORD *)(result + 8), *(_QWORD *)(a2 + 16));
        break;
      case 0x1Eu:
        v35 = v12[3];
        v36 = WORD1(v13);
        v37 = *((unsigned __int16 *)v12 + 8);
        v38 = *((unsigned __int16 *)v12 + 10);
        v39 = *((unsigned __int16 *)v12 + 12);
        v40 = result;
        v106 = (unsigned int)v13 >> 8;
        v41 = HIWORD(v12[2]);
        qdf_trace_msg(
          0x3Fu,
          8u,
          "HTT_T2H_MSG_TYPE_PEER_MAP msg for peer id %d vdev id %d n",
          a3,
          a4,
          a5,
          a6,
          a7,
          a8,
          a9,
          a10,
          WORD1(v13),
          BYTE1(v13));
        qdf_trace_msg(
          0x3Fu,
          4u,
          "ast_idx[0] %d ast_idx[1] %d ast_idx[2] %d ast_idx[3] %d n",
          v42,
          v43,
          v44,
          v45,
          v46,
          v47,
          v48,
          v49,
          v41,
          v37,
          v38,
          v39);
        result = dp_rx_peer_map_handler(*(_QWORD *)(v40 + 8), v36, v41, v106, v12 + 1, v35, HIWORD(v35) & 1);
        break;
      case 0x1Fu:
        v78 = WORD1(v13);
        v79 = *((_BYTE *)v12 + 10);
        v80 = *((unsigned __int16 *)v12 + 8);
        v81 = result;
        v82 = (unsigned int)v13 >> 8;
        qdf_trace_msg(
          0x3Fu,
          4u,
          "HTT_T2H_MSG_TYPE_PEER_UNMAP msg for peer id %d vdev id %d n",
          a3,
          a4,
          a5,
          a6,
          a7,
          a8,
          a9,
          a10,
          WORD1(v13),
          BYTE1(v13));
        result = dp_rx_peer_unmap_handler(*(_QWORD *)(v81 + 8), v78, v82, v12 + 1, v79 & 1, v80);
        break;
      case 0x24u:
        result = dp_htt_bkp_event_alert(*(_QWORD *)(v11 + 224), result);
        break;
      case 0x27u:
        v26 = v12[1];
        v25 = v12[2];
        v27 = BYTE1(v13);
        v28 = result;
        qdf_trace_msg(
          0x3Fu,
          4u,
          "%s: CMEM FSE num_entries %u CMEM BA LO %x HI %x",
          a3,
          a4,
          a5,
          a6,
          a7,
          a8,
          a9,
          a10,
          "dp_htt_t2h_msg_handler",
          BYTE1(v13),
          v26,
          v25);
        result = dp_rx_fst_update_cmem_params(*(_QWORD *)(v28 + 8), v27, v26, v25);
        break;
      case 0x28u:
        v24 = "dp_rx_mlo_timestamp_ind_handler";
        goto LABEL_19;
      case 0x29u:
        v24 = "dp_htt_mlo_peer_map_handler";
        goto LABEL_19;
      case 0x2Au:
        v24 = "dp_htt_mlo_peer_unmap_handler";
LABEL_19:
        result = qdf_trace_msg(0x45u, 1u, "%s: Unexpected event", a3, a4, a5, a6, a7, a8, a9, a10, v24);
        break;
      case 0x2Bu:
        v50 = v12[3];
        v51 = v12[4];
        v52 = WORD1(v13);
        v53 = BYTE1(v13);
        v54 = result;
        v55 = (unsigned int)v13 >> 8;
        qdf_trace_msg(
          0x80u,
          5u,
          "%s: HTT_T2H_MSG_TYPE_PEER_MAP_V3 msg for peer id %d vdev id %d",
          a3,
          a4,
          a5,
          a6,
          a7,
          a8,
          a9,
          a10,
          "dp_htt_t2h_msg_handler",
          WORD1(v13),
          BYTE1(v13));
        result = dp_rx_peer_map_handler(
                   *(_QWORD *)(v54 + 8),
                   v52,
                   v50,
                   v55,
                   v12 + 1,
                   HIWORD(v50) & 0xF,
                   HIWORD(v51) & 1);
        if ( (v51 & 0x80000) != 0 )
        {
          v64 = v12[5];
          v65 = HIWORD(v64);
          qdf_trace_msg(
            0x80u,
            5u,
            "%s: HTT_T2H_MSG_TYPE_PEER_MAP_V3 msg for peer id %d vdev id %d classify_idx_valid %d classify_info_idx %d",
            v56,
            v57,
            v58,
            v59,
            v60,
            v61,
            v62,
            v63,
            "dp_htt_t2h_msg_handler",
            v52,
            v53,
            1,
            BYTE2(v64));
          result = dp_peer_set_tx_classify_idx(*(_QWORD *)(v54 + 8), v52, v55, v65);
        }
        break;
      case 0x30u:
        result = dp_htt_ppdu_id_fmt_handler(*(_QWORD *)(result + 8), *(_QWORD *)(v11 + 224));
        break;
      case 0x31u:
        result = dp_htt_rx_addba_handler(
                   *(_QWORD *)(result + 8),
                   (unsigned int)v13 >> 20,
                   WORD1(v13) & 0xF,
                   v12[1] & 0x1FFF);
        break;
      case 0x32u:
        v83 = (unsigned int)v13 >> 20;
        v84 = v12[1];
        v85 = WORD1(v13) & 0xF;
        v86 = dp_rx_delba_ind_handler(*(_QWORD *)(result + 8), (unsigned int)v13 >> 20, v85, v84 & 0x1FFF);
        result = qdf_trace_msg(
                   0x45u,
                   5u,
                   "%s: DELBA PeerID %d BAW %d TID %d stat %d",
                   v87,
                   v88,
                   v89,
                   v90,
                   v91,
                   v92,
                   v93,
                   v94,
                   "dp_htt_t2h_msg_handler",
                   v83,
                   v84 & 0x1FFF,
                   v85,
                   v86);
        break;
      case 0x33u:
        result = dp_ipa_rx_cce_super_rule_setup_done_handler(result, *(_QWORD *)(v11 + 224));
        break;
      case 0x3Au:
        result = dp_htt_tx_latency_stats_handler(result, *(_QWORD *)(a2 + 16));
        break;
      case 0x3Bu:
        result = dp_ipa_tx_super_rule_setup_done_handler(*(_QWORD *)(v11 + 224));
        break;
      case 0x3Du:
        result = dp_htt_mlo_latency_req(result, *(_QWORD *)(v11 + 224));
        break;
      default:
        break;
    }
  }
  if ( v11 )
    result = _qdf_nbuf_free(v11);
  _ReadStatusReg(SP_EL0);
  return result;
}
