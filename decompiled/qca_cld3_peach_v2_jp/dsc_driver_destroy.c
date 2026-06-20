__int64 *__fastcall dsc_driver_destroy(__int64 *result)
{
  __int64 v1; // x19
  __int64 v2; // x1
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7

  if ( result )
  {
    v1 = *result;
    if ( *result )
    {
      *result = 0;
      qdf_list_empty((_QWORD *)(v1 + 16));
      while ( _dsc_trans_abort(v1 + 40) )
        ;
      _dsc_ops_deinit(v1 + 72, v2);
      _dsc_trans_deinit(v1 + 40, v3, v4, v5, v6, v7, v8, v9, v10);
      if ( *(_DWORD *)(v1 + 32) )
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: list length not equal to zero",
          v11,
          v12,
          v13,
          v14,
          v15,
          v16,
          v17,
          v18,
          "qdf_list_destroy");
      return (__int64 *)_qdf_mem_free(v1);
    }
  }
  return result;
}
