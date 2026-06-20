__int64 __fastcall wcd939x_mbhc_lock_sleep(__int64 a1)
{
  void (*v1)(void); // x8

  v1 = *(void (**)(void))(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 216) + 24LL) + 152LL) + 3168LL);
  if ( *((_DWORD *)v1 - 1) != -1297827279 )
    __break(0x8228u);
  v1();
  return 1;
}
