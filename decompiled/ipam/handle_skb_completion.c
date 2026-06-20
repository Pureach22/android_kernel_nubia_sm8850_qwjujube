_DWORD *__fastcall handle_skb_completion(__int64 *a1, char a2, _QWORD *a3)
{
  __int64 v3; // x22
  __int64 v4; // x23
  void (__fastcall *v7)(_QWORD); // x8
  __int64 v8; // x0
  void (__fastcall *v9)(_QWORD); // x8
  __int64 v10; // x8
  __int64 v11; // x0
  __int64 v12; // x0
  _DWORD *v13; // x19
  int v14; // w8
  unsigned __int64 v15; // x8
  __int64 v16; // x9
  __int64 v17; // x8
  _QWORD *v18; // x21
  _QWORD *v19; // x1
  int v20; // w8
  _QWORD *v21; // x20
  _DWORD *v22; // x25
  _QWORD *v23; // x27
  __int64 v24; // x8
  __int64 v25; // x1
  void (__fastcall *v26)(_QWORD); // x8
  int v27; // w10
  __int64 v28; // x0
  __int64 v29; // x0

  v4 = *a1;
  v3 = a1[1];
  if ( a3 )
    *a3 = v3;
  raw_spin_lock_bh(*(_QWORD *)(v3 + 80) + 1684LL);
  --**(_DWORD **)(v3 + 80);
  raw_spin_unlock_bh(*(_QWORD *)(v3 + 80) + 1684LL);
  if ( *((_WORD *)a1 + 10) )
    *(_DWORD *)(v3 + 40) = *((unsigned __int16 *)a1 + 10);
  if ( (*((_DWORD *)a1 + 4) == 4 || *(_BYTE *)(v4 + 712) == 1) && *(_DWORD *)(*(_QWORD *)(v4 + 1624) + 4LL) == 35 )
  {
    dma_unmap_page_attrs(*(_QWORD *)(ipa3_ctx + 34216), *(_QWORD *)(v3 + 24), *(unsigned int *)(v4 + 160), 2, 0);
    v7 = *(void (__fastcall **)(_QWORD))(v4 + 144);
    v8 = *(_QWORD *)(v3 + 16);
    if ( *((_DWORD *)v7 - 1) != 303786302 )
      __break(0x8228u);
    v7(v8);
    v9 = *(void (__fastcall **)(_QWORD))(v4 + 152);
    if ( *((_DWORD *)v9 - 1) != 246723534 )
      __break(0x8228u);
    v9(v3);
    ++*(_DWORD *)(v4 + 716);
    v10 = ipa3_ctx;
    if ( *((_DWORD *)a1 + 4) == 4 )
    {
      if ( ipa3_ctx )
      {
        v11 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v11 )
        {
          ipc_log_string(v11, "ipa %s:%d EOB event on WAN consumer channel, drop\n", "handle_skb_completion", 5408);
          v10 = ipa3_ctx;
        }
        v12 = *(_QWORD *)(v10 + 34160);
        if ( v12 )
          ipc_log_string(v12, "ipa %s:%d EOB event on WAN consumer channel, drop\n", "handle_skb_completion", 5408);
      }
      v13 = nullptr;
      *(_BYTE *)(v4 + 712) = 1;
    }
    else
    {
      if ( ipa3_ctx )
      {
        v28 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v28 )
        {
          ipc_log_string(v28, "ipa %s:%d Reset skip eot flag.\n", "handle_skb_completion", 5411);
          v10 = ipa3_ctx;
        }
        v29 = *(_QWORD *)(v10 + 34160);
        if ( v29 )
          ipc_log_string(v29, "ipa %s:%d Reset skip eot flag.\n", "handle_skb_completion", 5411);
      }
      v13 = nullptr;
      *(_BYTE *)(v4 + 712) = 0;
    }
  }
  else
  {
    v13 = *(_DWORD **)(v3 + 16);
    v13[52] = *(_DWORD *)(v3 + 40) + v13[56] - v13[54];
    v14 = *(_DWORD *)(v3 + 40);
    v13[28] = v14;
    if ( (a2 & 1) != 0 )
    {
      v13[10] = v14;
      v13[58] = *(_DWORD *)(v3 + 40) + 248;
    }
    v15 = *((unsigned __int8 *)a1 + 22);
    if ( v15 < 0x11 )
    {
      v16 = *(_QWORD *)(v3 + 80);
      *(_QWORD *)v3 = v3;
      *(_QWORD *)(v3 + 8) = v3;
      v17 = v16 + 16 * v15;
      v18 = (_QWORD *)(v17 + 392);
      v19 = *(_QWORD **)(v17 + 400);
      if ( v3 == v17 + 392 || (_QWORD *)v3 == v19 || (_QWORD *)*v19 != v18 )
      {
        _list_add_valid_or_report(v3, v19);
      }
      else
      {
        *(_QWORD *)(v17 + 400) = v3;
        *(_QWORD *)v3 = v18;
        *(_QWORD *)(v3 + 8) = v19;
        *v19 = v3;
      }
      if ( *((_DWORD *)a1 + 4) == 2 || (v20 = *(_DWORD *)(*(_QWORD *)(v4 + 1624) + 4LL), v20 == 127) || v20 == 33 )
      {
        v21 = (_QWORD *)v18[1];
        if ( v21 != v18 )
        {
          v22 = nullptr;
          do
          {
            v23 = (_QWORD *)v21[1];
            v13 = (_DWORD *)v21[2];
            if ( (_QWORD *)*v23 == v21 && (v24 = *v21, *(_QWORD **)(*v21 + 8LL) == v21) )
            {
              *(_QWORD *)(v24 + 8) = v23;
              *v23 = v24;
            }
            else
            {
              _list_del_entry_valid_or_report(v21);
            }
            v25 = v21[3];
            *v21 = 0xDEAD000000000100LL;
            v21[1] = 0xDEAD000000000122LL;
            dma_unmap_page_attrs(*(_QWORD *)(ipa3_ctx + 34216), v25, *(unsigned int *)(v4 + 160), 2, 0);
            v26 = *(void (__fastcall **)(_QWORD))(v4 + 152);
            if ( *((_DWORD *)v26 - 1) != 246723534 )
              __break(0x8228u);
            v26(v21);
            if ( v22 )
            {
              *(_QWORD *)(*((_QWORD *)v13 + 27) + (unsigned int)v13[53] + 8LL) = v22;
              v27 = v13[29];
              v13[28] += v22[28];
              v13[29] = v27 + v22[28];
            }
            v21 = v23;
            v22 = v13;
          }
          while ( v23 != v18 );
        }
      }
      else
      {
        return nullptr;
      }
    }
    else
    {
      v13 = nullptr;
      __break(0x800u);
    }
  }
  return v13;
}
