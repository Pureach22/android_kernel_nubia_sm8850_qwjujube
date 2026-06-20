__int64 __fastcall _traceiter_ipc_freq(
        __int64 a1,
        unsigned int a2,
        unsigned int a3,
        unsigned int a4,
        unsigned int a5,
        __int64 a6,
        __int64 a7,
        unsigned int a8,
        __int64 a9)
{
  __int64 v9; // x26
  void (__fastcall *v17)(__int64, _QWORD, _QWORD, _QWORD, _QWORD, __int64, __int64, _QWORD, __int64); // x8
  __int64 v18; // x0
  __int64 v19; // t1

  v9 = qword_6E620;
  if ( qword_6E620 )
  {
    do
    {
      v17 = *(void (__fastcall **)(__int64, _QWORD, _QWORD, _QWORD, _QWORD, __int64, __int64, _QWORD, __int64))v9;
      v18 = *(_QWORD *)(v9 + 8);
      if ( *(_DWORD *)(*(_QWORD *)v9 - 4LL) != -2128282615 )
        __break(0x8228u);
      v17(v18, a2, a3, a4, a5, a6, a7, a8, a9);
      v19 = *(_QWORD *)(v9 + 24);
      v9 += 24;
    }
    while ( v19 );
  }
  return 0;
}
