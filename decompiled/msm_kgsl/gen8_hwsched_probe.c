__int64 __fastcall gen8_hwsched_probe(__int64 a1, int a2, __int64 a3)
{
  __int64 v6; // x0
  __int64 v7; // x19
  __int64 v8; // x23
  __int64 result; // x0
  __int64 v10; // x20
  unsigned __int64 v17; // x9

  v6 = devm_kmalloc(a1 + 16, 26696, 3520);
  if ( !v6 )
    return 4294967284LL;
  v7 = v6;
  v8 = v6 + 22264;
  *(_BYTE *)(v6 + 25848) = 1;
  *(_DWORD *)(v6 + 22712) = 322961474;
  result = gen8_probe_common(a1, v6 + 1824, a2, a3);
  if ( !(_DWORD)result )
  {
    *(_QWORD *)(v7 + 10584) = 0xFFFFFFFE00000LL;
    *(_QWORD *)(v7 + 10592) = v7 + 10592;
    *(_QWORD *)(v7 + 10600) = v7 + 10592;
    *(_QWORD *)(v7 + 10608) = hwsched_idle_check_1;
    init_timer_key(v7 + 10616, hwsched_idle_timer_1, 0, 0, 0);
    if ( (*(_BYTE *)(*(_QWORD *)(v7 + 16088) + 33LL) & 0x40) != 0 )
      *(_BYTE *)v8 = 1;
    _X8 = (unsigned __int64 *)(v7 + 1928);
    __asm { PRFM            #0x11, [X8] }
    do
      v17 = __ldxr(_X8);
    while ( __stxr(v17 | 0x100, _X8) );
    if ( (*(_BYTE *)(*(_QWORD *)(v7 + 16088) + 34LL) & 1) != 0 )
      *(_DWORD *)(v7 + 16000) = 31;
    result = adreno_hwsched_init(v7 + 1824, gen8_hwsched_ops);
    if ( !(_DWORD)result )
    {
      v10 = *(_QWORD *)(v7 + 3368);
      *(_DWORD *)(v8 + 3320) = -1;
      *(_DWORD *)(v8 + 3328) = -1;
      *(_DWORD *)(v8 + 3336) = -1;
      *(_DWORD *)(v8 + 3344) = -1;
      *(_DWORD *)(v8 + 3352) = -1;
      *(_DWORD *)(v8 + 3360) = -1;
      *(_DWORD *)(v8 + 3368) = -1;
      *(_DWORD *)(v8 + 3376) = -1;
      *(_DWORD *)(v8 + 3384) = -1;
      *(_DWORD *)(v8 + 3392) = -1;
      *(_DWORD *)(v8 + 3400) = -1;
      *(_DWORD *)(v8 + 3408) = -1;
      *(_DWORD *)(v8 + 3416) = -1;
      *(_DWORD *)(v8 + 3424) = -1;
      *(_DWORD *)(v8 + 3432) = -1;
      *(_DWORD *)(v8 + 3440) = -1;
      *(_DWORD *)(v8 + 3448) = -1;
      if ( (unsigned int)kobject_init_and_add(v7 + 25392, &ktype_tunables, v10 + 16, "dcvs_tunables") )
        __break(0x800u);
      result = kobject_init_and_add(v7 + 25488, &ktype_dcvs, v10 + 16, "dcvs");
      if ( (_DWORD)result )
      {
        __break(0x800u);
        return 0;
      }
    }
  }
  return result;
}
