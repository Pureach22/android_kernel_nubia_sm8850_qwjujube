__int64 __fastcall adreno_dequeue_recurring_cmd(__int64 a1, __int64 a2)
{
  __int64 v2; // x8
  __int64 result; // x0
  __int64 v4; // x20
  __int64 v7; // x8
  __int64 (__fastcall *v8)(__int64, __int64); // x8
  __int64 v9; // x1
  unsigned int v10; // w20
  unsigned int v11; // w20
  unsigned __int64 v18; // x10
  unsigned __int64 v21; // x9

  v2 = *(_QWORD *)(a1 + 14264);
  if ( (*(_BYTE *)(v2 + 33) & 0x80) == 0 )
    return 4294967201LL;
  v4 = *(_QWORD *)(v2 + 40);
  if ( !*(_QWORD *)(v4 + 224) )
    return 4294967277LL;
  rt_mutex_lock(a1 + 11088);
  v7 = *(_QWORD *)(a1 + 22840);
  if ( !v7 || *(_QWORD *)(v7 + 8) != a2 )
  {
    rt_mutex_unlock(a1 + 11088);
    return 4294967274LL;
  }
  if ( !a2 || (*(_QWORD *)(a2 + 32) & 4) != 0 )
  {
    v11 = -35;
LABEL_17:
    rt_mutex_unlock(a1 + 11088);
    return v11;
  }
  if ( (*(_QWORD *)(a2 + 32) & 2) != 0 )
  {
    v11 = -2;
    goto LABEL_17;
  }
  _X8 = (unsigned __int64 *)(v7 + 56);
  __asm { PRFM            #0x11, [X8] }
  do
    v18 = __ldxr(_X8);
  while ( __stxr(v18 & 0xFFFFFFFFFFFFFFDFLL, _X8) );
  _X8 = (unsigned __int64 *)(*(_QWORD *)(a1 + 22840) + 56LL);
  __asm { PRFM            #0x11, [X8] }
  do
    v21 = __ldxr(_X8);
  while ( __stxr(v21 | 0x40, _X8) );
  v8 = *(__int64 (__fastcall **)(__int64, __int64))(v4 + 224);
  v9 = *(_QWORD *)(a1 + 22840);
  if ( *((_DWORD *)v8 - 1) != -348536088 )
    __break(0x8228u);
  v10 = v8(a1, v9);
  rt_mutex_unlock(a1 + 11088);
  result = v10;
  if ( !v10 )
  {
    srcu_notifier_call_chain(a1 + 13424, 1, 0);
    return 0;
  }
  return result;
}
