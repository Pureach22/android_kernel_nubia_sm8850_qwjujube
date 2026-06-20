unsigned int *__fastcall sg_rq_end_io_usercontext(__int64 a1)
{
  _QWORD *v1; // x20
  unsigned int *v2; // x19
  unsigned int *result; // x0
  __int64 v4; // x20
  __int64 v5; // x0
  unsigned int **v6; // x8
  __int64 v7; // x9
  __int64 v8; // x10
  int v14; // w8

  v1 = (_QWORD *)(a1 - 264);
  v2 = *(unsigned int **)(a1 - 248);
  sg_finish_rem_req(a1 - 264);
  sg_remove_request((__int64)v2, v1);
  result = v2 + 1228;
  __asm { PRFM            #0x11, [X0] }
  do
    v14 = __ldxr(result);
  while ( __stlxr(v14 - 1, result) );
  if ( v14 == 1 )
  {
    __dmb(9u);
    v4 = *((_QWORD *)v2 + 2);
    v5 = raw_write_lock_irqsave(v4 + 104);
    v6 = *((unsigned int ***)v2 + 1);
    v7 = v5;
    if ( *v6 == v2 && (v8 = *(_QWORD *)v2, *(unsigned int **)(*(_QWORD *)v2 + 8LL) == v2) )
    {
      *(_QWORD *)(v8 + 8) = v6;
      *v6 = (unsigned int *)v8;
    }
    else
    {
      _list_del_entry_valid_or_report(v2);
    }
    *(_QWORD *)v2 = 0xDEAD000000000100LL;
    *((_QWORD *)v2 + 1) = 0xDEAD000000000122LL;
    raw_write_unlock_irqrestore(v4 + 104, v7);
    *((_QWORD *)v2 + 615) = 0xFFFFFFFE00000LL;
    *((_QWORD *)v2 + 616) = v2 + 1232;
    *((_QWORD *)v2 + 617) = v2 + 1232;
    *((_QWORD *)v2 + 618) = sg_remove_sfp_usercontext;
    return (unsigned int *)queue_work_on(32, system_wq, v2 + 1230);
  }
  else if ( v14 <= 0 )
  {
    return (unsigned int *)refcount_warn_saturate(result, 3);
  }
  return result;
}
