bool __fastcall qdf_list_has_node(_QWORD *a1, _QWORD *a2)
{
  _QWORD *v2; // x8

  v2 = a1;
  do
    v2 = (_QWORD *)*v2;
  while ( v2 != a2 && v2 != a1 );
  return v2 != a1;
}
