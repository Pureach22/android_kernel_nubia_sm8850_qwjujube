const char *__fastcall lim_result_code_str(int a1)
{
  const char *result; // x0

  switch ( a1 )
  {
    case 500:
      result = "eSIR_SME_INVALID_PARAMETERS";
      break;
    case 501:
      result = "eSIR_SME_UNEXPECTED_REQ_RESULT_CODE";
      break;
    case 502:
      result = "eSIR_SME_RESOURCES_UNAVAILABLE";
      break;
    case 503:
      result = "eSIR_SME_SCAN_FAILED";
      break;
    case 504:
      result = "eSIR_SME_BSS_ALREADY_STARTED_OR_JOINED";
      break;
    case 505:
      result = "eSIR_SME_LOST_LINK_WITH_PEER_RESULT_CODE";
      break;
    case 506:
      result = "eSIR_SME_REFUSED";
      break;
    case 507:
    case 515:
    case 518:
    case 526:
    case 528:
      goto LABEL_6;
    case 508:
      result = "eSIR_SME_JOIN_TIMEOUT_RESULT_CODE";
      break;
    case 509:
      result = "eSIR_SME_AUTH_TIMEOUT_RESULT_CODE";
      break;
    case 510:
      result = "eSIR_SME_ASSOC_TIMEOUT_RESULT_CODE";
      break;
    case 511:
      result = "eSIR_SME_REASSOC_TIMEOUT_RESULT_CODE";
      break;
    case 512:
      result = "eSIR_SME_MAX_NUM_OF_PRE_AUTH_REACHED";
      break;
    case 513:
      result = "eSIR_SME_AUTH_REFUSED";
      break;
    case 514:
      result = "eSIR_SME_INVALID_WEP_DEFAULT_KEY";
      break;
    case 516:
      result = "eSIR_SME_ASSOC_REFUSED";
      break;
    case 517:
      result = "eSIR_SME_REASSOC_REFUSED";
      break;
    case 519:
      result = "eSIR_SME_STA_NOT_AUTHENTICATED";
      break;
    case 520:
      result = "eSIR_SME_STA_NOT_ASSOCIATED";
      break;
    case 521:
      result = "eSIR_SME_ALREADY_JOINED_A_BSS";
      break;
    case 522:
      result = "eSIR_SME_MORE_SCAN_RESULTS_FOLLOW";
      break;
    case 523:
      result = "eSIR_SME_INVALID_ASSOC_RSP_RXED";
      break;
    case 524:
      result = "eSIR_SME_MIC_COUNTER_MEASURES";
      break;
    case 525:
      result = "eSIR_SME_ADDTS_RSP_TIMEOUT";
      break;
    case 527:
      result = "eSIR_SME_CHANNEL_SWITCH_FAIL";
      break;
    case 529:
      result = "eSIR_SME_HAL_SCAN_INIT_FAILED";
      break;
    case 530:
      result = "eSIR_SME_HAL_SCAN_END_FAILED";
      break;
    case 531:
      result = "eSIR_SME_HAL_SCAN_FINISH_FAILED";
      break;
    case 532:
      result = "eSIR_SME_HAL_SEND_MESSAGE_FAIL";
      break;
    default:
      if ( a1 )
      {
        if ( a1 == 1 )
          result = "eSIR_LOGE_EXCEPTION";
        else
LABEL_6:
          result = "Unknown resultCode";
      }
      else
      {
        result = "eSIR_SME_SUCCESS";
      }
      break;
  }
  return result;
}
