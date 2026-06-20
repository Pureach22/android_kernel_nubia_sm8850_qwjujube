__int64 __fastcall hdd_get_link_info_by_ieee_link_id(
        __int64 a1,
        int a2,
        char a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v12; // x21
  __int64 v14; // x22

  if ( !a1 || a2 == 255 )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: NULL adapter or invalid link ID",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "hdd_get_link_info_by_ieee_link_id");
  }
  else
  {
    v12 = a1 + 52840;
    if ( a1 != -52840 )
    {
      v14 = 0;
      while ( (unsigned __int64)(0x71B3F945A27B1F49LL * (v14 >> 3)) <= 2 )
      {
        if ( (unsigned int)hdd_cm_get_ieee_link_id(v12 + v14, a3 & 1) == a2 )
          return v12 + v14;
        v14 += 6088;
        if ( !(v12 + v14) )
          return 0;
      }
    }
  }
  return 0;
}
