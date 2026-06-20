__int64 __fastcall handle_page_completion(__int64 *a1)
{
  __int64 v1; // x21
  char v3; // w23
  __int64 v4; // x19
  __int64 v5; // x22
  int v6; // w8
  unsigned __int64 v7; // x8
  __int64 v8; // x9
  __int64 v9; // x8
  _QWORD *v10; // x19
  _QWORD *v11; // x1
  __int64 v12; // x0
  _QWORD *v13; // x28
  __int64 v14; // x21
  _QWORD *v15; // x24
  _QWORD *v16; // x8
  _QWORD *v17; // t2
  __int64 v18; // x22
  __int64 v19; // x25
  char v20; // w27
  int v21; // w26
  unsigned int v22; // w23
  _QWORD *v23; // x2
  _QWORD *v24; // x1
  __int64 v25; // x0
  void (__fastcall *v26)(_QWORD); // x8
  __int64 v27; // x8
  __int64 v28; // x0
  __int64 v29; // x0
  __int64 *v30; // x1
  __int64 v31; // x2
  void (__fastcall *v32)(_QWORD); // x8
  __int64 v34; // x8
  __int64 v35; // x0
  __int64 v36; // x0
  __int64 v37; // x8
  __int64 v38; // x0
  __int64 v39; // x0
  _QWORD *v40; // x20
  void (__fastcall *v41)(_QWORD); // x8
  __int64 v42; // x21
  __int64 v43; // x26
  _QWORD *v44; // x25
  char v45; // w27
  __int64 v46; // [xsp+8h] [xbp-8h]

  v1 = a1[1];
  v46 = *a1;
  v3 = *(_BYTE *)(v1 + 32);
  v5 = *(_QWORD *)(v1 + 16);
  v4 = *(_QWORD *)(v1 + 24);
  raw_spin_lock_bh(*(_QWORD *)(v1 + 80) + 1684LL);
  --**(_DWORD **)(v1 + 80);
  raw_spin_unlock_bh(*(_QWORD *)(v1 + 80) + 1684LL);
  v6 = *((unsigned __int16 *)a1 + 10);
  if ( !*((_WORD *)a1 + 10) )
  {
    if ( (unsigned int)__ratelimit(&handle_page_completion__rs, "handle_page_completion") )
      printk(&unk_3CC84F, "handle_page_completion");
    v34 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v35 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v35 )
      {
        ipc_log_string(v35, "ipa %s:%d unexpected 0 byte_xfered\n", "handle_page_completion", 5494);
        v34 = ipa3_ctx;
      }
      v36 = *(_QWORD *)(v34 + 34160);
      if ( v36 )
        ipc_log_string(v36, "ipa %s:%d unexpected 0 byte_xfered\n", "handle_page_completion", 5494);
    }
    v6 = *(_DWORD *)(v1 + 40);
  }
  *(_DWORD *)(v1 + 44) = v6;
  v7 = *((unsigned __int8 *)a1 + 22);
  if ( v7 >= 0x11 )
  {
    printk(&unk_3EC407, "handle_page_completion");
    v27 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v28 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v28 )
      {
        ipc_log_string(v28, "ipa %s:%d notify->veid > GSI_VEID_MAX\n", "handle_page_completion", 5499);
        v27 = ipa3_ctx;
      }
      v29 = *(_QWORD *)(v27 + 34160);
      if ( v29 )
        ipc_log_string(v29, "ipa %s:%d notify->veid > GSI_VEID_MAX\n", "handle_page_completion", 5499);
    }
    if ( (v3 & 1) != 0 )
    {
      dma_unmap_page_attrs(*(_QWORD *)(ipa3_ctx + 34216), v4, *(unsigned int *)(v1 + 40), 2, 0);
      _free_pages(*(_QWORD *)(v1 + 16), *(unsigned int *)(v1 + 36));
    }
    else
    {
      *(_DWORD *)(v5 + 52) = 1;
      raw_spin_lock_bh(*(_QWORD *)(*(_QWORD *)(v1 + 80) + 1944LL) + 1684LL);
      v30 = *(__int64 **)(*(_QWORD *)(v1 + 80) + 1784LL);
      v31 = *v30;
      if ( *(__int64 **)(*v30 + 8) != v30 || (__int64 *)v1 == v30 || v1 == v31 )
      {
        _list_add_valid_or_report(v1, v30);
      }
      else
      {
        *(_QWORD *)(v31 + 8) = v1;
        *(_QWORD *)v1 = v31;
        *(_QWORD *)(v1 + 8) = v30;
        *v30 = v1;
      }
      raw_spin_unlock_bh(*(_QWORD *)(*(_QWORD *)(v1 + 80) + 1944LL) + 1684LL);
    }
    v32 = *(void (__fastcall **)(_QWORD))(*(_QWORD *)(v1 + 80) + 152LL);
    if ( *((_DWORD *)v32 - 1) != 246723534 )
      __break(0x8228u);
    v32(v1);
    goto LABEL_45;
  }
  v8 = *(_QWORD *)(v1 + 80);
  *(_QWORD *)v1 = v1;
  *(_QWORD *)(v1 + 8) = v1;
  v9 = v8 + 16 * v7;
  v10 = (_QWORD *)(v9 + 392);
  v11 = *(_QWORD **)(v9 + 400);
  if ( v1 == v9 + 392 || (_QWORD *)v1 == v11 || (_QWORD *)*v11 != v10 )
  {
    _list_add_valid_or_report(v1, v11);
  }
  else
  {
    *(_QWORD *)(v9 + 400) = v1;
    *(_QWORD *)v1 = v10;
    *(_QWORD *)(v1 + 8) = v11;
    *v11 = v1;
  }
  if ( *((_DWORD *)a1 + 4) != 2 && *(_DWORD *)(*(_QWORD *)(v46 + 1624) + 4LL) != 33 )
    return 0;
  v12 = _alloc_skb(0, 2080, 0, 0xFFFFFFFFLL);
  if ( !v12 )
  {
    printk(&unk_3C0C99, "handle_page_completion");
    v37 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v38 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v38 )
      {
        ipc_log_string(v38, "ipa %s:%d skb alloc failure, free all pending pages\n", "handle_page_completion", 5527);
        v37 = ipa3_ctx;
      }
      v39 = *(_QWORD *)(v37 + 34160);
      if ( v39 )
        ipc_log_string(v39, "ipa %s:%d skb alloc failure, free all pending pages\n", "handle_page_completion", 5527);
    }
    v40 = (_QWORD *)*v10;
    if ( (_QWORD *)*v10 != v10 )
    {
      do
      {
        v43 = v40[2];
        v42 = v40[3];
        v44 = (_QWORD *)*v40;
        v45 = *((_BYTE *)v40 + 32);
        _list_del_entry(v40);
        *v40 = v40;
        v40[1] = v40;
        if ( (v45 & 1) != 0 )
        {
          dma_unmap_page_attrs(*(_QWORD *)(ipa3_ctx + 34216), v42, *((unsigned int *)v40 + 10), 2, 0);
          _free_pages(v40[2], *((unsigned int *)v40 + 9));
        }
        else
        {
          *(_DWORD *)(v43 + 52) = 1;
          raw_spin_lock_bh(*(_QWORD *)(v40[10] + 1944LL) + 1684LL);
          _list_add(v40, *(_QWORD **)(v40[10] + 1784LL), **(_QWORD **)(v40[10] + 1784LL));
          raw_spin_unlock_bh(*(_QWORD *)(v40[10] + 1944LL) + 1684LL);
        }
        v41 = *(void (__fastcall **)(_QWORD))(v40[10] + 152LL);
        if ( *((_DWORD *)v41 - 1) != 246723534 )
          __break(0x8228u);
        v41(v40);
        v40 = v44;
      }
      while ( v44 != v10 );
    }
LABEL_45:
    v14 = 0;
    ++*(_DWORD *)(ipa3_ctx + 32892);
    return v14;
  }
  v13 = (_QWORD *)*v10;
  v14 = v12;
  if ( (_QWORD *)*v10 != v10 )
  {
    _ReadStatusReg(SP_EL0);
    do
    {
      v15 = v13;
      v17 = v13;
      v13 = (_QWORD *)*v13;
      v16 = (_QWORD *)v17[1];
      v18 = v15[2];
      v19 = v15[3];
      v20 = *((_BYTE *)v15 + 32);
      v21 = *((_DWORD *)v15 + 9);
      v22 = *((_DWORD *)v15 + 11);
      if ( (_QWORD *)*v16 == v15 && (_QWORD *)v13[1] == v15 )
      {
        v13[1] = v16;
        *v16 = v13;
      }
      else
      {
        _list_del_entry_valid_or_report(v15);
      }
      *v15 = v15;
      v15[1] = v15;
      if ( (v20 & 1) != 0 )
      {
        dma_unmap_page_attrs(*(_QWORD *)(ipa3_ctx + 34216), v19, *((unsigned int *)v15 + 10), 2, 0);
      }
      else
      {
        raw_spin_lock_bh(*(_QWORD *)(v15[10] + 1944LL) + 1684LL);
        v23 = *(_QWORD **)(v15[10] + 1784LL);
        v24 = (_QWORD *)v23[1];
        if ( v15 == v23 || v15 == v24 || (_QWORD *)*v24 != v23 )
        {
          _list_add_valid_or_report(v15, v24);
        }
        else
        {
          v23[1] = v15;
          *v15 = v23;
          v15[1] = v24;
          *v24 = v15;
        }
        raw_spin_unlock_bh(*(_QWORD *)(v15[10] + 1944LL) + 1684LL);
        v25 = *(_QWORD *)(ipa3_ctx + 34216);
        if ( (*(_BYTE *)(v25 + 844) & 0x40) == 0 )
          _dma_sync_single_for_cpu(v25);
      }
      v26 = *(void (__fastcall **)(_QWORD))(v15[10] + 152LL);
      if ( *((_DWORD *)v26 - 1) != 246723534 )
        __break(0x8228u);
      v26(v15);
      skb_add_rx_frag_netmem(
        v14,
        *(unsigned __int8 *)(*(_QWORD *)(v14 + 216) + *(unsigned int *)(v14 + 212) + 2LL),
        v18,
        0,
        v22,
        4096LL << v21);
    }
    while ( v13 != v10 );
  }
  return v14;
}
