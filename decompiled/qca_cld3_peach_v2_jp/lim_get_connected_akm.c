__int64 __fastcall lim_get_connected_akm(__int64 a1, int a2, int a3, int a4)
{
  __int64 result; // x0
  int param; // w21
  int v8; // w0
  int v9; // w21
  int v10; // w0
  int v11; // w19
  int v12; // w0
  __int16 v13; // w8
  bool v14; // zf

  result = 0;
  if ( (a3 & 3) == 0 && a2 != -1 && a3 != -1 && a4 != -1 )
  {
    param = wlan_crypto_get_param(*(_QWORD *)(a1 + 16), 1u);
    v8 = wlan_crypto_get_param(*(_QWORD *)(a1 + 16), 0);
    if ( v8 == -1 || param == -1 || (v8 & 0x6C8) == 0 || (param & 0x1868F) == 0 )
    {
      v9 = wlan_crypto_get_param(*(_QWORD *)(a1 + 16), 1u);
      v10 = wlan_crypto_get_param(*(_QWORD *)(a1 + 16), 0);
      if ( v10 == -1 || v9 == -1 || (v10 & 0x20) == 0 || (v9 & 0x1808F) == 0 )
      {
        v11 = wlan_crypto_get_param(*(_QWORD *)(a1 + 16), 1u);
        v12 = wlan_crypto_get_param(*(_QWORD *)(a1 + 16), 0);
        v13 = v12;
        v14 = v12 == -1;
        result = 0;
        if ( !v14 && v11 != -1 && (v13 & 0x100) != 0 )
        {
          if ( (v11 & 0x2010) != 0 )
            return 255;
          else
            return 0;
        }
      }
      else if ( (a4 & 1) != 0 )
      {
        return 20;
      }
      else if ( (a4 & 2) != 0 )
      {
        return 21;
      }
      else if ( (a4 & 0x4000) != 0 )
      {
        return 17;
      }
      else
      {
        return 255;
      }
    }
    else if ( (a4 & 0x200000) != 0 )
    {
      return 15;
    }
    else if ( (a4 & 0x100000) != 0 )
    {
      return 14;
    }
    else if ( (a4 & 0x80000) != 0 )
    {
      return 13;
    }
    else if ( (a4 & 0x40000) != 0 )
    {
      return 12;
    }
    else if ( (a4 & 0x10000000) != 0 )
    {
      return 23;
    }
    else if ( (a4 & 0x800) != 0 )
    {
      return 8;
    }
    else if ( (a4 & 0x400) != 0 )
    {
      return 7;
    }
    else if ( (a4 & 0x800000) != 0 )
    {
      return 19;
    }
    else if ( (a4 & 0x8000) != 0 )
    {
      return 18;
    }
    else if ( (a4 & 0x400000) != 0 )
    {
      return 16;
    }
    else if ( (a4 & 0x20) != 0 )
    {
      return 3;
    }
    else if ( (a4 & 0x40) != 0 )
    {
      return 4;
    }
    else if ( (a4 & 1) != 0 )
    {
      return 1;
    }
    else if ( (a4 & 2) != 0 )
    {
      return 2;
    }
    else if ( (a4 & 0x4000) != 0 )
    {
      return 17;
    }
    else if ( (a4 & 0x100) != 0 )
    {
      return 5;
    }
    else if ( (a4 & 0x80) != 0 )
    {
      return 6;
    }
    else if ( (a4 & 0x10000) != 0 )
    {
      return 9;
    }
    else if ( (a4 & 0x20000) != 0 )
    {
      return 10;
    }
    else if ( (a4 & 0x1000000) != 0 )
    {
      return 11;
    }
    else
    {
      return ((16 * a4) >> 31) & 0x16;
    }
  }
  return result;
}
