__int64 __fastcall gh_msgq_populate_cap_info(int a1, __int64 a2, int a3, unsigned int a4)
{
  _UNKNOWN **v8; // x8
  unsigned __int64 v10; // x19
  unsigned int v11; // w0
  unsigned __int64 v12; // x22
  __int64 v13; // x21
  unsigned int v14; // w20
  _QWORD *v15; // x8
  unsigned __int64 v16; // x0
  __int64 v17; // x9

  if ( a1 <= 256 )
  {
    printk(&unk_74D7, "gh_msgq_populate_cap_info");
    return 4294967274LL;
  }
  if ( (a4 & 0x80000000) != 0 )
  {
    printk(&unk_73CB, "gh_msgq_populate_cap_info");
    return 4294967290LL;
  }
  raw_spin_lock(&gh_msgq_cap_list_lock);
  v8 = &gh_msgq_cap_list;
  do
  {
    v8 = (_UNKNOWN **)*v8;
    if ( v8 == &gh_msgq_cap_list )
      goto LABEL_12;
  }
  while ( *((_DWORD *)v8 - 2) != a1 );
  if ( a3 == 1 )
  {
    if ( *(v8 - 13) != (_UNKNOWN *)-1LL )
    {
LABEL_9:
      raw_spin_unlock(&gh_msgq_cap_list_lock);
      return 4294967274LL;
    }
  }
  else if ( a3 || *(v8 - 14) != (_UNKNOWN *)-1LL )
  {
    goto LABEL_9;
  }
  v10 = (unsigned __int64)(v8 - 16);
  if ( v8 == &qword_80 )
  {
LABEL_12:
    v10 = gh_msgq_alloc_entry(a1);
    if ( v10 >= 0xFFFFFFFFFFFFF001LL )
    {
      raw_spin_unlock(&gh_msgq_cap_list_lock);
      return (unsigned int)v10;
    }
  }
  raw_spin_unlock(&gh_msgq_cap_list_lock);
  if ( a3 == 1 )
  {
    v11 = request_threaded_irq(a4, gh_msgq_rx_isr, 0, 0x200000, *(_QWORD *)(v10 + 48), v10);
    if ( (v11 & 0x80000000) == 0 )
    {
      v12 = v10 + 8;
      raw_spin_lock(v10 + 8);
      *(_QWORD *)(v10 + 24) = a2;
      v13 = 96;
      *(_DWORD *)(v10 + 36) = a4;
      goto LABEL_20;
    }
    goto LABEL_21;
  }
  if ( !a3 )
  {
    v11 = request_threaded_irq(a4, gh_msgq_tx_isr, 0, 0x200000, *(_QWORD *)(v10 + 40), v10);
    if ( (v11 & 0x80000000) == 0 )
    {
      v12 = v10 + 8;
      raw_spin_lock(v10 + 8);
      *(_QWORD *)(v10 + 16) = a2;
      v13 = 72;
      *(_DWORD *)(v10 + 32) = a4;
LABEL_20:
      raw_spin_unlock(v12);
      _wake_up(v10 + v13, 1, 1, 0);
      irq_set_irq_wake(a4, 1);
      return 0;
    }
LABEL_21:
    v14 = v11;
    goto LABEL_22;
  }
  printk(&unk_73AB, "gh_msgq_populate_cap_info");
  v14 = -22;
LABEL_22:
  raw_spin_lock(&gh_msgq_cap_list_lock);
  v15 = *(_QWORD **)(v10 + 136);
  v16 = v10 + 128;
  if ( *v15 == v10 + 128 && (v17 = *(_QWORD *)v16, *(_QWORD *)(*(_QWORD *)v16 + 8LL) == v16) )
  {
    *(_QWORD *)(v17 + 8) = v15;
    *v15 = v17;
  }
  else
  {
    _list_del_entry_valid_or_report();
  }
  *(_QWORD *)(v10 + 128) = 0xDEAD000000000100LL;
  *(_QWORD *)(v10 + 136) = 0xDEAD000000000122LL;
  raw_spin_unlock(&gh_msgq_cap_list_lock);
  kfree(*(_QWORD *)(v10 + 40));
  kfree(*(_QWORD *)(v10 + 48));
  kfree(v10);
  return v14;
}
