__int64 __fastcall _traceiter_sched_find_best_target(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        unsigned int a4,
        __int64 a5,
        unsigned int a6,
        unsigned int a7,
        unsigned int a8,
        int a9,
        int a10,
        int a11)
{
  __int64 v11; // x26
  void (__fastcall *v19)(__int64, __int64, __int64, _QWORD, __int64, _QWORD, _QWORD, _QWORD, int, int, int); // x8
  __int64 v20; // x0
  __int64 v21; // t1

  v11 = qword_6E1C0;
  if ( qword_6E1C0 )
  {
    do
    {
      v19 = *(void (__fastcall **)(__int64, __int64, __int64, _QWORD, __int64, _QWORD, _QWORD, _QWORD, int, int, int))v11;
      v20 = *(_QWORD *)(v11 + 8);
      if ( *(_DWORD *)(*(_QWORD *)v11 - 4LL) != -1362622009 )
        __break(0x8228u);
      v19(v20, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11);
      v21 = *(_QWORD *)(v11 + 24);
      v11 += 24;
    }
    while ( v21 );
  }
  return 0;
}
