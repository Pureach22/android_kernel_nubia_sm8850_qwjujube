__int64 __fastcall gpumem_alloc_entry(__int64 a1, unsigned __int64 a2, __int64 a3)
{
  __int64 v3; // x19
  _QWORD *v4; // x20
  int v5; // w21
  __int64 v6; // x22
  unsigned __int64 v7; // x23
  unsigned int *v8; // x0
  __int64 v9; // x9
  __int64 v10; // x21
  __int64 v11; // x24
  __int64 v12; // x8
  int v13; // w22
  int user; // w23
  unsigned __int64 v16; // x8
  const char **v17; // x0
  const char *v18; // x1
  const char *v19; // x2
  __int64 *v20; // x8
  __int64 v21; // x8
  __int64 v22; // x9
  __int64 v23; // x10
  int v24; // w21
  unsigned __int64 v25; // x23
  __int64 v26; // x24
  unsigned int *v27; // x0
  __int64 v28; // x9
  unsigned __int64 v29; // x22
  int vbo; // w0
  unsigned __int64 v31; // x9
  unsigned __int64 v32; // x21
  __int64 v33; // x22
  __int64 v34; // x8
  int v35; // w0
  int v36; // w19
  __int64 v37; // x1
  unsigned int v38; // w9
  __int64 v39; // x10
  __int64 v41; // x0
  unsigned __int64 v43; // x9
  unsigned __int64 v44; // x9
  unsigned int v51; // w9
  unsigned int v54; // w10

  v4 = *(_QWORD **)a1;
  v3 = *(_QWORD *)(a1 + 8);
  if ( (a3 & 0x400000000LL) != 0 )
  {
    if ( (a3 & 0x9D000000) == 0 )
    {
      if ( (a3 & 8) != 0 )
      {
        if ( *((_BYTE *)v4 + 96) != 1 || (v20 = v4 + 10, (v31 = v4[10]) == 0) || v31 >= 0xFFFFFFFFFFFFF001LL )
        {
          if ( (check_and_warn_secured___already_done & 1) != 0 )
            return -95;
          v41 = *v4;
          check_and_warn_secured___already_done = 1;
          v18 = (const char *)dev_driver_string(v41);
          v19 = *(const char **)(*v4 + 112LL);
          if ( !v19 )
            v19 = *(const char **)*v4;
          goto LABEL_21;
        }
      }
      else
      {
        v20 = (__int64 *)(v3 + 64);
      }
      if ( a2 )
      {
        v21 = *v20;
        v22 = 168;
        if ( (a3 & 0x100000000LL) != 0 )
        {
          v23 = 160;
        }
        else
        {
          v22 = 136;
          v23 = 128;
        }
        if ( *(_QWORD *)(v21 + v22) - *(_QWORD *)(v21 + v23) >= a2 )
        {
          v24 = BYTE2(a3);
          v25 = a2;
          v26 = a3;
          if ( BYTE2(a3) >= 0x19u )
          {
            dev_err(*v4, "Alignment too large; restricting to %dK\n", 0x8000);
            v24 = 25;
            v27 = kgsl_mem_entry_create();
            if ( !v27 )
              return -12;
          }
          else
          {
            v27 = kgsl_mem_entry_create();
            if ( !v27 )
              return -12;
          }
          v28 = (unsigned int)(v24 << 16);
          v10 = (__int64)v27;
          v29 = v26 & 0xD0000FF08LL | v28;
          vbo = kgsl_sharedmem_allocate_vbo(v4, v27 + 2, v25, v29);
          if ( vbo )
          {
            user = vbo;
            goto LABEL_33;
          }
          if ( (v26 & 8) != 0 )
          {
            _X8 = (unsigned int *)(v10 + 56);
            __asm { PRFM            #0x11, [X8] }
            do
              v51 = __ldxr(_X8);
            while ( __stxr(v51 | 0x10, _X8) );
          }
          v36 = kgsl_mem_entry_attach_to_process(v4, v3, v10);
          if ( v36
            || !(v29 >> 35)
            && (v36 = kgsl_mmu_map_zero_page_to_range(*(_QWORD *)(v10 + 8), v10 + 8, 0, *(_QWORD *)(v10 + 48))) != 0 )
          {
            kgsl_sharedmem_free(v10 + 8);
            kfree(v10);
            return v36;
          }
          goto LABEL_59;
        }
      }
    }
    return -22;
  }
  if ( (a3 & 8) != 0 && (*((_BYTE *)v4 + 96) != 1 || (v16 = v4[10]) == 0 || v16 >= 0xFFFFFFFFFFFFF001LL) )
  {
    if ( (check_and_warn_secured___already_done & 1) != 0 )
      return -95;
    v17 = (const char **)*v4;
    check_and_warn_secured___already_done = 1;
    v18 = (const char *)dev_driver_string(v17);
    v19 = *(const char **)(*v4 + 112LL);
    if ( !v19 )
      v19 = *(const char **)*v4;
LABEL_21:
    _warn_printk("%s %s: Secure buffers are not supported\n", v18, v19);
    __break(0x800u);
    return -95;
  }
  v5 = BYTE2(a3);
  if ( BYTE2(a3) >= 0x19u )
  {
    v32 = a2;
    v33 = a3;
    dev_err(*v4, "Alignment too large; restricting to %dK\n", 0x8000);
    a3 = v33;
    a2 = v32;
    v5 = 25;
  }
  if ( a2 - 0x100000000LL < 0xFFFFFFFF00000001LL )
    return -22;
  v6 = a3;
  v7 = a2;
  v8 = kgsl_mem_entry_create();
  if ( v8 )
  {
    v9 = (unsigned int)(v5 << 16);
    v10 = (__int64)v8;
    if ( (v6 & 0xC000000) == 0x8000000 )
      v11 = v6 & 0x39D00FF08LL | v9 | 0xC000000;
    else
      v11 = v6 & 0x39D00FF08LL | v9;
    v12 = (16 * (_DWORD)v11) & 0x80000000;
    v13 = v12 | v11;
    user = kgsl_allocate_user(v4, v8 + 2, v7, v12 | v11, 0);
    if ( user )
      goto LABEL_33;
    user = kgsl_mem_entry_attach_to_process(v4, v3, v10);
    if ( user )
      goto LABEL_12;
    v34 = v10;
    if ( *(_QWORD *)(v10 + 32) )
    {
      v35 = kgsl_mmu_map(*(_QWORD *)(v10 + 8), v10 + 8);
      if ( v35 )
      {
        user = v35;
        kgsl_mem_entry_detach_process(v10);
LABEL_12:
        kgsl_sharedmem_free(v10 + 8);
LABEL_33:
        kfree(v10);
        return user;
      }
      v37 = *(_QWORD *)(v10 + 32);
      v34 = v10;
    }
    else
    {
      v37 = 0;
    }
    kgsl_memfree_purge(*(_QWORD *)(v34 + 8), v37, *(_QWORD *)(v34 + 48));
    if ( (v11 & 8) == 0 )
    {
      if ( (v38 = (*(_DWORD *)(v10 + 80) >> 26) & 3, v13 < 0) && v38 != 2 || (v13 & 0x80000000) == 0 && v38 <= 1 )
      {
        _X9 = (unsigned int *)(v10 + 56);
        __asm { PRFM            #0x11, [X9] }
        do
          v54 = __ldxr(_X9);
        while ( __stxr(v54 | 0x400, _X9) );
      }
    }
    v39 = *(_QWORD *)(v10 + 48);
    _X8 = (unsigned __int64 *)(v3 + 16LL * ((unsigned __int8)*(_QWORD *)(v10 + 80) >> 5) + 208);
    __asm { PRFM            #0x11, [X8] }
    do
    {
      v43 = __ldxr(_X8);
      v44 = v43 + v39;
    }
    while ( __stlxr(v44, _X8) );
    __dmb(0xBu);
    if ( v44 > _X8[1] )
      _X8[1] = v44;
LABEL_59:
    trace_kgsl_mem_alloc(v10);
    kgsl_mem_entry_commit_process(v10);
    return v10;
  }
  return -12;
}
