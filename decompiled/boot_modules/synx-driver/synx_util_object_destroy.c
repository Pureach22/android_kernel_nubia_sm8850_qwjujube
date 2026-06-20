__int64 __fastcall synx_util_object_destroy(
        unsigned __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6)
{
  const char *v6; // x21
  unsigned __int64 v7; // x27
  _QWORD *v9; // x26
  char v10; // w8
  _QWORD *v11; // x24
  __int64 v12; // x5
  _QWORD *v13; // x8
  __int64 v14; // x9
  unsigned __int64 v15; // x8
  unsigned __int64 v16; // x25
  unsigned int v17; // w20
  _QWORD *v18; // x22
  unsigned int v19; // w27
  __int64 v20; // x26
  __int64 v21; // x24
  unsigned __int64 v22; // x24
  _DWORD *v23; // x8
  __int64 v24; // x2
  __int64 v25; // x4
  void *v26; // x0
  __int64 v27; // x3
  __int64 v28; // x5
  unsigned __int64 v29; // x21
  unsigned __int64 v30; // x24
  __int64 v31; // x26
  __int64 v32; // x8
  __int64 v33; // x10
  int *v34; // x9
  unsigned int v36; // w22
  __int64 v37; // x9
  _QWORD *map_entry; // x0
  _QWORD *v39; // x22
  _QWORD *v40; // x8
  unsigned int v41; // w0
  __int64 v42; // x0
  __int64 v43; // x4
  __int64 v44; // x5
  unsigned __int64 v45; // x22
  _QWORD *v46; // x8
  unsigned int v47; // w23
  _QWORD *v48; // x25
  unsigned __int64 v49; // x8
  int v55; // w8
  __int64 result; // x0
  __int64 v57; // x5
  unsigned int v58; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v59; // [xsp+8h] [xbp-8h]

  v7 = a1 + 328;
  v59 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = *(_QWORD **)(a1 + 328);
  v58 = 0;
  if ( v9 != (_QWORD *)(a1 + 328) )
  {
    v10 = synx_debug;
    v6 = "verb";
    do
    {
      v11 = (_QWORD *)*v9;
      if ( (v10 & 1) != 0 )
        printk(&unk_275E5, &unk_29207, "synx_util_object_destroy", 401, *(v9 - 13), a6);
      v12 = *(v9 - 5);
      if ( v12 != -1 )
      {
        if ( (synx_debug & 0x10) != 0 )
          printk(&unk_27FA6, "verb", "synx_util_object_destroy", 405, v9 - 13, v12);
        timer_delete_sync(v9 - 10);
      }
      v13 = (_QWORD *)v9[1];
      *((_DWORD *)v9 - 22) = 4;
      if ( (_QWORD *)*v13 == v9 && (v14 = *v9, *(_QWORD **)(*v9 + 8LL) == v9) )
      {
        *(_QWORD *)(v14 + 8) = v13;
        *v13 = v14;
      }
      else
      {
        _list_del_entry_valid_or_report(v9);
      }
      *v9 = v9;
      v9[1] = v9;
      queue_work_on(32, *(_QWORD *)(synx_dev + 160), v9 - 4);
      v10 = synx_debug;
      if ( (synx_debug & 0x10) != 0 )
      {
        printk(&unk_27C0D, "verb", "synx_util_object_destroy", 413, *(_QWORD *)(a1 + 64), a6);
        v10 = synx_debug;
      }
      v9 = v11;
    }
    while ( v11 != (_QWORD *)v7 );
  }
  v15 = *(unsigned int *)(a1 + 132);
  if ( (_DWORD)v15 )
  {
    v16 = 0;
    v17 = 0;
    v18 = (_QWORD *)(a1 + 152);
    while ( 1 )
    {
      if ( v16 == 9 )
      {
        __break(0x5512u);
LABEL_104:
        __break(0x800u);
LABEL_94:
        *(_DWORD *)(v15 + 60) = -4;
        v41 = dma_fence_signal_locked(*(_QWORD *)(a1 + 64));
LABEL_95:
        v17 = v41;
        goto LABEL_96;
      }
      v19 = *((_DWORD *)v18 - 2);
      v58 = *(v18 - 2);
      if ( v19
        || ((v20 = *v18,
             mutex_lock(synx_dev + 176),
             v21 = synx_dev,
             v6 = (const char *)*(unsigned __int8 *)(synx_dev + 324),
             mutex_unlock(synx_dev + 176),
             !(_DWORD)v6)
          ? (v22 = 0)
          : (v22 = v21 + 288),
            !v22 || v22 >= 0xFFFFFFFFFFFFF001LL) )
      {
        if ( (synx_debug & 1) != 0 )
        {
          v25 = v58;
          v26 = &unk_2B332;
          v27 = 425;
          v28 = v19;
          goto LABEL_34;
        }
      }
      else
      {
        synx_util_remove_data(&v58, 0);
        v23 = *(_DWORD **)(v22 + 8);
        v24 = v58;
        if ( *(v23 - 1) != 2137877367 )
          __break(0x8228u);
        v17 = ((__int64 (__fastcall *)(_QWORD, __int64, __int64))v23)(synx_external_callback, v20, v24);
        if ( (v17 & 0x80000000) != 0 )
        {
          if ( (synx_debug & 1) != 0 )
          {
            v25 = v58;
            v26 = &unk_2762B;
            v27 = 437;
            v28 = 0;
LABEL_34:
            printk(v26, &unk_29207, "synx_util_object_destroy", v27, v25, v28);
          }
        }
        else
        {
          kfree(v20);
        }
      }
      v15 = *(unsigned int *)(a1 + 132);
      ++v16;
      v18 += 3;
      if ( v16 >= v15 )
        goto LABEL_36;
    }
  }
  v17 = 0;
LABEL_36:
  v29 = *(_QWORD *)(a1 + 64);
  if ( v29 <= 0xFFFFFFFFFFFFF000LL && v29 && *(_UNKNOWN **)(v29 + 8) == &dma_fence_array_ops && *(_DWORD *)(v29 + 68) )
  {
    v30 = 0;
    do
    {
      v31 = *(_QWORD *)(*(_QWORD *)(v29 + 80) + 8 * v30);
      raw_spin_lock_bh(*(_QWORD *)(synx_dev + 152) + 2056LL);
      v32 = *(_QWORD *)(synx_dev + 152);
      v33 = *(_QWORD *)(v32 + 8 * ((unsigned __int64)(0x61C8864680B583EBLL * v31) >> 54) + 2064);
      v34 = (int *)(v33 - 16);
      if ( v33 )
        _ZF = v33 == 16;
      else
        _ZF = 1;
      if ( _ZF )
      {
        v36 = 0;
      }
      else
      {
        while ( *((_QWORD *)v34 + 1) != v31 )
        {
          v37 = *((_QWORD *)v34 + 2);
          v36 = 0;
          if ( v37 )
          {
            v34 = (int *)(v37 - 16);
            if ( v34 )
              continue;
          }
          goto LABEL_54;
        }
        v36 = *v34;
        if ( !*v34 )
          v36 = v34[1];
      }
LABEL_54:
      raw_spin_unlock_bh(v32 + 2056);
      map_entry = (_QWORD *)synx_util_get_map_entry(v36);
      if ( map_entry
        && (unsigned __int64)map_entry <= 0xFFFFFFFFFFFFF000LL
        && *map_entry
        && *map_entry <= 0xFFFFFFFFFFFFF000LL )
      {
        v39 = map_entry;
        synx_util_release_map_entry(map_entry);
        synx_util_release_map_entry(v39);
      }
      ++v30;
    }
    while ( v30 < *(unsigned int *)(v29 + 68) );
    v29 = *(_QWORD *)(a1 + 64);
  }
  synx_util_release_fence_entry(v29);
  v40 = *(_QWORD **)(a1 + 64);
  if ( v40 && (unsigned __int64)v40 <= 0xFFFFFFFFFFFFF000LL )
  {
    v6 = (const char *)raw_spin_lock_irqsave(*v40);
    if ( a1 )
    {
      if ( a1 <= 0xFFFFFFFFFFFFF000LL
        && (*(_DWORD *)(a1 + 124) & 0x20) != 0
        && (unsigned int)_fence_group_state(*(_QWORD *)(a1 + 64), 1) == 1 )
      {
        v41 = synx_util_cleanup_merged_fence(a1);
        goto LABEL_95;
      }
      if ( a1 <= 0xFFFFFFFFFFFFF000LL )
      {
        v42 = *(_QWORD *)(a1 + 64);
        if ( (*(_BYTE *)(a1 + 124) & 0x20) != 0 )
        {
          if ( (unsigned int)_fence_group_state(v42, 1) != 1 )
            goto LABEL_96;
        }
        else if ( (unsigned int)_fence_state(v42, 1) != 1 )
        {
          goto LABEL_96;
        }
        v45 = *(_QWORD *)(a1 + 64);
        if ( v45 && v45 < 0xFFFFFFFFFFFFF001LL )
        {
          v46 = *(_QWORD **)(v45 + 16);
          if ( v46 == (_QWORD *)(v45 + 16) )
          {
            v47 = 0;
          }
          else
          {
            v47 = 0;
            do
            {
              v48 = (_QWORD *)*v46;
              if ( v46 && (unsigned __int64)v46 < 0xFFFFFFFFFFFFF001LL )
              {
                v49 = v46[3];
                if ( v49 && v49 <= 0xFFFFFFFFFFFFF000LL && *(_UNKNOWN **)(v49 + 8) == &dma_fence_array_ops )
                  ++v47;
              }
              else if ( (synx_debug & 0x10) != 0 )
              {
                printk(&unk_2AFA9, "verb", "synx_util_count_dma_array_fences", 227, v45, v44);
              }
              v46 = v48;
            }
            while ( v48 != (_QWORD *)(v45 + 16) );
          }
          if ( (synx_debug & 0x10) != 0 )
            printk(&unk_2A1A7, "verb", "synx_util_count_dma_array_fences", 236, v47, v45);
        }
        else
        {
          if ( (synx_debug & 1) != 0 )
            printk(&unk_2871F, &unk_29207, "synx_util_count_dma_array_fences", 219, v43, v44);
          v47 = 0;
        }
        v15 = *(_QWORD *)(a1 + 64);
        if ( *(_DWORD *)(v15 + 56) == v47 + 1 )
        {
          if ( (*(_QWORD *)(v15 + 48) & 1) != 0 )
            goto LABEL_104;
          goto LABEL_94;
        }
      }
    }
LABEL_96:
    raw_spin_unlock_irqrestore(**(_QWORD **)(a1 + 64), v6);
    if ( v17 && (synx_debug & 1) != 0 )
      printk(&unk_2B795, &unk_29207, "synx_util_object_destroy", 489, *(_QWORD *)(a1 + 64), v17);
    v40 = *(_QWORD **)(a1 + 64);
  }
  if ( v40 )
  {
    _X0 = (unsigned int *)(v40 + 7);
    __asm { PRFM            #0x11, [X0] }
    do
      v55 = __ldxr(_X0);
    while ( __stlxr(v55 - 1, _X0) );
    if ( v55 == 1 )
    {
      __dmb(9u);
      dma_fence_release(_X0);
    }
    else if ( v55 <= 0 )
    {
      refcount_warn_saturate(_X0, 3);
    }
  }
  result = kfree(a1);
  if ( (synx_debug & 0x80) != 0 )
    result = printk(&unk_290D3, &unk_25D36, "synx_util_object_destroy", 494, a1, v57);
  _ReadStatusReg(SP_EL0);
  return result;
}
