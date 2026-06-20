__int64 __fastcall smmu_pmu_event_del(__int64 a1)
{
  __int64 v1; // x20
  unsigned __int64 v2; // x21
  __int64 v4; // x8
  unsigned __int64 v5; // x9
  __int64 v6; // x10
  unsigned __int64 v14; // x10

  v1 = *(_QWORD *)(a1 + 152);
  v2 = *(unsigned int *)(a1 + 396);
  smmu_pmu_event_stop();
  if ( (unsigned int)v2 >= 0x100 )
  {
    __break(0x5512u);
  }
  else
  {
    v5 = v2 >> 6;
    v4 = 1LL << v2;
    v6 = v1 - 88;
    *(_QWORD *)(v1 + 8 * v2 - 2136) = 0;
  }
  _X9 = (unsigned __int64 *)(v6 + 8 * v5);
  __asm { PRFM            #0x11, [X9] }
  do
    v14 = __ldxr(_X9);
  while ( __stxr(v14 & ~v4, _X9) );
  return perf_event_update_userpage(a1);
}
