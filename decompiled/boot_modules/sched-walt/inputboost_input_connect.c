__int64 __fastcall inputboost_input_connect(__int64 a1, __int64 a2)
{
  _QWORD *v4; // x0
  _QWORD *v5; // x21
  unsigned int v6; // w19
  __int64 result; // x0

  v4 = (_QWORD *)_kmalloc_cache_noprof(mem_alloc_profiling_key, 3520, 88);
  v5 = v4;
  if ( !v4 )
    return 4294967284LL;
  v4[3] = a2;
  v4[4] = a1;
  v4[2] = "cpufreq";
  v6 = input_register_handle(v4);
  if ( !v6 )
  {
    result = input_open_device(v5);
    if ( !(_DWORD)result )
      return result;
    v6 = result;
    input_unregister_handle(v5);
  }
  kfree(v5);
  return v6;
}
