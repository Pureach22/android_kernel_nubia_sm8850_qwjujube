const char *__fastcall _cam_isp_ife_sfe_resource_handle_id_to_type(int a1)
{
  int v1; // w8
  const char *result; // x0

  if ( a1 > 20481 )
  {
    switch ( a1 )
    {
      case 24576:
        result = "SFE_RDI_0";
        break;
      case 24577:
        result = "SFE_RDI_1";
        break;
      case 24578:
        result = "SFE_RDI_2";
        break;
      case 24579:
        result = "SFE_RDI_3";
        break;
      case 24580:
        result = "SFE_RDI_4";
        break;
      case 24581:
        result = "SFE_BE_STATS_0";
        break;
      case 24582:
        result = "SFE_BHIST_STATS_0";
        break;
      case 24583:
        result = "SFE_BE_STATS_1";
        break;
      case 24584:
        result = "SFE_BHIST_STATS_1";
        break;
      case 24585:
        result = "SFE_BE_STATS_2";
        break;
      case 24586:
        result = "SFE_BHIST_STATS_2";
        break;
      case 24587:
        result = "SFE_LCR";
        break;
      case 24588:
        result = "SFE_PROCESSED_RAW";
        break;
      case 24589:
        result = "SFE_IR";
        break;
      case 24590:
        result = "SFE_RS_STATS_0";
        break;
      case 24591:
        result = "SFE_RS_STATS_1";
        break;
      case 24592:
        result = "SFE_RS_STATS_2";
        break;
      case 24593:
        result = "HDR_STATS";
        break;
      default:
        if ( a1 == 20482 )
        {
          result = "SFE_RD_1";
        }
        else if ( a1 == 20483 )
        {
          result = "SFE_RD_2";
        }
        else
        {
LABEL_11:
          result = "Invalid_Resource_Type";
        }
        break;
    }
  }
  else
  {
    v1 = a1 - 12288;
    result = "IFE_FULL";
    switch ( v1 )
    {
      case 0:
        return result;
      case 1:
        result = "IFE_DS4";
        break;
      case 2:
        result = "IFE_DS16";
        break;
      case 3:
        result = "IFE_RAW_DUMP";
        break;
      case 4:
        result = "IFE_FD";
        break;
      case 5:
        result = "IFE_PDAF";
        break;
      case 6:
        result = "IFE_RDI_0";
        break;
      case 7:
        result = "IFE_RDI_1";
        break;
      case 8:
        result = "IFE_RDI_2";
        break;
      case 9:
        result = "IFE_RDI_3";
        break;
      case 10:
        result = "IFE_STATS_HDR_BE";
        break;
      case 11:
        result = "IFE_STATS_HDR_BHIST";
        break;
      case 12:
        result = "IFE_STATS_TL_BG";
        break;
      case 13:
        result = "IFE_STATS_BF";
        break;
      case 14:
        result = "IFE_STATS_AWB_BG";
        break;
      case 15:
        result = "IFE_STATS_BHIST";
        break;
      case 16:
        result = "IFE_STATS_RS";
        break;
      case 17:
        result = "IFE_STATS_CS";
        break;
      case 18:
        result = "IFE_STATS_IHIST";
        break;
      case 19:
        result = "IFE_FULL_DISP";
        break;
      case 20:
        result = "IFE_DS4_DISP";
        break;
      case 21:
        result = "IFE_DS16_DISP";
        break;
      case 22:
        result = "IFE_2PD";
        break;
      case 23:
        goto LABEL_11;
      case 24:
        result = "IFE_LCR";
        break;
      case 25:
        result = "IFE_SPARSE_PD";
        break;
      case 26:
        result = "IFE_PREPROCESS_2PD";
        break;
      case 27:
        result = "IFE_AWB_BFW";
        break;
      case 28:
        result = "IFE_STATS_AEC_BE";
        break;
      case 29:
        result = "IFE_LTM_STATS";
        break;
      case 30:
        result = "IFE_STATS_GTM_BHIST";
        break;
      case 31:
        result = "IFE_STATS_BG";
        break;
      case 32:
        result = "IFE_PREPROCESS_RAW";
        break;
      case 33:
        result = "IFE_STATS_CAF";
        break;
      case 34:
        result = "IFE_STATS_BAYER_RS";
        break;
      case 35:
        result = "IFE_PDAF_PARSED_DATA";
        break;
      case 36:
        result = "IFE_STATS_ALSC";
        break;
      case 37:
        result = "IFE_DS2";
        break;
      case 38:
        result = "IFE_IR";
        break;
      case 39:
        result = "IFE_RDI_4";
        break;
      case 40:
        result = "IFE_STATS_TMC_BHIST";
        break;
      case 41:
        result = "IFE_STATS_AF_BHIST";
        break;
      case 42:
        result = "IFE_STATS_AEC_BHIST";
        break;
      default:
        if ( a1 != 20481 )
          goto LABEL_11;
        result = "SFE_RD_0";
        break;
    }
  }
  return result;
}
