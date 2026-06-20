__int64 __fastcall cam_tasklet_put_cmd(__int64 a1, _QWORD **a2)
{
  _QWORD *v2; // x21
  __int64 v5; // x0
  _QWORD *v6; // x8
  __int64 v7; // x9
  __int64 v8; // x10
  __int64 v9; // x2
  _QWORD *v10; // x1
  int v12; // w0
  const char *v13; // x5
  __int64 v14; // x0
  __int64 v15; // x4
  int v16; // w0

  if ( !a1 )
  {
    v12 = __ratelimit(&cam_tasklet_put_cmd__rs, "cam_tasklet_put_cmd");
    v13 = "tasklet is NULL";
    if ( v12 )
      v14 = 3;
    else
      v14 = 2;
    v15 = 136;
    return ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
             v14,
             8,
             1,
             "cam_tasklet_put_cmd",
             v15,
             v13);
  }
  v2 = *a2;
  if ( !*a2 )
  {
    v16 = __ratelimit(&cam_tasklet_put_cmd__rs_5, "cam_tasklet_put_cmd");
    v13 = "Invalid tasklet_cmd";
    if ( v16 )
      v14 = 3;
    else
      v14 = 2;
    v15 = 141;
    return ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
             v14,
             8,
             1,
             "cam_tasklet_put_cmd",
             v15,
             v13);
  }
  v5 = raw_spin_lock_irqsave(a1 + 20);
  v6 = (_QWORD *)v2[1];
  v7 = v5;
  if ( (_QWORD *)*v6 == v2 && (v8 = *v2, *(_QWORD **)(*v2 + 8LL) == v2) )
  {
    *(_QWORD *)(v8 + 8) = v6;
    *v6 = v8;
  }
  else
  {
    _list_del_entry_valid_or_report(v2);
  }
  *v2 = v2;
  v9 = a1 + 72;
  v2[1] = v2;
  v10 = *(_QWORD **)(a1 + 80);
  if ( v2 == (_QWORD *)(a1 + 72) || v10 == v2 || *v10 != v9 )
  {
    _list_add_valid_or_report(v2);
  }
  else
  {
    *(_QWORD *)(a1 + 80) = v2;
    *v2 = v9;
    v2[1] = v10;
    *v10 = v2;
  }
  *a2 = nullptr;
  return raw_spin_unlock_irqrestore(a1 + 20, v7);
}
