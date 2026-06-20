__int64 __fastcall wifi_pos_register_osif_callbacks(__int64 a1)
{
  __int64 psoc; // x0
  __int64 psoc_priv_obj; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 v12; // x8

  psoc = wifi_pos_get_psoc(a1);
  psoc_priv_obj = wifi_pos_get_psoc_priv_obj(psoc);
  if ( psoc_priv_obj )
  {
    v12 = psoc_priv_obj;
    *(_QWORD *)(v12 + 80) = a1;
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x25u,
      2u,
      "%s: wifi_pos priv obj is null",
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      "wifi_pos_register_osif_callbacks");
    return 29;
  }
}
