__int64 __fastcall fastrpc_dma_buf_detatch(__int64 a1, __int64 a2)
{
  __int64 v2; // x20
  __int64 v3; // x19
  _QWORD *v4; // x8
  __int64 *v5; // x0
  __int64 v6; // x9

  v2 = *(_QWORD *)(a1 + 112);
  v3 = *(_QWORD *)(a2 + 64);
  mutex_lock(v2 + 80);
  v4 = *(_QWORD **)(v3 + 32);
  v5 = (__int64 *)(v3 + 24);
  if ( *v4 == v3 + 24 && (v6 = *v5, *(__int64 **)(*v5 + 8) == v5) )
  {
    *(_QWORD *)(v6 + 8) = v4;
    *v4 = v6;
  }
  else
  {
    _list_del_entry_valid_or_report(v5);
  }
  *(_QWORD *)(v3 + 24) = 0xDEAD000000000100LL;
  *(_QWORD *)(v3 + 32) = 0xDEAD000000000122LL;
  mutex_unlock(v2 + 80);
  sg_free_table(v3 + 8);
  return kfree(v3);
}
