__int64 __fastcall policy_mgr_set_hw_mode_on_channel_switch(__int64 a1, unsigned __int8 a2)
{
  __int64 result; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 (__fastcall *v13)(__int64); // x8
  unsigned int v14; // w21
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 context; // x0
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  __int64 v32; // x19
  const char *v33; // x2
  __int64 v34; // x20
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  unsigned int v43; // w19
  const char *v44; // x3
  unsigned int v45; // w1

  if ( (policy_mgr_is_hwmode_offload_enabled(a1) & 1) != 0 )
    return 11;
  if ( (policy_mgr_is_hw_dbs_capable(a1) & 1) == 0 )
  {
    v34 = jiffies;
    if ( policy_mgr_set_hw_mode_on_channel_switch___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x4Fu,
        8u,
        "%s: PM/DBS is disabled",
        v5,
        v6,
        v7,
        v8,
        v9,
        v10,
        v11,
        v12,
        "policy_mgr_set_hw_mode_on_channel_switch");
      policy_mgr_set_hw_mode_on_channel_switch___last_ticks = v34;
    }
    return 16;
  }
  v13 = (__int64 (__fastcall *)(__int64))policy_mgr_get_current_pref_hw_mode_ptr;
  if ( *((_DWORD *)policy_mgr_get_current_pref_hw_mode_ptr - 1) != 403152258 )
    __break(0x8228u);
  v14 = v13(a1);
  if ( v14 > 0xD || ((1 << v14) & 0x2824) == 0 )
  {
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: Invalid action: %d",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "policy_mgr_set_hw_mode_on_channel_switch",
      v14);
    return 0;
  }
  qdf_trace_msg(
    0x4Fu,
    8u,
    "%s: action:%d session id:%d",
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    "policy_mgr_set_hw_mode_on_channel_switch",
    v14,
    a2);
  if ( v14 == 5 )
  {
    if ( (policy_mgr_is_hwmode_offload_enabled(a1) & 1) != 0 )
      return 16;
    context = policy_mgr_get_context(a1);
    if ( context )
    {
      v32 = context;
      qdf_mc_timer_stop(context + 120);
      if ( !(unsigned int)qdf_mc_timer_start(v32 + 120, 0x1388u) )
      {
        v33 = "%s: opportunistic timer for MCC upgrade";
        v44 = "policy_mgr_set_hw_mode_on_channel_switch";
        v45 = 8;
        goto LABEL_21;
      }
      v33 = "%s: failed to start opportunistic timer";
    }
    else
    {
      v33 = "%s: Invalid context";
    }
    v44 = "policy_mgr_restart_opportunistic_timer";
    v45 = 2;
LABEL_21:
    qdf_trace_msg(0x4Fu, v45, v33, v24, v25, v26, v27, v28, v29, v30, v31, v44);
    return 16;
  }
  result = policy_mgr_next_actions(a1, a2, v14, 6u, 0);
  if ( (_DWORD)result )
  {
    v43 = result;
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: no set hw mode command was issued",
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      v42,
      "policy_mgr_set_hw_mode_on_channel_switch");
    return v43;
  }
  return result;
}
