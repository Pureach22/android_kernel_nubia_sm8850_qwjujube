__int64 __fastcall synx_poll(__int64 a1, _DWORD **a2)
{
  unsigned __int64 client; // x0
  __int64 v5; // x4
  __int64 v6; // x5
  _DWORD *v7; // x8
  unsigned __int64 v8; // x21
  unsigned __int64 v9; // x20
  unsigned int v10; // w19

  client = synx_get_client(*(_QWORD *)(a1 + 32));
  if ( client && client < 0xFFFFFFFFFFFFF001LL )
  {
    if ( a2 )
    {
      v7 = *a2;
      if ( *a2 )
      {
        v8 = client;
        if ( *(v7 - 1) != -442429149 )
          __break(0x8228u);
        ((void (__fastcall *)(__int64, unsigned __int64, _DWORD **))v7)(a1, client + 192, a2);
        __dmb(0xBu);
        client = v8;
      }
    }
    v9 = client;
    mutex_lock(client + 128);
    v10 = 2 * (*(_QWORD *)(v9 + 176) != v9 + 176);
    mutex_unlock(v9 + 128);
    synx_put_client(v9);
  }
  else
  {
    if ( (synx_debug & 1) != 0 )
      printk(&unk_27E1F, &unk_29207, "synx_poll", 3701, v5, v6);
    return 0;
  }
  return v10;
}
