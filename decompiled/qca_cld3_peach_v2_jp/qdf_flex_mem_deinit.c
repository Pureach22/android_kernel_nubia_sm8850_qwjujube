_QWORD *__fastcall qdf_flex_mem_deinit(_QWORD *result)
{
  _QWORD *v1; // x20
  __int64 v2; // x19
  _QWORD *v3; // x21

  v1 = (_QWORD *)*result;
  if ( (_QWORD *)*result != result )
  {
    v2 = (__int64)result;
    do
    {
      v3 = (_QWORD *)*v1;
      if ( !*((_DWORD *)v1 + 5) )
      {
        result = (_QWORD *)qdf_list_remove_node(v2, v1);
        if ( *((_BYTE *)v1 + 16) == 1 )
          result = (_QWORD *)kfree(v1);
      }
      v1 = v3;
    }
    while ( v3 != (_QWORD *)v2 );
  }
  return result;
}
