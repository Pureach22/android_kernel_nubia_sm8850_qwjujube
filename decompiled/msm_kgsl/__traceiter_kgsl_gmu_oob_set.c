__int64 __fastcall _traceiter_kgsl_gmu_oob_set(__int64 a1, unsigned int a2)
{
  __int64 v2; // x20
  void (__fastcall *v4)(__int64, _QWORD); // x8
  __int64 v5; // x0
  __int64 v6; // t1

  v2 = qword_180480;
  if ( qword_180480 )
  {
    do
    {
      v4 = *(void (__fastcall **)(__int64, _QWORD))v2;
      v5 = *(_QWORD *)(v2 + 8);
      if ( *(_DWORD *)(*(_QWORD *)v2 - 4LL) != -1783303382 )
        __break(0x8228u);
      v4(v5, a2);
      v6 = *(_QWORD *)(v2 + 24);
      v2 += 24;
    }
    while ( v6 );
  }
  return 0;
}
