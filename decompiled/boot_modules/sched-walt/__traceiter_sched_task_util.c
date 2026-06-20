__int64 __fastcall _traceiter_sched_task_util(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        unsigned int a4,
        char a5,
        unsigned int a6,
        unsigned int a7,
        __int64 a8,
        char a9,
        int a10,
        int a11)
{
  __int64 v11; // x26
  void (__fastcall *v19)(__int64, __int64, __int64, _QWORD, _QWORD, _QWORD, _QWORD, __int64, int, int, int); // x8
  __int64 v20; // x0
  __int64 v21; // t1
  int v23; // [xsp+0h] [xbp-20h]

  v11 = qword_6E170;
  if ( qword_6E170 )
  {
    do
    {
      v19 = *(void (__fastcall **)(__int64, __int64, __int64, _QWORD, _QWORD, _QWORD, _QWORD, __int64, int, int, int))v11;
      v20 = *(_QWORD *)(v11 + 8);
      if ( *(_DWORD *)(*(_QWORD *)v11 - 4LL) != -1694874870 )
        __break(0x8228u);
      LOBYTE(v23) = a9 & 1;
      v19(v20, a2, a3, a4, a5 & 1, a6, a7, a8, v23, a10, a11);
      v21 = *(_QWORD *)(v11 + 24);
      v11 += 24;
    }
    while ( v21 );
  }
  return 0;
}
