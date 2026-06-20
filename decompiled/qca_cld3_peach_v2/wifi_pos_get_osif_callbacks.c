__int64 __fastcall wifi_pos_get_osif_callbacks(__int64 a1)
{
  __int64 psoc; // x0
  __int64 psoc_priv_obj; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7

  psoc = wifi_pos_get_psoc(a1);
  psoc_priv_obj = wifi_pos_get_psoc_priv_obj(psoc);
  if ( psoc_priv_obj )
    return *(_QWORD *)(psoc_priv_obj + 80);
  qdf_trace_msg(
    0x25u,
    2u,
    "%s: wifi_pos priv obj is null",
    v3,
    v4,
    v5,
    v6,
    v7,
    v8,
    v9,
    v10,
    "wifi_pos_get_osif_callbacks");
  return 0;
}
