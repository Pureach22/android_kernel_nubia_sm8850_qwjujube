__int64 __fastcall cam_tasklet_init(_QWORD *a1, __int64 a2, int a3)
{
  __int64 v6; // x0
  _QWORD *v7; // x20
  __int64 v8; // x10
  _QWORD *v9; // x9
  _QWORD *v10; // x8
  _QWORD *v11; // x0
  _QWORD *v12; // x1
  __int64 result; // x0
  unsigned int v20; // w9

  if ( mem_trace_en == 1 )
    v6 = cam_mem_trace_alloc(12400, 0xCC0u, 0, "cam_tasklet_init", 0xF6u);
  else
    v6 = _kvmalloc_node_noprof(12400, 0, 3520, 0xFFFFFFFFLL);
  v7 = (_QWORD *)v6;
  if ( v6 )
  {
    *(_QWORD *)(v6 + 12392) = a2;
    *(_DWORD *)(v6 + 16) = a3;
    *(_DWORD *)(v6 + 20) = 0;
    memset((void *)(v6 + 104), 0, 0x3000u);
    v8 = 0;
    v9 = v7 + 9;
    v7[9] = v7 + 9;
    v7[10] = v7 + 9;
    v7[11] = v7 + 11;
    v7[12] = v7 + 11;
    do
    {
      v10 = &v7[v8];
      v11 = v10 + 13;
      v10[13] = v10 + 13;
      v10[14] = v10 + 13;
      v12 = (_QWORD *)v7[10];
      if ( &v7[v8 + 13] == v12 || (_QWORD *)*v12 != v9 )
      {
        _list_add_valid_or_report(v11);
      }
      else
      {
        v7[10] = v11;
        v10[13] = v9;
        v10[14] = v12;
        *v12 = v11;
      }
      v8 += 6;
    }
    while ( v8 != 1536 );
    tasklet_init(v7 + 4, cam_tasklet_action, v7);
    _X8 = (unsigned int *)(v7 + 6);
    __asm { PRFM            #0x11, [X8] }
    do
      v20 = __ldxr(_X8);
    while ( __stxr(v20 + 1, _X8) );
    __dmb(0xBu);
    tasklet_unlock_wait(v7 + 4);
    __dmb(0xBu);
    result = 0;
  }
  else
  {
    result = 4294967284LL;
    if ( (debug_mdl & 8) != 0 && !debug_priority )
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "cam_tasklet_init",
        249,
        "Error! Unable to allocate memory for tasklet");
      result = 4294967284LL;
    }
  }
  *a1 = v7;
  return result;
}
