__int64 __fastcall sme_process_msg(
        __int64 a1,
        unsigned __int16 *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  unsigned __int16 *v11; // x20
  __int64 v12; // x19
  __int64 result; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  unsigned int v22; // w19
  __int64 v23; // x4
  int updated; // w0
  const char *v25; // x2
  unsigned int v26; // w1
  __int64 v27; // x0
  __int64 v28; // x0
  __int64 v29; // x1
  __int64 v30; // x1
  void (__fastcall *v31)(_QWORD); // x8
  __int64 v32; // x0
  void (*v33)(void); // x8
  void (__fastcall *v34)(__int64, __int64); // x8
  __int64 v35; // x0
  __int64 v36; // x1
  void (__fastcall *v37)(__int64, __int64); // x8
  __int64 v38; // x1
  __int64 v39; // x0
  void (__fastcall *v40)(__int64, __int64); // x8
  __int64 v41; // x0
  __int64 v42; // x1
  void (__fastcall *v43)(__int64, __int64); // x8
  __int64 v44; // x0
  __int64 v45; // x1
  __int64 v46; // x0
  void (__fastcall *v47)(__int64, __int64); // x8
  __int64 v48; // x1
  __int64 v49; // x0
  void (__fastcall *v50)(_QWORD); // x8
  __int64 v51; // x0
  __int64 v52; // x8

  if ( a2 )
  {
    v11 = a2;
    v12 = a1 + 12848;
    result = qdf_mutex_acquire(a1 + 12848);
    if ( (_DWORD)result )
    {
      if ( *((_QWORD *)v11 + 1) )
      {
        v22 = result;
        _qdf_mem_free(*((_QWORD *)v11 + 1));
        return v22;
      }
    }
    else
    {
      v23 = *v11;
      if ( *(_DWORD *)(a1 + 12840) )
      {
        switch ( *v11 )
        {
          case 0x1414u:
            ((void (__fastcall *)(__int64, _QWORD))csr_roam_roaming_state_start_bss_rsp_processor)(
              a1,
              *((_QWORD *)v11 + 1));
            v27 = *((_QWORD *)v11 + 1);
            goto LABEL_13;
          case 0x1419u:
            ((void (__fastcall *)(__int64, _QWORD))csr_roam_roaming_state_stop_bss_rsp_processor)(
              a1,
              *((_QWORD *)v11 + 1));
            v27 = *((_QWORD *)v11 + 1);
            goto LABEL_13;
          case 0x141Du:
          case 0x141Fu:
          case 0x1420u:
          case 0x1435u:
            if ( !*((_QWORD *)v11 + 1) )
              goto LABEL_115;
            updated = sme_qos_msg_processor(a1, *v11);
            goto LABEL_112;
          case 0x142Cu:
          case 0x142Du:
          case 0x142Fu:
            if ( !*((_QWORD *)v11 + 1) )
              goto LABEL_115;
            updated = sme_rrm_msg_processor(a1, *v11);
            goto LABEL_112;
          case 0x1432u:
            updated = sme_process_sap_ch_width_update_rsp(a1, *((_QWORD *)v11 + 1));
            goto LABEL_112;
          case 0x1438u:
            if ( *((_QWORD *)v11 + 1) )
            {
              updated = sme_handle_generic_change_country_code(a1);
              goto LABEL_112;
            }
            qdf_trace_msg(
              0x34u,
              2u,
              "%s: Empty message for: %d",
              v14,
              v15,
              v16,
              v17,
              v18,
              v19,
              v20,
              v21,
              "sme_process_msg",
              5176);
            goto LABEL_14;
          case 0x144Au:
            if ( *((_QWORD *)v11 + 1) )
            {
              sme_unprotected_mgmt_frm_ind(a1);
              v27 = *((_QWORD *)v11 + 1);
              goto LABEL_13;
            }
            qdf_trace_msg(
              0x34u,
              2u,
              "%s: Empty message for: %d",
              v14,
              v15,
              v16,
              v17,
              v18,
              v19,
              v20,
              v21,
              "sme_process_msg",
              5194);
            goto LABEL_14;
          case 0x1452u:
            if ( *((_QWORD *)v11 + 1) )
            {
              sme_tsm_ie_ind(a1);
              v27 = *((_QWORD *)v11 + 1);
              goto LABEL_13;
            }
            qdf_trace_msg(
              0x34u,
              2u,
              "%s: Empty message for: %d",
              v14,
              v15,
              v16,
              v17,
              v18,
              v19,
              v20,
              v21,
              "sme_process_msg",
              5202);
            goto LABEL_14;
          case 0x1453u:
          case 0x1458u:
          case 0x148Au:
          case 0x1495u:
            updated = dfs_msg_processor(a1, v11);
            goto LABEL_112;
          case 0x1455u:
            if ( *((_QWORD *)v11 + 1) )
            {
              updated = sme_process_channel_change_resp(a1);
              goto LABEL_112;
            }
            qdf_trace_msg(
              0x34u,
              2u,
              "%s: Empty message for: %d",
              v14,
              v15,
              v16,
              v17,
              v18,
              v19,
              v20,
              v21,
              "sme_process_msg",
              5205);
            goto LABEL_14;
          case 0x1459u:
            updated = sme_stats_ext_event(a1, *((_QWORD *)v11 + 1));
            goto LABEL_112;
          case 0x1463u:
            v11 = *((unsigned __int16 **)v11 + 1);
            if ( !v11 )
              break;
            v37 = *(void (__fastcall **)(__int64, __int64))(a1 + 13136);
            if ( v37 )
            {
              v38 = *(_QWORD *)(a1 + 13144);
              v39 = *((unsigned __int8 *)v11 + 4);
              if ( *((_DWORD *)v37 - 1) != 1192198747 )
                __break(0x8228u);
              v37(v39, v38);
            }
            *(_QWORD *)(a1 + 13136) = 0;
            *(_QWORD *)(a1 + 13144) = 0;
            v27 = (__int64)v11;
            goto LABEL_13;
          case 0x1465u:
            v34 = *(void (__fastcall **)(__int64, __int64))(a1 + 13176);
            if ( !v34 )
              goto LABEL_14;
            v35 = *((unsigned int *)v11 + 1);
            v36 = *(_QWORD *)(a1 + 13168);
            if ( *((_DWORD *)v34 - 1) != 127008684 )
              __break(0x8228u);
            goto LABEL_89;
          case 0x1466u:
            v11 = *((unsigned __int16 **)v11 + 1);
            if ( !v11 )
              break;
            v47 = *((void (__fastcall **)(__int64, __int64))v11 + 1);
            if ( v47 )
            {
              v48 = *((_QWORD *)v11 + 2);
              v49 = *((unsigned __int8 *)v11 + 24);
              if ( *((_DWORD *)v47 - 1) != 1696569545 )
                __break(0x8228u);
              v47(v49, v48);
            }
            v27 = (__int64)v11;
            goto LABEL_13;
          case 0x146Au:
            if ( *((_QWORD *)v11 + 1) )
            {
              updated = sme_process_set_hw_mode_resp(a1);
              goto LABEL_112;
            }
            qdf_trace_msg(
              0x34u,
              2u,
              "%s: Empty message for: %d",
              v14,
              v15,
              v16,
              v17,
              v18,
              v19,
              v20,
              v21,
              "sme_process_msg",
              5226);
            goto LABEL_14;
          case 0x146Bu:
            if ( *((_QWORD *)v11 + 1) )
            {
              sme_process_hw_mode_trans_ind(a1);
              v27 = *((_QWORD *)v11 + 1);
              goto LABEL_13;
            }
            qdf_trace_msg(
              0x34u,
              2u,
              "%s: Empty message for: %d",
              v14,
              v15,
              v16,
              v17,
              v18,
              v19,
              v20,
              v21,
              "sme_process_msg",
              5227);
            goto LABEL_14;
          case 0x146Du:
            if ( *((_QWORD *)v11 + 1) )
            {
              updated = sme_process_nss_update_resp(a1);
              goto LABEL_112;
            }
            qdf_trace_msg(
              0x34u,
              2u,
              "%s: Empty message for: %d",
              v14,
              v15,
              v16,
              v17,
              v18,
              v19,
              v20,
              v21,
              "sme_process_msg",
              5229);
            goto LABEL_14;
          case 0x1474u:
            if ( *((_QWORD *)v11 + 1) )
            {
              updated = sme_process_dual_mac_config_resp(a1);
              goto LABEL_112;
            }
            qdf_trace_msg(
              0x34u,
              2u,
              "%s: Empty message for: %d",
              v14,
              v15,
              v16,
              v17,
              v18,
              v19,
              v20,
              v21,
              "sme_process_msg",
              5236);
            goto LABEL_14;
          case 0x1475u:
            v34 = *(void (__fastcall **)(__int64, __int64))(a1 + 14352);
            if ( !v34 )
              goto LABEL_14;
            goto LABEL_87;
          case 0x1478u:
            updated = sme_extended_change_channel_ind(a1, *((_QWORD *)v11 + 1));
            goto LABEL_112;
          case 0x147Cu:
            if ( *((_QWORD *)v11 + 1) )
            {
              updated = sme_process_antenna_mode_resp(a1);
              goto LABEL_112;
            }
            qdf_trace_msg(
              0x34u,
              2u,
              "%s: Empty message for: %d",
              v14,
              v15,
              v16,
              v17,
              v18,
              v19,
              v20,
              v21,
              "sme_process_msg",
              5244);
            goto LABEL_14;
          case 0x147Du:
            v40 = *(void (__fastcall **)(__int64, __int64))(a1 + 13152);
            if ( v40 )
            {
              v41 = *(_QWORD *)(a1 + 13160);
              v42 = *((_QWORD *)v11 + 1);
              if ( *((_DWORD *)v40 - 1) != 831455756 )
                __break(0x8228u);
              v40(v41, v42);
            }
            goto LABEL_12;
          case 0x1486u:
            sme_link_lost_ind(a1, *((_QWORD *)v11 + 1));
            v27 = *((_QWORD *)v11 + 1);
            goto LABEL_13;
          case 0x1488u:
            v43 = *(void (__fastcall **)(__int64, __int64))(a1 + 14408);
            if ( !v43 )
              goto LABEL_105;
            v44 = *(_QWORD *)(a1 + 12832);
            v45 = *((_QWORD *)v11 + 1);
            if ( *((_DWORD *)v43 - 1) != 1647248371 )
              __break(0x8228u);
            goto LABEL_104;
          case 0x1489u:
            v43 = *(void (__fastcall **)(__int64, __int64))(a1 + 13032);
            if ( !v43 )
              goto LABEL_105;
            v44 = *(_QWORD *)(a1 + 12832);
            v45 = *((_QWORD *)v11 + 1);
            if ( *((_DWORD *)v43 - 1) != -1073656782 )
              __break(0x8228u);
LABEL_104:
            v43(v44, v45);
LABEL_105:
            v27 = *((_QWORD *)v11 + 1);
            goto LABEL_13;
          case 0x148Cu:
            v34 = *(void (__fastcall **)(__int64, __int64))(a1 + 14424);
            if ( !v34 )
              goto LABEL_14;
            v35 = *(_QWORD *)(a1 + 12832);
            v36 = *((unsigned int *)v11 + 1);
            if ( *((_DWORD *)v34 - 1) != 508527981 )
              __break(0x8228u);
            goto LABEL_89;
          case 0x1497u:
            v34 = *(void (__fastcall **)(__int64, __int64))(a1 + 14584);
            if ( v34 )
            {
LABEL_87:
              v35 = *(_QWORD *)(a1 + 12832);
              v36 = *((unsigned int *)v11 + 1);
              if ( *((_DWORD *)v34 - 1) != -663432764 )
                __break(0x8228u);
LABEL_89:
              v34(v35, v36);
            }
            else
            {
              qdf_trace_msg(
                0x34u,
                2u,
                "%s: callback is NULL",
                v14,
                v15,
                v16,
                v17,
                v18,
                v19,
                v20,
                v21,
                "sme_process_msg");
            }
            goto LABEL_14;
          case 0x1498u:
            v50 = *(void (__fastcall **)(_QWORD))(a1 + 14464);
            if ( v50 )
            {
              v51 = *(_QWORD *)(a1 + 14472);
              if ( *((_DWORD *)v50 - 1) != 251140989 )
                __break(0x8228u);
              v50(v51);
            }
            LODWORD(v11) = 0;
            *(_QWORD *)(a1 + 14464) = 0;
            *(_QWORD *)(a1 + 14472) = 0;
            break;
          case 0x149Bu:
            v27 = *((_QWORD *)v11 + 1);
            if ( !v27 )
            {
              qdf_trace_msg(
                0x34u,
                2u,
                "%s: Empty message for: %d",
                v14,
                v15,
                v16,
                v17,
                v18,
                v19,
                v20,
                v21,
                "sme_process_msg",
                5275);
              goto LABEL_14;
            }
            v33 = *(void (**)(void))(a1 + 13120);
            if ( v33 )
            {
              if ( *((_DWORD *)v33 - 1) != 1115083711 )
                __break(0x8228u);
              v33();
              v27 = *((_QWORD *)v11 + 1);
            }
            goto LABEL_13;
          case 0x149Du:
            v46 = *((_QWORD *)v11 + 1);
            if ( v46 )
              sme_vdev_self_peer_delete_resp(v46);
            else
              qdf_trace_msg(
                0x34u,
                2u,
                "%s: Empty message for: %d",
                v14,
                v15,
                v16,
                v17,
                v18,
                v19,
                v20,
                v21,
                "sme_process_msg",
                5277);
            goto LABEL_14;
          case 0x14A0u:
            v30 = *((_QWORD *)v11 + 1);
            if ( v30 )
            {
              v31 = *(void (__fastcall **)(_QWORD))(a1 + 14672);
              if ( v31 )
              {
                v32 = *(_QWORD *)(a1 + 12832);
                if ( *((_DWORD *)v31 - 1) != 31132868 )
                  __break(0x8228u);
                v31(v32);
                v30 = *((_QWORD *)v11 + 1);
              }
            }
            v27 = v30;
            goto LABEL_13;
          case 0x14A1u:
            v28 = *((unsigned int *)v11 + 1);
            v29 = 1;
            goto LABEL_107;
          case 0x14A5u:
            sme_process_twt_add_dialog_event(a1, *((_QWORD *)v11 + 1));
            v27 = *((_QWORD *)v11 + 1);
            goto LABEL_13;
          case 0x14A6u:
            sme_process_twt_del_dialog_event(a1, *((_QWORD *)v11 + 1));
            v27 = *((_QWORD *)v11 + 1);
            goto LABEL_13;
          case 0x14A7u:
            sme_process_twt_pause_dialog_event(a1, *((_QWORD *)v11 + 1));
            v27 = *((_QWORD *)v11 + 1);
            goto LABEL_13;
          case 0x14A8u:
            sme_process_twt_resume_dialog_event(a1, *((_QWORD *)v11 + 1));
            v27 = *((_QWORD *)v11 + 1);
            goto LABEL_13;
          case 0x14A9u:
            sme_process_twt_nudge_dialog_event(a1, *((_QWORD *)v11 + 1));
            v27 = *((_QWORD *)v11 + 1);
            goto LABEL_13;
          case 0x14AAu:
            sme_process_twt_notify_event(a1, *((_QWORD *)v11 + 1));
            v27 = *((_QWORD *)v11 + 1);
            goto LABEL_13;
          case 0x14B2u:
            sme_process_chan_info_event(a1, *((_QWORD *)v11 + 1), *((unsigned int *)v11 + 1));
            v27 = *((_QWORD *)v11 + 1);
            goto LABEL_13;
          case 0x14B7u:
            v28 = *((unsigned int *)v11 + 1);
            v29 = 0;
LABEL_107:
            LODWORD(v11) = sme_process_monitor_mode_vdev_evt(v28, v29);
            break;
          default:
            if ( (unsigned int)(v23 - 5120) > 0xB3 )
            {
              v25 = "%s: Unknown message type: %d";
              v26 = 3;
              goto LABEL_11;
            }
            if ( !*((_QWORD *)v11 + 1) )
            {
LABEL_115:
              qdf_trace_msg(
                0x34u,
                2u,
                "%s: Empty message for: %d",
                v14,
                v15,
                v16,
                v17,
                v18,
                v19,
                v20,
                v21,
                "sme_process_msg");
              goto LABEL_14;
            }
            updated = csr_msg_processor(a1);
LABEL_112:
            v52 = *((_QWORD *)v11 + 1);
            LODWORD(v11) = updated;
            _qdf_mem_free(v52);
            break;
        }
      }
      else
      {
        v25 = "%s: message type %d in stop state ignored";
        v26 = 8;
LABEL_11:
        qdf_trace_msg(0x34u, v26, v25, v14, v15, v16, v17, v18, v19, v20, v21, "sme_process_msg", v23);
LABEL_12:
        v27 = *((_QWORD *)v11 + 1);
        if ( v27 )
LABEL_13:
          _qdf_mem_free(v27);
LABEL_14:
        LODWORD(v11) = 0;
      }
      qdf_mutex_release(v12);
      return (unsigned int)v11;
    }
  }
  else
  {
    qdf_trace_msg(0x34u, 2u, "%s: Empty message for SME", a3, a4, a5, a6, a7, a8, a9, a10, "sme_process_msg");
    return 16;
  }
  return result;
}
