__int64 __fastcall _traceiter_fastrpc_perf_counters(
        __int64 a1,
        unsigned int a2,
        unsigned int a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        __int64 a9,
        __int64 a10,
        __int64 a11,
        __int64 a12,
        __int64 a13)
{
  __int64 v13; // x26
  void (__fastcall *v21)(__int64, _QWORD, _QWORD, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64); // x8
  __int64 v22; // x0
  __int64 v23; // t1

  v13 = qword_22A10;
  if ( qword_22A10 )
  {
    do
    {
      v21 = *(void (__fastcall **)(__int64, _QWORD, _QWORD, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64))v13;
      v22 = *(_QWORD *)(v13 + 8);
      if ( *(_DWORD *)(*(_QWORD *)v13 - 4LL) != 1521357619 )
        __break(0x8228u);
      v21(v22, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13);
      v23 = *(_QWORD *)(v13 + 24);
      v13 += 24;
    }
    while ( v23 );
  }
  return 0;
}
