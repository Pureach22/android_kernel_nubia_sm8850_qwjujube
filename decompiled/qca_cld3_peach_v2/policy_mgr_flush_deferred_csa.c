__int64 __fastcall policy_mgr_flush_deferred_csa(__int64 a1, unsigned __int8 a2)
{
  __int64 context; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x22
  __int64 v14; // x19
  __int64 result; // x0
  const char *v16; // x2

  context = policy_mgr_get_context(a1);
  if ( !context )
  {
    v16 = "%s: Invalid context";
    return qdf_trace_msg(0x4Fu, 2u, v16, v5, v6, v7, v8, v9, v10, v11, v12, "policy_mgr_flush_deferred_csa");
  }
  v13 = *(_QWORD *)(context + 2096);
  v14 = context;
  if ( !v13 )
  {
    v16 = "%s: Invalid work_info context";
    return qdf_trace_msg(0x4Fu, 2u, v16, v5, v6, v7, v8, v9, v10, v11, v12, "policy_mgr_flush_deferred_csa");
  }
  result = wlan_mlme_is_aux_emlsr_support(a1);
  if ( (result & 1) != 0 )
  {
    qdf_mutex_acquire(v14 + 56);
    if ( *(_DWORD *)(v13 + 8) && (a2 == 255 || *(unsigned __int8 *)(v13 + 12) == a2) )
      qdf_mem_set((void *)(v13 + 8), 0x18u, 0);
    return qdf_mutex_release(v14 + 56);
  }
  return result;
}
