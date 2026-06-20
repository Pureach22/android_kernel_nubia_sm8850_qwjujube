__int64 __fastcall synx_internal_release(__int64 a1, int a2)
{
  unsigned __int64 client; // x0
  __int64 v4; // x4
  __int64 v5; // x5
  unsigned __int64 v6; // x19
  __int64 v7; // x9
  __int64 v8; // x8
  bool v9; // zf
  __int64 v10; // x22
  unsigned int v11; // w21
  int v12; // w9
  __int64 v13; // x8

  client = synx_get_client(a1);
  if ( client && (v6 = client, client < 0xFFFFFFFFFFFFF001LL) )
  {
    raw_spin_lock_bh(client + 264920);
    v7 = *(_QWORD *)(v6 + 8LL * ((unsigned int)(1640531527 * a2) >> 24) + 262872);
    v8 = v7 - 72;
    if ( v7 )
      v9 = v7 == 72;
    else
      v9 = 1;
    if ( v9 )
    {
      v10 = 0;
      v11 = -22;
    }
    else
    {
      v11 = -22;
      while ( 1 )
      {
        if ( *(_DWORD *)(v8 + 28) == a2 )
        {
          v12 = *(_DWORD *)(v8 + 32);
          if ( v12 )
            break;
        }
        v13 = *(_QWORD *)(v8 + 72);
        v10 = 0;
        if ( v13 )
        {
          v8 = v13 - 72;
          if ( v8 )
            continue;
        }
        goto LABEL_18;
      }
      v11 = 0;
      v10 = v8;
      *(_DWORD *)(v8 + 32) = v12 - 1;
    }
LABEL_18:
    raw_spin_unlock_bh(v6 + 264920);
    synx_util_release_handle(v10);
    synx_put_client(v6);
  }
  else
  {
    if ( (synx_debug & 1) != 0 )
      printk(&unk_2B010, &unk_29207, "synx_internal_release", 1771, v4, v5);
    return (unsigned int)-22;
  }
  return v11;
}
