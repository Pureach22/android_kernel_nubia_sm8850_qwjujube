__int64 __fastcall cam_tasklet_enqueue_cmd(__int64 a1, _QWORD *a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 result; // x0
  __int64 v11; // x0
  __int64 v12; // x0
  __int64 v13; // x0
  __int64 v14; // x0
  __int64 v15; // x0
  __int64 v16; // x2
  _QWORD *v17; // x1
  __int64 v18; // x9
  unsigned __int64 v25; // x8

  if ( a1 )
  {
    if ( a2 )
    {
      if ( *(_DWORD *)(a1 + 24) )
      {
        if ( (debug_mdl & 8) != 0 && !debug_priority )
        {
          v14 = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                  3,
                  debug_mdl & 8,
                  4,
                  "cam_tasklet_enqueue_cmd",
                  220,
                  "Enqueue tasklet cmd idx:%d",
                  *(_DWORD *)(a1 + 16));
          if ( (cam_presil_mode_enabled(v14) & 1) != 0 )
            return cam_presil_enqueue_presil_irq_tasklet(a5, a3, a4);
        }
        else if ( (cam_presil_mode_enabled(a1) & 1) != 0 )
        {
          return cam_presil_enqueue_presil_irq_tasklet(a5, a3, a4);
        }
        a2[3] = a3;
        a2[4] = a5;
        a2[2] = a4;
        a2[5] = ktime_get_with_offset(1);
        v15 = raw_spin_lock_irqsave(a1 + 20);
        v16 = a1 + 88;
        v17 = *(_QWORD **)(a1 + 96);
        v18 = v15;
        if ( (_QWORD *)(a1 + 88) == a2 || v17 == a2 || *v17 != v16 )
        {
          _list_add_valid_or_report(a2);
        }
        else
        {
          *(_QWORD *)(a1 + 96) = a2;
          *a2 = v16;
          a2[1] = v17;
          *v17 = a2;
        }
        result = raw_spin_unlock_irqrestore(a1 + 20, v18);
        _X9 = (unsigned __int64 *)(a1 + 40);
        __asm { PRFM            #0x11, [X9] }
        do
          v25 = __ldxr(_X9);
        while ( __stlxr(v25 | 1, _X9) );
        __dmb(0xBu);
        if ( (v25 & 1) == 0 )
          return _tasklet_hi_schedule(a1 + 32);
      }
      else
      {
        if ( (unsigned int)__ratelimit(&cam_tasklet_enqueue_cmd__rs_10, "cam_tasklet_enqueue_cmd") )
          v13 = 3;
        else
          v13 = 2;
        return ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                 v13,
                 8,
                 1,
                 "cam_tasklet_enqueue_cmd",
                 216,
                 "Tasklet is not active idx:%d",
                 *(_DWORD *)(a1 + 16));
      }
    }
    else
    {
      if ( (unsigned int)__ratelimit(&cam_tasklet_enqueue_cmd__rs_8, "cam_tasklet_enqueue_cmd") )
        v12 = 3;
      else
        v12 = 2;
      return ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
               v12,
               8,
               1,
               "cam_tasklet_enqueue_cmd",
               210,
               "NULL bh cmd");
    }
  }
  else
  {
    if ( (unsigned int)__ratelimit(&cam_tasklet_enqueue_cmd__rs, "cam_tasklet_enqueue_cmd") )
      v11 = 3;
    else
      v11 = 2;
    return ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
             v11,
             8,
             1,
             "cam_tasklet_enqueue_cmd",
             205,
             "NULL bottom half");
  }
  return result;
}
