__int64 __fastcall _traceiter_sched_update_task_ravg(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        unsigned int a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        __int64 a9,
        __int64 a10)
{
  __int64 v10; // x26
  void (__fastcall *v18)(__int64, __int64, __int64, _QWORD, __int64, __int64, __int64, __int64, __int64, __int64); // x8
  __int64 v19; // x0
  __int64 v20; // t1

  v10 = qword_6D9A0;
  if ( qword_6D9A0 )
  {
    do
    {
      v18 = *(void (__fastcall **)(__int64, __int64, __int64, _QWORD, __int64, __int64, __int64, __int64, __int64, __int64))v10;
      v19 = *(_QWORD *)(v10 + 8);
      if ( *(_DWORD *)(*(_QWORD *)v10 - 4LL) != 1321001748 )
        __break(0x8228u);
      v18(v19, a2, a3, a4, a5, a6, a7, a8, a9, a10);
      v20 = *(_QWORD *)(v10 + 24);
      v10 += 24;
    }
    while ( v20 );
  }
  return 0;
}
