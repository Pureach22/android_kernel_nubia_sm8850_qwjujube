__int64 __fastcall dp_fpm_display_policy(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x8
  unsigned __int64 StatusReg; // x9
  __int64 v11; // x26
  __int64 v12; // x27
  __int64 *i; // x28
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  int v22; // w8
  const char *v24; // x2

  if ( !a1 )
  {
    v24 = "%s: dp_intf is null";
    return qdf_trace_msg(0x45u, 2u, v24, a2, a3, a4, a5, a6, a7, a8, a9, "dp_fpm_display_policy");
  }
  v9 = *(_QWORD *)(a1 + 3712);
  if ( !v9 )
  {
    v24 = "%s: fpm_ctx is null";
    return qdf_trace_msg(0x45u, 2u, v24, a2, a3, a4, a5, a6, a7, a8, a9, "dp_fpm_display_policy");
  }
  StatusReg = _ReadStatusReg(SP_EL0);
  v11 = 0;
  *(_DWORD *)(StatusReg + 16) += 512;
  v12 = v9 + 16;
  do
  {
    for ( i = *(__int64 **)(v12 + 8 * v11); i; i = (__int64 *)*i )
    {
      qdf_trace_msg(
        0x45u,
        5u,
        "%s: policy_id:0x%llx prio:%u",
        a2,
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        "dp_fpm_display_policy",
        i[5],
        *((unsigned __int8 *)i + 32));
      a1 = qdf_trace_msg(
             0x45u,
             5u,
             "%s: pflags:0x%x flow_flags:0x%x svc_id:%u tid:%u",
             v14,
             v15,
             v16,
             v17,
             v18,
             v19,
             v20,
             v21,
             "dp_fpm_display_policy",
             *((unsigned int *)i + 24),
             *((unsigned int *)i + 22),
             *((unsigned __int8 *)i + 101),
             *((unsigned __int8 *)i + 100));
      v22 = *((_DWORD *)i + 22);
      if ( (v22 & 1) != 0 )
      {
        if ( (v22 & 4) != 0 )
        {
          a1 = qdf_trace_msg(
                 0x45u,
                 5u,
                 "%s: src_ip:0x%x",
                 a2,
                 a3,
                 a4,
                 a5,
                 a6,
                 a7,
                 a8,
                 a9,
                 "dp_fpm_display_policy",
                 *((unsigned int *)i + 12));
          v22 = *((_DWORD *)i + 22);
        }
        if ( (v22 & 4) != 0 )
        {
          a1 = qdf_trace_msg(
                 0x45u,
                 5u,
                 "%s: dst_ip:0x%x",
                 a2,
                 a3,
                 a4,
                 a5,
                 a6,
                 a7,
                 a8,
                 a9,
                 "dp_fpm_display_policy",
                 *((unsigned int *)i + 16));
          if ( (i[11] & 4) != 0 )
          {
            a1 = qdf_trace_msg(
                   0x45u,
                   5u,
                   "%s: srcport:%u",
                   a2,
                   a3,
                   a4,
                   a5,
                   a6,
                   a7,
                   a8,
                   a9,
                   "dp_fpm_display_policy",
                   *((unsigned __int16 *)i + 40));
            if ( (i[11] & 4) != 0 )
              a1 = qdf_trace_msg(
                     0x45u,
                     5u,
                     "%s: dstport:%u",
                     a2,
                     a3,
                     a4,
                     a5,
                     a6,
                     a7,
                     a8,
                     a9,
                     "dp_fpm_display_policy",
                     *((unsigned __int16 *)i + 41));
          }
        }
      }
    }
    ++v11;
  }
  while ( v11 != 8 );
  return local_bh_enable_3(a1);
}
