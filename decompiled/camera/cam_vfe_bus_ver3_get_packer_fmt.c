__int64 __fastcall cam_vfe_bus_ver3_get_packer_fmt(int a1, int a2)
{
  int v2; // w8
  __int64 result; // x0

  v2 = a1 - 1;
  result = 0;
  switch ( v2 )
  {
    case 0:
    case 5:
    case 12:
    case 19:
    case 34:
      return result;
    case 1:
    case 11:
      result = 1;
      break;
    case 2:
      result = 12;
      break;
    case 3:
      result = 13;
      break;
    case 4:
      result = 14;
      break;
    case 6:
      result = 15;
      break;
    case 13:
    case 48:
      result = 5;
      break;
    case 14:
      result = 6;
      break;
    case 15:
      result = 7;
      break;
    case 16:
      result = 8;
      break;
    case 17:
      result = 16;
      break;
    case 18:
    case 35:
    case 47:
      result = 10;
      break;
    case 20:
    case 46:
      result = 9;
      break;
    case 30:
      if ( (unsigned int)(a2 - 1) >= 5 )
        goto LABEL_18;
      result = dword_44EB9C[a2 - 1];
      break;
    case 31:
    case 36:
    case 37:
    case 44:
LABEL_18:
      result = 3;
      break;
    case 32:
    case 38:
    case 50:
    case 51:
    case 53:
      result = 11;
      break;
    default:
      result = 17;
      break;
  }
  return result;
}
