__int64 __fastcall sysstats_task_foreach(__int64 a1, __int64 a2)
{
  unsigned __int64 StatusReg; // x28
  __int64 active; // x23
  __int64 v6; // x0
  int v7; // w20
  __int64 tgid; // x0
  __int64 v9; // x1
  int v10; // w22
  __int64 v11; // x21
  __int64 v12; // x1
  int v13; // w8
  __int64 v14; // x24
  __int64 v15; // x0
  __int64 v16; // x26
  __int64 v17; // x0
  __int64 v18; // x27
  __int64 v19; // x0
  __int64 v20; // x0
  __int64 unlock; // x0
  __int64 lock; // x0
  __int64 v23; // x8
  _QWORD *v24; // x22
  __int64 v25; // x0
  _QWORD *v26; // x20
  __int64 v27; // x25
  _QWORD *v28; // x20
  __int64 v29; // x0
  int v30; // w28
  int v38; // w8
  int v40; // w9
  unsigned __int64 v41; // x8
  unsigned __int64 v42; // x9
  unsigned __int64 v44; // [xsp+8h] [xbp-28h]
  __int64 v45; // [xsp+10h] [xbp-20h]
  int v46; // [xsp+18h] [xbp-18h]
  int v47; // [xsp+1Ch] [xbp-14h]

  _ReadStatusReg(SP_EL0);
  StatusReg = _ReadStatusReg(SP_EL0);
  active = task_active_pid_ns(StatusReg);
  v6 = nla_find(*(_QWORD *)(a2 + 8) + 20LL, (unsigned int)(**(_DWORD **)(a2 + 8) - 20), 2);
  if ( !v6 )
    goto LABEL_50;
  v7 = *(_DWORD *)(v6 + 4);
  tgid = next_tgid(active, *(unsigned int *)(a2 + 80), 0);
  if ( !v9 )
    goto LABEL_49;
  v10 = (__int16)v7;
  v11 = v9;
  v44 = StatusReg;
  v45 = a2;
  v47 = v7 >> 16;
  v46 = (__int16)v7;
  while ( 1 )
  {
    if ( (*(_BYTE *)(v11 + 70) & 0x20) != 0 )
      goto LABEL_6;
    v13 = *(__int16 *)(*(_QWORD *)(v11 + 2392) + 954LL);
    if ( v10 > v13 || v47 < v13 )
      goto LABEL_6;
    v14 = tgid;
    v15 = genlmsg_put(
            a1,
            *(unsigned int *)(*(_QWORD *)a2 + 52LL),
            *(unsigned int *)(*(_QWORD *)(a2 + 8) + 8LL),
            &family,
            0,
            1);
    if ( !v15 )
    {
      _X0 = (unsigned int *)(v11 + 64);
      __asm { PRFM            #0x11, [X0] }
      do
        v38 = __ldxr(_X0);
      while ( __stlxr(v38 - 1, _X0) );
      if ( v38 == 1 )
      {
        __dmb(9u);
        _put_task_struct(v11);
      }
      else if ( v38 <= 0 )
      {
        refcount_warn_saturate(_X0, 3);
      }
      goto LABEL_48;
    }
    v16 = v15;
    v17 = nla_reserve(a1, 3, 152);
    if ( !v17 )
      break;
    v18 = v17;
    *(_QWORD *)(v17 + 148) = 0;
    *(_QWORD *)(v17 + 140) = 0;
    *(_QWORD *)(v17 + 132) = 0;
    *(_QWORD *)(v17 + 124) = 0;
    *(_QWORD *)(v17 + 116) = 0;
    *(_QWORD *)(v17 + 108) = 0;
    *(_QWORD *)(v17 + 100) = 0;
    *(_QWORD *)(v17 + 92) = 0;
    *(_QWORD *)(v17 + 84) = 0;
    *(_QWORD *)(v17 + 76) = 0;
    *(_QWORD *)(v17 + 68) = 0;
    *(_QWORD *)(v17 + 60) = 0;
    *(_QWORD *)(v17 + 52) = 0;
    *(_QWORD *)(v17 + 44) = 0;
    *(_QWORD *)(v17 + 36) = 0;
    *(_QWORD *)(v17 + 28) = 0;
    *(_QWORD *)(v17 + 20) = 0;
    *(_QWORD *)(v17 + 12) = 0;
    *(_QWORD *)(v17 + 4) = 0;
    _rcu_read_lock(v17);
    v19 = task_active_pid_ns(StatusReg);
    v20 = _task_pid_nr_ns(v11, 0, v19);
    *(_DWORD *)(v18 + 80) = v20;
    *(_WORD *)(v18 + 76) = *(_WORD *)(*(_QWORD *)(v11 + 2392) + 954LL);
    unlock = _rcu_read_unlock(v20);
    lock = _rcu_read_lock(unlock);
    v23 = *(_QWORD *)(v11 + 2392);
    v24 = *(_QWORD **)(v23 + 16);
    if ( v24 == (_QWORD *)(v23 + 16) )
    {
LABEL_15:
      _rcu_read_unlock(lock);
    }
    else
    {
      while ( 1 )
      {
        v25 = raw_spin_lock(v24 + 70);
        v26 = v24 - 38;
        if ( *(v24 - 38) )
          break;
        lock = raw_spin_unlock(v24 + 70);
        v24 = (_QWORD *)*v24;
        if ( v24 == (_QWORD *)(*(_QWORD *)(v11 + 2392) + 16LL) )
          goto LABEL_15;
      }
      _rcu_read_unlock(v25);
      if ( v24 != (_QWORD *)1976 )
      {
        v27 = 0;
        *(_QWORD *)(v18 + 4) = 4 * (*(_QWORD *)(*v26 + 848LL) & ~(*(__int64 *)(*v26 + 848LL) >> 63));
        *(_QWORD *)(v18 + 12) = 4 * (*(_QWORD *)(*v26 + 808LL) & ~(*(__int64 *)(*v26 + 808LL) >> 63));
        *(_QWORD *)(v18 + 28) = 4 * (*(_QWORD *)(*v26 + 928LL) & ~(*(__int64 *)(*v26 + 928LL) >> 63));
        *(_QWORD *)(v18 + 20) = 4 * (*(_QWORD *)(*v26 + 888LL) & ~(*(__int64 *)(*v26 + 888LL) >> 63));
        v28 = (_QWORD *)(v24[52] + 16LL);
        while ( 1 )
        {
          v28 = (_QWORD *)*v28;
          if ( v28 == (_QWORD *)(v24[52] + 16LL) )
          {
LABEL_4:
            *(_QWORD *)(v18 + 36) = 0;
            raw_spin_unlock(v24 + 70);
            StatusReg = v44;
            a2 = v45;
            break;
          }
          if ( v28 != v24 )
            raw_spin_lock(v28 + 70);
          if ( v27 )
          {
            v29 = v28[49];
            if ( !v29 )
              goto LABEL_28;
          }
          else
          {
            v27 = *(_QWORD *)(*(v24 - 14) + 2368LL);
            v29 = v28[49];
            if ( !v29 )
              goto LABEL_28;
          }
          if ( v27 != v29 || v28 - 247 == (_QWORD *)*(v24 - 14) )
          {
            v30 = iterate_fd();
            if ( v28 == v24 )
              goto LABEL_18;
LABEL_29:
            raw_spin_unlock(v28 + 70);
            goto LABEL_18;
          }
LABEL_28:
          v30 = 0;
          if ( v28 != v24 )
            goto LABEL_29;
LABEL_18:
          if ( v30 )
            goto LABEL_4;
        }
      }
    }
    v10 = v46;
    tgid = v14;
    *(_DWORD *)(v16 - 20) = *(_DWORD *)(a1 + 216) + *(_DWORD *)(a1 + 208) - (v16 - 20);
LABEL_6:
    tgid = next_tgid(active, (unsigned int)(tgid + 1) | tgid & 0xFFFFFFFF00000000LL, v11);
    v11 = v12;
    if ( !v12 )
      goto LABEL_49;
  }
  _X8 = (unsigned int *)(v11 + 64);
  __asm { PRFM            #0x11, [X8] }
  do
    v40 = __ldxr(_X8);
  while ( __stlxr(v40 - 1, _X8) );
  if ( v40 == 1 )
  {
    __dmb(9u);
    _put_task_struct(v11);
  }
  else
  {
    LODWORD(tgid) = v14;
    if ( v40 > 0 )
      goto LABEL_44;
    refcount_warn_saturate(v11 + 64, 3);
  }
  LODWORD(tgid) = v14;
LABEL_44:
  v41 = v16 - 20;
  if ( v16 == 20 )
    goto LABEL_49;
  v42 = *(_QWORD *)(a1 + 224);
  if ( v42 > v41 )
  {
    __break(0x800u);
    v42 = *(_QWORD *)(a1 + 224);
  }
  skb_trim(a1, (unsigned int)(v41 - v42));
LABEL_48:
  LODWORD(tgid) = v14;
LABEL_49:
  *(_QWORD *)(a2 + 80) = (unsigned int)tgid;
LABEL_50:
  _ReadStatusReg(SP_EL0);
  return *(unsigned int *)(a1 + 112);
}
