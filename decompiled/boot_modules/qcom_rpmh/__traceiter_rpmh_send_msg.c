__int64 __fastcall _traceiter_rpmh_send_msg(
        __int64 a1,
        __int64 a2,
        unsigned int a3,
        unsigned int a4,
        unsigned int a5,
        unsigned int a6,
        __int64 a7)
{
  __int64 v7; // x25
  void (__fastcall *v14)(__int64, __int64, _QWORD, _QWORD, _QWORD, _QWORD, __int64); // x8
  __int64 v15; // x0
  __int64 v16; // t1

  v7 = qword_D5B0;
  if ( qword_D5B0 )
  {
    do
    {
      v14 = *(void (__fastcall **)(__int64, __int64, _QWORD, _QWORD, _QWORD, _QWORD, __int64))v7;
      v15 = *(_QWORD *)(v7 + 8);
      if ( *(_DWORD *)(*(_QWORD *)v7 - 4LL) != 1269941751 )
        __break(0x8228u);
      v14(v15, a2, a3, a4, a5, a6, a7);
      v16 = *(_QWORD *)(v7 + 24);
      v7 += 24;
    }
    while ( v16 );
  }
  return 0;
}
