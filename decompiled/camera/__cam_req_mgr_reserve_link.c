char *__fastcall _cam_req_mgr_reserve_link(__int64 a1)
{
  unsigned int v1; // w6
  const char *v2; // x5
  __int64 v3; // x4
  char *i; // x19
  __int64 v6; // x6
  unsigned int v13; // w12
  _DWORD *v15; // x20
  __int64 v16; // x8
  __int64 v17; // x9
  __int64 v18; // x20
  int v19; // w10

  if ( !g_crm_core_dev )
  {
    v2 = "NULL session/core_dev ptr";
    v3 = 2921;
LABEL_5:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      16,
      1,
      "__cam_req_mgr_reserve_link",
      v3,
      v2);
    return nullptr;
  }
  v1 = *(_DWORD *)(a1 + 4);
  if ( v1 > 3 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      16,
      1,
      "__cam_req_mgr_reserve_link",
      2927,
      "Reached max links %d per session limit %d",
      v1,
      4);
    return nullptr;
  }
  v6 = 0;
  for ( i = (char *)&g_links; ; i += 33400 )
  {
    _X11 = (unsigned int *)(i + 33272);
    __asm { PRFM            #0x11, [X11] }
    while ( 1 )
    {
      v13 = __ldxr(_X11);
      if ( v13 )
        break;
      if ( !__stlxr(1u, _X11) )
      {
        __dmb(0xBu);
        break;
      }
    }
    if ( !v13 )
      break;
    if ( ++v6 == 8 )
      return nullptr;
  }
  if ( (debug_mdl & 0x10) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x10,
      4,
      "__cam_req_mgr_reserve_link",
      2933,
      "alloc link index %d",
      v6);
  cam_req_mgr_core_link_reset((__int64)i);
  if ( mem_trace_en == 1 )
  {
    v15 = (_DWORD *)cam_mem_trace_alloc(3480, 3264, 0, "__cam_req_mgr_reserve_link", 2942);
    if ( v15 )
      goto LABEL_21;
    goto LABEL_28;
  }
  v15 = (_DWORD *)_kvmalloc_node_noprof(3480, 0, 3520, 0xFFFFFFFFLL);
  if ( !v15 )
  {
LABEL_28:
    v2 = "failed to create input queue, no mem";
    v3 = 2944;
    goto LABEL_5;
  }
LABEL_21:
  mutex_lock(i + 33168);
  *(_QWORD *)(i + 4) = 0;
  *((_DWORD *)i + 3) = 2;
  memset(v15 + 2, 0, 0xD80u);
  *((_QWORD *)i + 6) = v15;
  *v15 = 0;
  raw_spin_lock_bh(i + 33216);
  *((_DWORD *)i + 8288) = 1;
  raw_spin_unlock_bh(i + 33216);
  *((_QWORD *)i + 4145) = a1;
  i[33362] = 0;
  *((_QWORD *)i + 4153) = 0;
  *((_QWORD *)i + 4154) = 0;
  *((_QWORD *)i + 4155) = 0;
  mutex_unlock(i + 33168);
  mutex_lock(a1 + 56);
  v16 = a1;
  v17 = a1 + 8;
  if ( *(_QWORD *)(a1 + 8) )
  {
    if ( *(_QWORD *)(a1 + 16) )
    {
      if ( *(_QWORD *)(a1 + 24) )
      {
        if ( *(_QWORD *)(a1 + 32) )
        {
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
            3,
            16,
            1,
            "__cam_req_mgr_reserve_link",
            2982,
            "Free link index not found");
          mutex_unlock(a1 + 56);
          if ( (mem_trace_en & 1) != 0 )
            cam_mem_trace_free(v15, 0);
          else
            kvfree(v15);
          return nullptr;
        }
        v18 = 3;
      }
      else
      {
        v18 = 2;
      }
    }
    else
    {
      v18 = 1;
    }
  }
  else
  {
    v18 = 0;
  }
  if ( (debug_mdl & 0x10) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x10,
      4,
      "__cam_req_mgr_reserve_link",
      2975,
      "Free link index %d found, num_links=%d",
      v18,
      *(_DWORD *)(a1 + 4));
    v17 = a1 + 8;
    v16 = a1;
  }
  v19 = *(_DWORD *)(v16 + 4);
  *(_QWORD *)(v17 + 8 * v18) = i;
  *(_DWORD *)(v16 + 4) = v19 + 1;
  if ( (debug_mdl & 0x10) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x10,
      4,
      "__cam_req_mgr_reserve_link",
      2988,
      "Active session links (%d)",
      v19 + 1);
    v16 = a1;
  }
  mutex_unlock(v16 + 56);
  return i;
}
