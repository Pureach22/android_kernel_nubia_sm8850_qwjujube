__int64 __fastcall synx_ipc_callback(__int64 a1, __int64 a2)
{
  unsigned __int64 v3; // x0
  __int64 v4; // x4
  __int64 v5; // x5
  __int64 v6; // x8
  unsigned __int64 v8; // x21

  v3 = _kmalloc_cache_noprof(_kmalloc_cache_noprof, 2336, 88);
  if ( v3 && v3 < 0xFFFFFFFFFFFFF001LL )
  {
    if ( (synx_debug & 8) != 0 )
    {
      v8 = v3;
      printk(&unk_27276, &unk_2A972, "synx_ipc_callback", 3924, HIDWORD(a2), (unsigned int)a2);
      v3 = v8;
    }
    *(_DWORD *)v3 = HIDWORD(a2);
    *(_DWORD *)(v3 + 4) = a2;
    *(_DWORD *)(v3 + 24) = 4;
    *(_QWORD *)(v3 + 56) = 0xFFFFFFFE00000LL;
    *(_QWORD *)(v3 + 64) = v3 + 64;
    *(_QWORD *)(v3 + 72) = v3 + 64;
    v6 = synx_dev;
    *(_QWORD *)(v3 + 80) = synx_ipc_handler;
    queue_work_on(32, *(_QWORD *)(v6 + 160), v3 + 56);
    return 0;
  }
  else
  {
    if ( (synx_debug & 1) != 0 )
      printk(&unk_276EF, &unk_29207, "synx_ipc_callback", 3918, v4, v5);
    return 4294967284LL;
  }
}
