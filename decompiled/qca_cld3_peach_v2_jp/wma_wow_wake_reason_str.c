const char *__fastcall wma_wow_wake_reason_str(int a1)
{
  int v1; // w8
  const char *result; // x0

  v1 = a1 + 1;
  result = "UNSPECIFIED";
  switch ( v1 )
  {
    case 0:
      return result;
    case 1:
      result = "NLOD";
      break;
    case 2:
      result = "AP_ASSOC_LOST";
      break;
    case 3:
      result = "LOW_RSSI";
      break;
    case 4:
      result = "DEAUTH_RECVD";
      break;
    case 5:
      result = "DISASSOC_RECVD";
      break;
    case 6:
      result = "GTK_HS_ERR";
      break;
    case 7:
      result = "EAP_REQ";
      break;
    case 8:
      result = "FOURWAY_HS_RECV";
      break;
    case 9:
      result = "TIMER_INTR_RECV";
      break;
    case 10:
      result = "PATTERN_MATCH_FOUND";
      break;
    case 11:
      result = "RECV_MAGIC_PATTERN";
      break;
    case 12:
      result = "P2P_DISC";
      break;
    case 13:
      result = "WLAN_HB";
      break;
    case 14:
      result = "CSA_EVENT";
      break;
    case 15:
      result = "PROBE_REQ_WPS_IE_RECV";
      break;
    case 16:
      result = "AUTH_REQ_RECV";
      break;
    case 17:
      result = "ASSOC_REQ_RECV";
      break;
    case 18:
      result = "HTT_EVENT";
      break;
    case 19:
      result = "RA_MATCH";
      break;
    case 20:
      result = "HOST_AUTO_SHUTDOWN";
      break;
    case 21:
      result = "IOAC_MAGIC_EVENT";
      break;
    case 22:
      result = "IOAC_SHORT_EVENT";
      break;
    case 23:
      result = "IOAC_EXTEND_EVENT";
      break;
    case 24:
      result = "IOAC_TIMER_EVENT";
      break;
    case 25:
      result = "ROAM_HO";
      break;
    case 26:
      result = "DFS_PHYERR_RADADR_EVENT";
      break;
    case 27:
      result = "BEACON_RECV";
      break;
    case 28:
      result = "CLIENT_KICKOUT_EVENT";
      break;
    case 29:
      result = "NAN_EVENT";
      break;
    case 30:
      result = "EXTSCAN";
      break;
    case 31:
      result = "RSSI_BREACH_EVENT";
      break;
    case 32:
      result = "IOAC_REV_KA_FAIL_EVENT";
      break;
    case 33:
      result = "IOAC_SOCK_EVENT";
      break;
    case 34:
      result = "NLO_SCAN_COMPLETE";
      break;
    case 35:
      result = "PACKET_FILTER_MATCH";
      break;
    case 36:
      result = "ASSOC_RES_RECV";
      break;
    case 37:
      result = "REASSOC_REQ_RECV";
      break;
    case 38:
      result = "REASSOC_RES_RECV";
      break;
    case 39:
      result = "ACTION_FRAME_RECV";
      break;
    case 40:
      result = "BPF_ALLOW";
      break;
    case 41:
      result = "NAN_DATA";
      break;
    case 42:
      result = "OEM_RESPONSE_EVENT";
      break;
    case 43:
      result = "TDLS_CONN_TRACKER_EVENT";
      break;
    case 44:
      result = "CRITICAL_LOG";
      break;
    case 45:
      result = "P2P_LISTEN_OFFLOAD";
      break;
    case 46:
      result = "NAN_EVENT_WAKE_HOST";
      break;
    case 47:
      result = "CHIP_POWER_FAILURE_DETECT";
      break;
    case 48:
      result = "11D_SCAN";
      break;
    case 52:
      result = "SAP_OBSS_DETECTION";
      break;
    case 53:
      result = "BSS_COLOR_COLLISION_DETECT";
      break;
    case 59:
      result = "PF";
      break;
    case 60:
      result = "ROAM_PREAUTH_START_EVENT";
      break;
    case 61:
      result = "ROAM_PMKID_REQUEST";
      break;
    case 64:
      result = "VDEV_DISCONNECT";
      break;
    case 65:
      result = "LOCAL_DATA_UC_DROP";
      break;
    case 66:
      result = "GENERIC_WAKE";
      break;
    case 68:
      result = "TWT Event";
      break;
    case 69:
      result = "FATAL_EVENT_WAKE";
      break;
    case 70:
      result = "DCS_INT_DET";
      break;
    case 71:
      result = "ROAM_STATS";
      break;
    case 73:
      result = "WOW_REASON_RTT_11AZ";
      break;
    case 75:
      result = "DELAYED_WAKEUP_TIMER_ELAPSED";
      break;
    case 76:
      result = "DELAYED_WAKEUP_DATA_STORE_LIST_FULL";
      break;
    case 80:
      result = "VDEV_REPURPOSE";
      break;
    case 84:
      result = "PF_BLOCKING_LAST_TIME";
      break;
    case 256:
      result = "DEBUG_TEST";
      break;
    default:
      result = "unknown";
      break;
  }
  return result;
}
