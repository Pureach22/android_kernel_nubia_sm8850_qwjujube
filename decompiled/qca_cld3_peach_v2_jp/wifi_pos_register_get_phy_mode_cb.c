__int64 __fastcall wifi_pos_register_get_phy_mode_cb(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 psoc_priv_obj; // x0
  const char *v13; // x2

  if ( a1 )
  {
    if ( a2 )
    {
      psoc_priv_obj = wifi_pos_get_psoc_priv_obj(a1);
      if ( psoc_priv_obj )
      {
        *(_QWORD *)(psoc_priv_obj + 136) = a2;
        return 0;
      }
      v13 = "%s: wifi_pos priv obj is null";
    }
    else
    {
      v13 = "%s: Null callback";
    }
  }
  else
  {
    v13 = "%s: psoc is null";
  }
  qdf_trace_msg(0x25u, 2u, v13, a3, a4, a5, a6, a7, a8, a9, a10, "wifi_pos_register_get_phy_mode_cb");
  return 29;
}
