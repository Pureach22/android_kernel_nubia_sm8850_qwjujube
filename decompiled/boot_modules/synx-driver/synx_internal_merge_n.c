__int64 __fastcall synx_internal_merge_n(
        unsigned __int64 a1,
        unsigned __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6)
{
  __int64 result; // x0
  unsigned __int64 v8; // x9
  unsigned __int64 v9; // x9
  unsigned __int64 v10; // x25
  unsigned __int64 v11; // x27
  unsigned __int64 client; // x0
  __int64 v14; // x19
  __int64 v15; // x4
  __int64 v16; // x5
  unsigned __int64 v17; // x21
  unsigned int v18; // w0
  __int64 v19; // x5
  unsigned int v20; // w23
  __int64 v21; // x28
  unsigned __int64 v22; // x22
  _QWORD *v23; // x0
  __int64 v24; // x4
  __int64 v25; // x5
  _QWORD *v26; // x20
  bool v27; // cc
  _BOOL4 v28; // w24
  void *v29; // x0
  __int64 v30; // x3
  size_t v31; // x2
  int v32; // w10
  __int64 v33; // x8
  __int64 v34; // x4
  unsigned int inited; // w0
  __int64 v36; // x5
  unsigned int v37; // w23
  __int64 fence_entry; // x0
  _QWORD *map_entry; // x0
  bool v40; // cf
  unsigned __int64 v41; // x0
  unsigned __int64 v42; // x22
  unsigned int v43; // w0
  unsigned __int64 v44; // x24
  __int64 v45; // x0
  __int64 v46; // x0
  __int64 v47; // x8
  unsigned int v48; // w9
  __int64 v49; // x4
  __int64 v50; // x5
  __int64 v51; // x4
  __int64 v52; // x5
  unsigned int v53; // w22
  int v54; // w0
  unsigned __int64 v55; // x8
  unsigned __int64 v56; // x8
  __int64 v57; // x8
  unsigned __int64 v58; // x10
  unsigned __int64 v59; // x22
  unsigned __int64 v60; // x23
  unsigned int v61; // w0
  unsigned __int64 v62; // x0
  unsigned __int64 v63; // x28
  __int64 v64; // x2
  __int64 v65; // x3
  __int64 v66; // x4
  __int64 v67; // x5
  unsigned int v68; // w0
  __int64 v69; // x4
  __int64 v70; // x5
  unsigned int v71; // w22
  unsigned __int64 StatusReg; // x20
  __int64 v73; // x22
  __int64 (__fastcall *v74)(_QWORD); // x0
  unsigned int v75; // [xsp+Ch] [xbp-54h]
  __int64 v76; // [xsp+10h] [xbp-50h]
  unsigned __int64 v77; // [xsp+18h] [xbp-48h]
  unsigned __int64 v78; // [xsp+20h] [xbp-40h]
  unsigned __int64 v79; // [xsp+28h] [xbp-38h]
  __int64 v80; // [xsp+30h] [xbp-30h] BYREF
  __int64 v81; // [xsp+38h] [xbp-28h] BYREF
  __int64 v82; // [xsp+40h] [xbp-20h]
  __int64 v83; // [xsp+48h] [xbp-18h]
  unsigned int v84; // [xsp+54h] [xbp-Ch] BYREF
  __int64 v85; // [xsp+58h] [xbp-8h]

  result = 4294967274LL;
  v85 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v84 = 0;
  v82 = 0;
  v83 = 0;
  v81 = 0;
  v80 = 0;
  if ( !a1 || a1 > 0xFFFFFFFFFFFFF000LL || !a2 || a2 > 0xFFFFFFFFFFFFF000LL || *(_DWORD *)a2 != 1 )
    goto LABEL_25;
  v8 = *(_QWORD *)(a2 + 8);
  if ( !v8 || v8 > 0xFFFFFFFFFFFFF000LL || (v9 = *(_QWORD *)(a2 + 24)) == 0 || v9 >= 0xFFFFFFFFFFFFF001LL )
  {
    if ( (synx_debug & 1) == 0 )
      goto LABEL_25;
    v29 = &unk_2B3D9;
    v30 = 1551;
LABEL_29:
    printk(v29, &unk_29207, "synx_internal_merge_n", v30, a5, a6);
    result = 4294967274LL;
    goto LABEL_25;
  }
  v10 = *(unsigned int *)(a2 + 40);
  v11 = *(unsigned int *)(a2 + 44);
  client = synx_get_client(a1);
  if ( !client || (v14 = client, client >= 0xFFFFFFFFFFFFF001LL) )
  {
    if ( (synx_debug & 1) == 0 )
    {
      result = 4294967274LL;
      goto LABEL_25;
    }
    v29 = &unk_2B010;
    v30 = 1557;
    goto LABEL_29;
  }
  v17 = _kmalloc_cache_noprof(_list_del_entry_valid_or_report, 3520, 368);
  if ( v17 )
  {
    while ( 1 )
    {
      if ( v17 >= 0xFFFFFFFFFFFFF001LL )
        goto LABEL_110;
      v18 = synx_util_validate_merge(v14, *(_QWORD *)(a2 + 8), *(unsigned int *)(a2 + 20), &v80, &v84);
      if ( (v18 & 0x80000000) != 0 )
      {
        if ( (synx_debug & 1) != 0 )
          printk(&unk_2579B, &unk_29207, "synx_internal_merge_n", 1573, *(_QWORD *)(v14 + 104), v19);
        kfree(v17);
        v20 = -22;
        goto LABEL_113;
      }
      v20 = v18;
      v21 = v84;
      v22 = 8LL * v84;
      v23 = (_QWORD *)_kmalloc_noprof(v22, 3520);
      v26 = v23;
      v27 = !v23 || (unsigned __int64)v23 > 0xFFFFFFFFFFFFF000LL;
      v28 = v27;
      if ( v28 )
        break;
      v31 = 8LL * v84;
      if ( 8 * v21 >= v31 )
      {
        memset(v23, 0, v31);
        v32 = *(_DWORD *)(a2 + 16);
        v33 = *(_QWORD *)(a2 + 24);
        v34 = *(_QWORD *)(v14 + 112);
        v81 = *(_QWORD *)(a2 + 8);
        LODWORD(v82) = v32;
        HIDWORD(v82) = v32;
        v83 = v33;
        inited = synx_util_init_group_coredata(v17, v80, &v81, v84, v34, v11 | (v10 << 32));
        if ( inited )
        {
          v20 = inited;
          if ( (synx_debug & 1) != 0 )
            printk(&unk_26602, &unk_29207, "synx_internal_merge_n", 1597, *(_QWORD *)(v14 + 104), v36);
LABEL_37:
          kfree(v17);
          synx_util_merge_error(v14, v80, v84, v26);
          if ( *(_DWORD *)(a2 + 20) - 1 < v84 )
            kfree(v80);
          if ( !v28 )
            goto LABEL_40;
          goto LABEL_113;
        }
        if ( v84 )
        {
          v37 = 1;
          while ( 1 )
          {
            v10 = v37 - 1;
            v11 = 8LL * (int)v10;
            fence_entry = synx_util_get_fence_entry(*(_QWORD *)(v80 + v11), 1);
            map_entry = (_QWORD *)synx_util_get_map_entry(fence_entry);
            if ( v22 <= v11 )
              break;
            v26[(int)v10] = map_entry;
            if ( !map_entry
              || (unsigned __int64)map_entry > 0xFFFFFFFFFFFFF000LL
              || !*map_entry
              || *map_entry >= 0xFFFFFFFFFFFFF001LL )
            {
              if ( v37 >= v84 )
              {
LABEL_61:
                synx_util_put_object(v17);
                kfree(v26);
                v20 = 0;
                goto LABEL_113;
              }
              while ( 1 )
              {
                v44 = 8LL * (int)v37;
                v45 = synx_util_get_fence_entry(*(_QWORD *)(v80 + v44), 1);
                v46 = synx_util_get_map_entry(v45);
                if ( v22 <= v44 )
                  goto LABEL_108;
                v47 = (int)v37;
                v48 = v84;
                ++v37;
                v26[v47] = v46;
                if ( v37 >= v48 )
                  goto LABEL_61;
              }
            }
            v40 = v37++ >= v84;
            if ( v40 )
              goto LABEL_51;
          }
        }
        else
        {
LABEL_51:
          v41 = synx_util_insert_to_map(v17, **(unsigned int **)(a2 + 24), 0, 0);
          v42 = v41;
          if ( !v41 || v41 >= 0xFFFFFFFFFFFFF001LL )
          {
            synx_util_put_object(v17);
            kfree(v26);
            v20 = v42;
            goto LABEL_113;
          }
          v20 = synx_util_add_callback(v17, **(unsigned int **)(a2 + 24));
          if ( v20 )
            goto LABEL_57;
          v43 = synx_util_init_handle(v14, v17, *(_QWORD *)(a2 + 24), v42);
          if ( v43 )
          {
            v20 = v43;
            if ( (synx_debug & 1) != 0 )
              printk(
                &unk_27920,
                &unk_29207,
                "synx_internal_merge_n",
                1636,
                *(_QWORD *)(v14 + 104),
                **(unsigned int **)(a2 + 24));
LABEL_57:
            synx_util_release_map_entry(v42);
LABEL_40:
            kfree(v26);
            goto LABEL_113;
          }
          v78 = 4 * v84;
          v79 = _kmalloc_noprof(v78, 3520);
          if ( !v79 || v79 >= 0xFFFFFFFFFFFFF001LL )
          {
            if ( (synx_debug & 1) != 0 )
              printk(&unk_27D59, &unk_29207, "synx_internal_merge_n", 1642, v49, v50);
LABEL_119:
            v71 = -12;
LABEL_120:
            kfree(v26);
            synx_native_release_core(v14, **(_DWORD **)(a2 + 24));
            synx_put_client(v14);
            result = v71;
            goto LABEL_25;
          }
          v10 = 4 * v84;
          v77 = _kmalloc_noprof(v10, 3520);
          if ( !v77 || v77 > 0xFFFFFFFFFFFFF000LL )
          {
            if ( (synx_debug & 1) != 0 )
              printk(&unk_2B867, &unk_29207, "synx_internal_merge_n", 1649, v51, v52);
            kfree(v79);
            goto LABEL_119;
          }
          if ( !v84 )
          {
            if ( (*(_BYTE *)(a2 + 16) & 2) != 0 )
            {
              LODWORD(v11) = 0;
LABEL_101:
              v68 = synx_global_merge(v77, (unsigned int)v11, **(unsigned __int16 **)(a2 + 24));
              if ( v68 )
              {
                v71 = v68;
                if ( (synx_debug & 1) != 0 )
                  printk(&unk_2B8A0, &unk_29207, "synx_internal_merge_n", 1668, v69, v70);
                kfree(v79);
                kfree(v77);
                goto LABEL_120;
              }
            }
LABEL_105:
            if ( (synx_debug & 0x80) != 0 )
              printk(
                &unk_26E81,
                &unk_25D36,
                "synx_internal_merge_n",
                1706,
                *(_QWORD *)(v14 + 104),
                **(unsigned int **)(a2 + 24));
            kfree(v79);
            kfree(v77);
            kfree(v26);
            synx_put_client(v14);
            result = 0;
            goto LABEL_25;
          }
          v53 = 0;
          v11 = 0;
          do
          {
            v54 = synx_util_get_fence_entry(*(_QWORD *)(v80 + 8LL * (int)v53), 1);
            if ( (v54 & 0x100000) != 0 )
            {
              v55 = 4LL * (int)v11;
              v40 = v78 >= v55;
              v56 = v78 - v55;
              if ( !v40 )
                goto LABEL_108;
              if ( v56 < 4 )
                goto LABEL_108;
              v57 = (int)v11;
              v58 = 4LL * (int)v11;
              *(_DWORD *)(v79 + v58) = v54;
              if ( v10 < v58 || v10 - v58 < 4 )
                goto LABEL_108;
              v11 = (unsigned int)(v11 + 1);
              *(_DWORD *)(v77 + 4 * v57) = (unsigned __int16)v54;
            }
            ++v53;
          }
          while ( v53 < v84 );
          if ( (*(_BYTE *)(a2 + 16) & 2) != 0 )
            goto LABEL_101;
          if ( (int)v11 < 1 )
            goto LABEL_105;
          v59 = v78;
          v60 = 0;
          v75 = 0;
          v76 = 4LL * (unsigned int)v11;
          while ( v78 >= v60 && v59 >= 4 )
          {
            v61 = synx_global_test_status_set_wait(*(unsigned __int16 *)(v79 + v60), 0);
            if ( v61 != 1 )
            {
              if ( v78 < v60 )
                break;
              v11 = v61;
              v62 = synx_util_acquire_handle(v14, *(unsigned int *)(v79 + v60));
              if ( v62
                && (v10 = v62, v62 <= 0xFFFFFFFFFFFFF000LL)
                && (v63 = *(_QWORD *)(v62 + 8)) != 0
                && v63 < 0xFFFFFFFFFFFFF001LL )
              {
                mutex_lock(v63 + 72);
                if ( *(_DWORD *)(v17 + 128) == 1 )
                  v75 = synx_native_signal_fence(v63, v11, v64, v65, v66, v67);
                mutex_unlock(v63 + 72);
                if ( v75 && (synx_debug & 1) != 0 )
                {
                  if ( v78 < v60 )
                    break;
                  printk(&unk_2B0A3, &unk_29207, "synx_internal_merge_n", 1696, *(unsigned int *)(v79 + v60), v75);
                }
                synx_util_release_handle(v10);
              }
              else if ( (synx_debug & 1) != 0 )
              {
                if ( v78 < v60 )
                  break;
                printk(
                  &unk_2992A,
                  &unk_29207,
                  "synx_internal_merge_n",
                  1686,
                  *(_QWORD *)(v14 + 104),
                  *(unsigned int *)(v79 + v60));
              }
            }
            v60 += 4LL;
            v59 -= 4LL;
            if ( v76 == v60 )
              goto LABEL_105;
          }
        }
LABEL_108:
        __break(1u);
      }
      _fortify_panic(15);
      StatusReg = _ReadStatusReg(SP_EL0);
      v73 = *(_QWORD *)(StatusReg + 80);
      v74 = _list_del_entry_valid_or_report;
      *(_QWORD *)(StatusReg + 80) = &synx_internal_merge_n__alloc_tag;
      v17 = _kmalloc_cache_noprof(v74, 3520, 368);
      *(_QWORD *)(StatusReg + 80) = v73;
      if ( !v17 )
        goto LABEL_110;
    }
    if ( (synx_debug & 1) != 0 )
      printk(&unk_296B5, &unk_29207, "synx_internal_merge_n", 1581, v24, v25);
    goto LABEL_37;
  }
LABEL_110:
  if ( (synx_debug & 1) != 0 )
    printk(&unk_2A5C1, &unk_29207, "synx_internal_merge_n", 1563, v15, v16);
  v20 = -12;
LABEL_113:
  synx_put_client(v14);
  result = v20;
LABEL_25:
  _ReadStatusReg(SP_EL0);
  return result;
}
