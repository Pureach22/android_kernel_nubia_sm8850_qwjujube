__int64 __fastcall synx_internal_wait(__int64 a1, unsigned int a2, unsigned int a3)
{
  unsigned __int64 client; // x0
  __int64 v6; // x4
  __int64 v7; // x5
  unsigned __int64 v8; // x19
  unsigned __int64 v9; // x0
  unsigned __int64 v10; // x21
  unsigned __int64 v11; // x8
  unsigned __int64 v12; // x24
  unsigned int v13; // w0
  unsigned int v14; // w23
  __int64 v15; // x2
  __int64 v16; // x3
  __int64 v17; // x4
  __int64 v18; // x5
  unsigned int object_status; // w20
  unsigned __int64 v21; // x21
  __int64 v22; // x23
  __int64 v23; // x0

  client = synx_get_client(a1);
  if ( client && client < 0xFFFFFFFFFFFFF001LL )
  {
    v8 = client;
    v9 = synx_util_acquire_handle(client, a2);
    if ( v9
      && v9 <= 0xFFFFFFFFFFFFF000LL
      && (v10 = *(_QWORD *)(v9 + 8)) != 0
      && v10 <= 0xFFFFFFFFFFFFF000LL
      && (v11 = *(_QWORD *)(v10 + 64)) != 0
      && v11 < 0xFFFFFFFFFFFFF001LL )
    {
      v12 = v9;
      if ( (a2 & 0x100000) != 0 )
      {
        v13 = synx_global_test_status_set_wait((unsigned __int16)a2, 0);
        if ( v13 != 1 )
        {
          v14 = v13;
          mutex_lock(v10 + 72);
          if ( (*(_BYTE *)(v10 + 124) & 0x20) != 0 )
            synx_native_signal_merged_fence(v10);
          else
            synx_native_signal_fence(v10, v14, v15, v16, v17, v18);
          mutex_unlock(v10 + 72);
        }
      }
      v22 = *(_QWORD *)(v10 + 64);
      v23 = _msecs_to_jiffies(a3);
      if ( dma_fence_wait_timeout(v22, 0, v23) )
      {
        if ( (synx_debug & 0x10) != 0 )
          printk(&unk_2AD1C, "verb", "synx_internal_wait", 1893, *(_QWORD *)(v8 + 104), a2);
        mutex_lock(v10 + 72);
        object_status = synx_util_get_object_status(v10);
        mutex_unlock(v10 + 72);
        v9 = v12;
      }
      else
      {
        if ( (synx_debug & 1) != 0 )
          printk(&unk_2ACDE, &unk_29207, "synx_internal_wait", 1889, *(_QWORD *)(v8 + 104), a2);
        v9 = v12;
        object_status = -110;
      }
    }
    else
    {
      if ( (synx_debug & 1) != 0 )
      {
        v21 = v9;
        printk(&unk_29EEC, &unk_29207, "synx_internal_wait", 1866, *(_QWORD *)(v8 + 104), a2);
        v9 = v21;
      }
      object_status = -22;
    }
    synx_util_release_handle(v9);
    synx_put_client(v8);
  }
  else
  {
    if ( (synx_debug & 1) != 0 )
      printk(&unk_2B010, &unk_29207, "synx_internal_wait", 1857, v6, v7);
    return (unsigned int)-22;
  }
  return object_status;
}
