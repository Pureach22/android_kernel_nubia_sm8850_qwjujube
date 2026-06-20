__int64 __fastcall wlan_crypto_get_secure_akm_available(int a1)
{
  if ( !a1 )
    return 30;
  if ( (a1 & 0x200000) != 0 )
    return 21;
  if ( (a1 & 0x100000) != 0 )
    return 20;
  if ( (a1 & 0x80000) != 0 )
    return 19;
  if ( (a1 & 0x40000) != 0 )
    return 18;
  if ( (a1 & 0x1000000) != 0 )
    return 24;
  if ( (a1 & 0x20000) != 0 )
    return 17;
  if ( (a1 & 0x10000) != 0 )
    return 16;
  if ( (a1 & 0x10000000) != 0 )
    return 28;
  if ( (a1 & 0x8000000) != 0 )
    return 27;
  if ( (a1 & 0x800) != 0 )
    return 11;
  if ( (a1 & 0x400) != 0 )
    return 10;
  if ( (a1 & 0x400000) != 0 )
    return 22;
  if ( (a1 & 0x800000) != 0 )
    return 23;
  if ( (a1 & 0x80) != 0 )
    return 7;
  if ( (a1 & 0x20) != 0 )
    return 5;
  if ( (a1 & 1) != 0 )
    return 0;
  if ( (a1 & 0x2000000) != 0 )
    return 25;
  if ( (a1 & 0x4000000) != 0 )
    return 26;
  if ( (a1 & 0x100) != 0 )
    return 8;
  if ( (a1 & 0x40) != 0 )
    return 6;
  if ( (a1 & 2) != 0 )
    return 1;
  if ( (a1 & 0x1000) != 0 )
    return 12;
  if ( (a1 & 0x2000) != 0 )
    return 13;
  if ( (a1 & 0x4000) != 0 )
    return 14;
  if ( (a1 & 0x8000) != 0 )
    return 15;
  if ( (a1 & 0x200) != 0 )
    return 9;
  if ( (a1 & 8) != 0 )
    return 3;
  if ( (a1 & 0x10) != 0 )
    return 4;
  return 30;
}
