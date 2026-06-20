__int64 __fastcall _traceiter_adreno_cmdbatch_ready(
        __int64 a1,
        unsigned int a2,
        unsigned int a3,
        unsigned int a4,
        unsigned int a5)
{
  __int64 v5; // x23
  void (__fastcall *v10)(__int64, _QWORD, _QWORD, _QWORD, _QWORD); // x8
  __int64 v11; // x0
  __int64 v12; // t1

  v5 = qword_17ED60;
  if ( qword_17ED60 )
  {
    do
    {
      v10 = *(void (__fastcall **)(__int64, _QWORD, _QWORD, _QWORD, _QWORD))v5;
      v11 = *(_QWORD *)(v5 + 8);
      if ( *(_DWORD *)(*(_QWORD *)v5 - 4LL) != 1777565545 )
        __break(0x8228u);
      v10(v11, a2, a3, a4, a5);
      v12 = *(_QWORD *)(v5 + 24);
      v5 += 24;
    }
    while ( v12 );
  }
  return 0;
}
