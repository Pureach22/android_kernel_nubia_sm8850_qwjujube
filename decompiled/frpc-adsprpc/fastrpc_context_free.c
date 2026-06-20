__int64 __fastcall fastrpc_context_free(int *a1)
{
  __int64 v2; // x19
  __int64 v3; // x21
  __int64 v4; // x0
  int v11; // w9
  __int64 v12; // x0
  __int64 v13; // x22

  v2 = *((_QWORD *)a1 + 17);
  mutex_lock(*((_QWORD *)a1 + 10) + 328LL);
  if ( *(a1 - 21) >= 1 )
  {
    v3 = 0;
    do
    {
      v4 = *(_QWORD *)(*((_QWORD *)a1 + 13) + 8 * v3);
      if ( v4 )
      {
        _X8 = (unsigned int *)(v4 + 112);
        __asm { PRFM            #0x11, [X8] }
        do
          v11 = __ldxr(_X8);
        while ( __stlxr(v11 - 1, _X8) );
        if ( v11 == 1 )
        {
          __dmb(9u);
          _fastrpc_free_map(v4);
        }
        else if ( v11 <= 0 )
        {
          refcount_warn_saturate(v4 + 112, 3);
        }
      }
      ++v3;
    }
    while ( v3 < *(a1 - 21) );
  }
  mutex_unlock(*((_QWORD *)a1 + 10) + 328LL);
  v12 = *((_QWORD *)a1 + 14);
  if ( v12 )
    fastrpc_buf_free(v12, 1);
  if ( *(_DWORD *)(*((_QWORD *)a1 + 10) + 280LL) )
    kfree(*((_QWORD *)a1 + 18));
  v13 = raw_spin_lock_irqsave(v2 + 51600);
  idr_remove(v2 + 51608, (unsigned __int16)*((_QWORD *)a1 - 3) >> 6);
  raw_spin_unlock_irqrestore(v2 + 51600, v13);
  kfree(*((_QWORD *)a1 + 13));
  kfree(*((_QWORD *)a1 + 16));
  kfree(*((_QWORD *)a1 + 15));
  kfree(*((_QWORD *)a1 + 12));
  kfree(a1 - 26);
  return fastrpc_channel_ctx_put(v2);
}
