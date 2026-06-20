__int64 __fastcall _traceiter_hwmon_attr_show_string(__int64 a1, unsigned int a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x22
  void (__fastcall *v8)(__int64, _QWORD, __int64, __int64); // x8
  __int64 v9; // x0
  __int64 v10; // t1

  v4 = qword_86B0;
  if ( qword_86B0 )
  {
    do
    {
      v8 = *(void (__fastcall **)(__int64, _QWORD, __int64, __int64))v4;
      v9 = *(_QWORD *)(v4 + 8);
      if ( *(_DWORD *)(*(_QWORD *)v4 - 4LL) != 551358637 )
        __break(0x8228u);
      v8(v9, a2, a3, a4);
      v10 = *(_QWORD *)(v4 + 24);
      v4 += 24;
    }
    while ( v10 );
  }
  return 0;
}
