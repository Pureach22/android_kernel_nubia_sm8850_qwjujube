__int64 __fastcall _traceiter_lpm_gov_select(__int64 a1, unsigned int a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v5; // x23
  void (__fastcall *v10)(__int64, _QWORD, __int64, __int64, __int64); // x8
  __int64 v11; // x0
  __int64 v12; // t1

  v5 = qword_C5B0;
  if ( qword_C5B0 )
  {
    do
    {
      v10 = *(void (__fastcall **)(__int64, _QWORD, __int64, __int64, __int64))v5;
      v11 = *(_QWORD *)(v5 + 8);
      if ( *(_DWORD *)(*(_QWORD *)v5 - 4LL) != -856827744 )
        __break(0x8228u);
      v10(v11, a2, a3, a4, a5);
      v12 = *(_QWORD *)(v5 + 24);
      v5 += 24;
    }
    while ( v12 );
  }
  return 0;
}
