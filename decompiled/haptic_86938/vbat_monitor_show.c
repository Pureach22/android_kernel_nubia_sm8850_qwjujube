__int64 __fastcall vbat_monitor_show(__int64 a1, __int64 a2, char *a3)
{
  __int64 v3; // x21
  void (__fastcall *v5)(_QWORD); // x8
  __int64 v6; // x19

  v3 = *(_QWORD *)(a1 + 152);
  mutex_lock(v3 + 584);
  v5 = *(void (__fastcall **)(_QWORD))(*(_QWORD *)(v3 + 1312) + 64LL);
  if ( *((_DWORD *)v5 - 1) != -2072377296 )
    __break(0x8228u);
  v5(v3 - 168);
  v6 = snprintf(a3, 0x1000u, "vbat_monitor = %d\n", *(_DWORD *)(v3 - 64));
  mutex_unlock(v3 + 584);
  return v6;
}
