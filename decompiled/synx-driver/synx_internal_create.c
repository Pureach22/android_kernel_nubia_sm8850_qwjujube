__int64 __fastcall synx_internal_create(
        __int64 a1,
        unsigned __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6)
{
  unsigned __int64 v7; // x8
  unsigned int v8; // w8
  __int64 result; // x0
  unsigned __int64 client; // x0
  unsigned __int64 v12; // x19
  void *v13; // x0
  __int64 v14; // x3
  unsigned __int64 v15; // x0
  unsigned __int64 data; // x0
  unsigned int v17; // w25
  __int64 v18; // x0
  _BOOL8 v19; // x1
  _QWORD *map_entry; // x0
  _QWORD *v21; // x26
  unsigned int inited; // w0
  __int64 v23; // x5
  unsigned int v24; // w25
  unsigned int core; // w0
  unsigned __int64 v26; // x0
  unsigned int v27; // w0
  __int64 v28; // x5
  int v29; // w26
  __int64 i; // x8
  __int64 v31; // x25
  __int64 v32; // x8
  int v33; // w9
  unsigned int v34; // w0
  __int64 v35; // x5
  unsigned int v36; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v37; // [xsp+8h] [xbp-8h]

  v37 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a2
    || a2 > 0xFFFFFFFFFFFFF000LL
    || (v7 = *(_QWORD *)(a2 + 8)) == 0
    || v7 > 0xFFFFFFFFFFFFF000LL
    || (v8 = *(_DWORD *)(a2 + 24), v8 >= 0x11) )
  {
    if ( (synx_debug & 1) == 0 )
    {
LABEL_7:
      result = 4294967274LL;
      goto LABEL_8;
    }
    v13 = &unk_29635;
    v14 = 346;
LABEL_17:
    printk(v13, &unk_29207, "synx_internal_create", v14, a5, a6);
    goto LABEL_7;
  }
  if ( (v8 & 4) != 0 )
  {
    if ( (synx_debug & 1) != 0 )
      printk(&unk_256D0, &unk_29207, "synx_internal_create", 352, a5, a6);
    result = 4294967201LL;
  }
  else
  {
    client = synx_get_client();
    if ( !client || (v12 = client, client >= 0xFFFFFFFFFFFFF001LL) )
    {
      if ( (synx_debug & 1) == 0 )
        goto LABEL_7;
      v13 = &unk_2B010;
      v14 = 358;
      goto LABEL_17;
    }
    for ( **(_DWORD **)(a2 + 8) = 0; ; **(_DWORD **)(a2 + 8) = 0 )
    {
      v15 = *(_QWORD *)(a2 + 16);
      if ( v15 )
      {
        if ( v15 <= 0xFFFFFFFFFFFFF000LL )
        {
          data = synx_util_retrieve_data();
          if ( data )
          {
            if ( data <= 0xFFFFFFFFFFFFF000LL )
            {
              v17 = *(_DWORD *)(data + 8);
              v18 = *(_QWORD *)(a2 + 16);
              v19 = ((*(_DWORD *)(a2 + 24) >> 3) & 1) == 0;
              v36 = v17;
              synx_util_remove_data(v18, v19);
              map_entry = (_QWORD *)synx_util_get_map_entry(v17);
              if ( map_entry )
              {
                v21 = map_entry;
                if ( (unsigned __int64)map_entry <= 0xFFFFFFFFFFFFF000LL )
                {
                  inited = synx_util_init_handle(v12, *map_entry, &v36, map_entry);
                  if ( !inited )
                  {
                    **(_DWORD **)(a2 + 8) = v36;
                    goto LABEL_51;
                  }
                  v24 = inited;
                  if ( (synx_debug & 1) != 0 )
                    printk(&unk_2B0D9, &unk_29207, "synx_native_check_bind", 259, *(_QWORD *)(v12 + 104), v23);
                  synx_util_release_map_entry(v21);
                  if ( v24 != -2 )
                    goto LABEL_54;
                }
              }
            }
          }
        }
      }
      core = synx_native_create_core(v12, a2, 0);
      if ( core )
      {
        v24 = core;
        goto LABEL_54;
      }
      v26 = *(_QWORD *)(a2 + 16);
      if ( !v26 || v26 > 0xFFFFFFFFFFFFF000LL )
        goto LABEL_51;
      v27 = synx_util_save_data();
      if ( v27 != -114 )
        break;
      v29 = **(_DWORD **)(a2 + 8);
      raw_spin_lock_bh(v12 + 264920);
      for ( i = *(_QWORD *)(v12 + 262872 + 8LL * ((unsigned int)(1640531527 * v29) >> 24)); ; i = *(_QWORD *)(v32 + 72) )
      {
        v31 = 0;
        if ( !i )
          break;
        v32 = i - 72;
        if ( !v32 )
          break;
        if ( *(_DWORD *)(v32 + 28) == v29 )
        {
          v33 = *(_DWORD *)(v32 + 32);
          if ( v33 )
          {
            v31 = v32;
            *(_DWORD *)(v32 + 32) = v33 - 1;
            break;
          }
        }
      }
      raw_spin_unlock_bh(v12 + 264920);
      synx_util_release_handle(v31);
    }
    if ( v27 )
    {
      v24 = v27;
      if ( (synx_debug & 1) != 0 )
        printk(&unk_26594, &unk_29207, "synx_internal_create", 389, v27, v28);
      goto LABEL_49;
    }
    v34 = synx_bind(a1, **(unsigned int **)(a2 + 8), **(unsigned int **)(a2 + 16), ~(*(_DWORD *)(a2 + 24) >> 3) & 1LL);
    if ( v34 )
    {
      v24 = v34;
      if ( (synx_debug & 1) != 0 )
        printk(&unk_2B035, &unk_29207, "synx_internal_create", 401, *(_QWORD *)(v12 + 104), v35);
LABEL_49:
      synx_native_release_core(v12, **(unsigned int **)(a2 + 8));
      goto LABEL_54;
    }
LABEL_51:
    if ( (synx_debug & 0x10) != 0 )
      printk(&unk_2ACA7, "verb", "synx_internal_create", 411, *(_QWORD *)(v12 + 104), **(unsigned int **)(a2 + 8));
    v24 = 0;
LABEL_54:
    synx_put_client(v12);
    result = v24;
  }
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return result;
}
