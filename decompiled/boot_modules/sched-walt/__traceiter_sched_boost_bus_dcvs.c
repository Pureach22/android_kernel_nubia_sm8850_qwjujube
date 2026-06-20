__int64 __fastcall _traceiter_sched_boost_bus_dcvs(__int64 a1, char a2, char a3, char a4)
{
  __int64 v4; // x22
  void (__fastcall *v8)(__int64, _QWORD, _QWORD, _QWORD); // x8
  __int64 v9; // x0
  __int64 v10; // t1

  v4 = qword_6E7B0;
  if ( qword_6E7B0 )
  {
    do
    {
      v8 = *(void (__fastcall **)(__int64, _QWORD, _QWORD, _QWORD))v4;
      v9 = *(_QWORD *)(v4 + 8);
      if ( *(_DWORD *)(*(_QWORD *)v4 - 4LL) != 585758698 )
        __break(0x8228u);
      v8(v9, a2 & 1, a3 & 1, a4 & 1);
      v10 = *(_QWORD *)(v4 + 24);
      v4 += 24;
    }
    while ( v10 );
  }
  return 0;
}
