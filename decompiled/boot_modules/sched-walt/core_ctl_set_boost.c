__int64 __fastcall core_ctl_set_boost(char a1)
{
  __int64 v2; // x1
  _BOOL4 v3; // w22
  int v4; // w10
  unsigned int v5; // w19
  unsigned __int64 v6; // x24
  __int64 v7; // x23
  void *v8; // x20
  int v9; // w10
  int v10; // w10
  int v11; // w10
  unsigned __int64 v12; // x24
  __int64 v13; // x0
  unsigned __int64 StatusReg; // x20
  __int64 v16; // x0
  __int64 v17; // x8

  if ( (walt_disabled & 1) != 0 )
    return (unsigned int)-11;
  if ( initialized != 1 )
    return 0;
  v2 = raw_spin_lock_irqsave(&state_lock);
  if ( num_clusters )
  {
    v3 = dword_67F7C == 0;
    if ( (a1 & 1) != 0 )
    {
      v4 = dword_67F7C + 1;
      v5 = 0;
    }
    else
    {
      if ( !dword_67F7C )
      {
        v3 = 0;
        v5 = -22;
        if ( num_clusters == 1 )
          goto LABEL_10;
        goto LABEL_12;
      }
      v4 = dword_67F7C - 1;
      v5 = 0;
      v3 = dword_67F7C == 1;
    }
    dword_67F7C = v4;
    if ( num_clusters == 1 )
    {
LABEL_10:
      v7 = 0;
      v8 = &cluster_state;
LABEL_33:
      v6 = 1216;
      goto LABEL_34;
    }
LABEL_12:
    v9 = dword_680AC;
    if ( (a1 & 1) != 0 )
    {
      v5 = 0;
      v3 = dword_680AC++ == 0;
      if ( num_clusters == 2 )
      {
LABEL_14:
        v8 = &unk_68018;
        v7 = 304;
        goto LABEL_33;
      }
    }
    else if ( dword_680AC )
    {
      v5 = 0;
      --dword_680AC;
      v3 = v9 == 1;
      if ( num_clusters == 2 )
        goto LABEL_14;
    }
    else
    {
      v5 = -22;
      if ( num_clusters == 2 )
        goto LABEL_14;
    }
    v10 = dword_681DC;
    if ( (a1 & 1) != 0 )
    {
      v5 = 0;
      v3 = dword_681DC++ == 0;
      if ( num_clusters == 3 )
      {
LABEL_19:
        v8 = &unk_68148;
        v7 = 608;
        goto LABEL_33;
      }
    }
    else if ( dword_681DC )
    {
      v5 = 0;
      --dword_681DC;
      v3 = v10 == 1;
      if ( num_clusters == 3 )
        goto LABEL_19;
    }
    else
    {
      v5 = -22;
      if ( num_clusters == 3 )
        goto LABEL_19;
    }
    v11 = dword_6830C;
    if ( (a1 & 1) != 0 )
    {
      v5 = 0;
      v3 = dword_6830C++ == 0;
    }
    else if ( dword_6830C )
    {
      v5 = 0;
      --dword_6830C;
      v3 = v11 == 1;
    }
    else
    {
      v5 = -22;
    }
    if ( num_clusters != 4 )
      goto LABEL_49;
    v8 = &unk_68278;
    v7 = 912;
    goto LABEL_33;
  }
  v3 = 0;
  v5 = 0;
  v6 = 0;
  v7 = 0;
  v8 = nullptr;
LABEL_34:
  raw_spin_unlock_irqrestore(&state_lock, v2);
  if ( v3 && num_clusters )
  {
    v12 = 0;
    v7 = -304;
    while ( (_UNKNOWN *)((char *)&cluster_state + v7) != (_UNKNOWN *)-304LL )
    {
      if ( (eval_need((char *)&cluster_state + v7 + 304) & 1) != 0 )
      {
        v13 = raw_spin_lock_irqsave(&core_ctl_pending_lock);
        core_ctl_pending = 1;
        raw_spin_unlock_irqrestore(&core_ctl_pending_lock, v13);
        wake_up_process(core_ctl_thread);
      }
      ++v12;
      v7 += 304;
      if ( v12 >= (unsigned int)num_clusters )
      {
        v6 = 1216;
        goto LABEL_44;
      }
    }
    return v5;
  }
  if ( !v8 )
    return v5;
LABEL_44:
  if ( v6 < v7 + 148 || v6 - (v7 + 148) < 4 )
  {
LABEL_49:
    __break(1u);
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                     + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
        & 1) != 0 )
    {
      ++*(_DWORD *)(StatusReg + 16);
      v16 = _traceiter_core_ctl_set_boost(0, v2, v5);
      v17 = *(_QWORD *)(StatusReg + 16) - 1LL;
      *(_DWORD *)(StatusReg + 16) = v17;
      if ( !v17 || !*(_QWORD *)(StatusReg + 16) )
        preempt_schedule_notrace(v16);
    }
  }
  return v5;
}
