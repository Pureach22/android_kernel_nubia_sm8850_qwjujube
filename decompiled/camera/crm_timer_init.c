__int64 __fastcall crm_timer_init(const void **a1, int a2, __int64 a3, __int64 (__fastcall *a4)(__int64 a1))
{
  int v5; // w19
  const void **v6; // x20
  __int64 v7; // x21
  __int64 (__fastcall *v8)(__int64); // x22
  int v9; // w20
  __int64 (__fastcall *v10)(__int64); // x22
  __int64 v11; // x21
  const void **v12; // x19
  __int64 v13; // x0
  __int64 (__fastcall *v14)(__int64); // x1
  unsigned int *v15; // x20

  if ( (debug_mdl & 0x10) != 0 && !debug_priority )
  {
    v5 = a2;
    v6 = a1;
    v7 = a3;
    v8 = a4;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x10,
      4,
      "crm_timer_init",
      49,
      "init timer %d %pK",
      a2,
      *a1);
    a2 = v5;
    a4 = v8;
    a3 = v7;
    a1 = v6;
    if ( *v6 )
      goto LABEL_4;
  }
  else if ( *a1 )
  {
LABEL_4:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      16,
      2,
      "crm_timer_init",
      77,
      "Timer already exists!!");
    return 4294967274LL;
  }
  if ( !g_cam_req_mgr_timer_cachep )
    return 4294967284LL;
  v9 = a2;
  v10 = a4;
  v11 = a3;
  v12 = a1;
  v13 = kmem_cache_alloc_noprof(g_cam_req_mgr_timer_cachep, 3520);
  if ( !v13 )
    return 4294967284LL;
  if ( v10 )
    v14 = v10;
  else
    v14 = crm_timer_callback;
  *(_DWORD *)v13 = v9;
  v15 = (unsigned int *)v13;
  *(_QWORD *)(v13 + 48) = v11;
  *(_QWORD *)(v13 + 56) = v14;
  init_timer_key(v13 + 8, v14, 0, 0, 0);
  cam_common_modify_timer(v15 + 2, *v15);
  *v12 = v15;
  return 0;
}
