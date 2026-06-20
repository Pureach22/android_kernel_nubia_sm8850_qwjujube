_QWORD *__fastcall cam_sync_util_cleanup_children_list(_QWORD *result, int a2, int a3)
{
  _QWORD *v3; // x9
  _QWORD *v4; // x20
  _QWORD *v8; // x23
  int v9; // w24
  _QWORD *v10; // x8
  _QWORD *v11; // x10

  v4 = result + 11;
  v3 = (_QWORD *)result[11];
  if ( v3 != result + 11 )
  {
    do
    {
      v8 = (_QWORD *)*v3;
      result = v3 - 1;
      v9 = *((_DWORD *)v3 - 2);
      if ( a2 || v9 == a3 )
      {
        v10 = (_QWORD *)v3[1];
        if ( (_QWORD *)*v10 == v3 && (_QWORD *)v8[1] == v3 )
        {
          v8[1] = v10;
          *v10 = v8;
        }
        else
        {
          _list_del_entry_valid_or_report(v3);
          result = v11;
        }
        *v3 = v3;
        v3[1] = v3;
        result = mem_trace_en == 1 ? cam_mem_trace_free(result, 0) : (_QWORD *)kvfree(result);
        if ( v9 == a3 && a2 == 0 )
          break;
      }
      v3 = v8;
    }
    while ( v8 != v4 );
  }
  return result;
}
