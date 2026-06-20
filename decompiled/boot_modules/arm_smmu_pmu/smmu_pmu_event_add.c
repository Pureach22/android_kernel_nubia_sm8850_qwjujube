__int64 __fastcall smmu_pmu_event_add(__int64 result, char a2)
{
  __int64 v2; // x8
  __int64 v3; // x19
  __int64 v5; // x24
  int v6; // w25
  __int64 v7; // x22
  __int64 v8; // x8
  unsigned __int64 v11; // x9
  unsigned __int64 v18; // x10

  v2 = *(_QWORD *)(result + 224);
  v3 = result;
  v5 = *(_QWORD *)(result + 152);
  LODWORD(result) = (unsigned __int16)v2;
  if ( (unsigned __int16)v2 > 0x7Fu )
  {
    v8 = 1LL << v2;
    _X10 = (unsigned __int64 *)(v5 - 88 + 8LL * ((unsigned int)result >> 6));
    __asm { PRFM            #0x11, [X10] }
    do
      v11 = __ldxr(_X10);
    while ( __stlxr(v11 | v8, _X10) );
    __dmb(0xBu);
    if ( (v11 & v8) != 0 )
      return 4294967285LL;
LABEL_12:
    *(_DWORD *)(v3 + 396) = result;
    *(_DWORD *)(v3 + 480) = 3;
    if ( (unsigned int)result >= 0x100 )
    {
      __break(0x5512u);
      return smmu_pmu_event_del();
    }
    else
    {
      *(_QWORD *)(v5 + 8LL * (unsigned int)result - 2136) = v3;
      *(_QWORD *)(v3 + 488) = 0;
      if ( (a2 & 1) != 0 )
        smmu_pmu_event_start(v3);
      perf_event_update_userpage(v3);
      return 0;
    }
  }
  v6 = *(_DWORD *)(v5 + 312) / *(_DWORD *)(v5 + 316);
  v7 = (*(_QWORD *)(v3 + 272) >> 35) & 7LL;
  result = find_next_zero_bit(v5 - 88);
  if ( v6 * (int)v7 + v6 <= (unsigned int)result )
  {
    dev_err(*(_QWORD *)(v5 + 320) + 16LL, "All counters in use for tbu : %d\n", v7);
    return 4294967285LL;
  }
  _X9 = (unsigned __int64 *)(v5 - 88 + 8LL * ((unsigned int)result >> 6));
  __asm { PRFM            #0x11, [X9] }
  do
    v18 = __ldxr(_X9);
  while ( __stxr(v18 | (1LL << result), _X9) );
  if ( (result & 0x80000000) == 0 )
    goto LABEL_12;
  return result;
}
