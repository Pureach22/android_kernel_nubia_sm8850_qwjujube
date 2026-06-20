__int64 __fastcall qcom_wdt_die_handler(__int64 a1)
{
  __int64 v1; // x8
  __int64 v2; // x20
  __int64 v4; // x0
  void (__fastcall *v5)(_QWORD); // x8
  void (__fastcall *v6)(__int64, __int64); // x8
  void (__fastcall *v7)(__int64, __int64); // x8

  v1 = *(_QWORD *)(a1 - 120);
  v2 = a1 - 136;
  v4 = a1 - 136;
  v5 = *(void (__fastcall **)(_QWORD))(v1 + 16);
  if ( *((_DWORD *)v5 - 1) != 2060914831 )
    __break(0x8228u);
  v5(v4);
  v6 = **(void (__fastcall ***)(__int64, __int64))(a1 - 120);
  if ( *((_DWORD *)v6 - 1) != -872624411 )
    __break(0x8228u);
  v6(15000, v2);
  v7 = *(void (__fastcall **)(__int64, __int64))(*(_QWORD *)(a1 - 120) + 8LL);
  if ( *((_DWORD *)v7 - 1) != -872624411 )
    __break(0x8228u);
  v7(15000, v2);
  return 0;
}
