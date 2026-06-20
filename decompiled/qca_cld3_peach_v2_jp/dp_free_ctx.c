__int64 dp_free_ctx()
{
  __int64 v0; // x19
  double v1; // d0
  double v2; // d1
  double v3; // d2
  double v4; // d3
  double v5; // d4
  double v6; // d5
  double v7; // d6
  double v8; // d7

  v0 = gp_dp_ctx;
  wlan_dp_spm_flow_table_detach(gp_dp_ctx);
  if ( *(_DWORD *)(v0 + 296) )
    qdf_trace_msg(0x33u, 2u, "%s: list length not equal to zero", v1, v2, v3, v4, v5, v6, v7, v8, "qdf_list_destroy");
  if ( gp_dp_ctx )
    gp_dp_ctx = 0;
  else
    qdf_trace_msg(0x45u, 2u, "%s: global dp ctx is already detached", v1, v2, v3, v4, v5, v6, v7, v8, "dp_detach_ctx");
  return _qdf_mem_free(v0);
}
