_QWORD *__fastcall sta_info_get_by_idx(__int64 a1, int a2)
{
  __int64 v2; // x9
  _QWORD *result; // x0
  _QWORD *v5; // x9
  int v6; // w10

  v2 = *(_QWORD *)(a1 + 1616);
  result = *(_QWORD **)(v2 + 1616);
  v5 = (_QWORD *)(v2 + 1616);
  if ( result != v5 )
  {
    v6 = 0;
    do
    {
      if ( result[10] == a1 )
      {
        if ( v6 >= a2 )
          return result;
        ++v6;
      }
      result = (_QWORD *)*result;
    }
    while ( result != v5 );
  }
  return nullptr;
}
