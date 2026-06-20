__int64 __fastcall _traceiter_gh_rm_mem_accept(
        __int64 a1,
        unsigned int a2,
        unsigned int a3,
        unsigned int a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        __int16 a9,
        char a10)
{
  __int64 v10; // x26
  void (__fastcall *v18)(__int64, _QWORD, _QWORD, _QWORD, __int64, __int64, __int64, __int64, int, int); // x8
  __int64 v19; // x0
  __int64 v20; // t1
  int v22; // [xsp+0h] [xbp-10h]
  int v23; // [xsp+8h] [xbp-8h]

  v10 = qword_14320;
  if ( qword_14320 )
  {
    do
    {
      v18 = *(void (__fastcall **)(__int64, _QWORD, _QWORD, _QWORD, __int64, __int64, __int64, __int64, int, int))v10;
      v19 = *(_QWORD *)(v10 + 8);
      LOBYTE(v23) = a10;
      LOWORD(v22) = a9;
      if ( *(_DWORD *)(*(_QWORD *)v10 - 4LL) != 1140098178 )
        __break(0x8228u);
      v18(v19, a2, a3, a4, a5, a6, a7, a8, v22, v23);
      v20 = *(_QWORD *)(v10 + 24);
      v10 += 24;
    }
    while ( v20 );
  }
  return 0;
}
