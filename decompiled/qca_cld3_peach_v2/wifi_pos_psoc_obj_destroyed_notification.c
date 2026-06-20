__int64 __fastcall wifi_pos_psoc_obj_destroyed_notification(__int64 a1)
{
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
  unsigned int v10; // w19
  __int64 v11; // x0
  __int64 psoc_priv_obj; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x20
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7

  if ( wifi_pos_get_psoc(a1) == a1 )
  {
    v11 = qdf_trace_msg(
            0x25u,
            8u,
            "%s: deregistering wifi_pos_psoc object",
            v2,
            v3,
            v4,
            v5,
            v6,
            v7,
            v8,
            v9,
            "wifi_pos_psoc_obj_destroyed_notification");
    wifi_pos_clear_psoc(v11);
    psoc_priv_obj = wifi_pos_get_psoc_priv_obj(a1);
    if ( psoc_priv_obj )
    {
      v21 = psoc_priv_obj;
      v10 = wlan_objmgr_psoc_component_obj_detach(a1, 9u, psoc_priv_obj);
      if ( v10 )
        qdf_trace_msg(
          0x25u,
          2u,
          "%s: wifi_pos_obj detach failed",
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          v28,
          v29,
          "wifi_pos_psoc_obj_destroyed_notification");
      qdf_trace_msg(
        0x25u,
        8u,
        "%s: wifi_pos_obj deleted with status %d",
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        "wifi_pos_psoc_obj_destroyed_notification",
        v10);
      _qdf_mem_free(v21);
    }
    else
    {
      qdf_trace_msg(
        0x25u,
        2u,
        "%s: wifi_pos_obj is NULL",
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        "wifi_pos_psoc_obj_destroyed_notification");
      return 5;
    }
  }
  else
  {
    qdf_trace_msg(
      0x25u,
      3u,
      "%s: un-related PSOC closed. do nothing",
      v2,
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      "wifi_pos_psoc_obj_destroyed_notification");
    return 0;
  }
  return v10;
}
