__int64 __fastcall cam_node_put_ctxt_to_free_list(__int64 a1)
{
  __int64 v1; // x20
  _QWORD *v3; // x0
  __int64 v4; // x2
  _QWORD *v5; // x1

  v1 = *(_QWORD *)(a1 + 4);
  mutex_lock(v1 + 32);
  v3 = (_QWORD *)(a1 - 364);
  v4 = v1 + 80;
  v5 = *(_QWORD **)(v1 + 88);
  if ( a1 - 364 == v1 + 80 || v5 == v3 || *v5 != v4 )
  {
    _list_add_valid_or_report(v3);
  }
  else
  {
    *(_QWORD *)(v1 + 88) = v3;
    *v3 = v4;
    *(_QWORD *)(a1 - 356) = v5;
    *v5 = v3;
  }
  return mutex_unlock(v1 + 32);
}
