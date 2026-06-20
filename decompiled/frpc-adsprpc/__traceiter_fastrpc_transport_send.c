__int64 __fastcall _traceiter_fastrpc_transport_send(
        __int64 a1,
        unsigned int a2,
        __int64 a3,
        __int64 a4,
        unsigned int a5,
        unsigned int a6,
        __int64 a7,
        __int64 a8)
{
  __int64 v8; // x26
  void (__fastcall *v16)(__int64, _QWORD, __int64, __int64, _QWORD, _QWORD, __int64, __int64); // x8
  __int64 v17; // x0
  __int64 v18; // t1

  v8 = qword_22650;
  if ( qword_22650 )
  {
    do
    {
      v16 = *(void (__fastcall **)(__int64, _QWORD, __int64, __int64, _QWORD, _QWORD, __int64, __int64))v8;
      v17 = *(_QWORD *)(v8 + 8);
      if ( *(_DWORD *)(*(_QWORD *)v8 - 4LL) != -1468097945 )
        __break(0x8228u);
      v16(v17, a2, a3, a4, a5, a6, a7, a8);
      v18 = *(_QWORD *)(v8 + 24);
      v8 += 24;
    }
    while ( v18 );
  }
  return 0;
}
