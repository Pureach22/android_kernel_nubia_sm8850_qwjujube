__int64 __fastcall st54spi_power_set(__int64 result, int a2)
{
  __int64 v2; // x8
  _DWORD *v4; // x19
  int v5; // w8
  int v6; // w8

  if ( result )
  {
    v2 = *(_QWORD *)(result + 8);
    if ( !v2 )
      v2 = *(_QWORD *)(result + 16);
    v4 = (_DWORD *)result;
    dev_info(
      v2,
      "st54spi sehal pwr_req: %d, se_is_poweron = %d, nfcc_needs_poweron = %d\n",
      a2,
      *(_DWORD *)(result + 144),
      *(_DWORD *)(result + 136));
    result = (__int64)v4;
    if ( a2 )
    {
      v5 = v4[36];
      v4[35] = 1;
      if ( !v5 )
      {
        st54spi_power_on(v4);
        result = (__int64)v4;
      }
      if ( !*(_DWORD *)(result + 148) )
        return st54spi_power_on_for_comm(result);
    }
    else
    {
      v6 = v4[37];
      v4[35] = 0;
      if ( v6 == 1 )
      {
        st54spi_power_off_for_comm(v4);
        result = (__int64)v4;
      }
      if ( *(_DWORD *)(result + 144) == 1 && !*(_DWORD *)(result + 136) )
        return st54spi_power_off(result);
    }
  }
  return result;
}
