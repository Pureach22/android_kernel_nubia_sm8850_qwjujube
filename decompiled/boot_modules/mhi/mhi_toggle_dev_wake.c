__int64 __fastcall mhi_toggle_dev_wake(__int64 a1)
{
  void (*v1)(void); // x8
  __int64 (__fastcall *v3)(__int64, __int64); // x8

  v1 = *(void (**)(void))(a1 + 488);
  if ( *((_DWORD *)v1 - 1) != 598874997 )
    __break(0x8228u);
  v1();
  v3 = *(__int64 (__fastcall **)(__int64, __int64))(a1 + 496);
  if ( *((_DWORD *)v3 - 1) != 598874997 )
    __break(0x8228u);
  return v3(a1, 1);
}
