__int64 __fastcall seq_show(__int64 a1, __int64 a2, char *a3)
{
  __int64 v3; // x21
  void (__fastcall *v5)(__int64, __int64); // x8
  __int64 v6; // x23
  __int64 v7; // x23
  __int64 v8; // x23
  __int64 v9; // x23
  __int64 v10; // x23
  __int64 v11; // x23
  __int64 v12; // x23

  v3 = *(_QWORD *)(a1 + 152);
  v5 = *(void (__fastcall **)(__int64, __int64))(*(_QWORD *)(v3 + 1312) + 288LL);
  if ( *((_DWORD *)v5 - 1) != -746885483 )
    __break(0x8228u);
  v5(v3 - 168, 8);
  v6 = snprintf(a3, 0x1000u, "seq%d = %d\n", 1, *(unsigned __int8 *)(v3 - 138));
  v7 = v6 + snprintf(&a3[v6], 4096 - v6, "seq%d = %d\n", 2, *(unsigned __int8 *)(v3 - 137));
  v8 = v7 + snprintf(&a3[v7], 4096 - v7, "seq%d = %d\n", 3, *(unsigned __int8 *)(v3 - 136));
  v9 = v8 + snprintf(&a3[v8], 4096 - v8, "seq%d = %d\n", 4, *(unsigned __int8 *)(v3 - 135));
  v10 = v9 + snprintf(&a3[v9], 4096 - v9, "seq%d = %d\n", 5, *(unsigned __int8 *)(v3 - 134));
  v11 = v10 + snprintf(&a3[v10], 4096 - v10, "seq%d = %d\n", 6, *(unsigned __int8 *)(v3 - 133));
  v12 = v11 + snprintf(&a3[v11], 4096 - v11, "seq%d = %d\n", 7, *(unsigned __int8 *)(v3 - 132));
  return v12 + snprintf(&a3[v12], 4096 - v12, "seq%d = %d\n", 8, *(unsigned __int8 *)(v3 - 131));
}
