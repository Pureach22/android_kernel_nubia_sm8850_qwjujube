__int64 __fastcall synx_fence_enable_handler(__int64 a1)
{
  __int64 v1; // x19
  __int64 v2; // x21
  unsigned int fence_entry; // w20
  _QWORD *map_entry; // x0
  __int64 v5; // x4
  __int64 v6; // x5
  unsigned int v7; // w21
  __int64 v8; // x22
  _QWORD *v9; // x20
  unsigned int v10; // w0

  v1 = a1 - 8;
  v2 = *(_QWORD *)(a1 - 8);
  fence_entry = synx_util_get_fence_entry(v2, 1);
  if ( (synx_debug & 8) != 0 )
  {
    printk(&unk_28D72, &unk_2A972, "synx_fence_enable_handler", 75, v2, fence_entry);
    if ( (fence_entry & 0x100000) == 0 )
      return kfree(v1);
  }
  else if ( (fence_entry & 0x100000) == 0 )
  {
    return kfree(v1);
  }
  map_entry = (_QWORD *)synx_util_get_map_entry(fence_entry);
  if ( map_entry && (unsigned __int64)map_entry < 0xFFFFFFFFFFFFF001LL )
  {
    if ( *(_UNKNOWN **)(v2 + 8) == &dma_fence_array_ops )
    {
      if ( (synx_debug & 1) == 0 )
        goto LABEL_16;
      v9 = map_entry;
      printk(&unk_2712D, &unk_29207, "synx_fence_enable_handler", 88, v5, v6);
    }
    else
    {
      v7 = (unsigned __int16)fence_entry;
      if ( (unsigned int)(unsigned __int16)fence_entry - 1 >= 0xFFF )
      {
        if ( (synx_debug & 1) == 0 )
          goto LABEL_16;
        v9 = map_entry;
        printk(&unk_27C7E, &unk_29207, "synx_fence_enable_handler", 96, v7, v6);
      }
      else
      {
        v8 = *map_entry;
        v9 = map_entry;
        mutex_lock(*map_entry + 72LL);
        v10 = synx_global_test_status_set_parent_child_wait(v7, 0);
        if ( v10 != 1 )
          synx_native_signal_fence(v8, v10);
        mutex_unlock(v8 + 72);
      }
    }
    map_entry = v9;
LABEL_16:
    synx_util_release_map_entry(map_entry);
    return kfree(v1);
  }
  if ( (synx_debug & 1) != 0 )
    printk(&unk_270F7, &unk_29207, "synx_fence_enable_handler", 81, fence_entry, v6);
  return kfree(v1);
}
