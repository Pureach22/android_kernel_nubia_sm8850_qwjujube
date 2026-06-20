__int64 __fastcall wlan_hdd_fill_os_eht_rateflags(
        __int64 result,
        int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  _WORD *v10; // x19
  unsigned int v11; // w1

  if ( (a2 & 0x3E000) != 0 )
  {
    v10 = (_WORD *)result;
    if ( (a2 & 0x20000) != 0 )
    {
      v11 = 6;
    }
    else if ( (a2 & 0x10000) != 0 )
    {
      v11 = 5;
    }
    else if ( (a2 & 0x8000) != 0 )
    {
      v11 = 4;
    }
    else
    {
      if ( (a2 & 0x4000) == 0 )
      {
LABEL_11:
        *v10 |= 0x80u;
        return result;
      }
      v11 = 3;
    }
    result = hdd_set_rate_bw(result, v11, a3, a4, a5, a6, a7, a8, a9, a10);
    goto LABEL_11;
  }
  return result;
}
