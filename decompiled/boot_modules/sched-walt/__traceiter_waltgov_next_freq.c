__int64 __fastcall _traceiter_waltgov_next_freq(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        unsigned int a5,
        unsigned int a6,
        unsigned int a7,
        char a8,
        char a9,
        int a10,
        int a11,
        int a12,
        int a13)
{
  __int64 v13; // x26
  void (__fastcall *v21)(__int64, __int64, __int64, __int64, _QWORD, _QWORD, _QWORD, _QWORD, int, int, int, int, int); // x8
  __int64 v22; // x0
  __int64 v23; // t1
  int v25; // [xsp+0h] [xbp-40h]

  v13 = qword_6DE50;
  if ( qword_6DE50 )
  {
    do
    {
      v21 = *(void (__fastcall **)(__int64, __int64, __int64, __int64, _QWORD, _QWORD, _QWORD, _QWORD, int, int, int, int, int))v13;
      v22 = *(_QWORD *)(v13 + 8);
      if ( *(_DWORD *)(*(_QWORD *)v13 - 4LL) != 1234115830 )
        __break(0x8228u);
      LOBYTE(v25) = a9 & 1;
      v21(v22, a2, a3, a4, a5, a6, a7, a8 & 1, v25, a10, a11, a12, a13);
      v23 = *(_QWORD *)(v13 + 24);
      v13 += 24;
    }
    while ( v23 );
  }
  return 0;
}
