__int64 __fastcall cam_sfe_bus_rd_pxls_to_bytes(__int64 result, int a2, unsigned int *a3)
{
  int v3; // w8

  switch ( a2 )
  {
    case 0:
      *a3 = 16 * result;
      break;
    case 1:
    case 2:
    case 3:
    case 4:
    case 6:
    case 7:
    case 8:
    case 16:
    case 18:
      *a3 = 2 * result;
      break;
    case 5:
    case 9:
      *a3 = 4 * result;
      break;
    case 10:
      *a3 = 8 * result;
      break;
    case 11:
      *a3 = 12 * (((int)result + 2) / 3u) / 3;
      break;
    case 12:
      *a3 = result;
      break;
    case 13:
      v3 = 5 * result;
      goto LABEL_9;
    case 14:
      *a3 = (unsigned int)(3 * result + 1) >> 1;
      break;
    case 15:
      v3 = 7 * result;
LABEL_9:
      *a3 = (unsigned int)(v3 + 3) >> 2;
      break;
    default:
      result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                 3,
                 0x40000000,
                 1,
                 "cam_sfe_bus_rd_pxls_to_bytes",
                 183,
                 "Invalid unpacker_fmt:%d",
                 a2);
      break;
  }
  return result;
}
