__int64 __fastcall dp_peer_obj_create_notification(unsigned __int8 *a1)
{
  __int64 v2; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  unsigned __int8 *v11; // x19
  unsigned int v12; // w20
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x4
  __int64 v22; // x5
  __int64 v23; // x6
  __int64 v24; // x7
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7

  v2 = _qdf_mem_malloc(0x20u, "dp_peer_obj_create_notification", 1332);
  if ( v2 )
  {
    v11 = (unsigned __int8 *)v2;
    v12 = wlan_objmgr_peer_component_obj_attach((__int64)a1, 0x2Eu, v2, 0);
    if ( v12 )
    {
      qdf_trace_msg(
        0x45u,
        2u,
        "%s: DP peer (%02x:%02x:%02x:**:**:%02x) attach failed",
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        "dp_peer_obj_create_notification",
        a1[48],
        a1[49],
        a1[50],
        a1[53]);
      _qdf_mem_free((__int64)v11);
    }
    else
    {
      qdf_mem_copy(v11, a1 + 48, 6u);
      v21 = *v11;
      v22 = v11[1];
      v23 = v11[2];
      v24 = v11[5];
      *((_QWORD *)v11 + 1) = 0;
      *((_QWORD *)v11 + 2) = 0;
      qdf_trace_msg(
        0x45u,
        5u,
        "%s: sta info created mac:%02x:%02x:%02x:**:**:%02x",
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        "dp_peer_obj_create_notification",
        v21,
        v22,
        v23,
        v24);
    }
  }
  else
  {
    v12 = 2;
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: Failed to allocated DP peer priv ctx",
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      "dp_peer_obj_create_notification");
  }
  return v12;
}
