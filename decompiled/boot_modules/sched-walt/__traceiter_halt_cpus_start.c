__int64 __fastcall _traceiter_halt_cpus_start(__int64 a1, __int64 a2, unsigned int a3)
{
  __int64 v3; // x21
  void (__fastcall *v6)(__int64, __int64, _QWORD); // x8
  __int64 v7; // x0
  __int64 v8; // t1

  v3 = qword_6E490;
  if ( qword_6E490 )
  {
    do
    {
      v6 = *(void (__fastcall **)(__int64, __int64, _QWORD))v3;
      v7 = *(_QWORD *)(v3 + 8);
      if ( *(_DWORD *)(*(_QWORD *)v3 - 4LL) != -1528498079 )
        __break(0x8228u);
      v6(v7, a2, a3);
      v8 = *(_QWORD *)(v3 + 24);
      v3 += 24;
    }
    while ( v8 );
  }
  return 0;
}
