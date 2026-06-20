const char *__fastcall cam_cpas_axi_util_path_type_to_string(int a1)
{
  const char *result; // x0

  result = "IFE_LINEAR";
  switch ( a1 )
  {
    case 0:
      return result;
    case 1:
      result = "IFE_VID";
      break;
    case 2:
      result = "IFE_DISP";
      break;
    case 3:
      result = "IFE_STATS";
      break;
    case 4:
      result = "IFE_RDI0";
      break;
    case 5:
      result = "IFE_RDI1";
      break;
    case 6:
      result = "IFE_RDI2";
      break;
    case 7:
      result = "IFE_RDI3";
      break;
    case 8:
      result = "IFE_PDAF";
      break;
    case 9:
      result = "IFE_PIXEL_RAW";
      break;
    case 10:
      result = "IFE_FULL";
      break;
    case 11:
      result = "IFE_DS2";
      break;
    case 12:
      result = "IFE_DS4";
      break;
    case 13:
      result = "IFE_DS16";
      break;
    case 14:
      result = "IFE_RDI4";
      break;
    case 15:
      result = "IFE_PDAF_1";
      break;
    case 16:
      result = "IFE_PDAF_2";
      break;
    case 17:
      result = "IFE_PDAF_3";
      break;
    case 18:
      result = "IFE_IR";
      break;
    case 19:
      result = "IFE_FD";
      break;
    case 32:
      result = "IPE_RD_IN";
      break;
    case 33:
      result = "IPE_RD_REF";
      break;
    case 34:
      result = "IPE_WR_VID";
      break;
    case 35:
      result = "IPE_WR_DISP";
      break;
    case 36:
      result = "IPE_WR_REF";
      break;
    case 37:
      result = "IPE_WR_APP";
      break;
    case 64:
      result = "OPE_RD_IN";
      break;
    case 65:
      result = "OPE_RD_REF";
      break;
    case 66:
      result = "OPE_WR_VID";
      break;
    case 67:
      result = "OPE_WR_DISP";
      break;
    case 68:
      result = "OPE_WR_REF";
      break;
    case 96:
      result = "SFE_NRDI";
      break;
    case 97:
      result = "SFE_RDI0";
      break;
    case 98:
      result = "SFE_RDI1";
      break;
    case 99:
      result = "SFE_RDI2";
      break;
    case 100:
      result = "SFE_RDI3";
      break;
    case 101:
      result = "SFE_RDI4";
      break;
    case 102:
      result = "SFE_STATS";
      break;
    case 128:
      result = "CRE_RD_IN";
      break;
    case 129:
      result = "CRE_WR_OUT";
      break;
    case 160:
      result = "OFE_RD_EXT";
      break;
    case 161:
      result = "OFE_RD_INT_PDI";
      break;
    case 162:
      result = "OFE_RD_INT_HDR";
      break;
    case 163:
      result = "OFE_WR_VID";
      break;
    case 164:
      result = "OFE_WR_DISP";
      break;
    case 165:
      result = "OFE_WR_IR";
      break;
    case 166:
      result = "OFE_WR_HDR_LTM";
      break;
    case 167:
      result = "OFE_WR_DC4";
      break;
    case 168:
      result = "OFE_WR_AI";
      break;
    case 169:
      result = "OFE_WR_PDI";
      break;
    case 170:
      result = "OFE_WR_IDEALRAW";
      break;
    case 171:
      result = "OFE_WR_STATS";
      break;
    case 256:
      result = "DATA_ALL";
      break;
    default:
      result = "CPAS_PATH_INVALID";
      break;
  }
  return result;
}
