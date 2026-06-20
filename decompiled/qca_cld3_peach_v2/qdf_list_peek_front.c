__int64 __fastcall qdf_list_peek_front(_QWORD *a1, _QWORD *a2)
{
  _QWORD *v2; // x8

  v2 = (_QWORD *)*a1;
  if ( (_QWORD *)*a1 == a1 )
    return 13;
  *a2 = v2;
  return 0;
}
