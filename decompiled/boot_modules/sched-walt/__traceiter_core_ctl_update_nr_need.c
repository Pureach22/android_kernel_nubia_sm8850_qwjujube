__int64 __fastcall _traceiter_core_ctl_update_nr_need(
        __int64 a1,
        unsigned int a2,
        unsigned int a3,
        unsigned int a4,
        unsigned int a5,
        unsigned int a6,
        unsigned int a7,
        unsigned int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13)
{
  __int64 v13; // x26
  void (__fastcall *v21)(__int64, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD, int, int, int, int, int); // x8
  __int64 v22; // x0
  __int64 v23; // t1

  v13 = qword_6DC20;
  if ( qword_6DC20 )
  {
    do
    {
      v21 = *(void (__fastcall **)(__int64, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD, int, int, int, int, int))v13;
      v22 = *(_QWORD *)(v13 + 8);
      if ( *(_DWORD *)(*(_QWORD *)v13 - 4LL) != -1192774869 )
        __break(0x8228u);
      v21(v22, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13);
      v23 = *(_QWORD *)(v13 + 24);
      v13 += 24;
    }
    while ( v23 );
  }
  return 0;
}
