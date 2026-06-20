__int64 __fastcall lpass_cdc_ssr_enable(__int64 a1, __int64 a2)
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
  void (__fastcall *v15)(__int64, __int64); // x8
  __int64 v16; // x0
  _DWORD *v17; // x8
  __int64 v18; // x0
  _DWORD *v19; // x8
  __int64 v20; // x0
  _DWORD *v21; // x8
  __int64 v22; // x0
  _DWORD *v23; // x8
  __int64 v24; // x0
  _DWORD *v25; // x8
  __int64 v26; // x0
  _DWORD *v27; // x8
  __int64 v28; // x0
  _DWORD *v29; // x8
  __int64 v30; // x0
  _DWORD *v31; // x8
  __int64 v32; // x0
  _DWORD *v33; // x8
  __int64 v34; // x0
  _DWORD *v35; // x8
  __int64 v36; // x0

  if ( *(_BYTE *)(a2 + 224) == 1 )
  {
    *(_BYTE *)(a2 + 224) = 0;
  }
  else
  {
    v3 = *(void (__fastcall **)(__int64, __int64))(a2 + 1088);
    if ( v3 )
    {
      v4 = *(_QWORD *)(a2 + 1080);
      if ( *((_DWORD *)v3 - 1) != -410139462 )
        __break(0x8228u);
      v3(v4, 5);
    }
    v5 = *(_DWORD **)(a2 + 280);
    if ( v5 )
    {
      v6 = *(_QWORD *)(a2 + 8);
      if ( *(v5 - 1) != -511372407 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, __int64, _QWORD))v5)(v6, 7, 0);
    }
    v7 = *(_DWORD **)(a2 + 392);
    if ( v7 )
    {
      v8 = *(_QWORD *)(a2 + 8);
      if ( *(v7 - 1) != -511372407 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, __int64, _QWORD))v7)(v8, 7, 0);
    }
    v9 = *(_DWORD **)(a2 + 504);
    if ( v9 )
    {
      v10 = *(_QWORD *)(a2 + 8);
      if ( *(v9 - 1) != -511372407 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, __int64, _QWORD))v9)(v10, 7, 0);
    }
    v11 = *(_DWORD **)(a2 + 616);
    if ( v11 )
    {
      v12 = *(_QWORD *)(a2 + 8);
      if ( *(v11 - 1) != -511372407 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, __int64, _QWORD))v11)(v12, 7, 0);
    }
    v13 = *(_DWORD **)(a2 + 728);
    if ( v13 )
    {
      v14 = *(_QWORD *)(a2 + 8);
      if ( *(v13 - 1) != -511372407 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, __int64, _QWORD))v13)(v14, 7, 0);
    }
    mutex_lock(a2 + 120);
    *(_BYTE *)(a2 + 223) = 1;
    mutex_unlock(a2 + 120);
    v15 = *(void (__fastcall **)(__int64, __int64))(a2 + 1088);
    if ( v15 )
    {
      v16 = *(_QWORD *)(a2 + 1080);
      if ( *((_DWORD *)v15 - 1) != -410139462 )
        __break(0x8228u);
      v15(v16, 11);
    }
    v17 = *(_DWORD **)(a2 + 280);
    if ( v17 )
    {
      v18 = *(_QWORD *)(a2 + 8);
      if ( *(v17 - 1) != -511372407 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, __int64, _QWORD))v17)(v18, 12, 0);
    }
    v19 = *(_DWORD **)(a2 + 392);
    if ( v19 )
    {
      v20 = *(_QWORD *)(a2 + 8);
      if ( *(v19 - 1) != -511372407 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, __int64, _QWORD))v19)(v20, 12, 0);
    }
    v21 = *(_DWORD **)(a2 + 504);
    if ( v21 )
    {
      v22 = *(_QWORD *)(a2 + 8);
      if ( *(v21 - 1) != -511372407 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, __int64, _QWORD))v21)(v22, 12, 0);
    }
    v23 = *(_DWORD **)(a2 + 616);
    if ( v23 )
    {
      v24 = *(_QWORD *)(a2 + 8);
      if ( *(v23 - 1) != -511372407 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, __int64, _QWORD))v23)(v24, 12, 0);
    }
    v25 = *(_DWORD **)(a2 + 728);
    if ( v25 )
    {
      v26 = *(_QWORD *)(a2 + 8);
      if ( *(v25 - 1) != -511372407 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, __int64, _QWORD))v25)(v26, 12, 0);
    }
    regcache_cache_only(*(_QWORD *)(a2 + 16), 0);
    mutex_lock(a2 + 120);
    *(_BYTE *)(a2 + 222) = 1;
    mutex_unlock(a2 + 120);
    regcache_mark_dirty(*(_QWORD *)(a2 + 16));
    lpass_cdc_clk_rsc_enable_all_clocks(*(_QWORD *)(a2 + 1080), 1);
    regcache_sync(*(_QWORD *)(a2 + 16));
    usleep_range_state(100, 110, 2);
    lpass_cdc_clk_rsc_enable_all_clocks(*(_QWORD *)(a2 + 1080), 0);
    v27 = *(_DWORD **)(a2 + 280);
    if ( v27 )
    {
      v28 = *(_QWORD *)(a2 + 8);
      if ( *(v27 - 1) != -511372407 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, __int64, _QWORD))v27)(v28, 5, 0);
    }
    v29 = *(_DWORD **)(a2 + 392);
    if ( v29 )
    {
      v30 = *(_QWORD *)(a2 + 8);
      if ( *(v29 - 1) != -511372407 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, __int64, _QWORD))v29)(v30, 5, 0);
    }
    v31 = *(_DWORD **)(a2 + 504);
    if ( v31 )
    {
      v32 = *(_QWORD *)(a2 + 8);
      if ( *(v31 - 1) != -511372407 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, __int64, _QWORD))v31)(v32, 5, 0);
    }
    v33 = *(_DWORD **)(a2 + 616);
    if ( v33 )
    {
      v34 = *(_QWORD *)(a2 + 8);
      if ( *(v33 - 1) != -511372407 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, __int64, _QWORD))v33)(v34, 5, 0);
    }
    v35 = *(_DWORD **)(a2 + 728);
    if ( v35 )
    {
      v36 = *(_QWORD *)(a2 + 8);
      if ( *(v35 - 1) != -511372407 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, __int64, _QWORD))v35)(v36, 5, 0);
    }
    blocking_notifier_call_chain(a2 + 1008, 4, *(_QWORD *)(a2 + 1000));
  }
  return 0;
}
