__int64 __fastcall dynamic_page_pool_do_shrink(__int64 a1, char a2, int a3)
{
  int v4; // w8
  int v5; // w26
  int v7; // w20
  __int64 v8; // x0
  int v9; // w8
  __int64 v10; // x24
  _QWORD *v11; // x23
  _QWORD *v12; // x8
  __int64 v13; // x9
  __int64 v14; // x2
  unsigned int v21; // w9
  unsigned int v24; // w9
  int v25; // w8
  _DWORD *v26; // x8
  __int64 v27; // x2
  __int64 v28; // x1
  _QWORD *v29; // x9
  _QWORD *v30; // x8
  _QWORD *v31; // x22
  _QWORD v33[3]; // [xsp+8h] [xbp-18h] BYREF

  v33[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_DWORD *)(_ReadStatusReg(SP_EL0) + 68);
  v33[0] = v33;
  v33[1] = v33;
  v5 = v4 & 0x20000 | a2 & 2;
  if ( !a3 )
  {
    v25 = *(_DWORD *)(a1 + 4);
    if ( v5 )
      v25 += *(_DWORD *)a1;
    v7 = v25 << *(_DWORD *)(a1 + 72);
    goto LABEL_39;
  }
  v7 = 0;
  if ( a3 < 1 )
    goto LABEL_32;
  while ( 1 )
  {
    v8 = raw_spin_lock_irqsave(a1 + 64);
    v9 = *(_DWORD *)(a1 + 4);
    v10 = v8;
    if ( !v9 )
      break;
    v11 = *(_QWORD **)(a1 + 32);
    *(_DWORD *)(a1 + 4) = v9 - 1;
    _X8 = (unsigned int *)(a1 + 8);
    __asm { PRFM            #0x11, [X8] }
    do
      v21 = __ldxr(_X8);
    while ( __stxr(v21 - 1, _X8) );
LABEL_8:
    v12 = (_QWORD *)v11[1];
    if ( (_QWORD *)*v12 == v11 && (v13 = *v11, *(_QWORD **)(*v11 + 8LL) == v11) )
    {
      *(_QWORD *)(v13 + 8) = v12;
      *v12 = v13;
    }
    else
    {
      _list_del_entry_valid_or_report(v11);
    }
    *v11 = 0xDEAD000000000100LL;
    v11[1] = 0xDEAD000000000122LL;
    mod_node_page_state(&contig_page_data, 34, -1LL << *(_DWORD *)(a1 + 72));
    raw_spin_unlock_irqrestore(a1 + 64, v10);
    v14 = v33[0];
    if ( *(_QWORD **)(v33[0] + 8LL) != v33 || v11 == v33 || (_QWORD *)v33[0] == v11 )
    {
      _list_add_valid_or_report(v11);
    }
    else
    {
      *(_QWORD *)(v33[0] + 8LL) = v11;
      *v11 = v14;
      v11[1] = v33;
      v33[0] = v11;
    }
    v7 += 1 << *(_DWORD *)(a1 + 72);
    if ( v7 >= a3 )
      goto LABEL_27;
  }
  if ( v5 && *(_DWORD *)a1 )
  {
    v11 = *(_QWORD **)(a1 + 16);
    --*(_DWORD *)a1;
    _X8 = (unsigned int *)(a1 + 8);
    __asm { PRFM            #0x11, [X8] }
    do
      v24 = __ldxr(_X8);
    while ( __stxr(v24 - 1, _X8) );
    goto LABEL_8;
  }
  raw_spin_unlock_irqrestore(a1 + 64, v8);
LABEL_27:
  if ( !v7 )
    goto LABEL_32;
  v26 = *(_DWORD **)(a1 + 104);
  if ( !v26 )
    goto LABEL_32;
  v27 = (unsigned int)(v7 >> *(_DWORD *)(a1 + 72));
  if ( *(v26 - 1) != 1836222703 )
    __break(0x8228u);
  if ( ((unsigned int (__fastcall *)(__int64, _QWORD *, __int64))v26)(a1, v33, v27) )
  {
    printk(&unk_D865, v28);
    v7 = 0;
  }
  else
  {
LABEL_32:
    v29 = (_QWORD *)v33[0];
    if ( (_QWORD *)v33[0] != v33 )
    {
      do
      {
        v31 = (_QWORD *)*v29;
        v30 = (_QWORD *)v29[1];
        if ( (_QWORD *)*v30 == v29 && (_QWORD *)v31[1] == v29 )
        {
          v31[1] = v30;
          *v30 = v31;
        }
        else
        {
          _list_del_entry_valid_or_report(v29);
        }
        *v29 = 0xDEAD000000000100LL;
        v29[1] = 0xDEAD000000000122LL;
        _free_pages(v29 - 1, *(unsigned int *)(a1 + 72));
        v29 = v31;
      }
      while ( v31 != v33 );
    }
  }
LABEL_39:
  _ReadStatusReg(SP_EL0);
  return (unsigned int)v7;
}
