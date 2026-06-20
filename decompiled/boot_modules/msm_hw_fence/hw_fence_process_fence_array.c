__int64 __fastcall hw_fence_process_fence_array(__int64 a1, unsigned int *a2, __int64 a3, __int64 *a4, __int64 a5)
{
  unsigned __int64 *v5; // x23
  __int64 v6; // x21
  unsigned int *v7; // x22
  __int64 range; // x0
  __int64 v10; // x26
  __int64 v11; // x4
  bool v12; // w25
  __int64 v13; // x24
  void *v14; // x19
  unsigned int *v15; // x21
  void *v16; // x22
  unsigned __int64 *v17; // x19
  int v18; // w23
  int v19; // w28
  __int64 v20; // x28
  __int64 v21; // x0
  int v22; // w28
  int v23; // w27
  __int64 v24; // x27
  __int64 v25; // x8
  __int64 v26; // x4
  __int64 result; // x0
  __int64 v28; // x4
  __int64 v29; // x30
  void *v30; // x0
  __int64 v31; // x2
  __int64 v32; // x3
  unsigned __int64 v33; // x23
  bool v34; // cc
  __int64 v35; // x8
  __int64 v36; // x25
  __int64 v37; // x0
  __int64 v38; // x27
  int v39; // w28
  __int64 v40; // x25
  int v41; // w9
  unsigned __int64 v48; // x9
  __int64 v50; // [xsp+18h] [xbp-38h]
  __int64 v51; // [xsp+20h] [xbp-30h]
  __int64 v52; // [xsp+28h] [xbp-28h] BYREF
  char v53[4]; // [xsp+34h] [xbp-1Ch] BYREF
  __int64 v54; // [xsp+38h] [xbp-18h] BYREF
  char v55[4]; // [xsp+44h] [xbp-Ch] BYREF
  __int64 v56; // [xsp+48h] [xbp-8h]

  v5 = (unsigned __int64 *)a4;
  v6 = a3;
  v7 = a2;
  v56 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v53[0] = 0;
  v52 = 0;
  if ( a5 && a2[1] != 1 )
  {
    printk(&unk_27233, "hw_fence_process_fence_array", 2024, v50, a5);
    goto LABEL_66;
  }
  range = hw_fence_lookup_and_create_range(
            a1,
            0xFFFFFFFF,
            a3,
            *(_QWORD *)(a3 + 32),
            *(_QWORD *)(a3 + 40),
            *(_DWORD *)(a3 + 68),
            a4,
            0,
            *(_DWORD *)(a1 + 80),
            0);
  if ( !range )
  {
    printk(&unk_23200, "_hw_fence_process_join_fence", 1841, v50, 0xFFFFFFFFLL);
    printk(&unk_2311D, "hw_fence_process_fence_array", 2037, v50, v28);
    goto LABEL_66;
  }
  v10 = range;
  global_atomic_store(a1, range + 40, 1);
  *(_QWORD *)(v10 + 24) |= 1LL << *v7;
  global_atomic_store(a1, v10 + 40, 0);
  if ( *(_DWORD *)(v6 + 68) )
  {
    v12 = 0;
    LODWORD(v13) = 0;
    v14 = &dma_fence_array_ops;
    v51 = v6;
    while ( 1 )
    {
      v20 = *(_QWORD *)(*(_QWORD *)(v6 + 80) + 8LL * (int)v13);
      if ( !v20 )
      {
        printk(&unk_26B79, "hw_fence_process_fence_array", 2051, v50, (unsigned int)v13);
        goto LABEL_44;
      }
      if ( *(void **)(v20 + 8) == v14 )
        break;
      if ( (*(_QWORD *)(v20 + 48) & 0x80000000) == 0 )
      {
        v29 = v50;
        v30 = &unk_2A25E;
        v31 = 2065;
        goto LABEL_40;
      }
      v21 = hw_fence_find_with_dma_fence(a1, v7, v20, &v52, v53, 0);
      if ( v53[0] == 1 )
      {
        v22 = *(_DWORD *)(v20 + 60);
        v12 = 1;
        global_atomic_store(a1, v10 + 40, 1);
        v23 = *(_DWORD *)(v10 + 84);
        *(_DWORD *)(v10 + 4) |= v22;
        if ( v23 )
        {
          v12 = v23 == 1;
          *(_DWORD *)(v10 + 84) = v23 - 1;
        }
        global_atomic_store(a1, v10 + 40, 0);
        __dsb(0xEu);
        if ( !v23 )
          printk(&unk_22D1A, "_update_and_get_join_fence_signal_status", 2003, v50, *(_QWORD *)(v10 + 8));
      }
      else
      {
        v24 = v21;
        if ( !v21 )
        {
          printk(&unk_20363, "hw_fence_process_fence_array", 2079, v50, *(_QWORD *)(v20 + 32));
          goto LABEL_44;
        }
        global_atomic_store(a1, v21 + 40, 1);
        if ( (*(_BYTE *)(v24 + 48) & 1) != 0 )
        {
          v15 = v7;
          v16 = v14;
          v17 = v5;
          v18 = *(_DWORD *)(v24 + 4);
          global_atomic_store(a1, v10 + 40, 1);
          v19 = *(_DWORD *)(v10 + 84);
          *(_DWORD *)(v10 + 4) |= v18;
          if ( v19 )
          {
            v12 = v19 == 1;
            *(_DWORD *)(v10 + 84) = v19 - 1;
          }
          else
          {
            v12 = 1;
          }
          global_atomic_store(a1, v10 + 40, 0);
          __dsb(0xEu);
          v5 = v17;
          if ( !v19 )
            printk(&unk_22D1A, "_update_and_get_join_fence_signal_status", 2003, v50, *(_QWORD *)(v10 + 8));
          v14 = v16;
          v7 = v15;
          v6 = v51;
        }
        else
        {
          v25 = *(unsigned int *)(v24 + 80);
          v26 = (unsigned int)(v25 + 1);
          *(_DWORD *)(v24 + 80) = v26;
          if ( (unsigned int)v25 >= 2 )
          {
            printk(&unk_244C8, "hw_fence_process_fence_array", 2100, v50, v26);
            v32 = v52;
            --*(_DWORD *)(v24 + 80);
            hw_fence_put_and_unlock(a1, *v7, v24, v32);
            goto LABEL_44;
          }
          *(_QWORD *)(v24 + 8 * v25 + 56) = *v5;
        }
        hw_fence_put_and_unlock(a1, *v7, v24, v52);
      }
      LODWORD(v13) = v13 + 1;
      if ( (unsigned int)v13 >= *(_DWORD *)(v6 + 68) )
        goto LABEL_27;
    }
    v29 = v50;
    v30 = &unk_25B59;
    v31 = 2058;
LABEL_40:
    printk(v30, "hw_fence_process_fence_array", v31, v29, v11);
    goto LABEL_44;
  }
  LODWORD(v13) = 0;
  v12 = 0;
LABEL_27:
  if ( a5 )
    *(_QWORD *)(v10 + 120) = a5;
  if ( !v12 )
  {
    if ( *(_DWORD *)(v6 + 68) )
    {
      result = 0;
      goto LABEL_67;
    }
    printk(&unk_28009, "hw_fence_process_fence_array", 2143, v50, *(_QWORD *)(v6 + 32));
LABEL_44:
    v33 = *v5;
    v54 = 0;
    if ( (v13 & 0x80000000) == 0 && *(_QWORD *)(v6 + 80) )
    {
      v13 = (unsigned int)v13;
      v55[0] = 0;
      do
      {
        v35 = *(_QWORD *)(v6 + 80);
        v36 = *(_QWORD *)(v35 + 8 * v13);
        if ( v36 )
        {
          v37 = hw_fence_find_with_dma_fence(a1, v7, *(_QWORD *)(v35 + 8 * v13), &v54, v55, 0);
          if ( (v55[0] & 1) == 0 )
          {
            v38 = v37;
            if ( v37 )
            {
              global_atomic_store(a1, v37 + 40, 1);
              v39 = *(_DWORD *)(v38 + 80);
              if ( v39 >= 1 )
              {
                v40 = v38 + 56;
                do
                {
                  if ( (unsigned int)v39 >= 4 )
                  {
                    v39 = 3;
                    printk(&unk_2B3D1, "_cleanup_join_and_child_fences", 1957, v50, *(unsigned int *)(v38 + 80));
                  }
                  if ( *(_QWORD *)(v40 + 8LL * (unsigned int)(v39 - 1)) == v33 )
                  {
                    *(_QWORD *)(v40 + 8LL * (unsigned int)(v39 - 1)) = -1;
                    v41 = *(_DWORD *)(v38 + 80);
                    if ( v41 )
                      *(_DWORD *)(v38 + 80) = v41 - 1;
                    __dsb(0xEu);
                  }
                  v34 = (unsigned int)v39-- > 1;
                }
                while ( v34 );
              }
              hw_fence_put_and_unlock(a1, *v7, v38, v54);
            }
            else
            {
              printk(&unk_213A6, "_cleanup_join_and_child_fences", 1942, v50, *(_QWORD *)(v36 + 32));
            }
          }
        }
        else
        {
          printk(&unk_287EE, "_cleanup_join_and_child_fences", 1932, v50, (unsigned int)v13);
        }
        v34 = v13-- <= 0;
      }
      while ( !v34 );
    }
    if ( (unsigned int)hw_fence_destroy_refcount(a1, v33, 0x80000000) )
      printk(&unk_2134A, "_hw_fence_process_join_fence", 1844, v50, 0xFFFFFFFFLL);
LABEL_66:
    result = 4294967274LL;
    goto LABEL_67;
  }
  fence_ctl_signal(a1, v7, v10, *v5);
  _X8 = (unsigned __int64 *)(v6 + 48);
  __asm { PRFM            #0x11, [X8] }
  do
    v48 = __ldxr(_X8);
  while ( __stxr(v48 | 0x40000000, _X8) );
  result = hw_fence_destroy_refcount(a1, *v5, 0x80000000);
  if ( (_DWORD)result )
  {
    printk(&unk_2134A, "_hw_fence_process_join_fence", 1844, v50, 0xFFFFFFFFLL);
    result = 0;
  }
LABEL_67:
  _ReadStatusReg(SP_EL0);
  return result;
}
