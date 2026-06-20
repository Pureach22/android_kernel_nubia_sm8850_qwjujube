const char *__fastcall hdd_auth_type_str(int a1)
{
  const char *result; // x0

  result = "OPEN SYSTEM";
  switch ( a1 )
  {
    case 0:
      result = "NONE";
      break;
    case 1:
      return result;
    case 2:
      result = "SHARED KEY";
      break;
    case 3:
      result = "SAE";
      break;
    case 4:
      result = "AUTO SWITCH";
      break;
    case 5:
      result = "WPA";
      break;
    case 6:
      result = "WPA PSK";
      break;
    case 7:
      result = "WPA NONE";
      break;
    case 8:
      result = "RSN";
      break;
    case 9:
      result = "RSN PSK";
      break;
    case 10:
      result = "FT RSN";
      break;
    case 11:
      result = "FT RSN PSK";
      break;
    case 12:
      result = "WAPI WAI CERTIFICATE";
      break;
    case 13:
      result = "WAPI WAI PSK";
      break;
    case 14:
      result = "CCKM WPA";
      break;
    case 15:
      result = "CCKM RSN";
      break;
    case 16:
      result = "RSN PSK SHA256";
      break;
    case 17:
      result = "RSN 8021X SHA256";
      break;
    case 18:
      result = "FILS SHA256";
      break;
    case 19:
      result = "FILS SHA384";
      break;
    case 20:
      result = "FT FILS SHA256";
      break;
    case 21:
      result = "FT FILS SHA384";
      break;
    case 22:
      result = "DPP RSN";
      break;
    case 23:
      result = "OWE";
      break;
    case 24:
      result = "SUITEB EAP SHA256";
      break;
    case 25:
      result = "SUITEB EAP SHA384";
      break;
    case 26:
      result = "OSEN";
      break;
    case 27:
      result = "FT SAE";
      break;
    case 28:
      result = "FT Suite B SHA384";
      break;
    case 29:
      result = "SAE EXT";
      break;
    case 30:
      result = "FT SAE EXT";
      break;
    case 31:
      result = "NUM OF SUPPORT AUTH TYPE";
      break;
    case 255:
      result = "FAILED";
      break;
    default:
      result = "UNKNOWN";
      break;
  }
  return result;
}
