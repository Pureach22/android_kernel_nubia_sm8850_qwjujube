__int64 __fastcall _traceiter_sched_get_nr_running_avg(
        __int64 a1,
        unsigned int a2,
        unsigned int a3,
        unsigned int a4,
        unsigned int a5,
        unsigned int a6,
        unsigned int a7,
        char a8)
{
  __int64 v8; // x26
  void (__fastcall *v16)(__int64, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD); // x8
  __int64 v17; // x0
  __int64 v18; // t1

  v8 = qword_6DD10;
  if ( qword_6DD10 )
  {
    do
    {
      v16 = *(void (__fastcall **)(__int64, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD))v8;
      v17 = *(_QWORD *)(v8 + 8);
      if ( *(_DWORD *)(*(_QWORD *)v8 - 4LL) != -1270637854 )
        __break(0x8228u);
      v16(v17, a2, a3, a4, a5, a6, a7, a8 & 1);
      v18 = *(_QWORD *)(v8 + 24);
      v8 += 24;
    }
    while ( v18 );
  }
  return 0;
}
