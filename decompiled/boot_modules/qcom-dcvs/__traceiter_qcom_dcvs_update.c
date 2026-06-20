__int64 __fastcall _traceiter_qcom_dcvs_update(
        __int64 a1,
        __int64 a2,
        unsigned int a3,
        unsigned int a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        __int64 a9)
{
  __int64 v9; // x26
  void (__fastcall *v17)(__int64, __int64, _QWORD, _QWORD, __int64, __int64, __int64, __int64, __int64); // x8
  __int64 v18; // x0
  __int64 v19; // t1

  v9 = qword_CE60;
  if ( qword_CE60 )
  {
    do
    {
      v17 = *(void (__fastcall **)(__int64, __int64, _QWORD, _QWORD, __int64, __int64, __int64, __int64, __int64))v9;
      v18 = *(_QWORD *)(v9 + 8);
      if ( *(_DWORD *)(*(_QWORD *)v9 - 4LL) != 1169222989 )
        __break(0x8228u);
      v17(v18, a2, a3, a4, a5, a6, a7, a8, a9);
      v19 = *(_QWORD *)(v9 + 24);
      v9 += 24;
    }
    while ( v19 );
  }
  return 0;
}
