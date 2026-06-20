__int64 __fastcall a6xx_gmu_device_probe(__int64 a1, int a2, __int64 a3)
{
  __int64 v6; // x0
  _QWORD *v7; // x19
  __int64 result; // x0

  v6 = devm_kmalloc(a1 + 16, 26192, 3520);
  if ( !v6 )
    return 4294967284LL;
  v7 = (_QWORD *)v6;
  *(_DWORD *)(v6 + 22536) = 332456898;
  result = a6xx_probe_common(a1, v6 + 1648, a2, a3);
  if ( !(_DWORD)result )
  {
    result = adreno_dispatcher_init(v7 + 206);
    if ( !(_DWORD)result )
    {
      v7[1301] = 0xFFFFFFFE00000LL;
      v7[1302] = v7 + 1302;
      v7[1303] = v7 + 1302;
      v7[1304] = gmu_idle_check;
      init_timer_key(v7 + 1305, gmu_idle_timer, 0, 0, 0);
      return 0;
    }
  }
  return result;
}
