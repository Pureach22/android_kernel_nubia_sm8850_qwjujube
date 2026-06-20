__int64 __fastcall cm_send_force_bss_peer_delete_req(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  unsigned int v9; // w19
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 v18; // x0
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  __int64 v27; // x19
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  __int64 result; // x0
  _QWORD v37[15]; // [xsp+8h] [xbp-78h] BYREF

  v37[14] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = *(unsigned __int8 *)(a1 + 104);
  memset(v37, 0, 112);
  if ( (cm_get_active_connect_req(a1, (__int64)v37, a2, a3, a4, a5, a6, a7, a8, a9) & 1) != 0 )
  {
    v18 = _qdf_mem_malloc(0x68u, "cm_send_force_bss_peer_delete_req", 1999);
    if ( v18 )
    {
      v27 = v18;
      if ( (unsigned int)cm_copy_join_params(v18, (__int64)v37) )
      {
        qdf_trace_msg(
          0x68u,
          2u,
          "%s: vdev %d cm_id 0x%x: Failed to copy join req",
          v28,
          v29,
          v30,
          v31,
          v32,
          v33,
          v34,
          v35,
          "cm_send_force_bss_peer_delete_req",
          LOBYTE(v37[0]),
          HIDWORD(v37[0]));
        cm_free_join_req(v27);
        result = 16;
      }
      else
      {
        cm_remove_force_bss_on_join_fail(v27);
        result = 0;
      }
    }
    else
    {
      qdf_trace_msg(
        0x68u,
        2u,
        "%s: malloc fail",
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
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
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      "cm_send_force_bss_peer_delete_req",
      v9);
    result = 4;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
