__int64 __fastcall cds_force_assert_target(__int64 a1)
{
  unsigned int v2; // w0
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
  __int64 v19; // x20
  unsigned int v20; // w0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 v29; // x4
  const char *v30; // x2
  __int64 result; // x0
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7

  v2 = pld_force_assert_target(*(_QWORD *)(a1 + 40));
  if ( !v2 )
    return qdf_trace_msg(
             0x38u,
             4u,
             "%s: Target force assert triggered via PLD",
             v3,
             v4,
             v5,
             v6,
             v7,
             v8,
             v9,
             v10,
             "cds_force_assert_target_via_pld");
  if ( v2 != -95 )
    return qdf_trace_msg(
             0x38u,
             2u,
             "%s: Failed PLD target force assert; errno %d",
             v3,
             v4,
             v5,
             v6,
             v7,
             v8,
             v9,
             v10,
             "cds_force_assert_target_via_pld",
             v2);
  qdf_trace_msg(
    0x38u,
    4u,
    "%s: PLD does not support target force assert",
    v3,
    v4,
    v5,
    v6,
    v7,
    v8,
    v9,
    v10,
    "cds_force_assert_target_via_pld",
    4294967201LL);
  if ( gp_cds_context )
  {
    v19 = *(_QWORD *)(gp_cds_context + 24);
    if ( v19 )
    {
      v20 = wma_crash_inject(*(_QWORD *)(gp_cds_context + 24), 8, 0);
      if ( v20 )
      {
        v29 = v20;
        v30 = "%s: Failed target force assert; status %d";
      }
      else
      {
        result = qdf_wait_for_event_completion(v19 + 120, 0x1388u);
        if ( !(_DWORD)result )
          return result;
        v29 = (unsigned int)result;
        v30 = "%s: Failed target force assert wait; status %d";
      }
      qdf_trace_msg(0x38u, 2u, v30, v21, v22, v23, v24, v25, v26, v27, v28, "cds_force_assert_target_via_wmi", v29);
    }
    else
    {
      qdf_trace_msg(
        0x38u,
        2u,
        "%s: Module ID %d context is Null (via %s)",
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        "__cds_get_context",
        54,
        "cds_force_assert_target_via_wmi");
    }
  }
  else
  {
    qdf_trace_msg(
      0x38u,
      2u,
      "%s: cds context pointer is null (via %s)",
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      "__cds_get_context",
      "cds_force_assert_target_via_wmi");
  }
  qdf_trace_msg(
    0x38u,
    2u,
    "%s: Scheduling recovery work without firmware assert",
    v32,
    v33,
    v34,
    v35,
    v36,
    v37,
    v38,
    v39,
    "cds_force_assert_target");
  return pld_schedule_recovery_work(*(_QWORD *)(a1 + 40), 2);
}
