unsigned __int64 __fastcall synx_signal_offload_job(__int64 a1, __int64 a2, unsigned int a3, int a4)
{
  unsigned __int64 result; // x0
  unsigned __int64 v9; // x21
  char v10; // w8
  _QWORD *v11; // x21
  __int64 v12; // x8

  result = _kmalloc_cache_noprof(_kmalloc_cache_noprof, 2336, 88);
  v9 = result;
  if ( result && result <= 0xFFFFFFFFFFFFF000LL )
  {
    synx_util_get_object(a2);
    *(_DWORD *)v9 = a3;
    *(_DWORD *)(v9 + 4) = a4;
    v10 = synx_debug;
    *(_QWORD *)(v9 + 16) = a2;
    *(_DWORD *)(v9 + 24) = 1;
    if ( (v10 & 0x10) != 0 )
      printk(&unk_28511, "verb", "synx_signal_offload_job", 882, *(_QWORD *)(a1 + 104), a3);
    *(_QWORD *)(v9 + 56) = 0xFFFFFFFE00000LL;
    v11 = (_QWORD *)(v9 + 56);
    v11[1] = v11 + 1;
    v11[2] = v11 + 1;
    v12 = synx_dev;
    v11[3] = synx_signal_handler;
    return queue_work_on(32, *(_QWORD *)(v12 + 160), v11);
  }
  return result;
}
