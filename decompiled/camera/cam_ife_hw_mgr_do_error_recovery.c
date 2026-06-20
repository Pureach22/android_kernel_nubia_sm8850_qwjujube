__int64 __fastcall cam_ife_hw_mgr_do_error_recovery(__int64 a1)
{
  __int64 result; // x0
  __int64 v2; // x19
  int *task; // x0
  unsigned __int64 v4; // x8
  __int64 v5; // x9
  unsigned __int64 v7; // x13
  unsigned int v13; // w12
  unsigned int v14; // w12
  __int64 v15; // x0
  unsigned __int64 StatusReg; // x20
  __int64 v17; // x21

  result = kmemdup_noprof(a1, 144, 2080);
  v2 = result;
  if ( result )
  {
    while ( 1 )
    {
      if ( (debug_mdl & 8) != 0 && !debug_priority )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 8,
          4,
          "cam_ife_hw_mgr_do_error_recovery",
          17061,
          "Enter: error_type (%d)",
          *(_DWORD *)v2);
      task = cam_req_mgr_workq_get_task(qword_3A84E8);
      if ( !task )
        break;
      *((_QWORD *)task + 1) = v2;
      *((_QWORD *)task + 2) = cam_context_handle_hw_recovery;
      if ( !*(_DWORD *)(v2 + 104) )
        return cam_req_mgr_workq_enqueue_task((unsigned int *)task, *(_QWORD *)(*(_QWORD *)(v2 + 40) + 32LL), 0);
      v4 = 0;
      v5 = v2 + 108;
      while ( v4 != 8 )
      {
        _X13 = (unsigned int *)(*(_QWORD *)(v5 + 8 * v4 - 68) + 9436LL);
        __asm { PRFM            #0x11, [X13] }
        do
        {
          v13 = __ldxr(_X13);
          v14 = v13 + 1;
        }
        while ( __stlxr(v14, _X13) );
        __dmb(0xBu);
        v7 = *(unsigned int *)(v2 + 104);
        *(_DWORD *)(v5 + 4 * v4++) = v14;
        if ( v4 >= v7 )
          return cam_req_mgr_workq_enqueue_task((unsigned int *)task, *(_QWORD *)(*(_QWORD *)(v2 + 40) + 32LL), 0);
      }
      __break(0x5512u);
      StatusReg = _ReadStatusReg(SP_EL0);
      v17 = *(_QWORD *)(StatusReg + 80);
      *(_QWORD *)(StatusReg + 80) = &cam_ife_hw_mgr_do_error_recovery__alloc_tag;
      result = kmemdup_noprof(task, 144, 2080);
      v2 = result;
      *(_QWORD *)(StatusReg + 80) = v17;
      if ( !result )
        return result;
    }
    if ( (unsigned int)__ratelimit(&cam_ife_hw_mgr_do_error_recovery__rs, "cam_ife_hw_mgr_do_error_recovery") )
      v15 = 3;
    else
      v15 = 2;
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      v15,
      8,
      1,
      "cam_ife_hw_mgr_do_error_recovery",
      17065,
      "No empty task frame");
    return kfree(v2);
  }
  return result;
}
