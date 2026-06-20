__int64 __fastcall wifi_pos_psoc_obj_created_notification(__int64 a1)
{
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
  __int64 result; // x0
  __int64 v11; // x0
  __int64 v12; // x20
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  unsigned int v21; // w19
  __int64 v22; // x0

  if ( wifi_pos_get_psoc(a1) )
  {
    qdf_trace_msg(
      0x25u,
      8u,
      "%s: global psoc obj already set. do not allocate another psoc private object",
      v2,
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      "wifi_pos_psoc_obj_created_notification");
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x25u,
      8u,
      "%s: setting global pos object",
      v2,
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      "wifi_pos_psoc_obj_created_notification");
    wifi_pos_set_psoc(a1);
    v11 = _qdf_mem_malloc(0xC0u, "wifi_pos_psoc_obj_created_notification", 1024);
    if ( v11 )
    {
      v12 = v11;
      *(_DWORD *)(v11 + 88) = 0;
      *(_QWORD *)(v11 + 96) = 0;
      *(_QWORD *)(v11 + 120) = wifi_pos_tlv_callback;
      result = wlan_objmgr_psoc_component_obj_attach(a1, 9u, v11, 0);
      if ( (_DWORD)result )
      {
        v21 = result;
        qdf_trace_msg(
          0x25u,
          2u,
          "%s: obj attach with psoc failed with status: %d",
          v13,
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          "wifi_pos_psoc_obj_created_notification",
          (unsigned int)result);
        v22 = _qdf_mem_free(v12);
        wifi_pos_clear_psoc(v22);
        return v21;
      }
    }
    else
    {
      ((void (*)(void))wifi_pos_clear_psoc)();
      return 2;
    }
  }
  return result;
}
