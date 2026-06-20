bool __fastcall qdf_list_node_in_any_list(_QWORD *a1)
{
  _QWORD *v1; // x9
  _QWORD *v2; // x10

  if ( a1 && (v1 = (_QWORD *)*a1, (_QWORD *)*a1 != a1) && v1 && (v2 = (_QWORD *)a1[1]) != nullptr && (_QWORD *)*v2 == a1 )
    return v1[1] == (_QWORD)a1;
  else
    return 0;
}
