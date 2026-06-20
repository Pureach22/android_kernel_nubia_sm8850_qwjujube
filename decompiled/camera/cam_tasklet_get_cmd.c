__int64 __fastcall cam_tasklet_get_cmd(__int64 a1, _QWORD *a2)
{
  __int64 v4; // x20
  _QWORD *v5; // x9
  _QWORD *v6; // x10
  __int64 v7; // x11
  _QWORD *v8; // x8
  unsigned int v9; // w21
  __int64 v10; // x0
  __int64 v11; // x0
  __int64 v12; // x0

  *a2 = 0;
  if ( a1 )
  {
    if ( *(_DWORD *)(a1 + 24) )
    {
      v4 = raw_spin_lock_irqsave(a1 + 20);
      v5 = *(_QWORD **)(a1 + 72);
      if ( v5 == (_QWORD *)(a1 + 72) )
      {
        if ( (unsigned int)__ratelimit(&cam_tasklet_get_cmd__rs_3, "cam_tasklet_get_cmd") )
          v12 = 3;
        else
          v12 = 2;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          v12,
          8,
          1,
          "cam_tasklet_get_cmd",
          112,
          "No more free tasklet cmd idx:%d",
          *(_DWORD *)(a1 + 16));
        v9 = -19;
      }
      else
      {
        v6 = (_QWORD *)v5[1];
        if ( (_QWORD *)*v6 == v5 && (v7 = *v5, *(_QWORD **)(*v5 + 8LL) == v5) )
        {
          v8 = a2;
          *(_QWORD *)(v7 + 8) = v6;
          *v6 = v7;
        }
        else
        {
          _list_del_entry_valid_or_report(*(_QWORD *)(a1 + 72));
          v8 = a2;
        }
        v9 = 0;
        *v5 = v5;
        v5[1] = v5;
        *v8 = v5;
      }
      raw_spin_unlock_irqrestore(a1 + 20, v4);
    }
    else
    {
      if ( (unsigned int)__ratelimit(&cam_tasklet_get_cmd__rs_1, "cam_tasklet_get_cmd") )
        v11 = 3;
      else
        v11 = 2;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        v11,
        8,
        1,
        "cam_tasklet_get_cmd",
        104,
        "Tasklet idx:%d is not active",
        *(_DWORD *)(a1 + 16));
      return (unsigned int)-32;
    }
  }
  else
  {
    if ( (unsigned int)__ratelimit(&cam_tasklet_get_cmd__rs, "cam_tasklet_get_cmd") )
      v10 = 3;
    else
      v10 = 2;
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      v10,
      8,
      1,
      "cam_tasklet_get_cmd",
      98,
      "tasklet is NULL");
    return (unsigned int)-22;
  }
  return v9;
}
