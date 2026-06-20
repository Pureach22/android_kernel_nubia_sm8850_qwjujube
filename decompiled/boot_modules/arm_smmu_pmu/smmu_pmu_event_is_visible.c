__int64 __fastcall smmu_pmu_event_is_visible(__int64 a1, __int64 a2)
{
  unsigned __int64 v2; // x9
  __int64 v3; // x8
  __int64 v4; // x10
  unsigned __int64 v12; // x9

  v2 = *(_QWORD *)(a2 + 32);
  v3 = *(_QWORD *)(a1 + 152) - 56LL;
  if ( v2 < 0x80 )
  {
    if ( ((*(_QWORD *)(v3 + ((v2 >> 3) & 0x1FFFFFFFFFFFFFF8LL)) >> v2) & 1) != 0 )
      return *(unsigned __int16 *)(a2 + 8);
    else
      return 0;
  }
  else
  {
    v4 = 1LL << v2;
    _X8 = (unsigned __int64 *)(v3 + 8LL * ((unsigned int)v2 >> 6));
    __asm { PRFM            #0x11, [X8] }
    do
      v12 = __ldxr(_X8);
    while ( __stlxr(v12 | v4, _X8) );
    __dmb(0xBu);
    return *(unsigned __int16 *)(a2 + 8);
  }
}
