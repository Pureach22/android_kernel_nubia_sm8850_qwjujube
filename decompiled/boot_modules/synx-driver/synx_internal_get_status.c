__int64 __fastcall synx_internal_get_status(__int64 a1, unsigned int a2)
{
  unsigned __int64 client; // x0
  __int64 v4; // x4
  __int64 v5; // x5
  unsigned __int64 v6; // x19
  unsigned __int64 v7; // x0
  unsigned __int64 v8; // x22
  unsigned __int64 v9; // x8
  unsigned __int64 v10; // x24
  unsigned int v11; // w21
  unsigned __int64 v13; // x21

  client = synx_get_client(a1);
  if ( client && client < 0xFFFFFFFFFFFFF001LL )
  {
    v6 = client;
    v7 = synx_util_acquire_handle(client, a2);
    if ( v7
      && v7 <= 0xFFFFFFFFFFFFF000LL
      && (v8 = *(_QWORD *)(v7 + 8)) != 0
      && v8 <= 0xFFFFFFFFFFFFF000LL
      && (v9 = *(_QWORD *)(v8 + 64)) != 0
      && v9 < 0xFFFFFFFFFFFFF001LL )
    {
      v10 = v7;
      mutex_lock(v8 + 72);
      synx_util_get_object_status(v8);
      v11 = *(_DWORD *)(v8 + 128);
      mutex_unlock(v8 + 72);
      if ( (synx_debug & 0x10) != 0 )
        printk(&unk_25AFA, "verb", "synx_internal_get_status", 2057, *(_QWORD *)(v6 + 104), a2);
      v7 = v10;
    }
    else
    {
      if ( (synx_debug & 1) != 0 )
      {
        v13 = v7;
        printk(&unk_29EEC, &unk_29207, "synx_internal_get_status", 2046, *(_QWORD *)(v6 + 104), a2);
        v7 = v13;
      }
      v11 = -22;
    }
    synx_util_release_handle(v7);
    synx_put_client(v6);
  }
  else
  {
    if ( (synx_debug & 1) != 0 )
      printk(&unk_2B010, &unk_29207, "synx_internal_get_status", 2036, v4, v5);
    return (unsigned int)-22;
  }
  return v11;
}
