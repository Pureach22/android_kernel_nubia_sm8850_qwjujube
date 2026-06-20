void *__fastcall wma_mc_process_handler(
        unsigned __int16 *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  const char *wma_msg_string; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  __int64 *context; // x0
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  void *result; // x0
  unsigned int v37; // w20

  if ( a1 )
  {
    wma_msg_string = mac_trace_get_wma_msg_string(*a1);
    qdf_trace_msg(0x36u, 8u, "Handle %s(0x%x)", v11, v12, v13, v14, v15, v16, v17, v18, wma_msg_string, *a1);
    context = _cds_get_context(54, (__int64)"wma_mc_process_msg", v19, v20, v21, v22, v23, v24, v25, v26);
    if ( context )
    {
      switch ( *a1 )
      {
        case 0x1021u:
          wma_add_sta(context, *((unsigned __int8 **)a1 + 1), v28, v29, v30, v31, v32, v33, v34, v35);
          goto LABEL_115;
        case 0x1023u:
          wma_delete_sta((__int64)context, *((_QWORD *)a1 + 1), v28, v29, v30, v31, v32, v33, v34, v35);
          goto LABEL_115;
        case 0x1027u:
          wma_delete_bss(context, *((_DWORD *)a1 + 1), v28, v29, v30, v31, v32, v33, v34, v35);
          goto LABEL_115;
        case 0x1031u:
          ((void (*)(void))wma_send_beacon)();
          goto LABEL_115;
        case 0x1036u:
          wma_process_update_edca_param_req();
          goto LABEL_113;
        case 0x1037u:
          wma_process_update_beacon_params();
          goto LABEL_113;
        case 0x103Au:
          wma_add_ts_req(context, *((_QWORD *)a1 + 1), v28, v29, v30, v31, v32, v33, v34, v35);
          goto LABEL_115;
        case 0x103Bu:
          wma_del_ts_req(context, *((unsigned __int8 **)a1 + 1), v28, v29, v30, v31, v32, v33, v34, v35);
          goto LABEL_115;
        case 0x104Eu:
          wma_delete_bss_ho_fail((__int64)context, *((_DWORD *)a1 + 1), v28, v29, v30, v31, v32, v33, v34, v35);
          goto LABEL_115;
        case 0x1063u:
          wma_process_set_mimops_req();
          goto LABEL_113;
        case 0x1066u:
          wma_set_tx_power();
          goto LABEL_115;
        case 0x107Eu:
          wma_send_probe_rsp_tmpl();
          goto LABEL_113;
        case 0x1082u:
          wma_set_max_tx_power();
          goto LABEL_115;
        case 0x108Du:
          wma_aggr_qos_req(context, *((_QWORD *)a1 + 1), v28, v29, v30, v31, v32, v33, v34, v35);
          goto LABEL_115;
        case 0x1095u:
          wma_set_keepalive_req();
          goto LABEL_115;
        case 0x1098u:
          wma_send_pdev_set_antenna_mode();
          goto LABEL_113;
        case 0x109Bu:
          wma_process_mcbc_set_filter_req();
          goto LABEL_113;
        case 0x10A4u:
          wma_process_tsm_stats_req((__int64)context, *((_QWORD *)a1 + 1), v28, v29, v30, v31, v32, v33, v34, v35);
          goto LABEL_115;
        case 0x10A7u:
          wma_process_update_opmode();
          goto LABEL_113;
        case 0x10ABu:
          wma_send_roam_preauth_status();
          goto LABEL_113;
        case 0x10B4u:
        case 0x10B5u:
          wma_process_dhcp_ind(context, *((unsigned __int16 **)a1 + 1));
          goto LABEL_113;
        case 0x10B8u:
          wma_process_add_periodic_tx_ptrn_ind(context, *((unsigned __int8 **)a1 + 1));
          goto LABEL_113;
        case 0x10B9u:
          wma_process_del_periodic_tx_ptrn_ind(context, *((unsigned __int8 **)a1 + 1));
          goto LABEL_113;
        case 0x10BAu:
          wma_send_pdev_set_dual_mac_config();
          goto LABEL_113;
        case 0x10BFu:
          wma_process_rate_update_indicate((__int64)context, *((unsigned __int8 **)a1 + 1));
          goto LABEL_115;
        case 0x10C0u:
          wma_send_flush_logs_to_fw(context);
          goto LABEL_115;
        case 0x10C1u:
          wma_send_set_pcl_cmd();
          goto LABEL_113;
        case 0x10C2u:
          wma_get_mws_coex_info_req();
          goto LABEL_113;
        case 0x10C3u:
          wma_process_cli_set_cmd();
          goto LABEL_113;
        case 0x10C7u:
          wma_update_channel_list();
          goto LABEL_113;
        case 0x10CCu:
          wma_process_update_membership();
          goto LABEL_115;
        case 0x10CDu:
          wma_process_update_userpos();
          goto LABEL_115;
        case 0x10CFu:
          wma_update_tdls_peer_state(context, *((unsigned int **)a1 + 1), v28, v29, v30, v31, v32, v33, v34, v35);
          goto LABEL_115;
        case 0x10D9u:
          wma_process_init_thermal_info((__int64)context, *((_QWORD *)a1 + 1), v28, v29, v30, v31, v32, v33, v34, v35);
          goto LABEL_113;
        case 0x10DAu:
          wma_process_set_thermal_level((__int64)context, *((_DWORD *)a1 + 1), v28, v29, v30, v31, v32, v33, v34, v35);
          goto LABEL_115;
        case 0x10DBu:
          wma_config_plm();
          goto LABEL_113;
        case 0x10DCu:
          wma_process_tx_power_limits();
          goto LABEL_113;
        case 0x10DDu:
          wma_set_vdev_intrabss_fwd(
            v28,
            v29,
            v30,
            v31,
            v32,
            v33,
            v34,
            v35,
            (__int64)context,
            *((unsigned __int16 **)a1 + 1));
          goto LABEL_113;
        case 0x10DEu:
          wma_notify_modem_power_state();
          goto LABEL_113;
        case 0x10E1u:
          wma_process_update_rx_nss();
          goto LABEL_113;
        case 0x10E2u:
          wma_stats_ext_req(context, *((unsigned int **)a1 + 1), v28, v29, v30, v31, v32, v33, v34, v35);
          goto LABEL_113;
        case 0x10EEu:
          wma_process_ch_avoid_update_req(context, *((_QWORD *)a1 + 1));
          goto LABEL_113;
        case 0x10EFu:
          wma_process_ll_stats_clear_req();
          goto LABEL_113;
        case 0x10F0u:
          wma_process_ll_stats_set_req();
          goto LABEL_113;
        case 0x10F1u:
          wma_process_ll_stats_get_req();
          goto LABEL_113;
        case 0x10F6u:
          wma_set_base_macaddr_indicate();
          goto LABEL_113;
        case 0x10F8u:
          wma_process_link_status_req(context, *((_QWORD *)a1 + 1), v28, v29, v30, v31, v32, v33, v34, v35);
          goto LABEL_115;
        case 0x10FCu:
          wma_get_temperature();
          goto LABEL_113;
        case 0x10FDu:
          wma_scan_probe_setoui();
          goto LABEL_113;
        case 0x1105u:
          wma_process_set_mas(*((_QWORD *)a1 + 1));
          goto LABEL_113;
        case 0x1106u:
          wma_process_set_miracast();
          goto LABEL_113;
        case 0x1108u:
          wma_config_stats_factor();
          goto LABEL_113;
        case 0x1109u:
          wma_config_guard_time();
          goto LABEL_113;
        case 0x110Du:
          wma_enable_uapsd_mode();
          goto LABEL_113;
        case 0x110Eu:
          wma_disable_uapsd_mode();
          goto LABEL_113;
        case 0x110Fu:
          wma_set_gateway_params();
          goto LABEL_113;
        case 0x1168u:
          wma_enable_specific_fw_logs();
          goto LABEL_113;
        case 0x1169u:
          wma_send_pdev_set_hw_mode_cmd();
          goto LABEL_113;
        case 0x116Du:
          wma_set_rssi_monitoring();
          goto LABEL_113;
        case 0x116Eu:
          wma_process_set_ie_info(context, *((unsigned int **)a1 + 1), v28, v29, v30, v31, v32, v33, v34, v35);
          goto LABEL_113;
        case 0x1171u:
          ((void (*)(void))wma_send_ht40_obss_scanind)();
          goto LABEL_113;
        case 0x1172u:
          wma_set_tsf_gpio_pin(context, *((_DWORD *)a1 + 1));
          goto LABEL_115;
        case 0x1173u:
          wma_add_beacon_filter(context, *((unsigned int **)a1 + 1));
          goto LABEL_113;
        case 0x1174u:
          wma_remove_beacon_filter(context, *((_DWORD **)a1 + 1));
          goto LABEL_113;
        case 0x1175u:
          wma_get_apf_capabilities(context);
          goto LABEL_115;
        case 0x1177u:
          wma_set_wisa_params(context, *((unsigned __int8 **)a1 + 1));
          goto LABEL_113;
        case 0x1178u:
          wma_send_adapt_dwelltime_params(context, *((_QWORD *)a1 + 1));
          goto LABEL_113;
        case 0x1179u:
          wma_process_set_pdev_ie_req();
          goto LABEL_113;
        case 0x1188u:
          wma_enable_disable_caevent_ind(context, *((_DWORD *)a1 + 1));
          goto LABEL_115;
        case 0x118Au:
          wma_process_hal_pwr_dbg_cmd(context, *((_QWORD *)a1 + 1), v28, v29, v30, v31, v32, v33, v34, v35);
          goto LABEL_113;
        case 0x118Bu:
          wma_set_dtim_period();
          goto LABEL_113;
        case 0x118Fu:
          wma_update_tx_fail_cnt_th();
          goto LABEL_113;
        case 0x1190u:
          wma_process_power_debug_stats_req();
          goto LABEL_115;
        case 0x1191u:
          goto LABEL_113;
        case 0x1195u:
          wma_get_rcpi_req();
          goto LABEL_113;
        case 0x119Au:
          wma_config_stats_ext_threshold();
          goto LABEL_113;
        case 0x119Bu:
          wma_send_dbs_scan_selection_params(context);
          goto LABEL_113;
        case 0x11A4u:
          wma_set_arp_req_stats();
          goto LABEL_113;
        case 0x11A5u:
          wma_get_arp_req_stats();
          goto LABEL_113;
        case 0x11A6u:
          wma_process_limit_off_chan();
          goto LABEL_113;
        case 0x11A7u:
          wma_set_del_pmkid_cache();
          result = *((void **)a1 + 1);
          if ( !result )
            return result;
          qdf_mem_set(result, 0x98u, 0);
          goto LABEL_113;
        case 0x11A8u:
          wma_roam_scan_send_hlp();
          goto LABEL_113;
        case 0x11A9u:
          wma_send_obss_detection_cfg();
          goto LABEL_113;
        case 0x11ABu:
          wma_send_invoke_neighbor_report();
          goto LABEL_113;
        case 0x11ACu:
          wma_process_obss_color_collision_req();
          goto LABEL_113;
        case 0x11AEu:
          wma_process_send_addba_req();
          goto LABEL_115;
        case 0x11AFu:
          wma_get_roam_scan_stats();
          goto LABEL_113;
        case 0x11B0u:
          wma_set_ap_vdev_up();
          goto LABEL_115;
        case 0x11B2u:
          wma_process_cfg_action_frm_tb_ppdu(context);
          goto LABEL_113;
        case 0x11B3u:
          wma_process_beacon_debug_stats_req();
          goto LABEL_113;
        case 0x11B9u:
          if ( *((_BYTE *)context + 673) )
            goto LABEL_111;
          wmi_unified_thermal_mitigation_param_cmd_send(*context);
          goto LABEL_118;
        case 0x11BAu:
          if ( *((_BYTE *)context + 673) )
          {
LABEL_111:
            v37 = 4;
          }
          else
          {
            wma_set_thermal_mgmt(context, v28, v29, v30, v31, v32, v33, v34, v35);
LABEL_118:
            v37 = 0;
          }
          _qdf_mem_free(*((_QWORD *)a1 + 1));
          return (void *)v37;
        case 0x11BBu:
          wma_peer_unmap_conf_send(context, *((unsigned __int8 **)a1 + 1), v28, v29, v30, v31, v32, v33, v34, v35);
          goto LABEL_113;
        case 0x11BCu:
          wma_get_isolation(context, v28, v29, v30, v31, v32, v33, v34, v35);
          goto LABEL_115;
        case 0x11BEu:
          wma_get_roam_scan_ch(*context, *((unsigned int *)a1 + 1));
          goto LABEL_115;
        case 0x11C1u:
          wma_twt_process_add_dialog(context, *((_QWORD *)a1 + 1));
          goto LABEL_113;
        case 0x11C2u:
          wma_twt_process_del_dialog(context, *((_QWORD *)a1 + 1));
          goto LABEL_113;
        case 0x11C3u:
          wma_twt_process_pause_dialog();
          goto LABEL_113;
        case 0x11C4u:
          wma_twt_process_resume_dialog();
          goto LABEL_113;
        case 0x11C6u:
          wma_twt_process_nudge_dialog();
          goto LABEL_113;
        case 0x11C8u:
          wma_update_edca_pifs_param();
          goto LABEL_113;
        case 0x11C9u:
          wma_enable_active_apf_mode((__int64)context, *((_QWORD *)a1 + 1), v28, v29, v30, v31, v32, v33, v34, v35);
          goto LABEL_113;
        case 0x11CAu:
          wma_disable_active_apf_mode(context, *((_QWORD *)a1 + 1), v28, v29, v30, v31, v32, v33, v34, v35);
LABEL_113:
          result = *((void **)a1 + 1);
          goto LABEL_114;
        default:
          qdf_trace_msg(
            0x36u,
            8u,
            "%s: Unhandled WMA message of type %d",
            v28,
            v29,
            v30,
            v31,
            v32,
            v33,
            v34,
            v35,
            "wma_mc_process_msg");
          result = *((void **)a1 + 1);
          if ( !result )
            return result;
LABEL_114:
          _qdf_mem_free((__int64)result);
LABEL_115:
          result = nullptr;
          break;
      }
    }
    else
    {
      _qdf_mem_free(*((_QWORD *)a1 + 1));
      return &off_0 + 4;
    }
  }
  else
  {
    qdf_trace_msg(0x36u, 2u, "%s: msg is NULL", a2, a3, a4, a5, a6, a7, a8, a9, "wma_mc_process_msg");
    return &off_0 + 4;
  }
  return result;
}
