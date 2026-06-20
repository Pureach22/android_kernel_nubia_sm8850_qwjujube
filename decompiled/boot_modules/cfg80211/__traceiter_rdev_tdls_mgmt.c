__int64 __fastcall _traceiter_rdev_tdls_mgmt(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        unsigned int a5,
        unsigned int a6,
        unsigned int a7,
        unsigned int a8,
        int a9,
        char a10,
        __int64 a11,
        __int64 a12)
{
  __int64 v12; // x26
  void (__fastcall *v20)(__int64, __int64, __int64, __int64, _QWORD, _QWORD, _QWORD, _QWORD, int, int, __int64, __int64); // x8
  __int64 v21; // x0
  __int64 v22; // t1
  int v24; // [xsp+8h] [xbp-28h]

  v12 = qword_C2360;
  if ( qword_C2360 )
  {
    do
    {
      v20 = *(void (__fastcall **)(__int64, __int64, __int64, __int64, _QWORD, _QWORD, _QWORD, _QWORD, int, int, __int64, __int64))v12;
      v21 = *(_QWORD *)(v12 + 8);
      if ( *(_DWORD *)(*(_QWORD *)v12 - 4LL) != 1084787260 )
        __break(0x8228u);
      LOBYTE(v24) = a10 & 1;
      v20(v21, a2, a3, a4, a5, a6, a7, a8, a9, v24, a11, a12);
      v22 = *(_QWORD *)(v12 + 24);
      v12 += 24;
    }
    while ( v22 );
  }
  return 0;
}
