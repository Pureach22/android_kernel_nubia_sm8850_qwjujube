__int64 __fastcall cam_req_mgr_process_workq(_DWORD *a1)
{
  __int64 v2; // x20
  __int64 v3; // x22
  char v4; // w8
  __int64 result; // x0
  _DWORD *v6; // x0
  int **v7; // x20
  int *v8; // x28
  __int64 v9; // x27
  __int64 v10; // x23
  int **v11; // x8
  __int64 v12; // x9
  void (__fastcall *v13)(__int64, __int64); // x8
  __int64 v14; // x0
  __int64 v15; // x1
  unsigned int v22; // w9
  _DWORD *v23; // [xsp+0h] [xbp-10h]
  char v24; // [xsp+Ch] [xbp-4h]

  if ( !a1 )
    return ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
             3,
             16,
             1,
             "cam_req_mgr_process_workq",
             113,
             "NULL task pointer can not schedule");
  v2 = 0;
  v3 = 0;
  v23 = a1 + 62;
  v4 = 1;
  while ( 2 )
  {
    v6 = a1 + 10;
    v24 = v4;
    if ( a1[11] )
      v3 = raw_spin_lock_irqsave(v6);
    else
      raw_spin_lock_bh(v6);
    v7 = (int **)&v23[4 * v2];
    while ( 1 )
    {
      v8 = *v7;
      if ( *v7 == (int *)v7 )
        break;
      v9 = *((_QWORD *)v8 - 2);
      cam_common_util_thread_switch_delay_detect(a1 + 15, "schedule", v9, *((_QWORD *)v8 + 4), 5);
      v10 = ktime_get_with_offset(1);
      _X8 = a1 + 60;
      __asm { PRFM            #0x11, [X8] }
      do
        v22 = __ldxr(_X8);
      while ( __stxr(v22 - 1, _X8) );
      v11 = *((int ***)v8 + 1);
      if ( *v11 == v8 && (v12 = *(_QWORD *)v8, *(int **)(*(_QWORD *)v8 + 8LL) == v8) )
      {
        *(_QWORD *)(v12 + 8) = v11;
        *v11 = (int *)v12;
      }
      else
      {
        _list_del_entry_valid_or_report(v8);
      }
      *(_QWORD *)v8 = v8;
      *((_QWORD *)v8 + 1) = v8;
      if ( a1[11] )
        raw_spin_unlock_irqrestore(a1 + 10, v3);
      else
        raw_spin_unlock_bh(a1 + 10);
      if ( v8 != &dword_20 && !a1[14] )
      {
        v13 = *((void (__fastcall **)(__int64, __int64))v8 - 2);
        if ( v13 )
        {
          v14 = *((_QWORD *)v8 + 3);
          v15 = *((_QWORD *)v8 - 3);
          if ( *((_DWORD *)v13 - 1) != 1863972096 )
            __break(0x8228u);
          v13(v14, v15);
        }
        else
        {
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
            3,
            16,
            2,
            "cam_req_mgr_process_task",
            93,
            "FATAL:no task handler registered for workq");
        }
        cam_req_mgr_workq_put_task(v8 - 8);
      }
      cam_common_util_thread_switch_delay_detect(a1 + 15, "execution", v9, v10, 5);
      if ( (debug_mdl & 0x10) != 0 && !debug_priority )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 0x10,
          4,
          "cam_req_mgr_process_workq",
          140,
          "processed task %pK free_cnt %d",
          v8 - 8,
          a1[61]);
        if ( a1[11] )
          goto LABEL_9;
LABEL_29:
        raw_spin_lock_bh(a1 + 10);
      }
      else
      {
        if ( !a1[11] )
          goto LABEL_29;
LABEL_9:
        v3 = raw_spin_lock_irqsave(a1 + 10);
      }
    }
    if ( a1[11] )
      result = raw_spin_unlock_irqrestore(a1 + 10, v3);
    else
      result = raw_spin_unlock_bh(a1 + 10);
    v4 = 0;
    v2 = 1;
    if ( (v24 & 1) != 0 )
      continue;
    return result;
  }
}
