__int64 __fastcall cali_show(__int64 a1, __int64 a2, char *a3)
{
  __int64 v3; // x21
  void (__fastcall *v5)(__int64, __int64); // x8
  void (__fastcall *v6)(_QWORD); // x8

  v3 = *(_QWORD *)(a1 + 152);
  mutex_lock(v3 + 584);
  v5 = *(void (__fastcall **)(__int64, __int64))(*(_QWORD *)(v3 + 1312) + 280LL);
  if ( *((_DWORD *)v5 - 1) != -746885483 )
    __break(0x8228u);
  v5(v3 - 168, 1);
  v6 = **(void (__fastcall ***)(_QWORD))(v3 + 1312);
  if ( *((_DWORD *)v6 - 1) != 1361900016 )
    __break(0x8228u);
  v6(v3 - 168);
  mutex_unlock(v3 + 584);
  return snprintf(a3, 0x1000u, "lra_f0 = %d cont_f0 = %d\n", *(_DWORD *)(v3 - 72), *(_DWORD *)(v3 - 56));
}
