__int64 __fastcall rmnet_shs_flush_core_work(__int64 a1)
{
  unsigned int v1; // w19
  int cpu_qtail; // w0
  __int64 v3; // x3
  __int64 v4; // x4
  __int64 *v5; // x24
  __int64 v6; // x26
  int v7; // w20
  unsigned int v8; // w25
  __int64 v9; // x21
  int v10; // w28
  __int64 *v11; // x27
  int v12; // w23
  __int64 v13; // x20
  __int64 v14; // x8
  __int64 v15; // x9
  __int64 result; // x0
  unsigned __int64 StatusReg; // x20
  __int64 v18; // x0
  __int64 v19; // x8

  v1 = *(unsigned __int8 *)(a1 + 52);
  rmnet_shs_update_cpu_proc_q_all_cpus();
  while ( 1 )
  {
    raw_spin_lock_bh(&rmnet_shs_ht_splock);
    cpu_qtail = rmnet_shs_get_cpu_qtail(v1);
    if ( v1 < 8 )
      break;
    __break(0x5512u);
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                     + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
        & 1) != 0 )
    {
      ++*(_DWORD *)(StatusReg + 16);
      v18 = _traceiter_rmnet_shs_high(0, 8, 39, v3, v4, 3567, 3567, 0);
      v19 = *(_QWORD *)(StatusReg + 16) - 1LL;
      *(_DWORD *)(StatusReg + 16) = v19;
      if ( !v19 || !*(_QWORD *)(StatusReg + 16) )
        preempt_schedule_notrace(v18);
    }
  }
  v5 = &rmnet_shs_cpu_node_tbl[5 * v1];
  v6 = *v5;
  if ( (__int64 *)*v5 == v5 )
  {
    v9 = 0;
    v13 = 0;
  }
  else
  {
    v7 = cpu_qtail;
    v8 = 0;
    LODWORD(v9) = 0;
    do
    {
      v10 = *(_DWORD *)(v6 + 56);
      v11 = *(__int64 **)v6;
      if ( v10 )
      {
        v12 = *(_DWORD *)(v6 + 48);
        rmnet_shs_chk_and_flush_node(v6 - 64, 7, 1, 0);
        LODWORD(v9) = v10 + v9;
        v8 += v12;
        if ( *(unsigned __int16 *)(v6 + 146) == v1 )
        {
          v7 += v10;
          *(_DWORD *)(v6 + 124) = v7;
        }
      }
      v6 = (__int64)v11;
    }
    while ( v11 != v5 );
    v13 = v8;
    v9 = (unsigned int)v9;
  }
  v14 = qword_19460;
  v15 = qword_19468;
  *((_BYTE *)v5 + 36) = 0;
  *((_DWORD *)v5 + 7) = 0;
  qword_19460 = v14 - v13;
  qword_19468 = v15 - v9;
  *((_DWORD *)&rmnet_shs_cfg + 30 * v1 + 120) = 0;
  result = raw_spin_unlock_bh(&rmnet_shs_ht_splock);
  if ( BYTE1(dword_19499) == v1 )
  {
    result = rmnet_module_hook_is_set(4);
    if ( (result & 1) != 0 )
    {
      result = rmnet_shs_switch_disable();
      word_1948C = 0;
      BYTE1(dword_19499) = BYTE2(dword_19499);
    }
  }
  ++qword_1A300;
  return result;
}
