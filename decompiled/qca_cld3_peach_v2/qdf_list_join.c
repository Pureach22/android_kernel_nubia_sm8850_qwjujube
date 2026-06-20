__int64 __fastcall qdf_list_join(__int64 a1, __int64 *a2)
{
  __int64 *v2; // x8
  __int64 **v3; // x9
  _QWORD *v4; // x10

  v2 = (__int64 *)*a2;
  if ( (__int64 *)*a2 != a2 )
  {
    v3 = *(__int64 ***)(a1 + 8);
    v4 = (_QWORD *)a2[1];
    v2[1] = (__int64)v3;
    *v3 = v2;
    *v4 = a1;
    *(_QWORD *)(a1 + 8) = v4;
    *a2 = (__int64)a2;
    a2[1] = (__int64)a2;
  }
  *(_DWORD *)(a1 + 16) += *((_DWORD *)a2 + 4);
  *((_DWORD *)a2 + 4) = 0;
  return 0;
}
