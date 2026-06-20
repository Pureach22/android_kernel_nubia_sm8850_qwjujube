const char *__fastcall get_ipc_virt_client_name(int a1)
{
  int v1; // w8
  const char *result; // x0

  v1 = a1 - 8;
  result = "APPS_VID";
  switch ( v1 )
  {
    case 0:
      return result;
    case 1:
      result = "GPU_VID";
      break;
    case 3:
      result = "IPE_VID";
      break;
    case 4:
      result = "VPU_VID";
      break;
    case 17:
      result = "DPU_VID";
      break;
    case 25:
      result = "APPS_NS1_VID";
      break;
    case 26:
      result = "APPS_NS2_VID";
      break;
    case 27:
      result = "APPS_NS3_VID";
      break;
    case 28:
      result = "APPS_NS4_VID";
      break;
    case 49:
      result = "DCP_VID";
      break;
    case 55:
      result = "LSR_VID";
      break;
    case 120:
      result = "IFE0_VID";
      break;
    case 121:
      result = "IFE1_VID";
      break;
    case 122:
      result = "IFE2_VID";
      break;
    case 123:
      result = "IFE3_VID";
      break;
    case 124:
      result = "IFE4_VID";
      break;
    case 125:
      result = "IFE5_VID";
      break;
    case 126:
      result = "IFE6_VID";
      break;
    case 127:
      result = "IFE7_VID";
      break;
    case 128:
      result = "IFE8_VID";
      break;
    case 129:
      result = "IFE9_VID";
      break;
    case 130:
      result = "IFE10_VID";
      break;
    case 131:
      result = "IFE11_VID";
      break;
    default:
      result = "UNKNOWN_VID";
      break;
  }
  return result;
}
