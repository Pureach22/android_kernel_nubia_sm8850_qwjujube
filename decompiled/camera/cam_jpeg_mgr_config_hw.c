__int64 __fastcall cam_jpeg_mgr_config_hw(_QWORD *a1, __int64 *a2)
{
  __int64 v4; // x9
  __int64 *v5; // x19
  __int64 **v6; // x8
  __int64 v7; // x10
  __int64 v8; // x8
  __int64 v9; // x11
  __int64 v10; // x12
  __int64 v11; // x8
  __int64 v12; // x11
  __int64 v13; // x12
  __int16 v14; // w8
  __int64 v15; // x22
  __int64 v16; // x6
  int *task; // x0
  __int64 v18; // x23
  int *v19; // x24
  __int64 *v20; // x1
  _QWORD *v21; // x2
  __int64 v22; // x9
  __int64 result; // x0
  unsigned int v24; // w20
  __int64 **v25; // x1

  if ( !a1 || !a2 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      512,
      1,
      "cam_jpeg_mgr_config_hw",
      923,
      "Invalid arguments %pK %pK",
      a1,
      a2);
    return 4294967274LL;
  }
  if ( !*((_DWORD *)a2 + 2) )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      512,
      1,
      "cam_jpeg_mgr_config_hw",
      928,
      "No hw update enteries are available");
    return 4294967274LL;
  }
  mutex_lock(a1);
  v4 = *a2;
  if ( (*(_BYTE *)(*a2 + 104) & 1) == 0 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      512,
      1,
      "cam_jpeg_mgr_config_hw",
      936,
      "ctx is not in use");
    mutex_unlock(a1);
    return 4294967274LL;
  }
  v5 = (__int64 *)a1[662];
  if ( v5 == a1 + 662 )
  {
    mutex_unlock(a1);
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      512,
      1,
      "cam_jpeg_mgr_config_hw",
      943,
      "list empty");
    return 4294967284LL;
  }
  v6 = (__int64 **)v5[1];
  if ( *v6 == v5 && (v7 = *v5, *(__int64 **)(*v5 + 8) == v5) )
  {
    *(_QWORD *)(v7 + 8) = v6;
    *v6 = (__int64 *)v7;
  }
  else
  {
    _list_del_entry_valid_or_report(a1[662]);
  }
  *v5 = (__int64)v5;
  v5[1] = (__int64)v5;
  v8 = a2[3];
  v9 = *a2;
  v10 = a2[1];
  v5[4] = a2[2];
  v5[5] = v8;
  v5[2] = v9;
  v5[3] = v10;
  v11 = a2[7];
  v12 = a2[4];
  v13 = a2[5];
  v5[8] = a2[6];
  v5[9] = v11;
  v5[6] = v12;
  v5[7] = v13;
  *((_DWORD *)v5 + 20) = *(_DWORD *)(v4 + 56);
  v14 = debug_mdl;
  v15 = a2[5];
  v16 = *(_QWORD *)(v15 + 8);
  *((_DWORD *)v5 + 26) = 0;
  v5[11] = v16;
  if ( (v14 & 0x200) != 0 && !debug_priority )
    ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      v14 & 0x200,
      4,
      "cam_jpeg_mgr_config_hw",
      959,
      "req_id: %u, dev_type: %d",
      v16,
      *(_DWORD *)(v4 + 56));
  task = cam_req_mgr_workq_get_task(qword_3AA0A0);
  if ( !task )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      512,
      1,
      "cam_jpeg_mgr_config_hw",
      962,
      "no empty task");
    mutex_unlock(a1);
    v24 = -12;
    if ( v5 )
      goto LABEL_29;
LABEL_34:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      512,
      1,
      "cam_jpeg_mgr_move_req_to_free_list",
      61,
      "Invalid args");
    return v24;
  }
  v18 = *((_QWORD *)task + 1);
  if ( !v18 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      512,
      1,
      "cam_jpeg_mgr_config_hw",
      971,
      "task_data is NULL");
    mutex_unlock(a1);
    v24 = -22;
    if ( v5 )
      goto LABEL_29;
    goto LABEL_34;
  }
  v19 = task;
  if ( (debug_mdl & 0x200) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x200,
      4,
      "cam_jpeg_mgr_config_hw",
      978,
      "cfge %pK num %d",
      (const void *)v5[4],
      *((_DWORD *)v5 + 6));
  v20 = (__int64 *)a1[661];
  v21 = a1 + 660;
  if ( v5 == a1 + 660 || v20 == v5 || (_QWORD *)*v20 != v21 )
  {
    _list_add_valid_or_report(v5);
  }
  else
  {
    a1[661] = v5;
    *v5 = (__int64)v21;
    v5[1] = (__int64)v20;
    *v20 = (__int64)v5;
  }
  mutex_unlock(a1);
  *(_QWORD *)(v18 + 8) = a2[5];
  v22 = *(_QWORD *)(v15 + 8);
  *(_DWORD *)v18 = 1;
  *(_QWORD *)(v18 + 16) = v22;
  *((_QWORD *)v19 + 2) = cam_jpeg_mgr_process_hw_update_entries;
  result = cam_req_mgr_workq_enqueue_task((unsigned int *)v19, (__int64)&g_jpeg_hw_mgr, 0);
  if ( (_DWORD)result )
  {
    v24 = result;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      512,
      1,
      "cam_jpeg_mgr_config_hw",
      991,
      "failed to enqueue task %d",
      result);
    list_del_init_1(v5);
    if ( !v5 )
      goto LABEL_34;
LABEL_29:
    cam_mem_put_cpu_buf(*(_DWORD *)v5[4]);
    v25 = (__int64 **)qword_3AA150;
    if ( v5 == &qword_3AA148 || (__int64 *)qword_3AA150 == v5 || *(__int64 **)qword_3AA150 != &qword_3AA148 )
    {
      _list_add_valid_or_report(v5);
    }
    else
    {
      qword_3AA150 = (__int64)v5;
      *v5 = (__int64)&qword_3AA148;
      v5[1] = (__int64)v25;
      *v25 = v5;
    }
    return v24;
  }
  return result;
}
