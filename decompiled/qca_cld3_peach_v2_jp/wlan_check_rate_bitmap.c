bool __fastcall wlan_check_rate_bitmap(char a1, unsigned __int16 a2)
{
  unsigned int v2; // w9
  int v3; // w8

  v2 = a1 & 0x7F;
  v3 = a2;
  if ( v2 > 0x17 )
  {
    if ( (a1 & 0x7Fu) > 0x47 )
    {
      switch ( v2 )
      {
        case 'H':
          v3 = a2 & 0x200;
          break;
        case '`':
          v3 = a2 & 0x400;
          break;
        case 'l':
          v3 = a2 & 0x800;
          break;
      }
    }
    else
    {
      switch ( v2 )
      {
        case 0x18u:
          v3 = a2 & 0x40;
          break;
        case 0x24u:
          v3 = a2 & 0x80;
          break;
        case 0x30u:
          v3 = a2 & 0x100;
          break;
      }
    }
  }
  else if ( (a1 & 0x7Fu) > 0xB )
  {
    switch ( v2 )
    {
      case 0xCu:
        v3 = a2 & 0x10;
        break;
      case 0x12u:
        v3 = a2 & 0x20;
        break;
      case 0x16u:
        v3 = a2 & 8;
        break;
    }
  }
  else
  {
    switch ( v2 )
    {
      case 2u:
        v3 = a2 & 1;
        break;
      case 4u:
        v3 = a2 & 2;
        break;
      case 0xBu:
        v3 = a2 & 4;
        break;
    }
  }
  return v3 != 0;
}
