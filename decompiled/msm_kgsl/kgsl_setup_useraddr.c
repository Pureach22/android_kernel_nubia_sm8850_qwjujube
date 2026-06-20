__int64 __fastcall kgsl_setup_useraddr(__int64 a1, __int64 a2, _QWORD *a3, __int64 a4, __int64 a5, unsigned __int64 a6)
{
  __int64 result; // x0
  __int64 user_pages; // x24
  _QWORD *v10; // x20
  __int64 v11; // x10
  __int64 v12; // x9
  __int64 v13; // x21
  __int64 v14; // x23
  unsigned __int64 v15; // x22
  unsigned int v16; // w25
  unsigned __int64 v17; // x27
  unsigned __int64 v18; // x22
  __int64 v19; // x21
  __int64 v20; // x0
  unsigned __int64 StatusReg; // x28
  __int64 vma; // x0
  __int64 v23; // x8
  int v25; // w23
  __int64 v26; // x8
  bool v27; // zf
  int v28; // w8
  unsigned __int64 v29; // x1
  int v30; // w0
  unsigned __int64 v31; // x26
  __int64 v32; // x0
  __int64 v33; // x8
  unsigned int v39; // w27
  int v40; // w0
  int v41; // w23
  unsigned __int64 v42; // x23
  __int64 v43; // x26
  __int64 v44; // x8
  void (__fastcall *v45)(_QWORD); // x8
  unsigned int v46; // w19
  unsigned __int64 v47; // [xsp+8h] [xbp-18h]
  __int64 v48; // [xsp+10h] [xbp-10h]
  __int64 v49; // [xsp+18h] [xbp-8h]

  result = 4294967274LL;
  if ( !a4 )
    return result;
  user_pages = a4;
  if ( (a4 & 0xFFF) != 0 || !a6 || a6 & 0xFFF | a5 )
    return result;
  a3[1] = a2;
  v10 = a3 + 1;
  v11 = a3[10];
  a3[6] = a6;
  LODWORD(v12) = v11 | 0x60;
  a3[9] = &kgsl_usermem_ops;
  a3[10] = v11 | 0x60;
  if ( (v11 & 0x10000000) != 0 )
  {
    v13 = a2;
    v14 = a1;
    v15 = a6;
    result = kgsl_mmu_set_svm_region(a2, a4, a6);
    if ( (_DWORD)result == -12 )
    {
      _flush_workqueue(qword_3A908);
      result = kgsl_mmu_set_svm_region(v13, user_pages, v15);
    }
    if ( (_DWORD)result )
      return result;
    a6 = a3[6];
    v12 = a3[10];
    a2 = v13;
    a1 = v14;
    a3[4] = user_pages;
  }
  v16 = (v12 & 0x1000000) == 0;
  if ( a6 >= 0x1000 )
  {
    v17 = a6 >> 12;
    v48 = a1;
    v49 = a2;
    v18 = 8 * (a6 >> 12);
    v19 = _kvmalloc_node_noprof(v18, 0, 3520, 0xFFFFFFFFLL);
    a2 = v49;
    if ( v19 )
    {
      while ( 1 )
      {
        v20 = _kmalloc_cache_noprof(raw_read_lock, 3264, 16);
        a3[8] = v20;
        if ( !v20 )
          break;
        StatusReg = _ReadStatusReg(SP_EL0);
        v47 = v17;
        down_read(*(_QWORD *)(StatusReg + 1672) + 136LL);
        vma = find_vma(*(_QWORD *)(StatusReg + 1672), user_pages);
        if ( !vma || *(_QWORD *)(vma + 88) && *(__int64 (__fastcall ***)())(vma + 72) == kgsl_gpumem_vm_ops )
        {
LABEL_34:
          up_read(*(_QWORD *)(StatusReg + 1672) + 136LL);
          v16 = -14;
          goto LABEL_61;
        }
        v23 = *(_QWORD *)(vma + 24);
        v25 = v23 != (v23 & 0xFF9FFFFFFFFFFFE3LL | 0x60000000000008LL)
           && v23 != (v23 & 0xFF9FFFFFFFFFFFE3LL | 0x6000000000000CLL);
        while ( 1 )
        {
          v29 = *(_QWORD *)(vma + 8);
          if ( v29 >= a3[6] + user_pages )
            break;
          vma = find_vma(*(_QWORD *)(StatusReg + 1672), v29);
          if ( vma && (!*(_QWORD *)(vma + 88) || *(__int64 (__fastcall ***)())(vma + 72) != kgsl_gpumem_vm_ops) )
          {
            v26 = *(_QWORD *)(vma + 24);
            v27 = v26 == (v26 & 0xFF9FFFFFFFFFFFE3LL | 0x60000000000008LL)
               || v26 == (v26 & 0xFF9FFFFFFFFFFFE3LL | 0x6000000000000CLL);
            v28 = !v27;
            if ( v25 == v28 )
              continue;
          }
          goto LABEL_34;
        }
        if ( v25 && (*(_QWORD *)(v48 + 104) & 8) != 0 )
          a3[10] |= 0x80000000uLL;
        user_pages = get_user_pages(user_pages, v17, v16, v19);
        up_read(*(_QWORD *)(StatusReg + 1672) + 136LL);
        v30 = user_pages & (user_pages >> 63);
        if ( !v30 )
        {
          if ( user_pages == v17 )
          {
            v30 = sg_alloc_table_from_pages_segment(a3[8], v19, (unsigned int)user_pages, 0, a3[6], 0xFFFFFFFFLL, 3264);
            if ( v30 )
            {
              user_pages = v17;
            }
            else
            {
              v40 = kgsl_cache_range_op(v10, 0, a3[6], 2);
              if ( !v40 )
              {
                kvfree(v19);
                return 0;
              }
              v41 = v40;
              sg_free_table(a3[8]);
              user_pages = v17;
              v30 = v41;
            }
          }
          else
          {
            v30 = -22;
          }
        }
        v16 = v30;
        if ( user_pages < 1 )
          goto LABEL_61;
        v31 = 0;
        while ( 8 * v47 != v31 && v18 > v31 )
        {
          v32 = *(_QWORD *)(v19 + v31);
          v33 = *(_QWORD *)(v32 + 8);
          if ( (v33 & 1) != 0 )
            v32 = v33 - 1;
          _X8 = (unsigned int *)(v32 + 52);
          __asm { PRFM            #0x11, [X8] }
          do
          {
            v39 = __ldxr(_X8);
            v17 = v39 - 1;
          }
          while ( __stlxr(v17, _X8) );
          __dmb(0xBu);
          if ( !(_DWORD)v17 )
            _folio_put();
          --user_pages;
          v31 += 8LL;
          if ( !user_pages )
            goto LABEL_61;
        }
        __break(1u);
        v18 = 8 * v17;
        v42 = _ReadStatusReg(SP_EL0);
        v43 = *(_QWORD *)(v42 + 80);
        *(_QWORD *)(v42 + 80) = &memdesc_sg_virt__alloc_tag;
        v19 = _kvmalloc_node_noprof(8 * v17, 0, 3520, 0xFFFFFFFFLL);
        *(_QWORD *)(v42 + 80) = v43;
        a2 = v49;
        if ( !v19 )
          goto LABEL_59;
      }
      v16 = -12;
LABEL_61:
      kfree(a3[8]);
      a3[8] = 0;
      kvfree(v19);
      a2 = v49;
      result = v16;
    }
    else
    {
LABEL_59:
      result = 4294967284LL;
    }
  }
  else
  {
    result = 4294967274LL;
  }
  if ( a2 )
  {
    if ( (a3[10] & 0x10000000) != 0 )
    {
      v44 = *(_QWORD *)(a2 + 96);
      if ( v44 )
      {
        v45 = *(void (__fastcall **)(_QWORD))(v44 + 80);
        if ( v45 )
        {
          v46 = result;
          if ( *((_DWORD *)v45 - 1) != 1555154090 )
            __break(0x8228u);
          v45(v10);
          return v46;
        }
      }
    }
  }
  return result;
}
