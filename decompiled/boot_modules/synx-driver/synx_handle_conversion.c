__int64 __fastcall synx_handle_conversion(_DWORD *a1, unsigned __int64 a2, __int64 a3)
{
  _QWORD *v5; // x19
  unsigned __int64 map_entry; // x0
  unsigned __int64 v7; // x22
  _DWORD *v8; // x20
  __int64 v9; // x0
  __int64 v10; // x0
  unsigned __int64 v11; // x0
  unsigned __int64 v12; // x0
  __int64 v13; // x4
  void *v14; // x0
  __int64 v15; // x3
  int v16; // w9
  unsigned __int64 v17; // x0

  if ( !a2 || (v5 = (_QWORD *)a2, a2 >= 0xFFFFFFFFFFFFF001LL) )
  {
    map_entry = synx_util_get_map_entry((unsigned int)*a1);
    v7 = map_entry;
    if ( !map_entry || map_entry >= 0xFFFFFFFFFFFFF001LL )
    {
      if ( (synx_debug & 1) != 0 )
        printk(&unk_2B44A, &unk_29207, "synx_handle_conversion", 2079, (unsigned int)*a1, (unsigned int)map_entry);
      return v7;
    }
    v5 = (_QWORD *)map_entry;
  }
  v8 = (_DWORD *)*v5;
  if ( *v5 )
  {
    mutex_lock(v8 + 18);
    synx_util_get_object(v8);
    v9 = (unsigned int)v8[86];
    if ( (_DWORD)v9 )
    {
      v10 = synx_encode_handle(v9, 0, 1);
      *a1 = v10;
      v11 = synx_util_get_map_entry(v10);
      if ( !v11 || (v7 = v11, v11 >= 0xFFFFFFFFFFFFF001LL) )
      {
        v12 = synx_util_insert_to_map(v8, (unsigned int)*a1, 0, 0);
        v7 = v12;
        if ( (!v12 || v12 >= 0xFFFFFFFFFFFFF001LL) && (synx_debug & 1) != 0 )
        {
          v13 = (unsigned int)*a1;
          v14 = &unk_2B113;
          v15 = 2103;
LABEL_27:
          printk(v14, &unk_29207, "synx_handle_conversion", v15, v13, (unsigned int)v7);
        }
      }
    }
    else
    {
      ++v8[87];
      if ( (unsigned int)synx_alloc_global_handle(a1, a3) )
      {
        v7 = 0;
        goto LABEL_21;
      }
      v16 = v8[31];
      v8[86] = *(unsigned __int16 *)a1;
      v8[31] = v16 | 2;
      v17 = synx_util_insert_to_map(v8, (unsigned int)*a1, 0, 0);
      v7 = v17;
      if ( !v17 || v17 >= 0xFFFFFFFFFFFFF001LL )
      {
        synx_global_put_ref(*(unsigned __int16 *)a1);
        if ( (synx_debug & 1) != 0 )
        {
          v13 = (unsigned int)*a1;
          v14 = &unk_252D5;
          v15 = 2124;
          goto LABEL_27;
        }
      }
    }
LABEL_21:
    mutex_unlock(v8 + 18);
    if ( !v7 || v7 >= 0xFFFFFFFFFFFFF001LL )
      synx_util_put_object(v8);
    synx_util_release_map_entry(v5);
    return v7;
  }
  __break(0x800u);
  return synx_register_hw_fence();
}
