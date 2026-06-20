__int64 __fastcall _traceiter_sde_perf_crtc_update(
        __int64 a1,
        unsigned int a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        int a9,
        char a10,
        int a11,
        int a12,
        int a13)
{
  __int64 v13; // x26
  void (__fastcall *v21)(__int64, _QWORD, __int64, __int64, __int64, __int64, __int64, __int64, int, int, int, int, int); // x8
  __int64 v22; // x0
  __int64 v23; // t1
  int v25; // [xsp+8h] [xbp-38h]

  v13 = qword_29E470;
  if ( qword_29E470 )
  {
    do
    {
      v21 = *(void (__fastcall **)(__int64, _QWORD, __int64, __int64, __int64, __int64, __int64, __int64, int, int, int, int, int))v13;
      v22 = *(_QWORD *)(v13 + 8);
      if ( *(_DWORD *)(*(_QWORD *)v13 - 4LL) != 1331335978 )
        __break(0x8228u);
      LOBYTE(v25) = a10 & 1;
      v21(v22, a2, a3, a4, a5, a6, a7, a8, a9, v25, a11, a12, a13);
      v23 = *(_QWORD *)(v13 + 24);
      v13 += 24;
    }
    while ( v23 );
  }
  return 0;
}
