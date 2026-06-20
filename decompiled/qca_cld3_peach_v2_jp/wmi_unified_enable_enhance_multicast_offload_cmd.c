__int64 __fastcall wmi_unified_enable_enhance_multicast_offload_cmd(__int64 a1)
{
  __int64 v1; // x8
  __int64 (*v2)(void); // x8

  v1 = *(_QWORD *)(a1 + 728);
  if ( !v1 )
    return 16;
  v2 = *(__int64 (**)(void))(v1 + 1168);
  if ( !v2 )
    return 16;
  if ( *((_DWORD *)v2 - 1) != 1146747844 )
    __break(0x8228u);
  return v2();
}
