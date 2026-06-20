_QWORD *__fastcall cfg80211_mgmt_registrations_update(_QWORD *result)
{
  _QWORD *v1; // x20
  __int64 v2; // x22
  __int64 v3; // x19
  __int64 v4; // x0
  __int64 lock; // x0
  _QWORD *v6; // x8
  int v7; // w10
  int v8; // w11
  int v9; // w12
  int v10; // w13
  __int64 *i; // x16
  int v12; // w1
  _DWORD *v13; // x8
  unsigned __int64 StatusReg; // x21
  __int64 v15; // x1
  __int64 v16; // x2
  __int64 v17; // x8
  __int64 v18; // [xsp+8h] [xbp-18h] BYREF
  __int64 v19; // [xsp+10h] [xbp-10h]
  __int64 v20; // [xsp+18h] [xbp-8h]

  v20 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *result;
  if ( *result )
  {
    v1 = result;
    v18 = 0;
    v19 = 0;
    v4 = raw_spin_lock_bh(v3 - 80);
    if ( (v1[8] & 1) == 0 )
    {
      result = (_QWORD *)raw_spin_unlock_bh(v3 - 80);
      goto LABEL_20;
    }
    v2 = v3 - 992;
    lock = _rcu_read_lock(v4);
    v6 = *(_QWORD **)(v3 + 1336);
    if ( v6 != (_QWORD *)(v3 + 1336) )
    {
      v7 = 0;
      v8 = 0;
      v9 = 0;
      v10 = 0;
      do
      {
        for ( i = (__int64 *)v6[4]; i != v6 + 4; i = (__int64 *)*i )
        {
          lock = 1LL << ((unsigned __int64)*((unsigned __int16 *)i + 16) >> 4);
          if ( *((_BYTE *)i + 34) )
            v12 = 1LL << ((unsigned __int64)*((unsigned __int16 *)i + 16) >> 4);
          else
            v12 = 0;
          v10 |= lock;
          v9 |= v12;
          LODWORD(v18) = v10;
          LODWORD(v19) = v9;
          if ( v6 - 2 == v1 )
          {
            v8 |= lock;
            v7 |= v12;
            HIDWORD(v18) = v8;
            HIDWORD(v19) = v7;
          }
        }
        v6 = (_QWORD *)*v6;
      }
      while ( v6 != (_QWORD *)(v3 + 1336) );
    }
    _rcu_read_unlock(lock);
    *((_BYTE *)v1 + 64) &= ~1u;
    result = (_QWORD *)raw_spin_unlock_bh(v3 - 80);
  }
  else
  {
    __break(0x800u);
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                     + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
        & 1) != 0 )
    {
      ++*(_DWORD *)(StatusReg + 16);
      result = (_QWORD *)_traceiter_rdev_update_mgmt_frame_registrations(0, 0, v1, &v18);
      v17 = *(_QWORD *)(StatusReg + 16) - 1LL;
      *(_DWORD *)(StatusReg + 16) = v17;
      if ( !v17 || !*(_QWORD *)(StatusReg + 16) )
        result = (_QWORD *)preempt_schedule_notrace(result, v15, v16);
    }
  }
  v13 = *(_DWORD **)(*(_QWORD *)v2 + 568LL);
  if ( v13 )
  {
    if ( *(v13 - 1) != 1317986418 )
      __break(0x8228u);
    result = (_QWORD *)((__int64 (__fastcall *)(__int64, _QWORD *, __int64 *))v13)(v3, v1, &v18);
  }
LABEL_20:
  _ReadStatusReg(SP_EL0);
  return result;
}
