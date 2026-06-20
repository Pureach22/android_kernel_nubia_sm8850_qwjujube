__int64 __fastcall synx_table_read(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v7; // x28
  __int64 v8; // x0
  __int64 v9; // x22
  int v10; // w0
  int v11; // w0
  int v12; // w8
  char *v13; // x19
  int v14; // w0
  char *v15; // x23
  __int64 v16; // x0
  char *v17; // x21
  __int64 v18; // x1
  int v19; // w0
  int v20; // w0
  __int64 v21; // x0
  int v22; // w0
  char **v23; // x8
  char *v24; // x9
  __int64 v25; // x19
  __int64 v27; // [xsp+8h] [xbp-28h]
  __int64 v28; // [xsp+10h] [xbp-20h]
  __int64 v29; // [xsp+18h] [xbp-18h] BYREF
  _QWORD v30[2]; // [xsp+20h] [xbp-10h] BYREF

  v30[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = *(_QWORD *)(a1 + 32);
  v8 = _kmalloc_large_noprof(0x10000, 3520);
  v9 = v8;
  if ( !v8 )
  {
    v25 = -12;
    goto LABEL_29;
  }
  v29 = v8 + 0x10000;
  v10 = scnprintf(v8, 0x10000, "\n\tHandle ID start value : %d", lower_handle_id);
  v30[0] = v9 + v10;
  v11 = scnprintf(v30[0], 0x10000LL - v10, "\n\tHandle ID end value : %d\n", upper_handle_id);
  v12 = synx_columns;
  v30[0] += v11;
  if ( (synx_columns & 0x20000) != 0 )
  {
    synx_debugfs_util_print_hash_table(v30, &v29, 1);
    v12 = synx_columns;
    if ( (synx_columns & 0x10000) == 0 )
    {
LABEL_4:
      if ( (v12 & 0x40000) == 0 )
        goto LABEL_5;
      goto LABEL_11;
    }
  }
  else if ( (synx_columns & 0x10000) == 0 )
  {
    goto LABEL_4;
  }
  synx_debugfs_util_print_hash_table(v30, &v29, 0);
  v12 = synx_columns;
  if ( (synx_columns & 0x40000) == 0 )
  {
LABEL_5:
    if ( (v12 & 0x80000) == 0 )
      goto LABEL_6;
    goto LABEL_12;
  }
LABEL_11:
  synx_debugfs_util_print_client_table(v30, &v29);
  v12 = synx_columns;
  if ( (synx_columns & 0x80000) == 0 )
  {
LABEL_6:
    if ( (v12 & 0x100000) == 0 )
      goto LABEL_7;
    goto LABEL_13;
  }
LABEL_12:
  synx_debugfs_util_print_global_shared_memory(v30, &v29);
  LOWORD(v12) = synx_columns;
  if ( (synx_columns & 0x100000) == 0 )
  {
LABEL_7:
    if ( (v12 & 0x8000) == 0 )
      goto LABEL_27;
LABEL_14:
    v13 = (char *)(v7 + 336);
    if ( *(_QWORD *)(v7 + 336) != v7 + 336 )
    {
      v27 = a3;
      v28 = a4;
      v14 = scnprintf(v30[0], v29 - v30[0], "\nError(s): ");
      v30[0] += v14;
      mutex_lock(v7 + 352);
      v15 = *(char **)(v7 + 336);
      if ( v15 != v13 )
      {
        do
        {
          v16 = v30[0];
          v17 = *(char **)v15;
          v18 = v29 - v30[0];
          if ( (unsigned __int64)(8 * (v29 - v30[0]) - 18) <= 0xFFFFFFFFFFFFFFFALL )
          {
            v19 = scnprintf(v30[0], v18, "\n\tTime: %s - ", v15 - 56);
            v16 = v30[0] + v19;
            v18 = v29 - v16;
            v30[0] = v16;
          }
          v20 = scnprintf(v16, v18, "ID: %d - ", *((_DWORD *)v15 - 3));
          v21 = v30[0] + v20;
          v30[0] = v21;
          if ( ((v29 - v21) & 0x1FFFFFFFFFFFFFFFLL) != 1 )
          {
            v22 = scnprintf(v21, v29 - v21, "Code: %d", *((_DWORD *)v15 - 2));
            v30[0] += v22;
          }
          v23 = *((char ***)v15 + 1);
          if ( *v23 == v15 && (v24 = *(char **)v15, *(char **)(*(_QWORD *)v15 + 8LL) == v15) )
          {
            *((_QWORD *)v24 + 1) = v23;
            *v23 = v24;
          }
          else
          {
            _list_del_entry_valid_or_report(v15);
          }
          *(_QWORD *)v15 = 0xDEAD000000000100LL;
          *((_QWORD *)v15 + 1) = 0xDEAD000000000122LL;
          kfree(v15 - 56);
          v15 = v17;
        }
        while ( v17 != v13 );
      }
      mutex_unlock(v7 + 352);
      a3 = v27;
      a4 = v28;
    }
    goto LABEL_27;
  }
LABEL_13:
  synx_debugfs_util_print_dma_fence(v30, &v29);
  if ( (synx_columns & 0x8000) != 0 )
    goto LABEL_14;
LABEL_27:
  v25 = simple_read_from_buffer(a2, a3, a4, v9, v30[0] - v9);
  kfree(v9);
LABEL_29:
  _ReadStatusReg(SP_EL0);
  return v25;
}
