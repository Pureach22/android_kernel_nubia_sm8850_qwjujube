__int64 __fastcall wmi_unified_set_auto_shutdown_timer_cmd(__int64 a1)
{
  __int64 (*v1)(void); // x8

  v1 = *(__int64 (**)(void))(*(_QWORD *)(a1 + 728) + 1440LL);
  if ( !v1 )
    return 16;
  if ( *((_DWORD *)v1 - 1) != -2034668364 )
    __break(0x8228u);
  return v1();
}
