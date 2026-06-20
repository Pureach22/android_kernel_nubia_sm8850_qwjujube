__int64 __fastcall adreno_power_cycle_bool(__int64 a1, _BYTE *a2, char a3)
{
  __int64 v6; // x24
  __int64 (__fastcall *v7)(_QWORD); // x8
  unsigned int v8; // w22
  void (__fastcall *v9)(_QWORD); // x8

  v6 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 14264) + 40LL) + 160LL);
  rt_mutex_lock(a1 + 11088);
  v7 = *(__int64 (__fastcall **)(_QWORD))(v6 + 24);
  if ( *((_DWORD *)v7 - 1) != -83892780 )
    __break(0x8228u);
  v8 = v7(a1);
  if ( !v8 )
  {
    *a2 = a3 & 1;
    gmu_core_mark_for_coldboot(a1);
    v9 = *(void (__fastcall **)(_QWORD))(v6 + 32);
    if ( *((_DWORD *)v9 - 1) != 994519391 )
      __break(0x8228u);
    v9(a1);
  }
  rt_mutex_unlock(a1 + 11088);
  return v8;
}
