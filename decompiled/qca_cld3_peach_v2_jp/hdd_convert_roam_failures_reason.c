__int64 __fastcall hdd_convert_roam_failures_reason(
        __int64 result,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x29
  __int64 v10; // x30

  switch ( (int)result )
  {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
      return result;
    case 11:
      result = 16;
      break;
    case 12:
    case 13:
    case 32:
    case 33:
    case 34:
    case 36:
    case 37:
    case 38:
    case 39:
    case 40:
    case 41:
    case 42:
    case 255:
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Invalid roam failures reason",
        a2,
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        "hdd_convert_roam_failures_reason",
        v9,
        v10);
      goto LABEL_3;
    case 14:
      result = 11;
      break;
    case 15:
      result = 12;
      break;
    case 16:
      result = 13;
      break;
    case 17:
      result = 14;
      break;
    case 18:
      result = 15;
      break;
    case 19:
      result = 17;
      break;
    case 20:
      result = 18;
      break;
    case 21:
      result = 19;
      break;
    case 22:
      result = 20;
      break;
    case 23:
      result = 21;
      break;
    case 24:
      result = 22;
      break;
    case 25:
      result = 23;
      break;
    case 26:
      result = 24;
      break;
    case 27:
      result = 25;
      break;
    case 28:
      result = 26;
      break;
    case 29:
      result = 27;
      break;
    case 30:
      result = 28;
      break;
    case 31:
      result = 29;
      break;
    case 35:
      result = 30;
      break;
    default:
LABEL_3:
      result = 0;
      break;
  }
  return result;
}
