__int64 __fastcall cam_tasklet_action(__int64 a1)
{
  _QWORD **v2; // x21
  const void *v3; // x26
  __int64 v4; // x0
  __int64 v5; // x8
  void (__fastcall *v6)(__int64, __int64); // x9
  __int64 v7; // x1
  __int64 v8; // x27
  __int64 v9; // x0
  _QWORD *v10; // x27
  __int64 v11; // x26
  _QWORD *v12; // x8
  __int64 v13; // x9
  __int64 result; // x0
  _QWORD *v15[2]; // [xsp+0h] [xbp-10h] BYREF

  v2 = (_QWORD **)(a1 + 88);
  v15[1] = *(_QWORD **)(_ReadStatusReg(SP_EL0) + 1808);
  while ( 1 )
  {
    if ( (debug_mdl & 8) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "cam_tasklet_dequeue_cmd",
        175,
        "Dequeue before lock tasklet idx:%d",
        *(_DWORD *)(a1 + 16));
    v9 = raw_spin_lock_irqsave(a1 + 20);
    v10 = *v2;
    v11 = v9;
    if ( *v2 == v2 )
      break;
    v12 = (_QWORD *)v10[1];
    v15[0] = *v2;
    if ( (_QWORD *)*v12 == v10 && (v13 = *v10, *(_QWORD **)(*v10 + 8LL) == v10) )
    {
      *(_QWORD *)(v13 + 8) = v12;
      *v12 = v13;
    }
    else
    {
      _list_del_entry_valid_or_report(v10);
    }
    *v10 = v10;
    v10[1] = v10;
    if ( (debug_mdl & 8) != 0 && !debug_priority )
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "cam_tasklet_dequeue_cmd",
        185,
        "Dequeue Successful");
    raw_spin_unlock_irqrestore(a1 + 20, v11);
    v3 = (const void *)v10[4];
    cam_common_util_thread_switch_delay_detect("ISP Tasklet", "schedule", v3, v10[5], 5u);
    v4 = ktime_get_with_offset(1);
    v5 = v10[3];
    v6 = (void (__fastcall *)(__int64, __int64))v10[4];
    v7 = v10[2];
    v8 = v4;
    if ( *((_DWORD *)v6 - 1) != 1863972096 )
      __break(0x8229u);
    v6(v5, v7);
    cam_common_util_thread_switch_delay_detect("ISP Tasklet", "execution", v3, v8, 5u);
    cam_tasklet_put_cmd(a1, v15);
  }
  if ( (debug_mdl & 8) != 0 && !debug_priority )
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_tasklet_dequeue_cmd",
      178,
      "End of list reached. Exit");
  result = raw_spin_unlock_irqrestore(a1 + 20, v11);
  _ReadStatusReg(SP_EL0);
  return result;
}
