__int64 __fastcall _traceiter_adreno_gpu_vote_params(
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
        __int64 a12)
{
  __int64 v12; // x26
  void (__fastcall *v20)(__int64, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD, int, int, int, __int64); // x8
  __int64 v21; // x0
  __int64 v22; // t1

  v12 = qword_17F580;
  if ( qword_17F580 )
  {
    do
    {
      v20 = *(void (__fastcall **)(__int64, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD, int, int, int, __int64))v12;
      v21 = *(_QWORD *)(v12 + 8);
      if ( *(_DWORD *)(*(_QWORD *)v12 - 4LL) != -1550688633 )
        __break(0x8228u);
      v20(v21, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12);
      v22 = *(_QWORD *)(v12 + 24);
      v12 += 24;
    }
    while ( v22 );
  }
  return 0;
}
