__int64 __fastcall csr_translate_to_wni_cfg_dot11_mode(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        unsigned int a10)
{
  __int64 result; // x0
  bool v11; // zf
  unsigned int v12; // w9

  result = 2;
  switch ( a10 )
  {
    case 0u:
      return 1;
    case 1u:
      return result;
    case 2u:
      return 3;
    case 3u:
      return 4;
    case 4u:
      return 5;
    case 5u:
      goto LABEL_15;
    case 6u:
    case 7u:
      return a10;
    case 8u:
      v11 = (wma_get_fw_wlan_feat_caps(2) & 1) == 0;
      v12 = 9;
      goto LABEL_17;
    case 9u:
    case 0xCu:
      if ( (wma_get_fw_wlan_feat_caps(14) & 1) == 0 )
        goto LABEL_5;
      return 12;
    case 0xAu:
LABEL_5:
      if ( (wma_get_fw_wlan_feat_caps(13) & 1) == 0 )
        goto LABEL_15;
      result = 10;
      break;
    case 0xBu:
      goto LABEL_13;
    case 0xDu:
      if ( (wma_get_fw_wlan_feat_caps(14) & 1) != 0 )
      {
        result = 13;
      }
      else
      {
LABEL_13:
        if ( (wma_get_fw_wlan_feat_caps(13) & 1) != 0 )
        {
          result = 11;
        }
        else
        {
LABEL_15:
          v11 = (wma_get_fw_wlan_feat_caps(2) & 1) == 0;
          v12 = 8;
LABEL_17:
          if ( v11 )
            result = 5;
          else
            result = v12;
        }
      }
      break;
    default:
      qdf_trace_msg(
        0x34u,
        3u,
        "%s: doesn't expect %d as csrDo11Mode",
        a1,
        a2,
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        "csr_translate_to_wni_cfg_dot11_mode");
      result = 0;
      break;
  }
  return result;
}
