__int64 __fastcall nbia_update_cpus_allowed(__int64 a1, __int64 a2, _DWORD *a3, _QWORD *a4, _DWORD *a5)
{
  _BYTE *v5; // x19
  int v7; // w9
  _QWORD *v8; // x21
  __int64 v9; // x22
  __int64 v10; // x20

  if ( (_UNKNOWN *)a2 == &init_task )
    v5 = &vendor_data_pad;
  else
    v5 = (_BYTE *)(a2 + 5184);
  if ( v5[456] != 1 || v5[457] != 1 || (*((_DWORD *)v5 + 116) & ~*a3) != 0 )
    return 1;
  *a5 = 0;
  if ( sched_nbia_debug )
  {
    _ReadStatusReg(SP_EL0);
    v8 = a4;
    v9 = a2;
    printk(&unk_669C2);
    printk(&unk_62D5A);
    a4 = v8;
    a2 = v9;
  }
  v7 = *((_DWORD *)v5 + 116);
  *((_QWORD *)v5 + 59) = *a4;
  if ( **(_DWORD **)(a2 + 1376) != v7 )
  {
    if ( sched_nbia_debug )
    {
      v10 = a2;
      printk(&unk_61C81);
      a2 = v10;
    }
    q_affinity_work(*(unsigned int *)(a2 + 1800), (_DWORD *)v5 + 116);
  }
  return 0;
}
