__int64 __fastcall dynamic_page_pool_destroy(__int64 a1)
{
  _QWORD *v2; // x8
  __int64 *v3; // x0
  __int64 v4; // x9
  __int64 v5; // x21
  unsigned int v6; // w20
  int v7; // w8
  _QWORD *v8; // x23
  _QWORD *v9; // x8
  __int64 v10; // x9
  __int64 v11; // x2
  unsigned int v18; // w9
  unsigned int v21; // w9
  _DWORD *v22; // x8
  __int64 v23; // x1
  _QWORD *v24; // x9
  _QWORD *v25; // x8
  _QWORD *v26; // x21
  __int64 result; // x0
  _QWORD v28[3]; // [xsp+8h] [xbp-18h] BYREF

  v28[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v28[0] = v28;
  v28[1] = v28;
  mutex_lock(&pool_list_lock);
  v2 = *(_QWORD **)(a1 + 88);
  v3 = (__int64 *)(a1 + 80);
  if ( *v2 == a1 + 80 && (v4 = *v3, *(__int64 **)(*v3 + 8) == v3) )
  {
    *(_QWORD *)(v4 + 8) = v2;
    *v2 = v4;
  }
  else
  {
    _list_del_entry_valid_or_report(v3);
  }
  *(_QWORD *)(a1 + 80) = 0xDEAD000000000100LL;
  *(_QWORD *)(a1 + 88) = 0xDEAD000000000122LL;
  mutex_unlock(&pool_list_lock);
  v5 = raw_spin_lock_irqsave(a1 + 64);
  v6 = 0;
  while ( 1 )
  {
    v7 = *(_DWORD *)(a1 + 4);
    if ( v7 )
    {
      v8 = *(_QWORD **)(a1 + 32);
      *(_DWORD *)(a1 + 4) = v7 - 1;
      _X8 = (unsigned int *)(a1 + 8);
      __asm { PRFM            #0x11, [X8] }
      do
        v18 = __ldxr(_X8);
      while ( __stxr(v18 - 1, _X8) );
      goto LABEL_9;
    }
    if ( !*(_DWORD *)a1 )
      break;
    v8 = *(_QWORD **)(a1 + 16);
    --*(_DWORD *)a1;
    _X8 = (unsigned int *)(a1 + 8);
    __asm { PRFM            #0x11, [X8] }
    do
      v21 = __ldxr(_X8);
    while ( __stxr(v21 - 1, _X8) );
LABEL_9:
    v9 = (_QWORD *)v8[1];
    if ( (_QWORD *)*v9 == v8 && (v10 = *v8, *(_QWORD **)(*v8 + 8LL) == v8) )
    {
      *(_QWORD *)(v10 + 8) = v9;
      *v9 = v10;
    }
    else
    {
      _list_del_entry_valid_or_report(v8);
    }
    *v8 = 0xDEAD000000000100LL;
    v8[1] = 0xDEAD000000000122LL;
    mod_node_page_state(&contig_page_data, 34, -1LL << *(_DWORD *)(a1 + 72));
    v11 = v28[0];
    if ( *(_QWORD **)(v28[0] + 8LL) != v28 || v8 == v28 || (_QWORD *)v28[0] == v8 )
    {
      _list_add_valid_or_report(v8);
      ++v6;
    }
    else
    {
      *(_QWORD *)(v28[0] + 8LL) = v8;
      ++v6;
      *v8 = v11;
      v8[1] = v28;
      v28[0] = v8;
    }
  }
  raw_spin_unlock_irqrestore(a1 + 64, v5);
  if ( !v6 )
    goto LABEL_27;
  v22 = *(_DWORD **)(a1 + 104);
  if ( !v22 )
    goto LABEL_27;
  if ( *(v22 - 1) != 1836222703 )
    __break(0x8228u);
  if ( ((unsigned int (__fastcall *)(__int64, _QWORD *, _QWORD))v22)(a1, v28, v6) )
  {
    result = printk(&unk_DBA3, v23);
  }
  else
  {
LABEL_27:
    v24 = (_QWORD *)v28[0];
    if ( (_QWORD *)v28[0] != v28 )
    {
      do
      {
        v26 = (_QWORD *)*v24;
        v25 = (_QWORD *)v24[1];
        if ( (_QWORD *)*v25 == v24 && (_QWORD *)v26[1] == v24 )
        {
          v26[1] = v25;
          *v25 = v26;
        }
        else
        {
          _list_del_entry_valid_or_report(v24);
        }
        *v24 = 0xDEAD000000000100LL;
        v24[1] = 0xDEAD000000000122LL;
        _free_pages(v24 - 1, *(unsigned int *)(a1 + 72));
        v24 = v26;
      }
      while ( v26 != v28 );
    }
    result = kfree(a1);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
