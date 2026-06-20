__int64 __fastcall policy_mgr_link_reconfig_is_concurrency_present(__int64 a1)
{
  __int64 context; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 v11; // x21
  int v12; // w20
  unsigned __int8 v13; // w0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  const char *v22; // x2
  __int64 v23; // x0
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  __int64 v32; // x21
  unsigned int v33; // w20
  unsigned __int8 v35; // w0

  context = policy_mgr_get_context(a1);
  if ( context )
  {
    v11 = context;
    qdf_mutex_acquire(context + 56);
    v12 = BYTE4(qword_81C47C) + BYTE4(qword_81C458) + BYTE4(qword_81C4A0) + BYTE4(qword_81C4C4) + BYTE4(qword_81C4E8);
    qdf_mutex_release(v11 + 56);
  }
  else
  {
    qdf_trace_msg(0x4Fu, 2u, "%s: Invalid Context", v3, v4, v5, v6, v7, v8, v9, v10, "policy_mgr_get_connection_count");
    v12 = 0;
  }
  v13 = policy_mgr_mode_specific_connection_count(a1, 0, 0);
  v22 = "%s: station not present reject link reconfig req";
  if ( v12 && v13 )
  {
    if ( v12 == v13 )
    {
      v23 = policy_mgr_get_context(a1);
      if ( v23 )
      {
        v32 = v23;
        qdf_mutex_acquire(v23 + 56);
        v33 = BYTE4(qword_81C47C)
            + BYTE4(qword_81C458)
            + BYTE4(qword_81C4A0)
            + BYTE4(qword_81C4C4)
            + BYTE4(qword_81C4E8);
        qdf_mutex_release(v32 + 56);
      }
      else
      {
        qdf_trace_msg(
          0x4Fu,
          2u,
          "%s: Invalid Context",
          v24,
          v25,
          v26,
          v27,
          v28,
          v29,
          v30,
          v31,
          "policy_mgr_get_connection_count_with_mlo");
        v33 = 0;
      }
      v35 = policy_mgr_mode_specific_connection_count_with_mlo(a1, 0);
      v22 = "%s: ML station not present reject link reconfig req";
      if ( v33 && v35 )
      {
        if ( v33 == v35 )
        {
          if ( v33 < 2 )
            return 0;
          v22 = "%s: Another interface present with ML station ";
        }
        else
        {
          v22 = "%s: ML concurrency present, reject link reconfig req";
        }
      }
    }
    else
    {
      v22 = "%s: concurrency present, reject link reconfig req";
    }
  }
  qdf_trace_msg(
    0x4Fu,
    8u,
    v22,
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    "policy_mgr_link_reconfig_is_concurrency_present");
  return 1;
}
