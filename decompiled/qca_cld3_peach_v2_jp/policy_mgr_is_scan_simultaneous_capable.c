__int64 __fastcall policy_mgr_is_scan_simultaneous_capable(__int64 a1)
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
  unsigned int v11; // w8
  char is_hw_dbs_capable; // w0

  context = policy_mgr_get_context(a1);
  if ( context )
  {
    v11 = *(unsigned __int8 *)(context + 2207);
    if ( v11 <= 6 && ((1 << v11) & 0x62) != 0 )
      is_hw_dbs_capable = 0;
    else
      is_hw_dbs_capable = policy_mgr_is_hw_dbs_capable(a1);
  }
  else
  {
    qdf_trace_msg(0x4Fu, 2u, "%s: pm_ctx is NULL", v3, v4, v5, v6, v7, v8, v9, v10, "policy_mgr_get_dual_mac_feature");
    is_hw_dbs_capable = 0;
  }
  return is_hw_dbs_capable & 1;
}
