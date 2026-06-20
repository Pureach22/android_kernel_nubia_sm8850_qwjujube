__int64 __fastcall dsi_display_drm_ext_detect(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 (*v3)(void); // x8

  v3 = *(__int64 (**)(void))(*(_QWORD *)(*(_QWORD *)(a3 + 24) + 416LL) + 16LL);
  if ( *((_DWORD *)v3 - 1) != -1859972157 )
    __break(0x8228u);
  return v3();
}
