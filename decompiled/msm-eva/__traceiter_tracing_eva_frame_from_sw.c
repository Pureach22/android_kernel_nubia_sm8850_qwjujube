__int64 __fastcall _traceiter_tracing_eva_frame_from_sw(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        unsigned int a4,
        unsigned int a5,
        unsigned int a6,
        __int64 a7,
        unsigned int a8,
        __int64 a9)
{
  _QWORD *v9; // x26
  void (__fastcall *v17)(__int64, __int64, __int64, _QWORD, _QWORD, _QWORD, __int64, _QWORD, __int64); // x8
  __int64 v18; // x0
  __int64 v19; // t1

  v9 = off_97828;
  if ( off_97828 )
  {
    do
    {
      v17 = (void (__fastcall *)(__int64, __int64, __int64, _QWORD, _QWORD, _QWORD, __int64, _QWORD, __int64))*v9;
      v18 = v9[1];
      if ( *(_DWORD *)(*v9 - 4LL) != -2023479207 )
        __break(0x8228u);
      v17(v18, a2, a3, a4, a5, a6, a7, a8, a9);
      v19 = v9[3];
      v9 += 3;
    }
    while ( v19 );
  }
  return 0;
}
