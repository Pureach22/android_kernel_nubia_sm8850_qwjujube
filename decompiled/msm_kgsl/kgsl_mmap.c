__int64 __fastcall kgsl_mmap(__int64 a1, __int64 *a2)
{
  __int64 v3; // x2
  _QWORD *v4; // x9
  _QWORD *v5; // x21
  __int64 v6; // x8
  __int64 v7; // x20
  __int64 v8; // x22
  __int64 v9; // x23
  __int64 v10; // x8
  __int64 v11; // x9
  __int64 v12; // x20
  __int64 v13; // x21
  __int64 v14; // x9
  __int64 result; // x0
  __int64 v16; // x20
  __int64 v17; // x8
  __int64 v18; // x21
  __int64 v19; // x8
  int v20; // w8
  __int64 v21; // x21
  unsigned int v22; // w22
  __int64 v24; // x8
  unsigned int v27; // w8
  unsigned int v28; // w8
  unsigned __int64 v34; // x8
  unsigned __int64 v37; // x10
  _QWORD v38[2]; // [xsp+0h] [xbp-10h] BYREF

  v38[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = a2[10];
  v4 = *(_QWORD **)(a1 + 32);
  v38[0] = 0;
  if ( (v3 & 0xFFFFFFFFFFFFFLL) != 0xEFFFF )
  {
    result = get_mmap_entry(v4[1], v38);
    if ( (_DWORD)result )
      goto LABEL_37;
    v16 = v38[0];
    v17 = a2[2];
    v18 = **(unsigned int **)(v38[0] + 72LL);
    if ( (*(_QWORD *)(v17 + 136) & 1) == 0 )
    {
      __break(0x800u);
      v17 = a2[2];
    }
    if ( *((_DWORD *)a2 + 10) != *(_DWORD *)(v17 + 224) )
      _vma_start_write(a2);
    v19 = a2[4];
    a2[12] = v16;
    a2[4] = v19 | v18;
    v20 = (*(_DWORD *)(v16 + 80) >> 26) & 3;
    if ( v20 != 3 )
    {
      if ( v20 != 2 )
      {
        a2[3] = a2[3] & 0xFF9FFFFFFFFFFFE3LL | 0x60000000000008LL;
        a2[9] = (__int64)kgsl_gpumem_vm_ops;
LABEL_29:
        if ( *(_QWORD *)(v16 + 120) )
        {
          fput(a2[11]);
          _X21 = *(unsigned __int64 **)(v16 + 120);
          __asm { PRFM            #0x11, [X21] }
          do
            v34 = __ldxr(_X21);
          while ( __stxr(v34 + 1, _X21) );
          if ( !v34 && (get_file___already_done & 1) == 0 )
          {
            get_file___already_done = 1;
            _warn_printk("struct file::f_count incremented from zero; use-after-free condition present!\n");
            __break(0x800u);
          }
          a2[11] = (__int64)_X21;
        }
        a2[10] = 0;
        _X9 = (unsigned int *)(v16 + 368);
        __asm { PRFM            #0x11, [X9] }
        do
        {
          v27 = __ldxr(_X9);
          v28 = v27 + 1;
        }
        while ( __stlxr(v28, _X9) );
        __dmb(0xBu);
        if ( v28 == 1 )
        {
          v24 = *(_QWORD *)(v16 + 48);
          _X9 = (unsigned __int64 *)(*(_QWORD *)(v16 + 256) + 336LL);
          __asm { PRFM            #0x11, [X9] }
          do
            v37 = __ldxr(_X9);
          while ( __stxr(v37 + v24, _X9) );
        }
LABEL_36:
        result = 0;
        goto LABEL_37;
      }
      if ( (kgsl_mmap___already_done & 1) == 0 )
      {
        kgsl_mmap___already_done = 1;
        _warn_printk("WRITETHROUGH is deprecated for arm64");
        __break(0x800u);
      }
    }
    a2[9] = (__int64)kgsl_gpumem_vm_ops;
    if ( (*(_BYTE *)(v16 + 83) & 0x80) == 0 && *(_DWORD *)(v16 + 112) )
    {
      v21 = *a2;
      v22 = 0;
      do
      {
        vm_insert_page(a2, v21, *(_QWORD *)(*(_QWORD *)(v16 + 104) + 8LL * (int)v22++));
        v21 += 4096;
      }
      while ( v22 < *(_DWORD *)(v16 + 112) );
    }
    goto LABEL_29;
  }
  if ( (a2[4] & 2) == 0 )
  {
    v5 = (_QWORD *)*v4;
    v6 = a2[2];
    v7 = *(_QWORD *)(*v4 + 40LL);
    v8 = a2[1] - *a2;
    if ( (*(_QWORD *)(v6 + 136) & 1) == 0 )
    {
      __break(0x800u);
      v6 = a2[2];
    }
    if ( *((_DWORD *)a2 + 10) != *(_DWORD *)(v6 + 224) )
    {
      v9 = a1;
      _vma_start_write(a2);
      a1 = v9;
    }
    a2[4] &= ~0x20uLL;
    if ( *(_QWORD *)(v7 + 40) != (unsigned int)v8 )
    {
      dev_err(*v5, "Cannot partially map the memstore\n");
      result = 4294967274LL;
      goto LABEL_37;
    }
    v10 = a2[2];
    v11 = a2[3];
    a2[12] = v7;
    a2[3] = v11 & 0xFF9FFFFFFFFFFFE3LL | 0x60000000000008LL;
    v12 = **(unsigned int **)(v7 + 64);
    if ( (*(_QWORD *)(v10 + 136) & 1) == 0 )
    {
      __break(0x800u);
      v10 = a2[2];
    }
    if ( *((_DWORD *)a2 + 10) != *(_DWORD *)(v10 + 224) )
    {
      v13 = a1;
      _vma_start_write(a2);
      a1 = v13;
    }
    v14 = a2[4];
    a2[9] = (__int64)&kgsl_memstore_vm_ops;
    a2[11] = a1;
    a2[4] = v14 | v12;
    goto LABEL_36;
  }
  result = 0xFFFFFFFFLL;
LABEL_37:
  _ReadStatusReg(SP_EL0);
  return result;
}
