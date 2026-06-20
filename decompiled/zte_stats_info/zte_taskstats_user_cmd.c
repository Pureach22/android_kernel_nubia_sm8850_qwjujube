__int64 __fastcall zte_taskstats_user_cmd(__int64 a1, __int64 a2)
{
  _QWORD *v3; // x8
  __int64 v4; // x0
  __int64 result; // x0
  __int64 v6; // x0
  __int64 v7; // x20
  unsigned int v8; // w21
  __int64 v9; // x0
  char *v10; // x23
  __int64 task_by_vpid; // x0
  __int64 v12; // x21
  __int64 active; // x24
  void *v15; // x0
  __int64 v16; // x8
  __int64 v17; // x8
  __int64 v18; // x8
  __int64 v19; // x10
  unsigned __int64 v20; // x26
  signed __int64 v21; // x8
  int v22; // w9
  int v23; // w8
  __int64 v24; // x8
  __int64 v25; // x0
  unsigned int v26; // w22
  __int64 v27; // x0
  _QWORD *v28; // x21
  __int64 unlock; // x0
  __int64 v30; // x22
  __int64 lock; // x0
  __int64 v32; // x24
  __int64 v33; // x0
  __int64 v34; // x23
  unsigned int v35; // w19
  unsigned __int64 v36; // x9
  unsigned __int64 v37; // x9
  _QWORD *task_mm; // x0
  unsigned __int64 v39; // x8
  unsigned __int64 v40; // x8
  void *v41; // x0
  __int64 v42; // x0
  __int64 v43; // x9
  __int64 v44; // x13
  __int64 v45; // x11
  __int64 v46; // x12
  __int64 v47; // x10
  __int64 v48; // x10
  __int64 v49; // x10
  __int64 v50; // x12
  __int64 v51; // x10
  __int64 v52; // x13
  __int64 v53; // x12
  __int64 v54; // x11
  __int64 v55; // x12
  __int64 v56; // x10
  __int64 v57; // x0
  __int64 v58; // x1
  unsigned int v64; // w8
  int v66; // w8
  int v67; // w0
  __int64 v68; // [xsp+8h] [xbp-18h] BYREF
  _QWORD v69[2]; // [xsp+10h] [xbp-10h] BYREF

  v69[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD **)(a2 + 32);
  v4 = v3[3];
  if ( v4 )
  {
    v69[0] = 0;
    result = zte_parse(v4, v69);
    if ( (result & 0x80000000) == 0 )
      result = zte_add_del_listener(*(unsigned int *)(a2 + 4), v69, 0);
    goto LABEL_81;
  }
  v6 = v3[4];
  if ( v6 )
  {
    v69[0] = 0;
    result = zte_parse(v6, v69);
    if ( (result & 0x80000000) == 0 )
      result = zte_add_del_listener(*(unsigned int *)(a2 + 4), v69, 1);
    goto LABEL_81;
  }
  if ( v3[1] )
  {
    v69[0] = 0;
    result = zte_prepare_reply(a2, v69, 368);
    if ( (result & 0x80000000) != 0 )
      goto LABEL_81;
    v7 = v69[0];
    v8 = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a2 + 32) + 8LL) + 4LL);
    v9 = zte_mk_reply(v69[0], 1, v8);
    if ( v9 )
    {
      v10 = (char *)v9;
      _rcu_read_lock();
      task_by_vpid = find_task_by_vpid(v8);
      if ( task_by_vpid )
      {
        v12 = task_by_vpid;
        _X22 = (unsigned int *)(task_by_vpid + 64);
        __asm { PRFM            #0x11, [X22] }
        do
          v64 = __ldxr(_X22);
        while ( __stxr(v64 + 1, _X22) );
        if ( v64 )
        {
          if ( (((v64 + 1) | v64) & 0x80000000) == 0 )
            goto LABEL_13;
          v58 = 1;
        }
        else
        {
          v58 = 2;
        }
        task_by_vpid = refcount_warn_saturate(task_by_vpid + 64, v58);
LABEL_13:
        _rcu_read_unlock(task_by_vpid);
        active = task_active_pid_ns(_ReadStatusReg(SP_EL0));
        v15 = memset(v10, 0, 0x160u);
        v16 = *(_QWORD *)(v12 + 2032) + *(_QWORD *)(v12 + 2024);
        *((_QWORD *)v10 + 8) = v16 & ~(v16 >> 63);
        v17 = *(_QWORD *)(v12 + 2032) + *(_QWORD *)(v12 + 2024);
        *((_QWORD *)v10 + 38) = v17 & ~(v17 >> 63);
        v18 = *(_QWORD *)(v12 + 1568) & ~(*(__int64 *)(v12 + 1568) >> 63);
        v19 = *(_QWORD *)(v12 + 288) & ~(*(__int64 *)(v12 + 288) >> 63);
        *((_QWORD *)v10 + 2) = *(_QWORD *)(v12 + 1560);
        *((_QWORD *)v10 + 3) = v18;
        *((_QWORD *)v10 + 9) = v19;
        *(_WORD *)v10 = 10;
        *((_QWORD *)v10 + 34) = *(_QWORD *)(v12 + 2088);
        *((_QWORD *)v10 + 35) = *(_QWORD *)(v12 + 2096);
        v20 = ktime_get(v15) - *(_QWORD *)(v12 + 2104);
        *((_QWORD *)v10 + 18) = v20 / 0x3E8;
        v21 = ktime_get_real_seconds() - v20 / 0x3B9ACA00;
        *((_QWORD *)v10 + 43) = v21;
        v22 = v21 & ~(unsigned int)(v21 >> 63);
        if ( v21 > 4294967294LL )
          v22 = -1;
        *((_DWORD *)v10 + 34) = v22;
        v23 = *(_DWORD *)(v12 + 68);
        if ( (v23 & 4) != 0 )
        {
          *((_DWORD *)v10 + 1) = *(_DWORD *)(v12 + 1700);
          v23 = *(_DWORD *)(v12 + 68);
        }
        if ( (*(_DWORD *)(v12 + 1704) & 0x80000000) == 0 && (v23 & 0x40) != 0 )
        {
          v10[8] |= 1u;
          v23 = *(_DWORD *)(v12 + 68);
        }
        if ( (v23 & 0x100) != 0 )
        {
          v10[8] |= 2u;
          v23 = *(_DWORD *)(v12 + 68);
          if ( (v23 & 0x200) == 0 )
          {
LABEL_22:
            if ( (v23 & 0x400) == 0 )
            {
LABEL_24:
              v10[9] = *(_BYTE *)(v12 + 152) - 120;
              v10[112] = *(_DWORD *)(v12 + 1352);
              *((_DWORD *)v10 + 32) = _task_pid_nr_ns(v12, 0, active);
              _rcu_read_lock();
              v24 = *(_QWORD *)(v12 + 2296);
              *((_DWORD *)v10 + 30) = *(_DWORD *)(v24 + 8);
              *((_DWORD *)v10 + 31) = *(_DWORD *)(v24 + 12);
              if ( *(_QWORD *)(v12 + 1904) )
                v25 = _task_pid_nr_ns(*(_QWORD *)(v12 + 1816), 1, active);
              else
                v25 = 0;
              *((_DWORD *)v10 + 33) = v25;
              _rcu_read_unlock(v25);
              v36 = *(_QWORD *)(v12 + 2032) / 0x3E8uLL;
              *((_QWORD *)v10 + 19) = *(_QWORD *)(v12 + 2024) / 0x3E8uLL;
              *((_QWORD *)v10 + 20) = v36;
              v37 = *(_QWORD *)(v12 + 2032) / 0x3E8uLL;
              *((_QWORD *)v10 + 36) = *(_QWORD *)(v12 + 2024) / 0x3E8uLL;
              *((_QWORD *)v10 + 37) = v37;
              *((_QWORD *)v10 + 21) = *(_QWORD *)(v12 + 2120);
              *((_QWORD *)v10 + 22) = *(_QWORD *)(v12 + 2128);
              strncpy(v10 + 80, (const char *)(v12 + 2320), 0x20u);
              *((_QWORD *)v10 + 23) = (((*(_QWORD *)(v12 + 2832) >> 1) & 0x7FFFFFFFFFFFFLL)
                                     * (unsigned __int128)0x20C49BA5E353F7DuLL) >> 64;
              *((_QWORD *)v10 + 24) = (((*(_QWORD *)(v12 + 2840) >> 1) & 0x7FFFFFFFFFFFFLL)
                                     * (unsigned __int128)0x20C49BA5E353F7DuLL) >> 64;
              task_mm = (_QWORD *)get_task_mm(v12);
              if ( task_mm )
              {
                v39 = task_mm[29];
                if ( v39 <= (task_mm[106] & ~((__int64)task_mm[106] >> 63))
                          + (task_mm[101] & ~((__int64)task_mm[101] >> 63))
                          + (task_mm[116] & (unsigned __int64)~((__int64)task_mm[116] >> 63)) )
                  v39 = (task_mm[106] & ~((__int64)task_mm[106] >> 63))
                      + (task_mm[101] & ~((__int64)task_mm[101] >> 63))
                      + (task_mm[116] & ~((__int64)task_mm[116] >> 63));
                *((_QWORD *)v10 + 25) = 4 * (v39 & 0xFFFFFFFFFFFFFLL);
                v40 = task_mm[30];
                if ( v40 <= task_mm[31] )
                  v40 = task_mm[31];
                *((_QWORD *)v10 + 26) = 4 * (v40 & 0xFFFFFFFFFFFFFLL);
                mmput();
              }
              *((_QWORD *)v10 + 27) = *(_QWORD *)(v12 + 2760) & 0xFFFFFFFFFFFFFC00LL;
              *((_QWORD *)v10 + 28) = *(_QWORD *)(v12 + 2768) & 0xFFFFFFFFFFFFFC00LL;
              *((_QWORD *)v10 + 29) = *(_QWORD *)(v12 + 2776) & 0xFFFFFFFFFFFFFC00LL;
              *((_QWORD *)v10 + 30) = *(_QWORD *)(v12 + 2784) & 0xFFFFFFFFFFFFFC00LL;
              *((_QWORD *)v10 + 31) = *(_QWORD *)(v12 + 2800) & 0xFFFFFFFFFFFFFC00LL;
              *((_QWORD *)v10 + 32) = *(_QWORD *)(v12 + 2808) & 0xFFFFFFFFFFFFFC00LL;
              *((_QWORD *)v10 + 33) = *(_QWORD *)(v12 + 2816) & 0xFFFFFFFFFFFFFC00LL;
              __asm { PRFM            #0x11, [X22] }
              do
                v66 = __ldxr(_X22);
              while ( __stlxr(v66 - 1, _X22) );
              if ( v66 == 1 )
              {
                __dmb(9u);
                _put_task_struct(v12);
              }
              else if ( v66 <= 0 )
              {
                refcount_warn_saturate(_X22, 3);
              }
LABEL_80:
              **(_DWORD **)((char *)&off_E0 + v7) = *(int *)((char *)&dword_D8 + v7)
                                                  + *(int *)((char *)&dword_D0 + v7)
                                                  - (unsigned int)*(_UNKNOWN **)((char *)&off_E0 + v7);
              v67 = netlink_unicast(*(_QWORD *)(*(_QWORD *)(a2 + 40) + 288LL), v7, *(unsigned int *)(a2 + 4), 64);
              result = v67 & (unsigned int)(v67 >> 31);
              goto LABEL_81;
            }
LABEL_23:
            v10[8] |= 0x10u;
            goto LABEL_24;
          }
        }
        else if ( (v23 & 0x200) == 0 )
        {
          goto LABEL_22;
        }
        v10[8] |= 8u;
        if ( (*(_DWORD *)(v12 + 68) & 0x400) == 0 )
          goto LABEL_24;
        goto LABEL_23;
      }
      _rcu_read_unlock(0);
      goto LABEL_38;
    }
    goto LABEL_35;
  }
  if ( !v3[2] )
  {
    result = 4294967274LL;
    goto LABEL_81;
  }
  v68 = 0;
  result = zte_prepare_reply(a2, &v68, 368);
  if ( (result & 0x80000000) == 0 )
  {
    v7 = v68;
    v26 = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a2 + 32) + 16LL) + 4LL);
    v27 = zte_mk_reply(v68, 2, v26);
    if ( v27 )
    {
      v28 = (_QWORD *)v27;
      _rcu_read_lock();
      unlock = find_task_by_vpid(v26);
      if ( unlock )
      {
        v30 = unlock;
        lock = _rcu_read_lock();
        v32 = *(_QWORD *)(v30 + 2400);
        if ( v32 )
        {
          while ( 1 )
          {
            v33 = raw_spin_lock_irqsave(v32);
            v34 = v33;
            if ( v32 == *(_QWORD *)(v30 + 2400) )
              break;
            lock = raw_spin_unlock_irqrestore(v32, v33);
            v32 = *(_QWORD *)(v30 + 2400);
            if ( !v32 )
              goto LABEL_33;
          }
          _rcu_read_unlock(v33);
          if ( *(_QWORD *)(*(_QWORD *)(v30 + 2392) + 928LL) )
            v41 = memcpy(v28, *(const void **)(*(_QWORD *)(v30 + 2392) + 928LL), 0x160u);
          else
            v41 = memset(v28, 0, 0x160u);
          v42 = ktime_get(v41);
          v43 = v30;
          do
          {
            while ( 1 )
            {
              if ( !*(_DWORD *)(v43 + 1696) )
              {
                v44 = v28[38];
                v46 = v28[8];
                v45 = v28[9];
                v47 = *(_QWORD *)(v43 + 2032) + *(_QWORD *)(v43 + 2024) + v46;
                if ( v47 < v46 )
                  v47 = 0;
                v28[8] = v47;
                v48 = *(_QWORD *)(v43 + 2032) + *(_QWORD *)(v43 + 2024) + v44;
                if ( v48 < v44 )
                  v48 = 0;
                v28[38] = v48;
                v49 = v28[3];
                v50 = v49 + *(_QWORD *)(v43 + 1568);
                _VF = __OFSUB__(v50, v49);
                v51 = v45 + *(_QWORD *)(v43 + 288);
                if ( *(__int64 *)(v43 + 1568) < 0 != _VF )
                  v50 = 0;
                if ( v51 < v45 )
                  v51 = 0;
                v28[2] += *(_QWORD *)(v43 + 1560);
                v28[3] = v50;
                v52 = v28[20];
                v28[9] = v51;
                v53 = v28[19];
                v28[18] += (v42 - *(_QWORD *)(v43 + 2104)) / 0x3E8uLL;
                v54 = v52 + *(_QWORD *)(v43 + 2032) / 0x3E8uLL;
                v28[19] = v53 + *(_QWORD *)(v43 + 2024) / 0x3E8uLL;
                v28[20] = v54;
                v55 = v28[35];
                v28[34] += *(_QWORD *)(v43 + 2088);
                v28[35] = v55 + *(_QWORD *)(v43 + 2096);
              }
              v56 = *(_QWORD *)(v43 + 2392) + 16LL;
              v69[0] = *(_QWORD *)(v43 + 1976);
              if ( v69[0] != v56 && v69[0] != 1976 )
                break;
              v43 = *(_QWORD *)(v43 + 1864);
              if ( v43 == v30 )
                goto LABEL_70;
            }
            v43 = v69[0] - 1976LL;
          }
          while ( v69[0] - 1976LL != v30 );
LABEL_70:
          v57 = raw_spin_unlock_irqrestore(*(_QWORD *)(v30 + 2400), v34);
          _rcu_read_unlock(v57);
          *(_WORD *)v28 = 10;
          goto LABEL_80;
        }
LABEL_33:
        unlock = _rcu_read_unlock(lock);
      }
      _rcu_read_unlock(unlock);
      *(_WORD *)v28 = 10;
LABEL_38:
      v35 = -3;
      goto LABEL_39;
    }
LABEL_35:
    v35 = -22;
LABEL_39:
    sk_skb_reason_drop(0, v7, 2);
    result = v35;
  }
LABEL_81:
  _ReadStatusReg(SP_EL0);
  return result;
}
