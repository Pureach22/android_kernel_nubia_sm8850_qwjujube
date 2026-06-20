__int64 __fastcall cm_crypto_authmode_to_wmi_authmode(int a1, int a2, int a3)
{
  __int16 v3; // w8
  bool v4; // cc
  __int64 result; // x0

  v3 = a1;
  v4 = a1 < 1;
  result = 1;
  if ( !v4 && (v3 & 2) == 0 )
  {
    if ( (v3 & 0x11) != 0 )
    {
      return (a3 & 0x1868F) != 0;
    }
    else if ( (v3 & 4) != 0 )
    {
      return 2;
    }
    else if ( (v3 & 0x6C8) != 0 )
    {
      if ( (a2 & 0x200000) != 0 )
      {
        return 26;
      }
      else if ( (a2 & 0x100000) != 0 )
      {
        return 25;
      }
      else if ( (a2 & 0x80000) != 0 )
      {
        return 20;
      }
      else if ( (a2 & 0x40000) != 0 )
      {
        return 19;
      }
      else if ( (a2 & 0x10000000) != 0 )
      {
        return 32;
      }
      else if ( (a2 & 0x8000000) != 0 )
      {
        return 31;
      }
      else if ( (a2 & 0x800) != 0 )
      {
        return 23;
      }
      else if ( (a2 & 0x400) != 0 )
      {
        return 27;
      }
      else if ( (a2 & 0x400000) != 0 )
      {
        return 28;
      }
      else if ( (a2 & 0x20) != 0 )
      {
        return 13;
      }
      else if ( (a2 & 0x40) != 0 )
      {
        return 14;
      }
      else if ( (a2 & 1) != 0 )
      {
        return 6;
      }
      else if ( (a2 & 2) != 0 )
      {
        return 11;
      }
      else if ( (a2 & 0x4000) != 0 )
      {
        return 18;
      }
      else if ( (a2 & 0x100) != 0 )
      {
        return 15;
      }
      else if ( (a2 & 0x80) != 0 )
      {
        return 16;
      }
      else if ( (a2 & 0x10000) != 0 )
      {
        return 21;
      }
      else if ( (a2 & 0x20000) != 0 )
      {
        return 22;
      }
      else
      {
        return (a2 << 7 >> 31) & 0x18;
      }
    }
    else if ( (v3 & 0x20) != 0 )
    {
      if ( (a2 & 1) != 0 )
      {
        return 5;
      }
      else if ( (a2 & 2) != 0 )
      {
        return 10;
      }
      else
      {
        return (a2 << 17 >> 31) & 0x11;
      }
    }
    else if ( (v3 & 0x100) != 0 )
    {
      if ( (a2 & 0x2000) != 0 )
        return 8;
      else
        return (a2 << 19 >> 31) & 0xC;
    }
  }
  return result;
}
