__int64 __fastcall synx_get_child_status(__int64 a1)
{
  unsigned __int64 v1; // x26
  unsigned int v2; // w19
  __int64 v3; // x28
  __int64 fence_entry; // x0
  unsigned int v5; // w23
  unsigned __int64 *map_entry; // x0
  __int64 v7; // x5
  unsigned __int64 *v8; // x24
  unsigned __int64 v9; // x21
  unsigned int status; // w25

  v1 = *(_QWORD *)(a1 + 64);
  v2 = 4095;
  if ( v1 > 0xFFFFFFFFFFFFF000LL || !v1 || *(_UNKNOWN **)(v1 + 8) != &dma_fence_array_ops || !*(_DWORD *)(v1 + 68) )
    return v2;
  v3 = 0;
  while ( 1 )
  {
    fence_entry = synx_util_get_fence_entry(*(_QWORD *)(*(_QWORD *)(v1 + 80) + 8 * v3), 1);
    if ( !(_DWORD)fence_entry )
    {
      fence_entry = synx_util_get_fence_entry(*(_QWORD *)(*(_QWORD *)(v1 + 80) + 8 * v3), 0);
      if ( !(_DWORD)fence_entry )
        goto LABEL_6;
    }
    v5 = fence_entry;
    map_entry = (unsigned __int64 *)synx_util_get_map_entry(fence_entry);
    if ( !map_entry )
      break;
    v8 = map_entry;
    if ( (unsigned __int64)map_entry > 0xFFFFFFFFFFFFF000LL )
      break;
    v9 = *map_entry;
    if ( !*map_entry || v9 >= 0xFFFFFFFFFFFFF001LL )
      break;
    mutex_lock(v9 + 72);
    if ( (*(_BYTE *)(v9 + 124) & 2) != 0 )
      status = synx_global_get_status(*(unsigned int *)(v9 + 344));
    else
      status = *(_DWORD *)(v9 + 128);
    mutex_unlock(v9 + 72);
    synx_util_release_map_entry(v8);
    if ( (synx_debug & 0x10) != 0 )
    {
      printk(&unk_26E52, "verb", "synx_get_child_status", 678, v5, status);
      if ( status != 1 )
      {
LABEL_18:
        if ( status - 3 < 0x3E || v2 == 4095 )
          v2 = status;
      }
    }
    else if ( status != 1 )
    {
      goto LABEL_18;
    }
LABEL_6:
    if ( ++v3 >= (unsigned __int64)*(unsigned int *)(v1 + 68) )
      return v2;
  }
  if ( (synx_debug & 1) != 0 )
    printk(&unk_26E24, &unk_29207, "synx_get_child_status", 665, v5, v7);
  return v2;
}
