__int64 __fastcall synx_internal_merge(unsigned __int64 a1, _QWORD *a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6)
{
  __int64 result; // x0
  unsigned __int64 v8; // x9
  unsigned __int64 v9; // x21
  unsigned __int64 client; // x0
  __int64 v11; // x19
  __int64 v12; // x4
  __int64 v13; // x5
  unsigned __int64 v14; // x22
  unsigned int v15; // w0
  __int64 v16; // x5
  unsigned int v17; // w25
  __int64 v18; // x26
  unsigned __int64 v19; // x23
  _QWORD *v20; // x0
  __int64 v21; // x4
  __int64 v22; // x5
  _QWORD *v23; // x20
  bool v24; // cc
  _BOOL4 v25; // w24
  void *v26; // x0
  __int64 v27; // x3
  unsigned int inited; // w0
  __int64 v29; // x5
  unsigned int v30; // w25
  unsigned __int64 v31; // x27
  __int64 fence_entry; // x0
  _QWORD *map_entry; // x0
  bool v34; // cf
  unsigned __int64 v35; // x0
  unsigned __int64 v36; // x23
  unsigned int v37; // w0
  __int64 v38; // x0
  __int64 v39; // x0
  __int64 v40; // x8
  unsigned int v41; // w9
  unsigned __int64 v42; // x0
  __int64 v43; // x4
  __int64 v44; // x5
  unsigned __int64 v45; // x26
  __int64 v46; // x4
  __int64 v47; // x5
  unsigned int v48; // w23
  int v49; // w28
  int v50; // w0
  unsigned __int64 v51; // x8
  unsigned __int64 v52; // x8
  __int64 v53; // x8
  unsigned __int64 v54; // x10
  unsigned __int64 v55; // x23
  unsigned __int64 v56; // x24
  unsigned int v57; // w0
  unsigned int v58; // w26
  unsigned __int64 v59; // x0
  unsigned __int64 v60; // x28
  unsigned __int64 v61; // x27
  __int64 v62; // x2
  __int64 v63; // x3
  __int64 v64; // x4
  __int64 v65; // x5
  __int64 v66; // x5
  unsigned int v67; // w21
  unsigned int v68; // w0
  __int64 v69; // x4
  __int64 v70; // x5
  unsigned int v71; // w23
  unsigned __int64 StatusReg; // x20
  __int64 v73; // x23
  __int64 (__fastcall *v74)(_QWORD); // x0
  unsigned int v75; // [xsp+4h] [xbp-3Ch]
  __int64 v76; // [xsp+8h] [xbp-38h]
  unsigned __int64 v77; // [xsp+10h] [xbp-30h]
  unsigned __int64 v78; // [xsp+18h] [xbp-28h]
  unsigned __int64 v79; // [xsp+20h] [xbp-20h]
  __int64 v80; // [xsp+28h] [xbp-18h] BYREF
  unsigned int v81; // [xsp+34h] [xbp-Ch] BYREF
  __int64 v82; // [xsp+38h] [xbp-8h]

  result = 4294967274LL;
  v82 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v81 = 0;
  v80 = 0;
  if ( !a1 || a1 > 0xFFFFFFFFFFFFF000LL || !a2 || (unsigned __int64)a2 > 0xFFFFFFFFFFFFF000LL )
    goto LABEL_24;
  if ( !*a2 || *a2 > 0xFFFFFFFFFFFFF000LL || (v8 = a2[2]) == 0 || v8 >= 0xFFFFFFFFFFFFF001LL )
  {
    if ( (synx_debug & 1) == 0 )
      goto LABEL_24;
    v26 = &unk_2B3D9;
    v27 = 1343;
LABEL_28:
    printk(v26, &unk_29207, "synx_internal_merge", v27, a5, a6);
    result = 4294967274LL;
    goto LABEL_24;
  }
  v9 = (unsigned __int64)a2;
  client = synx_get_client(a1);
  if ( !client || (v11 = client, client >= 0xFFFFFFFFFFFFF001LL) )
  {
    if ( (synx_debug & 1) == 0 )
    {
      result = 4294967274LL;
      goto LABEL_24;
    }
    v26 = &unk_2B010;
    v27 = 1349;
    goto LABEL_28;
  }
  v14 = _kmalloc_cache_noprof(_list_del_entry_valid_or_report, 3520, 368);
  if ( v14 )
  {
    while ( 1 )
    {
      if ( v14 >= 0xFFFFFFFFFFFFF001LL )
        goto LABEL_109;
      v15 = synx_util_validate_merge(v11, *(_QWORD *)v9, *(unsigned int *)(v9 + 12), &v80, &v81);
      if ( (v15 & 0x80000000) != 0 )
      {
        if ( (synx_debug & 1) != 0 )
          printk(&unk_2579B, &unk_29207, "synx_internal_merge", 1365, *(_QWORD *)(v11 + 104), v16);
        kfree(v14);
        v17 = -22;
        goto LABEL_112;
      }
      v17 = v15;
      v18 = v81;
      v19 = 8LL * v81;
      v20 = (_QWORD *)_kmalloc_noprof(v19, 3520);
      v23 = v20;
      v24 = !v20 || (unsigned __int64)v20 > 0xFFFFFFFFFFFFF000LL;
      v25 = v24;
      if ( v25 )
        break;
      if ( 8 * v18 >= 8 * (unsigned __int64)v81 )
      {
        memset(v20, 0, 8LL * v81);
        inited = synx_util_init_group_coredata(v14, v80, v9, v81, *(_QWORD *)(v11 + 112), 0);
        if ( inited )
        {
          v17 = inited;
          if ( (synx_debug & 1) != 0 )
            printk(&unk_26602, &unk_29207, "synx_internal_merge", 1384, *(_QWORD *)(v11 + 104), v29);
LABEL_36:
          kfree(v14);
          synx_util_merge_error(v11, v80, v81, v23);
          if ( *(_DWORD *)(v9 + 12) - 1 < v81 )
            kfree(v80);
          if ( !v25 )
            goto LABEL_39;
          goto LABEL_112;
        }
        if ( v81 )
        {
          v30 = 1;
          while ( 1 )
          {
            v31 = 8LL * (int)(v30 - 1);
            fence_entry = synx_util_get_fence_entry(*(_QWORD *)(v80 + v31), 1);
            map_entry = (_QWORD *)synx_util_get_map_entry(fence_entry);
            if ( v19 <= v31 )
              break;
            v23[v30 - 1] = map_entry;
            if ( !map_entry
              || (unsigned __int64)map_entry > 0xFFFFFFFFFFFFF000LL
              || !*map_entry
              || *map_entry >= 0xFFFFFFFFFFFFF001LL )
            {
              if ( v30 >= v81 )
              {
LABEL_60:
                synx_util_put_object(v14);
                kfree(v23);
                v17 = 0;
                goto LABEL_112;
              }
              while ( 1 )
              {
                v9 = 8LL * (int)v30;
                v38 = synx_util_get_fence_entry(*(_QWORD *)(v80 + v9), 1);
                v39 = synx_util_get_map_entry(v38);
                if ( v19 <= v9 )
                  goto LABEL_107;
                v40 = (int)v30;
                v41 = v81;
                ++v30;
                v23[v40] = v39;
                if ( v30 >= v41 )
                  goto LABEL_60;
              }
            }
            v34 = v30++ >= v81;
            if ( v34 )
              goto LABEL_50;
          }
        }
        else
        {
LABEL_50:
          v35 = synx_util_insert_to_map(v14, **(unsigned int **)(v9 + 16), 0, 0);
          v36 = v35;
          if ( !v35 || v35 >= 0xFFFFFFFFFFFFF001LL )
          {
            synx_util_put_object(v14);
            kfree(v23);
            v17 = v36;
            goto LABEL_112;
          }
          v37 = synx_util_add_callback(v14, **(unsigned int **)(v9 + 16));
          if ( v37 )
            goto LABEL_56;
          v37 = synx_util_init_handle(v11, v14, *(_QWORD *)(v9 + 16), v36);
          if ( v37 )
          {
            if ( (synx_debug & 1) != 0 )
            {
              v66 = **(unsigned int **)(v9 + 16);
              v67 = v37;
              printk(&unk_27920, &unk_29207, "synx_internal_merge", 1423, *(_QWORD *)(v11 + 104), v66);
              v37 = v67;
            }
LABEL_56:
            v17 = v37;
            synx_util_release_map_entry(v36);
LABEL_39:
            kfree(v23);
            goto LABEL_112;
          }
          v79 = 4 * v81;
          v42 = _kmalloc_noprof(v79, 3520);
          if ( !v42 || v42 >= 0xFFFFFFFFFFFFF001LL )
          {
            if ( (synx_debug & 1) != 0 )
              printk(&unk_27D59, &unk_29207, "synx_internal_merge", 1429, v43, v44);
LABEL_118:
            v71 = -12;
LABEL_119:
            kfree(v23);
            synx_native_release_core(v11, **(_DWORD **)(v9 + 16));
            synx_put_client(v11);
            result = v71;
            goto LABEL_24;
          }
          v78 = v42;
          v45 = 4 * v81;
          v77 = _kmalloc_noprof(v45, 3520);
          if ( !v77 || v77 > 0xFFFFFFFFFFFFF000LL )
          {
            if ( (synx_debug & 1) != 0 )
              printk(&unk_2B867, &unk_29207, "synx_internal_merge", 1436, v46, v47);
            kfree(v78);
            goto LABEL_118;
          }
          if ( !v81 )
          {
            if ( (*(_BYTE *)(v9 + 8) & 2) != 0 )
            {
              v49 = 0;
LABEL_100:
              v68 = synx_global_merge(v77, (unsigned int)v49, **(unsigned __int16 **)(v9 + 16));
              if ( v68 )
              {
                v71 = v68;
                if ( (synx_debug & 1) != 0 )
                  printk(&unk_2B8A0, &unk_29207, "synx_internal_merge", 1455, v69, v70);
                kfree(v78);
                kfree(v77);
                goto LABEL_119;
              }
            }
LABEL_104:
            if ( (synx_debug & 0x80) != 0 )
              printk(
                &unk_26E81,
                &unk_25D36,
                "synx_internal_merge",
                1490,
                *(_QWORD *)(v11 + 104),
                **(unsigned int **)(v9 + 16));
            kfree(v78);
            kfree(v77);
            kfree(v23);
            synx_put_client(v11);
            result = 0;
            goto LABEL_24;
          }
          v48 = 0;
          v49 = 0;
          do
          {
            v50 = synx_util_get_fence_entry(*(_QWORD *)(v80 + 8LL * (int)v48), 1);
            if ( (v50 & 0x100000) != 0 )
            {
              v51 = 4LL * v49;
              v34 = v79 >= v51;
              v52 = v79 - v51;
              if ( !v34 )
                goto LABEL_107;
              if ( v52 < 4 )
                goto LABEL_107;
              v53 = v49;
              v54 = 4LL * v49;
              *(_DWORD *)(v78 + v54) = v50;
              if ( v45 < v54 || v45 - v54 < 4 )
                goto LABEL_107;
              ++v49;
              *(_DWORD *)(v77 + 4 * v53) = (unsigned __int16)v50;
            }
            ++v48;
          }
          while ( v48 < v81 );
          if ( (*(_BYTE *)(v9 + 8) & 2) != 0 )
            goto LABEL_100;
          if ( v49 < 1 )
            goto LABEL_104;
          v55 = v79;
          v56 = 0;
          v75 = 0;
          v76 = 4LL * (unsigned int)v49;
          while ( v79 >= v56 && v55 >= 4 )
          {
            v57 = synx_global_test_status_set_wait(*(unsigned __int16 *)(v78 + v56), 0);
            if ( v57 != 1 )
            {
              if ( v79 < v56 )
                break;
              v58 = v57;
              v59 = synx_util_acquire_handle(v11, *(unsigned int *)(v78 + v56));
              if ( v59
                && (v60 = v59, v59 <= 0xFFFFFFFFFFFFF000LL)
                && (v61 = *(_QWORD *)(v59 + 8)) != 0
                && v61 < 0xFFFFFFFFFFFFF001LL )
              {
                mutex_lock(v61 + 72);
                if ( *(_DWORD *)(v14 + 128) == 1 )
                  v75 = synx_native_signal_fence(v61, v58, v62, v63, v64, v65);
                mutex_unlock(v61 + 72);
                if ( v75 && (synx_debug & 1) != 0 )
                {
                  if ( v79 < v56 )
                    break;
                  printk(&unk_2B0A3, &unk_29207, "synx_internal_merge", 1480, *(unsigned int *)(v78 + v56), v75);
                }
                synx_util_release_handle(v60);
              }
              else if ( (synx_debug & 1) != 0 )
              {
                if ( v79 < v56 )
                  break;
                printk(
                  &unk_2992A,
                  &unk_29207,
                  "synx_internal_merge",
                  1472,
                  *(_QWORD *)(v11 + 104),
                  *(unsigned int *)(v78 + v56));
              }
            }
            v56 += 4LL;
            v55 -= 4LL;
            if ( v76 == v56 )
              goto LABEL_104;
          }
        }
LABEL_107:
        __break(1u);
      }
      _fortify_panic(15);
      StatusReg = _ReadStatusReg(SP_EL0);
      v73 = *(_QWORD *)(StatusReg + 80);
      v74 = _list_del_entry_valid_or_report;
      *(_QWORD *)(StatusReg + 80) = &synx_internal_merge__alloc_tag;
      v14 = _kmalloc_cache_noprof(v74, 3520, 368);
      *(_QWORD *)(StatusReg + 80) = v73;
      if ( !v14 )
        goto LABEL_109;
    }
    if ( (synx_debug & 1) != 0 )
      printk(&unk_296B5, &unk_29207, "synx_internal_merge", 1373, v21, v22);
    goto LABEL_36;
  }
LABEL_109:
  if ( (synx_debug & 1) != 0 )
    printk(&unk_2A5C1, &unk_29207, "synx_internal_merge", 1355, v12, v13);
  v17 = -12;
LABEL_112:
  synx_put_client(v11);
  result = v17;
LABEL_24:
  _ReadStatusReg(SP_EL0);
  return result;
}
