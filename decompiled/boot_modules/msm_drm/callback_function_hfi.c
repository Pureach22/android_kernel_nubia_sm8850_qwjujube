__int64 __fastcall callback_function_hfi(__int64 a1, __int64 a2)
{
  int v3; // w9
  unsigned int v9; // w12
  unsigned int v10; // w19

  if ( !a2 )
    return 4294967274LL;
  _X10 = &work_queue_pos_wr;
  v3 = work_queue_pos_wr;
  do
  {
    if ( v3 == 4 )
      break;
    __asm { PRFM            #0x11, [X10] }
    while ( 1 )
    {
      v9 = __ldxr((unsigned int *)&work_queue_pos_wr);
      if ( v9 != v3 )
        break;
      if ( !__stlxr(v3 + 1, (unsigned int *)&work_queue_pos_wr) )
      {
        __dmb(0xBu);
        break;
      }
    }
    _ZF = v9 == v3;
    v3 = v9;
  }
  while ( !_ZF );
  v10 = work_queue_pos_wr;
  if ( (unsigned int)work_queue_pos_wr >= 4 )
  {
    v10 = 0;
    work_queue_pos_wr = 0;
  }
  if ( (kthread_queue_work(a2 + 264, a2 + 56LL * v10 + 40) & 1) == 0 )
    printk(&unk_2569DB, "callback_function_hfi");
  return 0;
}
