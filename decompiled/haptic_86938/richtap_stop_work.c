__int64 __fastcall richtap_stop_work(__int64 a1)
{
  __int64 v1; // x21
  __int64 v3; // x20
  void (__fastcall *v4)(_QWORD); // x8
  void (__fastcall *v5)(_QWORD); // x8
  _DWORD *v6; // x8
  __int64 result; // x0

  v1 = a1 - 888;
  v3 = a1 - 1640;
  mutex_lock(a1 - 888);
  v4 = *(void (__fastcall **)(_QWORD))(*(_QWORD *)(a1 - 160) + 240LL);
  if ( *((_DWORD *)v4 - 1) != -2072377296 )
    __break(0x8228u);
  v4(v3);
  v5 = *(void (__fastcall **)(_QWORD))(*(_QWORD *)(a1 - 160) + 56LL);
  if ( *((_DWORD *)v5 - 1) != -2072377296 )
    __break(0x8228u);
  v5(v3);
  mutex_unlock(v1);
  v6 = *(_DWORD **)(*(_QWORD *)(a1 - 160) + 272LL);
  if ( *(v6 - 1) != 487251822 )
    __break(0x8228u);
  result = ((__int64 (__fastcall *)(__int64, _QWORD))v6)(v3, 0);
  *(_DWORD *)(a1 + 84) = 0;
  return result;
}
