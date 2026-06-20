__int64 __fastcall cm_send_force_bss_peer_delete_req(__int64 a1)
{
  unsigned int v2; // w20
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x0
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  __int64 v28; // x20
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  __int64 result; // x0
  _DWORD v38[74]; // [xsp+0h] [xbp-130h] BYREF
  __int64 v39; // [xsp+128h] [xbp-8h]

  v39 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(unsigned __int8 *)(a1 + 168);
  memset(v38, 0, sizeof(v38));
  if ( (cm_get_active_connect_req(a1, (__int64)v38, v3, v4, v5, v6, v7, v8, v9, v10) & 1) != 0 )
  {
    v19 = _qdf_mem_malloc(0x118u, "cm_send_force_bss_peer_delete_req", 1999);
    if ( v19 )
    {
      v28 = v19;
      if ( (unsigned int)cm_copy_join_params(a1, v19, (__int64)v38) )
      {
        qdf_trace_msg(
          0x68u,
          2u,
          "%s: vdev %d cm_id 0x%x: Failed to copy join req",
          v29,
          v30,
          v31,
          v32,
          v33,
          v34,
          v35,
          v36,
          "cm_send_force_bss_peer_delete_req",
          LOBYTE(v38[0]),
          v38[1]);
        cm_free_join_req(v28);
        result = 16;
      }
      else
      {
        cm_remove_force_bss_on_join_fail(v28);
        result = 0;
      }
    }
    else
    {
      qdf_trace_msg(
        0x68u,
        2u,
        "%s: malloc fail",
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        "cm_send_force_bss_peer_delete_req");
      result = 2;
    }
  }
  else
  {
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: Failed to get vdev %d active connect req",
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      "cm_send_force_bss_peer_delete_req",
      v2);
    result = 4;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
