__int64 __fastcall synx_internal_get_fence(__int64 a1, unsigned int a2)
{
  unsigned __int64 client; // x0
  __int64 v4; // x4
  __int64 v5; // x5
  unsigned __int64 v6; // x19
  unsigned __int64 v7; // x0
  unsigned __int64 v8; // x22
  unsigned __int64 v9; // x8
  unsigned __int64 v10; // x23
  __int64 v11; // x20
  unsigned __int64 v14; // x20
  unsigned int v20; // w8

  client = synx_get_client();
  if ( client && client < 0xFFFFFFFFFFFFF001LL )
  {
    v6 = client;
    v7 = synx_util_acquire_handle();
    if ( !v7
      || v7 > 0xFFFFFFFFFFFFF000LL
      || (v8 = *(_QWORD *)(v7 + 8)) == 0
      || v8 > 0xFFFFFFFFFFFFF000LL
      || (v9 = *(_QWORD *)(v8 + 64)) == 0
      || v9 >= 0xFFFFFFFFFFFFF001LL )
    {
      if ( (synx_debug & 1) != 0 )
      {
        v14 = v7;
        printk(&unk_29EEC, &unk_29207, "synx_internal_get_fence", 212, *(_QWORD *)(v6 + 104), a2);
        v7 = v14;
      }
      v11 = 0;
      goto LABEL_20;
    }
    v10 = v7;
    mutex_lock(v8 + 72);
    v11 = *(_QWORD *)(v8 + 64);
    if ( (synx_debug & 0x10) != 0 )
    {
      printk(&unk_25A4E, "verb", "synx_internal_get_fence", 218, *(_QWORD *)(v6 + 104), a2);
      if ( v11 )
        goto LABEL_11;
    }
    else if ( v11 )
    {
LABEL_11:
      _X0 = (unsigned int *)(v11 + 56);
      __asm { PRFM            #0x11, [X0] }
      do
        v20 = __ldxr(_X0);
      while ( __stxr(v20 + 1, _X0) );
      if ( !v20 || (((v20 + 1) | v20) & 0x80000000) != 0 )
        refcount_warn_saturate();
    }
    mutex_unlock(v8 + 72);
    v7 = v10;
LABEL_20:
    synx_util_release_handle(v7);
    synx_put_client(v6);
    return v11;
  }
  if ( (synx_debug & 1) != 0 )
    printk(&unk_2B010, &unk_29207, "synx_internal_get_fence", 202, v4, v5);
  return 0;
}
