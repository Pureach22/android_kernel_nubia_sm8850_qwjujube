__int64 __fastcall wmi_unified_send_self_non_srg_obss_color_enable_bitmap_cmd(__int64 a1)
{
  __int64 (*v1)(void); // x8

  v1 = *(__int64 (**)(void))(*(_QWORD *)(a1 + 728) + 4200LL);
  if ( !v1 )
    return 16;
  if ( *((_DWORD *)v1 - 1) != 2056978171 )
    __break(0x8228u);
  return v1();
}
