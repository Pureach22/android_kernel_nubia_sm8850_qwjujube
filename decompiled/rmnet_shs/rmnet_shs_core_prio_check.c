__int64 __fastcall rmnet_shs_core_prio_check(unsigned __int8 a1, int a2)
{
  unsigned __int64 v2; // x27
  int v3; // w21
  __int64 v5; // x22
  unsigned int v7; // w24
  unsigned int v8; // w25
  __int64 result; // x0
  bool v10; // cf
  __int64 v11; // x20
  __int64 *v12; // x8
  _BYTE *v13; // x8
  int v14; // t1
  char *v15; // x19

  if ( (unsigned int)rmnet_shs_max_core_wait <= 1 )
    v3 = 1;
  else
    v3 = rmnet_shs_max_core_wait;
  if ( a1 >= 8u )
  {
    __break(0x5512u);
    _WriteStatusReg(ARM64_SYSREG(3, 2, 7, 10, 1), v2);
    return rmnet_shs_oom_notify();
  }
  else
  {
    v5 = a1;
    v7 = *((_DWORD *)&rmnet_shs_cfg + 30 * a1 + 120);
    v8 = rmnet_shs_cpu_inst_rate_max_pkts[a1];
    result = rmnet_shs_get_cpu_qdiff(a1);
    v10 = (unsigned int)(result + a2) >= rmnet_shs_cpu_backlog_max_pkts[v5];
    if ( (unsigned int)(result + a2) >= rmnet_shs_cpu_backlog_max_pkts[v5] )
      v11 = 5;
    else
      v11 = 4LL * (v7 >= v8);
    if ( v10 || v7 >= v8 )
    {
      result = rmnet_shs_is_lpwr_cpu(a1);
      if ( (_DWORD)result )
      {
        v12 = &rmnet_shs_cpu_node_tbl[5 * (unsigned int)v5];
        v14 = *((unsigned __int8 *)v12 + 36);
        v13 = (char *)v12 + 36;
        if ( !v14 && a1 != 1 && BYTE1(dword_19499) != a1 )
        {
          *v13 = 1;
          rmnet_shs_boost_cpus();
          v15 = (char *)&rmnet_shs_cfg + 120 * (unsigned int)v5;
          if ( (hrtimer_active(v15 + 368) & 1) != 0 )
            hrtimer_cancel(v15 + 368);
          result = hrtimer_start_range_ns(v15 + 368, (unsigned int)(1000000 * v3), 0, 1);
          ++rmnet_shs_switch_reason[v11];
        }
      }
    }
  }
  return result;
}
