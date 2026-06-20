__int64 __fastcall synx_ipc_handler(__int64 a1)
{
  unsigned int *v2; // x19
  _QWORD *map_entry; // x0
  __int64 v4; // x5
  _QWORD *v5; // x19

  v2 = (unsigned int *)(a1 - 56);
  map_entry = (_QWORD *)synx_util_get_map_entry(*(unsigned int *)(a1 - 56));
  if ( map_entry && (unsigned __int64)map_entry < 0xFFFFFFFFFFFFF001LL )
  {
    v5 = map_entry;
    synx_util_get_object(*map_entry);
    *(_QWORD *)(a1 - 40) = *v5;
    synx_util_release_map_entry(v5);
    return synx_signal_handler(a1);
  }
  if ( (synx_debug & 2) != 0 )
  {
    printk(&unk_26ECC, "warn", "synx_ipc_handler", 3896, *v2, v4);
    if ( (synx_debug & 0x80) == 0 )
      return kfree(v2);
LABEL_9:
    printk(&unk_25714, &unk_25D36, "synx_ipc_handler", 3897, v2, v4);
    return kfree(v2);
  }
  if ( (synx_debug & 0x80) != 0 )
    goto LABEL_9;
  return kfree(v2);
}
