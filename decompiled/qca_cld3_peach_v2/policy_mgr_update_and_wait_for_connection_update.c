__int64 __fastcall policy_mgr_update_and_wait_for_connection_update(
        __int64 a1,
        unsigned __int8 a2,
        unsigned int a3,
        unsigned int a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 context; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  const char *v25; // x2
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  int v34; // w0
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  int v43; // w8
  __int64 result; // x0
  __int64 v45; // x0
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  const char *v54; // x2
  const char *v55; // x2

  qdf_trace_msg(
    0x4Fu,
    8u,
    "%s: session:%d ch_freq:%d reason:%d",
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    a12,
    "policy_mgr_update_and_wait_for_connection_update",
    a2,
    a3,
    a4);
  context = policy_mgr_get_context(a1);
  if ( context )
  {
    if ( !(unsigned int)qdf_event_reset(context + 16) )
      goto LABEL_6;
    v25 = "%s: clear event failed";
  }
  else
  {
    v25 = "%s: Invalid context";
  }
  qdf_trace_msg(0x4Fu, 2u, v25, v17, v18, v19, v20, v21, v22, v23, v24, "policy_mgr_reset_connection_update");
  qdf_trace_msg(
    0x4Fu,
    2u,
    "%s: clearing event failed",
    v26,
    v27,
    v28,
    v29,
    v30,
    v31,
    v32,
    v33,
    "policy_mgr_update_and_wait_for_connection_update");
LABEL_6:
  v34 = policy_mgr_current_connections_update(a1, a2, a3, a4, 0);
  if ( v34 == 16 )
  {
    v55 = "%s: connections update failed";
  }
  else
  {
    v43 = v34;
    result = 0;
    if ( v43 )
      return result;
    v45 = policy_mgr_get_context(a1);
    if ( v45 )
    {
      result = qdf_wait_single_event(v45 + 16, 0x1770u);
      if ( !(_DWORD)result )
        return result;
      v54 = "%s: wait for event failed";
    }
    else
    {
      v54 = "%s: Invalid context";
    }
    qdf_trace_msg(0x4Fu, 2u, v54, v46, v47, v48, v49, v50, v51, v52, v53, "policy_mgr_wait_for_connection_update");
    v55 = "%s: qdf wait for event failed";
  }
  qdf_trace_msg(
    0x4Fu,
    2u,
    v55,
    v35,
    v36,
    v37,
    v38,
    v39,
    v40,
    v41,
    v42,
    "policy_mgr_update_and_wait_for_connection_update");
  return 16;
}
