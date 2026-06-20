__int64 __fastcall wlan_spatial_reuse_he_siga_val15_allowed_set(__int64 a1)
{
  __int64 v1; // x8
  __int64 v2; // x8
  __int64 v3; // x8
  __int64 (*v4)(void); // x8

  v1 = *(_QWORD *)(a1 + 152);
  if ( !v1 )
    return 29;
  v2 = *(_QWORD *)(v1 + 80);
  if ( !v2 )
    return 29;
  v3 = *(_QWORD *)(v2 + 2128);
  if ( !v3 )
    return 29;
  v4 = *(__int64 (**)(void))(v3 + 2096);
  if ( !v4 )
    return 29;
  if ( *((_DWORD *)v4 - 1) != -988222069 )
    __break(0x8228u);
  return v4();
}
