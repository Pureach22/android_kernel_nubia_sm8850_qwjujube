__int64 __fastcall synx_debugfs_util_print_client_table(__int64 *a1, __int64 *a2)
{
  __int64 v3; // x8
  __int64 v4; // x0
  __int64 v6; // x1
  __int16 v7; // w9
  __int64 v8; // x26
  __int64 v9; // x8
  unsigned __int64 v10; // x22
  __int64 v13; // x21
  __int64 v14; // x8
  unsigned __int64 v15; // x26
  __int64 v16; // x27
  unsigned int v18; // w8
  __int64 v19; // x0
  __int16 v20; // w9
  __int64 v21; // x8
  __int64 v22; // x1
  __int64 v23; // x0
  __int64 v24; // x1
  __int64 v25; // x1
  unsigned int v27; // w8
  int v29; // w8
  __int64 v30; // x1
  unsigned int v35; // w8
  int v38; // w8
  int v42; // w8
  __int64 v43; // [xsp+0h] [xbp-20h]
  __int64 v44; // [xsp+8h] [xbp-18h]
  unsigned int *v45; // [xsp+18h] [xbp-8h]

  v3 = *a2;
  v4 = *a1;
  v6 = *a2 - v4;
  if ( (unsigned __int64)(8 * v6 - 51) <= 0xFFFFFFFFFFFFFFFALL )
  {
    v4 = *a1 + (int)scnprintf(v4, v6, "\n\t ------------- CLIENT MAP TABLE------------\n");
    *a1 = v4;
    v3 = *a2;
  }
  v7 = synx_columns;
  if ( (synx_columns & 0x4000) != 0 && (unsigned __int64)(8 * (v3 - v4) - 18) <= 0xFFFFFFFFFFFFFFFALL )
  {
    v4 = *a1 + (int)scnprintf(v4, v3 - v4, "| CLIENT ID |");
    *a1 = v4;
    v7 = synx_columns;
    v3 = *a2;
  }
  if ( (v7 & 0x200) != 0 )
  {
    v4 = *a1 + (int)scnprintf(v4, v3 - v4, "|CLIENT REF COUNT|");
    *a1 = v4;
    v7 = synx_columns;
    v3 = *a2;
  }
  if ( (v7 & 2) != 0 && (unsigned __int64)(8 * (v3 - v4) - 18) <= 0xFFFFFFFFFFFFFFFALL )
  {
    v4 = *a1 + (int)scnprintf(v4, v3 - v4, "| HANDLE ID |");
    *a1 = v4;
    v7 = synx_columns;
    v3 = *a2;
  }
  if ( (v7 & 0x200) != 0 )
  {
    v4 = *a1 + (int)scnprintf(v4, v3 - v4, "|REF COUNT|");
    *a1 = v4;
    LOBYTE(v7) = synx_columns;
    v3 = *a2;
  }
  if ( (v7 & 0x80) != 0 )
  {
    v4 = *a1 + (int)scnprintf(v4, v3 - v4, "|REL COUNT|");
    *a1 = v4;
    v3 = *a2;
  }
  *a1 += (int)scnprintf(v4, v3 - v4, "\n");
  raw_spin_lock_bh(*(_QWORD *)(synx_dev + 152));
  v8 = 0;
  while ( 1 )
  {
    v9 = *(_QWORD *)(*(_QWORD *)(synx_dev + 152) + 8 * v8 + 8);
    v10 = v9 - 264960;
    if ( v9 && v9 != 264960 )
      break;
LABEL_21:
    if ( ++v8 == 256 )
      return raw_spin_unlock_bh(*(_QWORD *)(synx_dev + 152));
  }
  v43 = v8;
LABEL_23:
  if ( v10 > 0xFFFFFFFFFFFFF000LL )
    return raw_spin_unlock_bh(*(_QWORD *)(synx_dev + 152));
  _X0 = (unsigned int *)(v10 + 120);
  v44 = *(_QWORD *)(v10 + 264960);
  __asm { PRFM            #0x11, [X0] }
  do
    v35 = __ldxr(_X0);
  while ( __stxr(v35 + 1, _X0) );
  v45 = (unsigned int *)(v10 + 120);
  if ( !v35 )
  {
    v30 = 2;
    goto LABEL_81;
  }
  if ( (((v35 + 1) | v35) & 0x80000000) != 0 )
  {
    v30 = 1;
LABEL_81:
    refcount_warn_saturate(_X0, v30);
  }
  raw_spin_lock_bh(v10 + 264920);
  v13 = 0;
  while ( 1 )
  {
    v14 = *(_QWORD *)(v10 + 262872 + 8 * v13);
    if ( v14 )
    {
      v15 = v14 - 72;
      if ( v14 != 72 )
        break;
    }
LABEL_27:
    if ( ++v13 == 256 )
    {
      raw_spin_unlock_bh(v10 + 264920);
      _X0 = v10 + 120;
      __asm { PRFM            #0x11, [X0] }
      do
        v38 = __ldxr(v45);
      while ( __stlxr(v38 - 1, v45) );
      v8 = v43;
      if ( v38 == 1 )
      {
        __dmb(9u);
        synx_client_destroy();
      }
      else if ( v38 <= 0 )
      {
        refcount_warn_saturate(v45, 3);
      }
      if ( v44 )
      {
        v10 = v44 - 264960;
        if ( v44 != 264960 )
          goto LABEL_23;
      }
      goto LABEL_21;
    }
  }
  while ( 2 )
  {
    if ( v15 <= 0xFFFFFFFFFFFFF000LL )
    {
      v16 = *(_QWORD *)(v15 + 72);
      _X28 = (unsigned int *)(v15 + 24);
      __asm { PRFM            #0x11, [X28] }
      do
        v27 = __ldxr(_X28);
      while ( __stxr(v27 + 1, _X28) );
      if ( v27 )
      {
        if ( (((v27 + 1) | v27) & 0x80000000) == 0 )
          goto LABEL_33;
        v25 = 1;
      }
      else
      {
        v25 = 2;
      }
      refcount_warn_saturate(v15 + 24, v25);
LABEL_33:
      v18 = *(_DWORD *)(v15 + 28);
      if ( v18 >= lower_handle_id && v18 <= upper_handle_id )
      {
        v19 = *a1;
        v20 = synx_columns;
        v21 = *a2;
        if ( (synx_columns & 0x4000) != 0 && (unsigned __int64)(8 * (v21 - v19) - 10) <= 0xFFFFFFFFFFFFFFFALL )
        {
          v19 = *a1 + (int)scnprintf(v19, v21 - v19, "\t%llu", *(_QWORD *)(v10 + 104));
          *a1 = v19;
          v20 = synx_columns;
          v21 = *a2;
        }
        if ( (v20 & 0x200) != 0 && ((v21 - v19) & 0x1FFFFFFFFFFFFFFFLL) != 1 )
        {
          v19 = *a1 + (int)scnprintf(v19, v21 - v19, "\t\t%d", *v45);
          *a1 = v19;
          v20 = synx_columns;
          v21 = *a2;
        }
        if ( (v20 & 2) != 0 )
        {
          v19 = *a1 + (int)scnprintf(v19, v21 - v19, "\t%d", *(_DWORD *)(v15 + 28));
          *a1 = v19;
          v20 = synx_columns;
          v21 = *a2;
        }
        if ( (v20 & 0x200) != 0 && ((v21 - v19) & 0x1FFFFFFFFFFFFFFFLL) != 1 )
        {
          v19 = *a1 + (int)scnprintf(v19, v21 - v19, "\t\t%d", *_X28);
          *a1 = v19;
          LOBYTE(v20) = synx_columns;
          v21 = *a2;
        }
        if ( (v20 & 0x80) != 0 && ((v21 - v19) & 0x1FFFFFFFFFFFFFFFLL) != 1 )
        {
          v19 = *a1 + (int)scnprintf(v19, v21 - v19, "\t\t%d", *(_DWORD *)(v15 + 32));
          *a1 = v19;
          v21 = *a2;
        }
        v22 = v21 - v19;
        if ( (unsigned __int64)(8 * (v21 - v19) - 44) <= 0xFFFFFFFFFFFFFFFALL )
        {
          v19 = *a1 + (int)scnprintf(v19, v22, "\n\t-------------------------------------");
          *a1 = v19;
          v22 = *a2 - v19;
        }
        v23 = *a1 + (int)scnprintf(v19, v22, "-----------------------------------------");
        *a1 = v23;
        v24 = *a2 - v23;
        if ( (v24 & 0x1FFFFFFFFFFFFFFFLL) != 2 )
          *a1 += (int)scnprintf(v23, v24, "-----------\n");
      }
      __asm { PRFM            #0x11, [X28] }
      do
        v29 = __ldxr(_X28);
      while ( __stlxr(v29 - 1, _X28) );
      if ( v29 == 1 )
      {
        __dmb(9u);
        synx_util_destroy_handle(v15 + 24);
        if ( !v16 )
          goto LABEL_27;
      }
      else if ( v29 <= 0 )
      {
        refcount_warn_saturate(v15 + 24, 3);
        if ( !v16 )
          goto LABEL_27;
      }
      else if ( !v16 )
      {
        goto LABEL_27;
      }
      v15 = v16 - 72;
      if ( v16 == 72 )
        goto LABEL_27;
      continue;
    }
    break;
  }
  raw_spin_unlock_bh(v10 + 264920);
  _X0 = v10 + 120;
  __asm { PRFM            #0x11, [X0] }
  do
    v42 = __ldxr(v45);
  while ( __stlxr(v42 - 1, v45) );
  if ( v42 == 1 )
  {
    __dmb(9u);
    synx_client_destroy();
  }
  else if ( v42 <= 0 )
  {
    refcount_warn_saturate(v45, 3);
  }
  return raw_spin_unlock_bh(*(_QWORD *)(synx_dev + 152));
}
