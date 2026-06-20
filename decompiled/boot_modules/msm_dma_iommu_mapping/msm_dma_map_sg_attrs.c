__int64 __fastcall msm_dma_map_sg_attrs(
        unsigned __int64 a1,
        unsigned __int64 a2,
        int a3,
        unsigned int a4,
        unsigned __int64 a5,
        __int64 a6)
{
  unsigned __int64 v7; // x21
  _QWORD *v12; // x19
  unsigned __int64 v13; // x8
  unsigned __int64 v14; // x9
  __int64 v15; // x0
  __int64 v16; // x8
  unsigned int v17; // w20
  __int64 v19; // x24
  __int64 *v20; // x23
  __int64 v21; // x8
  __int64 *v22; // x28
  unsigned __int64 v23; // x8
  unsigned __int64 v24; // x2
  __int64 result; // x0
  unsigned int v27; // w26
  __int64 *v28; // x25
  __int64 *v29; // x23
  __int64 v30; // x3
  __int64 v31; // x5
  __int64 v32; // x7
  unsigned __int64 v33; // x10
  __int64 v34; // x9
  unsigned int v35; // w25
  __int64 v36; // x24
  int v37; // w8
  __int64 v38; // x0
  __int64 v40; // x27
  unsigned int v41; // w0
  unsigned int v42; // w20
  void *v43; // x0
  _QWORD *v44; // x28
  __int64 *v45; // x23
  __int64 v46; // x8
  __int64 v47; // x10
  __int64 v48; // x11
  unsigned __int64 v50; // x8
  __int64 v51; // x9
  __int64 v52; // x8
  __int64 v53; // x2
  __int64 v54; // x1
  __int64 v55; // x1
  unsigned int v61; // w8
  unsigned int v63; // w8
  unsigned int v65; // w8
  unsigned int v67; // w8
  __int64 v68; // [xsp+8h] [xbp-28h]
  unsigned int v69; // [xsp+10h] [xbp-20h]
  int v70; // [xsp+14h] [xbp-1Ch]
  int v71; // [xsp+14h] [xbp-1Ch]
  _QWORD v72[3]; // [xsp+18h] [xbp-18h] BYREF

  v72[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 || a1 >= 0xFFFFFFFFFFFFF001LL )
  {
    v43 = &unk_70DD;
LABEL_65:
    printk(v43, "msm_dma_map_sg_attrs");
    result = 4294967274LL;
    goto LABEL_91;
  }
  v7 = a2;
  if ( !a2 || a2 >= 0xFFFFFFFFFFFFF001LL )
  {
    v43 = &unk_70FB;
    goto LABEL_65;
  }
  if ( !a5 || a5 >= 0xFFFFFFFFFFFFF001LL )
  {
    v43 = &unk_6E2F;
    goto LABEL_65;
  }
  mutex_lock(&msm_iommu_map_mutex);
  v12 = (_QWORD *)iommu_root;
  if ( iommu_root )
  {
    v13 = *(_QWORD *)(a5 + 112);
    while ( 1 )
    {
      while ( 1 )
      {
        v14 = v12[12];
        if ( v14 <= v13 )
          break;
        v12 = (_QWORD *)v12[2];
        if ( !v12 )
          goto LABEL_13;
      }
      if ( v14 >= v13 )
        break;
      v12 = (_QWORD *)v12[1];
      if ( !v12 )
        goto LABEL_13;
    }
    _X0 = (unsigned int *)(v12 + 5);
    __asm { PRFM            #0x11, [X0] }
    do
      v61 = __ldxr(_X0);
    while ( __stxr(v61 + 1, _X0) );
    if ( !v61 || (((v61 + 1) | v61) & 0x80000000) != 0 )
      ((void (*)(void))refcount_warn_saturate)();
    goto LABEL_33;
  }
LABEL_13:
  v15 = _kmalloc_cache_noprof(memstart_addr, 3520, 104);
  v12 = (_QWORD *)v15;
  if ( !v15 )
  {
    mutex_unlock(&msm_iommu_map_mutex);
    result = 4294967284LL;
    goto LABEL_91;
  }
  v70 = a3;
  *(_QWORD *)(v15 + 24) = v15 + 24;
  *(_QWORD *)(v15 + 32) = v15 + 24;
  v16 = *(_QWORD *)(a5 + 112);
  v17 = a4;
  *(_DWORD *)(v15 + 40) = 1;
  _X25 = (unsigned int *)(v15 + 40);
  v19 = a6;
  *(_QWORD *)(v15 + 96) = v16;
  _mutex_init(v15 + 48, "&meta->lock", &msm_iommu_meta_create___key);
  v20 = &iommu_root;
  v21 = iommu_root;
  if ( iommu_root )
  {
    do
    {
      v22 = (__int64 *)v21;
      v23 = v12[12];
      v24 = v22[12];
      if ( v23 < v24 )
      {
        v20 = v22 + 2;
      }
      else if ( v23 > v24 )
      {
        v20 = v22 + 1;
      }
      else
      {
        printk(&unk_6E8C, "msm_iommu_meta_add");
      }
      v21 = *v20;
    }
    while ( *v20 );
  }
  else
  {
    v22 = nullptr;
  }
  *v12 = v22;
  v12[1] = 0;
  v12[2] = 0;
  *v20 = (__int64)v12;
  rb_insert_color(v12, &iommu_root);
  if ( (unsigned __int64)v12 > 0xFFFFFFFFFFFFF000LL )
  {
    mutex_unlock(&msm_iommu_map_mutex);
    result = (unsigned int)v12;
    goto LABEL_91;
  }
  a6 = v19;
  if ( (v19 & 0x2000) != 0 )
  {
    a4 = v17;
    a3 = v70;
LABEL_33:
    v27 = 0;
    goto LABEL_34;
  }
  a4 = v17;
  __asm { PRFM            #0x11, [X25] }
  do
    v63 = __ldxr(_X25);
  while ( __stxr(v63 + 1, _X25) );
  a3 = v70;
  if ( !v63 )
  {
    v27 = 2;
LABEL_98:
    refcount_warn_saturate(v12 + 5, v27);
    v27 = 1;
    goto LABEL_34;
  }
  v27 = 1;
  if ( (((v63 + 1) | v63) & 0x80000000) != 0 )
    goto LABEL_98;
LABEL_34:
  mutex_unlock(&msm_iommu_map_mutex);
  mutex_lock(v12 + 6);
  v28 = v12 + 3;
  v29 = v12 + 3;
  do
  {
    v29 = (__int64 *)*v29;
    if ( v29 == v28 )
      goto LABEL_55;
  }
  while ( v29[5] != a1 );
  if ( v29 )
  {
    v31 = *((unsigned int *)v29 + 14);
    v30 = *((unsigned int *)v29 + 15);
    if ( __PAIR64__(v30, v31) == __PAIR64__(a4, a3) )
    {
      v32 = v29[10];
      v33 = memstart_addr;
      v34 = *(_QWORD *)v7;
      if ( ((v32 ^ a6) & 0xFFFFFFFFFFFFFFDFLL) != 0 )
      {
        v30 = a4;
      }
      else
      {
        v30 = a4;
        if ( *(unsigned int *)(v7 + 8)
           + (((v34 & 0x3FFFFFFFFFFFFFCLL) + ((memstart_addr >> 6) & 0x3FFFFFFFFFFFFC0LL) + 0x140000000LL) << 6) == v29[11] )
        {
          v35 = a3;
          if ( a3 >= 1 )
          {
            v36 = v29[6];
            do
            {
              *(_QWORD *)(v7 + 16) = *(_QWORD *)(v36 + 16);
              v37 = *(_DWORD *)(v36 + 24);
              *(_DWORD *)(v7 + 24) = v37;
              if ( !v37 )
                break;
              v38 = sg_next(v7);
              if ( !v38 )
                break;
              v7 = v38;
              --a3;
              v36 = sg_next(v36);
            }
            while ( a3 );
          }
          _X0 = (unsigned int *)(v29 + 9);
          __asm { PRFM            #0x11, [X0] }
          do
            v65 = __ldxr(_X0);
          while ( __stxr(v65 + 1, _X0) );
          if ( v65 )
          {
            if ( (((v65 + 1) | v65) & 0x80000000) == 0 )
            {
              if ( (a6 & 0x20) != 0 )
              {
LABEL_51:
                if ( (*(_BYTE *)(a1 + 844) & 0x20) != 0 )
                  __dmb(0xBu);
                v69 = v35;
                goto LABEL_54;
              }
LABEL_49:
              if ( (*(_BYTE *)(a1 + 844) & 0x40) == 0 )
                _dma_sync_sg_for_device(a1, v29[6], *((unsigned int *)v29 + 14), *((unsigned int *)v29 + 15));
              goto LABEL_51;
            }
            v54 = 1;
          }
          else
          {
            v54 = 2;
          }
          refcount_warn_saturate(_X0, v54);
          if ( (a6 & 0x20) != 0 )
            goto LABEL_51;
          goto LABEL_49;
        }
      }
    }
    else
    {
      v34 = *(_QWORD *)v7;
      v32 = v29[10];
      v33 = memstart_addr;
    }
    dev_err(
      a1,
      "lazy map request differs:\n"
      "req dir:%d, original dir:%d\n"
      "req nents:%d, original nents:%d\n"
      "req map attrs:%lu, original map attrs:%lu\n"
      "req buffer start address differs:%d\n",
      a4,
      v30,
      (unsigned int)a3,
      v31,
      a6,
      v32,
      *(unsigned int *)(v7 + 8)
    + (((v34 & 0x3FFFFFFFFFFFFFCLL) + ((v33 >> 6) & 0x3FFFFFFFFFFFFC0LL) + 0x140000000LL) << 6) != v29[11]);
    v69 = -22;
LABEL_54:
    mutex_unlock(v12 + 6);
    result = v69;
    goto LABEL_91;
  }
LABEL_55:
  v40 = _kmalloc_cache_noprof(_kmalloc_cache_noprof, 3264, 96);
  if ( !v40 )
  {
    v42 = -12;
    goto LABEL_86;
  }
  v41 = dma_map_sg_attrs(a1, v7, (unsigned int)a3, a4, a6);
  if ( !v41 )
  {
    v42 = 0;
    goto LABEL_61;
  }
  v69 = v41;
  v72[0] = 0;
  v72[1] = 0;
  if ( !(unsigned int)sg_alloc_table(v72, (unsigned int)a3, 3264) )
  {
    v68 = a6;
    v44 = (_QWORD *)v72[0];
    if ( a3 >= 1 )
    {
      v45 = (__int64 *)v7;
      v71 = a3;
      do
      {
        v46 = v45[3];
        v47 = *v45;
        v48 = v45[1];
        v44[2] = v45[2];
        v44[3] = v46;
        *v44 = v47;
        v44[1] = v48;
        v44 = (_QWORD *)sg_next(v44);
        --a3;
        v45 = (__int64 *)sg_next(v45);
      }
      while ( a3 );
      v44 = (_QWORD *)v72[0];
      a3 = v71;
    }
    *(_QWORD *)(v40 + 48) = v44;
    if ( !v44 )
      goto LABEL_59;
    *(_DWORD *)(v40 + 72) = 1;
    _X0 = (unsigned int *)(v40 + 72);
    v50 = memstart_addr;
    v51 = *(_QWORD *)v7;
    *(_DWORD *)(v40 + 56) = a3;
    *(_DWORD *)(v40 + 60) = a4;
    *(_QWORD *)(v40 + 40) = a1;
    v52 = *(unsigned int *)(v7 + 8)
        + (((v51 & 0x3FFFFFFFFFFFFFCLL) + ((v50 >> 6) & 0x3FFFFFFFFFFFFC0LL) + 0x140000000LL) << 6);
    *(_QWORD *)(v40 + 80) = v68;
    *(_QWORD *)(v40 + 88) = v52;
    if ( (v68 & 0x2000) == 0 )
    {
      __asm { PRFM            #0x11, [X0] }
      do
        v67 = __ldxr(_X0);
      while ( __stxr(v67 + 1, _X0) );
      if ( !v67 )
      {
        v55 = 2;
        goto LABEL_107;
      }
      if ( (((v67 + 1) | v67) & 0x80000000) != 0 )
      {
        v55 = 1;
LABEL_107:
        refcount_warn_saturate(_X0, v55);
      }
    }
    *(_QWORD *)(v40 + 64) = v12;
    *(_QWORD *)v40 = v40;
    *(_QWORD *)(v40 + 8) = v40;
    v53 = v12[3];
    if ( *(__int64 **)(v53 + 8) != v28 || v28 == (__int64 *)v40 || v53 == v40 )
    {
      _list_add_valid_or_report(v40, v12 + 3);
    }
    else
    {
      *(_QWORD *)(v53 + 8) = v40;
      *(_QWORD *)v40 = v53;
      *(_QWORD *)(v40 + 8) = v28;
      *v28 = v40;
    }
    goto LABEL_54;
  }
  *(_QWORD *)(v40 + 48) = 0;
LABEL_59:
  v42 = -12;
LABEL_61:
  kfree(v40);
LABEL_86:
  mutex_unlock(v12 + 6);
  if ( (unsigned __int64)v12 <= 0xFFFFFFFFFFFFF000LL )
  {
    if ( v27 )
      msm_iommu_meta_put(v12);
    msm_iommu_meta_put(v12);
  }
  result = v42;
LABEL_91:
  _ReadStatusReg(SP_EL0);
  return result;
}
