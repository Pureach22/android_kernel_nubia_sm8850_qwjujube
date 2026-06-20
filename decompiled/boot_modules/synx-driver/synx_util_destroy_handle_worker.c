__int64 __fastcall synx_util_destroy_handle_worker(__int64 a1)
{
  synx_util_release_map_entry(*(_QWORD *)(a1 - 24));
  if ( (synx_debug & 0x10) != 0 )
    printk(&unk_28A4A, "verb", "synx_util_destroy_handle_worker", 1245, *(unsigned int *)(a1 - 12), a1 - 40);
  return kfree(a1 - 40);
}
