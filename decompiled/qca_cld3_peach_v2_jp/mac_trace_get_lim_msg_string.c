const char *__fastcall mac_trace_get_lim_msg_string(unsigned __int16 a1)
{
  int v1; // w9
  const char *result; // x0

  v1 = a1;
  switch ( a1 )
  {
    case 0x3E8u:
      result = "LIM_MLM_SCAN_REQ";
      break;
    case 0x3E9u:
      result = "LIM_MLM_SCAN_CNF";
      break;
    case 0x3EAu:
    case 0x3FEu:
    case 0x3FFu:
    case 0x401u:
    case 0x402u:
    case 0x403u:
    case 0x404u:
    case 0x405u:
LABEL_28:
      result = "UNKNOWN";
      break;
    case 0x3EBu:
      result = "LIM_MLM_START_CNF";
      break;
    case 0x3ECu:
      result = "LIM_MLM_JOIN_REQ";
      break;
    case 0x3EDu:
      result = "LIM_MLM_JOIN_CNF";
      break;
    case 0x3EEu:
      result = "LIM_MLM_AUTH_REQ";
      break;
    case 0x3EFu:
      result = "LIM_MLM_AUTH_CNF";
      break;
    case 0x3F0u:
      result = "LIM_MLM_AUTH_IND";
      break;
    case 0x3F1u:
      result = "LIM_MLM_ASSOC_REQ";
      break;
    case 0x3F2u:
      result = "LIM_MLM_ASSOC_CNF";
      break;
    case 0x3F3u:
      result = "LIM_MLM_ASSOC_IND";
      break;
    case 0x3F4u:
      result = "LIM_MLM_DISASSOC_REQ";
      break;
    case 0x3F5u:
      result = "LIM_MLM_DISASSOC_CNF";
      break;
    case 0x3F6u:
      result = "LIM_MLM_DISASSOC_IND";
      break;
    case 0x3F7u:
      result = "LIM_MLM_REASSOC_CNF";
      break;
    case 0x3F8u:
      result = "LIM_MLM_REASSOC_IND";
      break;
    case 0x3F9u:
      result = "LIM_MLM_DEAUTH_REQ";
      break;
    case 0x3FAu:
      result = "LIM_MLM_DEAUTH_CNF";
      break;
    case 0x3FBu:
      result = "LIM_MLM_DEAUTH_IND";
      break;
    case 0x3FCu:
      result = "LIM_MLM_TSPEC_REQ";
      break;
    case 0x3FDu:
      result = "LIM_MLM_TSPEC_CNF";
      break;
    case 0x400u:
      result = "LIM_MLM_SETKEYS_CNF";
      break;
    case 0x406u:
      result = "LIM_MLM_LINK_TEST_STOP_REQ";
      break;
    case 0x407u:
      result = "LIM_MLM_PURGE_STA_IND";
      break;
    default:
      result = "SIR_BB_XPORT_MGMT_MSG";
      switch ( v1 )
      {
        case 5044:
          return result;
        case 5057:
          result = "SIR_LIM_DELETE_STA_CONTEXT_IND";
          break;
        case 5059:
          result = "SIR_LIM_UPDATE_BEACON";
          break;
        case 5074:
          result = "SIR_LIM_JOIN_FAIL_TIMEOUT";
          break;
        case 5075:
          result = "SIR_LIM_AUTH_FAIL_TIMEOUT";
          break;
        case 5076:
          result = "SIR_LIM_AUTH_RSP_TIMEOUT";
          break;
        case 5077:
          result = "SIR_LIM_ASSOC_FAIL_TIMEOUT";
          break;
        case 5078:
          result = "SIR_LIM_REASSOC_FAIL_TIMEOUT";
          break;
        case 5079:
          result = "SIR_LIM_HEART_BEAT_TIMEOUT";
          break;
        case 5084:
          result = "SIR_LIM_ADDTS_RSP_TIMEOUT";
          break;
        case 5091:
          result = "SIR_LIM_LINK_TEST_DURATION_TIMEOUT";
          break;
        case 5095:
          result = "SIR_LIM_CNF_WAIT_TIMEOUT";
          break;
        case 5097:
          result = "SIR_LIM_UPDATE_OLBC_CACHEL_TIMEOUT";
          break;
        case 5102:
          result = "SIR_LIM_FT_PREAUTH_RSP_TIMEOUT";
          break;
        case 5108:
          result = "SIR_LIM_RRM_STA_STATS_RSP_TIMEOUT";
          break;
        case 5110:
          result = "SIR_LIM_DISASSOC_ACK_TIMEOUT";
          break;
        case 5112:
          result = "SIR_LIM_PERIODIC_JOIN_PROBE_REQ_TIMEOUT";
          break;
        case 5117:
          result = "SIR_LIM_AUTH_RETRY_TIMEOUT";
          break;
        case 5118:
          result = "SIR_LIM_AUTH_SAE_TIMEOUT";
          break;
        case 5119:
          result = "SIR_LIM_MSG_TYPES_END";
          break;
        default:
          goto LABEL_28;
      }
      break;
  }
  return result;
}
