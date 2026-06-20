__int64 __fastcall wlan_serialization_psoc_disable(__int64 a1)
{
  __int64 psoc_obj; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 v11; // x19
  unsigned int v12; // w20
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7

  psoc_obj = wlan_serialization_get_psoc_obj(a1);
  if ( psoc_obj )
  {
    v11 = psoc_obj;
    wlan_serialization_purge_all_cmd(a1);
    v12 = wlan_serialization_cleanup_all_timers(v11);
    if ( v12 )
      qdf_trace_msg(
        0x4Cu,
        2u,
        "%s: ser cleaning up all timer failed",
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        "wlan_serialization_psoc_disable");
    wlan_serialization_acquire_lock(v11 + 14976);
    _qdf_mem_free(*(_QWORD *)(v11 + 14960));
    *(_QWORD *)(v11 + 14960) = 0;
    *(_BYTE *)(v11 + 14968) = 0;
    wlan_serialization_release_lock(v11 + 14976);
  }
  else
  {
    qdf_trace_msg(
      0x4Cu,
      2u,
      "%s: invalid ser_soc_obj",
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      "wlan_serialization_psoc_disable");
    return 16;
  }
  return v12;
}
