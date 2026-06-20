__int64 __fastcall gen8_gmu_device_probe(__int64 a1, int a2, __int64 a3)
{
  __int64 v6; // x0
  _QWORD *v7; // x19
  __int64 result; // x0

  v6 = devm_kmalloc(a1 + 16, 26440, 3520);
  if ( !v6 )
    return 4294967284LL;
  v7 = (_QWORD *)v6;
  *(_DWORD *)(v6 + 22712) = 869434306;
  result = gen8_probe_common(a1, v6 + 1824, a2, a3);
  if ( !(_DWORD)result )
  {
    result = adreno_dispatcher_init(v7 + 228);
    if ( !(_DWORD)result )
    {
      v7[1323] = 0xFFFFFFFE00000LL;
      v7[1324] = v7 + 1324;
      v7[1325] = v7 + 1324;
      v7[1326] = gmu_idle_check_1;
      init_timer_key(v7 + 1327, gmu_idle_timer_1, 0, 0, 0);
      return 0;
    }
  }
  return result;
}
