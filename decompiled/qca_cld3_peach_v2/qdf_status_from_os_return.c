__int64 __fastcall qdf_status_from_os_return(__int64 result)
{
  switch ( (int)result )
  {
    case -125:
      result = 9;
      break;
    case -124:
    case -123:
    case -122:
    case -121:
    case -120:
    case -119:
    case -118:
    case -117:
    case -116:
    case -113:
    case -112:
    case -111:
    case -109:
    case -108:
    case -107:
    case -106:
    case -105:
    case -104:
    case -101:
    case -98:
    case -97:
    case -96:
    case -94:
    case -93:
    case -92:
    case -91:
    case -90:
    case -89:
    case -88:
    case -87:
    case -86:
    case -85:
    case -84:
    case -83:
    case -82:
    case -81:
    case -80:
    case -79:
    case -78:
    case -77:
    case -76:
    case -75:
    case -73:
    case -72:
    case -71:
    case -70:
    case -69:
    case -68:
    case -67:
    case -66:
    case -65:
    case -64:
    case -63:
    case -62:
    case -61:
    case -60:
    case -59:
    case -58:
    case -57:
    case -56:
    case -55:
    case -54:
    case -53:
    case -52:
    case -51:
    case -50:
    case -49:
    case -48:
    case -47:
    case -46:
    case -45:
    case -44:
    case -43:
    case -42:
    case -41:
    case -40:
    case -39:
    case -38:
    case -37:
    case -36:
    case -35:
    case -34:
    case -33:
    case -32:
    case -31:
    case -30:
    case -29:
    case -27:
    case -26:
    case -25:
    case -24:
    case -23:
    case -21:
    case -20:
    case -19:
    case -18:
    case -15:
    case -13:
    case -10:
    case -9:
    case -8:
    case -4:
    case -3:
    case -1:
      goto LABEL_5;
    case -115:
      result = 24;
      break;
    case -114:
      result = 6;
      break;
    case -110:
      result = 15;
      break;
    case -103:
      result = 10;
      break;
    case -102:
      result = 25;
      break;
    case -100:
      result = 22;
      break;
    case -99:
      result = 20;
      break;
    case -95:
      result = 11;
      break;
    case -74:
      result = 7;
      break;
    case -28:
      result = 19;
      break;
    case -22:
      result = 4;
      break;
    case -17:
      result = 14;
      break;
    case -16:
      result = 8;
      break;
    case -14:
      result = 5;
      break;
    case -12:
      result = 2;
      break;
    case -11:
      result = 3;
      break;
    case -7:
      result = 18;
      break;
    case -6:
      result = 21;
      break;
    case -5:
      result = 23;
      break;
    case -2:
      result = 17;
      break;
    case 0:
      return result;
    default:
      if ( (_DWORD)result == -512 )
        result = 48;
      else
LABEL_5:
        result = 12;
      break;
  }
  return result;
}
