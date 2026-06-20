__int64 __fastcall _traceiter_adreno_cmdbatch_submitted(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        unsigned int a7)
{
  __int64 v7; // x25
  void (__fastcall *v14)(__int64, __int64, __int64, __int64, __int64, __int64, _QWORD); // x8
  __int64 v15; // x0
  __int64 v16; // t1

  v7 = qword_17EBD0;
  if ( qword_17EBD0 )
  {
    do
    {
      v14 = *(void (__fastcall **)(__int64, __int64, __int64, __int64, __int64, __int64, _QWORD))v7;
      v15 = *(_QWORD *)(v7 + 8);
      if ( *(_DWORD *)(*(_QWORD *)v7 - 4LL) != -1153690664 )
        __break(0x8228u);
      v14(v15, a2, a3, a4, a5, a6, a7);
      v16 = *(_QWORD *)(v7 + 24);
      v7 += 24;
    }
    while ( v16 );
  }
  return 0;
}
