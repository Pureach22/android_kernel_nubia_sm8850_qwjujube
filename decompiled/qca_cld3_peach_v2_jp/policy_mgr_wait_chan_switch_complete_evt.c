__int64 __fastcall policy_mgr_wait_chan_switch_complete_evt(__int64 a1)
{
  __int64 context; // x0
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
  unsigned int v10; // w19
  const char *v11; // x2

  context = policy_mgr_get_context(a1);
  if ( !context )
  {
    v10 = 16;
    v11 = "%s: Invalid context";
    goto LABEL_5;
  }
  v10 = qdf_wait_single_event(context + 2152, 0x7D0u);
  if ( v10 )
  {
    v11 = "%s: wait for event failed, still continue with channel switch";
LABEL_5:
    qdf_trace_msg(0x4Fu, 2u, v11, v2, v3, v4, v5, v6, v7, v8, v9, "policy_mgr_wait_chan_switch_complete_evt");
  }
  return v10;
}
