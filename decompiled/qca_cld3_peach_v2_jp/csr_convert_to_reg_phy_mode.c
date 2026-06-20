__int64 __fastcall csr_convert_to_reg_phy_mode(
        int a1,
        unsigned int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  unsigned int v10; // w8

  if ( a1 <= 63 )
  {
    if ( a1 <= 7 )
    {
      if ( a1 == 1 )
      {
        if ( wlan_reg_is_24ghz_ch_freq(a2) )
          return 2;
        else
          return 3;
      }
      if ( a1 == 2 )
        return 3;
      if ( a1 != 4 )
        goto LABEL_22;
      return 1;
    }
    if ( a1 != 8 )
    {
      if ( a1 == 16 )
        return 4;
      if ( a1 != 32 )
        goto LABEL_22;
    }
    return 2;
  }
  if ( a1 <= 511 )
  {
    if ( a1 != 64 )
    {
      if ( a1 != 128 )
      {
        if ( a1 == 256 )
          return 5;
LABEL_22:
        qdf_trace_msg(
          0x34u,
          2u,
          "%s: Invalid eCsrPhyMode",
          a3,
          a4,
          a5,
          a6,
          a7,
          a8,
          a9,
          a10,
          "csr_convert_to_reg_phy_mode");
        return 0;
      }
      return 1;
    }
    return 4;
  }
  v10 = 6;
  if ( a1 > 2047 )
  {
    if ( a1 != 2048 && a1 != 4096 )
      goto LABEL_22;
    return v10;
  }
  if ( a1 == 512 )
    return 5;
  if ( a1 != 1024 )
    goto LABEL_22;
  return v10;
}
