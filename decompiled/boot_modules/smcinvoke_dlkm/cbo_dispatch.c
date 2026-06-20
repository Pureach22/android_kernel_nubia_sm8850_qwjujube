__int64 __fastcall cbo_dispatch(int a1, unsigned __int64 a2, unsigned __int64 a3, __int64 a4)
{
  unsigned __int64 v8; // x19
  __int64 v9; // x9
  unsigned __int64 v10; // x23
  const char *v11; // x2
  int v12; // w3
  int v13; // w4
  unsigned __int64 v14; // x21
  __int64 v15; // x0
  const char *v16; // x2
  int v17; // w3
  int v18; // w4
  unsigned __int64 v19; // x27
  __int64 v20; // x28
  const char *v21; // x2
  int v22; // w3
  int v23; // w4
  __int64 v24; // x26
  __int64 v25; // x24
  int v26; // w8
  __int64 v27; // x0
  unsigned __int64 v28; // x8
  __int64 v29; // x0
  __int64 v30; // x25
  _QWORD *v31; // x2
  _QWORD *v32; // x25
  __int64 v33; // t1
  unsigned int v35; // w19
  _QWORD *v36; // x8
  __int64 v37; // x9
  __int64 v38; // x19
  __int64 v39; // x21
  _QWORD *v40; // x22
  int v41; // w8
  size_t v42; // x2
  void *v43; // x0
  int v44; // w27
  unsigned __int64 StatusReg; // x24
  __int64 (__fastcall *v46)(_QWORD); // x0
  __int64 v47; // x26
  int v48; // [xsp+1Ch] [xbp-14h]
  _QWORD *v49; // [xsp+28h] [xbp-8h]

  LODWORD(v8) = 0;
  do
  {
    v9 = 24LL * (int)v8;
    LODWORD(v10) = v8;
    LODWORD(v8) = v8 + 1;
  }
  while ( *(_DWORD *)(a4 + v9) );
  v14 = _kmalloc_cache_noprof(_trace_trigger_soft_disabled, 3520, 104);
  if ( v14 )
  {
    while ( 1 )
    {
      *(_QWORD *)(v14 + 40) = 24LL * (int)v10;
      if ( (_DWORD)v8 != 1 )
      {
        v15 = _kmalloc_noprof(*(_QWORD *)(v14 + 40), print_fmt_cbo_dispatch_wait, v11, v12, v13);
        *(_QWORD *)(v14 + 48) = v15;
        if ( !v15 )
        {
          kfree(v14);
          goto LABEL_105;
        }
      }
      *(_DWORD *)(v14 + 36) = 0;
      *(_DWORD *)v14 = 1;
      *(_DWORD *)(v14 + 72) = 0;
      _init_swait_queue_head(v14 + 80, "&x->wait", &init_completion___key);
      *(_QWORD *)(v14 + 56) = v14 + 56;
      *(_QWORD *)(v14 + 64) = v14 + 56;
      if ( v14 >= 0xFFFFFFFFFFFFF001LL )
        return (unsigned int)v14;
      v19 = *(_QWORD *)(a2 + 96);
      v49 = (_QWORD *)(v14 + 56);
      LODWORD(v20) = -1;
      *(_DWORD *)(v14 + 4) = a1;
      *(_QWORD *)(v14 + 8) = v19;
      *(_QWORD *)(v14 + 16) = a3;
      do
        v20 = (unsigned int)(v20 + 1);
      while ( *(_DWORD *)(a4 + 24LL * (int)v20) );
      if ( !is_mul_ok((int)v20 + 1, 0x18u)
        || (v10 = 24LL * ((int)v20 + 1), (v24 = _kmalloc_noprof(v10, print_fmt_cbo_dispatch_wait, v16, v17, v18)) == 0) )
      {
LABEL_77:
        *(_QWORD *)(v14 + 24) = 0;
        goto LABEL_78;
      }
      v48 = a1;
      if ( (int)v20 < 1 )
        break;
      v8 = 0;
      a3 = v10;
      v25 = 24LL * (unsigned int)v20;
      _ReadStatusReg(SP_EL0);
      while ( v10 >= v8 && a3 >= 4 && (v8 & 0x8000000000000000LL) == 0 && v10 >= v8 )
      {
        v26 = *(_DWORD *)(a4 + v8);
        *(_DWORD *)(v24 + v8) = v26;
        if ( v26 == 2 )
        {
          v29 = _kmalloc_noprof(*(_QWORD *)(a4 + v8 + 16), print_fmt_cbo_dispatch_wait, v21, v22, v23);
          if ( v10 < v8 + 8 || a3 - 8 < 8 || ((v8 + 8) & 0x8000000000000000LL) != 0 || v10 < v8 + 8 || a3 - 8 < 8 )
            break;
          *(_QWORD *)(v24 + v8 + 8) = v29;
          if ( !v29 )
          {
LABEL_61:
            v8 = 0;
            a2 = v10;
            while ( (v8 & 0x8000000000000000LL) == 0
                 && v10 >= v8
                 && a2 >= 4
                 && (v8 & 0x8000000000000000LL) == 0
                 && v10 >= v8 )
            {
              if ( (unsigned int)(*(_DWORD *)(v24 + v8) - 1) <= 1 )
              {
                if ( ((v8 + 8) & 0x8000000000000000LL) != 0
                  || v10 < v8 + 8
                  || a2 - 8 < 8
                  || ((v8 + 8) & 0x8000000000000000LL) != 0
                  || v10 < v8 + 8
                  || a2 - 8 < 8 )
                {
                  goto LABEL_101;
                }
                kfree(*(_QWORD *)(v24 + v8 + 8));
              }
              --v20;
              a2 -= 24LL;
              v8 += 24LL;
              if ( !v20 )
              {
                kfree(v24);
                goto LABEL_77;
              }
            }
            break;
          }
          if ( v10 < v8 + 16 || a3 - 16 < 8 || ((v8 + 16) & 0x8000000000000000LL) != 0 || v10 < v8 + 16 || a3 - 16 < 8 )
            break;
          *(_QWORD *)(v24 + v8 + 16) = *(_QWORD *)(a4 + v8 + 16);
        }
        else if ( v26 == 1 )
        {
          v19 = *(_QWORD *)(a4 + v8 + 16);
          v27 = _kmalloc_noprof(v19, print_fmt_cbo_dispatch_wait, v21, v22, v23);
          v28 = v8 + 8;
          if ( v10 < v8 + 8 || a3 - 8 < 8 || (v28 & 0x8000000000000000LL) != 0 || v10 < v28 || a3 - 8 < 8 )
            break;
          *(_QWORD *)(v24 + v8 + 8) = v27;
          if ( !v27 )
            goto LABEL_61;
          if ( v10 < v8 + 16 || a3 - 16 < 8 || ((v8 + 16) & 0x8000000000000000LL) != 0 || v10 < v8 + 16 || a3 - 16 < 8 )
            break;
          v21 = *(const char **)(a4 + v8 + 16);
          *(_QWORD *)(v24 + v8 + 16) = v21;
          if ( v19 < (unsigned __int64)v21 )
            goto LABEL_102;
          if ( v10 < v28 )
            break;
          memcpy(*(void **)(v24 + v8 + 8), *(const void **)(a4 + v8 + 8), (size_t)v21);
        }
        else
        {
          if ( v10 < v8 + 8 || a3 - 8 < 8 || ((v8 + 8) & 0x8000000000000000LL) != 0 || v10 < v8 + 8 || a3 - 8 < 8 )
            break;
          *(_QWORD *)(v24 + v8 + 8) = *(_QWORD *)(a4 + v8 + 8);
        }
        v8 += 24LL;
        a3 -= 24LL;
        if ( v25 == v8 )
          goto LABEL_53;
      }
LABEL_101:
      __break(1u);
LABEL_102:
      _fortify_panic(17, v19, v21);
      v44 = v25;
      StatusReg = _ReadStatusReg(SP_EL0);
      v46 = _trace_trigger_soft_disabled;
      v47 = *(_QWORD *)(StatusReg + 80);
      *(_QWORD *)(StatusReg + 80) = &txn_alloc__alloc_tag;
      v14 = _kmalloc_cache_noprof(v46, 3520, 104);
      *(_QWORD *)(StatusReg + 80) = v47;
      a1 = v44;
      if ( !v14 )
        goto LABEL_105;
    }
LABEL_53:
    v30 = *(_QWORD *)(a2 + 104);
    *(_QWORD *)(v14 + 24) = v24;
    mutex_lock(&si_mutex);
    if ( *(_DWORD *)(v30 + 20) )
    {
      mutex_unlock(&si_mutex);
LABEL_78:
      put_txn(v14);
      return 4294967274LL;
    }
    v33 = *(_QWORD *)(v30 + 24);
    v32 = (_QWORD *)(v30 + 24);
    v31 = (_QWORD *)v33;
    if ( *(_QWORD **)(v33 + 8) != v32 || v49 == v32 || v31 == v49 )
    {
      _list_add_valid_or_report(v49, v32);
    }
    else
    {
      v31[1] = v49;
      *(_QWORD *)(v14 + 56) = v31;
      *(_QWORD *)(v14 + 64) = v32;
      *v32 = v49;
    }
    *(_DWORD *)(v14 + 36) = 1;
    mutex_unlock(&si_mutex);
    _wake_up(*(_QWORD *)(a2 + 104) + 40LL, 1, 0, 0);
    if ( !v48 )
      return 0;
    wait_for_completion_state(v14 + 72, 8450);
    mutex_lock(&si_mutex);
    if ( (unsigned int)(*(_DWORD *)(v14 + 36) - 1) <= 1 )
    {
      *(_DWORD *)(v14 + 36) = 4;
      mutex_unlock(&si_mutex);
      v35 = -512;
LABEL_83:
      mutex_lock(&si_mutex);
      if ( *(_DWORD *)(v14 + 36) )
      {
        v36 = *(_QWORD **)(v14 + 64);
        if ( (_QWORD *)*v36 == v49 && (v37 = *v49, *(_QWORD **)(*v49 + 8LL) == v49) )
        {
          *(_QWORD *)(v37 + 8) = v36;
          *v36 = v37;
        }
        else
        {
          _list_del_entry_valid_or_report(v49);
        }
        *(_QWORD *)(v14 + 56) = v14 + 56;
        *(_QWORD *)(v14 + 64) = v49;
      }
      mutex_unlock(&si_mutex);
      put_txn(v14);
      return v35;
    }
    mutex_unlock(&si_mutex);
    v35 = *(_DWORD *)(v14 + 32);
    if ( v35 )
      goto LABEL_83;
    LODWORD(v38) = -1;
    do
      v38 = (unsigned int)(v38 + 1);
    while ( *(_DWORD *)(a4 + 24LL * (int)v38) );
    if ( (int)v38 >= 1 )
    {
      v39 = *(_QWORD *)(v14 + 24) + 8LL;
      v40 = (_QWORD *)(a4 + 8);
      do
      {
        v41 = *((_DWORD *)v40 - 2);
        if ( v41 == 4 )
        {
          *v40 = *(_QWORD *)v39;
        }
        else if ( v41 == 2 )
        {
          v42 = *(_QWORD *)(v39 + 8);
          v43 = (void *)*v40;
          v40[1] = v42;
          memcpy(v43, *(const void **)v39, v42);
        }
        --v38;
        v39 += 24;
        v40 += 3;
      }
      while ( v38 );
    }
    return 0;
  }
  else
  {
LABEL_105:
    LODWORD(v14) = -12;
    return (unsigned int)v14;
  }
}
