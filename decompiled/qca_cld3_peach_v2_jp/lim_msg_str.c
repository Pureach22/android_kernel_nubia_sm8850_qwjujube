const char *__fastcall lim_msg_str(int a1)
{
  int v1; // w8
  const char *result; // x0

  v1 = a1 - 5044;
  result = "eWNI_SME_SYS_READY_IND";
  switch ( v1 )
  {
    case 0:
      result = "SIR_BB_XPORT_MGMT_MSG";
      break;
    case 30:
      result = "SIR_LIM_JOIN_FAIL_TIMEOUT";
      break;
    case 31:
      result = "SIR_LIM_AUTH_FAIL_TIMEOUT";
      break;
    case 32:
      result = "SIR_LIM_AUTH_RSP_TIMEOUT";
      break;
    case 33:
      result = "SIR_LIM_ASSOC_FAIL_TIMEOUT";
      break;
    case 34:
      result = "SIR_LIM_REASSOC_FAIL_TIMEOUT";
      break;
    case 35:
      result = "SIR_LIM_HEART_BEAT_TIMEOUT";
      break;
    case 40:
      result = "SIR_LIM_ADDTS_RSP_TIMEOUT";
      break;
    case 47:
      result = "SIR_LIM_LINK_TEST_DURATION_TIMEOUT";
      break;
    case 51:
      result = "SIR_LIM_CNF_WAIT_TIMEOUT";
      break;
    case 53:
      result = "SIR_LIM_UPDATE_OLBC_CACHEL_TIMEOUT";
      break;
    case 58:
      result = "SIR_LIM_FT_PREAUTH_RSP_TIMEOUT";
      break;
    case 75:
      result = "SIR_LIM_PROCESS_DEFERRED_QUEUE";
      break;
    case 77:
      return result;
    case 81:
      result = "eWNI_SME_SETCONTEXT_RSP";
      break;
    case 84:
      result = "eWNI_SME_DISASSOC_REQ";
      break;
    case 85:
      result = "eWNI_SME_DISASSOC_RSP";
      break;
    case 86:
      result = "eWNI_SME_DISASSOC_IND";
      break;
    case 87:
      result = "eWNI_SME_DISASSOC_CNF";
      break;
    case 88:
      result = "eWNI_SME_DEAUTH_REQ";
      break;
    case 89:
      result = "eWNI_SME_DEAUTH_RSP";
      break;
    case 90:
      result = "eWNI_SME_DEAUTH_IND";
      break;
    case 95:
      result = "eWNI_SME_START_BSS_REQ";
      break;
    case 96:
      result = "eWNI_SME_START_BSS_RSP";
      break;
    case 97:
      result = "eWNI_SME_ASSOC_IND";
      break;
    case 98:
      result = "eWNI_SME_ASSOC_CNF";
      break;
    case 99:
      result = "eWNI_SME_SWITCH_CHL_IND";
      break;
    case 100:
      result = "eWNI_SME_STOP_BSS_REQ";
      break;
    case 101:
      result = "eWNI_SME_STOP_BSS_RSP";
      break;
    case 102:
      result = "eWNI_SME_DEAUTH_CNF";
      break;
    case 104:
      result = "eWNI_SME_ADDTS_REQ";
      break;
    case 105:
      result = "eWNI_SME_ADDTS_RSP";
      break;
    case 106:
      result = "eWNI_SME_DELTS_REQ";
      break;
    case 107:
      result = "eWNI_SME_DELTS_RSP";
      break;
    case 108:
      result = "eWNI_SME_DELTS_IND";
      break;
    case 109:
      result = "eWNI_SME_MSCS_REQ";
      break;
    case 112:
      result = "eWNI_SME_ASSOC_IND_UPPER_LAYER";
      break;
    case 156:
      result = "eWNI_SME_GET_TSM_STATS_REQ";
      break;
    case 157:
      result = "eWNI_SME_GET_TSM_STATS_RSP";
      break;
    case 181:
      result = "eWNI_SME_SET_HW_MODE_REQ";
      break;
    case 182:
      result = "eWNI_SME_SET_HW_MODE_RESP";
      break;
    case 183:
      result = "eWNI_SME_HW_MODE_TRANS_IND";
      break;
    default:
      result = "Unknown";
      break;
  }
  return result;
}
