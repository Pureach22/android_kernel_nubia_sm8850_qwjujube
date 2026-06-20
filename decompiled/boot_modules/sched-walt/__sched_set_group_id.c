__int64 __fastcall _sched_set_group_id(char *a1, int a2)
{
  _QWORD *v2; // x24
  __int64 v5; // x20
  unsigned __int64 v6; // x21
  _UNKNOWN **v7; // x0
  void *v8; // x2
  __int64 v9; // x0
  __int64 v10; // x1
  __int64 v11; // x22
  __int64 v12; // x23
  _QWORD *v13; // x0
  _QWORD *v14; // x1
  _QWORD *v15; // x2
  unsigned __int64 v16; // x0
  __int64 v17; // x1
  __int64 v18; // x0
  __int64 v19; // x1
  __int64 v20; // x23
  __int64 v21; // x22
  void **v22; // x8
  char *v23; // x9
  _QWORD *v24; // x10
  __int64 result; // x0
  _QWORD *v26; // x8
  unsigned __int64 v27; // x9
  __int64 v28; // x10
  __int64 v29; // [xsp+8h] [xbp-18h] BYREF
  __int64 v30; // [xsp+10h] [xbp-10h]
  __int64 v31; // [xsp+18h] [xbp-8h]

  v31 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 == (char *)&init_task )
    v2 = &vendor_data_pad;
  else
    v2 = a1 + 5184;
  if ( (*(_BYTE *)v2 & 1) == 0 )
  {
    result = 4294967274LL;
    goto LABEL_32;
  }
  v5 = raw_spin_lock_irqsave(a1 + 2540);
  raw_write_lock(&related_thread_group_lock);
  v6 = v2[30];
  if ( (a2 != 0) == (v6 == 0) )
  {
    if ( a2 )
    {
      v6 = qword_67BA0;
      v7 = (_UNKNOWN **)(qword_67BA0 + 24);
      if ( *(_QWORD *)(qword_67BA0 + 24) == qword_67BA0 + 24 )
      {
        v8 = active_related_thread_groups;
        if ( *(_UNKNOWN ***)((char *)&unk_8 + (_QWORD)active_related_thread_groups) != &active_related_thread_groups
          || v7 == &active_related_thread_groups
          || active_related_thread_groups == (_UNKNOWN *)v7 )
        {
          _list_add_valid_or_report(v7, &active_related_thread_groups, active_related_thread_groups);
        }
        else
        {
          *(_QWORD *)((char *)&unk_8 + (_QWORD)active_related_thread_groups) = v7;
          *(_QWORD *)(v6 + 24) = v8;
          *(_QWORD *)(v6 + 32) = &active_related_thread_groups;
          active_related_thread_groups = v7;
        }
      }
      v29 = 0;
      v30 = 0;
      raw_spin_lock(v6 + 4);
      v9 = _task_rq_lock(a1, &v29);
      v11 = v9;
      if ( walt_clock_suspended == 1 )
        v12 = sched_clock_last;
      else
        v12 = sched_clock(v9, v10);
      transfer_busy_time(v11, a1, 0, v12);
      v13 = v2 + 31;
      v14 = (_QWORD *)(v6 + 8);
      v15 = *(_QWORD **)(v6 + 8);
      if ( v15[1] != v6 + 8 || v13 == v14 || v15 == v13 )
      {
        _list_add_valid_or_report(v13, v14, v15);
      }
      else
      {
        v15[1] = v13;
        v2[31] = v15;
        v2[32] = v14;
        *v14 = v13;
      }
      atomic_store(v6, v2 + 30);
      if ( *(_DWORD *)(v11 + 3392) >= 3u )
        LODWORD(v30) = 4;
      raw_spin_rq_unlock(v11);
      v16 = v6;
      v17 = v12;
    }
    else
    {
      v29 = 0;
      v30 = 0;
      raw_spin_lock(v6 + 4);
      v18 = _task_rq_lock(a1, &v29);
      v20 = v18;
      if ( walt_clock_suspended == 1 )
        v21 = sched_clock_last;
      else
        v21 = sched_clock(v18, v19);
      transfer_busy_time(v20, a1, 1, v21);
      v22 = (void **)v2[32];
      v23 = (char *)(v2 + 31);
      if ( *v22 == v2 + 31 && (v24 = *(_QWORD **)v23, *(char **)(*(_QWORD *)v23 + 8LL) == v23) )
      {
        v24[1] = v22;
        *v22 = v24;
      }
      else
      {
        _list_del_entry_valid_or_report(v2 + 31);
      }
      v2[31] = v2 + 31;
      v2[32] = v23;
      v2[30] = 0;
      if ( *(_DWORD *)(v20 + 3392) >= 3u )
        LODWORD(v30) = 4;
      raw_spin_rq_unlock(v20);
      if ( *(_QWORD *)(v6 + 8) == v6 + 8 )
      {
        raw_spin_unlock(v6 + 4);
        if ( *(_DWORD *)v6 != 1 )
        {
          v26 = *(_QWORD **)(v6 + 32);
          v27 = v6 + 24;
          if ( *v26 == v6 + 24 && (v28 = *(_QWORD *)v27, *(_QWORD *)(*(_QWORD *)v27 + 8LL) == v27) )
          {
            *(_QWORD *)(v28 + 8) = v26;
            *v26 = v28;
          }
          else
          {
            _list_del_entry_valid_or_report(v6 + 24);
          }
          *(_QWORD *)(v6 + 24) = v6 + 24;
          *(_QWORD *)(v6 + 32) = v27;
        }
        goto LABEL_31;
      }
      v16 = v6;
      v17 = v21;
    }
    set_preferred_cluster(v16, v17);
    raw_spin_unlock(v6 + 4);
  }
LABEL_31:
  raw_write_unlock(&related_thread_group_lock);
  raw_spin_unlock_irqrestore(a1 + 2540, v5);
  result = 0;
LABEL_32:
  _ReadStatusReg(SP_EL0);
  return result;
}
