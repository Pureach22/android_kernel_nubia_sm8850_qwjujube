__int64 __fastcall wifi_pos_register_send_action(__int64 a1, __int64 a2)
{
  __int64 psoc; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 psoc_priv_obj; // x0
  const char *v15; // x2

  psoc = wifi_pos_get_psoc(a1);
  if ( a1 )
  {
    if ( a2 )
    {
      if ( psoc )
      {
        psoc_priv_obj = wifi_pos_get_psoc_priv_obj(psoc);
        if ( psoc_priv_obj )
        {
          *(_QWORD *)(psoc_priv_obj + 152) = a2;
          return 0;
        }
      }
      v15 = "%s: wifi_pos priv obj is null";
    }
    else
    {
      v15 = "%s: Null callback";
    }
  }
  else
  {
    v15 = "%s: psoc is null";
  }
  qdf_trace_msg(0x25u, 2u, v15, v5, v6, v7, v8, v9, v10, v11, v12, "wifi_pos_register_send_action");
  return 29;
}
