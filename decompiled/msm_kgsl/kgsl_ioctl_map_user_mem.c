__int64 __fastcall kgsl_ioctl_map_user_mem(const char ****a1, __int64 a2, unsigned int *a3)
{
  const char ***v3; // x21
  const char ***v4; // x22
  unsigned int v6; // w8
  unsigned int *v7; // x0
  _QWORD *StatusReg; // x25
  unsigned int v10; // w23
  int v11; // w23
  unsigned __int64 v12; // x9
  const char **v14; // x23
  __int64 v15; // x0
  unsigned __int64 v16; // x0
  unsigned __int64 v17; // x24
  int v18; // w0
  unsigned __int64 v19; // x8
  unsigned __int64 v20; // x9
  unsigned __int64 v21; // x8
  int v22; // w0
  unsigned __int64 v23; // x22
  __int64 v24; // x8
  int v25; // w23
  __int64 v26; // x26
  __int64 v27; // x9
  __int64 v28; // x8
  unsigned __int64 v29; // x10
  __int64 v30; // x11
  __int64 v31; // x12
  unsigned __int64 v32; // x13
  unsigned __int64 v33; // x12
  __int64 v34; // x8
  __int64 v35; // x10
  const char **v37; // x0
  const char *v38; // x0
  const char *v39; // x2
  const char **v40; // x0
  const char *v41; // x0
  const char *v42; // x2
  unsigned int v49; // w9
  unsigned __int64 v52; // x9
  unsigned __int64 v53; // x9
  unsigned __int64 v55; // x9
  unsigned __int64 v56; // x9
  int v58; // w8

  v4 = *a1;
  v3 = a1[1];
  v6 = a3[11];
  if ( (v6 & 8) != 0 )
  {
    if ( *((_BYTE *)v4 + 96) != 1 || (v12 = (unsigned __int64)v4[10]) == 0 || v12 >= 0xFFFFFFFFFFFFF001LL )
    {
      if ( (check_and_warn_secured___already_done & 1) != 0 )
        return -95;
      v37 = *v4;
      check_and_warn_secured___already_done = 1;
      v38 = (const char *)dev_driver_string(v37);
      v39 = (*v4)[14];
      if ( !v39 )
        v39 = **v4;
      _warn_printk("%s %s: Secure buffers are not supported\n", v38, v39);
      __break(0x800u);
      return -95;
    }
    if ( (v6 & 0x10000000) != 0 )
      return -22;
  }
  v7 = kgsl_mem_entry_create();
  if ( !v7 )
    return -12;
  StatusReg = (_QWORD *)_ReadStatusReg(SP_EL0);
  _X19 = (unsigned __int64)v7;
  v10 = a3[10];
  kgsl_memdesc_init(v4, v7 + 2, a3[11] & 0x91FFFF08 | (((*StatusReg >> 22) & 1LL) << 32));
  if ( v10 != 3 )
  {
    if ( v10 == 2 )
    {
      if ( ((unsigned int)v4[13] & 2) != 0 && (*(_BYTE *)(_X19 + 80) & 8) == 0 )
      {
        v11 = kgsl_setup_useraddr(v4, v3[8], _X19, *((_QWORD *)a3 + 4), *((_QWORD *)a3 + 3), *((_QWORD *)a3 + 2));
        if ( !v11 )
          goto LABEL_31;
LABEL_30:
        *((_QWORD *)a3 + 1) = 0;
        kfree(_X19);
        return v11;
      }
LABEL_18:
      v11 = -22;
      goto LABEL_30;
    }
LABEL_29:
    v11 = -95;
    goto LABEL_30;
  }
  if ( *((_QWORD *)a3 + 3) )
    goto LABEL_18;
  v14 = v3[8];
  v15 = *a3;
  if ( (*(_BYTE *)(_X19 + 80) & 8) != 0 )
  {
    if ( *((_BYTE *)v4 + 96) != 1 || (v19 = (unsigned __int64)v4[10]) == 0 || v19 >= 0xFFFFFFFFFFFFF001LL )
    {
      if ( (check_and_warn_secured___already_done & 1) == 0 )
      {
        v40 = *v4;
        check_and_warn_secured___already_done = 1;
        v41 = (const char *)dev_driver_string(v40);
        v42 = (*v4)[14];
        if ( !v42 )
          v42 = **v4;
        _warn_printk("%s %s: Secure buffers are not supported\n", v41, v42);
        __break(0x800u);
        v11 = -95;
        goto LABEL_30;
      }
      goto LABEL_29;
    }
    _X8 = (unsigned int *)(_X19 + 56);
    __asm { PRFM            #0x11, [X8] }
    do
      v49 = __ldxr(_X8);
    while ( __stxr(v49 | 0x10, _X8) );
  }
  v16 = dma_buf_get(v15);
  v17 = v16;
  if ( !v16 || v16 >= 0xFFFFFFFFFFFFF001LL )
  {
    if ( (_DWORD)v16 )
      v11 = v16;
    else
      v11 = -22;
    goto LABEL_30;
  }
  v18 = kgsl_setup_dma_buf(v4, v14, _X19, v16);
  if ( v18 )
  {
    v11 = v18;
    dma_buf_put(v17);
    goto LABEL_30;
  }
LABEL_31:
  v20 = *(_QWORD *)(_X19 + 48);
  if ( v20 >= 0x200000 )
  {
    v21 = *(_QWORD *)(_X19 + 80) & 0xFFFFFFFFFF00FFFFLL | 0x150000;
LABEL_40:
    *(_QWORD *)(_X19 + 80) = v21;
    goto LABEL_41;
  }
  if ( v20 >= 0x100000 )
  {
    v21 = *(_QWORD *)(_X19 + 80) & 0xFFFFFFFFFF00FFFFLL | 0x140000;
    goto LABEL_40;
  }
  v21 = *(_QWORD *)(_X19 + 80);
  if ( v20 >= 0x10000 )
  {
    v21 = v21 & 0xFFFFFFFFFF00FFFFLL | 0x60000;
    goto LABEL_40;
  }
LABEL_41:
  a3[11] = v21;
  v11 = kgsl_mem_entry_attach_to_process(v4, v3, _X19);
  if ( v11 )
  {
LABEL_42:
    kgsl_sharedmem_free(_X19 + 8);
    goto LABEL_30;
  }
  if ( *(_QWORD *)(_X19 + 32) )
  {
    v22 = kgsl_mmu_map(*(_QWORD *)(_X19 + 8), _X19 + 8);
    if ( v22 )
    {
      v11 = v22;
      kgsl_mem_entry_detach_process(_X19);
      goto LABEL_42;
    }
    v23 = *(_QWORD *)(_X19 + 32);
  }
  else
  {
    v23 = 0;
  }
  v24 = *(_QWORD *)(_X19 + 8);
  if ( v24 )
    v25 = *(_DWORD *)(v24 + 24);
  else
    v25 = 0;
  if ( memfree )
  {
    v26 = *(_QWORD *)(_X19 + 48);
    raw_spin_lock(&memfree_lock);
    v27 = memfree;
    v28 = 0;
    v29 = v26 + v23;
    do
    {
      if ( *(_DWORD *)(v27 + v28) == v25 )
      {
        v30 = v27 + v28;
        v31 = *(_QWORD *)(v27 + v28 + 16);
        if ( v31 )
        {
          v32 = *(_QWORD *)(v30 + 8);
          v33 = v32 + v31;
          if ( v23 > v32 && v33 > v23 )
          {
            *(_QWORD *)(v30 + 16) = v23 - v32;
          }
          else if ( v23 <= v32 )
          {
            if ( v29 <= v32 || v29 >= v33 )
            {
              if ( v29 >= v33 )
                *(_QWORD *)(v30 + 16) = 0;
            }
            else
            {
              *(_QWORD *)(v30 + 8) = v29;
            }
          }
        }
      }
      v28 += 40;
    }
    while ( v28 != 20480 );
    raw_spin_unlock(&memfree_lock);
    v23 = *(_QWORD *)(_X19 + 32);
  }
  v34 = *((_QWORD *)a3 + 2);
  *((_QWORD *)a3 + 1) = (*((_QWORD *)a3 + 3) & 0xFFFFFFFFFFFFF000LL) + v23;
  _X10 = &qword_3A8E8;
  __asm { PRFM            #0x11, [X10] }
  do
  {
    v52 = __ldxr((unsigned __int64 *)&qword_3A8E8);
    v53 = v52 + v34;
  }
  while ( __stlxr(v53, (unsigned __int64 *)&qword_3A8E8) );
  __dmb(0xBu);
  if ( v53 > qword_3A8F0 )
    qword_3A8F0 = v53;
  v35 = *((_QWORD *)a3 + 2);
  _X8 = (unsigned __int64 *)&v3[2 * ((unsigned __int8)*(_QWORD *)(_X19 + 80) >> 5) + 26];
  __asm { PRFM            #0x11, [X8] }
  do
  {
    v55 = __ldxr(_X8);
    v56 = v55 + v35;
  }
  while ( __stlxr(v56, _X8) );
  __dmb(0xBu);
  if ( v56 > _X8[1] )
    _X8[1] = v56;
  raw_spin_lock(*(_QWORD *)(_X19 + 256) + 32LL);
  idr_replace(*(_QWORD *)(_X19 + 256) + 40LL, _X19, *(unsigned int *)(_X19 + 248));
  raw_spin_unlock(*(_QWORD *)(_X19 + 256) + 32LL);
  if ( _X19 > 0xFFFFFFFFFFFFF000LL )
    return 0;
  __asm { PRFM            #0x11, [X19] }
  do
    v58 = __ldxr((unsigned int *)_X19);
  while ( __stlxr(v58 - 1, (unsigned int *)_X19) );
  if ( v58 == 1 )
  {
    __dmb(9u);
    kgsl_mem_entry_destroy((_QWORD *)_X19);
    return 0;
  }
  if ( v58 > 0 )
    return 0;
  refcount_warn_saturate(_X19, 3);
  return 0;
}
