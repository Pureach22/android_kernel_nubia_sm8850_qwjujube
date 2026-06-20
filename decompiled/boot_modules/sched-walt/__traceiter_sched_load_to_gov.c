__int64 __fastcall _traceiter_sched_load_to_gov(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        unsigned int a4,
        unsigned int a5,
        __int64 a6,
        __int64 a7,
        unsigned int a8,
        char a9,
        int a10,
        __int64 a11,
        int a12)
{
  __int64 v12; // x26
  void (__fastcall *v20)(__int64, __int64, __int64, _QWORD, _QWORD, __int64, __int64, _QWORD, int, int, __int64, int); // x8
  __int64 v21; // x0
  __int64 v22; // t1
  int v24; // [xsp+0h] [xbp-30h]

  v12 = qword_6DB30;
  if ( qword_6DB30 )
  {
    do
    {
      v20 = *(void (__fastcall **)(__int64, __int64, __int64, _QWORD, _QWORD, __int64, __int64, _QWORD, int, int, __int64, int))v12;
      v21 = *(_QWORD *)(v12 + 8);
      if ( *(_DWORD *)(*(_QWORD *)v12 - 4LL) != -1201396304 )
        __break(0x8228u);
      LOBYTE(v24) = a9 & 1;
      v20(v21, a2, a3, a4, a5, a6, a7, a8, v24, a10, a11, a12);
      v22 = *(_QWORD *)(v12 + 24);
      v12 += 24;
    }
    while ( v22 );
  }
  return 0;
}
