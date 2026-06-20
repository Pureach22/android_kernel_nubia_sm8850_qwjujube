__int64 __fastcall _traceiter_si_objcet_do_ctx_invoke_ret(
        __int64 a1,
        unsigned int a2,
        unsigned int a3,
        unsigned int a4,
        __int64 a5,
        unsigned int a6)
{
  __int64 v6; // x24
  void (__fastcall *v12)(__int64, _QWORD, _QWORD, _QWORD, __int64, _QWORD); // x8
  __int64 v13; // x0
  __int64 v14; // t1

  v6 = qword_B940;
  if ( qword_B940 )
  {
    do
    {
      v12 = *(void (__fastcall **)(__int64, _QWORD, _QWORD, _QWORD, __int64, _QWORD))v6;
      v13 = *(_QWORD *)(v6 + 8);
      if ( *(_DWORD *)(*(_QWORD *)v6 - 4LL) != 475668572 )
        __break(0x8228u);
      v12(v13, a2, a3, a4, a5, a6);
      v14 = *(_QWORD *)(v6 + 24);
      v6 += 24;
    }
    while ( v14 );
  }
  return 0;
}
