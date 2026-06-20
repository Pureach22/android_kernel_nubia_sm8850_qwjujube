__int64 __fastcall lpass_cdc_ssr_disable(__int64 a1, __int64 a2)
{
  void (__fastcall *v3)(__int64, __int64); // x8
  __int64 v4; // x0
  _DWORD *v5; // x8
  __int64 v6; // x0
  _DWORD *v7; // x8
  __int64 v8; // x0
  _DWORD *v9; // x8
  __int64 v10; // x0
  _DWORD *v11; // x8
  __int64 v12; // x0
  _DWORD *v13; // x8
  __int64 v14; // x0
  __int64 result; // x0

  if ( (*(_BYTE *)(a2 + 222) & 1) != 0 )
  {
    regcache_cache_only(*(_QWORD *)(a2 + 16), 1);
    mutex_lock(a2 + 120);
    *(_WORD *)(a2 + 222) = 0;
    mutex_unlock(a2 + 120);
    v3 = *(void (__fastcall **)(__int64, __int64))(a2 + 1088);
    if ( v3 )
    {
      v4 = *(_QWORD *)(a2 + 1080);
      if ( *((_DWORD *)v3 - 1) != -410139462 )
        __break(0x8228u);
      v3(v4, 4);
    }
    v5 = *(_DWORD **)(a2 + 280);
    if ( v5 )
    {
      v6 = *(_QWORD *)(a2 + 8);
      if ( *(v5 - 1) != -511372407 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, __int64, _QWORD))v5)(v6, 4, 0);
    }
    v7 = *(_DWORD **)(a2 + 392);
    if ( v7 )
    {
      v8 = *(_QWORD *)(a2 + 8);
      if ( *(v7 - 1) != -511372407 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, __int64, _QWORD))v7)(v8, 4, 0);
    }
    v9 = *(_DWORD **)(a2 + 504);
    if ( v9 )
    {
      v10 = *(_QWORD *)(a2 + 8);
      if ( *(v9 - 1) != -511372407 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, __int64, _QWORD))v9)(v10, 4, 0);
    }
    v11 = *(_DWORD **)(a2 + 616);
    if ( v11 )
    {
      v12 = *(_QWORD *)(a2 + 8);
      if ( *(v11 - 1) != -511372407 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, __int64, _QWORD))v11)(v12, 4, 0);
    }
    v13 = *(_DWORD **)(a2 + 728);
    if ( v13 )
    {
      v14 = *(_QWORD *)(a2 + 8);
      if ( *(v13 - 1) != -511372407 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, __int64, _QWORD))v13)(v14, 4, 0);
    }
    return blocking_notifier_call_chain(a2 + 1008, 3, *(_QWORD *)(a2 + 1000));
  }
  else
  {
    result = __ratelimit(&lpass_cdc_ssr_disable__rs, "lpass_cdc_ssr_disable");
    if ( (_DWORD)result )
      return dev_err(*(_QWORD *)a2, "%s: already disabled\n", "lpass_cdc_ssr_disable");
  }
  return result;
}
