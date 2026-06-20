__int64 __fastcall qdf_list_split(__int64 a1, __int64 a2, __int64 *a3)
{
  __int64 *v3; // x8
  __int64 v4; // x9
  int v5; // w8
  _QWORD *v6; // x9

  if ( *(_QWORD *)a2 != a2 )
  {
    v3 = *(__int64 **)a2;
    if ( *(_QWORD *)a2 != *(_QWORD *)(a2 + 8) || a3 == (__int64 *)a2 || v3 == a3 )
    {
      if ( a3 == (__int64 *)a2 )
      {
        *(_QWORD *)a1 = a1;
        *(_QWORD *)(a1 + 8) = a1;
      }
      else
      {
        v4 = *a3;
        *(_QWORD *)a1 = v3;
        v3[1] = a1;
        *(_QWORD *)(a1 + 8) = a3;
        *a3 = a1;
        *(_QWORD *)a2 = v4;
        *(_QWORD *)(v4 + 8) = a2;
      }
    }
  }
  v5 = -1;
  v6 = (_QWORD *)a1;
  do
  {
    v6 = (_QWORD *)*v6;
    ++v5;
  }
  while ( v6 != (_QWORD *)a1 );
  *(_DWORD *)(a1 + 16) = v5;
  *(_DWORD *)(a2 + 16) -= v5;
  return 0;
}
