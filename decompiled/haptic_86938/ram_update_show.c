__int64 __fastcall ram_update_show(__int64 a1, __int64 a2, char *a3)
{
  __int64 v3; // x21
  void (__fastcall *v5)(_QWORD); // x8
  void (__fastcall *v6)(__int64, __int64); // x8
  void (__fastcall *v7)(_QWORD); // x8
  __int64 (__fastcall *v8)(__int64, char *); // x8
  __int64 v9; // x0
  __int64 v10; // x19
  _DWORD *v11; // x8

  v3 = *(_QWORD *)(a1 + 152);
  v5 = *(void (__fastcall **)(_QWORD))(*(_QWORD *)(v3 + 1312) + 56LL);
  if ( *((_DWORD *)v5 - 1) != -2072377296 )
    __break(0x8228u);
  v5(v3 - 168);
  v6 = *(void (__fastcall **)(__int64, __int64))(*(_QWORD *)(v3 + 1312) + 104LL);
  if ( *((_DWORD *)v6 - 1) != 487251822 )
    __break(0x8228u);
  v6(v3 - 168, 1);
  v7 = *(void (__fastcall **)(_QWORD))(*(_QWORD *)(v3 + 1312) + 248LL);
  if ( *((_DWORD *)v7 - 1) != -2072377296 )
    __break(0x8228u);
  v7(v3 - 168);
  strcpy(a3, "aw_haptic_ram:\n");
  v8 = *(__int64 (__fastcall **)(__int64, char *))(*(_QWORD *)(v3 + 1312) + 320LL);
  if ( *((_DWORD *)v8 - 1) != 202226252 )
    __break(0x8228u);
  v9 = v8(v3 - 168, a3);
  v10 = v9 + 15 + snprintf(&a3[v9 + 15], 4081 - v9, "\n");
  v11 = *(_DWORD **)(*(_QWORD *)(v3 + 1312) + 104LL);
  if ( *(v11 - 1) != 487251822 )
    __break(0x8228u);
  ((void (__fastcall *)(__int64, _QWORD))v11)(v3 - 168, 0);
  return v10;
}
