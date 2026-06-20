__int64 __fastcall dsi_display_drm_ext_mode_valid(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 result; // x0
  __int64 (*v5)(void); // x8

  result = dsi_conn_mode_valid(a1, a2, a3);
  if ( !(_DWORD)result )
  {
    v5 = *(__int64 (**)(void))(*(_QWORD *)(*(_QWORD *)(a3 + 24) + 2088LL) + 16LL);
    if ( *((_DWORD *)v5 - 1) != -574218809 )
      __break(0x8228u);
    return v5();
  }
  return result;
}
