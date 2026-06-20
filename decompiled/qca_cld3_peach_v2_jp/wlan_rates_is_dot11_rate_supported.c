__int64 __fastcall wlan_rates_is_dot11_rate_supported(__int64 a1, char a2)
{
  unsigned int v2; // w9
  int v3; // w8
  unsigned int v4; // w8
  unsigned int v6; // w9

  v2 = a2 & 0x7F;
  v3 = *(_DWORD *)(*(_QWORD *)(a1 + 8) + 5748LL);
  if ( v3 != 3 )
  {
    if ( v3 == 2 )
    {
      if ( v2 - 12 <= 0x3C && ((1LL << ((unsigned __int8)v2 - 12)) & 0x1000001001001041LL) != 0 || v2 == 96 || v2 == 108 )
        return 1;
    }
    else
    {
      if ( (*(_BYTE *)(a1 + 17145) & 1) != 0 )
      {
        switch ( a2 & 0x7F )
        {
          case 2:
          case 4:
          case 0xB:
          case 0xC:
          case 0x12:
          case 0x16:
          case 0x18:
          case 0x24:
          case 0x30:
          case 0x48:
          case 0x60:
          case 0x6C:
            return 1;
          default:
            return 0;
        }
      }
      if ( v2 <= 0x30 && ((1LL << v2) & 0x1001001441814LL) != 0 )
        return 1;
      v6 = v2 - 72;
      if ( v6 <= 0x24 && ((1LL << v6) & 0x1001000001LL) != 0 )
        return 1;
    }
    return 0;
  }
  v4 = 0x400814u >> v2;
  if ( v2 >= 0x17 )
    LOBYTE(v4) = 0;
  return v4 & 1;
}
