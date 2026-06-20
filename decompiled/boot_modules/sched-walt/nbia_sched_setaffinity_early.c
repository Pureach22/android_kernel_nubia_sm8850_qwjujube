__int64 __fastcall nbia_sched_setaffinity_early(__int64 a1, __int64 a2, _QWORD *a3, _BYTE *a4)
{
  _DWORD *v4; // x19
  int v5; // w9
  __int64 v6; // x21
  _QWORD *v7; // x22
  __int64 result; // x0
  __int64 v9; // x20

  if ( (_UNKNOWN *)a2 == &init_task )
    v4 = &vendor_data_pad;
  else
    v4 = (_DWORD *)(a2 + 5184);
  if ( *((_BYTE *)v4 + 456) == 1 && *((_BYTE *)v4 + 457) == 1 )
  {
    *a4 = 1;
    if ( sched_nbia_debug )
    {
      _ReadStatusReg(SP_EL0);
      v6 = a2;
      v7 = a3;
      printk(&unk_6726B);
      result = printk(&unk_663D8);
      a3 = v7;
      a2 = v6;
    }
    v5 = v4[116];
    *((_QWORD *)v4 + 59) = *a3;
    if ( **(_DWORD **)(a2 + 1376) != v5 )
    {
      if ( sched_nbia_debug )
      {
        v9 = a2;
        printk(&unk_60E9F);
        a2 = v9;
      }
      return q_affinity_work(*(unsigned int *)(a2 + 1800), v4 + 116);
    }
  }
  return result;
}
