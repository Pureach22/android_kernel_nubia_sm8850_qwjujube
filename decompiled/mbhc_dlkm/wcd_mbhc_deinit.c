__int64 __fastcall wcd_mbhc_deinit(__int64 a1)
{
  __int64 v2; // x20
  void (__fastcall *v3)(__int64, __int64, __int64); // x8
  __int64 v4; // x1
  void (__fastcall *v5)(__int64, __int64, __int64); // x8
  __int64 v6; // x1
  void (__fastcall *v7)(__int64, __int64, __int64); // x8
  __int64 v8; // x1
  void (__fastcall *v9)(__int64, __int64, __int64); // x8
  __int64 v10; // x1
  void (__fastcall *v11)(__int64, __int64, __int64); // x8
  __int64 v12; // x1
  void (__fastcall *v13)(__int64, __int64, __int64); // x8
  __int64 v14; // x1
  __int64 (__fastcall *v15)(__int64, __int64, __int64); // x8
  __int64 v16; // x1
  __int64 result; // x0
  __int64 v18; // x8
  _DWORD *v19; // x8
  void (__fastcall *v20)(__int64, __int64); // x8

  v2 = *(_QWORD *)(a1 + 216);
  v3 = *(void (__fastcall **)(__int64, __int64, __int64))(*(_QWORD *)(a1 + 120) + 120LL);
  v4 = **(unsigned int **)(a1 + 792);
  if ( *((_DWORD *)v3 - 1) != -1123681200 )
    __break(0x8228u);
  v3(v2, v4, a1);
  v5 = *(void (__fastcall **)(__int64, __int64, __int64))(*(_QWORD *)(a1 + 120) + 120LL);
  v6 = *(unsigned int *)(*(_QWORD *)(a1 + 792) + 4LL);
  if ( *((_DWORD *)v5 - 1) != -1123681200 )
    __break(0x8228u);
  v5(v2, v6, a1);
  v7 = *(void (__fastcall **)(__int64, __int64, __int64))(*(_QWORD *)(a1 + 120) + 120LL);
  v8 = *(unsigned int *)(*(_QWORD *)(a1 + 792) + 8LL);
  if ( *((_DWORD *)v7 - 1) != -1123681200 )
    __break(0x8228u);
  v7(v2, v8, a1);
  v9 = *(void (__fastcall **)(__int64, __int64, __int64))(*(_QWORD *)(a1 + 120) + 120LL);
  v10 = *(unsigned int *)(*(_QWORD *)(a1 + 792) + 12LL);
  if ( *((_DWORD *)v9 - 1) != -1123681200 )
    __break(0x8228u);
  v9(v2, v10, a1);
  v11 = *(void (__fastcall **)(__int64, __int64, __int64))(*(_QWORD *)(a1 + 120) + 120LL);
  v12 = *(unsigned int *)(*(_QWORD *)(a1 + 792) + 16LL);
  if ( *((_DWORD *)v11 - 1) != -1123681200 )
    __break(0x8228u);
  v11(v2, v12, a1);
  v13 = *(void (__fastcall **)(__int64, __int64, __int64))(*(_QWORD *)(a1 + 120) + 120LL);
  v14 = *(unsigned int *)(*(_QWORD *)(a1 + 792) + 20LL);
  if ( *((_DWORD *)v13 - 1) != -1123681200 )
    __break(0x8228u);
  v13(v2, v14, a1);
  v15 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(*(_QWORD *)(a1 + 120) + 120LL);
  v16 = *(unsigned int *)(*(_QWORD *)(a1 + 792) + 24LL);
  if ( *((_DWORD *)v15 - 1) != -1123681200 )
    __break(0x8228u);
  result = v15(v2, v16, a1);
  v18 = *(_QWORD *)(a1 + 120);
  if ( v18 )
  {
    v19 = *(_DWORD **)(v18 + 96);
    if ( v19 )
    {
      if ( *(v19 - 1) != -321073799 )
        __break(0x8228u);
      result = ((__int64 (__fastcall *)(__int64, __int64, _QWORD))v19)(a1, a1 + 832, 0);
    }
  }
  if ( *(_QWORD *)(*(_QWORD *)(a1 + 920) + 32LL) )
  {
    mutex_lock(a1 + 744);
    v20 = *(void (__fastcall **)(__int64, __int64))(*(_QWORD *)(a1 + 920) + 32LL);
    if ( *((_DWORD *)v20 - 1) != -794314397 )
      __break(0x8228u);
    v20(a1, a1 + 800);
    return mutex_unlock(a1 + 744);
  }
  return result;
}
