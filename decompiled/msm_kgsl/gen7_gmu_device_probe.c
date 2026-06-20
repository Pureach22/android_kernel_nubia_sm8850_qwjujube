__int64 __fastcall gen7_gmu_device_probe(__int64 a1, int a2, __int64 a3)
{
  __int64 v6; // x0
  _QWORD *v7; // x19
  __int64 v8; // x23
  __int64 result; // x0
  int v10; // w0
  unsigned int v11; // w19
  unsigned __int64 v18; // x9

  v6 = devm_kmalloc(a1 + 16, 26328, 3520);
  if ( !v6 )
    return 4294967284LL;
  v7 = (_QWORD *)v6;
  v8 = v6 + 20480;
  *(_DWORD *)(v6 + 22664) = 869434306;
  result = gen7_probe_common(a1, v6 + 1776, a2, a3);
  if ( !(_DWORD)result )
  {
    v10 = adreno_dispatcher_init(v7 + 222);
    if ( v10 )
    {
      v11 = v10;
      dev_err(a1 + 16, "adreno dispatcher init failed ret %d\n", v10);
      return v11;
    }
    else
    {
      v7[1317] = 0xFFFFFFFE00000LL;
      v7[1318] = v7 + 1318;
      v7[1319] = v7 + 1318;
      v7[1320] = gmu_idle_check_0;
      init_timer_key(v7 + 1321, gmu_idle_timer_0, 0, 0, 0);
      result = 0;
      if ( (*(_BYTE *)(v7[2005] + 34LL) & 2) != 0 )
      {
        _X8 = v7 + 2002;
        __asm { PRFM            #0x11, [X8] }
        do
          v18 = __ldxr(_X8);
        while ( __stxr(v18 | 0x4000, _X8) );
        *(_BYTE *)(v8 + 1737) = 1;
        return 0;
      }
    }
  }
  return result;
}
