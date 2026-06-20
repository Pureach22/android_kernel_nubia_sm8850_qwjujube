__int64 __fastcall msm_cvp_map_buf_wncc(__int64 a1, _DWORD *a2)
{
  __int64 result; // x0
  unsigned __int64 v3; // x9
  __int64 v4; // x2
  void *v5; // x0
  __int64 v6; // x1
  unsigned __int64 v7; // x8
  unsigned __int64 v8; // x8
  unsigned __int64 StatusReg; // x8
  __int64 v10; // x23
  __int64 v13; // x20
  unsigned __int64 dma_buf; // x0
  __int64 v15; // x24
  __int64 v16; // x0
  __int64 v17; // x20
  __int64 v18; // x0
  __int64 v19; // x21
  char v20; // w9
  int v21; // w0
  int v22; // w23
  int v23; // w0
  __int64 v24; // x8
  unsigned __int64 v25; // x8
  int v26; // w9
  __int64 v27; // x0
  __int64 v28; // x8
  __int64 v29; // x24
  __int64 v30; // x28
  __int64 v31; // x8
  char v32; // w9
  unsigned __int64 v33; // x8
  unsigned __int64 v34; // x8
  int v35; // w19
  unsigned int v36; // w19
  unsigned __int64 v37; // x8
  unsigned __int64 v38; // x8

  if ( !a1 || !a2 || !*(_QWORD *)(a1 + 128) )
  {
    result = 4294967274LL;
    if ( (msm_cvp_debug & 1) == 0 || msm_cvp_debug_out )
      return result;
    StatusReg = _ReadStatusReg(SP_EL0);
    v6 = *(unsigned int *)(StatusReg + 1800);
    v4 = *(unsigned int *)(StatusReg + 1804);
    v5 = &unk_8B4A1;
LABEL_9:
    printk(v5, v6, v4, &unk_8E7CE);
    return 4294967274LL;
  }
  if ( !*(_QWORD *)(a1 + 320) )
  {
    result = 4294967274LL;
    if ( (msm_cvp_debug & 1) == 0 || msm_cvp_debug_out )
      return result;
    v7 = _ReadStatusReg(SP_EL0);
    v6 = *(unsigned int *)(v7 + 1800);
    v4 = *(unsigned int *)(v7 + 1804);
    v5 = &unk_8D1CE;
    goto LABEL_9;
  }
  if ( *a2 )
  {
    result = 4294967274LL;
    if ( (msm_cvp_debug & 1) == 0 || msm_cvp_debug_out )
      return result;
    v3 = _ReadStatusReg(SP_EL0);
    v4 = *(unsigned int *)(v3 + 1804);
    v5 = &unk_94526;
    v6 = *(unsigned int *)(v3 + 1800);
    goto LABEL_9;
  }
  if ( a2[4] )
  {
    result = 4294967274LL;
    if ( (msm_cvp_debug & 1) == 0 || msm_cvp_debug_out )
      return result;
    v8 = _ReadStatusReg(SP_EL0);
    v6 = *(unsigned int *)(v8 + 1800);
    v4 = *(unsigned int *)(v8 + 1804);
    v5 = &unk_970B4;
    goto LABEL_9;
  }
  v10 = a1 + 600;
  mutex_lock(a1 + 616);
  v13 = v10;
  while ( 1 )
  {
    v13 = *(_QWORD *)v13;
    if ( v13 == v10 )
      break;
    if ( *(_DWORD *)(v13 + 16) == a2[2] )
    {
      if ( *(_DWORD *)(v13 + 20) == a2[3] )
      {
        mutex_unlock(a1 + 616);
        print_internal_buffer(1, "duplicate", a1, v13);
        return 4294967274LL;
      }
      else
      {
        v24 = a1;
        if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
        {
          v33 = _ReadStatusReg(SP_EL0);
          printk(&unk_8F6A6, *(unsigned int *)(v33 + 1800), *(unsigned int *)(v33 + 1804), &unk_8E7CE);
          v24 = a1;
        }
        mutex_unlock(v24 + 616);
        return 4294967274LL;
      }
    }
  }
  mutex_unlock(a1 + 616);
  dma_buf = msm_cvp_smem_get_dma_buf();
  if ( !dma_buf )
  {
    result = 4294967274LL;
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      v25 = _ReadStatusReg(SP_EL0);
      v6 = *(unsigned int *)(v25 + 1800);
      v4 = *(unsigned int *)(v25 + 1804);
      v5 = &unk_84FD6;
      goto LABEL_9;
    }
    return result;
  }
  v15 = dma_buf;
  v16 = cvp_kmem_cache_zalloc(cvp_driver + 104, 3264);
  if ( !v16 )
  {
LABEL_45:
    msm_cvp_smem_put_dma_buf(v15);
    return 4294967284LL;
  }
  v17 = v16;
  v18 = cvp_kmem_cache_zalloc(cvp_driver + 120, 3264);
  if ( !v18 )
  {
    cvp_kmem_cache_free(cvp_driver + 104, v17);
    goto LABEL_45;
  }
  *(_QWORD *)(v18 + 48) = v15;
  v19 = v18;
  *(_BYTE *)(v18 + 84) = 0;
  v20 = msm_cvp_debug;
  *(_QWORD *)(v18 + 92) = 0;
  *(_DWORD *)(v18 + 100) = a2[2];
  if ( (v20 & 0x40) != 0 && !msm_cvp_debug_out )
    printk(&unk_83B25, &unk_84256, "msm_cvp_map_buf_wncc", v15);
  v21 = msm_cvp_map_smem(a1, v19, (__int64)"map wncc");
  if ( v21 )
  {
    v22 = v21;
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      v37 = _ReadStatusReg(SP_EL0);
      printk(&unk_93275, *(unsigned int *)(v37 + 1800), *(unsigned int *)(v37 + 1804), &unk_8E7CE);
    }
    print_client_buffer(1, (__int64)"msm_cvp_map_buf_wncc", a1, (__int64)a2);
    v23 = v22;
    goto LABEL_60;
  }
  *(_QWORD *)(v17 + 56) = v19;
  *(_DWORD *)(v17 + 16) = a2[2];
  *(_DWORD *)(v17 + 20) = a2[3];
  v26 = a2[4];
  *(_DWORD *)(v17 + 48) = 1;
  *(_DWORD *)(v17 + 24) = v26;
  *(_DWORD *)(v17 + 32) = *a2;
  mutex_lock(a1 + 616);
  v27 = *(_QWORD *)(a1 + 12928);
  v28 = a1;
  if ( !v27 )
  {
    v27 = _kmalloc_large_noprof(28800, 3520);
    v28 = a1;
    *(_QWORD *)(a1 + 12928) = v27;
    if ( !v27 )
    {
      mutex_unlock(a1 + 616);
      v23 = 0;
LABEL_60:
      if ( *(_DWORD *)(v19 + 64) )
      {
        v23 = msm_cvp_unmap_smem(a1, v19, (__int64)"unmap wncc");
        if ( v23 )
        {
          if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
          {
            v34 = _ReadStatusReg(SP_EL0);
            v35 = v23;
            printk(&unk_86E2C, *(unsigned int *)(v34 + 1800), *(unsigned int *)(v34 + 1804), &unk_8E7CE);
            v23 = v35;
          }
        }
        else
        {
          msm_cvp_smem_put_dma_buf(*(_QWORD *)(v19 + 48));
          v23 = 0;
        }
      }
      v36 = v23;
      cvp_kmem_cache_free(cvp_driver + 104, v17);
      cvp_kmem_cache_free(cvp_driver + 120, v19);
      return v36;
    }
  }
  v29 = 0;
  v30 = 1;
  while ( *(_DWORD *)(v27 + 4 + v29) )
  {
    ++v30;
    v29 += 12;
    if ( v30 == 2401 )
    {
      if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
      {
        v38 = _ReadStatusReg(SP_EL0);
        printk(&unk_93C46, *(unsigned int *)(v38 + 1800), *(unsigned int *)(v38 + 1804), &unk_8E7CE);
        v28 = a1;
      }
      mutex_unlock(v28 + 616);
      v23 = -122;
      goto LABEL_60;
    }
  }
  list_add_tail_0(v17, v10);
  v31 = a1;
  ++*(_DWORD *)(a1 + 12920);
  *(_DWORD *)(*(_QWORD *)(a1 + 12928) + v29) = a2[2];
  *(_DWORD *)(*(_QWORD *)(a1 + 12928) + v29 + 4) = *(_DWORD *)(v19 + 64);
  *(_DWORD *)(*(_QWORD *)(a1 + 12928) + v29 + 8) = *(_DWORD *)(v19 + 80);
  v32 = msm_cvp_debug;
  a2[7] = v30;
  *(_QWORD *)(v17 + 40) = v30;
  if ( (v32 & 0x40) != 0 && !msm_cvp_debug_out )
  {
    printk(&unk_86E02, &unk_84256, "msm_cvp_map_buf_wncc", *(unsigned int *)(*(_QWORD *)(a1 + 12928) + v29 + 4));
    v31 = a1;
  }
  mutex_unlock(v31 + 616);
  return 0;
}
