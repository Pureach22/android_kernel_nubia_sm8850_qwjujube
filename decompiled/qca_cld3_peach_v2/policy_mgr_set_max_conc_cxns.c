__int64 __fastcall policy_mgr_set_max_conc_cxns(__int64 a1, unsigned int a2)
{
  __int64 context; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 v12; // x20

  context = policy_mgr_get_context(a1);
  if ( context )
  {
    v12 = context;
    qdf_trace_msg(
      0x4Fu,
      8u,
      "%s: set max_conc_cxns %d old %d",
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      "policy_mgr_set_max_conc_cxns",
      a2,
      *(unsigned __int8 *)(context + 2202));
    *(_BYTE *)(v12 + 2202) = a2;
    return 0;
  }
  else
  {
    qdf_trace_msg(0x4Fu, 2u, "%s: pm_ctx is NULL", v4, v5, v6, v7, v8, v9, v10, v11, "policy_mgr_set_max_conc_cxns");
    return 16;
  }
}
