void __fastcall walt_cfs_replace_next_task_fair(__int64 a1, __int64 a2, unsigned __int64 **a3, unsigned __int64 *a4)
{
  __int64 v4; // x19
  __int64 v5; // x20
  __int64 v6; // x6
  unsigned __int64 *v7; // x10
  __int64 v8; // x19
  int v9; // w8
  unsigned __int64 **v10; // x20
  __int64 v11; // x22
  unsigned __int64 *v12; // x21
  _BYTE *v13; // x23
  _BYTE *v14; // x8
  bool v15; // zf
  unsigned __int64 *v16; // x8
  unsigned __int64 *v17; // x20
  unsigned __int64 *v18; // x9
  unsigned __int64 **v19; // x24
  __int64 v20; // x26
  unsigned __int64 *v21; // x25
  int v22; // w3
  __int64 v23; // x21
  unsigned __int64 **v24; // x22
  unsigned __int64 *v25; // x23
  unsigned __int64 **v26; // x24
  unsigned __int64 StatusReg; // x21
  __int64 v28; // x0
  __int64 v29; // x8

  v6 = *(unsigned int *)(a2 + 3632);
  if ( (unsigned int)v6 >= 0x20 )
  {
    __break(0x5512u);
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                     + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
        & 1) != 0 )
    {
      ++*(_DWORD *)(StatusReg + 16);
      v28 = _traceiter_walt_cfs_mvp_pick_next(0, v5, v4, (unsigned int)a4);
      v29 = *(_QWORD *)(StatusReg + 16) - 1LL;
      *(_DWORD *)(StatusReg + 16) = v29;
      if ( !v29 || !*(_QWORD *)(StatusReg + 16) )
        preempt_schedule_notrace(v28);
    }
  }
  else if ( (walt_disabled & 1) == 0 )
  {
    v7 = *a3;
    v8 = *((_QWORD *)&_per_cpu_offset + v6);
    if ( *a3 && v7 != a4 )
    {
      v9 = *((_DWORD *)v7 + 22);
      if ( v9 != 1 && (*((_DWORD *)v7 + 36) | 2) != 2 )
        goto LABEL_14;
      do
      {
        if ( (unsigned int)sysctl_panic_on_walt_bug >> 8 != 4539614 )
          break;
        if ( (sysctl_panic_on_walt_bug & 8) != 0 )
        {
          v23 = a2;
          v24 = a3;
          v25 = a4;
          printk_deferred(
            "WALT-BUG picked %s(%d) on_cpu=%d on_rq=%d p->cpu=%d cpu_of(rq)=%d kthread=%d\n",
            (const char *)v7 + 2320,
            *((_DWORD *)v7 + 450),
            v9,
            *((_DWORD *)v7 + 36),
            *((_DWORD *)v7 + 10),
            v6,
            *((_DWORD *)v7 + 17) & 0x200000);
          a4 = v25;
          a2 = v23;
          a3 = v24;
          if ( (sysctl_panic_on_walt_bug & 1) == 0 )
            break;
        }
        else if ( (sysctl_panic_on_walt_bug & 1) == 0 )
        {
          break;
        }
        if ( *a3 )
        {
          v10 = a3;
          v11 = a2;
          v12 = a4;
          walt_task_dump(*a3);
          a4 = v12;
          a2 = v11;
          a3 = v10;
        }
        if ( in_sched_bug )
          break;
        in_sched_bug = 1;
        walt_dump();
        __break(0x800u);
LABEL_14:
        ;
      }
      while ( *((_DWORD *)v7 + 10) != (_DWORD)v6 );
    }
    v13 = &walt_rq[v8];
    if ( (walt_rq[v8 + 608] & 1) == 0 )
    {
      v14 = *((_BYTE **)v13 + 71);
      if ( v14 == v13 + 568 )
      {
LABEL_33:
        *((_QWORD *)v13 + 74) = 0;
        return;
      }
      v15 = v14 - 288 == (_BYTE *)&vendor_data_pad;
      v16 = (unsigned __int64 *)(v14 - 5472);
      if ( v15 )
        v17 = (unsigned __int64 *)&init_task;
      else
        v17 = v16;
      *a3 = v17;
      v18 = v17;
      if ( !*((_QWORD *)v13 + 74) )
      {
        v19 = a3;
        v20 = a2;
        v21 = a4;
        update_rq_clock(a2);
        a4 = v21;
        a2 = v20;
        a3 = v19;
        *((_QWORD *)v13 + 74) = *(_QWORD *)(v20 + 3400);
        v18 = *v19;
      }
      if ( v18 )
      {
        if ( v18 != a4 )
        {
          v22 = *((_DWORD *)v18 + 22);
          if ( v22 == 1 || (*((_DWORD *)v18 + 36) | 2) == 2 || *((_DWORD *)v18 + 10) != *(_DWORD *)(a2 + 3632) )
          {
            v13 = &unk_68000;
            if ( (unsigned int)sysctl_panic_on_walt_bug >> 8 == 4539614 )
            {
              if ( (sysctl_panic_on_walt_bug & 8) != 0 )
              {
                v26 = a3;
                printk_deferred(
                  "WALT-BUG picked %s(%d) on_cpu=%d on_rq=%d p->cpu=%d cpu_of(rq)=%d kthread=%d\n",
                  (const char *)v18 + 2320,
                  *((_DWORD *)v18 + 450),
                  v22,
                  *((_DWORD *)v18 + 36),
                  *((_DWORD *)v18 + 10),
                  *(_DWORD *)(a2 + 3632),
                  *((_DWORD *)v18 + 17) & 0x200000);
                a3 = v26;
                if ( (sysctl_panic_on_walt_bug & 1) == 0 )
                  return;
              }
              else if ( (sysctl_panic_on_walt_bug & 1) == 0 )
              {
                return;
              }
              if ( *a3 )
                walt_task_dump(*a3);
              if ( !in_sched_bug )
              {
                in_sched_bug = 1;
                walt_dump();
                __break(0x800u);
                goto LABEL_33;
              }
            }
          }
        }
      }
    }
  }
}
