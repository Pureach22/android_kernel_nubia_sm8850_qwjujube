__int64 __fastcall wlan_add_rate_bitmap(__int64 result, _WORD *a2)
{
  unsigned int v2; // w8
  __int16 v3; // w8

  v2 = result & 0x7F;
  if ( v2 > 0x17 )
  {
    if ( ((unsigned __int8)result & 0x7Fu) > 0x47 )
    {
      switch ( v2 )
      {
        case 'H':
          v3 = 512;
          break;
        case '`':
          v3 = 1024;
          break;
        case 'l':
          v3 = 2048;
          break;
        default:
          return result;
      }
    }
    else
    {
      switch ( v2 )
      {
        case 0x18u:
          v3 = 64;
          break;
        case 0x24u:
          v3 = 128;
          break;
        case 0x30u:
          v3 = 256;
          break;
        default:
          return result;
      }
    }
  }
  else if ( ((unsigned __int8)result & 0x7Fu) > 0xB )
  {
    switch ( v2 )
    {
      case 0xCu:
        v3 = 16;
        break;
      case 0x12u:
        v3 = 32;
        break;
      case 0x16u:
        v3 = 8;
        break;
      default:
        return result;
    }
  }
  else
  {
    switch ( v2 )
    {
      case 2u:
        v3 = 1;
        break;
      case 4u:
        v3 = 2;
        break;
      case 0xBu:
        v3 = 4;
        break;
      default:
        return result;
    }
  }
  *a2 |= v3;
  return result;
}
