__int64 __fastcall synx_util_cb_dispatch(__int64 a1)
{
  _QWORD *v2; // x19
  unsigned __int64 client; // x0
  __int64 v4; // x4
  __int64 v5; // x5
  __int64 v6; // x5
  unsigned __int64 v7; // x20
  unsigned __int64 v8; // x8
  unsigned __int64 v9; // x8
  __int64 v10; // x1
  __int64 (__fastcall *v11)(__int64, int, __int64, __int64, __int64, __int64); // x23
  unsigned int v12; // w20
  unsigned __int64 v13; // x2
  unsigned __int64 v14; // x9
  __int64 v15; // x8
  unsigned __int64 v16; // x20
  unsigned __int64 v17; // x24
  unsigned int v19; // w21
  unsigned __int64 v20; // x22
  unsigned __int64 v21; // x21
  unsigned int v22; // w22
  unsigned __int64 v23; // x24
  unsigned __int64 v24; // x21
  unsigned int v25; // w22
  unsigned __int64 v26; // x24
  unsigned __int64 v33; // x10

  v2 = (_QWORD *)(a1 - 72);
  client = synx_get_client(*(_QWORD *)(a1 - 72));
  if ( client && client < 0xFFFFFFFFFFFFF001LL )
  {
    v6 = *(unsigned int *)(a1 - 64);
    if ( (unsigned int)(v6 - 4096) <= 0xFFFFF000 )
    {
      if ( (synx_debug & 1) != 0 )
      {
        v7 = client;
        printk(&unk_2A855, &unk_29207, "synx_util_cb_dispatch", 1423, *(_QWORD *)(client + 104), v6);
        client = v7;
      }
LABEL_26:
      synx_put_client(client);
      return kfree(v2);
    }
    v8 = client + (v6 << 6);
    if ( (*(_BYTE *)(v8 + 728) & 1) == 0 )
    {
      if ( (synx_debug & 1) != 0 )
      {
        v16 = client;
        printk(&unk_276AD, &unk_29207, "synx_util_cb_dispatch", 1430, v4, v6);
        client = v16;
      }
      goto LABEL_26;
    }
    v9 = v8 + 728;
    v10 = *(unsigned int *)(a1 - 56);
    v11 = *(__int64 (__fastcall **)(__int64, int, __int64, __int64, __int64, __int64))(v9 + 32);
    v12 = *(_DWORD *)(v9 + 16);
    if ( v11 != synx_util_default_user_callback )
    {
      v13 = *(_QWORD *)(v9 + 24);
      if ( v9 && v9 <= 0xFFFFFFFFFFFFF000LL )
      {
        v14 = *(unsigned int *)(v9 + 4);
        *(_QWORD *)(v9 + 16) = 0;
        *(_QWORD *)(v9 + 24) = 0;
        *(_QWORD *)(v9 + 32) = 0;
        *(_QWORD *)(v9 + 40) = 0;
        *(_QWORD *)(v9 + 48) = 0;
        *(_QWORD *)(v9 + 56) = 0;
        *(_QWORD *)v9 = 0;
        *(_QWORD *)(v9 + 8) = 0;
        if ( (unsigned int)(v14 - 1) <= 0xFFE )
        {
          v15 = 1LL << v14;
          _X9 = (unsigned __int64 *)(client + 216 + 8 * (v14 >> 6));
          __asm { PRFM            #0x11, [X9] }
          do
            v33 = __ldxr(_X9);
          while ( __stxr(v33 & ~v15, _X9) );
          goto LABEL_21;
        }
        if ( (synx_debug & 1) != 0 )
        {
          v24 = client;
          v25 = v10;
          v26 = v13;
          printk(&unk_28BDA, &unk_29207, "synx_util_clear_cb_entry", 1348, v4, v6);
          v13 = v26;
          v10 = v25;
          client = v24;
        }
      }
      if ( (synx_debug & 1) != 0 )
      {
        v21 = client;
        v22 = v10;
        v23 = v13;
        printk(&unk_2567C, &unk_29207, "synx_util_cb_dispatch", 1452, *(_QWORD *)(client + 104), v6);
        v13 = v23;
        v10 = v22;
        client = v21;
      }
      goto LABEL_21;
    }
    v13 = v9;
LABEL_21:
    v17 = client;
    if ( (synx_debug & 8) != 0 )
    {
      v19 = v10;
      v20 = v13;
      printk(&unk_25BFD, &unk_2A972, "synx_util_cb_dispatch", 1457, v12, (unsigned int)v10);
      v13 = v20;
      v10 = v19;
    }
    if ( *((_DWORD *)v11 - 1) != 1343075257 )
      __break(0x8237u);
    ((void (__fastcall *)(_QWORD, __int64, unsigned __int64))v11)(v12, v10, v13);
    client = v17;
    goto LABEL_26;
  }
  if ( (synx_debug & 1) != 0 )
    printk(&unk_27670, &unk_29207, "synx_util_cb_dispatch", 1415, *v2, v5);
  return kfree(v2);
}
