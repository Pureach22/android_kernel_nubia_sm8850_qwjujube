__int64 __fastcall process_private_open(__int64 a1)
{
  unsigned __int64 StatusReg; // x22
  __int64 task_pid; // x0
  __int64 v4; // x20
  __int64 *v5; // x23
  __int64 v6; // x19
  unsigned int v8; // w8
  unsigned int v9; // w21
  unsigned int v15; // w9
  int v16; // w26
  __int64 i; // x27
  unsigned int v19; // w8
  unsigned int v20; // w28
  unsigned int v22; // w9
  __int64 v23; // x0
  __int64 *v24; // x0
  __int64 v25; // x2
  __int64 v26; // x1
  __int64 v27; // x8
  __int64 (__fastcall *v28)(__int64, __int64); // x8
  unsigned __int64 v29; // x0
  int v30; // w20
  void (__fastcall *v31)(__int64, __int64); // x8
  __int64 v32; // x2
  __int64 *v33; // x0

  mutex_lock(&unk_3A840);
  StatusReg = _ReadStatusReg(SP_EL0);
  task_pid = get_task_pid(*(_QWORD *)(StatusReg + 1864), 0);
  v4 = task_pid;
  v5 = &qword_3A800;
  do
  {
    v5 = (__int64 *)*v5;
    if ( v5 == &qword_3A800 )
    {
      v6 = _kmalloc_cache_noprof(icc_set_bw, 3520, 952);
      if ( !v6 )
      {
        put_pid(v4);
        v6 = -12;
        goto LABEL_66;
      }
      v16 = *(_DWORD *)(*(_QWORD *)(StatusReg + 2304) + 8LL);
      raw_spin_lock(&unk_3A820);
      for ( i = qword_3A810; (__int64 *)i != &qword_3A810; i = *(_QWORD *)i )
      {
        if ( *(_DWORD *)(i + 16) == v16 )
        {
          _X23 = i - 8;
          v19 = *(_DWORD *)(i - 8);
          if ( v19 )
          {
            do
            {
              __asm { PRFM            #0x11, [X23] }
              do
                v22 = __ldxr((unsigned int *)_X23);
              while ( v22 == v19 && __stxr(v19 + 1, (unsigned int *)_X23) );
              v20 = v19;
              if ( v22 == v19 )
                break;
              v20 = 0;
              v19 = v22;
            }
            while ( v22 );
          }
          else
          {
            v20 = 0;
          }
          if ( (((v20 + 1) | v20) & 0x80000000) != 0 )
          {
            refcount_warn_saturate(i - 8, 0);
            if ( v20 )
              goto LABEL_40;
          }
          else if ( v20 )
          {
            goto LABEL_40;
          }
        }
      }
      v23 = _kmalloc_cache_noprof(_kmalloc_cache_noprof, 2336, 96);
      _X23 = v23;
      if ( v23 )
      {
        v24 = (__int64 *)(v23 + 8);
        *(_DWORD *)_X23 = 1;
        *(_DWORD *)(_X23 + 24) = v16;
        *(_QWORD *)(_X23 + 64) = 0xFFFFFFFE00000LL;
        *(_QWORD *)(_X23 + 72) = _X23 + 72;
        *(_QWORD *)(_X23 + 80) = _X23 + 72;
        v25 = qword_3A810;
        *(_QWORD *)(_X23 + 88) = defer_work_period_put;
        if ( *(__int64 **)(v25 + 8) != &qword_3A810 || v24 == &qword_3A810 || (__int64 *)v25 == v24 )
        {
          _list_add_valid_or_report(v24, &qword_3A810);
        }
        else
        {
          *(_QWORD *)(v25 + 8) = v24;
          *(_QWORD *)(_X23 + 8) = v25;
          *(_QWORD *)(_X23 + 16) = &qword_3A810;
          qword_3A810 = _X23 + 8;
        }
LABEL_40:
        raw_spin_unlock(&unk_3A820);
        *(_QWORD *)(v6 + 488) = _X23;
        if ( _X23 < 0xFFFFFFFFFFFFF001LL )
        {
          *(_DWORD *)(v6 + 36) = 1;
          *(_DWORD *)(v6 + 372) = 1;
          *(_QWORD *)(v6 + 8) = v4;
          _get_task_comm(v6 + 16, 16, *(_QWORD *)(StatusReg + 1864));
          *(_QWORD *)(v6 + 648) = kstrdup_quotable_cmdline(StatusReg, 3264);
          *(_DWORD *)(v6 + 32) = 0;
          *(_DWORD *)(v6 + 368) = 0;
          *(_DWORD *)(v6 + 380) = 0;
          _mutex_init(v6 + 600, "&private->private_mutex", &kgsl_process_private_new___key);
          *(_QWORD *)(v6 + 48) = 0;
          *(_QWORD *)(v6 + 56) = 0;
          *(_QWORD *)(v6 + 40) = 0x1000000400000000LL;
          *(_QWORD *)(v6 + 344) = 0x1000000400000000LL;
          *(_QWORD *)(v6 + 352) = 0;
          *(_QWORD *)(v6 + 360) = 0;
          kgsl_reclaim_proc_private_init(v6);
          if ( v4 )
          {
            v26 = *(int *)(v4 + 112);
            v27 = *(_QWORD *)(a1 + 88);
            if ( !v27 )
              goto LABEL_50;
          }
          else
          {
            v26 = 0;
            v27 = *(_QWORD *)(a1 + 88);
            if ( !v27 )
              goto LABEL_50;
          }
          v28 = *(__int64 (__fastcall **)(__int64, __int64))(v27 + 80);
          if ( v28 )
          {
            if ( *((_DWORD *)v28 - 1) != -117241417 )
              __break(0x8228u);
            v29 = v28(a1 + 56, v26);
            *(_QWORD *)(v6 + 64) = v29;
            if ( v29 >= 0xFFFFFFFFFFFFF001LL )
            {
              v30 = v29;
              kgsl_put_work_period(*(unsigned int **)(v6 + 488));
              idr_destroy(v6 + 40);
              idr_destroy(v6 + 344);
              put_pid(*(_QWORD *)(v6 + 8));
              kfree(v6);
              v6 = v30;
              goto LABEL_66;
            }
            goto LABEL_51;
          }
LABEL_50:
          *(_QWORD *)(v6 + 64) = 0;
LABEL_51:
          v31 = *(void (__fastcall **)(__int64, __int64))(*(_QWORD *)(a1 + 8752) + 320LL);
          if ( *((_DWORD *)v31 - 1) != -1966975862 )
            __break(0x8228u);
          v31(a1, v6);
          _mutex_init(v6 + 904, "&private->profile.profile_mutex", &kgsl_process_private_new___key_96);
          kgsl_process_init_sysfs(a1, v6);
          kgsl_process_init_debugfs(v6);
          raw_write_lock(&unk_3A870);
          v32 = qword_3A800;
          v33 = (__int64 *)(v6 + 72);
          if ( *(__int64 **)(qword_3A800 + 8) != &qword_3A800 || v33 == &qword_3A800 || (__int64 *)qword_3A800 == v33 )
          {
            _list_add_valid_or_report(v33, &qword_3A800);
          }
          else
          {
            *(_QWORD *)(qword_3A800 + 8) = v33;
            *(_QWORD *)(v6 + 72) = v32;
            *(_QWORD *)(v6 + 80) = &qword_3A800;
            qword_3A800 = v6 + 72;
          }
          raw_write_unlock(&unk_3A870);
          goto LABEL_66;
        }
      }
      else
      {
        raw_spin_unlock(&unk_3A820);
        LODWORD(_X23) = -12;
        *(_QWORD *)(v6 + 488) = -12;
      }
      kfree(v6);
      v6 = (int)_X23;
      goto LABEL_66;
    }
  }
  while ( *(v5 - 8) != task_pid );
  v6 = (__int64)(v5 - 9);
  if ( v5 == (__int64 *)&_crc_kgsl_gpu_num_freqs )
    goto LABEL_59;
  _X0 = (unsigned int *)v5 - 9;
  v8 = *((_DWORD *)v5 - 9);
  if ( v8 )
  {
    do
    {
      __asm { PRFM            #0x11, [X0] }
      do
        v15 = __ldxr(_X0);
      while ( v15 == v8 && __stxr(v8 + 1, _X0) );
      v9 = v8;
      if ( v15 == v8 )
        break;
      v9 = 0;
      v8 = v15;
    }
    while ( v15 );
  }
  else
  {
    v9 = 0;
  }
  if ( (((v9 + 1) | v9) & 0x80000000) != 0 )
  {
    refcount_warn_saturate(_X0, 0);
    if ( !v9 )
      goto LABEL_59;
LABEL_18:
    mutex_lock(v5 + 66);
    ++*((_DWORD *)v5 + 75);
    mutex_unlock(v5 + 66);
  }
  else
  {
    if ( v9 )
      goto LABEL_18;
LABEL_59:
    v6 = -17;
  }
  put_pid(v4);
LABEL_66:
  mutex_unlock(&unk_3A840);
  return v6;
}
