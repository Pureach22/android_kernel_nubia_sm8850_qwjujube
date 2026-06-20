__int64 __fastcall sched_set_boost(__int64 result)
{
  __int64 v1; // x9
  unsigned int v2; // w8
  int v3; // w11
  __int64 (*v4)(void); // x8
  int v5; // w1
  int *v6; // x9
  bool v7; // zf
  unsigned int v8; // w19
  __int64 (*v9)(void); // x8
  __int64 v10; // x0
  __int64 (__fastcall *v11)(_QWORD); // x8
  int v12; // w1
  int v13; // w8
  unsigned __int64 StatusReg; // x19
  __int64 v15; // x8

  if ( !(_DWORD)result )
  {
    if ( !sched_boost_type )
      goto LABEL_35;
    if ( (unsigned int)sched_boost_type < 6 )
    {
      v4 = *((__int64 (**)(void))&sched_boosts + 3 * (unsigned int)sched_boost_type + 2);
      if ( *((_DWORD *)v4 - 1) != -440107680 )
        __break(0x8228u);
      result = v4();
      v5 = 0;
      dword_1838 = 0;
      dword_1850 = 0;
      dword_1868 = 0;
      dword_1880 = 0;
      dword_1898 = 0;
      goto LABEL_43;
    }
    goto LABEL_51;
  }
  if ( (int)result >= 1 )
  {
    if ( (unsigned int)result < 7 )
    {
      if ( (_DWORD)result != 6 )
      {
        v1 = 24LL * (unsigned int)result;
        v2 = sched_boost_type;
        v3 = *(_DWORD *)((char *)&sched_boosts + v1);
        *(_DWORD *)((char *)&sched_boosts + v1) = v3 + 1;
        if ( v3 )
          goto LABEL_35;
LABEL_17:
        if ( dword_1838 <= 0 )
        {
          if ( dword_1850 <= 0 )
          {
            if ( dword_1868 <= 0 )
            {
              if ( dword_1880 <= 0 )
              {
                if ( dword_1898 <= 0 )
                  v8 = 0;
                else
                  v8 = 5;
              }
              else
              {
                v8 = 4;
              }
            }
            else
            {
              v8 = 3;
            }
          }
          else
          {
            v8 = 2;
          }
        }
        else
        {
          v8 = 1;
        }
        if ( v8 == v2 )
          goto LABEL_35;
        if ( v2 < 6 )
        {
          v9 = *((__int64 (**)(void))&sched_boosts + 3 * v2 + 2);
          if ( *((_DWORD *)v9 - 1) != -440107680 )
            __break(0x8228u);
          v10 = v9();
          v11 = *((__int64 (__fastcall **)(_QWORD))&sched_boosts + 3 * v8 + 1);
          if ( *((_DWORD *)v11 - 1) != -440107680 )
            __break(0x8228u);
          result = v11(v10);
LABEL_35:
          v12 = 1;
          if ( dword_1838 > 0 )
            goto LABEL_38;
          if ( dword_1850 > 0 )
          {
            v12 = 2;
            goto LABEL_38;
          }
          if ( dword_1868 > 0 )
          {
            v5 = 3;
LABEL_43:
            v13 = 0;
            sched_boost_type = v5;
            sysctl_sched_boost = v5;
LABEL_44:
            boost_policy = v13;
            return result;
          }
          if ( dword_1880 <= 0 )
          {
            if ( dword_1898 <= 0 )
            {
              v5 = 0;
              goto LABEL_43;
            }
            v12 = 5;
          }
          else
          {
            v12 = 4;
          }
LABEL_38:
          sched_boost_type = v12;
          sysctl_sched_boost = v12;
          if ( max_possible_cluster_id == min_possible_cluster_id )
            v13 = 2;
          else
            v13 = 1;
          goto LABEL_44;
        }
        goto LABEL_51;
      }
      goto LABEL_52;
    }
LABEL_51:
    __break(0x5512u);
    goto LABEL_52;
  }
  if ( (unsigned int)-(int)result >= 7 )
    goto LABEL_51;
  if ( (_DWORD)result != -6 )
  {
    v6 = (int *)((char *)&sched_boosts + 24 * (unsigned int)-(int)result);
    v7 = *v6 == 1;
    if ( *v6 < 1 )
      goto LABEL_35;
    --*v6;
    v2 = sched_boost_type;
    if ( !v7 )
      goto LABEL_35;
    goto LABEL_17;
  }
LABEL_52:
  __break(1u);
  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    result = _traceiter_sched_set_boost(0);
    v15 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v15;
    if ( !v15 || !*(_QWORD *)(StatusReg + 16) )
      return preempt_schedule_notrace(result);
  }
  return result;
}
