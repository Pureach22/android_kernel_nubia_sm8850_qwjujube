const char *__fastcall wmi_id_to_name(int a1)
{
  const char *result; // x0

  if ( a1 <= 77824 )
  {
    if ( a1 > 24576 )
    {
      if ( a1 > 40961 )
      {
        if ( a1 > 49152 )
        {
          if ( a1 > 53259 )
          {
            if ( a1 > 65538 )
            {
              if ( a1 <= 69632 )
              {
                switch ( a1 )
                {
                  case 65539:
                    return "WMI_WLAN_PROFILE_GET_PROFILE_DATA_CMDID";
                  case 65540:
                    return "WMI_WLAN_PROFILE_ENABLE_PROFILE_ID_CMDID";
                  case 65541:
                    return "WMI_WLAN_PROFILE_LIST_PROFILE_ID_CMDID";
                }
              }
              else if ( a1 > 73728 )
              {
                if ( a1 == 73729 )
                  return "WMI_ADD_BCN_FILTER_CMDID";
                if ( a1 == 73730 )
                  return "WMI_RMV_BCN_FILTER_CMDID";
              }
              else
              {
                if ( a1 == 69633 )
                  return "WMI_PDEV_SUSPEND_CMDID";
                if ( a1 == 69634 )
                  return "WMI_PDEV_RESUME_CMDID";
              }
            }
            else if ( a1 <= 57346 )
            {
              switch ( a1 )
              {
                case 53260:
                  return "WMI_P2P_GO_DFS_AP_CONFIG_CMDID";
                case 57345:
                  return "WMI_AP_PS_PEER_PARAM_CMDID";
                case 57346:
                  return "WMI_AP_PS_PEER_UAPSD_COEX_CMDID";
              }
            }
            else
            {
              if ( a1 > 0x10000 )
              {
                if ( a1 == 65537 )
                  return "WMI_WLAN_PROFILE_TRIGGER_CMDID";
                else
                  return "WMI_WLAN_PROFILE_SET_HIST_INTVL_CMDID";
              }
              if ( a1 == 57347 )
                return "WMI_AP_PS_EGAP_PARAM_CMDID";
              if ( a1 == 61441 )
                return "WMI_PEER_RATE_RETRY_SCHED_CMDID";
            }
          }
          else
          {
            if ( a1 > 53252 )
            {
              if ( a1 <= 53255 )
              {
                if ( a1 == 53253 )
                {
                  return "WMI_P2P_SET_VENDOR_IE_DATA_CMDID";
                }
                else if ( a1 == 53254 )
                {
                  return "WMI_P2P_DISC_OFFLOAD_CONFIG_CMDID";
                }
                else
                {
                  return "WMI_P2P_DISC_OFFLOAD_APPIE_CMDID";
                }
              }
              else if ( a1 > 53257 )
              {
                if ( a1 == 53258 )
                  return "WMI_P2P_LISTEN_OFFLOAD_START_CMDID";
                else
                  return "WMI_P2P_LISTEN_OFFLOAD_STOP_CMDID";
              }
              else if ( a1 == 53256 )
              {
                return "WMI_P2P_DISC_OFFLOAD_PATTERN_CMDID";
              }
              else
              {
                return "WMI_P2P_SET_OPPPS_PARAM_CMDID";
              }
            }
            if ( a1 > 53248 )
            {
              if ( a1 > 53250 )
              {
                if ( a1 == 53251 )
                  return "WMI_P2P_GO_SET_BEACON_IE";
                else
                  return "WMI_P2P_GO_SET_PROBE_RESP_IE";
              }
              else if ( a1 == 53249 )
              {
                return "WMI_P2P_DEV_SET_DEVICE_INFO";
              }
              else
              {
                return "WMI_P2P_DEV_SET_DISCOVERABILITY";
              }
            }
            switch ( a1 )
            {
              case 49153:
                return "WMI_OFL_SCAN_ADD_AP_PROFILE";
              case 49154:
                return "WMI_OFL_SCAN_REMOVE_AP_PROFILE";
              case 49155:
                return "WMI_OFL_SCAN_PERIOD";
            }
          }
          return "Invalid WMI cmd";
        }
        if ( a1 <= 40966 )
        {
          if ( a1 <= 40963 )
          {
            if ( a1 == 40962 )
              return "WMI_PDEV_DFS_DISABLE_CMDID";
            else
              return "WMI_DFS_PHYERR_FILTER_ENA_CMDID";
          }
          else if ( a1 == 40964 )
          {
            return "WMI_DFS_PHYERR_FILTER_DIS_CMDID";
          }
          else if ( a1 == 40965 )
          {
            return "WMI_PDEV_DFS_PHYERR_OFFLOAD_ENABLE_CMDID";
          }
          else
          {
            return "WMI_PDEV_DFS_PHYERR_OFFLOAD_DISABLE_CMDID";
          }
        }
        else
        {
          switch ( a1 )
          {
            case 45057:
              return "WMI_ROAM_SCAN_MODE";
            case 45058:
              return "WMI_ROAM_SCAN_RSSI_THRESHOLD";
            case 45059:
              return "WMI_ROAM_SCAN_PERIOD";
            case 45060:
              return "WMI_ROAM_SCAN_RSSI_CHANGE_THRESHOLD";
            case 45061:
              return "WMI_ROAM_AP_PROFILE";
            case 45062:
              return "WMI_ROAM_CHAN_LIST";
            case 45063:
              return "WMI_ROAM_SCAN_CMD";
            case 45064:
              return "WMI_ROAM_SYNCH_COMPLETE";
            case 45065:
              return "WMI_ROAM_SET_RIC_REQUEST_CMDID";
            case 45066:
              return "WMI_ROAM_INVOKE_CMDID";
            case 45067:
              return "WMI_ROAM_FILTER_CMDID";
            case 45068:
              return "WMI_ROAM_SUBNET_CHANGE_CONFIG_CMDID";
            case 45069:
              return "WMI_ROAM_CONFIGURE_MAWC_CMDID";
            case 45070:
              return "WMI_ROAM_SET_MBO_PARAM_CMDID";
            case 45071:
              return "WMI_ROAM_PER_CONFIG_CMDID";
            case 45072:
              return "WMI_ROAM_BTM_CONFIG_CMDID";
            case 45073:
              return "WMI_ENABLE_FILS_CMDID";
            case 45074:
              return "WMI_REQUEST_ROAM_SCAN_STATS_CMDID";
            case 45075:
              return "WMI_ROAM_BSS_LOAD_CONFIG_CMDID";
            case 45076:
              return "WMI_ROAM_DEAUTH_CONFIG_CMDID";
            case 45077:
              return "WMI_ROAM_IDLE_CONFIG_CMDID";
            case 45078:
              return "Invalid WMI cmd";
            case 45079:
              return "WMI_ROAM_ENABLE_DISABLE_TRIGGER_REASON_CMDID";
            case 45080:
              return "WMI_ROAM_PREAUTH_STATUS_CMDID";
            case 45081:
              return "WMI_ROAM_GET_SCAN_CHANNEL_LIST_CMDID";
            case 45082:
              return "WMI_ROAM_MLO_CONFIG_CMDID";
            case 45083:
              return "WMI_ROAM_SET_PARAM_CMDID";
            case 45084:
              return "WMI_ROAM_ENABLE_VENDOR_CONTROL_CMDID";
            case 45085:
              return "WMI_ROAM_GET_VENDOR_CONTROL_PARAM_CMDID";
            default:
              if ( a1 == 40967 )
              {
                result = "WMI_VDEV_ADFS_CH_CFG_CMDID";
              }
              else
              {
                if ( a1 != 40968 )
                  return "Invalid WMI cmd";
                result = "WMI_VDEV_ADFS_OCAC_ABORT_CMDID";
              }
              break;
          }
        }
      }
      else if ( a1 > 28672 )
      {
        if ( a1 > 0x8000 )
        {
          if ( a1 <= 32773 )
          {
            if ( a1 <= 32770 )
            {
              if ( a1 == 32769 )
                return "WMI_ADDBA_CLEAR_RESP_CMDID";
              else
                return "WMI_ADDBA_SEND_CMDID";
            }
            else if ( a1 == 32771 )
            {
              return "WMI_ADDBA_STATUS_CMDID";
            }
            else if ( a1 == 32772 )
            {
              return "WMI_DELBA_SEND_CMDID";
            }
            else
            {
              return "WMI_ADDBA_SET_RESP_CMDID";
            }
          }
          if ( a1 > 36866 )
          {
            switch ( a1 )
            {
              case 36867:
                return "WMI_STA_MIMO_PS_MODE_CMDID";
              case 36868:
                return "WMI_STA_TDCC_CONFIG_CMDID";
              case 40961:
                return "WMI_PDEV_DFS_ENABLE_CMDID";
            }
          }
          else
          {
            switch ( a1 )
            {
              case 32774:
                return "WMI_SEND_SINGLEAMSDU_CMDID";
              case 36865:
                return "WMI_STA_POWERSAVE_MODE_CMDID";
              case 36866:
                return "WMI_STA_POWERSAVE_PARAM_CMDID";
            }
          }
          return "Invalid WMI cmd";
        }
        switch ( a1 )
        {
          case 28673:
            result = "WMI_BCN_TX_CMDID";
            break;
          case 28674:
            result = "WMI_PDEV_SEND_BCN_CMDID";
            break;
          case 28675:
            result = "WMI_BCN_TMPL_CMDID";
            break;
          case 28676:
            result = "WMI_BCN_FILTER_RX_CMDID";
            break;
          case 28677:
            result = "WMI_PRB_REQ_FILTER_RX_CMDID";
            break;
          case 28678:
            result = "WMI_MGMT_TX_CMDID";
            break;
          case 28679:
            result = "WMI_PRB_TMPL_CMDID";
            break;
          case 28680:
            result = "WMI_MGMT_TX_SEND_CMDID";
            break;
          case 28681:
            result = "WMI_OFFCHAN_DATA_TX_SEND_CMDID";
            break;
          case 28682:
            result = "WMI_PDEV_SEND_FD_CMDID";
            break;
          case 28683:
            result = "WMI_BCN_OFFLOAD_CTRL_CMDID";
            break;
          case 28684:
            result = "WMI_BSS_COLOR_CHANGE_ENABLE_CMDID";
            break;
          case 28685:
            result = "WMI_VDEV_BCN_OFFLOAD_QUIET_CONFIG_CMDID";
            break;
          case 28686:
            result = "WMI_FD_TMPL_CMDID";
            break;
          case 28687:
            result = "WMI_QOS_NULL_FRAME_TX_SEND_CMDID";
            break;
          case 28688:
            result = "WMI_MGMT_RX_REO_FILTER_CONFIGURATION_CMDID";
            break;
          default:
            return "Invalid WMI cmd";
        }
      }
      else
      {
        switch ( a1 )
        {
          case 24577:
            result = "WMI_PEER_CREATE_CMDID";
            break;
          case 24578:
            result = "WMI_PEER_DELETE_CMDID";
            break;
          case 24579:
            result = "WMI_PEER_FLUSH_TIDS_CMDID";
            break;
          case 24580:
            result = "WMI_PEER_SET_PARAM_CMDID";
            break;
          case 24581:
            result = "WMI_PEER_ASSOC_CMDID";
            break;
          case 24582:
            result = "WMI_PEER_ADD_WDS_ENTRY_CMDID";
            break;
          case 24583:
            result = "WMI_PEER_REMOVE_WDS_ENTRY_CMDID";
            break;
          case 24584:
            result = "WMI_PEER_MCAST_GROUP_CMDID";
            break;
          case 24585:
            result = "WMI_PEER_INFO_REQ_CMDID";
            break;
          case 24586:
            result = "WMI_PEER_GET_ESTIMATED_LINKSPEED_CMDID";
            break;
          case 24587:
            result = "WMI_PEER_SET_RATE_REPORT_CONDITION_CMDID";
            break;
          case 24588:
            result = "WMI_PEER_UPDATE_WDS_ENTRY_CMDID";
            break;
          case 24589:
            result = "WMI_PEER_ADD_PROXY_STA_ENTRY_CMDID";
            break;
          case 24590:
            result = "WMI_PEER_SMART_ANT_SET_TX_ANTENNA_CMDID";
            break;
          case 24591:
            result = "WMI_PEER_SMART_ANT_SET_TRAIN_INFO_CMDID";
            break;
          case 24592:
            result = "WMI_PEER_SMART_ANT_SET_NODE_CONFIG_OPS_CMDID";
            break;
          case 24593:
            result = "WMI_PEER_ATF_REQUEST_CMDID";
            break;
          case 24594:
            result = "WMI_PEER_BWF_REQUEST_CMDID";
            break;
          case 24595:
            result = "WMI_PEER_REORDER_QUEUE_SETUP_CMDID";
            break;
          case 24596:
            result = "WMI_PEER_REORDER_QUEUE_REMOVE_CMDID";
            break;
          case 24597:
            result = "WMI_PEER_SET_RX_BLOCKSIZE_CMDID";
            break;
          case 24598:
            result = "WMI_PEER_ANTDIV_INFO_REQ_CMDID";
            break;
          case 24599:
            result = "WMI_PEER_RESERVED0_CMDID";
            break;
          case 24600:
            result = "WMI_PEER_TID_MSDUQ_QDEPTH_THRESH_UPDATE_CMDID";
            break;
          case 24601:
            result = "WMI_PEER_TID_CONFIGURATIONS_CMDID";
            break;
          case 24602:
            result = "WMI_PEER_CFR_CAPTURE_CMDID";
            break;
          case 24603:
            result = "WMI_PEER_CHAN_WIDTH_SWITCH_CMDID";
            break;
          case 24604:
            result = "WMI_PEER_TX_PN_REQUEST_CMDID";
            break;
          case 24605:
            result = "WMI_PEER_UNMAP_RESPONSE_CMDID";
            break;
          case 24606:
            result = "WMI_PEER_CONFIG_VLAN_CMDID";
            break;
          case 24607:
            result = "WMI_PEER_CONFIG_PPE_DS_CMDID";
            break;
          case 24608:
            result = "WMI_PEER_ENABLE_DISABLE_INTRA_BSS_CMDID";
            break;
          case 24609:
            result = "WMI_PEER_RX_PN_REQUEST_CMDID";
            break;
          case 24610:
            result = "WMI_PEER_TX_FILTER_CMDID";
            break;
          case 24611:
            result = "WMI_PEER_FLUSH_POLICY_CMDID";
            break;
          case 24614:
            result = "WMI_PEER_MULTIPLE_REORDER_QUEUE_SETUP_CMDID";
            break;
          default:
            return "Invalid WMI cmd";
        }
      }
    }
    else
    {
      if ( a1 <= 12295 )
      {
        if ( a1 > 12291 )
        {
          if ( a1 > 12293 )
          {
            if ( a1 == 12294 )
              return "WMI_SCAN_PROB_REQ_OUI_CMDID";
            else
              return "WMI_SCAN_ADAPTIVE_DWELL_CONFIG_CMDID";
          }
          else if ( a1 == 12292 )
          {
            return "WMI_SCAN_SCH_PRIO_TBL_CMDID";
          }
          else
          {
            return "WMI_SCAN_UPDATE_REQUEST_CMDID";
          }
        }
        if ( a1 > 12289 )
        {
          if ( a1 == 12290 )
            return "WMI_STOP_SCAN_CMDID";
          else
            return "WMI_SCAN_CHAN_LIST_CMDID";
        }
        if ( a1 == 1 )
          return "WMI_INIT_CMDID";
        if ( a1 == 12289 )
          return "WMI_START_SCAN_CMDID";
        return "Invalid WMI cmd";
      }
      switch ( a1 )
      {
        case 16385:
          result = "WMI_PDEV_SET_REGDOMAIN_CMDID";
          break;
        case 16386:
          result = "WMI_PDEV_SET_CHANNEL_CMDID";
          break;
        case 16387:
          result = "WMI_PDEV_SET_PARAM_CMDID";
          break;
        case 16388:
          result = "WMI_PDEV_PKTLOG_ENABLE_CMDID";
          break;
        case 16389:
          result = "WMI_PDEV_PKTLOG_DISABLE_CMDID";
          break;
        case 16390:
          result = "WMI_PDEV_SET_WMM_PARAMS_CMDID";
          break;
        case 16391:
          result = "WMI_PDEV_SET_HT_CAP_IE_CMDID";
          break;
        case 16392:
          result = "WMI_PDEV_SET_VHT_CAP_IE_CMDID";
          break;
        case 16393:
          result = "WMI_PDEV_SET_DSCP_TID_MAP_CMDID";
          break;
        case 16394:
          result = "WMI_PDEV_SET_QUIET_MODE_CMDID";
          break;
        case 16395:
          result = "WMI_PDEV_GREEN_AP_PS_ENABLE_CMDID";
          break;
        case 16396:
          result = "WMI_PDEV_GET_TPC_CONFIG_CMDID";
          break;
        case 16397:
          result = "WMI_PDEV_SET_BASE_MACADDR_CMDID";
          break;
        case 16398:
          result = "WMI_PDEV_DUMP_CMDID";
          break;
        case 16399:
          result = "WMI_PDEV_SET_LED_CONFIG_CMDID";
          break;
        case 16400:
          result = "WMI_PDEV_GET_TEMPERATURE_CMDID";
          break;
        case 16401:
          result = "WMI_PDEV_SET_LED_FLASHING_CMDID";
          break;
        case 16402:
          result = "WMI_PDEV_SMART_ANT_ENABLE_CMDID";
          break;
        case 16403:
          result = "WMI_PDEV_SMART_ANT_SET_RX_ANTENNA_CMDID";
          break;
        case 16404:
          result = "WMI_PDEV_SET_ANTENNA_SWITCH_TABLE_CMDID";
          break;
        case 16405:
          result = "WMI_PDEV_SET_CTL_TABLE_CMDID";
          break;
        case 16406:
          result = "WMI_PDEV_SET_MIMOGAIN_TABLE_CMDID";
          break;
        case 16407:
          result = "WMI_PDEV_FIPS_CMDID";
          break;
        case 16408:
          result = "WMI_PDEV_GET_ANI_CCK_CONFIG_CMDID";
          break;
        case 16409:
          result = "WMI_PDEV_GET_ANI_OFDM_CONFIG_CMDID";
          break;
        case 16410:
          result = "WMI_PDEV_GET_NFCAL_POWER_CMDID";
          break;
        case 16411:
          result = "WMI_PDEV_GET_TPC_CMDID";
          break;
        case 16412:
          result = "WMI_MIB_STATS_ENABLE_CMDID";
          break;
        case 16413:
          result = "WMI_PDEV_SET_PCL_CMDID";
          break;
        case 16414:
          result = "WMI_PDEV_SET_HW_MODE_CMDID";
          break;
        case 16415:
          result = "WMI_PDEV_SET_MAC_CONFIG_CMDID";
          break;
        case 16416:
          result = "WMI_PDEV_SET_ANTENNA_MODE_CMDID";
          break;
        case 16417:
          result = "WMI_SET_PERIODIC_CHANNEL_STATS_CONFIG_CMDID";
          break;
        case 16418:
          result = "WMI_PDEV_WAL_POWER_DEBUG_CMDID";
          break;
        case 16419:
          result = "WMI_PDEV_SET_REORDER_TIMEOUT_VAL_CMDID";
          break;
        case 16420:
          result = "WMI_PDEV_SET_WAKEUP_CONFIG_CMDID";
          break;
        case 16421:
          result = "WMI_PDEV_GET_ANTDIV_STATUS_CMDID";
          break;
        case 16422:
          result = "WMI_PDEV_GET_CHIP_POWER_STATS_CMDID";
          break;
        case 16423:
          result = "WMI_PDEV_SET_STATS_THRESHOLD_CMDID";
          break;
        case 16424:
          result = "WMI_PDEV_MULTIPLE_VDEV_RESTART_REQUEST_CMDID";
          break;
        case 16425:
          result = "WMI_PDEV_UPDATE_PKT_ROUTING_CMDID";
          break;
        case 16426:
          result = "WMI_PDEV_CHECK_CAL_VERSION_CMDID";
          break;
        case 16427:
          result = "WMI_PDEV_SET_DIVERSITY_GAIN_CMDID";
          break;
        case 16428:
          result = "WMI_PDEV_DIV_GET_RSSI_ANTID_CMDID";
          break;
        case 16429:
          result = "WMI_PDEV_BSS_CHAN_INFO_REQUEST_CMDID";
          break;
        case 16430:
          result = "WMI_PDEV_UPDATE_PMK_CACHE_CMDID";
          break;
        case 16431:
          result = "WMI_PDEV_UPDATE_FILS_HLP_PKT_CMDID";
          break;
        case 16432:
          result = "WMI_PDEV_UPDATE_CTLTABLE_REQUEST_CMDID";
          break;
        case 16433:
          result = "WMI_PDEV_CONFIG_VENDOR_OUI_ACTION_CMDID";
          break;
        case 16434:
          result = "WMI_PDEV_SET_AC_TX_QUEUE_OPTIMIZED_CMDID";
          break;
        case 16435:
          result = "WMI_PDEV_SET_RX_FILTER_PROMISCUOUS_CMDID";
          break;
        case 16436:
          result = "WMI_PDEV_DMA_RING_CFG_REQ_CMDID";
          break;
        case 16437:
          result = "WMI_PDEV_HE_TB_ACTION_FRM_CMDID";
          break;
        case 16438:
          result = "WMI_PDEV_PKTLOG_FILTER_CMDID";
          break;
        case 16439:
          result = "WMI_PDEV_SET_RAP_CONFIG_CMDID";
          break;
        case 16440:
          result = "WMI_PDEV_DSM_FILTER_CMDID";
          break;
        case 16441:
          result = "WMI_PDEV_FRAME_INJECT_CMDID";
          break;
        case 16442:
          result = "WMI_PDEV_TBTT_OFFSET_SYNC_CMDID";
          break;
        case 16443:
          result = "WMI_PDEV_SET_SRG_BSS_COLOR_BITMAP_CMDID";
          break;
        case 16444:
          result = "WMI_PDEV_SET_SRG_PARTIAL_BSSID_BITMAP_CMDID";
          break;
        case 16445:
          result = "WMI_PDEV_SET_SRG_OBSS_COLOR_ENABLE_BITMAP_CMDID";
          break;
        case 16446:
          result = "WMI_PDEV_SET_SRG_OBSS_BSSID_ENABLE_BITMAP_CMDID";
          break;
        case 16447:
          result = "WMI_PDEV_SET_NON_SRG_OBSS_COLOR_ENABLE_BITMAP_CMDID";
          break;
        case 16448:
          result = "WMI_PDEV_SET_NON_SRG_OBSS_BSSID_ENABLE_BITMAP_CMDID";
          break;
        case 16449:
          result = "WMI_PDEV_GET_TPC_STATS_CMDID";
          break;
        case 16450:
          result = "WMI_PDEV_ENABLE_DURATION_BASED_TX_MODE_SELECTION_CMDID";
          break;
        case 16451:
          result = "WMI_PDEV_GET_DPD_STATUS_CMDID";
          break;
        case 16452:
          result = "WMI_PDEV_SET_BIOS_SAR_TABLE_CMDID";
          break;
        case 16453:
          result = "WMI_PDEV_SET_BIOS_GEO_TABLE_CMDID";
          break;
        case 16454:
          result = "WMI_PDEV_GET_HALPHY_CAL_STATUS_CMDID";
          break;
        case 16455:
          result = "WMI_PDEV_SET_HALPHY_CAL_BMAP_CMDID";
          break;
        case 16456:
          result = "WMI_PDEV_MULTIPLE_VDEV_SET_PARAM_CMDID";
          break;
        case 16457:
          result = "WMI_PDEV_MEC_AGING_TIMER_CONFIG_CMDID";
          break;
        case 16458:
          result = "WMI_PDEV_SET_BIOS_INTERFACE_CMDID";
          break;
        case 16459:
          result = "WMI_PDEV_FIPS_EXTEND_CMDID";
          break;
        case 16460:
          result = "WMI_PDEV_FIPS_MODE_SET_CMDID";
          break;
        case 16461:
          result = "WMI_PDEV_FEATURESET_CMDID";
          break;
        case 16462:
          result = "WMI_PDEV_MESH_RX_FILTER_ENABLE_CMDID";
          break;
        case 16463:
          result = "WMI_PDEV_SET_TGTR2P_TABLE_CMDID";
          break;
        case 16464:
          result = "WMI_PDEV_SET_RF_PATH_CMDID";
          break;
        case 16465:
          result = "WMI_PDEV_WSI_STATS_INFO_CMDID";
          break;
        case 16466:
          result = "WMI_PDEV_ENABLE_LED_BLINK_DOWNLOAD_TABLE_CMDID";
          break;
        case 16467:
          result = "WMI_PDEV_ENABLE_WIFI_RADAR_CMDID";
          break;
        case 16468:
          result = "WMI_PDEV_ENABLE_XLNA_CMDID";
          break;
        case 16469:
          result = "WMI_PDEV_SET_CUSTOM_TX_POWER_PER_MCS_CMDID";
          break;
        case 16470:
          result = "WMI_PDEV_POWER_BOOST_CMDID";
          break;
        case 16471:
          result = "WMI_PDEV_POWER_BOOST_MEM_ADDR_CMDID";
          break;
        default:
          switch ( a1 )
          {
            case 20481:
              result = "WMI_VDEV_CREATE_CMDID";
              break;
            case 20482:
              result = "WMI_VDEV_DELETE_CMDID";
              break;
            case 20483:
              result = "WMI_VDEV_START_REQUEST_CMDID";
              break;
            case 20484:
              result = "WMI_VDEV_RESTART_REQUEST_CMDID";
              break;
            case 20485:
              result = "WMI_VDEV_UP_CMDID";
              break;
            case 20486:
              result = "WMI_VDEV_STOP_CMDID";
              break;
            case 20487:
              result = "WMI_VDEV_DOWN_CMDID";
              break;
            case 20488:
              result = "WMI_VDEV_SET_PARAM_CMDID";
              break;
            case 20489:
              result = "WMI_VDEV_INSTALL_KEY_CMDID";
              break;
            case 20490:
              result = "WMI_VDEV_WNM_SLEEPMODE_CMDID";
              break;
            case 20491:
              result = "WMI_VDEV_WMM_ADDTS_CMDID";
              break;
            case 20492:
              result = "WMI_VDEV_WMM_DELTS_CMDID";
              break;
            case 20493:
              result = "WMI_VDEV_SET_WMM_PARAMS_CMDID";
              break;
            case 20494:
              result = "WMI_VDEV_SET_GTX_PARAMS_CMDID";
              break;
            case 20495:
              result = "WMI_VDEV_IPSEC_NATKEEPALIVE_FILTER_CMDID";
              break;
            case 20496:
              result = "WMI_VDEV_PLMREQ_START_CMDID";
              break;
            case 20497:
              result = "WMI_VDEV_PLMREQ_STOP_CMDID";
              break;
            case 20498:
              result = "WMI_VDEV_TSF_TSTAMP_ACTION_CMDID";
              break;
            case 20499:
              result = "WMI_VDEV_SET_IE_CMDID";
              break;
            case 20500:
              result = "WMI_VDEV_RATEMASK_CMDID";
              break;
            case 20501:
              result = "WMI_VDEV_ATF_REQUEST_CMDID";
              break;
            case 20502:
              result = "WMI_VDEV_SET_DSCP_TID_MAP_CMDID";
              break;
            case 20503:
              result = "WMI_VDEV_FILTER_NEIGHBOR_RX_PACKETS_CMDID";
              break;
            case 20504:
              result = "WMI_VDEV_SET_QUIET_MODE_CMDID";
              break;
            case 20505:
              result = "WMI_VDEV_SET_CUSTOM_AGGR_SIZE_CMDID";
              break;
            case 20506:
              result = "WMI_VDEV_ENCRYPT_DECRYPT_DATA_REQ_CMDID";
              break;
            case 20507:
              result = "WMI_VDEV_ADD_MAC_ADDR_TO_RX_FILTER_CMDID";
              break;
            case 20508:
              result = "WMI_VDEV_SET_ARP_STAT_CMDID";
              break;
            case 20509:
              result = "WMI_VDEV_GET_ARP_STAT_CMDID";
              break;
            case 20510:
              result = "WMI_VDEV_GET_TX_POWER_CMDID";
              break;
            case 20511:
              result = "WMI_VDEV_LIMIT_OFFCHAN_CMDID";
              break;
            case 20512:
              result = "WMI_VDEV_SET_CUSTOM_SW_RETRY_TH_CMDID";
              break;
            case 20513:
              result = "WMI_VDEV_CHAINMASK_CONFIG_CMDID";
              break;
            case 20514:
              result = "WMI_VDEV_GET_BCN_RECEPTION_STATS_CMDID";
              break;
            case 20515:
              result = "WMI_VDEV_GET_MWS_COEX_INFO_CMDID";
              break;
            case 20516:
              result = "WMI_VDEV_DELETE_ALL_PEER_CMDID";
              break;
            case 20517:
              result = "WMI_VDEV_BSS_MAX_IDLE_TIME_CMDID";
              break;
            case 20518:
              result = "WMI_VDEV_AUDIO_SYNC_TRIGGER_CMDID";
              break;
            case 20519:
              result = "WMI_VDEV_AUDIO_SYNC_QTIMER_CMDID";
              break;
            case 20520:
              result = "WMI_VDEV_SET_PCL_CMDID";
              break;
            case 20521:
              result = "WMI_VDEV_GET_BIG_DATA_CMDID";
              break;
            case 20522:
              result = "WMI_VDEV_GET_BIG_DATA_P2_CMDID";
              break;
            case 20523:
              result = "WMI_VDEV_SET_TPC_POWER_CMDID";
              break;
            case 20524:
              result = "WMI_VDEV_IGMP_OFFLOAD_CMDID";
              break;
            case 20525:
              result = "WMI_VDEV_ENABLE_DISABLE_INTRA_BSS_CMDID";
              break;
            case 20526:
              result = "WMI_VDEV_SET_MU_SNIF_CMDID";
              break;
            case 20527:
              result = "WMI_VDEV_ICMP_OFFLOAD_CMDID";
              break;
            case 20528:
              result = "WMI_VDEV_UPDATE_MAC_ADDR_CMDID";
              break;
            case 20529:
              result = "WMI_VDEV_MULTIPLE_PEER_GROUP_CMDID";
              break;
            case 20530:
              result = "WMI_VDEV_SET_LTF_KEY_SEED_CMDID";
              break;
            case 20531:
              result = "WMI_VDEV_PN_MGMT_RX_FILTER_CMDID";
              break;
            case 20532:
              result = "WMI_VDEV_PARAM_ENABLE_SR_PROHIBIT_CMDID";
              break;
            case 20533:
              result = "WMI_VDEV_PAUSE_CMDID";
              break;
            case 20534:
              result = "WMI_CSA_EVENT_STATUS_INDICATION_CMDID";
              break;
            case 20535:
              result = "WMI_VDEV_SCHED_MODE_PROBE_REQ_CMDID";
              break;
            case 20536:
              result = "WMI_VDEV_OOB_CONNECTION_REQ_CMDID";
              break;
            case 20537:
              result = "WMI_VDEV_REPORT_AP_OPER_BW_CMDID";
              break;
            case 20538:
              result = "WMI_VDEV_VBSS_CONFIG_CMDID";
              break;
            default:
              if ( a1 != 12296 )
                return "Invalid WMI cmd";
              result = "WMI_SET_SCAN_DBS_DUTY_CYCLE_CMDID";
              break;
          }
          break;
      }
    }
  }
  else if ( a1 > 159748 )
  {
    if ( a1 <= 237568 )
    {
      if ( a1 > 196609 )
      {
        if ( a1 <= 212992 )
        {
          if ( a1 > 200711 )
          {
            if ( a1 <= 204803 )
            {
              if ( a1 > 204801 )
              {
                if ( a1 == 204802 )
                  return "WMI_SOC_SET_HW_MODE_CMDID";
                else
                  return "WMI_SOC_SET_DUAL_MAC_CONFIG_CMDID";
              }
              if ( a1 == 200712 )
                return "WMI_DCC_UPDATE_NDL_CMDID";
              if ( a1 == 204801 )
                return "WMI_SOC_SET_PCL_CMDID";
            }
            else
            {
              if ( a1 <= 204805 )
              {
                if ( a1 == 204804 )
                  return "WMI_SOC_SET_ANTENNA_MODE_CMDID";
                else
                  return "WMI_SOC_TQM_RESET_ENABLE_DISABLE_CMDID";
              }
              switch ( a1 )
              {
                case 204806:
                  return "WMI_SOC_TX_PACKET_CUSTOM_CLASSIFY_CMDID";
                case 208897:
                  return "WMI_PACKET_FILTER_CONFIG_CMDID";
                case 208898:
                  return "WMI_PACKET_FILTER_ENABLE_CMDID";
              }
            }
          }
          else
          {
            if ( a1 > 200706 )
            {
              if ( a1 <= 200708 )
              {
                if ( a1 == 200707 )
                  return "WMI_OCB_START_TIMING_ADVERT_CMDID";
                else
                  return "WMI_OCB_STOP_TIMING_ADVERT_CMDID";
              }
              else if ( a1 == 200709 )
              {
                return "WMI_OCB_GET_TSF_TIMER_CMDID";
              }
              else if ( a1 == 200710 )
              {
                return "WMI_DCC_GET_STATS_CMDID";
              }
              else
              {
                return "WMI_DCC_CLEAR_STATS_CMDID";
              }
            }
            if ( a1 > 200704 )
            {
              if ( a1 == 200705 )
                return "WMI_OCB_SET_CONFIG_CMDID";
              else
                return "WMI_OCB_SET_UTC_TIME_CMDID";
            }
            if ( a1 == 196610 )
              return "WMI_SAP_SET_BLACKLIST_PARAM_CMDID";
            if ( a1 == 196611 )
              return "WMI_SAP_OBSS_DETECTION_CFG_CMDID";
          }
        }
        else if ( a1 <= 221191 )
        {
          if ( a1 > 221186 )
          {
            if ( a1 <= 221188 )
            {
              if ( a1 == 221187 )
                return "WMI_BPF_SET_VDEV_INSTRUCTIONS_CMDID";
              else
                return "WMI_BPF_DEL_VDEV_INSTRUCTIONS_CMDID";
            }
            else if ( a1 == 221189 )
            {
              return "WMI_BPF_SET_VDEV_ACTIVE_MODE_CMDID";
            }
            else if ( a1 == 221190 )
            {
              return "WMI_BPF_SET_VDEV_ENABLE_CMDID";
            }
            else
            {
              return "WMI_BPF_SET_VDEV_WORK_MEMORY_CMDID";
            }
          }
          if ( a1 > 221184 )
          {
            if ( a1 == 221185 )
              return "WMI_BPF_GET_CAPABILITY_CMDID";
            else
              return "WMI_BPF_GET_VDEV_STATS_CMDID";
          }
          if ( a1 == 212993 )
            return "WMI_MAWC_SENSOR_REPORT_IND_CMDID";
          if ( a1 == 217089 )
            return "WMI_PMF_OFFLOAD_SET_SA_QUERY_CMDID";
        }
        else if ( a1 > 229378 )
        {
          if ( a1 <= 229380 )
          {
            if ( a1 == 229379 )
              return "WMI_NDP_RESPONDER_REQ_CMDID";
            else
              return "WMI_NDP_END_REQ_CMDID";
          }
          switch ( a1 )
          {
            case 229381:
              return "WMI_NDP_CMDID";
            case 229382:
              return "WMI_NDP_SET_LATENCY_TPUT_CMDID";
            case 233473:
              return "WMI_MNT_FILTER_CMDID";
          }
        }
        else
        {
          if ( a1 <= 221193 )
          {
            if ( a1 == 221192 )
              return "WMI_BPF_GET_VDEV_WORK_MEMORY_CMDID";
            else
              return "WMI_BPF_SET_SUPPORTED_OFFLOAD_BITMAP_CMDID";
          }
          switch ( a1 )
          {
            case 221194:
              return "WMI_BPF_SET_APF_MODE_CMDID";
            case 229377:
              return "WMI_NDI_GET_CAP_REQ_CMDID";
            case 229378:
              return "WMI_NDP_INITIATOR_REQ_CMDID";
          }
        }
      }
      else if ( a1 <= 176130 )
      {
        if ( a1 > 167942 )
        {
          if ( a1 <= 172032 )
          {
            if ( a1 > 167945 )
            {
              if ( a1 == 167946 )
                return "WMI_ESL_EGID_CMDID";
              if ( a1 == 167947 )
                return "WMI_COEX_MULTIPLE_CONFIG_CMDID";
            }
            else
            {
              if ( a1 == 167943 )
                return "WMI_SAR_GET_LIMITS_CMDID";
              if ( a1 == 167944 )
                return "WMI_COEX_DBAM_CMDID";
            }
          }
          else
          {
            if ( a1 <= 172034 )
            {
              if ( a1 == 172033 )
                return "WMI_OBSS_SCAN_ENABLE_CMDID";
              else
                return "WMI_OBSS_SCAN_DISABLE_CMDID";
            }
            switch ( a1 )
            {
              case 172035:
                return "WMI_OBSS_COLOR_COLLISION_DET_CONFIG_CMDID";
              case 176129:
                return "WMI_LPI_MGMT_SNOOPING_CONFIG_CMDID";
              case 176130:
                return "WMI_LPI_START_SCAN_CMDID";
            }
          }
        }
        else
        {
          if ( a1 > 167937 )
          {
            if ( a1 <= 167939 )
            {
              if ( a1 == 167938 )
                return "WMI_CHAN_AVOID_UPDATE_CMDID";
              else
                return "WMI_COEX_CONFIG_CMDID";
            }
            else if ( a1 == 167940 )
            {
              return "WMI_CHAN_AVOID_RPT_ALLOW_CMDID";
            }
            else if ( a1 == 167941 )
            {
              return "WMI_COEX_GET_ANTENNA_ISOLATION_CMDID";
            }
            else
            {
              return "WMI_SAR_LIMITS_CMDID";
            }
          }
          if ( a1 > 163841 )
          {
            if ( a1 == 163842 )
              return "WMI_NAN_OEM_DATA_CMDID";
            if ( a1 == 167937 )
              return "WMI_MODEM_POWER_STATE_CMDID";
          }
          else
          {
            if ( a1 == 159749 )
              return "WMI_OEM_DATA_CMDID";
            if ( a1 == 163841 )
              return "WMI_NAN_CMDID";
          }
        }
      }
      else if ( a1 <= 180232 )
      {
        if ( a1 > 180227 )
        {
          if ( a1 <= 180229 )
          {
            if ( a1 == 180228 )
              return "WMI_EXTSCAN_CONFIGURE_HOTLIST_MONITOR_CMDID";
            else
              return "WMI_EXTSCAN_GET_CACHED_RESULTS_CMDID";
          }
          else if ( a1 == 180230 )
          {
            return "WMI_EXTSCAN_GET_WLAN_CHANGE_RESULTS_CMDID";
          }
          else if ( a1 == 180231 )
          {
            return "WMI_EXTSCAN_SET_CAPABILITIES_CMDID";
          }
          else
          {
            return "WMI_EXTSCAN_GET_CAPABILITIES_CMDID";
          }
        }
        if ( a1 > 180225 )
        {
          if ( a1 == 180226 )
            return "WMI_EXTSCAN_STOP_CMDID";
          else
            return "WMI_EXTSCAN_CONFIGURE_WLAN_CHANGE_MONITOR_CMDID";
        }
        if ( a1 == 176131 )
          return "WMI_LPI_STOP_SCAN_CMDID";
        if ( a1 == 180225 )
          return "WMI_EXTSCAN_START_CMDID";
      }
      else if ( a1 > 192513 )
      {
        if ( a1 <= 192515 )
        {
          if ( a1 == 192514 )
            return "WMI_MDNS_SET_FQDN_CMDID";
          else
            return "WMI_MDNS_SET_RESPONSE_CMDID";
        }
        switch ( a1 )
        {
          case 192516:
            return "WMI_MDNS_GET_STATS_CMDID";
          case 192517:
            return "WMI_MDNS_SET_STAIP_CMDID";
          case 196609:
            return "WMI_SAP_OFL_ENABLE_CMDID";
        }
      }
      else if ( a1 <= 184320 )
      {
        if ( a1 == 180233 )
          return "WMI_EXTSCAN_CONFIGURE_HOTLIST_SSID_MONITOR_CMDID";
        if ( a1 == 180234 )
          return "WMI_EXTSCAN_CONFIGURE_MAWC_CMDID";
      }
      else
      {
        switch ( a1 )
        {
          case 184321:
            return "WMI_SET_DHCP_SERVER_OFFLOAD_CMDID";
          case 188417:
            return "WMI_IPA_OFFLOAD_ENABLE_DISABLE_CMDID";
          case 192513:
            return "WMI_MDNS_OFFLOAD_ENABLE_CMDID";
        }
      }
      return "Invalid WMI cmd";
    }
    if ( a1 > 278528 )
    {
      if ( a1 > 299008 )
      {
        if ( a1 > 319488 )
        {
          if ( a1 <= 319491 )
          {
            if ( a1 == 319489 )
              return "WMI_ENERGY_MGMT_PCIE_CONFIG_CMDID";
            if ( a1 == 319490 )
              return "WMI_ENERGY_MGMT_PCIE_LPM_CMDID";
            return "WMI_ENERGY_MGMT_DCVS_CONFIG_CMDID";
          }
          switch ( a1 )
          {
            case 319492:
              return "WMI_ENERGY_MGMT_EDPS_CONFIG_CMDID";
            case 319493:
              return "WMI_ENERGY_MGMT_PUO_CONFIG_CMDID";
            case 319494:
              return "WMI_ENERGY_MGMT_ECO_MODE_CONFIG_CMDID";
          }
        }
        else if ( a1 > 311296 )
        {
          switch ( a1 )
          {
            case 311297:
              return "WMI_TDMA_SCHEDULE_REQUEST_CMDID";
            case 315393:
              return "WMI_VDEV_SET_ULOFDMA_MANUAL_SU_TRIG_CMDID";
            case 315394:
              return "WMI_VDEV_SET_ULOFDMA_MANUAL_MU_TRIG_CMDID";
          }
        }
        else
        {
          switch ( a1 )
          {
            case 299009:
              return "WMI_SAWF_SVC_CLASS_CFG_CMDID";
            case 299010:
              return "WMI_SAWF_SVC_CLASS_DISABLE_CMDID";
            case 299011:
              return "WMI_SAWF_EZMESH_HOP_COUNT_CMDID";
          }
        }
        return "Invalid WMI cmd";
      }
      if ( a1 <= 290816 )
      {
        if ( a1 <= 282626 )
        {
          switch ( a1 )
          {
            case 278529:
              return "WMI_CFR_CAPTURE_FILTER_CMDID";
            case 282625:
              return "WMI_ATF_SSID_GROUPING_REQUEST_CMDID";
            case 282626:
              return "WMI_ATF_GROUP_WMM_AC_CONFIG_REQUEST_CMDID";
          }
        }
        else if ( a1 > 286721 )
        {
          if ( a1 == 286722 )
            return "WMI_VENDOR_VDEV_CMDID";
          if ( a1 == 286723 )
            return "WMI_VENDOR_PEER_CMDID";
        }
        else
        {
          if ( a1 == 282627 )
            return "WMI_PEER_ATF_EXT_REQUEST_CMDID";
          if ( a1 == 286721 )
            return "WMI_VENDOR_PDEV_CMDID";
        }
        return "Invalid WMI cmd";
      }
      switch ( a1 )
      {
        case 294913:
          return "WMI_MLO_LINK_SET_ACTIVE_CMDID";
        case 294914:
          return "WMI_MLO_SETUP_CMDID";
        case 294915:
          return "WMI_MLO_READY_CMDID";
        case 294916:
          return "WMI_MLO_TEARDOWN_CMDID";
        case 294917:
          return "WMI_MLO_PEER_TID_TO_LINK_MAP_CMDID";
        case 294918:
          return "WMI_MLO_LINK_REMOVAL_CMDID";
        case 294919:
          return "WMI_MLO_AP_VDEV_TID_TO_LINK_MAP_CMDID";
        case 294920:
          return "WMI_MLO_VDEV_GET_LINK_INFO_CMDID";
        case 294921:
        case 294922:
          return "Invalid WMI cmd";
        case 294923:
          return "WMI_MLO_PRIMARY_LINK_PEER_MIGRATION_CMDID";
        case 294924:
          return "WMI_MLO_LINK_RECOMMENDATION_CMDID";
        case 294925:
          return "WMI_MLO_LINK_RECONFIG_CMDID";
        case 294926:
          return "WMI_MLO_LINK_RECONFIG_COMPLETE_CMDID";
        case 294927:
          return "WMI_MLO_LINK_TTLM_COMPLETE_CMDID";
        default:
          if ( a1 == 290817 )
          {
            result = "WMI_VDEV_TID_LATENCY_CONFIG_CMDID";
          }
          else
          {
            if ( a1 != 290818 )
              return "Invalid WMI cmd";
            result = "WMI_PEER_TID_LATENCY_CONFIG_CMDID";
          }
          break;
      }
    }
    else
    {
      if ( a1 <= 253963 )
      {
        if ( a1 > 253953 )
        {
          if ( a1 > 253958 )
          {
            if ( a1 <= 253960 )
            {
              if ( a1 == 253959 )
                return "WMI_TWT_BTWT_INVITE_STA_CMDID";
              else
                return "WMI_TWT_BTWT_REMOVE_STA_CMDID";
            }
            else if ( a1 == 253961 )
            {
              return "WMI_TWT_NUDGE_DIALOG_CMDID";
            }
            else if ( a1 == 253962 )
            {
              return "WMI_VDEV_SET_TWT_EDCA_PARAMS_CMDID";
            }
            else
            {
              return "WMI_VDEV_GET_TWT_SESSION_STATS_INFO_CMDID";
            }
          }
          else if ( a1 <= 253955 )
          {
            if ( a1 == 253954 )
              return "WMI_TWT_DISABLE_CMDID";
            else
              return "WMI_TWT_ADD_DIALOG_CMDID";
          }
          else if ( a1 == 253956 )
          {
            return "WMI_TWT_DEL_DIALOG_CMDID";
          }
          else if ( a1 == 253957 )
          {
            return "WMI_TWT_PAUSE_DIALOG_CMDID";
          }
          else
          {
            return "WMI_TWT_RESUME_DIALOG_CMDID";
          }
        }
        if ( a1 > 241664 )
        {
          if ( a1 <= 249856 )
          {
            if ( a1 == 241665 )
              return "WMI_HW_DATA_FILTER_CMDID";
            if ( a1 == 245761 )
              return "WMI_WLM_CONFIG_CMDID";
          }
          else
          {
            switch ( a1 )
            {
              case 249857:
                return "WMI_11K_OFFLOAD_REPORT_CMDID";
              case 249858:
                return "WMI_11K_INVOKE_NEIGHBOR_REPORT_CMDID";
              case 253953:
                return "WMI_TWT_ENABLE_CMDID";
            }
          }
        }
        else
        {
          if ( a1 <= 237570 )
          {
            if ( a1 == 237569 )
              return "WMI_SET_CURRENT_COUNTRY_CMDID";
            else
              return "WMI_11D_SCAN_START_CMDID";
          }
          switch ( a1 )
          {
            case 237571:
              return "WMI_11D_SCAN_STOP_CMDID";
            case 237572:
              return "WMI_SET_INIT_COUNTRY_CMDID";
            case 237573:
              return "WMI_AFC_CMDID";
          }
        }
        return "Invalid WMI cmd";
      }
      if ( a1 <= 262145 )
      {
        if ( a1 <= 258049 )
        {
          if ( a1 == 253964 )
            return "WMI_TWT_VDEV_CONFIG_CMDID";
          if ( a1 == 258049 )
            return "WMI_MOTION_DET_CONFIG_PARAM_CMDID";
        }
        else
        {
          switch ( a1 )
          {
            case 258050:
              return "WMI_MOTION_DET_BASE_LINE_CONFIG_PARAM_CMDID";
            case 258051:
              return "WMI_MOTION_DET_START_STOP_CMDID";
            case 258052:
              return "WMI_MOTION_DET_BASE_LINE_START_STOP_CMDID";
          }
        }
        return "Invalid WMI cmd";
      }
      switch ( a1 )
      {
        case 274433:
          result = "WMI_AUDIO_AGGR_ENABLE_CMDID";
          break;
        case 274434:
          result = "WMI_AUDIO_AGGR_ADD_GROUP_CMDID";
          break;
        case 274435:
          result = "WMI_AUDIO_AGGR_DEL_GROUP_CMDID";
          break;
        case 274436:
          result = "WMI_AUDIO_AGGR_SET_GROUP_RATE_CMDID";
          break;
        case 274437:
          result = "WMI_AUDIO_AGGR_SET_GROUP_RETRY_CMDID";
          break;
        case 274438:
          result = "WMI_AUDIO_AGGR_SET_GROUP_AUTO_RATE_CMDID";
          break;
        case 274439:
          result = "WMI_AUDIO_AGGR_SET_GROUP_PROBE_CMDID";
          break;
        case 274440:
          result = "WMI_AUDIO_AGGR_UPDATE_STA_GROUP_INFO_CMDID";
          break;
        case 274441:
          result = "WMI_AUDIO_AGGR_GET_STATISTICS_CMDID";
          break;
        case 274442:
          result = "WMI_AUDIO_AGGR_RESET_STATISTICS_CMDID";
          break;
        case 274443:
          result = "WMI_AUDIO_AGGR_SET_RTSCTS_CONFIG_CMDID";
          break;
        case 274444:
          result = "WMI_AUDIO_AGGR_SET_SCHED_METHOD_CMDID";
          break;
        case 274445:
          result = "WMI_AUDIO_AGGR_GET_SCHED_METHOD_CMDID";
          break;
        default:
          if ( a1 == 262146 )
          {
            result = "WMI_PDEV_OBSS_PD_SPATIAL_REUSE_SET_DEF_OBSS_THRESH_CMDID";
          }
          else
          {
            if ( a1 != 270337 )
              return "Invalid WMI cmd";
            result = "WMI_HPCS_PULSE_START_CMDID";
          }
          break;
      }
    }
  }
  else
  {
    if ( a1 > 118784 )
    {
      if ( a1 <= 122880 )
      {
        switch ( a1 )
        {
          case 118785:
            result = "WMI_ECHO_CMDID";
            break;
          case 118786:
            result = "WMI_PDEV_UTF_CMDID";
            break;
          case 118787:
            result = "WMI_DBGLOG_CFG_CMDID";
            break;
          case 118788:
            result = "WMI_PDEV_QVIT_CMDID";
            break;
          case 118789:
            result = "WMI_PDEV_FTM_INTG_CMDID";
            break;
          case 118790:
            result = "WMI_VDEV_SET_KEEPALIVE_CMDID";
            break;
          case 118791:
            result = "WMI_VDEV_GET_KEEPALIVE_CMDID";
            break;
          case 118792:
            result = "WMI_FORCE_FW_HANG_CMDID";
            break;
          case 118793:
            result = "WMI_SET_MCASTBCAST_FILTER_CMDID";
            break;
          case 118794:
            result = "WMI_THERMAL_MGMT_CMDID";
            break;
          case 118795:
            result = "WMI_HOST_AUTO_SHUTDOWN_CFG_CMDID";
            break;
          case 118796:
            result = "WMI_TPC_CHAINMASK_CONFIG_CMDID";
            break;
          case 118797:
            result = "WMI_SET_ANTENNA_DIVERSITY_CMDID";
            break;
          case 118798:
            result = "WMI_OCB_SET_SCHED_CMDID";
            break;
          case 118799:
            result = "WMI_RSSI_BREACH_MONITOR_CONFIG_CMDID";
            break;
          case 118800:
            result = "WMI_LRO_CONFIG_CMDID";
            break;
          case 118801:
            result = "WMI_TRANSFER_DATA_TO_FLASH_CMDID";
            break;
          case 118802:
            result = "WMI_CONFIG_ENHANCED_MCAST_FILTER_CMDID";
            break;
          case 118803:
            result = "WMI_VDEV_WISA_CMDID";
            break;
          case 118804:
            result = "WMI_DBGLOG_TIME_STAMP_SYNC_CMDID";
            break;
          case 118805:
            result = "WMI_SET_MULTIPLE_MCAST_FILTER_CMDID";
            break;
          case 118806:
            result = "WMI_READ_DATA_FROM_FLASH_CMDID";
            break;
          case 118807:
            result = "WMI_THERM_THROT_SET_CONF_CMDID";
            break;
          case 118808:
            result = "WMI_RUNTIME_DPD_RECAL_CMDID";
            break;
          case 118809:
            result = "WMI_GET_TPC_POWER_CMDID";
            break;
          case 118810:
            result = "WMI_IDLE_TRIGGER_MONITOR_CMDID";
            break;
          case 118811:
            result = "WMI_SET_ELNA_BYPASS_CMDID";
            break;
          case 118812:
            result = "WMI_GET_ELNA_BYPASS_CMDID";
            break;
          case 118813:
            result = "WMI_GET_CHANNEL_ANI_CMDID";
            break;
          case 118814:
            result = "WMI_SET_OCL_CMDID";
            break;
          case 118815:
            result = "WMI_SET_MULTIPLE_PDEV_VDEV_PARAM_CMDID";
            break;
          case 118816:
            result = "WMI_PMM_SCRATCH_REG_ALLOCATION_CMDID";
            break;
          case 118817:
            result = "WMI_XGAP_ENABLE_CMDID";
            break;
          case 118818:
            result = "WMI_HPA_CMDID";
            break;
          case 118819:
            result = "WMI_VDEV_STANDALONE_SOUND_CMDID";
            break;
          case 118820:
            result = "WMI_AUDIO_TRANSPORT_SWITCH_RESP_STATUS_CMDID";
            break;
          case 118821:
            result = "WMI_PEER_ACTIVE_TRAFFIC_MAP_CMDID";
            break;
          case 118822:
            result = "WMI_REQUEST_OPM_STATS_CMDID";
            break;
          case 118823:
            result = "WMI_SET_AP_SUSPEND_RESUME_CMDID";
            break;
          case 118824:
            result = "WMI_USD_SERVICE_CMDID";
            break;
          case 118825:
            result = "WMI_GET_SCAN_CACHE_RESULT_CMDID";
            break;
          default:
            return "Invalid WMI cmd";
        }
        return result;
      }
      if ( a1 <= 143360 )
      {
        if ( a1 > 126981 )
        {
          if ( a1 > 135168 )
          {
            if ( a1 <= 135170 )
            {
              if ( a1 == 135169 )
                return "WMI_RESMGR_ADAPTIVE_OCS_ENABLE_DISABLE_CMDID";
              else
                return "WMI_RESMGR_SET_CHAN_TIME_QUOTA_CMDID";
            }
            switch ( a1 )
            {
              case 135171:
                return "WMI_RESMGR_SET_CHAN_LATENCY_CMDID";
              case 139265:
                return "WMI_STA_SMPS_FORCE_MODE_CMDID";
              case 139266:
                return "WMI_STA_SMPS_PARAM_CMDID";
            }
          }
          else if ( a1 <= 0x20000 )
          {
            if ( a1 == 126982 )
              return "WMI_SIMULATION_TEST_CMDID";
            if ( a1 == 126983 )
              return "WMI_WFA_CONFIG_CMDID";
          }
          else
          {
            switch ( a1 )
            {
              case 131073:
                return "WMI_TDLS_SET_STATE_CMDID";
              case 131074:
                return "WMI_TDLS_PEER_UPDATE_CMDID";
              case 131075:
                return "WMI_TDLS_SET_OFFCHAN_MODE_CMDID";
            }
          }
        }
        else
        {
          if ( a1 > 126976 )
          {
            if ( a1 <= 126978 )
            {
              if ( a1 == 126977 )
                return "WMI_FWTEST_VDEV_MCC_SET_TBTT_MODE_CMDID";
              else
                return "WMI_FWTEST_P2P_SET_NOA_PARAM_CMDID";
            }
            else if ( a1 == 126979 )
            {
              return "WMI_UNIT_TEST_CMDID";
            }
            else if ( a1 == 126980 )
            {
              return "WMI_FWTEST_CMDID";
            }
            else
            {
              return "WMI_QBOOST_CFG_CMDID";
            }
          }
          if ( a1 <= 122882 )
          {
            if ( a1 == 122881 )
              return "WMI_GPIO_CONFIG_CMDID";
            else
              return "WMI_GPIO_OUTPUT_CMDID";
          }
          switch ( a1 )
          {
            case 122883:
              return "WMI_TXBF_CMDID";
            case 122884:
              return "WMI_ANT_CONTROLLER_CMDID";
            case 122885:
              return "WMI_GPIO_STATE_REQ_CMDID";
          }
        }
      }
      else if ( a1 <= 147458 )
      {
        if ( a1 <= 143365 )
        {
          if ( a1 <= 143362 )
          {
            if ( a1 == 143361 )
              return "WMI_HB_SET_ENABLE_CMDID";
            else
              return "WMI_HB_SET_TCP_PARAMS_CMDID";
          }
          else if ( a1 == 143363 )
          {
            return "WMI_HB_SET_TCP_PKT_FILTER_CMDID";
          }
          else if ( a1 == 143364 )
          {
            return "WMI_HB_SET_UDP_PARAMS_CMDID";
          }
          else
          {
            return "WMI_HB_SET_UDP_PKT_FILTER_CMDID";
          }
        }
        if ( a1 <= 143367 )
        {
          if ( a1 == 143366 )
            return "WMI_HB_OIC_PING_OFFLOAD_PARAM_CMDID";
          else
            return "WMI_HB_OIC_PING_OFFLOAD_SET_ENABLE_CMDID";
        }
        switch ( a1 )
        {
          case 143368:
            return "WMI_HB_DHCP_LEASE_RENEW_OFFLOAD_CMDID";
          case 147457:
            return "WMI_RMC_SET_MODE_CMDID";
          case 147458:
            return "WMI_RMC_SET_ACTION_PERIOD_CMDID";
        }
      }
      else if ( a1 <= 155649 )
      {
        if ( a1 <= 151552 )
        {
          if ( a1 == 147459 )
            return "WMI_RMC_CONFIG_CMDID";
          if ( a1 == 147460 )
            return "WMI_RMC_SET_MANUAL_LEADER_CMDID";
        }
        else
        {
          switch ( a1 )
          {
            case 151553:
              return "WMI_MHF_OFFLOAD_SET_MODE_CMDID";
            case 151554:
              return "WMI_MHF_OFFLOAD_PLUMB_ROUTING_TBL_CMDID";
            case 155649:
              return "WMI_BATCH_SCAN_ENABLE_CMDID";
          }
        }
      }
      else
      {
        if ( a1 > 159745 )
        {
          if ( a1 == 159746 )
            return "WMI_OEM_REQUEST_CMDID";
          if ( a1 == 159747 )
            return "WMI_LPI_OEM_REQ_CMDID";
          return "WMI_OEM_DMA_RING_CFG_REQ_CMDID";
        }
        switch ( a1 )
        {
          case 155650:
            return "WMI_BATCH_SCAN_DISABLE_CMDID";
          case 155651:
            return "WMI_BATCH_SCAN_TRIGGER_RESULT_CMDID";
          case 159745:
            return "WMI_OEM_REQ_CMDID";
        }
      }
      return "Invalid WMI cmd";
    }
    if ( a1 <= 90112 )
    {
      if ( a1 > 81920 )
      {
        if ( a1 <= 81923 )
        {
          if ( a1 == 81921 )
            return "WMI_RTT_MEASREQ_CMDID";
          if ( a1 == 81922 )
            return "WMI_RTT_TSF_CMDID";
          return "WMI_RTT_PASN_AUTH_STATUS_CMD";
        }
        switch ( a1 )
        {
          case 81924:
            return "WMI_RTT_PASN_DEAUTH_CMD";
          case 86017:
            return "WMI_VDEV_SPECTRAL_SCAN_CONFIGURE_CMDID";
          case 86018:
            return "WMI_VDEV_SPECTRAL_SCAN_ENABLE_CMDID";
        }
        return "Invalid WMI cmd";
      }
      switch ( a1 )
      {
        case 77825:
          result = "WMI_WOW_ADD_WAKE_PATTERN_CMDID";
          break;
        case 77826:
          result = "WMI_WOW_DEL_WAKE_PATTERN_CMDID";
          break;
        case 77827:
          result = "WMI_WOW_ENABLE_DISABLE_WAKE_EVENT_CMDID";
          break;
        case 77828:
          result = "WMI_WOW_ENABLE_CMDID";
          break;
        case 77829:
          result = "WMI_WOW_HOSTWAKEUP_FROM_SLEEP_CMDID";
          break;
        case 77830:
          result = "WMI_WOW_IOAC_ADD_KEEPALIVE_CMDID";
          break;
        case 77831:
          result = "WMI_WOW_IOAC_DEL_KEEPALIVE_CMDID";
          break;
        case 77832:
          result = "WMI_WOW_IOAC_ADD_WAKE_PATTERN_CMDID";
          break;
        case 77833:
          result = "WMI_WOW_IOAC_DEL_WAKE_PATTERN_CMDID";
          break;
        case 77834:
          result = "WMI_D0_WOW_ENABLE_DISABLE_CMDID";
          break;
        case 77835:
          result = "WMI_EXTWOW_ENABLE_CMDID";
          break;
        case 77836:
          result = "WMI_EXTWOW_SET_APP_TYPE1_PARAMS_CMDID";
          break;
        case 77837:
          result = "WMI_EXTWOW_SET_APP_TYPE2_PARAMS_CMDID";
          break;
        case 77838:
          result = "WMI_WOW_ENABLE_ICMPV6_NA_FLT_CMDID";
          break;
        case 77839:
          result = "WMI_WOW_UDP_SVC_OFLD_CMDID";
          break;
        case 77840:
          result = "WMI_WOW_HOSTWAKEUP_GPIO_PIN_PATTERN_CONFIG_CMDID";
          break;
        case 77841:
          result = "WMI_WOW_SET_ACTION_WAKE_UP_CMDID";
          break;
        case 77842:
          result = "WMI_WOW_COAP_ADD_PATTERN_CMDID";
          break;
        case 77843:
          result = "WMI_WOW_COAP_DEL_PATTERN_CMDID";
          break;
        case 77844:
          result = "WMI_WOW_COAP_ADD_KEEPALIVE_PATTERN_CMDID";
          break;
        case 77845:
          result = "WMI_WOW_COAP_DEL_KEEPALIVE_PATTERN_CMDID";
          break;
        case 77846:
          result = "WMI_WOW_COAP_GET_BUF_INFO_CMDID";
          break;
        default:
          return "Invalid WMI cmd";
      }
    }
    else
    {
      if ( a1 > 94209 )
      {
        if ( a1 <= 110592 )
        {
          if ( a1 <= 98306 )
          {
            if ( a1 > 98304 )
            {
              if ( a1 == 98305 )
                return "WMI_NETWORK_LIST_OFFLOAD_CONFIG_CMDID";
              else
                return "WMI_APFIND_CMDID";
            }
            if ( a1 == 94210 )
              return "WMI_ADD_PROACTIVE_ARP_RSP_PATTERN_CMDID";
            if ( a1 == 94211 )
              return "WMI_DEL_PROACTIVE_ARP_RSP_PATTERN_CMDID";
          }
          else if ( a1 <= 102400 )
          {
            if ( a1 == 98307 )
              return "WMI_PASSPOINT_LIST_CONFIG_CMDID";
            if ( a1 == 98308 )
              return "WMI_NLO_CONFIGURE_MAWC_CMDID";
          }
          else
          {
            switch ( a1 )
            {
              case 102401:
                return "WMI_GTK_OFFLOAD_CMDID";
              case 106497:
                return "WMI_CSA_OFFLOAD_ENABLE_CMDID";
              case 106498:
                return "WMI_CSA_OFFLOAD_CHANSWITCH_CMDID";
            }
          }
        }
        else if ( a1 > 114689 )
        {
          if ( a1 <= 114691 )
          {
            if ( a1 == 114690 )
              return "WMI_PEER_TID_DELBA_CMDID";
            else
              return "WMI_STA_DTIM_PS_METHOD_CMDID";
          }
          switch ( a1 )
          {
            case 114692:
              return "WMI_STA_UAPSD_AUTO_TRIG_CMDID";
            case 114693:
              return "WMI_STA_KEEPALIVE_CMDID";
            case 114694:
              return "WMI_BA_REQ_SSN_CMDID";
          }
        }
        else
        {
          if ( a1 <= 110594 )
          {
            if ( a1 == 110593 )
              return "WMI_CHATTER_SET_MODE_CMDID";
            else
              return "WMI_CHATTER_ADD_COALESCING_FILTER_CMDID";
          }
          switch ( a1 )
          {
            case 110595:
              return "WMI_CHATTER_DELETE_COALESCING_FILTER_CMDID";
            case 110596:
              return "WMI_CHATTER_COALESCING_QUERY_CMDID";
            case 114689:
              return "WMI_PEER_TID_ADDBA_CMDID";
          }
        }
        return "Invalid WMI cmd";
      }
      switch ( a1 )
      {
        case 90113:
          result = "WMI_REQUEST_STATS_CMDID";
          break;
        case 90114:
          result = "WMI_MCC_SCHED_TRAFFIC_STATS_CMDID";
          break;
        case 90115:
          result = "WMI_REQUEST_STATS_EXT_CMDID";
          break;
        case 90116:
          result = "WMI_REQUEST_LINK_STATS_CMDID";
          break;
        case 90117:
          result = "WMI_START_LINK_STATS_CMDID";
          break;
        case 90118:
          result = "WMI_CLEAR_LINK_STATS_CMDID";
          break;
        case 90119:
          result = "WMI_GET_FW_MEM_DUMP_CMDID";
          break;
        case 90120:
          result = "WMI_DEBUG_MESG_FLUSH_CMDID";
          break;
        case 90121:
          result = "WMI_DIAG_EVENT_LOG_CONFIG_CMDID";
          break;
        case 90122:
          result = "WMI_REQUEST_WLAN_STATS_CMDID";
          break;
        case 90123:
          result = "WMI_REQUEST_RCPI_CMDID";
          break;
        case 90124:
          result = "WMI_REQUEST_PEER_STATS_INFO_CMDID";
          break;
        case 90125:
          result = "WMI_REQUEST_RADIO_CHAN_STATS_CMDID";
          break;
        case 90126:
          result = "WMI_REQUEST_WLM_STATS_CMDID";
          break;
        case 90127:
          result = "WMI_REQUEST_CTRL_PATH_STATS_CMDID";
          break;
        case 90128:
          result = "WMI_REQUEST_UNIFIED_LL_GET_STA_CMDID";
          break;
        case 90129:
          result = "WMI_REQUEST_THERMAL_STATS_CMDID";
          break;
        case 90130:
          result = "WMI_REQUEST_HALPHY_CTRL_PATH_STATS_CMDID";
          break;
        default:
          if ( a1 != 94209 )
            return "Invalid WMI cmd";
          result = "WMI_SET_ARP_NS_OFFLOAD_CMDID";
          break;
      }
    }
  }
  return result;
}
