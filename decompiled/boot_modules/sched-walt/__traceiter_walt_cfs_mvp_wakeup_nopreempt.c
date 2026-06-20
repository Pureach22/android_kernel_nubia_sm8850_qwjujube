__int64 __fastcall _traceiter_walt_cfs_mvp_wakeup_nopreempt(__int64 a1, __int64 a2, __int64 a3, unsigned int a4)
{
  __int64 v4; // x22
  void (__fastcall *v8)(__int64, __int64, __int64, _QWORD); // x8
  __int64 v9; // x0
  __int64 v10; // t1

  v4 = qword_6E350;
  if ( qword_6E350 )
  {
    do
    {
      v8 = *(void (__fastcall **)(__int64, __int64, __int64, _QWORD))v4;
      v9 = *(_QWORD *)(v4 + 8);
      if ( *(_DWORD *)(*(_QWORD *)v4 - 4LL) != 128679515 )
        __break(0x8228u);
      v8(v9, a2, a3, a4);
      v10 = *(_QWORD *)(v4 + 24);
      v4 += 24;
    }
    while ( v10 );
  }
  return 0;
}
