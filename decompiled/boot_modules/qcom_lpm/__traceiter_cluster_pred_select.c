__int64 __fastcall _traceiter_cluster_pred_select(
        __int64 a1,
        unsigned int a2,
        __int64 a3,
        unsigned int a4,
        unsigned int a5,
        __int64 a6)
{
  __int64 v6; // x24
  void (__fastcall *v12)(__int64, _QWORD, __int64, _QWORD, _QWORD, __int64); // x8
  __int64 v13; // x0
  __int64 v14; // t1

  v6 = qword_C470;
  if ( qword_C470 )
  {
    do
    {
      v12 = *(void (__fastcall **)(__int64, _QWORD, __int64, _QWORD, _QWORD, __int64))v6;
      v13 = *(_QWORD *)(v6 + 8);
      if ( *(_DWORD *)(*(_QWORD *)v6 - 4LL) != -303637479 )
        __break(0x8228u);
      v12(v13, a2, a3, a4, a5, a6);
      v14 = *(_QWORD *)(v6 + 24);
      v6 += 24;
    }
    while ( v14 );
  }
  return 0;
}
