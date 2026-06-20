_QWORD **__fastcall dsc_vdev_destroy(_QWORD **result)
{
  _QWORD *v1; // x19
  __int64 v2; // x1
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7

  if ( result )
  {
    v1 = *result;
    if ( *result )
    {
      *result = nullptr;
      while ( _dsc_trans_abort((__int64)(v1 + 3)) )
        ;
      _dsc_lock(*(_QWORD *)(v1[2] + 16LL));
      qdf_list_remove_node(v1[2] + 24LL, v1);
      _dsc_unlock(*(_QWORD *)(v1[2] + 16LL));
      _dsc_ops_deinit((__int64)(v1 + 7), v2);
      _dsc_trans_deinit((__int64)(v1 + 3), v3, v4, v5, v6, v7, v8, v9, v10);
      v1[2] = 0;
      return (_QWORD **)kfree(v1);
    }
  }
  return result;
}
