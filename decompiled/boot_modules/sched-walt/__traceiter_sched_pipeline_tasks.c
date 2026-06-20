__int64 __fastcall _traceiter_sched_pipeline_tasks(
        __int64 a1,
        unsigned int a2,
        unsigned int a3,
        __int64 a4,
        unsigned int a5,
        unsigned int a6,
        char a7,
        unsigned int a8,
        char a9)
{
  __int64 v9; // x26
  void (__fastcall *v17)(__int64, _QWORD, _QWORD, __int64, _QWORD, _QWORD, _QWORD, _QWORD, int); // x8
  __int64 v18; // x0
  __int64 v19; // t1
  int v21; // [xsp+0h] [xbp-10h]

  v9 = qword_6E710;
  if ( qword_6E710 )
  {
    do
    {
      v17 = *(void (__fastcall **)(__int64, _QWORD, _QWORD, __int64, _QWORD, _QWORD, _QWORD, _QWORD, int))v9;
      v18 = *(_QWORD *)(v9 + 8);
      if ( *(_DWORD *)(*(_QWORD *)v9 - 4LL) != -1830074441 )
        __break(0x8228u);
      LOBYTE(v21) = a9 & 1;
      v17(v18, a2, a3, a4, a5, a6, a7 & 1, a8, v21);
      v19 = *(_QWORD *)(v9 + 24);
      v9 += 24;
    }
    while ( v19 );
  }
  return 0;
}
