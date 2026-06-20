__int64 __fastcall cam_req_mgr_workq_enqueue_task(unsigned int *a1, __int64 a2, unsigned int a3)
{
  __int64 v3; // x19
  unsigned int v4; // w19
  __int64 result; // x0
  const char *v6; // x5
  __int64 v7; // x1
  __int64 v8; // x2
  __int64 v9; // x4
  unsigned int *v10; // x20
  unsigned int v11; // w8
  unsigned int *v12; // x21
  __int64 v13; // x0
  __int64 v14; // x20
  __int64 v15; // x8
  const void *v16; // x6
  __int64 v17; // x8
  __int64 v18; // x2
  __int64 *v19; // x1
  unsigned int v26; // w9

  if ( !a1 )
  {
    v6 = "NULL task pointer can not schedule";
    v7 = 16;
    v8 = 2;
    v9 = 156;
    goto LABEL_8;
  }
  v3 = *((_QWORD *)a1 + 3);
  if ( !v3 )
  {
    result = 4294967274LL;
    if ( (debug_mdl & 0x10) == 0 || debug_priority )
      return result;
    v6 = "NULL workq pointer suspect mem corruption";
    v7 = debug_mdl & 0x10;
    v8 = 4;
    v9 = 161;
LABEL_8:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      v7,
      v8,
      "cam_req_mgr_workq_enqueue_task",
      v9,
      v6);
    return 4294967274LL;
  }
  if ( *((_BYTE *)a1 + 48) == 1 || *(_DWORD *)(v3 + 56) )
  {
    v4 = 0;
LABEL_6:
    cam_req_mgr_workq_put_task(a1);
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      16,
      3,
      "cam_req_mgr_workq_enqueue_task",
      195,
      "task aborted and queued back to pool");
    return v4;
  }
  *((_QWORD *)a1 + 7) = a2;
  v10 = a1;
  if ( a3 >= 2 )
    v11 = 0;
  else
    v11 = a3;
  *a1 = v11;
  *((_QWORD *)a1 + 8) = ktime_get_with_offset(1);
  v12 = v10;
  if ( *(_DWORD *)(v3 + 44) )
  {
    v13 = raw_spin_lock_irqsave(v3 + 40);
    v14 = v13;
    if ( *(_QWORD *)(v3 + 32) )
      goto LABEL_17;
LABEL_28:
    if ( *(_DWORD *)(v3 + 44) )
      raw_spin_unlock_irqrestore(v3 + 40, v14);
    else
      raw_spin_unlock_bh(v3 + 40);
    v4 = -22;
    a1 = v12;
    goto LABEL_6;
  }
  v13 = raw_spin_lock_bh(v3 + 40);
  v14 = 0;
  if ( !*(_QWORD *)(v3 + 32) )
    goto LABEL_28;
LABEL_17:
  v15 = *v12;
  v16 = v12;
  if ( (unsigned int)v15 >= 3 )
  {
    __break(0x5512u);
  }
  else
  {
    v17 = v3 + 16 * v15;
    v13 = (__int64)(v12 + 8);
    v18 = v17 + 248;
    v19 = *(__int64 **)(v17 + 256);
    if ( v12 + 8 != (unsigned int *)(v17 + 248) && v19 != (__int64 *)v13 && *v19 == v18 )
    {
      *(_QWORD *)(v17 + 256) = v13;
      *((_QWORD *)v12 + 4) = v18;
      *((_QWORD *)v12 + 5) = v19;
      *v19 = v13;
      goto LABEL_37;
    }
  }
  _list_add_valid_or_report(v13);
  v16 = v12;
LABEL_37:
  _X8 = (unsigned int *)(v3 + 240);
  __asm { PRFM            #0x11, [X8] }
  do
    v26 = __ldxr(_X8);
  while ( __stxr(v26 + 1, _X8) );
  if ( (debug_mdl & 0x10) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x10,
      4,
      "cam_req_mgr_workq_enqueue_task",
      187,
      "enq task %pK pending_cnt %d",
      v16,
      *(_DWORD *)(v3 + 240));
  queue_work_on(32, *(_QWORD *)(v3 + 32), v3);
  if ( *(_DWORD *)(v3 + 44) )
    raw_spin_unlock_irqrestore(v3 + 40, v14);
  else
    raw_spin_unlock_bh(v3 + 40);
  return 0;
}
