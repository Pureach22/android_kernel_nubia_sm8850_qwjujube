__int64 __fastcall _traceiter_kgsl_gpu_frequency(__int64 a1, unsigned int a2, unsigned int a3, __int64 a4)
{
  __int64 v4; // x22
  void (__fastcall *v8)(__int64, _QWORD, _QWORD, __int64); // x8
  __int64 v9; // x0
  __int64 v10; // t1

  v4 = qword_17F990;
  if ( qword_17F990 )
  {
    do
    {
      v8 = *(void (__fastcall **)(__int64, _QWORD, _QWORD, __int64))v4;
      v9 = *(_QWORD *)(v4 + 8);
      if ( *(_DWORD *)(*(_QWORD *)v4 - 4LL) != -100431228 )
        __break(0x8228u);
      v8(v9, a2, a3, a4);
      v10 = *(_QWORD *)(v4 + 24);
      v4 += 24;
    }
    while ( v10 );
  }
  return 0;
}
