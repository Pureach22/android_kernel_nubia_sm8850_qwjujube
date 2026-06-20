__int64 __fastcall sde_connector_atomic_best_encoder(__int64 a1, __int64 a2)
{
  int v2; // w8
  __int64 v3; // x2
  __int64 (__fastcall *v4)(__int64, __int64, __int64); // x8
  __int64 v5; // x1

  if ( !a1 )
  {
    printk(&unk_242658, "sde_connector_atomic_best_encoder");
    return 0;
  }
  v2 = *(_DWORD *)(a1 + 152);
  if ( v2 >= *(_DWORD *)(a2 + 40) )
  {
    v3 = 0;
    v4 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(a1 + 3096);
    if ( v4 )
      goto LABEL_6;
    return 0;
  }
  v3 = *(_QWORD *)(*(_QWORD *)(a2 + 48) + 40LL * v2 + 24);
  v4 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(a1 + 3096);
  if ( !v4 )
    return 0;
LABEL_6:
  v5 = *(_QWORD *)(a1 + 2760);
  if ( *((_DWORD *)v4 - 1) != 678164314 )
    __break(0x8228u);
  return v4(a1, v5, v3);
}
