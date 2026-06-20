__int64 dp_svc_dump()
{
  __int64 context; // x0
  double v1; // d0
  double v2; // d1
  double v3; // d2
  double v4; // d3
  double v5; // d4
  double v6; // d5
  double v7; // d6
  double v8; // d7
  __int64 v9; // x21
  unsigned __int64 StatusReg; // x8
  __int64 v11; // x22
  __int64 v12; // x8
  __int64 v14; // [xsp+0h] [xbp-10h]

  context = dp_get_context();
  if ( !context )
    return qdf_trace_msg(0x45u, 2u, "%s: svc_ctx is not initialised", v1, v2, v3, v4, v5, v6, v7, v8, "dp_svc_dump");
  v9 = *(_QWORD *)(context + 1552);
  if ( !v9 )
    return qdf_trace_msg(0x45u, 2u, "%s: svc_ctx is not initialised", v1, v2, v3, v4, v5, v6, v7, v8, "dp_svc_dump");
  StatusReg = _ReadStatusReg(SP_EL0);
  v11 = 0;
  *(_DWORD *)(StatusReg + 16) += 512;
  do
  {
    v12 = *(_QWORD *)(v9 + v11);
    if ( v12 )
    {
      LODWORD(v14) = *(unsigned __int8 *)(v12 + 17);
      qdf_trace_msg(
        0x45u,
        5u,
        "%s: svc_id:%d buffer_latency_tolerance:%d app_ind_default_dscp:%d app_ind_special_dscp:%d policy_ref_count:%d",
        v1,
        v2,
        v3,
        v4,
        v5,
        v6,
        v7,
        v8,
        "dp_svc_dump",
        *(unsigned __int8 *)(v12 + 16),
        *(unsigned int *)(v12 + 20),
        *(unsigned __int8 *)(v12 + 24),
        *(unsigned __int8 *)(v12 + 25),
        v14);
    }
    v11 += 8;
  }
  while ( v11 != 256 );
  return local_bh_enable_5();
}
