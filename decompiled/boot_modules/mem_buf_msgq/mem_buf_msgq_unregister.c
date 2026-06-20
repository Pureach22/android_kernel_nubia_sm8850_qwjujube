__int64 __fastcall mem_buf_msgq_unregister(_QWORD *a1)
{
  _QWORD *v2; // x8
  _QWORD *v3; // x0
  __int64 v4; // x9

  kthread_stop(a1[12]);
  mutex_lock(&mem_buf_msgq_list_lock);
  v2 = (_QWORD *)a1[14];
  v3 = a1 + 13;
  if ( (_QWORD *)*v2 == a1 + 13 && (v4 = *v3, *(_QWORD **)(*v3 + 8LL) == v3) )
  {
    *(_QWORD *)(v4 + 8) = v2;
    *v2 = v4;
  }
  else
  {
    _list_del_entry_valid_or_report();
  }
  a1[13] = 0xDEAD000000000100LL;
  a1[14] = 0xDEAD000000000122LL;
  mutex_unlock(&mem_buf_msgq_list_lock);
  gh_msgq_unregister(a1[11]);
  idr_destroy(a1 + 8);
  return kfree(a1);
}
