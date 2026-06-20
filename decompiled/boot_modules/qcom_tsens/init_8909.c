__int64 __fastcall init_8909(__int64 a1, __int64 a2)
{
  unsigned int v2; // w8
  __int64 v3; // x12

  if ( *(_DWORD *)(a1 + 8) )
  {
    v2 = 0;
    do
    {
      v3 = a1 + 2600 + 88LL * (int)v2++;
      *(_DWORD *)(v3 + 72) = 3000;
    }
    while ( v2 < *(_DWORD *)(a1 + 8) );
  }
  *(_QWORD *)(a1 + 2680) = 0;
  *(_QWORD *)(a1 + 2856) = 0;
  *(_QWORD *)(a1 + 2768) = 0xFFFFFFFAFFFFFFF6LL;
  *(_QWORD *)(a1 + 2944) = 0xFFFFFFF7FFFFFFF7LL;
  *(_QWORD *)(a1 + 3032) = 0xFFFFFFF6FFFFFFF8LL;
  return ((__int64 (__fastcall *)(__int64, __int64))init_common)(a1, a2);
}
