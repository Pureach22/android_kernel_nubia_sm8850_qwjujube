__int64 __fastcall msm_open(__int64 a1, __int64 a2)
{
  __int64 v4; // x0
  __int64 v5; // x21
  __int64 v6; // x8
  __int64 result; // x0
  void (*v8)(void); // x8

  v4 = _kmalloc_cache_noprof(_kmalloc_cache_noprof, 3520, 80);
  if ( !v4 )
    return 4294967284LL;
  v5 = v4;
  _mutex_init(v4 + 32, "&ctx->power_lock", &context_init___key);
  *(_QWORD *)(a2 + 152) = v5;
  if ( a1 )
  {
    v6 = *(_QWORD *)(a1 + 56);
    if ( v6 )
    {
      result = *(_QWORD *)(v6 + 8);
      if ( !result )
        return result;
      if ( *(_QWORD *)result )
      {
        v8 = *(void (**)(void))(*(_QWORD *)result + 144LL);
        if ( v8 )
        {
          if ( *((_DWORD *)v8 - 1) != -37677341 )
            __break(0x8228u);
          v8();
        }
      }
    }
  }
  return 0;
}
