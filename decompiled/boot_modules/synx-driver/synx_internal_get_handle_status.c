__int64 __fastcall synx_internal_get_handle_status(
        unsigned __int64 a1,
        unsigned int a2,
        _DWORD *a3,
        char a4,
        __int64 a5,
        __int64 a6)
{
  unsigned __int64 v6; // x8
  int fence_entry; // w0
  __int64 v13; // x5
  int v14; // w23
  int updated; // w8

  if ( !a1
    || a1 > 0xFFFFFFFFFFFFF000LL
    || (v6 = *(_QWORD *)(a1 + 16)) == 0
    || v6 > 0xFFFFFFFFFFFFF000LL
    || (*(_BYTE *)(a1 + 8) & 8) == 0 )
  {
    if ( (synx_debug & 1) != 0 )
      printk(&unk_2A617, &unk_29207, "synx_internal_get_handle_status", 2284, a5, a6);
    return 4294967274LL;
  }
  fence_entry = synx_util_get_fence_entry(*(_QWORD *)(a1 + 16), 1);
  if ( (fence_entry & 0x100000) == 0 )
  {
    if ( (synx_debug & 1) != 0 )
      printk(&unk_25B57, &unk_29207, "synx_internal_get_handle_status", 2292, *(_QWORD *)(a1 + 16), v13);
    return 4294967274LL;
  }
  v14 = fence_entry;
  updated = synx_global_test_status_update_coredata((unsigned __int16)fence_entry, 5, a2, a4 & 1);
  if ( updated == 1 && (a4 & 1) != 0 )
    **(_DWORD **)a1 = v14;
  *a3 = updated;
  return 0;
}
