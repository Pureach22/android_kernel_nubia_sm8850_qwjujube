__int64 __fastcall _traceiter_api_scan_completed(__int64 a1, __int64 a2, char a3)
{
  __int64 v3; // x21
  void (__fastcall *v6)(__int64, __int64, _QWORD); // x8
  __int64 v7; // x0
  __int64 v8; // t1

  v3 = qword_C4EA8;
  if ( qword_C4EA8 )
  {
    do
    {
      v6 = *(void (__fastcall **)(__int64, __int64, _QWORD))v3;
      v7 = *(_QWORD *)(v3 + 8);
      if ( *(_DWORD *)(*(_QWORD *)v3 - 4LL) != -1256365746 )
        __break(0x8228u);
      v6(v7, a2, a3 & 1);
      v8 = *(_QWORD *)(v3 + 24);
      v3 += 24;
    }
    while ( v8 );
  }
  return 0;
}
