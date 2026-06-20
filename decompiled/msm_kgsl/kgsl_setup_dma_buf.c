__int64 __fastcall kgsl_setup_dma_buf(_QWORD *a1, __int64 a2, __int64 a3, __int64 a4)
{
  _QWORD *v8; // x20
  unsigned __int64 v9; // x0
  unsigned __int64 v10; // x22
  unsigned __int64 v11; // x23
  unsigned int v12; // w24
  __int64 v13; // x8
  unsigned __int64 v14; // x0
  int v15; // w25
  unsigned int v16; // w24
  int v17; // w25
  __int64 i; // x0
  __int64 v19; // x21
  unsigned __int64 v20; // x23
  _UNKNOWN **v21; // x1
  _QWORD *v22; // x0
  _QWORD *v23; // x1
  _QWORD *v24; // x2
  _QWORD **v25; // t1
  __int64 v26; // x0
  _QWORD *v27; // x9
  void *v28; // x2
  void *v29; // x8
  _QWORD *v30; // x2
  _QWORD *v31; // x0
  __int64 v32; // x8
  __int64 v33; // x10
  unsigned __int64 v41; // x3
  int v42; // [xsp+4h] [xbp-1Ch] BYREF
  __int64 v43; // [xsp+8h] [xbp-18h] BYREF
  _QWORD v44[2]; // [xsp+10h] [xbp-10h] BYREF

  v44[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = (_QWORD *)_kmalloc_cache_noprof(raw_read_unlock, 3520, 56);
  if ( !v8 )
  {
    v12 = -12;
    goto LABEL_54;
  }
  v9 = dma_buf_attach(a4, *a1);
  v10 = v9;
  if ( v9 > 0xFFFFFFFFFFFFF000LL )
  {
    v11 = 0;
    v12 = v9;
    goto LABEL_17;
  }
  v13 = *(_QWORD *)(a3 + 80);
  if ( (v13 & 0x80000000) != 0 )
  {
    *(_QWORD *)(v9 + 72) |= 0x20uLL;
    v13 = *(_QWORD *)(a3 + 80);
  }
  v8[1] = v9;
  v8[2] = a4;
  *v8 = a3;
  *(_QWORD *)(a3 + 216) = v8;
  *(_QWORD *)(a3 + 8) = a2;
  *(_QWORD *)(a3 + 48) = 0;
  *(_QWORD *)(a3 + 72) = &kgsl_dmabuf_ops;
  *(_QWORD *)(a3 + 80) = v13 & 0xFFFFFFFFEFFFFF7FLL | 0x80;
  v14 = dma_buf_map_attachment_unlocked(v9, 0);
  v11 = v14;
  if ( !v14 || v14 > 0xFFFFFFFFFFFFF000LL )
  {
    v12 = v14;
    if ( !(_DWORD)v14 )
      goto LABEL_54;
LABEL_17:
    if ( v11 )
      goto LABEL_18;
    goto LABEL_20;
  }
  v8[3] = v14;
  *(_QWORD *)(a3 + 216) = v8;
  *(_QWORD *)(a3 + 64) = v14;
  v15 = *(_DWORD *)(a3 + 56);
  v43 = 0;
  v44[0] = 0;
  v42 = 0;
  if ( (unsigned int)mem_buf_dma_buf_copy_vmperm(a4, v44, &v43, &v42) )
  {
    dev_info(*a1, "Skipped access check\n");
  }
  else
  {
    v16 = v15 & 0x10;
    v17 = 0;
    if ( v42 )
    {
      while ( *(_DWORD *)(v44[0] + 4LL * v17) != 10 )
      {
        if ( v42 == ++v17 )
        {
          v17 = v42;
          break;
        }
      }
    }
    kfree(v44[0]);
    kfree(v43);
    if ( (v17 == v42) == v16 >> 4 || v16 && (mem_buf_dma_buf_exclusive_owner(a4) & 1) != 0 )
    {
      v12 = -1;
      if ( v11 )
        goto LABEL_18;
      goto LABEL_20;
    }
  }
  for ( i = **(_QWORD **)(a3 + 64); i; i = sg_next(i) )
    *(_QWORD *)(a3 + 48) += *(unsigned int *)(i + 12);
  if ( !*(_QWORD *)(a3 + 48) )
  {
    v12 = -22;
    if ( v11 )
    {
LABEL_18:
      if ( v11 <= 0xFFFFFFFFFFFFF000LL )
        dma_buf_unmap_attachment_unlocked(v10, v11, 0);
    }
LABEL_20:
    if ( v10 && v10 <= 0xFFFFFFFFFFFFF000LL )
      dma_buf_detach(a4, v10);
    kfree(v8);
    goto LABEL_54;
  }
  v19 = *(_QWORD *)(*(_QWORD *)(v8[1] + 8LL) + 152LL);
  v20 = **(_QWORD **)v8[3] & 0xFFFFFFFFFFFFFFFCLL;
  raw_spin_lock(&kgsl_dmabuf_lock);
  v21 = &kgsl_dmabuf_list;
  while ( 1 )
  {
    v21 = (_UNKNOWN **)*v21;
    if ( v21 == &kgsl_dmabuf_list )
      break;
    if ( *(v21 - 1) == (_UNKNOWN *)v20 )
    {
      v22 = v8 + 5;
      v8[4] = v21 - 1;
      v25 = (_QWORD **)v21[2];
      v23 = v21 + 2;
      v24 = v25;
      if ( v25[1] != v23 || v22 == v23 || v24 == v22 )
      {
        _list_add_valid_or_report(v22, v23);
      }
      else
      {
        v24[1] = v22;
        v8[5] = v24;
        v8[6] = v23;
        *v23 = v22;
      }
      goto LABEL_49;
    }
  }
  v26 = _kmalloc_cache_noprof(raw_read_unlock, 2336, 40);
  if ( v26 )
  {
    v27 = (_QWORD *)(v26 + 24);
    *(_QWORD *)v26 = v20;
    *(_QWORD *)(v26 + 24) = v26 + 24;
    *(_QWORD *)(v26 + 32) = v26 + 24;
    v28 = kgsl_dmabuf_list;
    v29 = (void *)(v26 + 8);
    if ( *(_UNKNOWN ***)((char *)&dword_8 + (_QWORD)kgsl_dmabuf_list) != &kgsl_dmabuf_list || kgsl_dmabuf_list == v29 )
    {
      _list_add_valid_or_report(v26 + 8, &kgsl_dmabuf_list);
      v26 = v33;
    }
    else
    {
      *(_QWORD *)((char *)&dword_8 + (_QWORD)kgsl_dmabuf_list) = v29;
      *(_QWORD *)(v26 + 8) = v28;
      *(_QWORD *)(v26 + 16) = &kgsl_dmabuf_list;
      kgsl_dmabuf_list = (_UNKNOWN *)(v26 + 8);
    }
    v30 = *(_QWORD **)(v26 + 24);
    v8[4] = v26;
    v31 = v8 + 5;
    if ( (_QWORD *)v30[1] != v27 || v31 == v27 || v30 == v31 )
    {
      _list_add_valid_or_report(v31, v27);
    }
    else
    {
      v30[1] = v31;
      v8[5] = v30;
      v8[6] = v27;
      *v27 = v31;
    }
    v32 = *(_QWORD *)(*v8 + 48LL);
    _X9 = (unsigned __int64 *)(v19 + 11136);
    __asm { PRFM            #0x11, [X9] }
    do
      v41 = __ldxr(_X9);
    while ( __stlxr(v41 + v32, _X9) );
    __dmb(0xBu);
  }
LABEL_49:
  raw_spin_unlock(&kgsl_dmabuf_lock);
  v12 = 0;
  *(_QWORD *)(a3 + 48) = (*(_QWORD *)(a3 + 48) + 4095LL) & 0xFFFFFFFFFFFFF000LL;
LABEL_54:
  _ReadStatusReg(SP_EL0);
  return v12;
}
