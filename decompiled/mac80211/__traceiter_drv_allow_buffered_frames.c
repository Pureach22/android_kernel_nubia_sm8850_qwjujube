__int64 __fastcall _traceiter_drv_allow_buffered_frames(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        unsigned int a4,
        unsigned int a5,
        unsigned int a6,
        char a7)
{
  __int64 v7; // x25
  void (__fastcall *v14)(__int64, __int64, __int64, _QWORD, _QWORD, _QWORD, _QWORD); // x8
  __int64 v15; // x0
  __int64 v16; // t1

  v7 = qword_C3D28;
  if ( qword_C3D28 )
  {
    do
    {
      v14 = *(void (__fastcall **)(__int64, __int64, __int64, _QWORD, _QWORD, _QWORD, _QWORD))v7;
      v15 = *(_QWORD *)(v7 + 8);
      if ( *(_DWORD *)(*(_QWORD *)v7 - 4LL) != -427114136 )
        __break(0x8228u);
      v14(v15, a2, a3, a4, a5, a6, a7 & 1);
      v16 = *(_QWORD *)(v7 + 24);
      v7 += 24;
    }
    while ( v16 );
  }
  return 0;
}
