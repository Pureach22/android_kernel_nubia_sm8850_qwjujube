__int64 __fastcall policy_mgr_get_first_connection_pcl_table_index(__int64 a1)
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

  context = policy_mgr_get_context(a1);
  if ( context )
  {
    if ( *(unsigned __int8 *)(context + 2104) <= 2u )
      return *(unsigned __int8 *)(context + 2104);
    else
      return 0;
  }
  else
  {
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: context is NULL",
      v2,
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      "policy_mgr_get_first_connection_pcl_table_index");
    return 0;
  }
}
