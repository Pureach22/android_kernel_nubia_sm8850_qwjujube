unsigned int *__fastcall kgsl_sharedmem_bind_worker(__int64 a1)
{
  __int64 v1; // x27
  __int64 v2; // x19
  __int64 v3; // x25
  __int64 v4; // x21
  __int64 v5; // x8
  unsigned __int64 v6; // x22
  unsigned __int64 v7; // x24
  __int64 v8; // x23
  __int64 v9; // x26
  unsigned __int64 v10; // x0
  unsigned int **v11; // x20
  __int64 v12; // x0
  unsigned __int64 v13; // x27
  __int64 v14; // x28
  __int64 v15; // x26
  unsigned int **v16; // x20
  unsigned __int64 v17; // x1
  unsigned __int64 v18; // x2
  unsigned int *result; // x0
  unsigned __int64 v20; // x8
  __int64 v21; // x8
  unsigned int v29; // w9
  int v31; // w8
  __int64 v32; // x0
  __int64 v33; // x20
  unsigned int **v34; // x25
  __int64 v35; // x26
  unsigned int v39; // w9
  int v41; // w8
  int v42; // w0
  unsigned int v46; // w9
  int v48; // w8
  __int64 (__fastcall *v49)(_QWORD); // x8
  int v51; // w8
  __int64 v53; // [xsp+18h] [xbp-18h]
  unsigned int **v54; // [xsp+20h] [xbp-10h]

  v1 = a1;
  if ( *(int *)(a1 - 24) >= 1 )
  {
    v2 = 0;
    _ReadStatusReg(SP_EL0);
    do
    {
      v4 = *(_QWORD *)(v1 - 40);
      v5 = *(_QWORD *)(v1 - 32) + 32 * v2;
      v6 = *(_QWORD *)v5;
      v7 = *(_QWORD *)(v5 + 8);
      v8 = *(_QWORD *)(v5 + 24);
      if ( *(_DWORD *)(v5 + 20) == 1 )
      {
        v9 = *(unsigned int *)(v5 + 16);
        v10 = bind_range_create(*(_QWORD *)v5, *(_QWORD *)(v5 + 8), *(_QWORD *)(v5 + 24));
        if ( v10 > 0xFFFFFFFFFFFFF000LL )
          goto LABEL_5;
        v3 = v4 + 144;
        v11 = (unsigned int **)v10;
        mutex_lock(v4 + 144);
        if ( (*(_BYTE *)(v4 + 84) & 8) == 0
          && (unsigned int)kgsl_mmu_unmap_range(*(_QWORD *)(v4 + 8), v4 + 8, v6, v7 - v6 + 1) )
        {
          goto LABEL_66;
        }
        v53 = v9;
        v54 = v11;
        v12 = interval_tree_iter_first(v4 + 128, v6, v7);
        v13 = v7 + 1;
        if ( v12 )
        {
          v14 = v12;
          do
          {
            v15 = interval_tree_iter_next(v14, v6, v7);
            v16 = (unsigned int **)(v14 - 8);
            interval_tree_remove(v14, v4 + 128);
            v18 = *(_QWORD *)(v14 + 24);
            v17 = *(_QWORD *)(v14 + 32);
            if ( v18 >= v6 )
            {
              v21 = *(_QWORD *)(v4 + 80);
              if ( v17 <= v7 )
              {
                if ( (v21 & 0x800000000LL) != 0
                  && (unsigned int)kgsl_mmu_unmap_range(*(_QWORD *)(v4 + 8), v4 + 8, v18, v17 - v18 + 1) )
                {
                  goto LABEL_65;
                }
                _X0 = *v16;
                _X8 = *v16 + 93;
                __asm { PRFM            #0x11, [X8] }
                do
                  v29 = __ldxr(_X8);
                while ( __stxr(v29 - 1, _X8) );
                if ( _X0 && (unsigned __int64)_X0 <= 0xFFFFFFFFFFFFF000LL )
                {
                  __asm { PRFM            #0x11, [X0] }
                  do
                    v31 = __ldxr(_X0);
                  while ( __stlxr(v31 - 1, _X0) );
                  if ( v31 == 1 )
                  {
                    __dmb(9u);
                    kgsl_mem_entry_destroy(_X0);
                  }
                  else if ( v31 <= 0 )
                  {
                    refcount_warn_saturate(_X0, 3);
                  }
                }
                kfree(v14 - 8);
              }
              else
              {
                if ( (v21 & 0x800000000LL) != 0
                  && (unsigned int)kgsl_mmu_unmap_range(*(_QWORD *)(v4 + 8), v4 + 8, v18, v13 - v18) )
                {
                  goto LABEL_65;
                }
                *(_QWORD *)(v14 + 24) = v13;
                interval_tree_insert(v14, v4 + 128);
              }
            }
            else
            {
              if ( v17 > v7 )
              {
                result = (unsigned int *)bind_range_create(v7 + 1, v17, *v16);
                if ( (unsigned __int64)result >= 0xFFFFFFFFFFFFF001LL )
                {
                  __break(0x800u);
                  goto LABEL_87;
                }
                interval_tree_insert(result + 2, v4 + 128);
              }
              if ( (*(_BYTE *)(v4 + 84) & 8) != 0 )
              {
                v20 = *(_QWORD *)(v14 + 32);
                if ( v20 >= v7 )
                  v20 = v7;
                if ( (unsigned int)kgsl_mmu_unmap_range(*(_QWORD *)(v4 + 8), v4 + 8, v6, v20 - v6 + 1) )
                {
LABEL_65:
                  interval_tree_insert(v14, v4 + 128);
                  v11 = v54;
                  v1 = a1;
                  goto LABEL_66;
                }
              }
              *(_QWORD *)(v14 + 32) = v6 - 1;
              interval_tree_insert(v14, v4 + 128);
            }
            v14 = v15;
          }
          while ( v15 );
        }
        v42 = kgsl_mmu_map_child(*(_QWORD *)(v4 + 8), v4 + 8, v6, v8 + 8, v53, v13 - v6);
        v11 = v54;
        v1 = a1;
        if ( v42 )
        {
LABEL_66:
          _X0 = *v11;
          _X8 = *v11 + 93;
          __asm { PRFM            #0x11, [X8] }
          do
            v46 = __ldxr(_X8);
          while ( __stxr(v46 - 1, _X8) );
          if ( _X0 && (unsigned __int64)_X0 <= 0xFFFFFFFFFFFFF000LL )
          {
            __asm { PRFM            #0x11, [X0] }
            do
              v48 = __ldxr(_X0);
            while ( __stlxr(v48 - 1, _X0) );
            if ( v48 == 1 )
            {
              __dmb(9u);
              kgsl_mem_entry_destroy(_X0);
            }
            else if ( v48 <= 0 )
            {
              refcount_warn_saturate(_X0, 3);
            }
          }
          kfree(v11);
        }
        else
        {
          interval_tree_insert(v54 + 1, v4 + 128);
        }
      }
      else
      {
        v3 = v4 + 144;
        mutex_lock(v4 + 144);
        v32 = interval_tree_iter_first(v4 + 128, v6, v7);
        if ( v32 )
        {
          v33 = v32;
          do
          {
            v34 = (unsigned int **)(v33 - 8);
            v35 = interval_tree_iter_next(v33, v6, v7);
            if ( (!v8 || (*v34)[62] == *(_DWORD *)(v8 + 248))
              && !(unsigned int)kgsl_mmu_unmap_range(
                                  *(_QWORD *)(v4 + 8),
                                  v4 + 8,
                                  *(_QWORD *)(v33 + 24),
                                  *(_QWORD *)(v33 + 32) - *(_QWORD *)(v33 + 24) + 1LL) )
            {
              interval_tree_remove(v33, v4 + 128);
              if ( (*(_BYTE *)(v4 + 84) & 8) == 0 )
                kgsl_mmu_map_zero_page_to_range(
                  *(_QWORD *)(v4 + 8),
                  v4 + 8,
                  *(_QWORD *)(v33 + 24),
                  *(_QWORD *)(v33 + 32) - *(_QWORD *)(v33 + 24) + 1LL);
              _X0 = *v34;
              _X8 = *v34 + 93;
              __asm { PRFM            #0x11, [X8] }
              do
                v39 = __ldxr(_X8);
              while ( __stxr(v39 - 1, _X8) );
              if ( _X0 && (unsigned __int64)_X0 <= 0xFFFFFFFFFFFFF000LL )
              {
                __asm { PRFM            #0x11, [X0] }
                do
                  v41 = __ldxr(_X0);
                while ( __stlxr(v41 - 1, _X0) );
                if ( v41 == 1 )
                {
                  __dmb(9u);
                  kgsl_mem_entry_destroy(_X0);
                }
                else if ( v41 <= 0 )
                {
                  refcount_warn_saturate(_X0, 3);
                }
              }
              kfree(v33 - 8);
            }
            v33 = v35;
          }
          while ( v35 );
          v3 = v4 + 144;
        }
      }
      mutex_unlock(v3);
LABEL_5:
      ++v2;
    }
    while ( v2 < *(int *)(v1 - 24) );
  }
  v16 = (unsigned int **)(v1 - 40);
  result = (unsigned int *)complete_all(v1 + 32);
  v49 = *(__int64 (__fastcall **)(_QWORD))(v1 - 16);
  if ( v49 )
  {
    if ( *((_DWORD *)v49 - 1) != 379401429 )
      __break(0x8228u);
    result = (unsigned int *)v49(v1 - 40);
  }
  if ( v1 != 40 && (unsigned __int64)v16 <= 0xFFFFFFFFFFFFF000LL )
  {
    result = (unsigned int *)(v1 + 64);
LABEL_87:
    __asm { PRFM            #0x11, [X0] }
    do
      v51 = __ldxr(result);
    while ( __stlxr(v51 - 1, result) );
    if ( v51 == 1 )
    {
      __dmb(9u);
      return (unsigned int *)kgsl_sharedmem_free_bind_op((unsigned __int64)v16);
    }
    else if ( v51 <= 0 )
    {
      return (unsigned int *)refcount_warn_saturate(result, 3);
    }
  }
  return result;
}
