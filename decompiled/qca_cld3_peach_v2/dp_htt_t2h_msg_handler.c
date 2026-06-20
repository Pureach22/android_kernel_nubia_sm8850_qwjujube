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
  unsigned int v24; // w20
  unsigned int v25; // w22
  unsigned int v26; // w21
  __int64 v27; // x23
  __int64 v28; // x0
  unsigned int v29; // w20
  unsigned int v30; // w21
  unsigned int v31; // w22
  unsigned int v32; // w0
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  unsigned __int64 v41; // x21
  __int64 v42; // x24
  __int64 v43; // x25
  unsigned int v44; // w22
  unsigned int v45; // w23
  unsigned int v46; // w21
  unsigned int v47; // w22
  unsigned int v48; // w24
  unsigned int v49; // w27
  unsigned int v50; // w28
  __int64 v51; // x23
  unsigned int v52; // w25
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7
  unsigned int v61; // w24
  unsigned int v62; // w28
  unsigned int v63; // w21
  unsigned int v64; // w23
  __int64 v65; // x27
  unsigned int v66; // w22
  double v67; // d0
  double v68; // d1
  double v69; // d2
  double v70; // d3
  double v71; // d4
  double v72; // d5
  double v73; // d6
  double v74; // d7
  unsigned int v75; // w8
  unsigned int v76; // w20
  unsigned int v77; // w21
  char v78; // w24
  unsigned int v79; // w23
  __int64 v80; // x25
  unsigned int v81; // w22
  unsigned int v82; // w21
  unsigned int v83; // w22
  unsigned int v84; // w20
  unsigned int v85; // w0
  double v86; // d0
  double v87; // d1
  double v88; // d2
  double v89; // d3
  double v90; // d4
  double v91; // d5
  double v92; // d6
  double v93; // d7
  __int64 v94; // x3
  __int64 v95; // x4
  double v96; // d0
  double v97; // d1
  double v98; // d2
  double v99; // d3
  double v100; // d4
  double v101; // d5
  double v102; // d6
  double v103; // d7
  __int64 v104; // x8
  __int64 v105; // [xsp+8h] [xbp-18h]
  int v106; // [xsp+10h] [xbp-10h] BYREF
  __int16 v107; // [xsp+14h] [xbp-Ch]
  __int64 v108; // [xsp+18h] [xbp-8h]

  v108 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
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
        v94 = (unsigned __int8)BYTE2(*v12);
        *(_BYTE *)(v23 + 88) = BYTE2(*v12);
        v95 = (unsigned __int8)BYTE1(*v12);
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
                   v94,
                   v95,
                   3,
                   143);
        v104 = v14;
        if ( *(_BYTE *)(v14 + 88) != 3 )
        {
          result = qdf_trace_msg(
                     0x3Fu,
                     3u,
                     "*** Incompatible host/target HTT versions!",
                     v96,
                     v97,
                     v98,
                     v99,
                     v100,
                     v101,
                     v102,
                     v103);
          v104 = v14;
        }
        if ( *(unsigned __int8 *)(v104 + 89) != 143 )
          result = qdf_trace_msg(
                     0x3Fu,
                     7u,
                     "*** Warning: host/target HTT versions are different, though compatible!",
                     v96,
                     v97,
                     v98,
                     v99,
                     v100,
                     v101,
                     v102,
                     v103);
        break;
      case 3u:
        v41 = v13 >> 16;
        v42 = *(_QWORD *)(result + 8);
        v43 = result;
        v44 = HIWORD(v12[2]);
        v45 = (unsigned int)v13 >> 8;
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
        LODWORD(v42) = *(_QWORD *)(*(_QWORD *)(v42 + 13136) + 8 * v41) != 0;
        dp_check_is_wds_valid(*(_QWORD *)(v43 + 8), (unsigned int)v41, v44, v45, v12 + 1, (unsigned int)v42);
        result = dp_rx_peer_map_handler(
                   *(_QWORD *)(v43 + 8),
                   (unsigned int)v41,
                   v44,
                   v45,
                   v12 + 1,
                   0,
                   (unsigned int)v42);
        break;
      case 4u:
        v28 = *(_QWORD *)(result + 8);
        v107 = 0;
        v106 = 0;
        result = dp_rx_peer_unmap_handler(v28, WORD1(v13), (unsigned int)v13 >> 8, &v106, 0, 0xFFFFFFFFLL);
        break;
      case 5u:
        result = dp_htt_rx_addba_handler(
                   *(_QWORD *)(result + 8),
                   (unsigned int)v13 >> 20,
                   WORD1(v13) & 0xF,
                   (unsigned int)BYTE1(v13) + 1);
        break;
      case 6u:
        v29 = (unsigned int)v13 >> 20;
        v30 = (unsigned __int16)v13 >> 10;
        v31 = WORD1(v13) & 0xF;
        v32 = dp_rx_delba_ind_handler(
                *(_QWORD *)(result + 8),
                (unsigned int)v13 >> 20,
                v31,
                (unsigned __int16)v13 >> 10);
        result = qdf_trace_msg(
                   0x3Fu,
                   4u,
                   "%s: DELBA PeerID %d BAW %d TID %d stat %d",
                   v33,
                   v34,
                   v35,
                   v36,
                   v37,
                   v38,
                   v39,
                   v40,
                   "dp_htt_t2h_msg_handler",
                   v29,
                   v30,
                   v31,
                   v32);
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
        v46 = v12[3];
        v47 = WORD1(v13);
        v48 = *((unsigned __int16 *)v12 + 8);
        v49 = *((unsigned __int16 *)v12 + 10);
        v50 = *((unsigned __int16 *)v12 + 12);
        v51 = result;
        v105 = (unsigned int)v13 >> 8;
        v52 = HIWORD(v12[2]);
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
          v53,
          v54,
          v55,
          v56,
          v57,
          v58,
          v59,
          v60,
          v52,
          v48,
          v49,
          v50);
        result = dp_rx_peer_map_handler(*(_QWORD *)(v51 + 8), v47, v52, v105, v12 + 1, v46, HIWORD(v46) & 1);
        break;
      case 0x1Fu:
        v77 = WORD1(v13);
        v78 = *((_BYTE *)v12 + 10);
        v79 = *((unsigned __int16 *)v12 + 8);
        v80 = result;
        v81 = (unsigned int)v13 >> 8;
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
        result = dp_rx_peer_unmap_handler(*(_QWORD *)(v80 + 8), v77, v81, v12 + 1, v78 & 1, v79);
        break;
      case 0x24u:
        result = dp_htt_bkp_event_alert(*(_QWORD *)(v11 + 224), result);
        break;
      case 0x27u:
        v25 = v12[1];
        v24 = v12[2];
        v26 = BYTE1(v13);
        v27 = result;
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
          v25,
          v24);
        result = dp_rx_fst_update_cmem_params(*(_QWORD *)(v27 + 8), v26, v25, v24);
        break;
      case 0x28u:
        result = dp_rx_mlo_timestamp_ind_handler(*(_QWORD *)(result + 8), *(_QWORD *)(v11 + 224));
        break;
      case 0x29u:
        result = dp_htt_mlo_peer_map_handler(result, *(_QWORD *)(v11 + 224));
        break;
      case 0x2Au:
        result = dp_rx_mlo_peer_unmap_handler(*(_QWORD *)(result + 8), (unsigned int)v13 >> 8);
        break;
      case 0x2Bu:
        v61 = v12[3];
        v62 = v12[4];
        v63 = WORD1(v13);
        v64 = BYTE1(v13);
        v65 = result;
        v66 = (unsigned int)v13 >> 8;
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
                   *(_QWORD *)(v65 + 8),
                   v63,
                   v61,
                   v66,
                   v12 + 1,
                   HIWORD(v61) & 0xF,
                   HIWORD(v62) & 1);
        if ( (v62 & 0x80000) != 0 )
        {
          v75 = v12[5];
          v76 = HIWORD(v75);
          qdf_trace_msg(
            0x80u,
            5u,
            "%s: HTT_T2H_MSG_TYPE_PEER_MAP_V3 msg for peer id %d vdev id %d classify_idx_valid %d classify_info_idx %d",
            v67,
            v68,
            v69,
            v70,
            v71,
            v72,
            v73,
            v74,
            "dp_htt_t2h_msg_handler",
            v63,
            v64,
            1,
            BYTE2(v75));
          result = dp_peer_set_tx_classify_idx(*(_QWORD *)(v65 + 8), v63, v66, v76);
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
        v82 = (unsigned int)v13 >> 20;
        v83 = v12[1];
        v84 = WORD1(v13) & 0xF;
        v85 = dp_rx_delba_ind_handler(*(_QWORD *)(result + 8), (unsigned int)v13 >> 20, v84, v83 & 0x1FFF);
        result = qdf_trace_msg(
                   0x45u,
                   5u,
                   "%s: DELBA PeerID %d BAW %d TID %d stat %d",
                   v86,
                   v87,
                   v88,
                   v89,
                   v90,
                   v91,
                   v92,
                   v93,
                   "dp_htt_t2h_msg_handler",
                   v82,
                   v83 & 0x1FFF,
                   v84,
                   v85);
        break;
      case 0x33u:
        result = dp_ipa_rx_cce_super_rule_setup_done_handler(result, *(_QWORD *)(v11 + 224));
        break;
      case 0x39u:
        result = dp_htt_peer_ext_evt(result, *(_QWORD *)(v11 + 224));
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
