void *__fastcall ucfg_policy_mgr_psoc_close(__int64 a1)
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

  policy_mgr_psoc_close(a1);
  context = policy_mgr_get_context(a1);
  if ( context )
    return qdf_mem_set((void *)(context + 2200), 0x30u, 0);
  else
    return (void *)qdf_trace_msg(
                     0x4Fu,
                     2u,
                     "%s: pm_ctx is NULL",
                     v3,
                     v4,
                     v5,
                     v6,
                     v7,
                     v8,
                     v9,
                     v10,
                     "policy_mgr_deinit_cfg");
}
