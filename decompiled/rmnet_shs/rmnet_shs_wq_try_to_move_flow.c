bool __fastcall rmnet_shs_wq_try_to_move_flow(unsigned __int16 a1, unsigned __int16 a2, int a3, unsigned int a4)
{
  int v5; // w20
  __int64 *v6; // x8
  __int64 v10; // x0
  __int64 lock; // x0
  __int64 v12; // x8
  _BOOL4 v13; // w15
  __int64 i; // x14
  __int64 v15; // x14
  __int64 v16; // x16
  _BOOL4 v17; // w19

  v5 = a1;
  if ( (a2 | (unsigned int)a1) >= 8 )
  {
    ++qword_1A440;
    return 0;
  }
  if ( (((rmnet_shs_halt_mask | (unsigned int)(unsigned __int8)byte_19496) >> a2) & 1) != 0
    || (_cpu_active_mask & (1LL << a2)) == 0 )
  {
    v6 = &qword_1A3A8;
LABEL_4:
    ++*v6;
    return 0;
  }
  if ( a1 == a2 || (_cpu_active_mask & (1LL << a2)) == 0 )
  {
    v6 = &qword_1A3B0;
    goto LABEL_4;
  }
  v10 = raw_spin_lock_bh(&rmnet_shs_ht_splock);
  lock = _rcu_read_lock(v10);
  v12 = 0;
  v13 = 0;
  _ReadStatusReg(SP_EL0);
  do
  {
    for ( i = rmnet_shs_ht[v12]; i; i = *(_QWORD *)(v15 + 128) )
    {
      v15 = i - 128;
      if ( !v15 )
        break;
      if ( *(_QWORD *)(v15 + 88) )
      {
        v16 = *(_QWORD *)(v15 + 88);
        if ( (!a3 || *(_DWORD *)(v16 + 300) == a3) && *(unsigned __int16 *)(v16 + 318) == v5 )
        {
          *(_WORD *)(*(_QWORD *)(v15 + 88) + 316LL) = a2;
          if ( a4 <= 6 )
          {
            if ( v16 )
              ++*(_QWORD *)(v16 + 8LL * a4);
          }
          v13 = 1;
          if ( a3 )
            goto LABEL_25;
        }
      }
    }
    ++v12;
  }
  while ( v12 != 512 );
  v13 = v13;
LABEL_25:
  v17 = v13;
  _rcu_read_unlock(lock);
  raw_spin_unlock_bh(&rmnet_shs_ht_splock);
  return v17;
}
