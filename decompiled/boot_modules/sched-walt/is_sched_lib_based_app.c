__int64 __fastcall is_sched_lib_based_app(int a1)
{
  __int64 pid_task; // x20
  size_t v2; // x0
  __int64 v3; // x0
  char *v4; // x19
  __int64 vpid; // x0
  unsigned int v6; // w22
  __int64 task_mm; // x0
  __int64 v9; // x21
  __int64 i; // x0
  __int64 v11; // x8
  unsigned __int64 v12; // x0
  const char *v13; // x24
  unsigned __int64 v14; // x2
  __int64 v15; // x25
  size_t v16; // x2
  __int64 v18; // x1
  unsigned __int64 StatusReg; // x21
  __int64 v20; // x22
  __int64 v21; // x0
  int v23; // w8
  unsigned int v30; // w8
  __int64 v31; // x0
  _QWORD v32[7]; // [xsp+8h] [xbp-258h] BYREF
  int v33; // [xsp+40h] [xbp-220h]
  __int64 v34; // [xsp+44h] [xbp-21Ch]
  int v35; // [xsp+4Ch] [xbp-214h]
  char *stringp; // [xsp+50h] [xbp-210h] BYREF
  _BYTE s[512]; // [xsp+58h] [xbp-208h] BYREF
  __int64 v38; // [xsp+258h] [xbp-8h]

  LODWORD(pid_task) = a1;
  v38 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  stringp = nullptr;
  memset(s, 0, sizeof(s));
  v2 = strnlen(sched_lib_name, 0x200u);
  if ( v2 >= 0x201 )
  {
LABEL_34:
    _fortify_panic(2, 512, v2 + 1);
LABEL_35:
    _fortify_panic(7, 512, v14);
    StatusReg = _ReadStatusReg(SP_EL0);
    v20 = *(_QWORD *)(StatusReg + 80);
    v21 = _tracepoint_android_rvh_sched_cpu_dying;
    *(_QWORD *)(StatusReg + 80) = &is_sched_lib_based_app__alloc_tag;
    v3 = _kmalloc_cache_noprof(v21, 3264, 512);
    v4 = (char *)v3;
    *(_QWORD *)(StatusReg + 80) = v20;
    if ( v3 )
    {
LABEL_4:
      _rcu_read_lock(v3);
      if ( (_DWORD)pid_task )
      {
        vpid = find_vpid((unsigned int)pid_task);
        pid_task = get_pid_task(vpid, 0);
        _rcu_read_unlock(pid_task);
        if ( !pid_task )
        {
LABEL_6:
          v6 = 0;
LABEL_41:
          kfree(v4);
          goto LABEL_42;
        }
LABEL_10:
        task_mm = get_task_mm(pid_task);
        if ( task_mm )
        {
          v9 = task_mm;
          v32[0] = task_mm + 64;
          memset(&v32[1], 0, 32);
          v32[5] = -1;
          v32[6] = 0;
          v33 = 1;
          v34 = 0;
          v35 = 0;
          down_read(task_mm + 136);
          for ( i = mas_find(v32, -1); i; i = mas_find(v32, -1) )
          {
            v11 = *(_QWORD *)(i + 88);
            if ( v11 && (*(_BYTE *)(i + 32) & 4) != 0 )
            {
              v12 = d_path(v11 + 64, s, 512);
              if ( v12 > 0xFFFFFFFFFFFFF000LL )
                break;
              v13 = (const char *)v12;
              v2 = strnlen(sched_lib_name, 0x200u);
              if ( v2 >= 0x201 )
                goto LABEL_34;
              if ( v2 == 512 )
                v14 = 512;
              else
                v14 = v2 + 1;
              if ( v14 >= 0x201 )
                goto LABEL_35;
              sized_strscpy(v4, sched_lib_name);
              stringp = v4;
              while ( strsep(&stringp, ",") )
              {
                v15 = skip_spaces();
                v16 = strnlen(v13, 0x200u);
                if ( v16 == -1 )
                {
                  v2 = _fortify_panic(2, -1, 0);
                  goto LABEL_34;
                }
                if ( strnstr(v13, v15, v16) )
                {
                  v6 = 1;
                  goto LABEL_29;
                }
              }
            }
          }
          v6 = 0;
LABEL_29:
          up_read(v9 + 136);
          mmput(v9);
        }
        else
        {
          v6 = 0;
        }
        _X0 = (unsigned int *)(pid_task + 64);
        __asm { PRFM            #0x11, [X0] }
        do
          v23 = __ldxr(_X0);
        while ( __stlxr(v23 - 1, _X0) );
        if ( v23 == 1 )
        {
          __dmb(9u);
          _put_task_struct(pid_task);
        }
        else if ( v23 <= 0 )
        {
          refcount_warn_saturate(_X0, 3);
        }
        goto LABEL_41;
      }
      pid_task = _ReadStatusReg(SP_EL0);
      _X0 = (unsigned int *)(pid_task + 64);
      __asm { PRFM            #0x11, [X0] }
      do
        v30 = __ldxr(_X0);
      while ( __stxr(v30 + 1, _X0) );
      if ( v30 )
      {
        if ( (((v30 + 1) | v30) & 0x80000000) == 0 )
        {
          _rcu_read_unlock(_X0);
          if ( !pid_task )
            goto LABEL_6;
          goto LABEL_10;
        }
        v18 = 1;
      }
      else
      {
        v18 = 2;
      }
      v31 = refcount_warn_saturate(_X0, v18);
      _rcu_read_unlock(v31);
      if ( !pid_task )
        goto LABEL_6;
      goto LABEL_10;
    }
  }
  else if ( v2 )
  {
    v3 = _kmalloc_cache_noprof(_tracepoint_android_rvh_sched_cpu_dying, 3264, 512);
    v4 = (char *)v3;
    if ( v3 )
      goto LABEL_4;
  }
  v6 = 0;
LABEL_42:
  _ReadStatusReg(SP_EL0);
  return v6;
}
