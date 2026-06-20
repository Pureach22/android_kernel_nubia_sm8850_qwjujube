__int64 __fastcall funnel_gfx_enable(__int64 a1, __int64 a2, __int64 a3)
{
  char *device; // x0
  __int64 v7; // x19
  unsigned int v8; // w23
  __int64 (__fastcall *v9)(__int64, __int64, __int64); // x8

  device = (char *)kgsl_get_device(0);
  if ( device )
  {
    v7 = (__int64)device;
    rt_mutex_lock(device + 11088);
    v8 = adreno_active_count_get(v7);
    if ( !v8 )
    {
      v9 = **(__int64 (__fastcall ***)(__int64, __int64, __int64))(*(_QWORD *)(v7 + 20744) + 8LL);
      if ( *((_DWORD *)v9 - 1) != 8774143 )
        __break(0x8228u);
      v8 = v9(a1, a2, a3);
      adreno_active_count_put(v7);
    }
    rt_mutex_unlock(v7 + 11088);
  }
  else
  {
    return (unsigned int)-19;
  }
  return v8;
}
