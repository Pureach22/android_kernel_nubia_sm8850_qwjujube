__int64 __fastcall adreno_input_work(__int64 a1)
{
  __int64 v2; // x20
  void (__fastcall *v3)(_QWORD); // x8

  v2 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a1 - 6040) + 40LL) + 160LL);
  rt_mutex_lock(a1 - 9216);
  *(_BYTE *)(a1 - 9352) = 1;
  v3 = *(void (__fastcall **)(_QWORD))(v2 + 40);
  if ( *((_DWORD *)v3 - 1) != 994519391 )
    __break(0x8228u);
  v3(a1 - 20304);
  return rt_mutex_unlock(a1 - 9216);
}
