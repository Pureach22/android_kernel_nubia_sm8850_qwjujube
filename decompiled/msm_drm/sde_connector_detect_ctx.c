__int64 __fastcall sde_connector_detect_ctx(__int64 a1, __int64 a2, char a3)
{
  __int64 (__fastcall *v3)(__int64, __int64, __int64, __int64); // x8
  __int64 v5; // x3
  __int64 v6; // x2
  unsigned int v7; // w0
  __int64 (__fastcall *v8)(__int64, __int64, __int64); // x9
  __int64 v9; // x1
  __int64 v10; // x2
  unsigned int v11; // w20

  if ( !a1 )
  {
    printk(&unk_242658, "sde_connector_detect_ctx");
    return 3;
  }
  v3 = *(__int64 (__fastcall **)(__int64, __int64, __int64, __int64))(a1 + 2896);
  if ( v3 )
  {
    v5 = *(_QWORD *)(a1 + 2760);
    v6 = a3 & 1;
    if ( *((_DWORD *)v3 - 1) != -899333166 )
      __break(0x8228u);
    v7 = v3(a1, a2, v6, v5);
LABEL_10:
    v11 = v7;
    goto LABEL_11;
  }
  v8 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(a1 + 2888);
  if ( v8 )
  {
    v9 = a3 & 1;
    v10 = *(_QWORD *)(a1 + 2760);
    if ( *((_DWORD *)v8 - 1) != 333569284 )
      __break(0x8229u);
    v7 = v8(a1, v9, v10);
    goto LABEL_10;
  }
  v11 = 3;
LABEL_11:
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(0, 0, 0, "connector id: %d, connection status: %d\n", *(_DWORD *)(a1 + 64), v11);
  return v11;
}
