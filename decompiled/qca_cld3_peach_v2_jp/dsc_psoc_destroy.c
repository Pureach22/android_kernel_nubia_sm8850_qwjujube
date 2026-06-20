_QWORD *__fastcall dsc_psoc_destroy(_QWORD *result)
{
  __int64 v1; // x20
  _QWORD *v2; // x19
  __int64 v3; // x1
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7

  if ( result )
  {
    v1 = *result;
    v2 = result;
    if ( *result )
    {
      qdf_list_empty((_QWORD *)(v1 + 24));
      while ( _dsc_trans_abort(v1 + 48) )
        ;
      _dsc_lock(*(_QWORD *)(v1 + 16));
      qdf_list_remove_node(*(_QWORD *)(v1 + 16) + 16LL, (_QWORD *)v1);
      _dsc_unlock(*(_QWORD *)(v1 + 16));
      _dsc_ops_deinit(v1 + 80, v3);
      _dsc_trans_deinit(v1 + 48, v4, v5, v6, v7, v8, v9, v10, v11);
      if ( *(_DWORD *)(v1 + 40) )
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: list length not equal to zero",
          v12,
          v13,
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          "qdf_list_destroy");
      *(_QWORD *)(v1 + 16) = 0;
      *v2 = 0;
      return (_QWORD *)kfree(v1);
    }
  }
  return result;
}
