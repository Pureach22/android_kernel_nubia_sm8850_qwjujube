__int64 __fastcall policy_mgr_psoc_disable(__int64 a1)
{
  __int64 context; // x0
  __int64 v3; // x1
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 v12; // x21
  __int64 v13; // x1
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  unsigned int v22; // w20
  __int64 v23; // x1
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7

  context = policy_mgr_get_context(a1);
  if ( context )
  {
    v12 = context;
    if ( (unsigned int)qdf_event_destroy(context + 16, v3) )
    {
      qdf_trace_msg(
        0x4Fu,
        2u,
        "%s: Failed to destroy connection_update_done_evt",
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        "policy_mgr_psoc_disable");
      v22 = 16;
    }
    else
    {
      v22 = 0;
    }
    if ( (unsigned int)qdf_event_destroy(v12 + 2112, v13) )
    {
      qdf_trace_msg(
        0x4Fu,
        2u,
        "%s: Failed to destroy opportunistic_update_done_evt",
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        "policy_mgr_psoc_disable");
      v22 = 16;
    }
    if ( (unsigned int)qdf_event_destroy(v12 + 2152, v23) )
    {
      qdf_trace_msg(
        0x4Fu,
        2u,
        "%s: Failed to destroy channel_switch_complete evt",
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        v39,
        "policy_mgr_psoc_disable");
      v22 = 16;
    }
    if ( (unsigned int)qdf_mc_timer_get_current_state(v12 + 120) == 21 )
      qdf_mc_timer_stop(v12 + 120);
    if ( (unsigned int)qdf_mc_timer_destroy(v12 + 120) )
    {
      qdf_trace_msg(
        0x4Fu,
        2u,
        "%s: Cannot deallocate dbs opportunistic timer",
        v40,
        v41,
        v42,
        v43,
        v44,
        v45,
        v46,
        v47,
        "policy_mgr_psoc_disable");
      v22 = 16;
    }
    if ( (unsigned int)policy_mgr_reset_sap_mandatory_channels(a1) )
    {
      qdf_trace_msg(
        0x4Fu,
        2u,
        "%s: failed to reset sap mandatory channels",
        v48,
        v49,
        v50,
        v51,
        v52,
        v53,
        v54,
        v55,
        "policy_mgr_psoc_disable");
      v22 = 16;
    }
    qdf_mem_set(&pm_conc_connection_list, 0xB4u, 0);
    policy_mgr_clear_concurrent_session_count(a1);
  }
  else
  {
    qdf_trace_msg(0x4Fu, 2u, "%s: Invalid Context", v4, v5, v6, v7, v8, v9, v10, v11, "policy_mgr_psoc_disable");
    return 16;
  }
  return v22;
}
