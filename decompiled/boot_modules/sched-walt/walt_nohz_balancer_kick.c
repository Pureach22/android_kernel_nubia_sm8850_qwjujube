void __fastcall walt_nohz_balancer_kick(__int64 a1, __int64 a2, _DWORD *a3, _DWORD *a4)
{
  __int64 v4; // x8
  _QWORD *v5; // x9
  __int64 v6; // x8
  unsigned __int64 v7; // x10
  unsigned __int64 v8; // x9
  __int64 v9; // x8
  unsigned __int64 StatusReg; // x19
  __int64 v11; // x0
  __int64 v12; // x8

  if ( (walt_disabled & 1) == 0 )
  {
    *a4 = 1;
    if ( *(_DWORD *)(a2 + 4) >= 2u )
    {
      v4 = *(unsigned int *)(a2 + 3632);
      if ( (unsigned int)v4 >= 0x20
        || (v5 = &walt_rq[*((_QWORD *)&_per_cpu_offset + v4)],
            v6 = *(unsigned int *)(v5[1] + 32LL),
            (unsigned int)v6 >= 4) )
      {
        __break(0x5512u);
        StatusReg = _ReadStatusReg(SP_EL0);
        if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                         + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
            & 1) != 0 )
        {
          ++*(_DWORD *)(StatusReg + 16);
          v11 = _traceiter_walt_nohz_balance_kick(0, a2);
          v12 = *(_QWORD *)(StatusReg + 16) - 1LL;
          *(_DWORD *)(StatusReg + 16) = v12;
          if ( !v12 || !*(_QWORD *)(StatusReg + 16) )
            preempt_schedule_notrace(v11);
        }
      }
      else
      {
        v7 = v5[5];
        v8 = v5[79];
        v9 = (unsigned int)sched_capacity_margin_up[v6];
        if ( v7 >= v8 )
          v7 = v8;
        if ( v7 * v9 > v8 << 10 )
          *a3 = 11;
      }
    }
  }
}
