void *__fastcall policy_mgr_init_dbs_hw_mode(__int64 a1, unsigned int a2, const void *a3)
{
  __int64 context; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x21
  void *result; // x0

  context = policy_mgr_get_context(a1);
  if ( !context )
    return (void *)qdf_trace_msg(
                     0x4Fu,
                     2u,
                     "%s: Invalid Context",
                     v7,
                     v8,
                     v9,
                     v10,
                     v11,
                     v12,
                     v13,
                     v14,
                     "policy_mgr_init_dbs_hw_mode");
  v15 = context;
  *(_DWORD *)(context + 1184) = a2;
  result = (void *)_qdf_mem_malloc(8LL * a2, "policy_mgr_init_dbs_hw_mode", 2769);
  *(_QWORD *)(v15 + 1192) = result;
  if ( result )
  {
    qdf_mem_copy(result, a3, (unsigned int)(8 * *(_DWORD *)(v15 + 1184)));
    return (void *)policy_mgr_dump_dbs_hw_mode(a1);
  }
  else
  {
    *(_DWORD *)(v15 + 1184) = 0;
  }
  return result;
}
