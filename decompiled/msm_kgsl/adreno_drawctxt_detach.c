__int64 __fastcall adreno_drawctxt_detach(__int64 result)
{
  __int64 *v1; // x20
  __int64 v3; // x22
  _QWORD *v4; // x8
  __int64 v5; // x21
  __int64 v6; // x9
  unsigned __int64 v7; // x8
  __int64 v8; // x9
  __int64 v9; // x23
  __int64 v10; // x11
  char v11; // w14
  __int64 v12; // x12
  __int64 v13; // x24
  __int64 v14; // x21
  __int64 v15; // x1
  __int64 v16; // x2
  __int64 v17; // x3
  void (__fastcall *v18)(_QWORD); // x8
  int v19; // w0
  __int64 i; // x20
  __int64 v21; // x0
  __int64 v22; // x1
  __int64 v23; // x2
  __int64 v24; // x3
  __int64 v25; // x4
  __int64 v26; // x5
  __int64 v27; // x9
  __int64 v28; // x8
  int v30; // w8
  int v33; // w8
  unsigned int v40; // w9
  _QWORD v41[5]; // [xsp+10h] [xbp-430h] BYREF
  _QWORD s[128]; // [xsp+38h] [xbp-408h] BYREF
  __int64 v43; // [xsp+438h] [xbp-8h]

  v43 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !result )
    goto LABEL_60;
  v1 = *(__int64 **)(result + 40);
  _X19 = result;
  v3 = *(_QWORD *)(v1[1783] + 40);
  raw_spin_lock(result + 404);
  raw_spin_lock(v1 + 2602);
  v4 = *(_QWORD **)(_X19 + 1624);
  v5 = _X19 + 1616;
  if ( *v4 == _X19 + 1616 && (v6 = *(_QWORD *)v5, *(_QWORD *)(*(_QWORD *)v5 + 8LL) == v5) )
  {
    *(_QWORD *)(v6 + 8) = v4;
    *v4 = v6;
  }
  else
  {
    _list_del_entry_valid_or_report(_X19 + 1616);
  }
  memset(s, 0, sizeof(s));
  *(_QWORD *)(_X19 + 1616) = _X19 + 1616;
  *(_QWORD *)(_X19 + 1624) = v5;
  raw_spin_unlock(v1 + 2602);
  v7 = *(unsigned int *)(_X19 + 1432);
  v8 = *(unsigned int *)(_X19 + 1436);
  if ( v7 == v8 )
  {
    raw_spin_unlock(_X19 + 404);
LABEL_16:
    debugfs_remove(*(_QWORD *)(_X19 + 1520));
    if ( !*(_QWORD *)(_X19 + 1520) )
      goto LABEL_44;
  }
  else
  {
    v9 = 0;
    while ( v7 < 0x80 )
    {
      v10 = (int)v9;
      v11 = v7 + 1;
      v12 = *(_QWORD *)(_X19 + 408 + 8 * v7);
      v7 = ((_BYTE)v7 + 1) & 0x7F;
      *(_DWORD *)(_X19 + 1432) = v11 & 0x7F;
      if ( (unsigned __int64)(8LL * (int)v9) > 0x400 || (_DWORD)v9 == 128 )
      {
        __break(1u);
        break;
      }
      ++v9;
      s[v10] = v12;
      if ( v7 == v8 )
      {
        raw_spin_unlock(_X19 + 404);
        if ( (unsigned int)(v9 - 1) > 0x7FFFFFFE )
          goto LABEL_16;
        v13 = 0;
        while ( v13 != 128 )
        {
          v14 = s[v13];
          adreno_fault_skipcmd_detached(v1, _X19, v14);
          kgsl_drawobj_destroy(v14, v15, v16, v17);
          --v9;
          ++v13;
          if ( !v9 )
            goto LABEL_16;
        }
        break;
      }
    }
    __break(0x5512u);
  }
  __asm { PRFM            #0x11, [X19] }
  do
    v30 = __ldxr((unsigned int *)_X19);
  while ( __stlxr(v30 - 1, (unsigned int *)_X19) );
  if ( v30 != 1 )
  {
    if ( v30 <= 0 )
    {
      refcount_warn_saturate(_X19, 3);
      v18 = *(void (__fastcall **)(_QWORD))(v3 + 96);
      if ( v18 )
        goto LABEL_45;
      goto LABEL_19;
    }
LABEL_44:
    v18 = *(void (__fastcall **)(_QWORD))(v3 + 96);
    if ( v18 )
      goto LABEL_45;
LABEL_19:
    rt_mutex_lock(v1 + 1386);
    if ( (*(_QWORD *)(_X19 + 32) & 4) == 0 && (*(_QWORD *)(_X19 + 32) & 1) != 0 )
      v19 = adreno_ringbuffer_waittimestamp(*(_QWORD *)(_X19 + 1536), *(unsigned int *)(_X19 + 396), 30000);
    else
      v19 = 0;
    if ( v19 != -11 && v19 )
    {
      dev_err(
        *v1,
        "Wait for global ctx=%u ts=%u type=%d error=%d\n",
        *(_DWORD *)(_X19 + 4),
        *(_DWORD *)(_X19 + 396),
        *(_DWORD *)(_X19 + 400),
        v19);
      _X8 = (unsigned int *)(v1 + 3056);
      __asm { PRFM            #0x11, [X8] }
      do
        v40 = __ldxr(_X8);
      while ( __stxr(v40 | 0x40, _X8) );
      __dmb(0xAu);
      rt_mutex_unlock(v1 + 1386);
      kthread_queue_work(v1[3050], v1 + 3051);
      if ( (*(_QWORD *)(_X19 + 32) & 4) == 0 )
      {
        memset(v41, 0, sizeof(v41));
        init_wait_entry(v41, 0);
        for ( i = 1250; ; i = schedule_timeout(v28, v22, v23, v24, v25, v26) )
        {
          v21 = prepare_to_wait_event(_X19 + 1488, v41, 1);
          v27 = *(_QWORD *)(_X19 + 32);
          v28 = ((i == 0) & ((unsigned int)v27 >> 2)) != 0 ? 1LL : i;
          if ( (v27 & 4) != 0 || !v28 )
            break;
          if ( v21 )
            goto LABEL_48;
        }
        finish_wait(_X19 + 1488, v41);
      }
    }
    else
    {
      kgsl_sharedmem_writel(v1[5], 40LL * *(unsigned int *)(_X19 + 4), *(unsigned int *)(_X19 + 392));
      kgsl_sharedmem_writel(v1[5], 40LL * *(unsigned int *)(_X19 + 4) + 8, *(unsigned int *)(_X19 + 392));
      adreno_profile_process_results(v1);
      rt_mutex_unlock(v1 + 1386);
    }
    goto LABEL_48;
  }
  __dmb(9u);
  kgsl_context_destroy(_X19);
  v18 = *(void (__fastcall **)(_QWORD))(v3 + 96);
  if ( !v18 )
    goto LABEL_19;
LABEL_45:
  if ( *((_DWORD *)v18 - 1) != -617225124 )
    __break(0x8228u);
  v18(_X19);
LABEL_48:
  if ( *(_QWORD *)(_X19 + 272) )
  {
    gpumem_free_entry();
    _X0 = *(unsigned int **)(_X19 + 272);
    if ( _X0 )
    {
      if ( (unsigned __int64)_X0 <= 0xFFFFFFFFFFFFF000LL )
      {
        __asm { PRFM            #0x11, [X0] }
        do
          v33 = __ldxr(_X0);
        while ( __stlxr(v33 - 1, _X0) );
        if ( v33 == 1 )
        {
          __dmb(9u);
          kgsl_mem_entry_destroy();
        }
        else if ( v33 <= 0 )
        {
          refcount_warn_saturate(_X0, 3);
        }
      }
    }
  }
  _wake_up(_X19 + 1464, 3, 0, 0);
  result = _wake_up(_X19 + 1440, 3, 0, 0);
LABEL_60:
  _ReadStatusReg(SP_EL0);
  return result;
}
