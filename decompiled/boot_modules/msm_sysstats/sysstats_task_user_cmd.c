__int64 __fastcall sysstats_task_user_cmd(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  __int64 v4; // x21
  unsigned int v5; // w20
  __int64 v6; // x0
  __int64 v7; // x22
  __int64 task_by_vpid; // x0
  __int64 v9; // x20
  unsigned __int64 StatusReg; // x23
  __int64 active; // x0
  __int64 v13; // x0
  __int64 v14; // x8
  _QWORD *v15; // x26
  __int64 v16; // x0
  _QWORD *v17; // x24
  unsigned int v18; // w19
  __int64 v19; // x27
  _QWORD *v20; // x28
  __int64 v21; // x0
  int v22; // w25
  __int64 v23; // x0
  __int64 (__fastcall *v24)(__int64); // x8
  unsigned __int64 v25; // x9
  __int64 v26; // x0
  __int64 v27; // x24
  __int64 v28; // x0
  __int64 v29; // x25
  __int64 unlock; // x0
  __int64 v31; // x8
  int v32; // w8
  __int64 v33; // x24
  __int64 v34; // x0
  __int64 v35; // x0
  size_t v36; // x0
  unsigned __int64 v37; // x2
  __int64 v38; // x0
  __int64 lock; // x0
  __int64 v40; // x24
  __int64 v41; // x0
  __int64 v42; // x8
  unsigned __int64 v44; // x9
  unsigned __int64 v50; // x11
  unsigned __int64 *v51; // x8
  unsigned __int64 v52; // x11
  __int64 v53; // x8
  __int64 v54; // x0
  __int64 v55; // x0
  __int64 v56; // x8
  unsigned __int64 *v57; // x8
  unsigned __int64 v58; // x11
  __int64 v59; // x8
  __int64 v60; // x1
  __int64 (*v62)(void); // x8
  unsigned int v64; // w8
  int v66; // w8
  __int64 v67; // x1
  int v68; // w0
  unsigned __int64 v70; // x9
  unsigned __int64 v71; // x9
  __int64 v72; // [xsp+8h] [xbp-18h] BYREF
  unsigned __int64 v73; // [xsp+10h] [xbp-10h]
  __int64 v74; // [xsp+18h] [xbp-8h]

  v74 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !*(_QWORD *)(*(_QWORD *)(a2 + 32) + 8LL) )
  {
    result = 4294967274LL;
    goto LABEL_96;
  }
  v72 = 0;
  result = prepare_reply(a2, 2, &v72, 156);
  if ( (result & 0x80000000) == 0 )
  {
    v4 = v72;
    v5 = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a2 + 32) + 8LL) + 4LL);
    v6 = nla_reserve_64bit(v72, 1, 152, 2);
    if ( v6 )
    {
      v7 = v6;
      ((void (*)(void))_rcu_read_lock)();
      task_by_vpid = find_task_by_vpid(v5);
      if ( task_by_vpid )
      {
        v9 = task_by_vpid;
        _X21 = (unsigned int *)(task_by_vpid + 64);
        while ( 1 )
        {
          __asm { PRFM            #0x11, [X21] }
          do
            v64 = __ldxr(_X21);
          while ( __stxr(v64 + 1, _X21) );
          if ( !v64 )
            break;
          if ( (((v64 + 1) | v64) & 0x80000000) != 0 )
          {
            v60 = 1;
LABEL_90:
            refcount_warn_saturate(_X21, v60);
          }
          ((void (*)(void))_rcu_read_unlock)();
          StatusReg = _ReadStatusReg(SP_EL0);
          *(_QWORD *)(v7 + 148) = 0;
          *(_QWORD *)(v7 + 140) = 0;
          *(_QWORD *)(v7 + 132) = 0;
          *(_QWORD *)(v7 + 124) = 0;
          *(_QWORD *)(v7 + 116) = 0;
          *(_QWORD *)(v7 + 108) = 0;
          *(_QWORD *)(v7 + 100) = 0;
          *(_QWORD *)(v7 + 92) = 0;
          *(_QWORD *)(v7 + 84) = 0;
          *(_QWORD *)(v7 + 76) = 0;
          *(_QWORD *)(v7 + 68) = 0;
          *(_QWORD *)(v7 + 60) = 0;
          *(_QWORD *)(v7 + 52) = 0;
          *(_QWORD *)(v7 + 44) = 0;
          *(_QWORD *)(v7 + 36) = 0;
          *(_QWORD *)(v7 + 28) = 0;
          *(_QWORD *)(v7 + 20) = 0;
          *(_QWORD *)(v7 + 12) = 0;
          *(_QWORD *)(v7 + 4) = 0;
          active = task_active_pid_ns(StatusReg);
          *(_DWORD *)(v7 + 80) = _task_pid_nr_ns(v9, 0, active);
          v13 = ((__int64 (*)(void))_rcu_read_lock)();
          v14 = *(_QWORD *)(v9 + 2392);
          v15 = *(_QWORD **)(v14 + 16);
          if ( v15 == (_QWORD *)(v14 + 16) )
          {
LABEL_10:
            _rcu_read_unlock(v13);
            goto LABEL_32;
          }
          while ( 1 )
          {
            v16 = raw_spin_lock(v15 + 70);
            v17 = v15 - 38;
            if ( *(v15 - 38) )
              break;
            v13 = raw_spin_unlock(v15 + 70);
            v15 = (_QWORD *)*v15;
            if ( v15 == (_QWORD *)(*(_QWORD *)(v9 + 2392) + 16LL) )
              goto LABEL_10;
          }
          _rcu_read_unlock(v16);
          if ( v15 == (_QWORD *)1976 )
            goto LABEL_32;
          v19 = 0;
          *(_QWORD *)(v7 + 4) = 4 * (*(_QWORD *)(*v17 + 848LL) & ~(*(__int64 *)(*v17 + 848LL) >> 63));
          *(_QWORD *)(v7 + 12) = 4 * (*(_QWORD *)(*v17 + 808LL) & ~(*(__int64 *)(*v17 + 808LL) >> 63));
          *(_QWORD *)(v7 + 28) = 4 * (*(_QWORD *)(*v17 + 928LL) & ~(*(__int64 *)(*v17 + 928LL) >> 63));
          *(_QWORD *)(v7 + 20) = 4 * (*(_QWORD *)(*v17 + 888LL) & ~(*(__int64 *)(*v17 + 888LL) >> 63));
          v73 = 0;
          v20 = (_QWORD *)(v15[52] + 16LL);
          do
          {
            v20 = (_QWORD *)*v20;
            if ( v20 == (_QWORD *)(v15[52] + 16LL) )
              break;
            if ( v20 != v15 )
              raw_spin_lock(v20 + 70);
            if ( v19 )
            {
              v21 = v20[49];
              if ( !v21 )
                goto LABEL_25;
            }
            else
            {
              v19 = *(_QWORD *)(*(v15 - 14) + 2368LL);
              v21 = v20[49];
              if ( !v21 )
                goto LABEL_25;
            }
            if ( v19 != v21 || v20 - 247 == (_QWORD *)*(v15 - 14) )
            {
              v22 = iterate_fd();
              if ( v20 == v15 )
                continue;
LABEL_26:
              raw_spin_unlock(v20 + 70);
              continue;
            }
LABEL_25:
            v22 = 0;
            if ( v20 != v15 )
              goto LABEL_26;
          }
          while ( !v22 );
          *(_QWORD *)(v7 + 36) = (v73 >> 10) & 0x3FFFFFFFFFFFFCLL;
          raw_spin_unlock(v15 + 70);
LABEL_32:
          v23 = *(unsigned int *)(v7 + 80);
          v24 = (__int64 (__fastcall *)(__int64))sysstats_kgsl_get_stats;
          if ( *((_DWORD *)sysstats_kgsl_get_stats - 1) != -1593946263 )
            __break(0x8228u);
          *(_QWORD *)(v7 + 36) += (unsigned __int64)v24(v23) >> 10;
          v25 = *(_QWORD *)(v9 + 2032) / 0x3E8uLL;
          *(_QWORD *)(v7 + 44) = *(_QWORD *)(v9 + 2024) / 0x3E8uLL;
          *(_QWORD *)(v7 + 52) = v25;
          v26 = ((__int64 (*)(void))_rcu_read_lock)();
          v27 = *(_QWORD *)(v9 + 2400);
          if ( v27 )
          {
            while ( 1 )
            {
              v28 = raw_spin_lock_irqsave(v27);
              v29 = v28;
              if ( v27 == *(_QWORD *)(v9 + 2400) )
                break;
              v26 = raw_spin_unlock_irqrestore(v27, v28);
              v27 = *(_QWORD *)(v9 + 2400);
              if ( !v27 )
                goto LABEL_37;
            }
            _rcu_read_unlock(v28);
            v31 = *(_QWORD *)(v9 + 2392);
            *(_QWORD *)(v7 + 60) = *(_QWORD *)(v31 + 432);
            *(_QWORD *)(v7 + 68) = *(_QWORD *)(v31 + 440);
            unlock = raw_spin_unlock_irqrestore(*(_QWORD *)(v9 + 2400), v29);
          }
          else
          {
LABEL_37:
            unlock = _rcu_read_unlock(v26);
          }
          _rcu_read_lock(unlock);
          v32 = *(_DWORD *)(*(_QWORD *)(v9 + 2296) + 8LL);
          if ( v32 == -1 )
            v32 = overflowuid;
          *(_DWORD *)(v7 + 84) = v32;
          if ( *(_QWORD *)(v9 + 1904) )
          {
            v33 = *(_QWORD *)(v9 + 1816);
            v34 = task_active_pid_ns(StatusReg);
            v35 = _task_pid_nr_ns(v33, 1, v34);
          }
          else
          {
            v35 = 0;
          }
          *(_DWORD *)(v7 + 88) = v35;
          _rcu_read_unlock(v35);
          v36 = strnlen((const char *)(v9 + 2320), 0x10u);
          if ( v36 < 0x10 || v36 == 32 )
          {
            if ( v36 == 32 )
              v37 = 32;
            else
              v37 = v36 + 1;
            if ( v37 < 0x21 )
            {
              v38 = sized_strscpy(v7 + 92, v9 + 2320);
              lock = _rcu_read_lock(v38);
              while ( 1 )
              {
                v40 = **(_QWORD **)(v9 + 2872);
                if ( (*(_BYTE *)(v40 + 84) & 1) != 0 )
                  break;
                v41 = _rcu_read_lock(lock);
                v42 = *(_QWORD *)(v40 + 16);
                if ( (v42 & 3) == 0 )
                {
                  ++*(_DWORD *)(StatusReg + 16);
                  v51 = (unsigned __int64 *)(_ReadStatusReg(TPIDR_EL1) + v42);
                  do
                    v52 = __ldxr(v51);
                  while ( __stxr(v52 + 1, v51) );
                  v53 = *(_QWORD *)(StatusReg + 16) - 1LL;
                  *(_DWORD *)(StatusReg + 16) = v53;
                  if ( !v53 || !*(_QWORD *)(StatusReg + 16) )
                    v41 = preempt_schedule_notrace(v41);
LABEL_67:
                  lock = _rcu_read_unlock(v41);
                  break;
                }
                _X8 = *(unsigned __int64 **)(v40 + 24);
                v44 = *_X8;
                while ( v44 )
                {
                  __asm { PRFM            #0x11, [X8] }
                  while ( 1 )
                  {
                    v50 = __ldxr(_X8);
                    if ( v50 != v44 )
                      break;
                    if ( !__stlxr(v44 + 1, _X8) )
                    {
                      __dmb(0xBu);
                      break;
                    }
                  }
                  _ZF = v50 == v44;
                  v44 = v50;
                  if ( _ZF )
                    goto LABEL_67;
                }
                lock = _rcu_read_unlock(v41);
                __yield();
              }
              _rcu_read_unlock(lock);
              v54 = cgroup_path_ns(*(_QWORD *)v40, v7 + 124, 32, *(_QWORD *)(*(_QWORD *)(StatusReg + 2384) + 64LL));
              if ( (*(_BYTE *)(v40 + 84) & 1) == 0 )
              {
                _rcu_read_lock(v54);
                v55 = v40 + 16;
                v56 = *(_QWORD *)(v40 + 16);
                if ( (v56 & 3) != 0 )
                {
                  _X8 = *(unsigned __int64 **)(v40 + 24);
                  __asm { PRFM            #0x11, [X8] }
                  do
                  {
                    v70 = __ldxr(_X8);
                    v71 = v70 - 1;
                  }
                  while ( __stlxr(v71, _X8) );
                  __dmb(0xBu);
                  if ( !v71 )
                  {
                    v62 = *(__int64 (**)(void))(*(_QWORD *)(v40 + 24) + 8LL);
                    if ( *((_DWORD *)v62 - 1) != 1081795037 )
                      __break(0x8228u);
                    v55 = v62();
                  }
                }
                else
                {
                  ++*(_DWORD *)(StatusReg + 16);
                  v57 = (unsigned __int64 *)(_ReadStatusReg(TPIDR_EL1) + v56);
                  do
                    v58 = __ldxr(v57);
                  while ( __stxr(v58 - 1, v57) );
                  v59 = *(_QWORD *)(StatusReg + 16) - 1LL;
                  *(_DWORD *)(StatusReg + 16) = v59;
                  if ( !v59 || !*(_QWORD *)(StatusReg + 16) )
                    v55 = preempt_schedule_notrace(v55);
                }
                _rcu_read_unlock(v55);
              }
              __asm { PRFM            #0x11, [X21] }
              do
                v66 = __ldxr(_X21);
              while ( __stlxr(v66 - 1, _X21) );
              if ( v66 == 1 )
              {
                __dmb(9u);
                _put_task_struct(v9);
              }
              else if ( v66 <= 0 )
              {
                refcount_warn_saturate(_X21, 3);
              }
              v67 = v72;
              **(_DWORD **)((char *)&off_E0 + v72) = *(int *)((char *)&dword_D8 + v72)
                                                   + *(int *)((char *)&dword_D0 + v72)
                                                   - (unsigned int)*(_UNKNOWN **)((char *)&off_E0 + v72);
              v68 = netlink_unicast(*(_QWORD *)(*(_QWORD *)(a2 + 40) + 288LL), v67, *(unsigned int *)(a2 + 4), 64);
              result = v68 & (unsigned int)(v68 >> 31);
              goto LABEL_96;
            }
          }
          else
          {
            _fortify_panic(2, 16, v36 + 1);
          }
          _fortify_panic(7, 32, v37);
        }
        v60 = 2;
        goto LABEL_90;
      }
      ((void (*)(void))_rcu_read_unlock)();
      v18 = -3;
    }
    else
    {
      v18 = -22;
    }
    sk_skb_reason_drop(0, v4, 2);
    result = v18;
  }
LABEL_96:
  _ReadStatusReg(SP_EL0);
  return result;
}
