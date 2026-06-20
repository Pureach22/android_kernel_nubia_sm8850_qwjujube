__int64 __fastcall policy_mgr_update_flow_pool_map(
        __int64 result,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  unsigned int v10; // w19
  __int64 v11; // x8
  __int64 v12; // x20
  __int64 v13; // x21
  __int64 context; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x22
  int v24; // w23
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  __int64 (__fastcall *v41)(_QWORD); // x8

  if ( !a2 )
    return result;
  v10 = *(unsigned __int8 *)(a2 + 168);
  if ( (*(_BYTE *)(a2 + 67) & 2) != 0 )
    return qdf_trace_msg(
             0x4Fu,
             8u,
             "%s: vdev:%d Link switch/set_link is ongoing, don't update flow pool map",
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             "policy_mgr_update_flow_pool_map",
             v10);
  v11 = *(_QWORD *)(a2 + 216);
  if ( v11 )
  {
    v12 = result;
    v13 = a2;
    context = policy_mgr_get_context(*(_QWORD *)(v11 + 80));
    if ( context )
      goto LABEL_5;
  }
  else
  {
    v12 = result;
    v13 = a2;
    context = policy_mgr_get_context(0);
    if ( context )
    {
LABEL_5:
      v23 = context;
      qdf_mutex_acquire(context + 56);
      v24 = *(_DWORD *)(v23 + 2664);
      qdf_mutex_release(v23 + 56);
      if ( v24 )
      {
        qdf_trace_msg(
          0x4Fu,
          8u,
          "%s: set_link_in_progress %d",
          v25,
          v26,
          v27,
          v28,
          v29,
          v30,
          v31,
          v32,
          "policy_mgr_get_link_in_progress",
          1);
        return qdf_trace_msg(
                 0x4Fu,
                 8u,
                 "%s: vdev:%d Link switch/set_link is ongoing, don't update flow pool map",
                 a3,
                 a4,
                 a5,
                 a6,
                 a7,
                 a8,
                 a9,
                 a10,
                 "policy_mgr_update_flow_pool_map",
                 v10);
      }
      goto LABEL_11;
    }
  }
  qdf_trace_msg(
    0x4Fu,
    2u,
    "%s: Invalid Context",
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    "policy_mgr_is_set_link_in_progress");
LABEL_11:
  result = policy_mgr_get_context(v12);
  if ( !result )
    return qdf_trace_msg(
             0x4Fu,
             2u,
             "%s: pm_ctx is NULL",
             v33,
             v34,
             v35,
             v36,
             v37,
             v38,
             v39,
             v40,
             "policy_mgr_update_flow_pool_map");
  if ( *(_DWORD *)(v13 + 16) != 16 )
  {
    v41 = *(__int64 (__fastcall **)(_QWORD))(result + 512);
    if ( v41 )
    {
      if ( *((_DWORD *)v41 - 1) != 1162514891 )
        __break(0x8228u);
      return v41(v10);
    }
  }
  return result;
}
