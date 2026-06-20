__int64 __fastcall qdf_list_peek_next(_QWORD *a1, _QWORD *a2, _QWORD *a3)
{
  __int64 result; // x0

  result = 5;
  if ( a1 && a2 && a3 )
  {
    if ( (_QWORD *)*a1 == a1 || (_QWORD *)*a2 == a1 )
    {
      return 13;
    }
    else
    {
      result = 0;
      *a3 = *a2;
    }
  }
  return result;
}
