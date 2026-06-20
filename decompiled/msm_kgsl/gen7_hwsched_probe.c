__int64 __fastcall gen7_hwsched_probe(__int64 a1, int a2, __int64 a3)
{
  __int64 v6; // x0
  __int64 v7; // x20
  _BYTE *v8; // x23
  __int64 result; // x0
  __int64 v10; // x9
  __int64 v11; // x8
  unsigned int v12; // w20
  unsigned __int64 v15; // x9
  unsigned __int64 v22; // x9

  v6 = devm_kmalloc(a1 + 16, 26592, 3520);
  if ( !v6 )
    return 4294967284LL;
  v7 = v6;
  v8 = (_BYTE *)(v6 + 22216);
  *(_BYTE *)(v6 + 25800) = 1;
  *(_DWORD *)(v6 + 22664) = 322961474;
  result = gen7_probe_common(a1, v6 + 1776, a2, a3);
  if ( !(_DWORD)result )
  {
    *(_QWORD *)(v7 + 10536) = 0xFFFFFFFE00000LL;
    *(_QWORD *)(v7 + 10544) = v7 + 10544;
    *(_QWORD *)(v7 + 10552) = v7 + 10544;
    *(_QWORD *)(v7 + 10560) = hwsched_idle_check_0;
    init_timer_key(v7 + 10568, hwsched_idle_timer_0, 0, 0, 0);
    v10 = *(_QWORD *)(v7 + 16040);
    v11 = *(_QWORD *)(v10 + 32);
    if ( (v11 & 0x4000) != 0 )
    {
      *v8 = 1;
      v11 = *(_QWORD *)(v10 + 32);
    }
    if ( (v11 & 0x20000) != 0 )
    {
      _X8 = (unsigned __int64 *)(v7 + 16016);
      __asm { PRFM            #0x11, [X8] }
      do
        v22 = __ldxr(_X8);
      while ( __stxr(v22 | 0x4000, _X8) );
      v8[1] = 1;
    }
    _X8 = (unsigned __int64 *)(v7 + 1880);
    __asm { PRFM            #0x11, [X8] }
    do
      v15 = __ldxr(_X8);
    while ( __stxr(v15 | 0x100, _X8) );
    if ( (*(_BYTE *)(*(_QWORD *)(v7 + 16040) + 34LL) & 1) != 0 )
      *(_DWORD *)(v7 + 15952) = 41;
    result = adreno_hwsched_init(v7 + 1776, gen7_hwsched_ops);
    if ( (_DWORD)result )
    {
      v12 = result;
      dev_err(a1 + 16, "adreno hardware scheduler init failed ret %d\n", result);
      return v12;
    }
  }
  return result;
}
