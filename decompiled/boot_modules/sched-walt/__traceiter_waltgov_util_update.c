__int64 __fastcall _traceiter_waltgov_util_update(
        __int64 a1,
        unsigned int a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        unsigned int a8,
        int a9,
        int a10,
        char a11)
{
  __int64 v11; // x26
  void (__fastcall *v19)(__int64, _QWORD, __int64, __int64, __int64, __int64, __int64, _QWORD, int, int, int); // x8
  __int64 v20; // x0
  __int64 v21; // t1
  int v23; // [xsp+10h] [xbp-10h]

  v11 = qword_6DE00;
  if ( qword_6DE00 )
  {
    do
    {
      v19 = *(void (__fastcall **)(__int64, _QWORD, __int64, __int64, __int64, __int64, __int64, _QWORD, int, int, int))v11;
      v20 = *(_QWORD *)(v11 + 8);
      if ( *(_DWORD *)(*(_QWORD *)v11 - 4LL) != -1318997153 )
        __break(0x8228u);
      LOBYTE(v23) = a11 & 1;
      v19(v20, a2, a3, a4, a5, a6, a7, a8, a9, a10, v23);
      v21 = *(_QWORD *)(v11 + 24);
      v11 += 24;
    }
    while ( v21 );
  }
  return 0;
}
