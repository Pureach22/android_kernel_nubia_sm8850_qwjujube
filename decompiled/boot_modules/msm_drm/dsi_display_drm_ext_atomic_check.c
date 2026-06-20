__int64 __fastcall dsi_display_drm_ext_atomic_check(__int64 a1, __int64 a2)
{
  __int64 (*v2)(void); // x8

  v2 = *(__int64 (**)(void))(*(_QWORD *)(*(_QWORD *)(a2 + 24) + 2088LL) + 48LL);
  if ( *((_DWORD *)v2 - 1) != -1253278960 )
    __break(0x8228u);
  return v2();
}
