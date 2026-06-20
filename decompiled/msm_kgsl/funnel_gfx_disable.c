char *__fastcall funnel_gfx_disable(__int64 a1, __int64 a2, __int64 a3)
{
  char *result; // x0
  __int64 v7; // x19
  void (__fastcall *v8)(__int64, __int64, __int64); // x8

  result = (char *)kgsl_get_device(0);
  if ( result )
  {
    v7 = (__int64)result;
    rt_mutex_lock(result + 11088);
    if ( !(unsigned int)adreno_active_count_get(v7) )
    {
      v8 = *(void (__fastcall **)(__int64, __int64, __int64))(*(_QWORD *)(*(_QWORD *)(v7 + 20744) + 8LL) + 8LL);
      if ( *((_DWORD *)v8 - 1) != -727984260 )
        __break(0x8228u);
      v8(a1, a2, a3);
      adreno_active_count_put(v7);
    }
    return (char *)rt_mutex_unlock(v7 + 11088);
  }
  return result;
}
