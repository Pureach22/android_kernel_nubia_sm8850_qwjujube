__int64 __fastcall sme_update_config(__int64 a1, __int64 a2)
{
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  unsigned int v12; // w0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  unsigned int v21; // w21
  unsigned int v22; // w0
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7

  qdf_trace(52, 7u, 255, 0);
  if ( a2 )
  {
    v12 = qdf_mutex_acquire(a1 + 12776);
    if ( v12 )
    {
      v21 = v12;
      qdf_trace_msg(
        0x34u,
        2u,
        "%s: SME lock error %d",
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        "sme_update_config",
        v12);
    }
    else
    {
      v22 = ((__int64 (__fastcall *)(__int64, __int64))csr_change_default_config_param)(a1, a2);
      if ( v22 )
        qdf_trace_msg(
          0x34u,
          2u,
          "%s: csr_change_default_config_param failed status: %d",
          v23,
          v24,
          v25,
          v26,
          v27,
          v28,
          v29,
          v30,
          "sme_update_config",
          v22);
      if ( (csr_is_all_session_disconnected(a1) & 1) != 0 )
        csr_set_global_cfgs(a1);
      qdf_mutex_release(a1 + 12776);
      return 0;
    }
  }
  else
  {
    qdf_trace_msg(0x34u, 2u, "%s: SME config params empty", v4, v5, v6, v7, v8, v9, v10, v11, "sme_update_config");
    return 16;
  }
  return v21;
}
