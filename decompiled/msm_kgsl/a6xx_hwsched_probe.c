__int64 __fastcall a6xx_hwsched_probe(__int64 a1, int a2, __int64 a3)
{
  __int64 v6; // x0
  _QWORD *v7; // x19
  __int64 result; // x0

  v6 = devm_kmalloc(a1 + 16, 26328, 3520);
  if ( !v6 )
    return 4294967284LL;
  v7 = (_QWORD *)v6;
  *(_BYTE *)(v6 + 25672) = 1;
  *(_DWORD *)(v6 + 22536) = 322961474;
  result = a6xx_probe_common(a1, v6 + 1648, a2, a3);
  if ( !(_DWORD)result )
  {
    v7[1301] = 0xFFFFFFFE00000LL;
    v7[1302] = v7 + 1302;
    v7[1303] = v7 + 1302;
    v7[1304] = hwsched_idle_check;
    init_timer_key(v7 + 1305, hwsched_idle_timer, 0, 0, 0);
    return adreno_hwsched_init(v7 + 206, a6xx_hwsched_ops);
  }
  return result;
}
