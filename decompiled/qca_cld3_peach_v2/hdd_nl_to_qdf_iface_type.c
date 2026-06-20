__int64 __fastcall hdd_nl_to_qdf_iface_type(
        int a1,
        _DWORD *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x29
  __int64 v11; // x30

  if ( a1 <= 7 )
  {
    if ( a1 > 4 )
    {
      if ( a1 == 5 )
      {
        *a2 = 12;
        return 0;
      }
      if ( a1 == 6 )
      {
        *a2 = 6;
        return 0;
      }
    }
    else
    {
      if ( a1 == 2 )
      {
        *a2 = 0;
        return 0;
      }
      if ( a1 == 3 )
      {
        *a2 = 1;
        return 0;
      }
    }
LABEL_22:
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Invalid nl80211 interface type %d",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "hdd_nl_to_qdf_iface_type",
      v10,
      v11);
    return 4;
  }
  if ( a1 > 9 )
  {
    switch ( a1 )
    {
      case 10:
        *a2 = 7;
        return 0;
      case 11:
        *a2 = 8;
        return 0;
      case 12:
        *a2 = 16;
        return 0;
    }
    goto LABEL_22;
  }
  if ( a1 == 8 )
    *a2 = 2;
  else
    *a2 = 3;
  return 0;
}
